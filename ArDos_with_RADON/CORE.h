#define TASK_UPDATE_TIME   1  //обновление времени
#define TASK_UPDATE_STAT   3  //обновление статистики
#define TASK_CALC_BACK_1   5  //расчет текущего фона этап-1
#define TASK_CALC_BACK_2   7  //расчет текущего фона этап-2
#define TASK_CALC_BACK_3   9  //расчет текущего фона этап-3
#define TASK_CALC_BACK_4   11 //расчет текущего фона этап-4
#define TASK_CALC_BACK_5   13 //расчет текущего фона этап-5
#define TASK_CALC_BACK_6   17 //расчет текущего фона этап-6
#define TASK_UPDATE_ACCUR  21 //обновление статистической точности
#define TASK_MAX_BACK      23 //поиск максимального фона
#define TASK_CALC_DOSE     25 //расчет дозы
#define TASK_UPDATE_ALARM  27 //обновление тревоги
#define TASK_UPDATE_UART   29 //обновление отправки данных в порт
#define TASK_UPDATE_ERROR  31 //обновление ошибок
#define TASK_UPDATE_MEASUR 33 //обновление режима замера
#define TASK_UPDATE_SLEEP  35 //обновление режима сна
#define TASK_UPDATE_POWER  37 //обновление состояния энергосбережения
#define TASK_UPDATE_BAT    39 //обновление состояния батареи
#define TASK_UPDATE_SCREEN 41 //обновление экрана

//перевод напряжения в значение ацп
uint8_t LOW_BAT_POWER; //минимальное рабочее напряжение батареи
uint8_t LOW_BAT_STAT; //напряжение оповещения о разряде батареи
uint8_t MIN_BAT; //минимальное напряжение батареи
uint8_t MAX_BAT; //максимальное напряжение батареи

//переменные питания
uint8_t bat = 5; //текущий заряд батареи
uint8_t bat_adc = MAX_BAT; //результат опроса акб
uint8_t hv_adc; //результат опроса АЦП преобразователя
uint8_t analogState; //флаги обновления аналоговых портов

uint8_t pump_puls_now = 10; //текущая длинна импульса преобразователя
uint16_t speed_hv; //текущая скорость накачки преобразователя
uint16_t speed_pump; //скорость накачки преобразователя
uint16_t speed_puls; //скорость накачки преобразователя

uint8_t pump_imp_time = 50; //период проверки преобразователя

enum {
  ADC_BAT, //флаг запуска замера батареи
  ADC_BAT_WAIT, //флаг ожидания установки напряжения ИОН
  ADC_HW, //флаг начала накачки преобразователя
  ADC_HW_DONE //флаг окончания накачки преобразователя
};

uint8_t sleep_count = 0; //счетчик ухода в сон
uint8_t sleep_mode = 0; //переключатель состояния сна
uint8_t sleep_manual = 0; //флаг ручной блокировки сна
boolean sleep_disable = 0; //флаг запрета сна

uint8_t power_manager = 2; //переключатель режимов питания мк

//переменные таймеров
volatile uint8_t tick_buff; //счетчик тиков для обработки данных
volatile uint8_t time_buff; //счетчик времени для обработки подсветки и вспышек

uint8_t timer_wait; //таймер отсчета миллисекунд для замера батареи
uint8_t timer_flash; //таймер отсчета миллисекунд для вспышек
uint8_t timer_light; //таймер отсчета миллисекунд для подсветки
uint16_t timer_millis; //таймер отсчета миллисекунд
uint16_t timer_melody; //таймер отсчета миллисекунд для мелодий

#define RESET_WDT __asm__ __volatile__ ("WDR") //сброс WDT
#define RESET_SYSTEM __asm__ __volatile__ ("JMP 0x0000") //перезагрузка

boolean _system_task(void); //основная задача

#include "SOUND.h"
#include "MEMORY.h"

//переменные обработки кнопок
enum {
  KEY_NULL,        //кнопка не нажата
  UP_KEY_PRESS,    //клик кнопкой вверх
  UP_KEY_HOLD,     //удержание кнопки вверх
  UP_KEY_KEEP,     //длительное удержание кнопки вверх
  DOWN_KEY_PRESS,  //клик кнопкой вниз
  DOWN_KEY_HOLD,   //удержание кнопки вниз
  DOWN_KEY_KEEP,   //длительное удержание кнопки вниз
  SEL_KEY_PRESS,   //клик кнопкой ок
  SEL_KEY_HOLD,    //удержание кнопки ок
  SEL_KEY_KEEP     //длительное удержание кнопки ок
};
enum {
  CHECK_KEYS, //кнопка не нажата
  UP_KEY,     //кнопка вверх
  DOWN_KEY,   //кнопка вниз
  SEL_KEY     //кнопка ок
};
uint8_t btn_check; //флаг разрешения опроса кнопки
uint8_t button_state; //текущее состояние кнопок

#if DEBUG_ENABLE
uint16_t debug_res = 0; //текущее количество сбросов
uint16_t debug_diff = 0; //разница значений перед сбросом
#endif

void _show_logo(void); //вывод логотипа
void _low_bat_show(void); //отрисовка сообщения разряженной батареи
void _show_load_bar(const char* txt); //вывод рамки загрузки
inline void _set_load_bar(uint8_t data, uint8_t min, uint8_t max); //установка полосы загрузки

void _bat_update(void); //опрос батареи
inline uint8_t _button_state(void); //проверка кнопок

void _start_pump(void); //первая накачка
void _update_pump_puls(void); //обновить длину импульса
void _pump_puls(uint8_t puls); //ипульс на преобразователь

uint8_t _convert_adc_bat(float vcc); //конвертация напряжения батареи
float _convert_vcc_bat(uint8_t adc); //конвертация напряжения батареи

//----------------------------------Прерывание ADC----------------------------------------------------
EMPTY_INTERRUPT(ADC_vect); //прерывание ADC
//-------------------------------Детектирование частиц------------------------------------------------
ISR(INT0_vect) //внешнее прерывание на пине INT0 - считаем импульсы от счетчика 1
{
  main_buff++; //прибавляем импульс в основной буфер
}
//--------------------------------Счет тиков WatchDog-------------------------------------------------
ISR(WDT_vect) //cчет тиков WatchDog
{
  if (++tick_buff == REBOOT_TICK) RESET_SYSTEM; //если буфер переполнен то перезагружаемся
  WDTCSR = (0x01 << WDCE) | (0x01 << WDE); //разрешаем изменения
  WDTCSR = (0x01 << WDIE) | (0x01 << WDE); //устанавливаем пределитель 2(режим прерываний + сброс)
}
//------------------------------Инициализация таймеров-----------------------------------------------
void _init_timers(void) //инициализация таймеров
{
  TCCR0A = 0x00; //отключаем OC0A/OC0B
  TCCR0B = (0x01 << CS01); //пределитель 8
  TIMSK0 = 0x00; //отключаем прерывания Таймера0

  TCCR1A = (0x01 << WGM11); //отключаем OC1A/OC1B
  TCCR1B = (0x01 << WGM13) | (0x01 << WGM12) | (0x01 << CS11) | (0x01 << CS10); //пределитель 64 | ICR режим
  TIMSK1 = 0x00; //отключаем прерывания Таймера1

  TCCR2A = 0x00; //отключаем OC2A/OC2B
  TCCR2B = (0x01 << CS22); //пределитель 64
  TIMSK2 = 0x00; //отключаем прерывания Таймера2
}
//-----------------------------Инициализация настроек акб----------------------------------------------
void _init_battery(void) //инициализация настроек акб
{
  LOW_BAT_POWER = _convert_adc_bat(LOW_BAT_POWER_V);
  LOW_BAT_STAT = _convert_adc_bat(LOW_BAT_STAT_V);
  MIN_BAT = _convert_adc_bat(MIN_BAT_V);
  MAX_BAT = _convert_adc_bat(MAX_BAT_V);
}
//------------------------------Инициализация настроек------------------------------------------------
void _init_settings(void) //инициализация настроек
{
  _set_contrast_lcd(mainSettings.contrast); //установка контрастности
  _buzz_set_vol(mainSettings.volume); //устанавливаем громкость щелчков
}
//----------------------------------Включение ADC-----------------------------------------------------
void _adc_enable(void) //включение ADC
{
  PRR &= ~(0x01 << PRADC); //включаем питание АЦП
  ADCSRA = (0x01 << ADEN) | (0x01 << ADIE) | (0x01 << ADPS2) | (0x01 << ADPS1) | (0x01 << ADPS0); //настройка АЦП
}
//----------------------------------Выключение ADC----------------------------------------------------
void _adc_disable(void) //выключение ADC
{
  ADCSRA = (0x01 << ADPS2) | (0x01 << ADPS1) | (0x01 << ADPS0); //настройка АЦП
  ADMUX |= 0x0F; //сбросли признак чтения АЦП
  PRR |= (0x01 << PRADC); //выключаем питание ацп
  power_status &= ~(0x01 << WAIT_ADC); //сбросили флаг запрета сна
  analogState = 0x00; //сбросили флаги обновления АЦП
}
//----------------------------------Включение WDT-----------------------------------------------------
void _wdt_enable(void) //включение WDT
{
  cli(); //запрещаем прерывания
  RESET_WDT; //сброс WDT
  WDTCSR = (0x01 << WDCE) | (0x01 << WDE); //разрешаем изменения
  WDTCSR = (0x01 << WDIE) | (0x01 << WDE); //устанавливаем пределитель 2(режим прерываний + сброс)
  sei(); //разрешаем прерывания
}
//----------------------------------Выключение WDT----------------------------------------------------
void _wdt_disable(void) //выключение WDT
{
  RESET_WDT; //сброс WDT
  WDTCSR = (0x01 << WDCE) | (0x01 << WDE); //разрешаем изменения
  WDTCSR = 0x00; //выключаем WDT
  power_status &= ~(0x01 << WAIT_WDT); //сбросили флаг запрета сна
}
//-------------------------------Первичный запуск WDT-------------------------------------------------
void _wdt_start_mode(void) //первичный запуск WDT
{
  cli(); //запрещаем прерывания
  RESET_WDT; //сброс WDT
  WDTCSR = (0x01 << WDCE) | (0x01 << WDE); //разрешаем изменения
  WDTCSR = (0x01 << WDE) | (0x01 << WDP3); //устанавливаем таймер WDT на 4сек
}
//---------------------------Проверка гоовности дисплея-----------------------------------------------
boolean _check_screen(void) //проверка гоовности дисплея
{
  if (!screen_update) { //обновление дисплея
    if (display_update <= DISPLAY_INIT) {
      screen_update = 1; //сброс флага
      return 1;
    }
  }
  return 0;
}
//--------------------------Ожидание с выходом по кнопке---------------------------------------------
void _wait(uint32_t timer) //ожидание с выходом по кнопке
{
  for (timer_millis = timer; timer_millis && !_button_state();) _system_task(); // ждем, преобразование данных
}
//--------------------------Ожидание без выхода по кнопке--------------------------------------------
void _wait_now(uint32_t timer) //ожидание без выхода по кнопке
{
  for (timer_millis = timer; timer_millis || display_update;) _system_task(); // ждем, преобразование данных
}
//------------------------Таймер общего назначения старт/стоп-------------------------------
void _timer_wait(uint8_t _time) {
  PRR &= ~(0x01 << PRTIM2); //включаем питание таймера
  TIMSK2 |= (0x01 << TOIE2); //разрешаем прерывания
  power_status |= (0x01 << WAIT_TIM2);
  timer_wait = _time; //установили время
}
void _timer_stop(void) { //таймер стоп
  TCNT2 = TIMSK2 = 0x00; //сбрасываем счетный регистр и отключаем прерывания
  PRR |= (0x01 << PRTIM2); //выключаем питание таймера
  power_status &= ~(0x01 << WAIT_TIM2);
}
void _rad_flash_on(void) {
  PRR &= ~(0x01 << PRTIM2); //включаем питание таймера
  TIMSK2 |= (0x01 << TOIE2); //разрешаем прерывания
  timer_flash = RAD_FLASH_TIME; //установили время
  power_status |= (0x01 << WAIT_TIM2);
  RAD_FLASH_ON; //включили индикацию
}
void _backl_lcd_on(void) { //подсветка старт
  PRR &= ~(0x01 << PRTIM2); //включаем питание таймера
  if (OCR2A < 5) OCR2A = 5; //установили минимальный шим
  TIFR2 |= (0x01 << OCF2A); //сбрасываем флаг прерывания
  TIMSK2 |= (0x01 << OCIE2A) | (0x01 << TOIE2); //разрешаем прерывания
  timer_light = 4; //установили таймер
  power_status |= (0x01 << WAIT_TIM2);
  light_switch = 1; //устанасвливаем флаг разгорания подсветки
}
void _backl_lcd_off(void) { //подсветка стоп
  PRR &= ~(0x01 << PRTIM2); //включаем питание таймера
  if (OCR2A > 250) OCR2A = 250; //установили максимальный шим
  TIFR2 |= (0x01 << OCF2A); //сбрасываем флаг прерывания
  TIMSK2 |= (0x01 << OCIE2A) | (0x01 << TOIE2); //разрешаем прерывания
  timer_light = 4; //установили таймер
  power_status |= (0x01 << WAIT_TIM2);
  light_switch = 0; //устанасвливаем флаг затухания подсветки
}
//------------------------------------Таймер общего назначения-------------------------------------------
ISR(TIMER2_OVF_vect) //плавная подсветка
{
#if defined(PCD8544)
  if (TIMSK2 & (0x01 << OCIE2A)) BACKL_ON; //включаем подсветку
#endif
  if (time_buff < 255) time_buff++;
}
#if defined(PCD8544)
ISR(TIMER2_COMPA_vect, ISR_NAKED) {
  __asm__ __volatile__ (
#if DISP_BACKL_INV
    "CBI %[_BACKL_PORT], %[_BACKL_BIT] \n\t" //LOW на выход пина
#else
    "SBI %[_BACKL_PORT], %[_BACKL_BIT] \n\t" //HIGH на выход пина
#endif
    "RETI                              \n\t" //выход из прерывания
    :
    : [_BACKL_PORT]"I"(_SFR_IO_ADDR(BACKL_PORT)),
    [_BACKL_BIT]"I"(BACKL_BIT)
  );
}
#endif
//---------------------------------------Ожидание---------------------------------------------------------
void _wait_pwr(void) //ожидание
{
  SMCR = (0x01 << SE);  //устанавливаем режим сна idle

  MCUCR = (0x01 << BODS) | (0x01 << BODSE); //выкл bod
  MCUCR = (0x01 << BODS);

  asm ("sleep");  //с этого момента спим.
}
//-------------------------------------Энергосбережение---------------------------------------------------
void _save_pwr(void) //энергосбережение
{
  SMCR = (0x01 << SM2) | (0x01 << SM1) | (0x01 << SE);  //устанавливаем режим сна standby

  MCUCR = (0x01 << BODS) | (0x01 << BODSE); //выкл bod
  MCUCR = (0x01 << BODS);

  asm ("sleep");  //с этого момента спим.
}
//-------------------------------------Глубокий сон--------------------------------------------------------
void _sleep_pwr(void) //энергосбережение
{
  SMCR = (0x01 << SM1) | (0x01 << SE);  //устанавливаем режим сна powerdown

  MCUCR = (0x01 << BODS) | (0x01 << BODSE); //выкл bod
  MCUCR = (0x01 << BODS);

  asm ("sleep");  //с этого момента спим.
}
//-------------------------Режим пониженного энергопотребления----------------------------------------------------
void _low_pwr(void) //режим пониженного энергопотребления
{
  if (!power_status) _sleep_pwr(); //режим глубокого энергосбережения
  else if (!(power_status & ((0x01 << WAIT_WDT) | (0x01 << WAIT_DSP) | (0x01 << WAIT_ADC) | (0x01 << WAIT_COMP) | (0x01 << WAIT_TIM1) | (0x01 << WAIT_TIM2) | (0x01 << WAIT_PWR1)))) _save_pwr(); //режим энергосбережения
  else if (!(power_status & ((0x01 << WAIT_WDT) | (0x01 << WAIT_DSP) | (0x01 << WAIT_COMP)))) _wait_pwr(); //режим ожидания
}
//-------------------------------------Выход из сна--------------------------------------------------------
void _sleep_out(void) //выход из сна
{
  if (sleep_mode) { //если выключели подсветку
#if defined(PCD8544)
    _backl_lcd_on(); //включаем подсветку
#endif
    if (sleep_mode == 2) { //если спали
      _disable_sleep_lcd(); //выводим дисплей из сна
      _buzz_enable(); //восстанавливаем настройку щелчков
      screen_update = 0; //разрешаем обновления экрана
    }
#if defined(SSD1306) || defined(SH1106)
    _set_contrast_lcd(mainSettings.contrast); //установка яркости
#endif
    sleep_mode = 0; //сбрасываем флаг сна
  }
  sleep_count = 0; //обнуляем счетчик сна
}
//------------------------------Выход из сна и сброс флагов-----------------------------------------------
void _disable_sleep(void) //выход из сна
{
  _sleep_out(); //выход из сна
  screen_update = 0; //разрешаем обновления экрана
  time_out = 0; //сбрасываем счетчик авто-выхода
}
//---------------------------------------Включение питания------------------------------------------------------
#if PWR_ON_RETURN
EMPTY_INTERRUPT(INT1_vect); //внешнее прерывание на пине INT1 - включение питания
#endif
//-------------------------------------Выключение устройства----------------------------------------------------
uint8_t _system_power_down(void) //выключение устройства
{
  cli(); //запрещаем прерывания

  _wdt_disable(); //выключаем watchdog
  _adc_disable(); //выключаем питание АЦП

#if PUMP_FEEDBACK == 1
  ACSR |= (0x01 << ACD); //отключаем компаратор
#endif

  _timer_stop(); //выключаем таймер

#if defined(PCD8544)
  BACKL_OFF; //выключаем подсветку
#endif
  SOUND_STOP; //выключаем таймер бузера
  BUZZ_OFF; //выключаем бузер

  FLASH_OFF; //выключаем фонарь
  RAD_FLASH_OFF; //выключаем индикацию

  _enable_sleep_lcd(); //выключаем дисплей
#if defined(PCD8544)
  LCD_DISABLE; //выключаем питание дисплея
#else
  PWR_LCD_OFF; //выключаем питание дисплея
#endif

#if PWR_ON_RETURN
  EIMSK = (0x01 << INT1); //разрешаем внешнее прерывание INT1

  sei(); //разрешаем прерывания

  while (1) { //цикл выключенного питания
    _sleep_pwr(); //спим

    uint16_t startDellay = POWER_ON_TIME; //устанавливаем таймер
    while (!SEL_CHK) { //если кнопка не отжата
      if (startDellay) { //если время не истекло
        _delay_ms(1); //ждем 1мс
        startDellay--; //отнимаем от таймера 1 мс
      }
      else { //иначе включаем питание
        if (!DOWN_CHK) return INIT_PROGRAM; //выходим

        _init_lcd(); //включаем дисплей
#if !PUMP_FEEDBACK
        _adc_enable(); //включаем питание АЦП
#endif
        _bat_update(); //опрос батареи
        _wdt_enable(); //запускаем WDT
        if (bat_adc < LOW_BAT_POWER) { //если батарея не разряжена
          _set_contrast_lcd(mainSettings.contrast); //установка контраста
#if defined(PCD8544)
          _backl_lcd_on(); //включаем подсветку
#endif
#if PUMP_FEEDBACK == 1
          ACSR = (0x01 << ACBG) | (0x01 << ACIS1); //включаем компаратор
#if !PUMP_FEEDBACK_PULL
          ACSR |= (0x01 << ACIS1); //включаем компаратор
#endif
#endif
          _show_logo(); //вывод логотипа
          _start_pump(); //первая накачка преобразователя
          btn_check = 0; //запрещем проверку кнопки
          EIFR |= (0x01 << INTF1) | (0x01 << INTF0); //сбросили флаги прерывания портов
          EIMSK = (0x01 << INT0); //разрешаем внешнее прерывание INT0
          return MAIN_PROGRAM; //выходим
        }
        else { //иначе выводим предупреждение об разряженной батарее
          _low_bat_show(); //отрисовка сообщения разряженной батареи
          _wait_now(POWER_TIME); //ждём
          return POWER_DOWN_PROGRAM; //перезапускаем сон
        }
      }
    }
  }
#else
  EIMSK = 0x00; //запрещаем внешние прерывание
  _sleep_pwr(); //спим
#endif
  return INIT_PROGRAM;
}
//---------------------------------Разрешить щелчки---------------------------------------------------
void _buzz_enable(void) //разрешить щелчки
{
  mainSettings.buzz_switch &= ~0x80;
}
//---------------------------------Запретить щелчки---------------------------------------------------
void _buzz_disable(void) //запретить щелчки
{
  mainSettings.buzz_switch |= 0x80;
}
//--------------------------Вибрация и световая индикация тревоги---------------------------------
void _vibro_on(uint8_t vibro) //вибрация и световая индикация тревоги
{
  if (vibro > 1) {
    if (!timer_millis) { //если пришло время
      switch (pgm_read_word(&alarm_vibro[vibro_switch][0])) {
        case 0:
#if (TYPE_ALARM_IND == 1)
          FLASH_ON;
#elif (TYPE_ALARM_IND == 2)
#if defined(PCD8544)
          BACKL_ON;
#endif
#endif
          VIBRO_ON;
          break;

        case 1:
#if (TYPE_ALARM_IND == 1)
          FLASH_OFF;
#elif (TYPE_ALARM_IND == 2)
#if defined(PCD8544)
          BACKL_OFF;
#endif
#endif
          VIBRO_OFF;
          break;
      }
      timer_millis = pgm_read_word(&alarm_vibro[vibro_switch][1]); //устанавливаем паузу перед воспроизведением нового семпла
      if (++vibro_switch > (sizeof(alarm_vibro) / 4) - 1) vibro_switch = 0; //переключпем на следующий семпл
    }
  }
}
//-----------------------Выключение вибрация и световой индикаци--------------------------------
void _vibro_off(void) //выключение вибрация и световой индикаци
{
  vibro_switch = 0; //сбрасываем переключатель вибрации
#if (TYPE_ALARM_IND == 1)
  FLASH_OFF; //выключаем фонарик
#elif (TYPE_ALARM_IND == 2)
#if defined(PCD8544)
  if (light_switch) BACKL_ON; //включаем подсветку, если была включена настройками
  else BACKL_OFF; //выключаем подсветку
#endif
#endif
  VIBRO_OFF; //выключаем вибрацию
}
//-----------------------------------Вкл/выкл подсветки---------------------------------
void _fast_light(void) //вкл/выкл подсветки
{
  if (!mainSettings.sleep_switch) { //если сон выключен
#if defined(SSD1306) || defined(SH1106)
    _enable_sleep_lcd(); //выключаем подсветку, если была включена настройками
    _buzz_disable(); //запрещаем щелчки
    sleep_mode = 2; //выставляем флаг сна
#endif
#if defined(PCD8544)
    if (light_switch) _backl_lcd_off(); //выключаем подсветку, если была включена настройками
    else _backl_lcd_on(); //включаем подсветку
#endif
  }
  else if (!sleep_disable) sleep_manual ^= 0x01; //иначе переключаем ручную блокировку сна
}
//---------------------------------Проверка инверсии кнопок----------------------------------------------
uint8_t _button_switch(uint8_t _switch) //проверка инверсии кнопок
{
#if ROTATE_DISP_RETURN
  if (mainSettings.rotation) { //если изображение перевернуто
    switch (_switch) { //инвертируем управление
      case UP_KEY: return DOWN_KEY;
      case DOWN_KEY: return UP_KEY;
    }
  }
#endif
  return _switch; //возвращаем нормальное состояние
}
//---------------------------------------Проверка кнопок-------------------------------------------------
inline uint8_t _button_state(void) //проверка кнопок
{
  uint8_t button = button_state; //запоминаем текущее состояние кнопки
  button_state = 0; //сбрасываем текущее состояние кнопки
  return button; //возвращаем состояние кнопки
}
//---------------------------------------Обновление кнопок------------------------------------------------
inline uint8_t _button_state_update(void) //обновление кнопок
{
  static boolean btn_state; //флаг текущего состояния кнопки
  static uint8_t btn_switch; //флаг мультиплексатора кнопок
  static uint8_t btn_tmr; //таймер тиков обработки кнопок
  static uint8_t btn_tmr_keep; //таймер тиков обработки кнопок

  switch (btn_switch) { //переключаемся в зависимости от состояния мультиопроса
    case CHECK_KEYS:
      if (!UP_CHK) { //если нажата правая кл.
        btn_switch = UP_KEY; //выбираем клавишу опроса
        btn_state = 0; //обновляем текущее состояние кнопки
      }
      else if (!DOWN_CHK) { //если нажата левая кл.
        btn_switch = DOWN_KEY; //выбираем клавишу опроса
        btn_state = 0; //обновляем текущее состояние кнопки
      }
      else if (!SEL_CHK) { //если нажата кл. ок
        btn_switch = SEL_KEY; //выбираем клавишу опроса
        btn_state = 0; //обновляем текущее состояние кнопки
      }
      else btn_state = 1; //обновляем текущее состояние кнопки
      break;
    case UP_KEY: btn_state = UP_CHK; break; //опрашиваем кнопку вверх
    case DOWN_KEY: btn_state = DOWN_CHK; break; //опрашиваем кнопку вниз
    case SEL_KEY: btn_state = SEL_CHK; break; //опрашиваем клавишу ок
  }

  switch (btn_state) { //переключаемся в зависимости от состояния клавиши
    case 0:
      if (btn_check == 1) { //если разрешена провекрка кнопки
        if (++btn_tmr > BTN_HOLD_TICK) { //если таймер больше длительности удержания кнопки
          btn_tmr = BTN_GIST_TICK; //сбрасываем таймер на антидребезг
          btn_tmr_keep = 0; //сбрасываем таймер удержания кнопки
          melodyStop(); //сброс воспроизведения мелодии
          if (sleep_mode != 2) { //если не спим
            _disable_sleep(); //выход из сна
            btn_check = 2; //разрешаем проверку удержания кнопки
            switch (_button_switch(btn_switch)) { //переключаемся в зависимости от состояния мультиопроса
              case UP_KEY: return UP_KEY_HOLD; //возвращаем удержание кнопки вверх
              case DOWN_KEY: return DOWN_KEY_HOLD; //возвращаем удержание кнопки вниз
              case SEL_KEY: return SEL_KEY_HOLD; //возвращаем удержание кнопки ок
            }
          }
          else btn_check = 0; //запрещем проверку кнопки
        }
      }
      else if (btn_check == 2) { //если было удержание кнопки
        if (++btn_tmr_keep > BTN_KEEP_TICK) { //если прошел таймаут удержания кнопки
          btn_tmr_keep = 0; //сбрасываем таймер удержания кнопки
          melodyStop(); //сброс воспроизведения мелодии
          if (sleep_mode != 2) { //если не спим
            _disable_sleep(); //выход из сна
            switch (_button_switch(btn_switch)) { //переключаемся в зависимости от состояния мультиопроса
              case UP_KEY: return UP_KEY_KEEP; //возвращаем длительное удержание кнопки вверх
              case DOWN_KEY: return DOWN_KEY_KEEP; //возвращаем длительное удержание кнопки вниз
              case SEL_KEY: return SEL_KEY_KEEP; //возвращаем длительное удержание кнопки ок
            }
          }
          else btn_check = 0; //запрещем проверку кнопки
        }
      }
      break;

    case 1:
      if (btn_tmr > BTN_GIST_TICK) { //если таймер больше времени антидребезга
        btn_tmr = BTN_GIST_TICK; //сбрасываем таймер на антидребезг
        btn_check = 0; //запрещем проверку кнопки
        melodyStop(); //сброс воспроизведения мелодии
        if (!sleep_mode) { //если не спим и если подсветка включена, поднимаем признак нажатия
          if (!mainSettings.knock_disable) soundPulse(FREQ_BEEP, TIME_BEEP); //щелчок пищалкой
          _disable_sleep(); //выход из сна
          switch (_button_switch(btn_switch)) { //переключаемся в зависимости от состояния мультиопроса
            case UP_KEY: return UP_KEY_PRESS; //возвращаем клик кнопки вверх
            case DOWN_KEY: return DOWN_KEY_PRESS; //возвращаем клик кнопки вниз
            case SEL_KEY: return SEL_KEY_PRESS; //возвращаем клик кнопки ок
          }
        }
        else _disable_sleep(); //выход из сна
      }
      else if (!btn_tmr) {
        btn_check = 1; //разрешаем проверку кнопки
        btn_switch = CHECK_KEYS; //сбрасываем мультиплексатор кнопок
      }
      else btn_tmr--; //убираем дребезг
      break;
  }

  return KEY_NULL; //кнопка не нажата
}
//---------------------------------Обработка аналоговых входов--------------------------------------------
void _analog_update(void) //обработка аналоговых входов
{
  if (!(ADCSRA & (0x01 << ADSC))) { //ждем окончания преобразования
    switch (ADMUX & 0x0F) {
#if !PUMP_FEEDBACK
      case ANALOG_DET_PIN: { //обратная связь
          hv_adc = ADCH; //записывем результат опроса АЦП
          if ((hv_adc < pumpSettings.ADC_value) && (speed_puls < 999)) { //значение АЦП при котором на выходе 400В
            _pump_puls(pump_puls_now); //импульс на преобразователь
            speed_puls++; //считаем скорость накачки
            ADCSRA |= (0x01 << ADSC); //запускаем преобразование
          }
          else {
            if ((9999 - speed_pump) >= speed_puls) speed_pump += speed_puls; //если счетчик импульсов не переполнен
            else speed_pump = 9999; //иначе переполнение
            if (speed_puls < 999) analogState &= ~(0x01 << ADC_HW); //сбросили флаг обновления АЦП обратной связи
            power_status &= ~(0x01 << WAIT_ADC); //сбросили флаг запрета сна
            speed_puls = 0; //сбросили счетчик импульсов
            ADMUX |= 0x0F; //сбросли признак чтения АЦП
          }
        }
        break;
#endif
      case 0x0E: { //замер батареи
          if (!timer_wait) { //если пришло время
            if (analogState & (0x01 << ADC_BAT_WAIT)) { //если первый запуск
              analogState &= ~(0x01 << ADC_BAT_WAIT); //сбросили флаг ожидания выравнивания напряжения ИОН
              ADCSRA |= (0x01 << ADSC); //запускаем преобразование
            }
            else {
              bat_adc = ADCH; //считываем состояние батареи
              _update_pump_puls(); //обновить длинну импульса

              if (bat_adc == 255) bat_adc = MIN_BAT; //защита от ложных данных
              if (bat_adc < MIN_BAT) { //мин.напр. 3v макс.нап. 4,2v
                if (bat_adc < MAX_BAT) bat = 5;  //если батарея заряжена
                else { //иначе расчитывает указатель заряда батареи
                  bat = map(bat_adc, MIN_BAT, MAX_BAT, 0, 6); //переводим значение в полосы акб
                  bat = (bat > 5) ? 5 : bat; //ограничиваем
                }
              }
              else bat = 0; //иначе акб разряжен
#if PUMP_FEEDBACK
              _adc_disable(); //выключаем питание АЦП
#else
              power_status &= ~(0x01 << WAIT_ADC); //сбросили флаг запрета сна
              analogState &= ~(0x01 << ADC_BAT); //сбросили флаг обновления АЦП замера батареи
              ADMUX = (0x01 << REFS1) | (0x01 << REFS0) | (0x01 << ADLAR) | 0x0F; //сбросли признак чтения АЦП
              _timer_wait(5); //включили таймер ожидания для выравнивания напряжения ИОН
#endif
            }
          }
        }
        break;
      default:
        if (analogState & (0x01 << ADC_BAT)) { //замер батареи
#if PUMP_FEEDBACK
          _adc_enable(); //включаем питание АЦП
#endif
          ADMUX = (0x01 << REFS0) | (0x01 << ADLAR) | (0x01 << MUX3) | (0x01 << MUX2) | (0x01 << MUX1); //выбор внешнего опорного + ИОН
          _timer_wait(7); //включили таймер ожидания для выравнивания напряжения ИОН
          analogState |= (0x01 << ADC_BAT_WAIT); //установили флаг ожидания выравнивания напряжения ИОН
          power_status |= (0x01 << WAIT_ADC); //установили флаг запрета сна
          return; //выходим
        }
#if !PUMP_FEEDBACK
        if (analogState & (0x01 << ADC_HW)) { //обратная связь
          if (!timer_wait) { //если пришло время
            ADMUX = (0x01 << REFS1) | (0x01 << REFS0) | (0x01 << ADLAR) | ANALOG_DET_PIN; //выбор внутреннего опорного 1.1В
            ADCSRA |= (0x01 << ADSC); //запускаем преобразование
            power_status |= (0x01 << WAIT_ADC); //установили флаг запрета сна
          }
          return; //выходим
        }
#endif
        break;
    }
  }
#if PUMP_FEEDBACK
  if (analogState & (0x01 << ADC_HW)) { //обратная связь
    if (TIFR0 & (0x01 << TOV0)) { //иначе если пришло время подать импульс
      if (COMP_INT_CHK || (speed_puls >= 999)) { //если накачка окончена
        COMP_INT_CLR; //сбрасываем флаг прерывания
        PRR |= (0x01 << PRTIM0); //выключаем питание таймера
        power_status &= ~(0x01 << WAIT_COMP); //сбросили флаг запрета сна
        analogState &= ~(0x01 << ADC_HW); //сбросили флаг обновления обратной связи
        analogState |= (0x01 << ADC_HW_DONE); //установили флаг
      }
      else {
        _pump_puls(pump_puls_now); //импульс на преобразователь
        speed_puls++; //считаем скорость накачки
        TCNT0 = 0; //сбросили счетчик
        TIFR0 |= (0x01 << TOV0); //сбрасываем флаг прерывания
      }
    }
  }
#endif
}
//-------------------------------Ипульс на преобразователь------------------------------------
void _pump_puls(uint8_t puls) //ипульс на преобразователь
{
  __asm__ __volatile__ (
    "CLI                  \n\t" //запретили прерывания
    "SBI %[PORT], %[PIN]  \n\t" //HIGH на выход пина
    "_LOOP_START_%=:      \n\t" //цикл задержки
    "DEC %[COUNT]         \n\t" //декремент счетчика циклов
    "BRNE _LOOP_START_%=  \n\t" //переход в начало цикла если счетчик не равен нулю
    "CBI %[PORT], %[PIN]  \n\t" //LOW на выход пина
    "SEI                  \n\t" //разрешили прерывания
    :"=r"(puls)
    :[COUNT]"0"(puls),
    [PORT]"I"(_SFR_IO_ADDR(CONV_PORT)),
    [PIN]"I"(CONV_BIT)
  );
}
//-------------------------------Обновить длину импульса--------------------------------------
void _update_pump_puls(void) //обновить длину импульса
{
  uint16_t vcc = (uint16_t)((pumpSettings.reference * 256000UL) / ((bat_adc > MIN_BAT) ? MIN_BAT : bat_adc)); //напряжение батареи
  pump_puls_now = (uint8_t)((469UL * pumpSettings.puls) / vcc); //находим длину импульса
}
//---------------------------Запуск накачки преобразователя---------------------------------
void _pump_update(void) //накачка по обратной связи с АЦП
{
  analogState |= (0x01 << ADC_HW); //установили флаг обновления АЦП обратной связи
#if PUMP_FEEDBACK
  power_status |= (0x01 << WAIT_COMP); //установили флаг запрета сна
  PRR &= ~(0x01 << PRTIM0); //включаем питание таймера
  TCNT0 = 255; //сбросили счетчик
  COMP_INT_CLR; //сбрасываем флаг прерывания
#endif
}
//------------------------Статус работы накачки преобразователя------------------------------
boolean _pump_status(void) //статус работы накачки преобразователя
{
  return (analogState & ((0x01 << ADC_HW) | (0x01 << ADC_HW_DONE))); //возвращаем статус
}
//-----------------------Статус активной накачки преобразователя-----------------------------
boolean _pump_status_progress(void) //статус активной накачки преобразователя
{
  return (analogState & (0x01 << ADC_HW)); //возвращаем статус
}
//----------------------Статус завершения накачки преобразователя----------------------------
boolean _pump_status_compleated(void) //статус завершения накачки преобразователя
{
  return (analogState & (0x01 << ADC_HW_DONE)); //возвращаем статус
}
//------------------Установить статус завершения накачки преобразователя---------------------
void _pump_status_compleated_set(void) //установить статус завершения накачки преобразователя
{
  analogState |= (0x01 << ADC_HW_DONE); //устанавливаем статус
}
//-------------------Сбросить статус завершения накачки преобразователя----------------------
void _pump_status_compleated_reset(void) //сбросить статус завершения накачки преобразователя
{
  analogState &= ~(0x01 << ADC_HW_DONE); //сбрасываем статус
}
//-----------------------------------Первая накачка-------------------------------------------
void _start_pump(void) //первая накачка
{
  uint8_t timer = (START_PUMP_TIME / 50); //таймер авто-выхода

  _show_load_bar(LOAD); //загрузка...
  _pump_update(); //накачка по обратной связи

  while (1) { //первая накачка
    _system_task(); //обновление данных

    if (!timer_millis) { //если время пришло
      if (!_pump_status_progress() || !timer--) break; //если время вышло то останавливаем накачку

      timer_millis = 50; //очищаем буфер тиков
#if PUMP_FEEDBACK
      _set_load_bar(timer, (START_PUMP_TIME / 50), 0); //прогресс бар накачки преобразователя
#else
      _set_load_bar(hv_adc, 0, pumpSettings.ADC_value); //прогресс бар накачки преобразователя
#endif
    }
  }

  speed_pump = 0; //сбросили импульсы накачки
  speed_puls = 0; //сбросили импульсы накачки
}
//-------------------------Конвертация напряжения преобразователя-----------------------------
#if !PUMP_FEEDBACK
uint16_t _convert_vcc_hv(uint8_t adc) //конвертация напряжения преобразователя
{
  return adc * pumpSettings.reference * pumpSettings.k_delitel / 256; //считем высокое перед выводом
}
#endif
//--------------------------------Опрос батареи----------------------------------------------
void _bat_check(void) //опрос батареи
{
  analogState = (0x01 << ADC_BAT); //установили флаг обновления АЦП замер батареи
  while (analogState) _system_task(); //обработка аналоговых входов
}
//--------------------------------Опрос батареи----------------------------------------------
void _bat_update(void) //опрос батареи
{
  analogState |= (0x01 << ADC_BAT); //установили флаг обновления АЦП замер батареи
}
//--------------------------Конвертация напряжения батареи-----------------------------------
uint8_t _convert_adc_bat(float vcc) //конвертация напряжения батареи
{
  return (pumpSettings.reference * 256.0) / vcc; //состояние батареи
}
//--------------------------Конвертация напряжения батареи-----------------------------------
float _convert_vcc_bat(uint8_t adc) //конвертация напряжения батареи
{
  return (pumpSettings.reference * 256.0) / adc; //состояние батареи
}
