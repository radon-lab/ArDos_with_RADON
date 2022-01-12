#include "languages.h"
#include "connection.h"
#include "DefaultFonts.c"

//дерективы для управления дисплеем
#define pulseClock BIT_CLEAR(SCK_PORT, SCK_BIT); asm ("nop"); BIT_SET(SCK_PORT, SCK_BIT)
#define resetLCD BIT_SET(DC_PORT, DC_BIT); BIT_SET(MOSI_PORT, MOSI_BIT); BIT_SET(SCK_PORT, SCK_BIT); BIT_CLEAR(RST_PORT, RST_BIT); _delay_ms(10); BIT_SET(RST_PORT, RST_BIT)

#define fontbyte(x) pgm_read_byte(&cfont.font[x])
#define bitmapbyte(x) pgm_read_byte(&bitmap[x])

//------------------
#define LEFT 0
#define RIGHT 255
#define CENTER 254

#define LCD_COMMAND 0
#define LCD_DATA 1

//основные команды
#define PCD8544_POWERDOWN 0x04
#define PCD8544_ENTRYMODE 0x02
#define PCD8544_EXTENDEDINSTRUCTION 0x01
#define PCD8544_DISPLAYBLANK 0x00
#define PCD8544_DISPLAYNORMAL 0x04
#define PCD8544_DISPLAYALLON 0x01
#define PCD8544_DISPLAYINVERTED 0x05
//основные инструкции
#define PCD8544_FUNCTIONSET 0x20
#define PCD8544_DISPLAYCONTROL 0x08
#define PCD8544_SETYADDR 0x40
#define PCD8544_SETXADDR 0x80
//внешние инструкции
#define PCD8544_SETTEMP 0x04
#define PCD8544_SETBIAS 0x10
#define PCD8544_SETVOP 0x80
//установки дисплея
#define LCD_BIAS 0x03  //0-7 (0x00-0x07)
#define LCD_TEMP 0x02  //0-3 (0x00-0x03)
#define LCD_CONTRAST 0x46  //0-127 (0x00-0x7F)

uint8_t _lcd_buffer[504]; //буфер дисплея

struct _current_font {
  const uint8_t* font;
  uint8_t x_size;
  uint8_t y_size;
  uint8_t offset;
  uint8_t numchars;
  uint8_t inverted;
} cfont;

void  initLcd(void);
void  setContrast(uint8_t contrast);
void  enableSleep(void);
void  disableSleep(uint8_t contrast);
void  clrScr(void);
void  drawLine(uint8_t row, uint8_t start_x = 0, uint8_t end_x = 83, uint8_t line = 0);
void  invert(bool mode);
void  invertText(bool mode);
void  print(const char *st, uint8_t x, uint8_t y, boolean mem = 0);
void  printNumI(uint32_t num, uint8_t x, uint8_t y, uint8_t length = 0, char filler = ' ');
void  printNumF(float num, uint8_t dec, uint8_t x, uint8_t y, char divider = '.', uint8_t length = 0, char filler = ' ');
void  setFont(const uint8_t* font);
void  drawBitmap(uint8_t x, uint8_t y, const uint8_t* bitmap, uint8_t size_x, uint8_t size_y);

void  _LCD_Write(unsigned char data, unsigned char mode);
void  _print_char(unsigned char c, uint8_t x, uint8_t row, uint8_t steps);

inline void _LCD_Write(uint8_t data, uint8_t mode)
{
#if ROTATE_DISP
  switch (mode) {
    case LCD_COMMAND:
      BIT_CLEAR(DC_PORT, DC_BIT);
      for (uint8_t c = 0; c < 8; c++) {
        if (data & 0x80) BIT_SET(MOSI_PORT, MOSI_BIT);
        else BIT_CLEAR(MOSI_PORT, MOSI_BIT);
        data <<= 0x01;
        pulseClock;
      }
      break;

    case LCD_DATA:
      BIT_SET(DC_PORT, DC_BIT);
      for (uint8_t c = 0; c < 8; c++) {
        if (data & 0x01) BIT_SET(MOSI_PORT, MOSI_BIT);
        else BIT_CLEAR(MOSI_PORT, MOSI_BIT);
        data >>= 0x01;
        pulseClock;
      }
      break;
  }
#else
  switch (mode) {
    case LCD_COMMAND: BIT_CLEAR(DC_PORT, DC_BIT); break;
    case LCD_DATA: BIT_SET(DC_PORT, DC_BIT); break;
  }

  for (uint8_t c = 0; c < 8; c++) {
    if (data & 0x80) BIT_SET(MOSI_PORT, MOSI_BIT);
    else BIT_CLEAR(MOSI_PORT, MOSI_BIT);
    data <<= 0x01;
    pulseClock;
  }
#endif
}
//-------------------------Инициализация дисплея----------------------------------------------------
void initLcd(void) //инициализация дисплея
{
  resetLCD; //отправка команды ресет
  disableSleep(DEFAULT_CONTRAST); //инициализация дисплея
  setFont(FONT_DATA_NAME); //установка шрифта
}
//-------------------------Установка контрастности----------------------------------------------------
void setContrast(uint8_t contrast) //установка контрастности
{
  _LCD_Write(PCD8544_FUNCTIONSET | PCD8544_EXTENDEDINSTRUCTION, LCD_COMMAND);
  _LCD_Write(PCD8544_SETVOP | contrast, LCD_COMMAND);
  _LCD_Write(PCD8544_FUNCTIONSET, LCD_COMMAND);
}
//-------------------------Включение режима сна----------------------------------------------------
void enableSleep(void) //включение режима сна
{
  _LCD_Write(PCD8544_FUNCTIONSET | PCD8544_POWERDOWN, LCD_COMMAND);
}
//-------------------------Выключение режима сна----------------------------------------------------
void disableSleep(uint8_t contrast) //выключение режима сна
{
  _LCD_Write(PCD8544_FUNCTIONSET | PCD8544_EXTENDEDINSTRUCTION, LCD_COMMAND);
  _LCD_Write(PCD8544_SETVOP | contrast, LCD_COMMAND);
  _LCD_Write(PCD8544_SETTEMP | LCD_TEMP, LCD_COMMAND);
  _LCD_Write(PCD8544_SETBIAS | LCD_BIAS, LCD_COMMAND);
  _LCD_Write(PCD8544_FUNCTIONSET, LCD_COMMAND);
  clrScr(); //очистка экрана
  _LCD_Write(PCD8544_DISPLAYCONTROL | PCD8544_DISPLAYNORMAL, LCD_COMMAND);
}
//----------------------Вывод буфера на экран-----------------------------------------------
void showScr(void) //вывод буфера на экран
{
#if ROTATE_DISP
  for (uint16_t c = 504; c; c--) _LCD_Write(_lcd_buffer[c - 1], LCD_DATA);
  _LCD_Write(PCD8544_SETYADDR, LCD_COMMAND);
  _LCD_Write(PCD8544_SETXADDR, LCD_COMMAND);
#else
  for (uint16_t c = 0; c < 504; c++) _LCD_Write(_lcd_buffer[c], LCD_DATA);
  _LCD_Write(PCD8544_SETYADDR, LCD_COMMAND);
  _LCD_Write(PCD8544_SETXADDR, LCD_COMMAND);
#endif
}
//-------------------------Очистка экрана----------------------------------------------------
void clrScr(void) //очистка экрана
{
  for (uint16_t c = 0; c < 504; c++) _lcd_buffer[c] = 0;
}
//-------------------------Очистка строки----------------------------------------------------
void drawLine(uint8_t row, uint8_t start_x, uint8_t end_x, uint8_t line) //очистка строки
{
  uint16_t start = start_x + (uint16_t)(row * 84);
  uint16_t end = end_x + (uint16_t)(row * 84);
  for (uint16_t c = start; c <= end; c++) {
    if (!line) _lcd_buffer[c] = 0;
    else _lcd_buffer[c] |= line;
  }
}
//-------------------------Инверсия экрана----------------------------------------------------
void invert(boolean mode) //инверсия экрана
{
  switch (mode) {
    case 0: _LCD_Write(PCD8544_DISPLAYCONTROL | PCD8544_DISPLAYNORMAL, LCD_COMMAND); break;
    case 1: _LCD_Write(PCD8544_DISPLAYCONTROL | PCD8544_DISPLAYINVERTED, LCD_COMMAND); break;
  }
}
//-------------------------Инверсия текста----------------------------------------------------
void invertText(boolean mode) //инверсия текста
{
  switch (mode) {
    case 0: cfont.inverted = 0; break;
    case 1: cfont.inverted = 1; break;
  }
}
//-------------------------Установка шрифта----------------------------------------------------
void setFont(const uint8_t* font) //установка шрифта
{
  cfont.font = font;
  cfont.x_size = fontbyte(0);
  cfont.y_size = fontbyte(1);
  cfont.offset = fontbyte(2);
  cfont.numchars = fontbyte(3);
}
//-------------------------Вывод текста----------------------------------------------------
void print(const char *st, uint8_t x, uint8_t y, boolean mem) //вывод текста
{
  uint8_t stl = 0, row = 0, steps = 0;

  for (uint8_t i = 0; i < 15; i++) {
    if (!((mem) ? (*(st + i)) : pgm_read_byte(st + i))) {
      stl = i;
      break;
    }
  }

  switch (x) {
    case RIGHT: x = 84 - (stl * cfont.x_size); break;
    case CENTER: x = (84 - (stl * cfont.x_size)) / 2; break;
  }

  if (y % 8 == 0) {
    row = y / 8;
    steps = 0;
  }
  else {
    row = (y / 8) + 1;
    steps = 8 - y % 8;
  }

  for (uint8_t cnt = 0; cnt < stl; cnt++) _print_char((mem) ? (*st++) : pgm_read_byte(st++), x + (cnt * (cfont.x_size)), row, steps);

  setFont(FONT_DATA_NAME); //установка шрифта
}
//-------------------------Вывод чисел----------------------------------------------------
void printNumI(uint32_t num, uint8_t x, uint8_t y, uint8_t length, char filler) //вывод чисел
{
  printNumF(num, 0, x, y, '.', length, filler);
}
//-------------------------Вывод чисел с плавающей точкой----------------------------------------------------
void printNumF(float num, uint8_t dec, uint8_t x, uint8_t y, char divider, uint8_t length, char filler) //вывод чисел с плавающей точкой
{
  char ct[6];
  char ft[6];
  char st[10];
  uint8_t c = 0, f = 0, d = 0;
  uint32_t numInt = num;
  float decNum = num - numInt;

  if (numInt) {
    while (numInt > 0) {
      ct[c++] = 48 + (numInt % 10);
      numInt = (numInt - (numInt % 10)) / 10;
    }
  }
  else ct[c++] = 48;

  if (dec) {
    ft[d++] = divider;
    for (uint8_t i = 0; i < dec; i++) {
      decNum *= 10.0;
      ft[d++] = 48 + decNum;
      decNum -= (uint8_t)decNum;
    }
  }

  if (length > c + d) {
    while (f < (length - (c + d))) st[f++] = filler;
  }

  for (uint8_t i = 0; i < c; i++) st[i + f] = ct[c - i - 1];
  for (uint8_t i = 0; i < d; i++) st[i + f + c] = ft[i];

  st[c + f + d] = 0;

  print(st, x, y, 1);
}
//-------------------------Отрисовка символа----------------------------------------------------
void _print_char(uint8_t c, uint8_t x, uint8_t row, uint8_t steps) //отрисовка символа
{
  if (((x + cfont.x_size) <= 84) and (row + (cfont.y_size / 8) <= 6)) {
    for (uint8_t rowcnt = 0; rowcnt < (cfont.y_size / 8); rowcnt++) {
      uint16_t cell = (row + rowcnt) * 84 + x;
      uint16_t font_idx = ((c - cfont.offset) * (cfont.x_size * (cfont.y_size / 8))) + 4;

      for (uint16_t cnt = 0; cnt < cfont.x_size; cnt++) {
        switch (cfont.inverted) {
          case 0: _lcd_buffer[cell + cnt] = fontbyte(font_idx + cnt + (rowcnt * cfont.x_size)) >> steps; break;
          case 1: _lcd_buffer[cell + cnt] = ~(fontbyte(font_idx + cnt + (rowcnt * cfont.x_size)) >> steps); break;
        }
      }
    }
  }
}
//-------------------------Отрисовка изображений-----------------------------------------------
void drawBitmap(uint8_t x, uint8_t y, const uint8_t* bitmap, uint8_t size_x, uint8_t size_y) //отрисовка изображений
{
  uint8_t start_y, rows;

  start_y = y / 8;

  if (size_y % 8 == 0) rows = size_y / 8;
  else rows = (size_y / 8) + 1;

  for (uint8_t cy = 0; cy < rows; cy++) {
    uint16_t cell = (start_y + cy) * 84 + x;
    for (uint8_t cx = 0; cx < size_x; cx++) _lcd_buffer[cell + cx] = bitmapbyte(cx + (cy * size_x));
  }
}
