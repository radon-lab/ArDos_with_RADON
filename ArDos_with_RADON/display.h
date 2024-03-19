#include "resources.c"
#include "languages.h"
#include "DefaultFonts.c"

#define fontbyte(x) pgm_read_byte(&cfont.font[x])
#define bitmapbyte(x) pgm_read_byte(&bitmap[x])

//положения текста на дисплее
#define LEFT 0
#define RIGHT 255
#define CENTER 254

#define drawCenter(x, max_x, line) (uint8_t)(x + (max_x - (cfont.x_size * (sizeof(line) - 1))) / 2)

uint8_t _str_cursor; //указатель на последний символ строки
char _str_buffer[14]; //буфер символов строки

uint8_t _lcd_buffer[504]; //буфер дисплея

struct _current_font {
  const uint8_t* font;
  uint8_t x_size;
  uint8_t y_size;
  uint8_t offset;
  boolean inverted;
} cfont;

enum {
  WAIT_WDT, //ожидание основоного таймера
  WAIT_DSP, //ожидание дисплея
  WAIT_ADC, //ожидание АЦП
  WAIT_COMP, //ожидание компаратора
  WAIT_TIM1, //ожидание таймера 1
  WAIT_TIM2, //ожидание таймера 2
  WAIT_PWR1, //режим питания 1
  WAIT_PWR2 //режим питания 2
};

uint8_t sleep_status = 0; //флаги запрета сна
uint8_t display_update = 0;
uint8_t* display_cnt;

void _set_contrast_lcd(uint8_t contrast);
void _invert_lcd(boolean mode);
void _enable_sleep_lcd(void);
void _disable_sleep_lcd(void);
void _update_lcd(void);

void clrScr(void);
void invertText(boolean mode);
void setFont(const uint8_t* font);
void drawLine(uint8_t row, uint8_t start_x = 0, uint8_t end_x = 83, uint8_t line = 0);
void print(const char *st, uint8_t x, uint8_t y);
void printNumI(uint32_t num, uint8_t x, uint8_t y, uint8_t length = 0, char filler = ' ');
void printNumF(float num, uint8_t dec, uint8_t x, uint8_t y, char divider = '.', uint8_t length = 0, char filler = ' ');
void drawBitmap(uint8_t x, uint8_t y, const uint8_t* bitmap, uint8_t size_x, uint8_t size_y);

inline void _clear_buff(void); //очистка буфера

void _print_text(uint8_t x, uint8_t y); //вывод текста
void _print_char(unsigned char c, uint8_t x, uint8_t row, uint8_t steps); //вывод символа

void _add_char(char ch); //запись символа
void _add_text(const char *st); //запись текста
void _add_num_float(float num, uint8_t dec, char divider = '.', uint8_t length = 0, char filler = ' '); //вывод чисел с плавающей точкой
void _add_num_int_f(uint32_t num, uint8_t dec = 0, uint8_t div = 0, char divider = '.',  uint8_t length = 0, char filler = ' '); //вывод целых чисел с точкой
void _add_num_int(uint32_t num, uint8_t length = 0, char filler = ' '); //вывод чисел

enum {
  DISPLAY_IDLE, //дисплей в режиме ожидания
  DISPLAY_INIT, //инициализация передачи изображения на дисплей
  DISPLAY_WRITE, //передача изображения на дисплей
  DISPLAY_STOP //завершение передачи изображения на дисплей
};

void stopWrite(void) //остановка обновления дисплея
{
  display_update = DISPLAY_IDLE; //перешли в режим ожидания
  sleep_status &= ~(0x01 << WAIT_DSP); //сбросили флаг запрета сна
}

#include "SPI.h"
#ifdef PCD8544
#include "PCD8544.h"
#endif
#ifdef SSD1306
#include "SSD1306.h"
#endif

//-------------------------Инверсия текста----------------------------------------------------
void invertText(boolean mode) //инверсия текста
{
  cfont.inverted = mode;
}
//-------------------------Установка шрифта----------------------------------------------------
void setFont(const uint8_t* font) //установка шрифта
{
  cfont.font = font;
  cfont.x_size = fontbyte(0);
  cfont.y_size = fontbyte(1);
  cfont.offset = fontbyte(2);
}
//-------------------------Вывод текста----------------------------------------------------
void print(const char *st, uint8_t x, uint8_t y) //вывод текста
{
  _clear_buff();
  _add_text(st);
  _print_text(x, y);
}
//-------------------------Вывод чисел с плавающей точкой----------------------------------------------------
void printNumF(float num, uint8_t dec, uint8_t x, uint8_t y, char divider, uint8_t length, char filler) //вывод чисел с плавающей точкой
{
  _clear_buff();
  _add_num_float(num, dec, divider, length, filler);
  _print_text(x, y);
}
//-------------------------Вывод чисел----------------------------------------------------
void printNumI(uint32_t num, uint8_t x, uint8_t y, uint8_t length, char filler) //вывод чисел
{
  printNumF(num, 0, x, y, '.', length, filler);
}
//-------------------------Очистка экрана----------------------------------------------------
void clrScr(void) //очистка экрана
{
  if (display_update > DISPLAY_INIT) stopWrite(); //остановка обновления дисплея
  for (uint16_t c = 0; c < 504; c++) _lcd_buffer[c] = 0;
  display_update = DISPLAY_INIT;
}
//-------------------------Отрисовка изображений-----------------------------------------------
void drawBitmap(uint8_t x, uint8_t y, const uint8_t* bitmap, uint8_t size_x, uint8_t size_y) //отрисовка изображений
{
  if (display_update > DISPLAY_INIT) stopWrite(); //остановка обновления дисплея
  uint8_t start_y, rows;

  start_y = y / 8;

  if (size_y % 8 == 0) rows = size_y / 8;
  else rows = (size_y / 8) + 1;

  for (uint8_t cy = 0; cy < rows; cy++) {
    uint16_t cell = (start_y + cy) * 84 + x;
    for (uint8_t cx = 0; cx < size_x; cx++) _lcd_buffer[cell + cx] = bitmapbyte(cx + (cy * size_x));
  }
  display_update = DISPLAY_INIT;
}
//-------------------------Очистка строки----------------------------------------------------
void drawLine(uint8_t row, uint8_t start_x, uint8_t end_x, uint8_t line) //очистка строки
{
  if (display_update > DISPLAY_INIT) stopWrite(); //остановка обновления дисплея
  uint16_t start = start_x + ((uint16_t)row * 84);
  uint16_t end = end_x + ((uint16_t)row * 84);
  for (uint16_t c = start; c <= end; c++) {
    if (!line) _lcd_buffer[c] = 0;
    else _lcd_buffer[c] |= line;
  }
  display_update = DISPLAY_INIT;
}
//------------------------Отрисовка прочерков-------------------------------------------------
void drawDashLine(uint8_t row, uint8_t start_x, uint8_t len_line, uint8_t len_dot, uint8_t line) //отрисовка прочерков
{
  if (display_update > DISPLAY_INIT) stopWrite(); //остановка обновления дисплея
  uint16_t start = start_x + ((uint16_t)row * 84);
  for (uint8_t i = 0; i < len_line; i++) {
    for (uint8_t c = 0; c < len_dot; c++) _lcd_buffer[start++] |= line;
    start += len_dot;
  }
  display_update = DISPLAY_INIT;
}
//--------------------------------Отрисовка графика-------------------------------------
void drawGraf(uint8_t val, uint8_t pos_x, uint8_t height) //отрисовка графика
{
  if (display_update > DISPLAY_INIT) stopWrite(); //остановка обновления дисплея
  for (uint8_t y = 0; y < height; y++) { //отрисовываем строки
    _lcd_buffer[424 - (84 * y) + pos_x] |= pgm_read_byte(&graf_line[(val > 8) ? 8 : val]);
    if (val > 8) val -= 8;
    else val = 0;
  }
  display_update = DISPLAY_INIT;
}
//------------------------Очистка буфера---------------------------------------------------
inline void _clear_buff(void) //очистка буфера
{
  _str_cursor = 0;
}
//------------------------Вывод текста----------------------------------------------------
void _print_text(uint8_t x, uint8_t y) //вывод текста
{
  uint8_t row = 0, steps = 0;

  switch (x) {
    case RIGHT: x = 84 - (_str_cursor * cfont.x_size); break;
    case CENTER: x = (84 - (_str_cursor * cfont.x_size)) / 2; break;
  }

  if (y % 8 == 0) {
    row = y / 8;
    steps = 0;
  }
  else {
    row = (y / 8) + 1;
    steps = 8 - y % 8;
  }

  for (uint8_t cnt = 0; cnt < _str_cursor; cnt++) _print_char(_str_buffer[cnt], x + (cnt * (cfont.x_size)), row, steps);

  setFont(FONT_DATA_NAME); //установка шрифта
}
//-------------------------Отрисовка символа----------------------------------------------------
void _print_char(uint8_t c, uint8_t x, uint8_t row, uint8_t steps) //отрисовка символа
{
  if (display_update > DISPLAY_INIT) stopWrite(); //остановка обновления дисплея
  if (((x + cfont.x_size) <= 84) && (row + (cfont.y_size / 8) <= 6)) {
    for (uint8_t rowcnt = 0; rowcnt < (cfont.y_size / 8); rowcnt++) {
      uint16_t cell = (row + rowcnt) * 84 + x;
      uint16_t font_idx = ((c - cfont.offset) * (cfont.x_size * (cfont.y_size / 8))) + 3;

      for (uint16_t cnt = 0; cnt < cfont.x_size; cnt++) {
        if (cfont.inverted) _lcd_buffer[cell + cnt] = ~(fontbyte(font_idx + cnt + (rowcnt * cfont.x_size)) >> steps);
        else _lcd_buffer[cell + cnt] = fontbyte(font_idx + cnt + (rowcnt * cfont.x_size)) >> steps;
      }
    }
  }
  display_update = DISPLAY_INIT;
}
//------------------------Запись символа---------------------------------------------------
void _add_char(char ch) //запись символа
{
  if (_str_cursor < sizeof(_str_buffer)) {
    _str_buffer[_str_cursor] = ch;
    _str_cursor++;
  }
}
//------------------------Запись текста----------------------------------------------------
void _add_text(const char *st) //запись текста
{
  char ch = 0;
  for (uint8_t i = sizeof(_str_buffer) - _str_cursor; i; i--) {
    ch = pgm_read_byte(st++);
    if (!ch) break;
    else _add_char(ch);
  }
}
//-------------------------Вывод чисел с плавающей точкой----------------------------------------------------
void _add_num_float(float num, uint8_t dec, char divider, uint8_t length, char filler) //вывод чисел с плавающей точкой
{
  char ct[6];
  char ft[6];
  uint8_t c = 0, f = 0, d = 0;
  uint32_t numInt = num;
  float decNum = num - numInt;

  if (numInt) {
    while (numInt > 0) {
      ct[c++] = '0' + (numInt % 10);
      numInt = (numInt - (numInt % 10)) / 10;
    }
  }
  else ct[c++] = '0';

  if (dec) {
    ft[d++] = divider;
    for (uint8_t i = 0; i < dec; i++) {
      decNum *= 10.0;
      ft[d++] = '0' + decNum;
      decNum -= (uint8_t)decNum;
    }
  }

  if (length > (c + d)) {
    while (f++ < (length - (c + d))) _add_char(filler);
  }

  for (uint8_t i = 0; i < c; i++) _add_char(ct[c - i - 1]);
  for (uint8_t i = 0; i < d; i++) _add_char(ft[i]);
}
//-------------------------Вывод чисел----------------------------------------------------
void _add_num_int_f(uint32_t num, uint8_t dec, uint8_t div, char divider, uint8_t length, char filler) //вывод чисел
{
  char buff[10];
  uint8_t cnt = 0;

  if (num) {
    while ((num > 0) && (cnt < 10)) {
      buff[cnt++] = '0' + (num % 10);
      num /= 10;
    }
  }
  else buff[cnt++] = '0';

  while (((dec + div) >= cnt) && (cnt < 10)) {
    buff[cnt++] = '0';
  }

  while (length > (cnt - div + (boolean)dec)) {
    length--;
    _add_char(filler);
  }

  while (cnt > div) {
    if (dec == (cnt - div)) _add_char(divider);
    _add_char(buff[--cnt]);
  }
}
//-------------------------Вывод чисел----------------------------------------------------
void _add_num_int(uint32_t num, uint8_t length, char filler) //вывод чисел
{
  _add_num_int_f(num, 0, 0, '.', length, filler);
}
