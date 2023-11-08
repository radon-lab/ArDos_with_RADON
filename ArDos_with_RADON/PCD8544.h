#ifdef PCD8544
#define MIN_CONTRAST 0   //минимальное значение контрастности
#define MAX_CONTRAST 127 //максимальное значение контрастности
#define STEP_CONTRAST 1  //шаг значения контрастности

//Сброс дисплея
#define RESET_LCD BIT_SET(DC_PORT, DC_BIT); BIT_SET(MOSI_PORT, MOSI_BIT); BIT_SET(SCK_PORT, SCK_BIT); BIT_CLEAR(RST_PORT, RST_BIT); _delay_ms(10); BIT_SET(RST_PORT, RST_BIT)

//Тип данных дисплея
#define DATA_LCD (BIT_SET(DC_PORT, DC_BIT))
#define COMMAND_LCD (BIT_CLEAR(DC_PORT, DC_BIT))

//Основные команды
#define PCD8544_POWERDOWN 0x04
#define PCD8544_ENTRYMODE 0x02
#define PCD8544_EXTENDEDINSTRUCTION 0x01
#define PCD8544_DISPLAYBLANK 0x00
#define PCD8544_DISPLAYNORMAL 0x04
#define PCD8544_DISPLAYALLON 0x01
#define PCD8544_DISPLAYINVERTED 0x05

//Основные инструкции
#define PCD8544_FUNCTIONSET 0x20
#define PCD8544_DISPLAYCONTROL 0x08
#define PCD8544_SETYADDR 0x40
#define PCD8544_SETXADDR 0x80

//Дополнительные инструкции
#define PCD8544_SETTEMP 0x04
#define PCD8544_SETBIAS 0x10
#define PCD8544_SETVOP 0x80

//Установки дисплея
#define LCD_BIAS 0x03  //(0..7)(0x00..0x07)
#define LCD_TEMP 0x02  //(0..3)(0x00..0x03)
#define LCD_CONTRAST 0x46  //(0..127)(0x00..0x7F)

//-------------------------Инициализация дисплея----------------------------------------------------
void _init_lcd(void) //инициализация дисплея
{
  PWR_LCD_ON; //включаем питание дисплея
  RESET_LCD; //сигнал сброса дисплея
  CE_ON; //включаем шину данных

  COMMAND_LCD;
  writeSPI(PCD8544_FUNCTIONSET | PCD8544_EXTENDEDINSTRUCTION);
  writeSPI(PCD8544_SETVOP | DEFAULT_CONTRAST);
  writeSPI(PCD8544_SETTEMP | LCD_TEMP);
  writeSPI(PCD8544_SETBIAS | LCD_BIAS);
  writeSPI(PCD8544_FUNCTIONSET);
  writeSPI(PCD8544_DISPLAYCONTROL | PCD8544_DISPLAYNORMAL);
  stopWrite(); //остановка обновления дисплея

  clrScr(); //очистка экрана
  setFont(FONT_DATA_NAME); //установка шрифта
}
//-------------------------Установка контрастности----------------------------------------------------
void _set_contrast_lcd(uint8_t contrast) //установка контрастности
{
  COMMAND_LCD;
  writeSPI(PCD8544_FUNCTIONSET | PCD8544_EXTENDEDINSTRUCTION);
  writeSPI(PCD8544_SETVOP | contrast);
  writeSPI(PCD8544_FUNCTIONSET);
  stopWrite(); //остановка обновления дисплея
}
//-------------------------Включение режима сна----------------------------------------------------
void _enable_sleep_lcd(void) //включение режима сна
{
  COMMAND_LCD;
  writeSPI(PCD8544_FUNCTIONSET | PCD8544_POWERDOWN);
  stopWrite(); //остановка обновления дисплея
}
//-------------------------Выключение режима сна----------------------------------------------------
void _disable_sleep_lcd(void) //выключение режима сна
{
  COMMAND_LCD;
  writeSPI(PCD8544_FUNCTIONSET);
  stopWrite(); //остановка обновления дисплея
}
//-------------------------Инверсия экрана----------------------------------------------------
void _invert_lcd(boolean mode) //инверсия экрана
{
  COMMAND_LCD;
  switch (mode) {
    case 0: writeSPI(PCD8544_DISPLAYCONTROL | PCD8544_DISPLAYNORMAL); break;
    case 1: writeSPI(PCD8544_DISPLAYCONTROL | PCD8544_DISPLAYINVERTED); break;
  }
  stopWrite(); //остановка обновления дисплея
}
//----------------------Вывод буфера на экран-----------------------------------------------
void _update_lcd(void) //вывод буфера на экран
{
  switch (display_update) {
    case DISPLAY_IDLE: return;
    case DISPLAY_WRITE:
#if ROTATE_DISP_RETURN
      switch (mainSettings.rotation) {
        case 0:
          writeSPI(*display_cnt++);
          if ((uint16_t)display_cnt >= (uint16_t)(_lcd_buffer + sizeof(_lcd_buffer))) display_update = DISPLAY_STOP;
          break;
        case 1:
          if ((uint16_t)display_cnt-- <= (uint16_t)_lcd_buffer) display_update = DISPLAY_STOP;
          writeRevSPI(*display_cnt);
          break;
      }
#else
#if DEFAULT_ROTATION
      if ((uint16_t)display_cnt-- <= (uint16_t)_lcd_buffer) display_update = DISPLAY_STOP;
      writeRevSPI(*display_cnt);
#else
      writeSPI(*display_cnt++);
      if ((uint16_t)display_cnt >= (uint16_t)(_lcd_buffer + sizeof(_lcd_buffer))) display_update = DISPLAY_STOP;
#endif
#endif
      break;

    case DISPLAY_STOP:
      COMMAND_LCD;
      writeSPI(PCD8544_SETYADDR);
      writeSPI(PCD8544_SETXADDR);

      display_update = DISPLAY_IDLE;
      sleep_status &= ~(0x01 << WAIT_DSP); //сбросили флаг запрета сна
      break;

    default:
#if ROTATE_DISP_RETURN
      switch (mainSettings.rotation) {
        case 0: display_cnt = _lcd_buffer; break;
        case 1: display_cnt = _lcd_buffer + sizeof(_lcd_buffer); break;
      }
#else
#if DEFAULT_ROTATION
      display_cnt = _lcd_buffer + sizeof(_lcd_buffer);
#else
      display_cnt = _lcd_buffer;
#endif
#endif
      COMMAND_LCD;
      writeSPI(PCD8544_SETYADDR);
      writeSPI(PCD8544_SETXADDR);
      DATA_LCD;

      display_update = DISPLAY_WRITE;
      sleep_status |= (0x01 << WAIT_DSP); //установили флаг запрета сна
      break;
  }
}
#endif
