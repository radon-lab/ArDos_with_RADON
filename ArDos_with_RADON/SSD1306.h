#ifdef SSD1306
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

#undef SEARCH_ANIM_DISABLE
#define SEARCH_ANIM_DISABLE 1 //принудительно отключаем анимацию шкалы режима "Поиск"

//-------------------------Очистка блока дисплея----------------------------------------------------
void _clear_block(uint8_t start_x, uint8_t end_x, uint8_t start_y, uint8_t end_y) //очистка блока дисплея
{
  wireBeginTransmission(SSD1306_ADDR, SSD1306_COMMAND_MODE); //начинаем передачу
  wireWrite(SSD1306_COLUMNADDR); //начало колонны
  wireWrite(start_x); //минимальное значение
  wireWrite(end_x); //максимальное значение
  wireWrite(SSD1306_PAGEADDR); //начало страницы
  wireWrite(start_y); //минимальное значение
  wireWrite(end_y); //максимальное значение

  wireBeginTransmission(SSD1306_ADDR, SSD1306_DATA_MODE); //начинаем передачу
  for (uint16_t i = (end_x - start_x + 1) * (end_y - start_y + 1); i; i--) wireWrite(0x00); //очищаем блок
  stopWrite(); //остановка обновления дисплея
}
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
#if SCALE_Y
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

#if !SCALE_Y
  _clear_block(0, 127, 0, 0); //очистка блока дисплея
  _clear_block(0, 127, 7, 7); //очистка блока дисплея
#endif

#if SCALE_X
#if SCALE_Y
  _clear_block(0, 0, 0, 7); //очистка блока дисплея
  _clear_block(127, 127, 0, 7); //очистка блока дисплея
#else
  _clear_block(0, 0, 1, 6); //очистка блока дисплея
  _clear_block(127, 127, 1, 6); //очистка блока дисплея
#endif
#else
#if SCALE_Y
  _clear_block(0, 21, 0, 7); //очистка блока дисплея
  _clear_block(106, 127, 0, 7); //очистка блока дисплея
#else
  _clear_block(0, 21, 1, 6); //очистка блока дисплея
  _clear_block(106, 127, 1, 6); //очистка блока дисплея
#endif
#endif
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

  switch (mode) {
    case 0: wireWrite(SSD1306_NORMALDISPLAY); break;
    case 1: wireWrite(SSD1306_INVERTDISPLAY); break;
  }
  stopWrite(); //остановка обновления дисплея
}
//----------------------Вывод буфера на экран-----------------------------------------------
void _update_lcd(void) //вывод буфера на экран
{
#if SCALE_Y
  static uint8_t data;
  static uint16_t buff;
  static uint8_t pos_x;
  static uint8_t pos_y;
#endif
#if SCALE_X
  static uint8_t copy_x;
  static uint8_t copy_step;
#endif
  switch (display_update) {
    case DISPLAY_IDLE: return;
    case DISPLAY_WRITE:
#if SCALE_Y
      if (pos_x < 84) {
        if (pos_y < 6) {
          data = _lcd_buffer[(pos_y * 84) + pos_x];
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
#if SCALE_X
          if (++copy_x > copy_step) {
            if (++copy_step > 1) copy_step = 0;
            copy_x = 0;
            pos_x++;
          }
#else
          pos_x++;
#endif
        }
      }
      else display_update = DISPLAY_STOP;
#else
      wireWrite(*display_cnt); //отрисовываем буфер
#if SCALE_X
      if (++copy_x > copy_step) {
        if (++copy_step > 1) copy_step = 0;
        copy_x = 0;
        display_cnt++;
        if ((uint16_t)display_cnt >= (uint16_t)(_lcd_buffer + sizeof(_lcd_buffer))) display_update = DISPLAY_STOP;
      }
#else
      display_cnt++;
      if ((uint16_t)display_cnt >= (uint16_t)(_lcd_buffer + sizeof(_lcd_buffer))) display_update = DISPLAY_STOP;
#endif
#endif
      break;

    case DISPLAY_STOP:
      wireEnd(); //остановка шины wire
      display_update = DISPLAY_IDLE;
      sleep_status &= ~(0x01 << WAIT_DSP); //сбросили флаг запрета сна
      break;

    default:
#if SCALE_Y
      data = 0;
      buff = 0;
      pos_x = 0;
      pos_y = 0;
#endif
#if SCALE_X
      copy_x = 0;
      copy_step = 0;
#endif

      display_cnt = _lcd_buffer;

      wireBeginTransmission(SSD1306_ADDR, SSD1306_COMMAND_MODE); //начинаем передачу
#if ROTATE_DISP_RETURN
      switch (mainSettings.rotation) {
        case 0:
          wireWrite(SSD1306_NORMAL_H); //нормальная горизонталь
          wireWrite(SSD1306_NORMAL_V); //нормальная вертикаль
          break;
        case 1:
          wireWrite(SSD1306_FLIP_H); //инверсия горизонтали
          wireWrite(SSD1306_FLIP_V); //инверсия вертикали
          break;
      }
#endif
      wireWrite(SSD1306_COLUMNADDR); //начало колонны
#if SCALE_X
      wireWrite(1); //минимальное значение
      wireWrite(126); //максимальное значение
#else
      wireWrite(22); //минимальное значение
      wireWrite(105); //максимальное значение
#endif
      wireWrite(SSD1306_PAGEADDR); //начало страницы
#if SCALE_Y
      wireWrite(0); //минимальное значение
      wireWrite(7); //максимальное значение
#else
      wireWrite(1); //минимальное значение
      wireWrite(6); //максимальное значение
#endif

      wireBeginTransmission(SSD1306_ADDR, SSD1306_DATA_MODE); //начинаем передачу

      display_update = DISPLAY_WRITE;
      sleep_status |= (0x01 << WAIT_DSP); //установили флаг запрета сна
      break;
  }
}
#endif
