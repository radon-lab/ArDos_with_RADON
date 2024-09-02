//Соединения периферии с пинами МК
//    (0 - D0 | 1 - D1 | 2 - D2 | 3 - D3 | 4 - D4 | 5 - D5 | 6 - D6 | 7 - D7)
//        (8 - D8 | 9 - D9 | 10 - D10 | 11 - D11 | 12 - D12 | 13 - D13)
//         (14 - A0 | 15 - A1 | 16 - A2 | 17 - A3 | 18 - A4 | 19 - A5)

//Цифровые кнопки
#define SEL_PIN   3  //пин кнопки выбора(только пин 3)(pin D)
#define DOWN_PIN  7  //пин кнопки вниз(0..19)(pin D)
#define UP_PIN    4  //пин кнопки вверх(0..19)(pin D)

//Дисплей 5110(3310)
#define MOSI_PIN 14 //пин MOSI дисплея(0..19)(pin D)
#define RST_PIN  10 //пин RST дисплея(0..19)(pin D)
#define SCK_PIN  15 //пин SCK дисплея(0..19)(pin D)
#define DC_PIN   12 //пин DC дисплея(0..19)(pin D)
#define CE_PIN   11 //пин CE дисплея(0..19)(pin D)

//Основная периферия
#define DET_PIN   2  //пин детектора частиц(только пин 2)(pin D)
#define CONV_PIN  5  //пин преобразователя(0..19)(pin D)
#define BACKL_PIN 16 //пин подсветки(0..19)(pin D)
#define BUZZ_PIN  6  //пин пищалки(0..19)(pin D)

//Дополнительная периферия
#define VIBRO_PIN     8  //пин вибромотора(0..19)(pin D)
#define FLASH_PIN     9  //пин фонарика(0..19)(pin D)
#define RAD_FLASH_PIN 13 //пин индикации поподания частиц(0..19)(pin D)
#define PWR_LCD_PIN   17 //пин управления питанием экрана(0..19)(pin D)

//Обратная связь
#define ANALOG_DET_PIN 6 //пин обратной связи преобразователя на АЦП(0..7)(pin A)
#define COMP_DET_PIN 7 //пин обратной связи преобразователя на компараторе/цифровом входе(компаратор - только 7 | цифровой вход - 0..19)(pin D)


//Соединения периферии с портами МК
#define DDR_REG(portx)  (*(&portx - 1))
#define PIN_REG(portx)  (*(&portx - 2))
#define BIT_READ(value, bit) ((value) & (0x01 << (bit)))
#define BIT_INV(value, bit) ((value) ^= (0x01 << (bit)))
#define BIT_SET(value, bit) ((value) |= (0x01 << (bit)))
#define BIT_CLEAR(value, bit) ((value) &= ~(0x01 << (bit)))
#define BIT_WRITE(value, bit, bitvalue) (bitvalue ? BIT_SET(value, bit) : BIT_CLEAR(value, bit))

#define DECODE_PCMSK(pin) ((pin < 8) ? PCMSK2 : ((pin < 14) ? PCMSK0 : PCMSK1))
#define DECODE_PCIF(pin) ((pin < 8) ? PCIF2 : ((pin < 14) ? PCIF0 : PCIF1))
#define DECODE_PORT(pin) ((pin < 8) ? PORTD : ((pin < 14) ? PORTB : PORTC))
#define DECODE_BIT(pin) ((pin < 8) ? pin : ((pin < 14) ? (pin - 8) : (pin - 14)))

#ifndef PRTWI //если бит PRTWI не обнаружен
#define PRTWI PRTWI0 //создаем бит PRTWI
#endif
#ifndef PRR //если регистр PRR не обнаружен
#define PRR PRR0 //создаем регистр PRR
#endif

//пин компаратора
#define COMP_BIT   DECODE_BIT(COMP_DET_PIN)
#define COMP_PORT  DECODE_PORT(COMP_DET_PIN)

#define COMP_CLR   (BIT_CLEAR(COMP_PORT, COMP_BIT))
#define COMP_INP   (BIT_CLEAR((DDR_REG(COMP_PORT)), COMP_BIT))

#if PUMP_FEEDBACK == 1
#if PUMP_FEEDBACK_PULL
#define COMP_CHK (!(ACSR & (0x01 << ACO)))
#else
#define COMP_CHK (ACSR & (0x01 << ACO))
#endif
#define COMP_INT_CHK   (ACSR & (0x01 << ACI))
#define COMP_INT_CLR   (ACSR |= (0x01 << ACI))

#define COMP_INIT  COMP_CLR; COMP_INP
#else
#if PUMP_FEEDBACK_PULL
#define COMP_CHK (BIT_READ(COMP_PORT, COMP_BIT))
#else
#define COMP_CHK (!(BIT_READ(COMP_PORT, COMP_BIT)))
#endif
#define COMP_INT_CHK   (BIT_READ(PCIFR, DECODE_PCIF(COMP_DET_PIN)))
#define COMP_INT_CLR   (BIT_SET(PCIFR, DECODE_PCIF(COMP_DET_PIN)))
#define COMP_INT_SET   (DECODE_PCMSK(COMP_DET_PIN) = (0x01 << COMP_BIT))

#define COMP_INIT  COMP_CLR; COMP_INP; COMP_INT_SET; COMP_INT_CLR
#endif

//пин SCK дисплея
#define SCK_BIT  DECODE_BIT(SCK_PIN)
#define SCK_PORT DECODE_PORT(SCK_PIN)
#define SCK_SET  (BIT_SET(SCK_PORT, SCK_BIT))
#define SCK_OUT  (BIT_SET((DDR_REG(SCK_PORT)), SCK_BIT))

//пин MOSI дисплея
#define MOSI_BIT  DECODE_BIT(MOSI_PIN)
#define MOSI_PORT DECODE_PORT(MOSI_PIN)
#define MOSI_SET  (BIT_SET(MOSI_PORT, MOSI_BIT))
#define MOSI_OUT  (BIT_SET((DDR_REG(MOSI_PORT)), MOSI_BIT))

//пин DC дисплея
#define DC_BIT  DECODE_BIT(DC_PIN)
#define DC_PORT DECODE_PORT(DC_PIN)
#define DC_SET  (BIT_SET(DC_PORT, DC_BIT))
#define DC_OUT  (BIT_SET((DDR_REG(DC_PORT)), DC_BIT))

//пин RST дисплея
#define RST_BIT  DECODE_BIT(RST_PIN)
#define RST_PORT DECODE_PORT(RST_PIN)
#define RST_SET  (BIT_SET(RST_PORT, RST_BIT))
#define RST_OUT  (BIT_SET((DDR_REG(RST_PORT)), RST_BIT))

//пин CE дисплея
#define CE_BIT   DECODE_BIT(CE_PIN)
#define CE_PORT  DECODE_PORT(CE_PIN)
#define CE_ON    (BIT_CLEAR(CE_PORT, CE_BIT))
#define CE_OFF   (BIT_SET(CE_PORT, CE_BIT))
#define CE_OUT   (BIT_SET((DDR_REG(CE_PORT)), CE_BIT))

//пин питания дисплея
#define PWR_LCD_BIT   DECODE_BIT(PWR_LCD_PIN)
#define PWR_LCD_PORT  DECODE_PORT(PWR_LCD_PIN)

#if DISP_POWER_INV
#define PWR_LCD_ON    BIT_SET(PWR_LCD_PORT, PWR_LCD_BIT)
#define PWR_LCD_OFF   BIT_CLEAR(PWR_LCD_PORT, PWR_LCD_BIT)
#else
#define PWR_LCD_ON    BIT_CLEAR(PWR_LCD_PORT, PWR_LCD_BIT)
#define PWR_LCD_OFF   BIT_SET(PWR_LCD_PORT, PWR_LCD_BIT)
#endif
#define PWR_LCD_OUT   BIT_SET((DDR_REG(PWR_LCD_PORT)), PWR_LCD_BIT)

#define PWR_LCD_INIT  PWR_LCD_OFF; PWR_LCD_OUT
#define LCD_DISABLE   SCK_SET; MOSI_SET; DC_SET; RST_SET; CE_OFF; PWR_LCD_OFF
#define LCD_INIT      SCK_SET; SCK_OUT; MOSI_SET; MOSI_OUT; DC_SET; DC_OUT; RST_SET; RST_OUT; CE_OFF; CE_OUT

//пин кнопки ОК
#define SEL_BIT   DECODE_BIT(SEL_PIN)
#define SEL_PORT  DECODE_PORT(SEL_PIN)

#define SEL_CHK   (BIT_READ(PIN_REG(SEL_PORT), SEL_BIT))
#define SEL_SET   (BIT_SET(SEL_PORT, SEL_BIT))
#define SEL_INP   (BIT_CLEAR((DDR_REG(SEL_PORT)), SEL_BIT))

#define SEL_INIT  SEL_SET; SEL_INP

//пин кнопки DOWN
#define DOWN_BIT   DECODE_BIT(DOWN_PIN)
#define DOWN_PORT  DECODE_PORT(DOWN_PIN)

#define DOWN_CHK   (BIT_READ(PIN_REG(DOWN_PORT), DOWN_BIT))
#define DOWN_SET   (BIT_SET(DOWN_PORT, DOWN_BIT))
#define DOWN_INP   (BIT_CLEAR((DDR_REG(DOWN_PORT)), DOWN_BIT))

#define DOWN_INIT  DOWN_SET; DOWN_INP

//пин кнопки UP
#define UP_BIT   DECODE_BIT(UP_PIN)
#define UP_PORT  DECODE_PORT(UP_PIN)

#define UP_CHK   (BIT_READ(PIN_REG(UP_PORT), UP_BIT))
#define UP_SET   (BIT_SET(UP_PORT, UP_BIT))
#define UP_INP   (BIT_CLEAR((DDR_REG(UP_PORT)), UP_BIT))

#define UP_INIT  UP_SET; UP_INP

//пин пищалки
#define BUZZ_BIT   DECODE_BIT(BUZZ_PIN)
#define BUZZ_PORT  DECODE_PORT(BUZZ_PIN)

#define BUZZ_OFF   (BIT_CLEAR(BUZZ_PORT, BUZZ_BIT))
#define BUZZ_ON    (BIT_SET(BUZZ_PORT, BUZZ_BIT))
#define BUZZ_OUT   (BIT_SET((DDR_REG(BUZZ_PORT)), BUZZ_BIT))

#define BUZZ_INIT  BUZZ_OFF; BUZZ_OUT

//пин детектора
#define DET_BIT   DECODE_BIT(DET_PIN)
#define DET_PORT  DECODE_PORT(DET_PIN)

#if GEIGER_INT_PULL
#define DET_CHK   (!BIT_READ(PIN_REG(DET_PORT), DET_BIT))
#define DET_SET   (BIT_SET(DET_PORT, DET_BIT))
#else
#define DET_CHK   (BIT_READ(PIN_REG(DET_PORT), DET_BIT))
#define DET_SET   (BIT_CLEAR(DET_PORT, DET_BIT))
#endif
#define DET_INP   (BIT_CLEAR((DDR_REG(DET_PORT)), DET_BIT))

#define DET_INIT  DET_SET; DET_INP

//пин преобразователя
#define CONV_BIT   DECODE_BIT(CONV_PIN)
#define CONV_PORT  DECODE_PORT(CONV_PIN)

#define CONV_ON    (BIT_SET(CONV_PORT, CONV_BIT))
#define CONV_OFF   (BIT_CLEAR(CONV_PORT, CONV_BIT))
#define CONV_INP   (BIT_SET((DDR_REG(CONV_PORT)), CONV_BIT))

#define CONV_INIT  CONV_OFF; CONV_INP

//пин подсветки
#define BACKL_BIT   DECODE_BIT(BACKL_PIN)
#define BACKL_PORT  DECODE_PORT(BACKL_PIN)

#if DISP_BACKL_INV
#define BACKL_ON    (BIT_SET(BACKL_PORT, BACKL_BIT))
#define BACKL_OFF   (BIT_CLEAR(BACKL_PORT, BACKL_BIT))
#else
#define BACKL_ON    (BIT_CLEAR(BACKL_PORT, BACKL_BIT))
#define BACKL_OFF   (BIT_SET(BACKL_PORT, BACKL_BIT))
#endif
#define BACKL_OUT   (BIT_SET((DDR_REG(BACKL_PORT)), BACKL_BIT))

#define BACKL_INIT  BACKL_OFF; BACKL_OUT

//пин фонарика
#define FLASH_BIT   DECODE_BIT(FLASH_PIN)
#define FLASH_PORT  DECODE_PORT(FLASH_PIN)

#define FLASH_SWITCH (BIT_INV(FLASH_PORT, FLASH_BIT))
#define FLASH_ON     (BIT_SET(FLASH_PORT, FLASH_BIT))
#define FLASH_OFF    (BIT_CLEAR(FLASH_PORT, FLASH_BIT))
#define FLASH_OUT    (BIT_SET((DDR_REG(FLASH_PORT)), FLASH_BIT))

#define FLASH_INIT  FLASH_OFF; FLASH_OUT

//пин вибромотора
#define VIBRO_BIT   DECODE_BIT(VIBRO_PIN)
#define VIBRO_PORT  DECODE_PORT(VIBRO_PIN)

#define VIBRO_ON    (BIT_SET(VIBRO_PORT, VIBRO_BIT))
#define VIBRO_OFF   (BIT_CLEAR(VIBRO_PORT, VIBRO_BIT))
#define VIBRO_OUT   (BIT_SET((DDR_REG(VIBRO_PORT)), VIBRO_BIT))

#define VIBRO_INIT  VIBRO_OFF; VIBRO_OUT

//пин индикации частиц
#define RAD_FLASH_BIT   DECODE_BIT(RAD_FLASH_PIN)
#define RAD_FLASH_PORT  DECODE_PORT(RAD_FLASH_PIN)

#define RAD_FLASH_ON    (BIT_SET(RAD_FLASH_PORT, RAD_FLASH_BIT))
#define RAD_FLASH_OFF   (BIT_CLEAR(RAD_FLASH_PORT, RAD_FLASH_BIT))
#define RAD_FLASH_OUT   (BIT_SET((DDR_REG(RAD_FLASH_PORT)), RAD_FLASH_BIT))

#define RAD_FLASH_INIT  RAD_FLASH_OFF; RAD_FLASH_OUT
