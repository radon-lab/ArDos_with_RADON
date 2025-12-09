#define OFF_BACKL 10     //значение яркости при выключенной подсветке
#define MIN_CONTRAST 50  //минимальное значение яркости
#define MAX_CONTRAST 250 //максимальное значение яркости
#define STEP_CONTRAST 10 //шаг значения яркости

//Адрес дисплея
#define SH1106_ADDR 0x3C

//Основные инструкции
#define SH1106_DISPLAY_OFF 0xAE
#define SH1106_DISPLAY_ON 0xAF
#define SH1106_COMMAND_MODE 0x00
#define SH1106_ONE_COMMAND_MODE 0x80
#define SH1106_DATA_MODE 0x40
#define SH1106_ADDRESSING_MODE 0x20
#define SH1106_HORIZONTAL 0x00
#define SH1106_VERTICAL 0x01

//Основные команды
#define SH1106_CONTRAST 0x81
#define SH1106_SETCOMPINS 0xDA
#define SH1106_SETVCOMDETECT 0xDB
#define SH1106_CLOCKDIV 0xD5
#define SH1106_SETMULTIPLEX 0xA8
#define SH1106_CHARGEPUMP 0x8D
#define SH1106_SETCOLUMNADDRL 0x00
#define SH1106_SETCOLUMNADDRH 0x10
#define SH1106_SETPAGEADDR 0xB0

//Дополнительные инструкции
#define SH1106_FLIP_V 0xC0
#define SH1106_FLIP_H 0xA0
#define SH1106_NORMAL_V 0xC8
#define SH1106_NORMAL_H 0xA1
#define SH1106_NORMALDISPLAY 0xA6
#define SH1106_INVERTDISPLAY 0xA7

#include "WIRE.h"

#if defined(SH1106)
#define SH1106_MAX_WIDTH 132
#if DISP_SCALE_IMG
#define SH1106_START_X 3
#define SH1106_START_Y 0
#else
#define SH1106_START_X 24
#define SH1106_START_Y 1
#endif
#elif defined(CH1116)
#define SH1106_MAX_WIDTH 128
#if DISP_SCALE_IMG
#define SH1106_START_X 1
#define SH1106_START_Y 0
#else
#define SH1106_START_X 22
#define SH1106_START_Y 1
#endif
#endif

#undef SEARCH_ANIM_DISABLE
#define SEARCH_ANIM_DISABLE 1 //принудительно отключаем анимацию шкалы режима "Поиск"

//------------------------Установка курсора дисплея------------------------------------------------
void _set_position_lcd(uint8_t x, uint8_t y) //установка курсора дисплея
{
  wireBeginTransmission(SH1106_ADDR, SH1106_COMMAND_MODE);
  wireWrite(SH1106_SETPAGEADDR | y);
  wireWrite(SH1106_SETCOLUMNADDRL | (x & 0x0F));
  wireWrite(SH1106_SETCOLUMNADDRH | ((x >> 4) & 0x0F));
  wireEnd();
}
//-------------------------Инициализация дисплея----------------------------------------------------
void _init_lcd(void) //инициализация дисплея
{
  PWR_LCD_ON; //включаем питание дисплея
  PRR &= ~(0x01 << PRTWI); //включили питание I2C

  wireInit(); //инициализация wire

  if (wireBeginTransmission(SH1106_ADDR, SH1106_COMMAND_MODE, 1500)) return; //начинаем передачу

  wireWrite(SH1106_DISPLAY_OFF); //выключаем дисплей
  wireWrite(SH1106_CLOCKDIV); //пределитель
  wireWrite(0x80); //установили пределитель
  wireWrite(SH1106_CHARGEPUMP); //накачка
  wireWrite(0x14); //установили накачку
  wireWrite(SH1106_ADDRESSING_MODE); //режим адресации

#if !ROTATE_DISP_RETURN && DEFAULT_ROTATION
  wireWrite(SH1106_FLIP_H); //инверсия горизонтали
  wireWrite(SH1106_FLIP_V); //инверсия вертикали
#else
  wireWrite(SH1106_NORMAL_H); //нормальная горизонталь
  wireWrite(SH1106_NORMAL_V); //нормальная вертикаль
#endif

  wireWrite(SH1106_CONTRAST); //контраст
  wireWrite(DEFAULT_CONTRAST); //установили контраст
  wireWrite(SH1106_SETVCOMDETECT);
  wireWrite(0x40);
  wireWrite(SH1106_NORMALDISPLAY); //неинверсный режим
  wireWrite(SH1106_DISPLAY_ON); //включили дисплей

  wireBeginTransmission(SH1106_ADDR, SH1106_COMMAND_MODE); //начинаем передачу
  wireWrite(SH1106_SETCOMPINS);
  wireWrite(0x12);
  wireWrite(SH1106_SETMULTIPLEX);
  wireWrite(0x3F);

  for (uint8_t y = 0; y < 8; y++) {
    _set_position_lcd(0, y); //устанавливаем курсор
    wireBeginTransmission(SH1106_ADDR, SH1106_DATA_MODE); //начинаем передачу
    for (uint8_t i = SH1106_MAX_WIDTH; i; i--) wireWrite(0x00); //очищаем блок
  }

  wireEnd(); //остановка шины wire
  stopWrite(); //остановка обновления дисплея

  clrScr(); //очистка экрана
  setFont(FONT_DATA_NAME); //установка шрифта
}
//-------------------------Установка контрастности--------------------------------------------------
void _set_contrast_lcd(uint8_t contrast) //установка контрастности
{
  wireBeginTransmission(SH1106_ADDR, SH1106_COMMAND_MODE); //начинаем передачу
  wireWrite(SH1106_CONTRAST); //записываем команду
  wireWrite(contrast); //записываем команду
  wireEnd(); //остановка шины wire
  stopWrite(); //остановка обновления дисплея
}
//-------------------------Включение режима сна-----------------------------------------------------
void _enable_sleep_lcd(void) //включение режима сна
{
  wireBeginTransmission(SH1106_ADDR, SH1106_ONE_COMMAND_MODE); //начинаем передачу
  wireWrite(SH1106_DISPLAY_OFF); //выключели дисплей
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

  wireBeginTransmission(SH1106_ADDR, SH1106_ONE_COMMAND_MODE); //начинаем передачу
  wireWrite(SH1106_DISPLAY_ON); //включили дисплей
  wireEnd(); //остановка шины wire
  stopWrite(); //остановка обновления дисплея
}
//-------------------------Инверсия экрана----------------------------------------------------
void _invert_lcd(boolean mode) //инверсия экрана
{
  wireBeginTransmission(SH1106_ADDR, SH1106_ONE_COMMAND_MODE); //начинаем передачу

  if (!mode) wireWrite(SH1106_NORMALDISPLAY);
  else wireWrite(SH1106_INVERTDISPLAY);
  stopWrite(); //остановка обновления дисплея
}
//----------------------Вывод буфера на экран-----------------------------------------------
void _update_lcd(void) //вывод буфера на экран
{
  static uint8_t pos_x;
  static uint8_t pos_y;

#if DISP_SCALE_IMG
  static uint8_t data_0;
  static uint8_t data_1;
#endif
  switch (display_update) {
    case DISPLAY_INIT:
      pos_x = 0;
      pos_y = 0;

#if DISP_SCALE_IMG
      data_0 = 0;
      data_1 = 0;
#endif

      wireBeginTransmission(SH1106_ADDR, SH1106_COMMAND_MODE); //начинаем передачу
#if ROTATE_DISP_RETURN
      if (!mainSettings.rotation) {
        wireWrite(SH1106_NORMAL_H); //нормальная горизонталь
        wireWrite(SH1106_NORMAL_V); //нормальная вертикаль
      }
      else {
        wireWrite(SH1106_FLIP_H); //инверсия горизонтали
        wireWrite(SH1106_FLIP_V); //инверсия вертикали
      }
#endif

      _set_position_lcd(SH1106_START_X, SH1106_START_Y); //устанавливаем курсор
      wireBeginTransmission(SH1106_ADDR, SH1106_DATA_MODE); //начинаем передачу

      display_update = DISPLAY_WRITE;
      power_status |= (0x01 << WAIT_DSP); //установили флаг запрета сна
      break;

    case DISPLAY_WRITE:
#if DISP_SCALE_IMG
      if (pos_y < 8) {
        if (pos_x < 84) {
          switch (pos_y) {
            case 0:
            case 5:
              data_0 = _lcd_buffer[(uint16_t)pos_x + ((pos_y == 5) ? (84 * 4) : 0)];
              data_0 = (data_0 << 1) | (data_0 & 0x01);
              break;
            case 1:
            case 6:
              data_0 = _lcd_buffer[(uint16_t)pos_x + ((pos_y == 6) ? (84 * 4) : 0)];
              data_1 = _lcd_buffer[(uint16_t)pos_x + ((pos_y == 6) ? (84 * 5) : (84 * 1))];
              data_0 = (data_0 >> 7);
              data_0 |= (data_0 << 1);
              data_1 = (data_1 << 3);
              data_0 |= data_1 | ((data_1 & 0x08) >> 1);
              break;
            case 2:
            case 7:
              data_0 = _lcd_buffer[(uint16_t)pos_x + ((pos_y == 7) ? (84 * 5) : (84 * 1))];
              data_0 = (data_0 >> 5);
              data_0 |= ((data_0 & 0x04) << 1);
              if (pos_y == 2) {
                data_1 = _lcd_buffer[(uint16_t)pos_x + (84 * 2)];
                data_1 = (data_1 << 5);
                data_0 |= data_1 | ((data_1 & 0x20) >> 1);
              }
              break;
            case 3:
              data_0 = _lcd_buffer[(uint16_t)pos_x + (84 * 2)];
              data_1 = _lcd_buffer[(uint16_t)pos_x + (84 * 3)];
              data_0 = (data_0 >> 3);
              data_0 |= ((data_0 & 0x10) << 1);
              data_1 = ((data_1 & 0x01) << 7);
              data_0 |= data_1 | (data_1 >> 1);
              break;
            case 4:
              data_0 = _lcd_buffer[(uint16_t)pos_x + (84 * 3)];
              data_0 = (data_0 >> 1);
              data_0 |= ((data_0 & 0x40) << 1);
              break;
          }

          wireWrite(data_0); //отрисовываем буфер
          if (pos_x & 0x01) wireWrite(data_0); //отрисовываем буфер
          pos_x++;
        }
        else {
          pos_y++;
          pos_x = 0;
          _set_position_lcd(SH1106_START_X, pos_y); //устанавливаем курсор
          wireBeginTransmission(SH1106_ADDR, SH1106_DATA_MODE); //начинаем передачу
        }
      }
      else display_update = DISPLAY_STOP;
#else
      if (pos_x < 84) {
        wireWrite((uint8_t)_lcd_buffer[(uint16_t)(pos_y * 84) + pos_x]);
        pos_x++;
      }
      else {
        pos_x = 0;
        if (++pos_y >= 6) display_update = DISPLAY_STOP;
        else {
          _set_position_lcd(SH1106_START_X, pos_y + 1); //устанавливаем курсор
          wireBeginTransmission(SH1106_ADDR, SH1106_DATA_MODE); //начинаем передачу
        }
      }
#endif
      break;

    case DISPLAY_STOP:
      wireEnd(); //остановка шины wire
      display_update = DISPLAY_IDLE;
      power_status &= ~(0x01 << WAIT_DSP); //сбросили флаг запрета сна
      break;
  }
}
