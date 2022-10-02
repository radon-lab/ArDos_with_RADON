#ifdef PCD8544
#define MAX_CONTRAST 127 //максимальное значение контрастности

//Сброс дисплея
#define RESET_LCD BIT_SET(DC_PORT, DC_BIT); BIT_SET(MOSI_PORT, MOSI_BIT); BIT_SET(SCK_PORT, SCK_BIT); BIT_CLEAR(RST_PORT, RST_BIT); _delay_ms(10); BIT_SET(RST_PORT, RST_BIT)

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

void _LCD_Write_Command(uint8_t data);
void _LCD_Write_Data_Dir(void);
void _LCD_Write_Data_Inv(void);
void _init_lcd(void);

//-----------------------------Отправка команд на дисплей-------------------------------------
void _LCD_Write_Command(uint8_t data)
{
  __asm__ __volatile__ (
    "CBI %[_DC_PORT], %[_DC_PIN]      \n\t" //LOW на выход пина команд
    "LDI r19, 8                       \n\t" //счетчик циклов байта
    //-----------------------------------------------------------------------------------------
    "_LOOP_START_%=:                  \n\t" //начало цикла отправки бита
    "SBI %[_MOSI_PORT], %[_MOSI_PIN]  \n\t" //HIGH на выход пина бит
    "SBRS %[DATA], 7                  \n\t" //если бит "7" установлен то пропускаем переход
    "CBI %[_MOSI_PORT], %[_MOSI_PIN]  \n\t" //LOW на выход пина бит
    //-----------------------------------------------------------------------------------------
    "CBI %[_SCK_PORT], %[_SCK_PIN]    \n\t" //LOW на выход пина такта
    "LSL %[DATA]                      \n\t" //сдвигаем байт влево
    "SBI %[_SCK_PORT], %[_SCK_PIN]    \n\t" //HIGH на выход пина такта
    "DEC r19                          \n\t" //декремент счетчика циклов байта
    "BRNE _LOOP_START_%=              \n\t" //переход в начало цикла отправки бита
    :"=r"(data)
    :[DATA]"0"(data),
    [_DC_PORT]"I"(_SFR_IO_ADDR(DC_PORT)),
    [_DC_PIN]"I"(DC_BIT),
    [_MOSI_PORT]"I"(_SFR_IO_ADDR(MOSI_PORT)),
    [_MOSI_PIN]"I"(MOSI_BIT),
    [_SCK_PORT]"I"(_SFR_IO_ADDR(SCK_PORT)),
    [_SCK_PIN]"I"(SCK_BIT)
  );
}
//--------------------------------Отправка данных на дисплей(прямое)----------------------------------
void _LCD_Write_Data_Dir(void)
{
  __asm__ __volatile__ (
    "SBI %[_DC_PORT], %[_DC_PIN]      \n\t" //HIGH на выход пина команд
    //-----------------------------------------------------------------------------------------
    "_BYTE_START_%=:                  \n\t" //начало цикла отправки байта
    "LD r21, X+                       \n\t" //загрузили байт из масива
    "LDI r19, 8                       \n\t" //счетчик циклов байта
    //-----------------------------------------------------------------------------------------
    "_LOOP_START_%=:                  \n\t" //начало цикла отправки бита
    "SBI %[_MOSI_PORT], %[_MOSI_PIN]  \n\t" //HIGH на выход пина бит
    "SBRS r21, 7                      \n\t" //если бит "7" установлен то пропускаем переход
    "CBI %[_MOSI_PORT], %[_MOSI_PIN]  \n\t" //LOW на выход пина бит
    //-----------------------------------------------------------------------------------------
    "CBI %[_SCK_PORT], %[_SCK_PIN]    \n\t" //LOW на выход пина такта
    "LSL r21                          \n\t" //сдвигаем байт влево
    "SBI %[_SCK_PORT], %[_SCK_PIN]    \n\t" //HIGH на выход пина такта
    "DEC r19                          \n\t" //декремент счетчика циклов байта
    "BRNE _LOOP_START_%=              \n\t" //переход в начало цикла отправки бита
    //-----------------------------------------------------------------------------------------
    "SBIW %[COUNT], 1                 \n\t" //отнимаем от счетчика байт
    "BRNE _BYTE_START_%=              \n\t" //переход к загрузке нового байта
    :
    :"x"(_lcd_buffer),
    [COUNT]"w"(sizeof(_lcd_buffer)),
    [_DC_PORT]"I"(_SFR_IO_ADDR(DC_PORT)),
    [_DC_PIN]"I"(DC_BIT),
    [_MOSI_PORT]"I"(_SFR_IO_ADDR(MOSI_PORT)),
    [_MOSI_PIN]"I"(MOSI_BIT),
    [_SCK_PORT]"I"(_SFR_IO_ADDR(SCK_PORT)),
    [_SCK_PIN]"I"(SCK_BIT)
  );
}
//--------------------------------Отправка данных на дисплей(перевернутое)----------------------------------
void _LCD_Write_Data_Inv(void)
{
  __asm__ __volatile__ (
    "SBI %[_DC_PORT], %[_DC_PIN]      \n\t" //HIGH на выход пина команд
    //-----------------------------------------------------------------------------------------
    "_BYTE_START_%=:                  \n\t" //начало цикла отправки байта
    "LD r21, -X                       \n\t" //загрузили байт из масива
    "LDI r19, 8                       \n\t" //счетчик циклов байта
    //-----------------------------------------------------------------------------------------
    "_LOOP_START_%=:                  \n\t" //начало цикла отправки бита
    "SBI %[_MOSI_PORT], %[_MOSI_PIN]  \n\t" //HIGH на выход пина бит
    "SBRS r21, 0                      \n\t" //если бит "0" установлен то пропускаем переход
    "CBI %[_MOSI_PORT], %[_MOSI_PIN]  \n\t" //LOW на выход пина бит
    //-----------------------------------------------------------------------------------------
    "CBI %[_SCK_PORT], %[_SCK_PIN]    \n\t" //LOW на выход пина такта
    "LSR r21                          \n\t" //сдвигаем байт вправо
    "SBI %[_SCK_PORT], %[_SCK_PIN]    \n\t" //HIGH на выход пина такта
    "DEC r19                          \n\t" //декремент счетчика циклов байта
    "BRNE _LOOP_START_%=              \n\t" //переход в начало цикла отправки бита
    //-----------------------------------------------------------------------------------------
    "SBIW %[COUNT], 1                 \n\t" //отнимаем от счетчика байт
    "BRNE _BYTE_START_%=              \n\t" //переход к загрузке нового байта
    :
    :"x"(_lcd_buffer + sizeof(_lcd_buffer)),
    [COUNT]"w"(sizeof(_lcd_buffer)),
    [_DC_PORT]"I"(_SFR_IO_ADDR(DC_PORT)),
    [_DC_PIN]"I"(DC_BIT),
    [_MOSI_PORT]"I"(_SFR_IO_ADDR(MOSI_PORT)),
    [_MOSI_PIN]"I"(MOSI_BIT),
    [_SCK_PORT]"I"(_SFR_IO_ADDR(SCK_PORT)),
    [_SCK_PIN]"I"(SCK_BIT)
  );
}
//-------------------------Инициализация дисплея----------------------------------------------------
void _init_lcd(void) //инициализация дисплея
{
  RESET_LCD; //команда перезагрузки дисплея
  disableSleep(DEFAULT_CONTRAST); //инициализация дисплея
  setFont(FONT_DATA_NAME); //установка шрифта
}
//-------------------------Установка контрастности----------------------------------------------------
void setContrast(uint8_t contrast) //установка контрастности
{
  _LCD_Write_Command(PCD8544_FUNCTIONSET | PCD8544_EXTENDEDINSTRUCTION);
  _LCD_Write_Command(PCD8544_SETVOP | contrast);
  _LCD_Write_Command(PCD8544_FUNCTIONSET);
}
//-------------------------Включение режима сна----------------------------------------------------
void enableSleep(void) //включение режима сна
{
  _LCD_Write_Command(PCD8544_FUNCTIONSET | PCD8544_POWERDOWN);
}
//-------------------------Выключение режима сна----------------------------------------------------
void disableSleep(uint8_t contrast) //выключение режима сна
{
  _LCD_Write_Command(PCD8544_FUNCTIONSET | PCD8544_EXTENDEDINSTRUCTION);
  _LCD_Write_Command(PCD8544_SETVOP | contrast);
  _LCD_Write_Command(PCD8544_SETTEMP | LCD_TEMP);
  _LCD_Write_Command(PCD8544_SETBIAS | LCD_BIAS);
  _LCD_Write_Command(PCD8544_FUNCTIONSET);
  _LCD_Write_Command(PCD8544_DISPLAYCONTROL | PCD8544_DISPLAYNORMAL);
  clrScr(); //очистка экрана
}
//-------------------------Инверсия экрана----------------------------------------------------
void invert(boolean mode) //инверсия экрана
{
  switch (mode) {
    case 0: _LCD_Write_Command(PCD8544_DISPLAYCONTROL | PCD8544_DISPLAYNORMAL); break;
    case 1: _LCD_Write_Command(PCD8544_DISPLAYCONTROL | PCD8544_DISPLAYINVERTED); break;
  }
}
//----------------------Вывод буфера на экран-----------------------------------------------
void showScr(void) //вывод буфера на экран
{
  _LCD_Write_Command(PCD8544_SETYADDR);
  _LCD_Write_Command(PCD8544_SETXADDR);
#if ROTATE_DISP_RETURN
  switch (mainSettings.rotation) {
    case 0: _LCD_Write_Data_Dir(); break;
    case 1: _LCD_Write_Data_Inv(); break;
  }
#else
#if DEFAULT_ROTATION
  _LCD_Write_Data_Inv();
#else
  _LCD_Write_Data_Dir();
#endif
#endif
  _LCD_Write_Command(PCD8544_SETYADDR);
  _LCD_Write_Command(PCD8544_SETXADDR);
}
#endif
