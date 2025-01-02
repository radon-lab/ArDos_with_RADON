#include "fonts.c"
#include "resources.c"
#include "languages.h"

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
void printNumIntF(uint32_t num, uint8_t dec, uint8_t div, uint8_t x, uint8_t y, char divider = '.', uint8_t length = 0, char filler = ' ');
void drawBitmap(uint8_t x, uint8_t y, const uint8_t* bitmap, uint8_t size_x, uint8_t size_y);

inline void _clear_buff(void); //очистка буфера

void _print_text(uint8_t x, uint8_t y); //вывод текста
void _print_char(unsigned char c, uint8_t x, uint8_t row, uint8_t steps); //вывод символа

void _add_char(char ch); //запись символа
void _add_text(const char *st); //запись текста
void _add_num_int_f(uint32_t num, uint8_t dec = 0, uint8_t div = 0, char divider = '.',  uint8_t length = 0, char filler = ' '); //добавление целых чисел с точкой
void _add_num_int(uint32_t num, uint8_t length = 0, char filler = ' '); //добавление целых чисел

uint8_t display_update = 0; //состояние обновления дисплея
uint8_t* display_cnt; //указатель на байт буфера дисплея

enum {
  DISPLAY_IDLE, //дисплей в режиме ожидания
  DISPLAY_INIT, //инициализация передачи изображения на дисплей
  DISPLAY_WRITE, //передача изображения на дисплей
  DISPLAY_STOP //завершение передачи изображения на дисплей
};

void stopWrite(void) //остановка обновления дисплея
{
  display_update = DISPLAY_IDLE; //перешли в режим ожидания
  power_status &= ~(0x01 << WAIT_DSP); //сбросили флаг запрета сна
}

#include "SPI.h"
#ifdef PCD8544
#include "PCD8544.h"
#endif
#ifdef SSD1306
#include "SSD1306.h"
#endif

//--------------------------------Инверсия текста-----------------------------------------------------------
void invertText(boolean mode) //инверсия текста
{
  cfont.inverted = mode;
}
//--------------------------------Установка шрифта----------------------------------------------------------
void setFont(const uint8_t* font) //установка шрифта
{
  cfont.font = font;
  cfont.x_size = fontbyte(0);
  cfont.y_size = fontbyte(1);
  cfont.offset = fontbyte(2);
}
//----------------------------------Вывод текста------------------------------------------------------------
void print(const char *st, uint8_t x, uint8_t y) //вывод текста
{
  _clear_buff();
  _add_text(st);
  _print_text(x, y);
}
//------------------------------Вывод чисел с точкой--------------------------------------------------------
void printNumIntF(uint32_t num, uint8_t dec, uint8_t div, uint8_t x, uint8_t y, char divider, uint8_t length, char filler) //вывод чисел с точкой
{
  _clear_buff();
  _add_num_int_f(num, dec, div, divider, length, filler);
  _print_text(x, y);
}
//-------------------------Вывод чисел с плавающей точкой----------------------------------------------------
void printNumF(float num, uint8_t dec, uint8_t x, uint8_t y, char divider, uint8_t length, char filler) //вывод чисел с плавающей точкой
{
  _clear_buff();
  if (dec > 3) dec = 3;
  _add_num_int_f(num * pgm_read_word(&pow_table[dec]), dec, 0, divider, length, filler);
  _print_text(x, y);
}
//-------------------------Вывод чисел----------------------------------------------------
void printNumI(uint32_t num, uint8_t x, uint8_t y, uint8_t length, char filler) //вывод чисел
{
  _clear_buff();
  _add_num_int(num, length, filler);
  _print_text(x, y);
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
//-----------------------Добавление чисел--------------------------------------------------
void _add_num_int_f(uint32_t num, uint8_t dec, uint8_t div, char divider, uint8_t length, char filler) //добавление чисел
{
  boolean st = 0;
  uint8_t ch = 0;
  uint8_t cnt = 0;
  uint32_t tbl = 0;

  div = 10 - div;
  length = div - length + boolean(dec);
  dec = div - dec;

  while (cnt < div) {
    ch = 0;
    tbl = pgm_read_dword(&div_table[cnt]);
    while ((num >= tbl) && (ch < 9)) {
      num -= tbl;
      ch += 1;
    }
    if (cnt == dec) _add_char(divider);
    if (ch) st = 1;
    if (st) _add_char(ch + '0');
    else {
      if (cnt >= (dec - 1)) {
        _add_char('0');
        st = 1;
      }
      else if (cnt >= length) _add_char(filler);
    }
    cnt++;
  }
}
//-----------------------Добавление чисел--------------------------------------------------
void _add_num_int(uint32_t num, uint8_t length, char filler) //добавление чисел
{
  _add_num_int_f(num, 0, 0, '.', length, filler);
}
