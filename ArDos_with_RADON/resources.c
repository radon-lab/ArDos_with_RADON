#include <avr/pgmspace.h>

//=============батарея===============
const uint8_t bat_alt_img[] PROGMEM = { //полоски заряда акб
  0x81, 0xBD, 0x81, 0xBD, 0x81, 0xBD, 0x81, 0xBD, 0x81, 0xBD
};

const uint8_t low_bat_img[] PROGMEM = { //эмблемма разряженой батареи
  0xC0, 0xC0, 0xC0, 0xC0, 0xC0, 0xC0, 0xC0, 0xC0,
  0xC0, 0xC0, 0xC0, 0xC0, 0xC0, 0xC0, 0xC0, 0xC0,
  0xC0, 0xC0, 0xC0, 0xC0, 0xC0, 0xC0, 0xC0, 0xC0,
  0xC0, 0xC0, 0xC0, 0xC0, 0xC0, 0x00, 0x00, 0x00,
  0xFF, 0xFF, 0x01, 0x00, 0xF8, 0xFC, 0xFC, 0xFC,
  0xFC, 0xFC, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
  0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
  0x00, 0x00, 0x01, 0xFF, 0xFF, 0xF8, 0xF8, 0xF8,
  0xFF, 0xFF, 0x80, 0x00, 0x1F, 0x3F, 0x3F, 0x3F,
  0x3F, 0x3F, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
  0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
  0x00, 0x00, 0x80, 0xFF, 0xFF, 0x1F, 0x1F, 0x1F,
  0x03, 0x03, 0x03, 0x03, 0x03, 0x03, 0x03, 0x03,
  0x03, 0x03, 0x03, 0x03, 0x03, 0x03, 0x03, 0x03,
  0x03, 0x03, 0x03, 0x03, 0x03, 0x03, 0x03, 0x03,
  0x03, 0x03, 0x03, 0x03, 0x03, 0x00, 0x00, 0x00
};

//=============набор шкал===============
const uint8_t l3[] PROGMEM = {0x5A}; //4 пкс
const uint8_t l2[] PROGMEM = {0x10}; //1 пкс
const uint8_t l1[] PROGMEM = {0x30}; //2 пкс
const uint8_t l0[] PROGMEM = {0xFF}; //8 пкс
//---------------------------------------------//
const uint8_t* const _scale[] PROGMEM = {l0, l1, l2, l3};

//=============шкала фона===============
const uint8_t back_scale_img[] PROGMEM = { //журнал
  0x7E, 0x42, 0x42, 0x42, 0x42, 0x42, 0x42, 0x42, 0x42, 0x42, 0x42, 0x42,
  0x42, 0x42, 0x42, 0x42, 0x42, 0x42, 0x42, 0x42, 0x42, 0x42, 0x42, 0x42,
  0x42, 0x42, 0x42, 0x42, 0x42, 0x42, 0x42, 0x42, 0x42, 0x42, 0x42, 0x42,
  0x42, 0x42, 0x42, 0x42, 0x42, 0x42, 0x42, 0x42, 0x42, 0x42, 0x42, 0x42,
  0x42, 0x42, 0x42, 0x42, 0x42, 0x42, 0x42, 0x42, 0x42, 0x42, 0x42, 0x42,
  0x42, 0x42, 0x42, 0x42, 0x42, 0x42, 0x42, 0x42, 0x42, 0x42, 0x42, 0x42,
  0x42, 0x42, 0x42, 0x42, 0x42, 0x42, 0x42, 0x42, 0x42, 0x42, 0x42, 0x7E
};

//=============тревога===============
const uint8_t beep_alt_img[] PROGMEM = { //скобка и вертикальная волна
  0xFF, 0xAB, 0xD5, 0xFF, 0xDB, 0xE7, 0xBD, 0xC3
};

const uint8_t beep_alt_waint_img[] PROGMEM = { //звездочка
  0xFF, 0xD7, 0x93, 0xEF, 0x93, 0xD7, 0xFF
};

const uint8_t beep_alt_vibro_img[] PROGMEM = { //две вертикальные волны
  0xFF, 0xAB, 0xD5, 0xFF, 0xAB, 0xD5, 0xFF
};
//=============щелчки===============
const uint8_t buzz_alt_img[] PROGMEM = { //две скобки
  0xFF, 0xDF, 0xC3, 0xFB, 0xC3, 0xDF, 0xFF
};

const uint8_t buzz_alt_on_img[] PROGMEM = { //горизонтальная волна
  0xFF, 0xDB, 0xE7, 0xBD, 0xC3, 0xFF, 0xFF
};

const uint8_t buzz_alt_off_img[] PROGMEM = { //крестик
  0xFF, 0xBB, 0xD7, 0xEF, 0xD7, 0xBB, 0xFF
};

//=============верхний бар===============
const uint8_t font_alt_img[] PROGMEM = { //верхний бар
  0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF,
  0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF,
  0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF,
  0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xE7, 0xE7, 0xC3, 0x81, 0xFF,
  0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xDF, 0xC3, 0x81, 0xC3, 0xDF,
  0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0x81, 0x81,
  0x81, 0x81, 0x81, 0x81, 0x81, 0x81, 0x81, 0x81, 0x81, 0xC3, 0xFF, 0xFF
};

//=============настройки===============
const uint8_t setings_img[] PROGMEM = { //настройки
  0x7F, 0x7F, 0x7F, 0x7F, 0x7F, 0x7F, 0x7F, 0x7F, 0x7F, 0x7F, 0x7F, 0x7F,
  0x7F, 0x7F, 0x7F, 0x7F, 0x41, 0x77, 0x77, 0x41, 0x7F, 0x7F, 0x43, 0x75,
  0x75, 0x43, 0x7F, 0x7F, 0x63, 0x5D, 0x5D, 0x7F, 0x7F, 0x7D, 0x7D, 0x41,
  0x7D, 0x7D, 0x7F, 0x7F, 0x41, 0x6D, 0x6D, 0x73, 0x7F, 0x7F, 0x63, 0x5D,
  0x5D, 0x63, 0x7F, 0x7F, 0x41, 0x6F, 0x76, 0x41, 0x7F, 0x7F, 0x41, 0x77,
  0x6B, 0x5D, 0x7F, 0x7F, 0x41, 0x6F, 0x77, 0x41, 0x7F, 0x7F, 0x7F, 0x7F,
  0x7F, 0x7F, 0x7F, 0x7F, 0x7F, 0x7F, 0x7F, 0x7F, 0x7F, 0x7F, 0x7F, 0x7F
};

//=============меню===============
const uint8_t menu_img[] PROGMEM = { //меню
  0x7F, 0x7F, 0x7F, 0x7F, 0x7F, 0x7F, 0x7F, 0x7F, 0x7F, 0x7F, 0x7F, 0x7F,
  0x7F, 0x7F, 0x7F, 0x7F, 0x7F, 0x7F, 0x7F, 0x7F, 0x7F, 0x7F, 0x7F, 0x7F,
  0x7F, 0x7F, 0x7F, 0x7F, 0x7F, 0x7F, 0x41, 0x7B, 0x77, 0x7B, 0x41, 0x7F,
  0x7F, 0x41, 0x55, 0x55, 0x7F, 0x7F, 0x41, 0x77, 0x77, 0x41, 0x7F, 0x7F,
  0x41, 0x77, 0x63, 0x5D, 0x5D, 0x63, 0x7F, 0x7F, 0x7F, 0x7F, 0x7F, 0x7F,
  0x7F, 0x7F, 0x7F, 0x7F, 0x7F, 0x7F, 0x7F, 0x7F, 0x7F, 0x7F, 0x7F, 0x7F,
  0x7F, 0x7F, 0x7F, 0x7F, 0x7F, 0x7F, 0x7F, 0x7F, 0x7F, 0x7F, 0x7F, 0x7F
};

//=============журнал===============
const uint8_t logbook_img[] PROGMEM = { //журнал
  0x7F, 0x7F, 0x7F, 0x7F, 0x7F, 0x7F, 0x7F, 0x7F, 0x7F, 0x7F, 0x7F, 0x7F,
  0x7F, 0x7F, 0x7F, 0x7F, 0x7F, 0x7F, 0x7F, 0x7F, 0x7F, 0x7F, 0x7F, 0x7F,
  0x5D, 0x6B, 0x77, 0x41, 0x77, 0x6B, 0x5D, 0x7F, 0x7F, 0x59, 0x57, 0x57,
  0x61, 0x7F, 0x7F, 0x41, 0x75, 0x75, 0x7B, 0x7F, 0x7F, 0x41, 0x77, 0x77,
  0x41, 0x7F, 0x7F, 0x43, 0x75, 0x75, 0x43, 0x7F, 0x7F, 0x43, 0x7D, 0x7D,
  0x43, 0x7F, 0x7F, 0x7F, 0x7F, 0x7F, 0x7F, 0x7F, 0x7F, 0x7F, 0x7F, 0x7F,
  0x7F, 0x7F, 0x7F, 0x7F, 0x7F, 0x7F, 0x7F, 0x7F, 0x7F, 0x7F, 0x7F, 0x7F
};

//=============отладка===============
const uint8_t debug_img[] PROGMEM = { //отладка
  0x7F, 0x7F, 0x7F, 0x7F, 0x7F, 0x7F, 0x7F, 0x7F, 0x7F, 0x7F, 0x7F, 0x7F,
  0x7F, 0x7F, 0x7F, 0x7F, 0x7F, 0x7F, 0x7F, 0x7F, 0x7F, 0x63, 0x5D, 0x5D,
  0x63, 0x7F, 0x7F, 0x7D, 0x7D, 0x41, 0x7D, 0x7D, 0x7F, 0x7F, 0x43, 0x7D,
  0x7D, 0x43, 0x7F, 0x7F, 0x43, 0x75, 0x75, 0x43, 0x7F, 0x7F, 0x4F, 0x61,
  0x6D, 0x61, 0x4F, 0x7F, 0x7F, 0x41, 0x77, 0x6B, 0x5D, 0x7F, 0x7F, 0x43,
  0x75, 0x75, 0x43, 0x7F, 0x7F, 0x7F, 0x7F, 0x7F, 0x7F, 0x7F, 0x7F, 0x7F,
  0x7F, 0x7F, 0x7F, 0x7F, 0x7F, 0x7F, 0x7F, 0x7F, 0x7F, 0x7F, 0x7F, 0x7F
};

//=============параметры===============
const uint8_t stat_img[] PROGMEM = { //параметры
  0x7F, 0x7F, 0x7F, 0x7F, 0x7F, 0x7F, 0x7F, 0x7F, 0x7F, 0x7F, 0x7F, 0x7F,
  0x7F, 0x7F, 0x41, 0x7D, 0x7D, 0x41, 0x7F, 0x7F, 0x43, 0x75, 0x75, 0x43,
  0x7F, 0x7F, 0x41, 0x75, 0x75, 0x7B, 0x7F, 0x7F, 0x43, 0x75, 0x75, 0x43,
  0x7F, 0x7F, 0x41, 0x7B, 0x77, 0x7B, 0x41, 0x7F, 0x7F, 0x41, 0x55, 0x55,
  0x7F, 0x7F, 0x7D, 0x7D, 0x41, 0x7D, 0x7D, 0x7F, 0x7F, 0x41, 0x75, 0x75,
  0x7B, 0x7F, 0x7F, 0x41, 0x57, 0x57, 0x6F, 0x7F, 0x41, 0x7F, 0x7F, 0x7F,
  0x7F, 0x7F, 0x7F, 0x7F, 0x7F, 0x7F, 0x7F, 0x7F, 0x7F, 0x7F, 0x7F, 0x7F
};

//===============бета=================
const uint8_t mesur_img[] PROGMEM = { //бета
  0x7F, 0x7F, 0x7F, 0x7F, 0x7F, 0x7F, 0x7F, 0x7F, 0x7F, 0x7F, 0x7F, 0x7F,
  0x7F, 0x7F, 0x7F, 0x7F, 0x7F, 0x7F, 0x7F, 0x7F, 0x7F, 0x7F, 0x7F, 0x7F,
  0x7F, 0x7F, 0x7F, 0x7F, 0x7F, 0x7F, 0x7F, 0x41, 0x55, 0x55, 0x6F, 0x7F,
  0x7F, 0x41, 0x55, 0x55, 0x7F, 0x7F, 0x7D, 0x7D, 0x41, 0x7D, 0x7D, 0x7F,
  0x7F, 0x43, 0x75, 0x75, 0x43, 0x7F, 0x7F, 0x7F, 0x7F, 0x7F, 0x7F, 0x7F,
  0x7F, 0x7F, 0x7F, 0x7F, 0x7F, 0x7F, 0x7F, 0x7F, 0x7F, 0x7F, 0x7F, 0x7F,
  0x7F, 0x7F, 0x7F, 0x7F, 0x7F, 0x7F, 0x7F, 0x7F, 0x7F, 0x7F, 0x7F, 0x7F
};

//===============поиск=================
const uint8_t serch_img[] PROGMEM = { //поиск
  0x7F, 0x7F, 0x7F, 0x7F, 0x7F, 0x7F, 0x7F, 0x7F, 0x7F, 0x7F, 0x7F, 0x7F,
  0x7F, 0x7F, 0x7F, 0x7F, 0x7F, 0x7F, 0x7F, 0x7F, 0x7F, 0x7F, 0x7F, 0x7F,
  0x7F, 0x7F, 0x7F, 0x7F, 0x41, 0x7D, 0x7D, 0x41, 0x7F, 0x7F, 0x63, 0x5D,
  0x5D, 0x63, 0x7F, 0x7F, 0x41, 0x6F, 0x77, 0x41, 0x7F, 0x7F, 0x63, 0x5D,
  0x5D, 0x7F, 0x7F, 0x41, 0x77, 0x6B, 0x5D, 0x7F, 0x7F, 0x7F, 0x7F, 0x7F,
  0x7F, 0x7F, 0x7F, 0x7F, 0x7F, 0x7F, 0x7F, 0x7F, 0x7F, 0x7F, 0x7F, 0x7F,
  0x7F, 0x7F, 0x7F, 0x7F, 0x7F, 0x7F, 0x7F, 0x7F, 0x7F, 0x7F, 0x7F, 0x7F
};

//=============логотип===============
const uint8_t logo_img[] PROGMEM = { //логотип
  0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x80, 0xF0, 0xF8, 0xF8,
  0xF8, 0xF8, 0xF8, 0xF0, 0xC0, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
  0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0xF8, 0xF8,
  0xF8, 0xF8, 0x78, 0x78, 0x78, 0x78, 0xF8, 0xF8, 0xF8, 0xF0, 0xF0, 0xE0,
  0xC0, 0x00, 0x00, 0x00, 0x00, 0xC0, 0xE0, 0xF0, 0xF0, 0xF8, 0x98, 0x18,
  0x18, 0x18, 0x18, 0x18, 0x18, 0xF8, 0xF0, 0xF0, 0xE0, 0xC0, 0x00, 0x00,
  0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
  0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0xF0, 0xFE, 0xFF, 0xFF, 0x9F, 0x81,
  0x81, 0x81, 0x9F, 0xFF, 0xFF, 0xFC, 0xF0, 0x00, 0x00, 0x00, 0x00, 0xFF,
  0xFF, 0xFF, 0xFF, 0xFC, 0x1E, 0x0F, 0x0F, 0x0F, 0x06, 0x00, 0xFF, 0xFF,
  0xFF, 0xFF, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x01, 0xCF, 0xFF, 0xFF,
  0xFF, 0xFF, 0x00, 0xFC, 0xFF, 0x3F, 0x3F, 0x3F, 0x3F, 0x3F, 0x1F, 0x36,
  0x78, 0x78, 0x78, 0x36, 0x1F, 0x3F, 0x3F, 0x3F, 0x3F, 0x3F, 0xFF, 0xFC,
  0x00, 0xFC, 0xFE, 0xFF, 0xEF, 0xC7, 0xC7, 0x8F, 0x0F, 0x0E, 0x00, 0x00,
  0x00, 0x00, 0x00, 0xC0, 0xFC, 0xFF, 0xFF, 0xFF, 0x1F, 0x07, 0x07, 0x07,
  0x07, 0x07, 0x07, 0x07, 0x3F, 0xFF, 0xFF, 0xFF, 0xF8, 0xC0, 0x00, 0xFF,
  0xFF, 0xFF, 0xFF, 0xFF, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0xFF, 0xFF,
  0xFF, 0xFF, 0xF8, 0xF8, 0xF8, 0xF8, 0xF8, 0xF8, 0x7E, 0x7F, 0x3F, 0x3F,
  0x0F, 0x07, 0x00, 0x01, 0x0F, 0x1E, 0x38, 0x70, 0x60, 0xF0, 0xFE, 0xFF,
  0xFF, 0xFF, 0xFF, 0xFF, 0xFC, 0xF0, 0x60, 0x70, 0x38, 0x1F, 0x07, 0x01,
  0x00, 0x79, 0xF9, 0xF1, 0xF3, 0xF7, 0xFF, 0xFF, 0x7F, 0x3E, 0x00, 0x00
};

//=============режимы===============
const uint8_t backgr_img[] PROGMEM = { //фон
  0xFF, 0xFF, 0xC3, 0xDB,
  0x81, 0xDB, 0xC3, 0xFF,
  0xC3, 0xBD, 0xBD, 0xC3,
  0xFF, 0x81, 0xEF, 0xEF,
  0x81
};

const uint8_t dose_img[] PROGMEM = { //доза
  0xFF, 0xFF, 0x9F, 0xC3,
  0xDD, 0xC1, 0x9F, 0xFF,
  0xC3, 0xBD, 0xBD, 0xC3,
  0xFF, 0xDB, 0xBD, 0xB5,
  0xCB, 0xFF, 0x83, 0xED,
  0xED, 0x83
};

//=============эмблемма радиации===============
const uint8_t rad_img[] PROGMEM = { //эмблемма радиации
  0x00, 0x00, 0x00, 0x80, 0xC0, 0xE0, 0xF0, 0xF0,
  0xF8, 0x98, 0x18, 0x0C, 0x0C, 0x0C, 0x0C, 0x0C,
  0x0C, 0x0C, 0x0C, 0x0C, 0x0C, 0x1C, 0x98, 0xF8,
  0xF0, 0xF0, 0xE0, 0xC0, 0x80, 0x00, 0x00, 0x00,
  0xF8, 0xFE, 0xFF, 0x7F, 0x7F, 0x7F, 0x7F, 0x7F,
  0x7F, 0x7F, 0x7F, 0x7E, 0x78, 0x20, 0x80, 0xC0,
  0xC0, 0x80, 0x20, 0x70, 0x7C, 0x7E, 0x7F, 0x7F,
  0x7F, 0x7F, 0x7F, 0x7F, 0x7F, 0xFF, 0xFC, 0xF8,
  0x0F, 0x3F, 0x70, 0xC0, 0x80, 0x00, 0x00, 0x00,
  0x00, 0x00, 0x00, 0x00, 0x80, 0xE0, 0xF9, 0xFB,
  0xFB, 0xF9, 0xE0, 0x80, 0x00, 0x00, 0x00, 0x00,
  0x00, 0x00, 0x00, 0x80, 0xC0, 0x70, 0x3F, 0x0F,
  0x00, 0x00, 0x00, 0x00, 0x01, 0x03, 0x06, 0x04,
  0x0C, 0x08, 0x0C, 0x1E, 0x1F, 0x1F, 0x1F, 0x1F,
  0x1F, 0x1F, 0x1F, 0x1F, 0x1E, 0x0C, 0x08, 0x0C,
  0x04, 0x06, 0x03, 0x01, 0x00, 0x00, 0x00, 0x00
};

//=============график===============
const uint8_t s8[] PROGMEM = {0xFF}; //8 пкс
const uint8_t s7[] PROGMEM = {0xFE}; //7 пкс
const uint8_t s6[] PROGMEM = {0xFC}; //6 пкс
const uint8_t s5[] PROGMEM = {0xF8}; //5 пкс
const uint8_t s4[] PROGMEM = {0xF0}; //4 пкс
const uint8_t s3[] PROGMEM = {0xE0}; //3 пкс
const uint8_t s2[] PROGMEM = {0xC0}; //2 пкс
const uint8_t s1[] PROGMEM = {0x80}; //1 пкс
const uint8_t s0[] PROGMEM = {0x00}; //0 пкс
//---------------------------------------------//
const uint8_t* const scan_scale[] PROGMEM = {s0, s1, s2, s3, s4, s5, s6, s7, s8};
//---------------------------------------------//
const uint8_t scan_left_img[] PROGMEM = {0xFF, 0x49, 0x49, 0x01, 0xFF, 0x92, 0x92, 0x80}; //левая шкала графика
const uint8_t scan_right_img[] PROGMEM = {0x01, 0x49, 0x49, 0xFF, 0x80, 0x92, 0x92, 0xFF}; //правая шкала графика
//---------------------------------------------//
const uint8_t scan_alt_left_img[] PROGMEM = {0xFE, 0x02, 0x02, 0x02, 0xFF, 0x01, 0x01, 0x01, 0xFF, 0x81, 0x81, 0x81}; //левая шкала графика
const uint8_t scan_alt_right_img[] PROGMEM = {0x02, 0x02, 0x02, 0xFE, 0x01, 0x01, 0x01, 0xFF, 0x81, 0x81, 0x81, 0xFF}; //правая шкала графика
//---------------------------------------------//
const uint8_t scan_ind_scale_img[] PROGMEM = { //шкала уровня импульсов
  0xFC, 0x04, 0x04, 0x04,
  0x04, 0x3C, 0x04, 0x04,
  0x04, 0x04, 0x7C, 0x04,
  0x04, 0x04, 0x04, 0x3C,
  0x04, 0x04, 0x04, 0x04,
  0x7C, 0x04, 0x04, 0x04,
  0x04, 0x3C, 0x04, 0x04,
  0x04, 0x04, 0x7C, 0x04,
  0x04, 0x04, 0x04, 0x3C,
  0x04, 0x04, 0x04, 0x04,
  0x7C, 0x04, 0x04, 0x04,
  0x04, 0x3C, 0x04, 0x04,
  0x04, 0x04, 0xFC
};

const uint8_t scan_ind_img[] PROGMEM = { //уровень импульсов
  0x3F, 0x00, 0x3E, 0x3E, 0x3E, 0x3E, 0x3E, 0x3E,
  0x3E, 0x3E, 0x3E, 0x3E, 0x3E, 0x3E, 0x3E, 0x3E,
  0x3E, 0x3E, 0x3E, 0x3E, 0x3E, 0x3E, 0x3E, 0x3E,
  0x3E, 0x3E, 0x3E, 0x3E, 0x3E, 0x3E, 0x3E, 0x3E,
  0x3E, 0x3E, 0x3E, 0x3E, 0x3E, 0x3E, 0x3E, 0x3E,
  0x3E, 0x3E, 0x3E, 0x3E, 0x3E, 0x3E, 0x3E, 0x3E,
  0x3E, 0x3E, 0x3E, 0x3E, 0x3E, 0x3E, 0x3E
};

//=============тех.символы и буквы===============
const uint8_t day_img[] PROGMEM = { //д
  0xC0, 0x70, 0x70, 0xC0, 0x00, 0xF0, 0x40, 0xF0
};
const uint8_t hour_img[] PROGMEM = { //ч
  0x30, 0x40, 0xF0
};
const uint8_t min_img[] PROGMEM = { //м
  0xF0, 0x20, 0x40, 0x20, 0xF0
};
const uint8_t colon_img[] PROGMEM = { //:
  0x00, 0x50, 0x00
};
const uint8_t sigma_img[] PROGMEM = { //σ
  0x30, 0x48, 0x48, 0x38, 0x08
};
//const uint8_t sigma_img[] PROGMEM = { //Σ
//  0x00, 0x44, 0x6C, 0x54, 0x44
//};
const uint8_t percent_img[] PROGMEM = { //%
  0x18, 0x58, 0x20, 0x10, 0x68, 0x60
};
const uint8_t plus_minus_img[] PROGMEM = { //±
  0x48, 0x5C, 0x48
};
const uint8_t error_ico_img[] PROGMEM = { //ERR
  0x81, 0xB5, 0xB5, 0xBD, 0xFF, 0x81, 0xED,
  0xCD, 0xB3, 0xFF, 0x81, 0xED, 0xCD, 0xB3
};
const uint8_t logbook_ico_img[] PROGMEM = { //logbook
  0xC1, 0xDD, 0xA5, 0xBB, 0x83, 0xBB, 0xA5, 0xDD, 0xC1
};
const uint8_t measur_result_img[] PROGMEM = { //результат
  0x7E, 0x12, 0x12, 0x0C, 0x00, 0x7E, 0x4A, 0x4A, 0x00, 0x24, 0x42, 0x4A,
  0x34, 0x00, 0x06, 0x48, 0x48, 0x3E, 0x00, 0x78, 0x04, 0x02, 0x7E, 0x00,
  0x7E, 0x48, 0x48, 0x30, 0x00, 0x02, 0x02, 0x7E, 0x02, 0x02, 0x00, 0x7C,
  0x12, 0x12, 0x7C, 0x00, 0x02, 0x02, 0x7E, 0x02, 0x02
};
const uint8_t measur_first_img[] PROGMEM = { //замер фона
  0x24, 0x42, 0x4A, 0x34, 0x00, 0x7C, 0x12, 0x12, 0x7C, 0x00, 0x7E, 0x04,
  0x08, 0x04, 0x7E, 0x00, 0x7E, 0x4A, 0x4A, 0x00, 0x7E, 0x12, 0x12, 0x0C,
  0x00, 0x00, 0x00, 0x3C, 0x24, 0x7E, 0x24, 0x3C, 0x00, 0x3C, 0x42, 0x42,
  0x3C, 0x00, 0x7E, 0x10, 0x10, 0x7E, 0x00, 0x7C, 0x12, 0x12, 0x7C
};
const uint8_t measur_second_img[] PROGMEM = { //замер образца
  0x24, 0x42, 0x4A, 0x34, 0x00, 0x7C, 0x12, 0x12, 0x7C, 0x00, 0x7E, 0x04,
  0x08, 0x04, 0x7E, 0x00, 0x7E, 0x4A, 0x4A, 0x00, 0x7E, 0x12, 0x12, 0x0C,
  0x00, 0x00, 0x00, 0x3C, 0x42, 0x42, 0x3C, 0x00, 0x7E, 0x4A, 0x4A, 0x30,
  0x00, 0x7E, 0x12, 0x12, 0x0C, 0x00, 0x7C, 0x12, 0x12, 0x7C, 0x00, 0x24,
  0x42, 0x4A, 0x34, 0x00, 0x7E, 0x40, 0x40, 0x7E, 0xC0, 0x00, 0x7C, 0x12,
  0x12, 0x7C
};
const uint8_t measur_ok_img[] PROGMEM = { //ок -
  0x3C, 0x42, 0x42, 0x3C, 0x00, 0x7E, 0x18, 0x24,
  0x42, 0x00, 0x08, 0x08, 0x08, 0x08, 0x00
};
const uint8_t warning_img[] PROGMEM = { //опасность!
  0x3C,
  0x42, 0x42, 0x3C, 0x00,
  0x7E, 0x02, 0x02, 0x7E,
  0x00, 0x7C, 0x12, 0x12,
  0x7C, 0x00, 0x3C, 0x42,
  0x42, 0x24, 0x00, 0x7E,
  0x10, 0x10, 0x7E, 0x00,
  0x3C, 0x42, 0x42, 0x3C,
  0x00, 0x3C, 0x42, 0x42,
  0x24, 0x00, 0x02, 0x02,
  0x7E, 0x02, 0x02, 0x00,
  0x7E, 0x48, 0x48, 0x30,
  0x00, 0x00, 0x5E
};
const uint8_t warning_inv_img[] PROGMEM = { //опасность!
  0x7E, 0x42, 0x3C, 0x3C,
  0x42, 0x7E, 0x00, 0x7C,
  0x7C, 0x00, 0x7E, 0x02,
  0x6C, 0x6C, 0x02, 0x7E,
  0x42, 0x3C, 0x3C, 0x5A,
  0x7E, 0x00, 0x6E, 0x6E,
  0x00, 0x7E, 0x42, 0x3C,
  0x3C, 0x42, 0x7E, 0x42,
  0x3C, 0x3C, 0x5A, 0x7E,
  0x7C, 0x7C, 0x00, 0x7C,
  0x7C, 0x7E, 0x00, 0x36,
  0x36, 0x4E, 0x7E, 0x7E,
  0x20, 0x7E
};
const uint8_t imp_s_img[] PROGMEM = { //имп/с
  0x7C, 0x20, 0x10, 0x7C,
  0x00, 0x7C, 0x08, 0x10,
  0x08, 0x7C, 0x00, 0x7C,
  0x04, 0x04, 0x7C, 0x00,
  0x40, 0x20, 0x10, 0x08,
  0x04, 0x00, 0x38, 0x44,
  0x44, 0x28
};
const uint8_t imp_m_img[] PROGMEM = { //имп/м
  0x7C, 0x20, 0x10, 0x7C,
  0x00, 0x7C, 0x08, 0x10,
  0x08, 0x7C, 0x00, 0x7C,
  0x04, 0x04, 0x7C, 0x00,
  0x40, 0x20, 0x10, 0x08,
  0x04, 0x00, 0x7C, 0x08,
  0x10, 0x08, 0x7C
};
const uint8_t dose_all_img[] PROGMEM = { //всего:
  0x7E, 0x4A, 0x4A, 0x34, 0x00, 0x3C, 0x42, 0x42, 0x24, 0x00, 0x7E, 0x4A,
  0x42, 0x00, 0x7E, 0x02, 0x02, 0x00, 0x3C, 0x42, 0x42, 0x3C, 0x00, 0x36
};

const uint8_t dose_max_img[] PROGMEM = { //макс
  0x7E, 0x04, 0x08, 0x04,
  0x7E, 0x00, 0x7C, 0x12,
  0x12, 0x7C, 0x00, 0x7E,
  0x18, 0x24, 0x42, 0x00,
  0x3C, 0x42, 0x42, 0x24,
  0x00, 0x36, 0x00
};
const uint8_t dose_min_img[] PROGMEM = { //средн
  0x7E, 0x04, 0x08, 0x04, 0x7E, 0x00, 0x7E, 0x10, 0x08, 0x7E, 0x00, 0x7E,
  0x08, 0x08, 0x7E, 0x00, 0x36, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00
};
//const uint8_t dose_max_img[] PROGMEM = { //MAX:
//  0xFE, 0xFE, 0x0C, 0x18, 0x0C, 0xFE, 0xFE, 0x00, 0xFC, 0xFE, 0x12, 0xFE,
//  0xFC, 0x00, 0xC6, 0xEE, 0x38, 0xEE, 0xC6, 0x00, 0x00, 0x6C, 0x6C, 0x00,
//  0x00, 0x00
//};
//const uint8_t dose_min_img[] PROGMEM = { //MIN:
//  0x7F, 0x7F, 0x06, 0x0C, 0x06, 0x7F, 0x7F, 0x00, 0x41, 0x7F, 0x7F, 0x41,
//  0x00, 0x7F, 0x7F, 0x06, 0x18, 0x7F, 0x7F, 0x00, 0x00, 0x36, 0x36, 0x00,
//  0x00, 0x00
//};
