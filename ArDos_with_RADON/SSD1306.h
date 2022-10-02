#ifdef SSD1306
#define MAX_CONTRAST 255 //максимальное значение яркости

#define WIRE_PULL 1 //подтяжка шины I2C

#define SSD1306_ADDR 0x3C //адрес дисплея

//Основные инструкции
#define SSD1306_DISPLAY_OFF 0xAE
#define SSD1306_DISPLAY_ON 0xAF
#define SSD1306_COMMAND_MODE 0x00
#define SSD1306_ONE_COMMAND_MODE 0x80
#define SSD1306_DATA_MODE 0x40
#define SSD1306_ADDRESSING_MODE 0x20
#define SSD1306_HORIZONTAL 0x00

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

//-----------------------------Отправка команд на дисплей-------------------------------------
void _LCD_Write_Command(uint8_t data)
{
  wireBeginTransmission(SSD1306_ADDR); //начинаем передачу
  wireWrite(SSD1306_ONE_COMMAND_MODE); //записываем команду
  wireWrite(data); //записываем команду
  wireEnd(); //остановка шины wire
}
//-------------------------Инициализация дисплея----------------------------------------------------
void _init_lcd(void) //инициализация дисплея
{
  PRR &= ~(0x01 << PRTWI);
  PWR_LCD_ON; //включаем питание дисплея
  wireInit(); //инициализация wire

  wireBeginTransmission(SSD1306_ADDR); //начинаем передачу
  wireWrite(SSD1306_COMMAND_MODE); //режим передачи команд

  wireWrite(SSD1306_DISPLAY_OFF); //выключаем дисплей
  wireWrite(SSD1306_CLOCKDIV); //пределитель
  wireWrite(0x80); //установили пределитель
  wireWrite(SSD1306_CHARGEPUMP); //накачка
  wireWrite(0x14); //установили накачку
  wireWrite(SSD1306_ADDRESSING_MODE); //режим адресации
  wireWrite(SSD1306_HORIZONTAL); //горизонтальный режим
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
  wireEnd(); //остановка шины wire

  wireBeginTransmission(SSD1306_ADDR); //начинаем передачу
  wireWrite(SSD1306_COMMAND_MODE); //режим передачи команд

  wireWrite(SSD1306_SETCOMPINS);
  wireWrite(0x12);
  wireWrite(SSD1306_SETMULTIPLEX);
  wireWrite(0x3F);
  wireEnd(); //остановка шины wire

  setFont(FONT_DATA_NAME); //установка шрифта
}
//-------------------------Установка контрастности----------------------------------------------------
void setContrast(uint8_t contrast) //установка контрастности
{
  wireBeginTransmission(SSD1306_ADDR); //начинаем передачу
  wireWrite(SSD1306_COMMAND_MODE); //режим передачи команд

  wireWrite(SSD1306_CONTRAST); //записываем команду
  wireWrite(contrast); //записываем команду
  wireEnd(); //остановка шины wire
}
//-------------------------Включение режима сна----------------------------------------------------
void enableSleep(void) //включение режима сна
{
  wireBeginTransmission(SSD1306_ADDR); //начинаем передачу
  wireWrite(SSD1306_ONE_COMMAND_MODE); //режим передачи команды

  wireWrite(SSD1306_DISPLAY_OFF); //выключели дисплей
  wireEnd(); //остановка шины wire

  PRR |= (0x01 << PRTWI); //выключили питание I2C
  PWR_LCD_OFF; //включаем питание дисплея
}
//-------------------------Выключение режима сна----------------------------------------------------
void disableSleep(uint8_t contrast) //выключение режима сна
{
  _init_lcd(); //инициализация дисплея
  setContrast(contrast); //установка контрастности
  clrScr(); //очистка экрана
}
//-------------------------Инверсия экрана----------------------------------------------------
void invert(boolean mode) //инверсия экрана
{
  wireBeginTransmission(SSD1306_ADDR); //начинаем передачу
  wireWrite(SSD1306_ONE_COMMAND_MODE); //режим передачи команд

  switch (mode) {
    case 0: wireWrite(SSD1306_NORMALDISPLAY); break;
    case 1: wireWrite(SSD1306_INVERTDISPLAY); break;
  }
  wireEnd(); //остановка шины wire
}
//----------------------Вывод буфера на экран-----------------------------------------------
void showScr(void) //вывод буфера на экран
{
  wireBeginTransmission(SSD1306_ADDR); //начинаем передачу
  wireWrite(SSD1306_COMMAND_MODE); //режим передачи команд

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
  wireWrite(0x16); //минимальное значение
  wireWrite(0x69); //максимальное значение
  wireWrite(SSD1306_PAGEADDR); //начало страницы
  wireWrite(0x01); //минимальное значение
  wireWrite(0x06); //максимальное значение

  wireBeginTransmission(SSD1306_ADDR); //начинаем передачу
  wireWrite(SSD1306_DATA_MODE); //режим передачи данных

  for (uint16_t i = 0; i < 504; i++) wireWrite(_lcd_buffer[i]); //отрисовываем буфер
  wireEnd(); //остановка шины wire
}
#endif
