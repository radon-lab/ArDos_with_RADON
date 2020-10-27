//Соединения периферии с портами МК 
//    PORTD (2 - D2 | 3 - D3 | 4 - D4 | 5 - D5 | 6 - D6 | 7 - D7) PIND
//  PORTB (0 - D8 | 1 - D9 | 2 - D10 | 3 - D11 | 4 - D12 | 5 - D13) PINB
//    PORTC (0 - A0 | 1 - A1 | 2 - A2 | 3 - A3 | 4 - A4 | 5 - A5) PINC

//обьявляем дисплей с указанием пинов подключения
//пин SCK дисплея A1
#define SCK_BIT  1
#define SCK_PORT PORTC
#define SCK_CLR  (bitClear(SCK_PORT, SCK_BIT))
#define SCK_OUT  (bitSet((DDR_REG(SCK_PORT)), SCK_BIT))

//пин MOSI дисплея A0
#define MOSI_BIT  0
#define MOSI_PORT PORTC
#define MOSI_CLR  (bitClear(MOSI_PORT, MOSI_BIT))
#define MOSI_OUT  (bitSet((DDR_REG(MOSI_PORT)), MOSI_BIT))

//пин DC дисплея D12
#define DC_BIT  4
#define DC_PORT PORTB
#define DC_CLR  (bitClear(DC_PORT, DC_BIT))
#define DC_OUT  (bitSet((DDR_REG(DC_PORT)), DC_BIT))

//пин RST дисплея D10
#define RST_BIT  2
#define RST_PORT PORTB
#define RST_CLR  (bitClear(RST_PORT, RST_BIT))
#define RST_OUT  (bitSet((DDR_REG(RST_PORT)), RST_BIT))

//пин CE дисплея D11
#define LCD_BIT   3 // D11
#define LCD_PORT  PORTB
#define LCD_ON    bitClear(LCD_PORT, LCD_BIT)
#define LCD_OUT   bitSet((DDR_REG(LCD_PORT)), LCD_BIT)

#define LCD_INIT  SCK_CLR; SCK_OUT; MOSI_CLR; MOSI_OUT; DC_CLR; DC_OUT; RST_CLR; RST_OUT; LCD_ON; LCD_OUT

//назначаем кнопки//
//пин кнопки ОК D3
#define OK_BIT   3 // D3
#define OK_PORT  PORTD
#define OK_PIN   PIND

#define OK_OUT   (bitRead(OK_PIN, OK_BIT))
#define OK_SET   (bitSet(OK_PORT, OK_BIT))
#define OK_INP   (bitClear((DDR_REG(OK_PORT)), OK_BIT))

#define OK_INIT  OK_SET; OK_INP

//пин кнопки DOWN D7
#define DOWN_BIT   7 // D7
#define DOWN_PORT  PORTD
#define DOWN_PIN   PIND

#define DOWN_OUT   (bitRead(DOWN_PIN, DOWN_BIT))
#define DOWN_SET   (bitSet(DOWN_PORT, DOWN_BIT))
#define DOWN_INP   (bitClear((DDR_REG(DOWN_PORT)), DOWN_BIT))

#define DOWN_INIT  DOWN_SET; DOWN_INP

//пин кнопки UP D4
#define UP_BIT   4 // D4
#define UP_PORT  PORTD
#define UP_PIN   PIND

#define UP_OUT   (bitRead(UP_PIN, UP_BIT))
#define UP_SET   (bitSet(UP_PORT, UP_BIT))
#define UP_INP   (bitClear((DDR_REG(UP_PORT)), UP_BIT))

#define UP_INIT  UP_SET; UP_INP


//пределитель Timer1 для пищалки
#define TMR1_PRESCALER  256

//пищалка старт/стоп
#define TIMER1_START       PRR &= ~(1 << 3); TIMSK1 = 0b00000010
#define TIMER1_STOP        PRR |= (1 << 3); TIMSK1 = 0b00000000

//подсветка старт/стоп
#define _LIGHT_ON       PRR &= ~(1 << 6); TCCR2B = 0b00000101; TIMSK2 = 0b00000011; light_switch = 1
#define _LIGHT_OFF      PRR &= ~(1 << 6); TCCR2B = 0b00000101; TIMSK2 = 0b00000011; light_switch = 0
#define _LIGHT_STOP     TCNT2 = TCCR2B = TIMSK2 = 0b00000000; PRR |= (1 << 6)

#define DDR_REG(portx)  (*(&portx-1))

//пин пищалки
#define BUZZ_BIT   6 // D6
#define BUZZ_PORT  PORTD

#define BUZZ_CLR   (bitClear(BUZZ_PORT, BUZZ_BIT))
#define BUZZ_SET   (bitSet(BUZZ_PORT, BUZZ_BIT))
#define is_BUZ_SET (bitRead(BUZZ_PORT, BUZZ_BIT))
#define BUZZ_OUT   (bitSet((DDR_REG(BUZZ_PORT)), BUZZ_BIT))

#define BUZZ_INIT  BUZZ_CLR; BUZZ_OUT

//пин детектора
#define DET_1_BIT   2 // D2
#define DET_1_PORT  PORTD

#define DET_1_SET   (bitSet(DET_1_PORT, DET_1_BIT))
#define DET_1_INP   (bitClear((DDR_REG(DET_1_PORT)), DET_1_BIT))

#define DET_1_INIT  DET_1_SET; DET_1_INP

//пин преобразователя
#define CONV_BIT   5 // D5
#define CONV_PORT  PORTD

#define CONV_CLR   (bitClear(CONV_PORT, CONV_BIT))
#define CONV_INP   (bitSet((DDR_REG(CONV_PORT)), CONV_BIT))

#define CONV_INIT  CONV_CLR; CONV_INP

//пин подсветки A2
#define LIGHT_BIT   2 // A2
#define LIGHT_PORT  PORTC

#if LIGHT_INV
#define LIGHT_ON    (bitSet(LIGHT_PORT, LIGHT_BIT))
#define LIGHT_OFF   (bitClear(LIGHT_PORT, LIGHT_BIT))
#else
#define LIGHT_ON    (bitClear(LIGHT_PORT, LIGHT_BIT))
#define LIGHT_OFF   (bitSet(LIGHT_PORT, LIGHT_BIT))
#endif
#define LIGHT_OUT   (bitSet((DDR_REG(LIGHT_PORT)), LIGHT_BIT))

#define LIGHT_INIT  LIGHT_OFF; LIGHT_OUT

//пин фонарика D9
#define FLASH_BIT   1 // D9
#define FLASH_PORT  PORTB

#define is_FLASH_ON (bitRead(FLASH_PORT, FLASH_BIT))
#define FLASH_ON    (bitSet(FLASH_PORT, FLASH_BIT))
#define FLASH_OFF   (bitClear(FLASH_PORT, FLASH_BIT))
#define FLASH_OUT   (bitSet((DDR_REG(FLASH_PORT)), FLASH_BIT))

#define FLASH_INIT  FLASH_OFF; FLASH_OUT

//пин вибро-мотора D8
#define VIBRO_BIT   0 // D8
#define VIBRO_PORT  PORTB

#define VIBRO_ON    (bitSet(VIBRO_PORT, VIBRO_BIT))
#define VIBRO_OFF   (bitClear(VIBRO_PORT, VIBRO_BIT))
#define VIBRO_OUT   (bitSet((DDR_REG(VIBRO_PORT)), VIBRO_BIT))

#define VIBRO_INIT  VIBRO_OFF; VIBRO_OUT

//пин индикации частиц D13
#define RAD_FLASH_BIT   5 // D13
#define RAD_FLASH_PORT  PORTB

#define is_RAD_FLASH_ON (bitRead(RAD_FLASH_PORT, RAD_FLASH_BIT))
#define RAD_FLASH_ON    (bitSet(RAD_FLASH_PORT, RAD_FLASH_BIT))
#define RAD_FLASH_OFF   (bitClear(RAD_FLASH_PORT, RAD_FLASH_BIT))
#define RAD_FLASH_OUT   (bitSet((DDR_REG(RAD_FLASH_PORT)), RAD_FLASH_BIT))

#define RAD_FLASH_INIT  RAD_FLASH_OFF; RAD_FLASH_OUT

//пин питания дисплея A3
#define PWR_LCD_BIT   3 // A3
#define PWR_LCD_PORT  PORTC

#define PWR_LCD_ON    bitClear(PWR_LCD_PORT, PWR_LCD_BIT)
#define PWR_LCD_OUT   bitSet((DDR_REG(PWR_LCD_PORT)), PWR_LCD_BIT)

#define PWR_LCD_INIT  PWR_LCD_ON; PWR_LCD_OUT
