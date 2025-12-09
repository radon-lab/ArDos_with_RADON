#define OFF_BACKL 10     //значение яркости при выключенной подсветке
#define MIN_CONTRAST 50  //минимальное значение яркости
#define MAX_CONTRAST 250 //максимальное значение яркости
#define STEP_CONTRAST 10 //шаг значения яркости

//Адрес дисплея
#define SSD1306_ADDR 0x3C

//Основные инструкции
#define SSD1306_DISPLAY_OFF 0xAE
#define SSD1306_DISPLAY_ON 0xAF
#define SSD1306_COMMAND_MODE 0x00
#define SSD1306_ONE_COMMAND_MODE 0x80
#define SSD1306_DATA_MODE 0x40
#define SSD1306_ADDRESSING_MODE 0x20
#define SSD1306_HORIZONTAL 0x00
#define SSD1306_VERTICAL 0x01

//Основные команды
#define SSD1306_CONTRAST 0x81
#define SSD1306_SETCOMPINS 0xDA
#define SSD1306_SETVCOMDETECT 0xDB
#define SSD1306_CLOCKDIV 0xD5
#define SSD1306_SETMULTIPLEX 0xA8
#define SSD1306_COLUMNADDR 0x21
#define SSD1306_PAGEADDR 0x22
#define SSD1306_CHARGEPUMP 0x8D

//Дополнительные инструкции
#define SSD1306_FLIP_V 0xC0
#define SSD1306_FLIP_H 0xA0
#define SSD1306_NORMAL_V 0xC8
#define SSD1306_NORMAL_H 0xA1
#define SSD1306_NORMALDISPLAY 0xA6
#define SSD1306_INVERTDISPLAY 0xA7

#include "WIRE.h"

#if DISP_SCALE_IMG
#define SSD1306_START_X 1
#define SSD1306_END_X 126
#define SSD1306_START_Y 0
#define SSD1306_END_Y 7
#else
#define SSD1306_START_X 22
#define SSD1306_END_X 105
#define SSD1306_START_Y 1
#define SSD1306_END_Y 6
#endif

#undef SEARCH_ANIM_DISABLE
#define SEARCH_ANIM_DISABLE 1 //принудительно отключаем анимацию шкалы режима "Поиск"

//-------------------------Инициализация дисплея----------------------------------------------------
void _init_lcd(void) //инициализация дисплея
{
  PWR_LCD_ON; //включаем питание дисплея
  PRR &= ~(0x01 << PRTWI); //включили питание I2C

  wireInit(); //инициализация wire

  if (wireBeginTransmission(SSD1306_ADDR, SSD1306_COMMAND_MODE, 1000)) return; //начинаем передачу

  wireWrite(SSD1306_DISPLAY_OFF); //выключаем дисплей
  wireWrite(SSD1306_CLOCKDIV); //пределитель
  wireWrite(0x80); //установили пределитель
  wireWrite(SSD1306_CHARGEPUMP); //накачка
  wireWrite(0x14); //установили накачку
  wireWrite(SSD1306_ADDRESSING_MODE); //режим адресации
#if DISP_SCALE_IMG
  wireWrite(SSD1306_VERTICAL); //вертикальный режим
#else
  wireWrite(SSD1306_HORIZONTAL); //горизонтальный режим
#endif

#if !ROTATE_DISP_RETURN && DEFAULT_ROTATION
  wireWrite(SSD1306_FLIP_H); //инверсия горизонтали
  wireWrite(SSD1306_FLIP_V); //инверсия вертикали
#else
  wireWrite(SSD1306_NORMAL_H); //нормальная горизонталь
  wireWrite(SSD1306_NORMAL_V); //нормальная вертикаль
#endif

  wireWrite(SSD1306_CONTRAST); //контраст
  wireWrite(DEFAULT_CONTRAST); //установили контраст
  wireWrite(SSD1306_SETVCOMDETECT);
  wireWrite(0x40);
  wireWrite(SSD1306_NORMALDISPLAY); //неинверсный режим
  wireWrite(SSD1306_DISPLAY_ON); //включили дисплей

  wireBeginTransmission(SSD1306_ADDR, SSD1306_COMMAND_MODE); //начинаем передачу
  wireWrite(SSD1306_SETCOMPINS);
  wireWrite(0x12);
  wireWrite(SSD1306_SETMULTIPLEX);
  wireWrite(0x3F);

  wireBeginTransmission(SSD1306_ADDR, SSD1306_COMMAND_MODE); //начинаем передачу
  wireWrite(SSD1306_COLUMNADDR); //начало колонны
  wireWrite(0); //минимальное значение
  wireWrite(127); //максимальное значение
  wireWrite(SSD1306_PAGEADDR); //начало страницы
  wireWrite(0); //минимальное значение
  wireWrite(7); //максимальное значение

  wireBeginTransmission(SSD1306_ADDR, SSD1306_DATA_MODE); //начинаем передачу
  for (uint16_t i = 1024; i; i--) wireWrite(0x00); //очищаем блок

  wireEnd(); //остановка шины wire
  stopWrite(); //остановка обновления дисплея

  clrScr(); //очистка экрана
  setFont(FONT_DATA_NAME); //установка шрифта
}
//-------------------------Установка контрастности--------------------------------------------------
void _set_contrast_lcd(uint8_t contrast) //установка контрастности
{
  wireBeginTransmission(SSD1306_ADDR, SSD1306_COMMAND_MODE); //начинаем передачу
  wireWrite(SSD1306_CONTRAST); //записываем команду
  wireWrite(contrast); //записываем команду
  wireEnd(); //остановка шины wire
  stopWrite(); //остановка обновления дисплея
}
//-------------------------Включение режима сна-----------------------------------------------------
void _enable_sleep_lcd(void) //включение режима сна
{
  wireBeginTransmission(SSD1306_ADDR, SSD1306_ONE_COMMAND_MODE); //начинаем передачу
  wireWrite(SSD1306_DISPLAY_OFF); //выключели дисплей
  wireEnd(); //остановка шины wire
  wireWait(); //ожидание остановки шины
  stopWrite(); //остановка обновления дисплея

  PRR |= (0x01 << PRTWI); //выключили питание I2C
}
//-------------------------Выключение режима сна----------------------------------------------------
void _disable_sleep_lcd(void) //выключение режима сна
{
  PRR &= ~(0x01 << PRTWI); //включили питание I2C

  wireInit(); //инициализация wire

  wireBeginTransmission(SSD1306_ADDR, SSD1306_ONE_COMMAND_MODE); //начинаем передачу
  wireWrite(SSD1306_DISPLAY_ON); //включили дисплей
  wireEnd(); //остановка шины wire
  stopWrite(); //остановка обновления дисплея
}
//-------------------------Инверсия экрана----------------------------------------------------
void _invert_lcd(boolean mode) //инверсия экрана
{
  wireBeginTransmission(SSD1306_ADDR, SSD1306_ONE_COMMAND_MODE); //начинаем передачу

  if (!mode) wireWrite(SSD1306_NORMALDISPLAY);
  else wireWrite(SSD1306_INVERTDISPLAY);
  stopWrite(); //остановка обновления дисплея
}
//----------------------Вывод буфера на экран-----------------------------------------------
void _update_lcd(void) //вывод буфера на экран
{
#if DISP_SCALE_IMG
  static uint8_t data;
  static uint16_t buff;
  static uint8_t pos_x;
  static uint8_t pos_y;
  static uint8_t copy_x;
  static uint8_t copy_step;
#else
  static uint8_t* display_cnt; //указатель на байт буфера дисплея
#endif

  switch (display_update) {
    case DISPLAY_INIT:
#if DISP_SCALE_IMG
      data = 0;
      buff = 0;
      pos_x = 0;
      pos_y = 0;
      copy_x = 0;
      copy_step = 0;
#else
      display_cnt = _lcd_buffer;
#endif

      wireBeginTransmission(SSD1306_ADDR, SSD1306_COMMAND_MODE); //начинаем передачу
#if ROTATE_DISP_RETURN
      if (!mainSettings.rotation) {
        wireWrite(SSD1306_NORMAL_H); //нормальная горизонталь
        wireWrite(SSD1306_NORMAL_V); //нормальная вертикаль
      }
      else {
        wireWrite(SSD1306_FLIP_H); //инверсия горизонтали
        wireWrite(SSD1306_FLIP_V); //инверсия вертикали
      }
#endif

      wireWrite(SSD1306_COLUMNADDR); //начало колонны
      wireWrite(SSD1306_START_X); //минимальное значение
      wireWrite(SSD1306_END_X); //максимальное значение
      wireWrite(SSD1306_PAGEADDR); //начало страницы
      wireWrite(SSD1306_START_Y); //минимальное значение
      wireWrite(SSD1306_END_Y); //максимальное значение

      wireBeginTransmission(SSD1306_ADDR, SSD1306_DATA_MODE); //начинаем передачу

      display_update = DISPLAY_WRITE;
      power_status |= (0x01 << WAIT_DSP); //установили флаг запрета сна
      break;

    case DISPLAY_WRITE:
#if DISP_SCALE_IMG
      if (pos_x < 84) {
        if (pos_y < 6) {
          data = _lcd_buffer[(uint16_t)(pos_y * 84) + pos_x];
          switch (pos_y) {
            case 4:
            case 0:
              buff = (uint16_t)data << 1;
              wireWrite((uint8_t)buff | (data & 0x01)); //отрисовываем буфер
              buff >>= 8;
              buff |= buff << 1;
              break;
            case 5:
            case 1:
              buff |= (uint16_t)data << 3;
              wireWrite((uint8_t)buff | ((data & 0x01) << 2)); //отрисовываем буфер
              buff >>= 8;
              buff |= (buff << 1) & 0x08;
              if (pos_y == 5) wireWrite((uint8_t)buff); //отрисовываем буфер
              break;
            case 2:
              buff |= (uint16_t)data << 5;
              wireWrite((uint8_t)buff | ((data & 0x01) << 4)); //отрисовываем буфер
              buff >>= 8;
              buff |= (buff << 1) & 0x20;
              break;
            case 3:
              buff |= (uint16_t)data << 7;
              wireWrite((uint8_t)buff | ((data & 0x01) << 6)); //отрисовываем буфер
              buff >>= 8;
              buff |= (buff << 1) & 0x80;
              wireWrite((uint8_t)buff); //отрисовываем буфер
              break;
          }
          pos_y++;
        }
        else {
          pos_y = 0;

          if (++copy_x > copy_step) {
            if (++copy_step > 1) copy_step = 0;
            copy_x = 0;
            pos_x++;
          }
        }
      }
      else display_update = DISPLAY_STOP;
#else
      wireWrite(*display_cnt); //отрисовываем буфер
      display_cnt++;
      if ((uint16_t)display_cnt >= (uint16_t)(_lcd_buffer + sizeof(_lcd_buffer))) display_update = DISPLAY_STOP;
#endif
      break;

    case DISPLAY_STOP:
      wireEnd(); //остановка шины wire
      display_update = DISPLAY_IDLE;
      power_status &= ~(0x01 << WAIT_DSP); //сбросили флаг запрета сна
      break;
  }
}
