#include <Arduino.h>
#include "connection.h"

// *** Переменные для управления дисплеем ***
#define pulseClock bitClear(SCK_PORT, SCK_BIT); asm ("nop"); bitSet(SCK_PORT, SCK_BIT)
#define resetLCD bitSet(DC_PORT, DC_BIT); bitSet(MOSI_PORT, MOSI_BIT); bitSet(SCK_PORT, SCK_BIT); bitClear(RST_PORT, RST_BIT); _delay_ms(10); bitSet(RST_PORT, RST_BIT)

#define fontbyte(x) pgm_read_byte(&cfont.font[x])
#define bitmapbyte(x) pgm_read_byte(&bitmap[x])

#define bitmapdatatype uint8_t*

// ------------------
#define LEFT 0
#define RIGHT 255
#define CENTER 254

#define LCD_COMMAND 0
#define LCD_DATA 1

// *** Команды для PCD8544 ***

// Основные команды
#define PCD8544_POWERDOWN      0x04
#define PCD8544_ENTRYMODE     0x02
#define PCD8544_EXTENDEDINSTRUCTION 0x01
#define PCD8544_DISPLAYBLANK    0x00
#define PCD8544_DISPLAYNORMAL   0x04
#define PCD8544_DISPLAYALLON    0x01
#define PCD8544_DISPLAYINVERTED   0x05
// Основные инструкции
#define PCD8544_FUNCTIONSET     0x20
#define PCD8544_DISPLAYCONTROL    0x08
#define PCD8544_SETYADDR      0x40
#define PCD8544_SETXADDR      0x80
// Внешние инструкции
#define PCD8544_SETTEMP       0x04
#define PCD8544_SETBIAS       0x10
#define PCD8544_SETVOP        0x80
// Установки дисплея
#define LCD_BIAS          0x03  // Range: 0-7 (0x00-0x07)
#define LCD_TEMP          0x02  // Range: 0-3 (0x00-0x03)
#define LCD_CONTRAST        0x46  // Range: 0-127 (0x00-0x7F)

struct _current_font
{
  uint8_t* font;
  uint8_t x_size;
  uint8_t y_size;
  uint8_t offset;
  uint8_t numchars;
  uint8_t inverted;
};

void  InitLCD(uint8_t contrast = LCD_CONTRAST);
void  setContrast(uint8_t contrast);
void  enableSleep(void);
void  disableSleep(uint8_t contrast);
void  clrScr(void);
void  clrRow(uint8_t row, uint8_t start_x = 0, uint8_t end_x = 83);
void  invert(bool mode);
void  invertText(bool mode);
void  print(char *st, uint8_t x, uint8_t y, uint8_t length = 0, char filler = ' ');
void  print(String st, uint8_t x, uint8_t y, uint8_t length = 0, char filler = ' ');
void  printNumI(uint32_t num, uint8_t x, uint8_t y, uint8_t length = 0, char filler = ' ');
void  printNumF(float num, uint8_t dec, uint8_t x, uint8_t y, char divider = '.', uint8_t length = 0, char filler = ' ');
void  setFont(uint8_t* font);
void  drawBitmap(uint8_t x, uint8_t y, bitmapdatatype bitmap, uint8_t sx, uint8_t sy,  boolean inv = 0);

void  _LCD_Write(unsigned char data, unsigned char mode);
void  _print_char(unsigned char c, uint8_t x, uint8_t row, uint8_t steps);

_current_font cfont;

void _LCD_Write(unsigned char data, unsigned char mode)
{
#if ROTATE_DISP
  switch (mode) {
    case LCD_COMMAND:
      bitClear(DC_PORT, DC_BIT);
      for (uint8_t c = 0; c < 8; c++)
      {
        if (data & 0x80)
          bitSet(MOSI_PORT, MOSI_BIT);
        else
          bitClear(MOSI_PORT, MOSI_BIT);
        data = data << 1;
        pulseClock;
      }
      break;
    case LCD_DATA:
      bitSet(DC_PORT, DC_BIT);
      for (uint8_t c = 0; c < 8; c++)
      {
        if (data & 0x01)
          bitSet(MOSI_PORT, MOSI_BIT);
        else
          bitClear(MOSI_PORT, MOSI_BIT);
        data = data >> 1;
        pulseClock;
      }
      break;
  }
#else
  switch (mode) {
    case LCD_COMMAND: bitClear(DC_PORT, DC_BIT); break;
    case LCD_DATA: bitSet(DC_PORT, DC_BIT); break;
  }

  for (uint8_t c = 0; c < 8; c++)
  {
    if (data & 0x80)
      bitSet(MOSI_PORT, MOSI_BIT);
    else
      bitClear(MOSI_PORT, MOSI_BIT);
    data = data << 1;
    pulseClock;
  }
#endif
}
//-------------------------Инициализация дисплея----------------------------------------------------
void InitLCD(uint8_t contrast) //инициализация дисплея
{
  resetLCD;

  _LCD_Write(PCD8544_FUNCTIONSET | PCD8544_EXTENDEDINSTRUCTION, LCD_COMMAND);
  _LCD_Write(PCD8544_SETVOP | contrast, LCD_COMMAND);
  _LCD_Write(PCD8544_SETTEMP | LCD_TEMP, LCD_COMMAND);
  _LCD_Write(PCD8544_SETBIAS | LCD_BIAS, LCD_COMMAND);
  _LCD_Write(PCD8544_FUNCTIONSET, LCD_COMMAND);
  _LCD_Write(PCD8544_SETYADDR, LCD_COMMAND);
  _LCD_Write(PCD8544_SETXADDR, LCD_COMMAND);
  for (uint16_t c = 0; c < 504; c++) _LCD_Write(0x00, LCD_DATA);
  _LCD_Write(PCD8544_DISPLAYCONTROL | PCD8544_DISPLAYNORMAL, LCD_COMMAND);

  cfont.font = 0;
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
  _LCD_Write(PCD8544_SETYADDR, LCD_COMMAND);
  _LCD_Write(PCD8544_SETXADDR, LCD_COMMAND);
  for (uint16_t b = 0; b < 504; b++) _LCD_Write(0x00, LCD_DATA);
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
  _LCD_Write(PCD8544_DISPLAYCONTROL | PCD8544_DISPLAYNORMAL, LCD_COMMAND);
}
//-------------------------Очистка экрана----------------------------------------------------
void clrScr(void) //очистка экрана
{
  _LCD_Write(PCD8544_SETYADDR, LCD_COMMAND);
  _LCD_Write(PCD8544_SETXADDR, LCD_COMMAND);
  for (uint16_t c = 0; c < 504; c++)
    _LCD_Write(0x00, LCD_DATA);
}
//-------------------------Очистка строки----------------------------------------------------
void clrRow(uint8_t row, uint8_t start_x, uint8_t end_x) //очистка строки
{
#if ROTATE_DISP
  row = 5 - row;
  start_x = 83 - start_x;
  end_x = 83 - end_x;

  _LCD_Write(PCD8544_SETYADDR | row, LCD_COMMAND);
  _LCD_Write(PCD8544_SETXADDR | end_x, LCD_COMMAND);
  for (uint8_t c = end_x; c <= start_x; c++) _LCD_Write(0x00, LCD_DATA);
  _LCD_Write(PCD8544_SETYADDR, LCD_COMMAND);
  _LCD_Write(PCD8544_SETXADDR, LCD_COMMAND);
#else
  _LCD_Write(PCD8544_SETYADDR | row, LCD_COMMAND);
  _LCD_Write(PCD8544_SETXADDR | start_x, LCD_COMMAND);
  for (uint8_t c = start_x; c <= end_x; c++) _LCD_Write(0x00, LCD_DATA);
  _LCD_Write(PCD8544_SETYADDR, LCD_COMMAND);
  _LCD_Write(PCD8544_SETXADDR, LCD_COMMAND);
#endif
}
//-------------------------Инверсия экрана----------------------------------------------------
void invert(bool mode) //инверсия экрана
{
  switch (mode) {
    case 0: _LCD_Write(PCD8544_DISPLAYCONTROL | PCD8544_DISPLAYNORMAL, LCD_COMMAND); break;
    case 1: _LCD_Write(PCD8544_DISPLAYCONTROL | PCD8544_DISPLAYINVERTED, LCD_COMMAND); break;
  }
}
//-------------------------Инверсия текста----------------------------------------------------
void invertText(bool mode) //инверсия текста
{
  switch (mode) {
    case 0: cfont.inverted = 0; break;
    case 1: cfont.inverted = 1; break;
  }
}
//-------------------------Вывод текста----------------------------------------------------
void print(char *st, uint8_t x, uint8_t y, uint8_t length, char filler) //вывод текста
{
  uint8_t stl, row, xp, steps;

  stl = strlen(st);

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
  xp = x;

  for (int cnt = 0; cnt < stl; cnt++) _print_char(*st++, x + (cnt * (cfont.x_size)), row, steps);
}
//-------------------------Вывод чисел----------------------------------------------------
void printNumI(uint32_t num, uint8_t x, uint8_t y, uint8_t length, char filler) //вывод чисел
{
  printNumF(num, 0, x, y, '.', length, filler);
}
//-------------------------Вывод чисел с плавающей точкой----------------------------------------------------
void printNumF(float num, uint8_t dec, uint8_t x, uint8_t y, char divider, uint8_t length, char filler) //вывод чисел с плавающей точкой
{
  char st[14];

  dtostrf(num, length, dec, st);

  if (divider != '.') {
    for (uint8_t i = 0; i < 14; i++) if (st[i] == '.') st[i] = divider;
  }

  if (filler != ' ') {
    for (uint8_t i = 0; i < 14; i++) if (st[i] == ' ') st[i] = filler;
  }

  print(st, x, y);
}
//-------------------------Отрисовка символа----------------------------------------------------
void _print_char(unsigned char c, uint8_t x, uint8_t row, uint8_t steps) //отрисовка символа
{
#if ROTATE_DISP
  x = 84 - x - cfont.x_size;
  row = 5 - row;

  if (((x + cfont.x_size) <= 84) and (row + (cfont.y_size / 8) <= 6))
  {
    for (uint8_t rowcnt = 0; rowcnt < (cfont.y_size / 8); rowcnt++)
    {
      _LCD_Write(PCD8544_SETYADDR | (row - rowcnt), LCD_COMMAND);
      _LCD_Write(PCD8544_SETXADDR | x, LCD_COMMAND);

      uint16_t font_idx = ((c - cfont.offset) * (cfont.x_size * (cfont.y_size / 8))) + 4;

      for (uint16_t cnt = cfont.x_size; cnt > 0; cnt--)
      {
        switch (cfont.inverted) {
          case 0: _LCD_Write(fontbyte(font_idx + cnt - 1 + (rowcnt * cfont.x_size)) >> steps, LCD_DATA); break;
          case 1: _LCD_Write(~(fontbyte(font_idx + cnt - 1 + (rowcnt * cfont.x_size)) >> steps), LCD_DATA); break;
        }
      }
    }
    _LCD_Write(PCD8544_SETYADDR, LCD_COMMAND);
    _LCD_Write(PCD8544_SETXADDR, LCD_COMMAND);
  }
#else
  if (((x + cfont.x_size) <= 84) and (row + (cfont.y_size / 8) <= 6)) {
    for (uint8_t rowcnt = 0; rowcnt < (cfont.y_size / 8); rowcnt++) {
      _LCD_Write(PCD8544_SETYADDR | (row + rowcnt), LCD_COMMAND);
      _LCD_Write(PCD8544_SETXADDR | x, LCD_COMMAND);

      uint16_t font_idx = ((c - cfont.offset) * (cfont.x_size * (cfont.y_size / 8))) + 4;

      for (uint16_t cnt = 0; cnt < cfont.x_size; cnt++) {
        switch (cfont.inverted) {
          case 0: _LCD_Write(fontbyte(font_idx + cnt + (rowcnt * cfont.x_size)) >> steps, LCD_DATA); break;
          case 1: _LCD_Write(~(fontbyte(font_idx + cnt + (rowcnt * cfont.x_size)) >> steps), LCD_DATA); break;
        }
      }
    }
    _LCD_Write(PCD8544_SETYADDR, LCD_COMMAND);
    _LCD_Write(PCD8544_SETXADDR, LCD_COMMAND);
  }
#endif
}
//-------------------------Установка шрифта----------------------------------------------------
void setFont(uint8_t* font) //установка шрифта
{
  cfont.font = font;
  cfont.x_size = fontbyte(0);
  cfont.y_size = fontbyte(1);
  cfont.offset = fontbyte(2);
  cfont.numchars = fontbyte(3);
}
//-------------------------Отрисовка изображений----------------------------------------------------
void drawBitmap(uint8_t x, uint8_t y, bitmapdatatype bitmap, uint8_t sx, uint8_t sy, boolean inv) //отрисовка изображений
{
  uint8_t starty, rows;

#if ROTATE_DISP
  starty = y / 8;

  x = 84 - x - sx;
  starty = 5 - starty;

  if (sy % 8 == 0)
    rows = sy / 8;
  else
    rows = (sy / 8) + 1;

  for (uint8_t cy = 0; cy < rows; cy++)
  {
    _LCD_Write(PCD8544_SETYADDR | (starty - cy), LCD_COMMAND);
    _LCD_Write(PCD8544_SETXADDR | x, LCD_COMMAND);
    switch (inv) {
      case 0: for (uint8_t cx = sx; cx > 0; cx--) _LCD_Write(bitmapbyte(cx - 1 + (cy * sx)), LCD_DATA); break;
      case 1: for (uint8_t cx = sx; cx > 0; cx--) _LCD_Write(~(bitmapbyte(cx - 1 + (cy * sx))), LCD_DATA); break;
    }
  }
#else
  starty = y / 8;

  if (sy % 8 == 0)
    rows = sy / 8;
  else
    rows = (sy / 8) + 1;

  for (uint8_t cy = 0; cy < rows; cy++) {
    _LCD_Write(PCD8544_SETYADDR | (starty + cy), LCD_COMMAND);
    _LCD_Write(PCD8544_SETXADDR | x, LCD_COMMAND);
    switch (inv) {
      case 0: for (uint8_t cx = 0; cx < sx; cx++) _LCD_Write(bitmapbyte(cx + (cy * sx)), LCD_DATA); break;
      case 1: for (uint8_t cx = 0; cx < sx; cx++) _LCD_Write(~(bitmapbyte(cx + (cy * sx))), LCD_DATA); break;
    }
  }
#endif
  _LCD_Write(PCD8544_SETYADDR, LCD_COMMAND);
  _LCD_Write(PCD8544_SETXADDR, LCD_COMMAND);
}
