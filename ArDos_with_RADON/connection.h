//Соединения периферии с портами МК 
//    PORTD (2 - D2 | 3 - D3 | 4 - D4 | 5 - D5 | 6 - D6 | 7 - D7) PIND
//  PORTB (0 - D8 | 1 - D9 | 2 - D10 | 3 - D11 | 4 - D12 | 5 - D13) PINB
//    PORTC (0 - A0 | 1 - A1 | 2 - A2 | 3 - A3 | 4 - A4 | 5 - A5) PINC

#define DDR_REG(portx)  (*(&portx - 1))
#define PIN_REG(portx)  (*(&portx - 2))
#define BIT_READ(value, bit) (((value) >> (bit)) & 0x01)
#define BIT_INV(value, bit) ((value) ^= (0x01 << (bit)))
#define BIT_SET(value, bit) ((value) |= (0x01 << (bit)))
#define BIT_CLEAR(value, bit) ((value) &= ~(0x01 << (bit)))
#define BIT_WRITE(value, bit, bitvalue) (bitvalue ? BIT_SET(value, bit) : BIT_CLEAR(value, bit))

//обьявляем дисплей с указанием пинов подключения
//пин SCK дисплея A1
#define SCK_BIT  1
#define SCK_PORT PORTC
#define SCK_CLR  (BIT_CLEAR(SCK_PORT, SCK_BIT))
#define SCK_OUT  (BIT_SET((DDR_REG(SCK_PORT)), SCK_BIT))

//пин MOSI дисплея A0
#define MOSI_BIT  0
#define MOSI_PORT PORTC
#define MOSI_CLR  (BIT_CLEAR(MOSI_PORT, MOSI_BIT))
#define MOSI_OUT  (BIT_SET((DDR_REG(MOSI_PORT)), MOSI_BIT))

//пин DC дисплея D12
#define DC_BIT  4
#define DC_PORT PORTB
#define DC_CLR  (BIT_CLEAR(DC_PORT, DC_BIT))
#define DC_OUT  (BIT_SET((DDR_REG(DC_PORT)), DC_BIT))

//пин RST дисплея D10
#define RST_BIT  2
#define RST_PORT PORTB
#define RST_CLR  (BIT_CLEAR(RST_PORT, RST_BIT))
#define RST_OUT  (BIT_SET((DDR_REG(RST_PORT)), RST_BIT))

//пин CE дисплея D11
#define LCD_BIT   3 // D11
#define LCD_PORT  PORTB
#define LCD_ON    (BIT_CLEAR(LCD_PORT, LCD_BIT))
#define LCD_OUT   (BIT_SET((DDR_REG(LCD_PORT)), LCD_BIT))

#define LCD_INIT  SCK_CLR; SCK_OUT; MOSI_CLR; MOSI_OUT; DC_CLR; DC_OUT; RST_CLR; RST_OUT; LCD_ON; LCD_OUT

//назначаем кнопки//
//пин кнопки ОК D3
#define OK_BIT   3 // D3
#define OK_PORT  PORTD

#define OK_OUT   (BIT_READ(PIN_REG(OK_PORT), OK_BIT))
#define OK_SET   (BIT_SET(OK_PORT, OK_BIT))
#define OK_INP   (BIT_CLEAR((DDR_REG(OK_PORT)), OK_BIT))

#define OK_INIT  OK_SET; OK_INP

//пин кнопки DOWN D7
#define DOWN_BIT   7 // D7
#define DOWN_PORT  PORTD

#define DOWN_OUT   (BIT_READ(PIN_REG(DOWN_PORT), DOWN_BIT))
#define DOWN_SET   (BIT_SET(DOWN_PORT, DOWN_BIT))
#define DOWN_INP   (BIT_CLEAR((DDR_REG(DOWN_PORT)), DOWN_BIT))

#define DOWN_INIT  DOWN_SET; DOWN_INP

//пин кнопки UP D4
#define UP_BIT   4 // D4
#define UP_PORT  PORTD

#define UP_OUT   (BIT_READ(PIN_REG(UP_PORT), UP_BIT))
#define UP_SET   (BIT_SET(UP_PORT, UP_BIT))
#define UP_INP   (BIT_CLEAR((DDR_REG(UP_PORT)), UP_BIT))

#define UP_INIT  UP_SET; UP_INP

//пин пищалки
#define BUZZ_BIT   6 // D6
#define BUZZ_PORT  PORTD

#define BUZZ_OFF   (BIT_CLEAR(BUZZ_PORT, BUZZ_BIT))
#define BUZZ_ON    (BIT_SET(BUZZ_PORT, BUZZ_BIT))
#define BUZZ_OUT   (BIT_SET((DDR_REG(BUZZ_PORT)), BUZZ_BIT))

#define BUZZ_INIT  BUZZ_OFF; BUZZ_OUT

//пин детектора
#define DET_1_BIT   2 // D2
#define DET_1_PORT  PORTD

#define DET_1_SET   (BIT_SET(DET_1_PORT, DET_1_BIT))
#define DET_1_INP   (BIT_CLEAR((DDR_REG(DET_1_PORT)), DET_1_BIT))

#define DET_1_INIT  DET_1_SET; DET_1_INP

//пин преобразователя
#define CONV_BIT   5 // D5
#define CONV_PORT  PORTD

#define CONV_ON    (BIT_SET(CONV_PORT, CONV_BIT))
#define CONV_OFF   (BIT_CLEAR(CONV_PORT, CONV_BIT))
#define CONV_INP   (BIT_SET((DDR_REG(CONV_PORT)), CONV_BIT))

#define CONV_INIT  CONV_OFF; CONV_INP

//пин подсветки A2
#define LIGHT_BIT   2 // A2
#define LIGHT_PORT  PORTC

#if LIGHT_INV
#define LIGHT_ON    (BIT_SET(LIGHT_PORT, LIGHT_BIT))
#define LIGHT_OFF   (BIT_CLEAR(LIGHT_PORT, LIGHT_BIT))
#else
#define LIGHT_ON    (BIT_CLEAR(LIGHT_PORT, LIGHT_BIT))
#define LIGHT_OFF   (BIT_SET(LIGHT_PORT, LIGHT_BIT))
#endif
#define LIGHT_OUT   (BIT_SET((DDR_REG(LIGHT_PORT)), LIGHT_BIT))

#define LIGHT_INIT  LIGHT_OFF; LIGHT_OUT

//пин фонарика D9
#define FLASH_BIT   1 // D9
#define FLASH_PORT  PORTB

#define FLASH_SWITCH (BIT_INV(FLASH_PORT, FLASH_BIT))
#define FLASH_ON     (BIT_SET(FLASH_PORT, FLASH_BIT))
#define FLASH_OFF    (BIT_CLEAR(FLASH_PORT, FLASH_BIT))
#define FLASH_OUT    (BIT_SET((DDR_REG(FLASH_PORT)), FLASH_BIT))

#define FLASH_INIT  FLASH_OFF; FLASH_OUT

//пин вибро-мотора D8
#define VIBRO_BIT   0 // D8
#define VIBRO_PORT  PORTB

#define VIBRO_ON    (BIT_SET(VIBRO_PORT, VIBRO_BIT))
#define VIBRO_OFF   (BIT_CLEAR(VIBRO_PORT, VIBRO_BIT))
#define VIBRO_OUT   (BIT_SET((DDR_REG(VIBRO_PORT)), VIBRO_BIT))

#define VIBRO_INIT  VIBRO_OFF; VIBRO_OUT

//пин индикации частиц D13
#define RAD_FLASH_BIT   5 // D13
#define RAD_FLASH_PORT  PORTB

#define is_RAD_FLASH_ON (BIT_READ(RAD_FLASH_PORT, RAD_FLASH_BIT))
#define RAD_FLASH_ON    (BIT_SET(RAD_FLASH_PORT, RAD_FLASH_BIT))
#define RAD_FLASH_OFF   (BIT_CLEAR(RAD_FLASH_PORT, RAD_FLASH_BIT))
#define RAD_FLASH_OUT   (BIT_SET((DDR_REG(RAD_FLASH_PORT)), RAD_FLASH_BIT))

#define RAD_FLASH_INIT  RAD_FLASH_OFF; RAD_FLASH_OUT

//пин питания дисплея A3
#define PWR_LCD_BIT   3 // A3
#define PWR_LCD_PORT  PORTC

#define PWR_LCD_ON    BIT_CLEAR(PWR_LCD_PORT, PWR_LCD_BIT)
#define PWR_LCD_OUT   BIT_SET((DDR_REG(PWR_LCD_PORT)), PWR_LCD_BIT)

#define PWR_LCD_INIT  PWR_LCD_ON; PWR_LCD_OUT
