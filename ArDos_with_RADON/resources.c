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

//=============шкала фона===============
const uint8_t back_scale_img[] PROGMEM = { //шкала фона
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

const uint8_t beep_alt_wait_img[] PROGMEM = { //звездочка
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
const uint8_t font_bat_img[] PROGMEM = { //батарея
  0x81, 0x81, 0x81, 0x81, 0x81, 0x81,
  0x81, 0x81, 0x81, 0x81, 0x81, 0xC3
};
const uint8_t font_sound_img[] PROGMEM = { //звуки
  0xE7, 0xE7, 0xC3, 0x81
};
const uint8_t font_alarm_img[] PROGMEM = { //тревога
  0xDF, 0xC3, 0x81, 0xC3, 0xDF
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
  0xFF, 0xFF, 0xF8, 0xF8, 0xF8, 0xF8, 0xF8, 0xF8, 0x7E, 0x7F, 0x3F, 0x1F,
  0x0F, 0x07, 0x00, 0x01, 0x0F, 0x1E, 0x38, 0x70, 0x60, 0xF0, 0xFE, 0xFF,
  0xFF, 0xFF, 0xFF, 0xFF, 0xFC, 0xF0, 0x60, 0x70, 0x38, 0x1F, 0x07, 0x01,
  0x00, 0x78, 0xF9, 0xF1, 0xF3, 0xF7, 0xFF, 0xFF, 0x7F, 0x3E, 0x00, 0x00
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

//=============шкалы===============
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

const uint8_t scan_stop_img[] PROGMEM = { //иконка паузы
  0x81, 0x81, 0xFF, 0xFF, 0x81, 0x81
};

//=============тех.символы и буквы===============
const uint8_t error_ico_img[] PROGMEM = { //ERR
  0x81, 0xB5, 0xB5, 0xBD, 0xFF, 0x81, 0xED,
  0xCD, 0xB3, 0xFF, 0x81, 0xED, 0xCD, 0xB3
};
const uint8_t logbook_ico_img[] PROGMEM = { //logbook
  0xC1, 0xDD, 0xA5, 0xBB, 0x83, 0xBB, 0xA5, 0xDD, 0xC1
};

const uint8_t colon_img[] PROGMEM = { //:
  0x00, 0x28, 0x00
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

#ifdef RUSSIAN //если выбран язык "русский"
const uint8_t day_img[] PROGMEM = { //дн
  0x60, 0x38, 0x38, 0x60, 0x00, 0x78, 0x20, 0x78
};
#endif
#ifdef ENGLISH //если выбран язык "английский"
const uint8_t day_img[] PROGMEM = { //дн
  0x78, 0x48, 0x30, 0x00, 0x00, 0x00, 0x00, 0x00
};
#endif
