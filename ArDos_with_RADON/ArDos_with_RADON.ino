/*Arduino IDE 1.8.13
  Версия программы RADON v3.7.1 low_pwr release 16.12.21 специально для проекта ArDos
  Страница проекта ArDos http://arduino.ru/forum/proekty/ardos-dozimetr-prodolzhenie-temy-chast-%E2%84%962 и прошивки RADON https://github.com/radon-lab/ArDos_with_RADON
  Желательна установка OptiBoot v8 https://github.com/Optiboot/optiboot

  Внимание!!! При выключении пункта "СОН" в меню настроек влечет увеличением энергопотребления, но тем самым увеличивается производительность устройства.

  Для полного сброса настроек(в том числе данных журнала и статистики накопленной дозы) необходимо зажать клавишу "ОК" и включить питание.
  Если что-то идет или работает не так, в первую очередь пробуйте сброс настроек хот-кеем как описано выше!!!

  Не забудьте установить свои настройки DEFAULT_ADC_VALUE и DEFAULT_DIV_FACTOR в файле "config"!!! Этот файл также можно сохранить отдельно и вставлять в новые версии программы.

  После выключения устройства при низком напряжении акб, включить его можно или передергиванием выключателя питания или зажать кнопку "OK" более чем на 2 сек.


  -Обозначения иконок-

  - Иконка "Динамик"
  Две скобки - звуки клавиш и треск включен
  Горизонтальная волна - звук клвиш выключен, треск включен
  Звёздочка - звук клавиш включен, треск выключен
  Крестик - звук клавиш и треск выключены

  - Иконка "Колокольчик"
  Волна и две скобки - звки и вибрация при тревоге включены
  Две волны - звук тревоги выключен, вибрация включена
  Две скобки - звук тревоги включен, вибрация выключена
  Звёздочка - ожидание понижения фона
  Крестик - звуки и вибрация при тревоге выключены

  - Иконка "Книга"
  Статичная - Журнал включен
  Мигающая - Есть не прочитанная информация

  - Иконка "ERR"
  Мигающая - Есть не прочитанная ошибка

  - Иконка "Пауза"
  Режим "поиск" приостановлен


  -Действия клавиш-

  - На экране ФОН
  Вверх - выбор (график | средн. и макс. фон | бета и гамма), удерж. - вкл/выкл фонарик
  Вниз - сбросить текущий фон и (график | средн. и макс. фон | бета и гамма), удерж. - вкл/выкл подсветку
  Ок - переключить экран (фон | доза), удерж. - выход в меню

  - На экране ДОЗА
  Вверх - смена подрежима(текущая доза | доза за все время), удерж. - вкл/выкл фонарик
  Вниз - сброс показаний(текущей дозы | дозы за все время), удерж. - вкл/выкл подсветку
  Ок - переключить экран, удерж. - выход в меню

  - На экране ПОИСК
  Вверх - пауза графика и показателей, удерж. - вкл/выкл фонарик
  Вниз - сброс графика и показателей, удерж. - вкл/выкл подсветку
  Ок - переключить единицы измерения, удерж. - выход в меню

  - На экране БЕТА
  Вверх - остановить замер, удерж. - вкл/выкл фонарик
  Вниз - принудительный сброс при замере, удерж. - вкл/выкл подсветку
  Ок - начать замер / следующий замер, удерж. - выход в меню

  - На экране НАСТРОЙКИ
  Вверх - позиция выше/прибавить показания, удерж. - вкл/выкл фонарик
  Вниз - позиция ниже/убавить показания, удерж. - вкл/выкл подсветку
  Ок - перейти к настройкам/перйти к выбору позиции, удерж. - выход в меню

   - На экране МЕНЮ
  Вверх - позиция выше, удерж. - вкл/выкл фонарик
  Вниз - позиция ниже, удерж. - вкл/выкл подсветку
  Ок - выбор позиции, удерж. - выход в основные экраны

  - На экранах ПАРАМЕТРЫ
  Вверх - нет действия, удерж. - отладка
  Вниз - нет действия, удерж. - отладка
  Ок - нет действия, удерж. - выход из параметров

  - На экранах ЖУРНАЛ
  Вверх - позиция выше, удерж. - вкл/выкл фонарик
  Вниз - позиция ниже, удерж. - вкл/выкл подсветку
  Ок - выбор позиции(очистка журнала), удерж. - выход из журнала

  - На экране ОТЛАДКА
  Вверх - прибавить показания, удерж. - дробно/целое изменеия пункта "счет"
  Вниз - убавить показания, удерж. - дробно/целое изменеия пункта "счет"
  Ок - выбор позиции, удерж. - выход из отладки

  - На экране ОШИБКА
  Вверх - выход, удерж. - выход
  Вниз - выход, удерж. - выход
  Ок - выход, удерж. - выход


  -Ошибки-

  - Перегрузка преобразователя
  Преобразователь ВВ перегружен либо не правильно настроен, проверьте цепи преобразователя и установленные параметры DEFAULT_ADC_VALUE / DEFAULT_DIV_FACTOR / DEFAULT_PULS.

  - Короткое замыкание преобразователя
  Короткое замыкание преобразователя ВВ либо не правильно настроен, проверьте цепи преобразователя и установленные параметры DEFAULT_ADC_VALUE / DEFAULT_DIV_FACTOR / DEFAULT_PULS.

  - Низкое напряжение преобразователя
  Низкое напряжение преобразователя ВВ либо не правильно настроен, проверьте цепи преобразователя и установленные параметры DEFAULT_ADC_VALUE / DEFAULT_DIV_FACTOR / DEFAULT_PULS.

  - Нет счета
  Отсутствуют импульсы от счетчика, проверьте цепи подключения счетчика, сам счетчик или преобразователь.
*/

//----------------Библиотеки----------------
#include <util/delay.h>

//---------------Конфигурации---------------
#include "EEPROM.h"
#include "config.h"
#include "display.h"
#include "resources.c"
#include "connection.h"
#include "uartSender.h"

//-------------Для разработчиков-------------
const float ALARM_AUTO_GISTERESIS = (1.00 - (ALARM_AUTO_GIST / 100.00)); //инвертируем проценты
const float IMP_PWR_GISTERESIS = (1.00 - (IMP_PWR_GIST / 100.00)); //инвертируем проценты

const uint8_t MASS_TIME_FACT = (MASS_TIME - 1); //фактический номер элемента массивов секунд
const uint8_t MASS_BACK_FACT = (MASS_BACK - 1); //фактический номер элемента массивов фона

const uint16_t buzz_time = ((uint32_t)FREQ_BUZZ * (uint32_t)TIME_BUZZ) / 1000; //пересчитываем частоту и время щелчков в циклы таймера
const uint16_t buzz_freq = (F_CPU / SOUND_PRESCALER) / FREQ_BUZZ; //устанавливаем частоту таймера щелчков
uint16_t buzz_vol; //устанавливаем громкость щелчков

uint8_t GEIGER_CYCLE; //минимум секунд для начала расчетов
uint8_t GEIGER_MASS; //максимум секунд для окончания смещения коэффициентов

//пищалка старт/стоп
#define BUZZ_START(freq, vol)  PRR &= ~(1 << 3); ICR1 = freq; OCR1A = vol; TCNT1 = 0; TIMSK1 = 0b00000011
#define BUZZ_VOL_SET(vol)      buzz_vol = (buzz_freq / 2) / 10 * vol;
#define SOUND_START(freq)      PRR &= ~(1 << 3); ICR1 = freq; OCR1A = ((freq / 2) / 10 * mainSettings.volume); TCNT1 = 0; TIMSK1 = 0b00000011
#define SOUND_STOP             TIMSK1 = 0b00000000; PRR |= (1 << 3)

//вспышки старт/стоп
#define _RAD_FLASH_ON  {PRR &= ~(1 << 5); TIMSK0 = 0b00000001; RAD_FLASH_ON;}
#define _RAD_FLASH_OFF {TIMSK0 = 0b00000000; PRR |= (1 << 5); RAD_FLASH_OFF;}

volatile uint16_t scan_buff; //переменная для счета импульсов от датчика
uint16_t rad_buff[BUFF_LENGTHY]; //массив секундных замеров для расчета фона
uint32_t rad_mid_buff[MID_BUFF_LENGTHY]; //массив секундных замеров для усреднения фона
uint16_t search_buff[76]; //буфер поиска

uint8_t TIME_FACT; //секундные интервалы 1
#define TIME_FACT_2  2 //секундные интервалы 2
#define TIME_FACT_3  4 //секундные интервалы 3
#define TIME_FACT_4  6 //секундные интервалы 4
#define TIME_FACT_5  8 //секундные интервалы 5
#define TIME_FACT_6  10 //секундные интервалы 6
#define TIME_FACT_7  12 //секундные интервалы 7
#define TIME_FACT_8  14 //секундные интервалы 8
#define TIME_FACT_9  16 //секундные интервалы 9
#define TIME_FACT_10 18 //секундные интервалы 10
#define TIME_FACT_11 20 //секундные интервалы 11
#define TIME_FACT_12 22 //секундные интервалы 12
#define TIME_FACT_13 24 //секундные интервалы 13
#define TIME_FACT_14 26 //секундные интервалы 14
#define TIME_FACT_15 28 //секундные интервалы 15
#define TIME_FACT_16 30 //секундные интервалы 16
#define TIME_FACT_17 32 //секундные интервалы 17
#define TIME_FACT_18 34 //секундные интервалы 18
#define TIME_FACT_19 36 //секундные интервалы 19
#define TIME_FACT_20 38 //секундные интервалы 20
#define TIME_FACT_21 40 //секундные интервалы 21

//настройки основные
struct Settings_1 {
  uint8_t contrast = DEFAULT_CONTRAST; //контрастность дисплея
  uint8_t volume = DEFAULT_VOLUME; //громкость всех звуков
  uint8_t alarm_back = DEFAULT_ALARM_BACK; //переключатель режимов тревоги фона
  uint8_t buzz_switch = DEFAULT_BUZ_SWITCH; //указатель на тип треска пищалкой
  boolean knock_disable = DEFAULT_KNOCK_DISABLE; //флаг запрет треска кнопками
  uint8_t measur_pos = DEFAULT_MEASUR_POS; //указатель на время разностного замера в массиве
  uint8_t alarm_dose = DEFAULT_ALARM_DOSE; //переключатель режимов тревоги дозы
  uint8_t sleep_switch = DEFAULT_SLEEP_MODE; //переключатель режимов сна
  uint8_t time_bright = DEFAULT_TIME_BRIGHT; //время до отключения подсветки (5..250)(s)
  uint8_t time_sleep = DEFAULT_TIME_SLEEP; //время до ухода в сон(должно быть больше чем время подсветки) (10..250)(s)
  boolean rad_mode = DEFAULT_RAD_MODE; //единицы измерения дозы/фона(мкР/мкЗв)
  uint8_t rad_flash = DEFAULT_RAD_FLASH; //индикация попадания частиц
  uint8_t sigma_pos = DEFAULT_SIGMA_POS; //указатель сигмы
  uint8_t search_pos = DEFAULT_SEARCH_POS; //указатель на время время обновления графика в массиве
  uint16_t warn_level_back = DEFAULT_LEVEL_BACK_1; //уровень тревоги 1 фона
  uint16_t alarm_level_back = DEFAULT_LEVEL_BACK_2; //уровень тревоги 2 фона
  uint16_t warn_level_dose = DEFAULT_LEVEL_DOSE_1; //уровень тревоги 1 дозы
  uint16_t alarm_level_dose = DEFAULT_LEVEL_DOSE_2; //уровень тревоги 2 дозы
} mainSettings;

//настройки преобразователя
struct Settings_2 {
  uint8_t ADC_value = DEFAULT_ADC_VALUE; //значение АЦП при котором 400В
  uint16_t k_delitel = DEFAULT_DIV_FACTOR; //коефициент делителя напряжения
  uint8_t puls = DEFAULT_PULS; //длинна импульса высоковольтного транса
  float reference = DEFAULT_REFERENCE; //опорное напряжение
  float geiger_time = DEFAULT_GEIGER_TIME; //время измерения
  uint16_t wdt_period = DEF_WDT_PERIOD; //период тика wdt
} pumpSettings;

//настройки журнала
struct Settings_3 {
  uint8_t logbook_alarm = DEFAULT_LOGBOOK_ALARM; //указатель на активность журнала тревоги
  uint8_t logbook_warn = DEFAULT_LOGBOOK_WARN; //указатель на активность журнала предупреждений
  uint8_t logbook_measur = DEFAULT_LOGBOOK_MEASUR; //указатель на активность журнала замеров
} bookSettings;

uint16_t stat_upd_tmr; //таймер записи статистики в память

uint32_t rad_sum; //сумма импульсов за все время
uint32_t rad_back; //текущий фон
uint32_t rad_dose; //текущая доза
uint32_t rad_min; //минимальный фон
uint32_t rad_max; //максимальный фон

uint8_t accur_percent; //точность процентов

float rad_imp; //импульсы в секунду
float rad_imp_m; //импульсы в минуту
uint16_t scan_ind; //шкала имп/с
uint32_t rad_search; //фон в режиме поиск

uint16_t maxLevel = 22; //максимальный уровень маштабирования графика
uint16_t maxLevel_back = 15; //максимальный уровень маштабирования графика фона

boolean search_disable = 0; //флаг запрета движения графика
uint8_t cur_dose_cell = 0; //текущая ячейка хранения дозы

uint32_t time_save; //время из памяти
uint32_t rad_dose_save; //доза из памяти
uint32_t time_save_old; //предыдущее значение сохраненной времени
uint32_t rad_dose_old; //предыдущее значение дозы

//счетчики времени
uint32_t time_total = 0; //счетчик реального времени
uint32_t time_sec = 0; //секунды реального времени
uint8_t mid_time_now = 0; //текущий номер набранного массива усреднения
uint8_t back_time_now = 0; //текущий номер набранной секунды счета фона
uint8_t geiger_time_now = 0; //текущий номер набранной секунды счета
uint8_t search_time_now = 0; //текущий номер набранной секунды графика

volatile uint8_t tick_wdt; //счетчик тиков для обработки данных
uint8_t time_wdt; //счетчик тиков для отсчета секунды
uint8_t cnt_pwr; //счетчик ухода в сон
uint32_t timer_millis; //таймер отсчета миллисекунд
uint32_t timer_melody; //таймер отсчета миллисекунд для мелодий

//флаги режимов
boolean scr_mode = 0; //текущий режим(фон/доза)
boolean dose_mode = 0; //режим отображения дозы(текущая/общая)

//переменные питания
uint8_t bat = 5; //текущий заряд батареи
uint8_t bat_adc = MAX_BAT; //результат опроса акб
uint8_t hv_adc; //результат опроса АЦП преобразователя
uint16_t speed_hv; //текущая скорость накачки преобразователя
uint16_t speed_pump; //скорость накачки преобразователя

boolean low_bat_massege = 0; //флаг разрешения вывода сообщения об разряженой акб
boolean error_massege = 0; //флаг разрешения вывода сообщения об ошибке

//флаги обновления информации
boolean scr = 0; //флаг обновления экрана
boolean graf = 0; //флаг обновления графика
boolean search = 0; //флаг поиска

//технические флаги
uint8_t alarm_switch = 0; //указатель текущей тревоги

boolean alarm_back_wait = 0; //флаг ожидания выключения запрета тревоги фона
boolean warn_back_wait = 0; //флаг ожидания выключения запрета предупреждения фона
uint32_t alarm_dose_wait = 0; //флаг ожидания выключения запрета тревоги дозы
uint32_t warn_dose_wait = 0; //флаг ожидания выключения запрета предупреждения дозы

uint8_t power_manager = 2; //переключатель режимов питания мк
boolean sleep_disable = 0; //флаг запрета сна
boolean sleep = 0; //флаг активного сна
boolean light = 0; //флаг выключенной подсветки

//переменные обработки кнопок
uint8_t btn_tmr; //таймер тиков обработки
boolean btn_check; //флаг разрешения опроса кнопки
boolean btn_state; //флаг текущего состояния кнопки

//переменные режима замер бета
boolean alarm_measur = 0; //флаг запрета повторного оповещения
boolean next_measur = 0; //флаг следующего замера
uint8_t measur = 0; //текущий статус замера
uint16_t time_switch = 0; //счетчик времени замера
uint32_t first_froze = 0; //счетчик 1-го замера
uint32_t second_froze = 0; //счетчик 2-го замера

//технические переменные
volatile uint16_t cnt_puls; //количество циклов для работы пищалки
uint8_t melody_switch; //переключатель мелодии
uint8_t vibro_switch; //переключатель вибрации

uint8_t temp_buzz_switch; //временный буфер состояния щелчков
uint8_t error_switch = 0; //указатель на активность ошибки
boolean light_switch = 1; //переключатель вкл/выкл подсветки дисплея

float now = 0.00; //текущее соотношение ячеек сравнения
#if COEF_DEBUG //отладка коэффициента
float debug_coef = 0.00; //для  вывода общего коэффициента в дебаг
#endif

#define EEPROM_BLOCK_SETTINGS_MAIN (EEPROM_BLOCK_NULL)
#define EEPROM_BLOCK_SETTINGS_BOOK (EEPROM_BLOCK_SETTINGS_MAIN + sizeof(mainSettings))
#define EEPROM_BLOCK_SETTINGS_PUMP (EEPROM_BLOCK_SETTINGS_BOOK + sizeof(bookSettings))
#define EEPROM_BLOCK_CRC_MAIN (EEPROM_BLOCK_SETTINGS_PUMP + sizeof(pumpSettings)) //ячейка контрольной суммы основных настроек
#define EEPROM_BLOCK_CRC_BOOK (EEPROM_BLOCK_CRC_MAIN + 1) //ячейка контрольной суммы настроек журнала
#define EEPROM_BLOCK_CRC_PUMP (EEPROM_BLOCK_CRC_BOOK + 1) //ячейка контрольной суммы настроек преобразователя
#define EEPROM_BLOCK_CRC_STRUCT (EEPROM_BLOCK_CRC_PUMP + 1) //ячейка контрольной суммы структур данных

void _init_rads_unit(boolean type, uint32_t num, uint8_t divisor, uint8_t char_all, uint8_t num_x, uint8_t num_y, boolean unit, uint8_t unit_x, uint8_t unit_y, boolean dash = 0);
//--------------------------------------Инициализация---------------------------------------------------
int main(void)  //инициализация
{
  CONV_INIT; //инициализация преобразователя
  BUZZ_INIT; //инициализация бузера
  DET_1_INIT; //инициализация детектора частиц
  LIGHT_INIT; //инициализация подсветки
  PWR_LCD_INIT; //инициализация питания дисплея
  RAD_FLASH_INIT; //инициализация фонарика
  FLASH_INIT; //инициализация индикатора частиц
  VIBRO_INIT; //инициализация вибромотора

  LCD_INIT; //инициализация пинов дисплея
  PWR_LCD_ON; //включаем питание дисплея
  LCD_ON; //разрешаем работу с диплеем

  OK_INIT; //инициализация кнопки "ок"
  DOWN_INIT; //инициализация кнопки "вниз"
  UP_INIT; //инициализация кнопки "вверх"

  _delay_ms(START_TIME); //ждем
  _init_timers(); //инициализация таймеров;

  PRR = 0b11101110; //отключаем все лишнее (I2C | TIMER2 | TIMER0 | TIMER1 | SPI | UART)
  ACSR |= 0b10000000; //отключаем компаратор

  initLcd(); //инициализируем дисплей
  _LIGHT_ON(); //включаем подсветку
  _wdt_enable(); //запускаем WatchDog

  _read_memory(); //проверка и чтение данных из памяти
  _rows_clear(); //очистка строк

  _adc_enable(); //включение ADC
  _bat_check(); //опрос батареи
  _start_pump(); //первая накачка преобразователя
  _init_param(); //инициализация параметров

  _rows_clear(); //очистка строк
  print(INTRO, CENTER, 32); //-=РАДОН=-
  print(VERSION, CENTER, 40); //версия по
  showScr(); //вывод буфера на экран

  EICRA = 0b00001010; //настраиваем внешнее прерывание по спаду импульса на INT0 и INT1
  EIMSK = 0b00000001; //разрешаем внешнее прерывание INT0

  _waint(FONT_TIME); //ждем

  clrScr(); //очистка экрана

  //----------------------------------Главная-------------------------------------------------------------
  for (;;) //главная
  {
    data_convert(); //преобразование данных
    error_messege(); //обработка сообщений ошибок
    alarm_warning(); //обработка сообщений тревоги
    main_screen(); //основные режимы
  }
  return 0; //конец
}
//------------------------Инициализация таймеров--------------------------------------------------
void _init_timers(void) //инициализация таймеров
{
  TCCR0A = 0b00000000; //отключаем OC0A/OC0B
  TCCR0B = 0b00000011; //пределитель 64
  TIMSK0 = 0b00000000; //отключаем прерывания Таймера0

  TCCR1A = 0b00000010; //отключаем OC1A/OC1B
  TCCR1B = 0b00011011; //пределитель 64 | ICR режим
  TIMSK1 = 0b00000000; //отключаем прерывания Таймера1

  TCCR2A = 0b00000000; //отключаем OC2A/OC2B
  TCCR2B = 0b00000101; //пределитель 256
  TIMSK2 = 0b00000000; //отключаем прерывания Таймера2

  sei(); //разрешаем прерывания глобально
}
//------------------------Инициализация таймеров--------------------------------------------------
void _waint(uint32_t timer) //инициализация таймеров
{
  for (timer_millis = timer; timer_millis && !check_keys();) data_convert(); // ждем, преобразование данных
}
//------------------------Очистка строк загрузки--------------------------------------------------
void _rows_clear(void) //очистка строк загрузки
{
  clrRow(4); //очистка строки 4
  clrRow(5); //очистка строки 5
}
//-------------------Проверка и чтение данных из памяти-------------------------------------------
void _read_memory(void) //проверка и чтение данных из памяти
{
  uint8_t dataReg = 0; //регистр очистки данных
  uint8_t crc = 0; //контрольная сумма

  for (uint8_t n = 0; n < sizeof(mainSettings); n++) checkCRC(&crc, *((uint8_t*)(&mainSettings) + n)); //рассчитываем контрольную сумму для основных настроек
  for (uint8_t n = 0; n < sizeof(bookSettings); n++) checkCRC(&crc, *((uint8_t*)(&bookSettings) + n)); //рассчитываем контрольную сумму для настроек журнала
  for (uint8_t n = 0; n < sizeof(pumpSettings); n++) checkCRC(&crc, *((uint8_t*)(&pumpSettings) + n)); //рассчитываем контрольную сумму для настроек преобразователя

  if (!OK_OUT || crc != EEPROM_ReadByte(EEPROM_BLOCK_CRC_STRUCT)) { //если зажата кнопка "ОК" или данные структур изменились
    print(RES_RESET, CENTER, 0); //Сбросить
    print(RES_MAIN, CENTER, 8); //основные
    print(RES_SETTINGS_M, CENTER, 16); //настройки?
    if (dialogSwitch()) dataReg |= 0x03; //если ответ да то устанавливаем флаг сброса
    clrScr(); //очистка экрана
#if DEBUG_RETURN
    print(RES_RESET, CENTER, 0); //Сбросить
    print(RES_SETTINGS_P, CENTER, 8); //настройки
    print(RES_PUMP, CENTER, 16); //конвертера?
    if (dialogSwitch()) dataReg |= 0x04; //если ответ да то устанавливаем флаг сброса
    clrScr(); //очистка экрана
#endif
    print(RES_RESET, CENTER, 0); //Сбросить
    print(RES_DATA, CENTER, 8); //данные
    print(RES_USER, CENTER, 16); //пользователя?
    if (dialogSwitch()) dataReg |= 0x18; //если ответ да то устанавливаем флаг сброса

    EEPROM_UpdateByte(EEPROM_BLOCK_CRC_STRUCT, crc); //обновляем значение контрольной суммы структур
  }
  else { //иначе проверяем целостность данных
    if (checkData(sizeof(mainSettings), EEPROM_BLOCK_SETTINGS_MAIN, EEPROM_BLOCK_CRC_MAIN)) dataReg |= 0x01; //проверяем контрольную сумму основных настроек
#if LOGBOOK_RETURN
    if (checkData(sizeof(bookSettings), EEPROM_BLOCK_SETTINGS_BOOK, EEPROM_BLOCK_CRC_BOOK)) dataReg |= 0x02; //проверяем контрольную сумму настроек журнала
#endif
#if DEBUG_RETURN
    if (checkData(sizeof(pumpSettings), EEPROM_BLOCK_SETTINGS_PUMP, EEPROM_BLOCK_CRC_PUMP)) dataReg |= 0x04; //проверяем контрольную сумму настроек преобразователя
#endif

    if (dataReg) { //если какие-то данные были повреждены
      print(SETTINGS, CENTER, 0); //Настройки
      print(DAMAGED, CENTER, 8); //повреждены,
      print(RESTORE, CENTER, 16); //восстановить?
      if (!dialogSwitch()) dataReg = 0; //если ответ нет то сбрасываем флаги
    }
  }

  clrScr(); //очистка экрана
  _init_logo(); //вывод логотипа

  print(READ, CENTER, 32); //чтение...
  for (uint8_t i = 0; i < 5; i++) {
    if (dataReg & (0x01 << i)) { //если установлен флаг очистки
      switch (i) {
        case 0: updateData((uint8_t*)&mainSettings, sizeof(mainSettings), EEPROM_BLOCK_SETTINGS_MAIN, EEPROM_BLOCK_CRC_MAIN); break; //сбрасываем основные настройки
#if LOGBOOK_RETURN
        case 1: updateData((uint8_t*)&bookSettings, sizeof(bookSettings), EEPROM_BLOCK_SETTINGS_BOOK, EEPROM_BLOCK_CRC_BOOK); break; //сбрасываем настройки журнала
#endif
#if DEBUG_RETURN
        case 2: updateData((uint8_t*)&pumpSettings, sizeof(pumpSettings), EEPROM_BLOCK_SETTINGS_PUMP, EEPROM_BLOCK_CRC_PUMP); break; //сбрасываем настройки преобразователя
#endif
        case 3: _statistic_erase(); break; //стирание статистики
        case 4: _logbook_data_clear(); break; //очистка журнала
      }
    }
    else {
      switch (i) { //иначе загружаем данные
        case 0: EEPROM_ReadBlock((uint16_t)&mainSettings, EEPROM_BLOCK_SETTINGS_MAIN, sizeof(mainSettings)); break; //загружаем основные настройки
#if LOGBOOK_RETURN
        case 1: EEPROM_ReadBlock((uint16_t)&bookSettings, EEPROM_BLOCK_SETTINGS_BOOK, sizeof(bookSettings)); break; //загружаем настройки журнала
#endif
#if DEBUG_RETURN || PUMP_READ_MEM
        case 2: EEPROM_ReadBlock((uint16_t)&pumpSettings, EEPROM_BLOCK_SETTINGS_PUMP, sizeof(pumpSettings)); break; //загружаем настройки преобразователя
#endif
        case 3: statistic_read(); break; //считываем статистику
      }
    }
    _screen_line(0, map(i, 0, 4, 0, 64), 0, 10, 40); //прогресс бар загрузки данных
    showScr(); //вывод буфера на экран
    _delay_ms(LOAD_TIME); //ждем
  }
}
//------------------------Сравнение данных в памяти--------------------------------------------------
boolean checkDataMemory(uint8_t* str, uint8_t size, uint8_t cellCRC) //сравнение данных в памяти
{
  uint8_t crc = 0;
  for (uint8_t n = 0; n < size; n++) checkCRC(&crc, str[n]);
  if (crc != EEPROM_ReadByte(cellCRC)) return 1;
  return 0;
}
//------------------------Проверка данных в памяти--------------------------------------------------
boolean checkData(uint8_t size, uint8_t cell, uint8_t cellCRC) //проверка данных в памяти
{
  uint8_t crc = 0;
  for (uint8_t n = 0; n < size; n++) checkCRC(&crc, EEPROM_ReadByte(cell + n));
  if (crc != EEPROM_ReadByte(cellCRC)) return 1;
  return 0;
}
//------------------------Обновление данных в памяти--------------------------------------------------
void updateData(uint8_t* str, uint8_t size, uint8_t cell, uint8_t cellCRC) //обновление данных в памяти
{
  uint8_t crc = 0;
  for (uint8_t n = 0; n < size; n++) checkCRC(&crc, str[n]);
  EEPROM_UpdateBlock((uint16_t)str, cell, size);
  EEPROM_UpdateByte(cellCRC, crc);
}
//------------------------Сверка контрольной суммы--------------------------------------------------
void checkCRC(uint8_t* crc, uint8_t data) //сверка контрольной суммы
{
  for (uint8_t i = 0; i < 8; i++) { //считаем для всех бит
    *crc = ((*crc ^ data) & 0x01) ? (*crc >> 0x01) ^ 0x8C : (*crc >> 0x01); //рассчитываем значение
    data >>= 0x01; //сдвигаем буфер
  }
}
//--------------------------------Диалог выбора-----------------------------------------------------
boolean dialogSwitch(void) //диалог выбора
{
  boolean updScreen = 0;
  boolean state = 0;
  while (1) {
    for (; tick_wdt > 0; tick_wdt--) { //если был тик, обрабатываем данные

      switch (btn_state) { //таймер опроса кнопок
        case 0: if (btn_check) btn_tmr++; break; //считаем циклы
        case 1: if (btn_tmr > 0) btn_tmr--; break; //убираем дребезг
      }

      if (!updScreen) {
        updScreen = 1;
        choice_menu(state); //меню выбора
        showScr(); //вывод буфера на экран
      }

      switch (check_keys()) {
        case 2: //Down key //сброс
          state = 0;
          updScreen = 0; //разрешаем обновления экрана
          break;

        case 3: //Up key //доп.действие
          state = 1;
          updScreen = 0; //разрешаем обновления экрана
          break;

        case 5: return state; //Select key //выбор режима
      }
    }
  }
  return 0;
}
//------------------------Инициализация параметров--------------------------------------------------
void _init_param(void) //инициализация параметров
{
  tick_wdt = 0; //сбрасываем тики собаки
  TIME_FACT = 100000 / pumpSettings.wdt_period; //расчитываем период для секунд
  BUZZ_VOL_SET(mainSettings.volume); //устанавливаем громкость щелчков

  GEIGER_CYCLE = (pgm_read_byte(&time_mass[0][0]) + pgm_read_byte(&time_mass[0][1])); //минимум секунд для начала расчетов
  GEIGER_MASS = (pgm_read_byte(&time_mass[MASS_TIME_FACT][0]) + pgm_read_byte(&time_mass[MASS_TIME_FACT][1])); //максимум секунд для окончания смещения коэффициентов
}
//------------------------Подсветка старт/стоп--------------------------------------------------
void _LIGHT_ON(void) { //подсветка старт
  PRR &= ~(1 << 6); //включаем питание таймера
  TIMSK2 = 0b00000011; //разрешаем прерывания
  light_switch = 1; //устанасвливаем флаг разгорания подсветки
}
void _LIGHT_OFF(void) { //подсветка стоп
  PRR &= ~(1 << 6); //включаем питание таймера
  TIMSK2 = 0b00000011; //разрешаем прерывания
  light_switch = 0; //устанасвливаем флаг затухания подсветки
}
void _LIGHT_STOP(void) { //подсветка стоп
  TCNT2 = TIMSK2 = 0b00000000; //сбрасываем счетный регистр и отключаем прерывания
  PRR |= (1 << 6); //выключаем питание таймера
}
//-------------------------------Включение WDT----------------------------------------------------
void _wdt_enable(void) //включение WDT
{
  cli(); //запрещаем глобальные прерывания
  WDTCSR = ((0x01 << WDCE) | (0x01 << WDE)); //сбрасываем собаку
  WDTCSR = 0x40; //устанавливаем пределитель 2(режим прерываний)
  sei(); //восстанавливаем глобальные прерывания
}
//-------------------------------Выключение WDT---------------------------------------------------
void _wdt_disable(void) //выключение WDT
{
  cli(); //запрещаем глобальные прерывания
  WDTCSR = ((0x01 << WDCE) | (0x01 << WDE)); //сбрасываем собаку
  WDTCSR = 0x00; //выключаем собаку
  sei(); //восстанавливаем глобальные прерывания
}
//-------------------------------Включение ADC----------------------------------------------------
void _adc_enable(void) //включение ADC
{
  PRR &= ~ (1 << 0); //включаем питание АЦП
  ADCSRA = 0b10000111; //настройка АЦП
}
//-------------------------------Выключение ADC---------------------------------------------------
void _adc_disable(void) //выключение ADC
{
  ADCSRA = 0b00000111; //настройка АЦП
  PRR |= (1 << 0); //выключаем питание ацп
}
//-------------------------------Вывод логотипа---------------------------------------------------
void _init_logo(void) //вывод логотипа
{
  drawBitmap(0, 0, logo_img, 84, 24); //выводим лого
}
//-------------------------------Детектирование частиц------------------------------------------------
ISR(INT0_vect) //внешнее прерывание на пине INT0 - считаем импульсы от счетчика 1
{
  if (scan_buff != 65535) scan_buff++; //нулевой элемент массива - текущий секундный замер

  switch (mainSettings.rad_flash) {
    case 1: _RAD_FLASH_ON break; //индикация попадания частиц
    case 2: if (!sleep) _RAD_FLASH_ON break; //индикация попадания частиц
  }
  switch (mainSettings.buzz_switch) {
    case 1: buzz_click(); break; //щелчок пищалкой
    case 2: if (rad_back >= mainSettings.warn_level_back) buzz_click(); break; //щелчок пищалкой
  }
}
//-------------------------Прерывание по переполнению wdt - 17.5мс------------------------------------
ISR(WDT_vect) //прерывание по переполнению wdt - 17.5мс
{
  tick_wdt++; //прибавляем тик
}
//----------------------------------Преобразование данных---------------------------------------------------------
void data_convert(void) //преобразование данных
{
  static uint8_t time_1; //секундные замеры первого плеча
  static uint8_t time_2; //секундные замеры второго плеча
  static uint8_t mass_switch; //переключатель массива
  static uint8_t tmr_nop_imp; //таймер отсутствия импульсов
  static uint8_t tmr_upd_bat; //таймер обновления состояния акб
  static uint8_t tmr_low_bat; //таймер вывода сообщения об разряженой акб
  static uint8_t tmr_upd_err; //таймер вывода сообщения об ошибке
  static uint32_t temp; //буффер второго плеча
  static uint32_t temp_run; //буффер первого плеча
  static uint32_t tmp_buff; //общий буфер
  static float coef; //коэффициент сравнения
  static float coef_back; //коэффициент поправки на фон

  low_pwr(); //отключение дисплея и подсветки, уход в сон для экономии энергии
  pump(); //накачка по обратной связи с АЦП
  bat_massege(); //обработка сообщения разряженой батареи

  for (; tick_wdt > 0; tick_wdt--) { //если был тик, обрабатываем данные

    if (++time_wdt >= TIME_FACT) time_wdt = 0; //расчет времени один раз в секунду

    switch (btn_state) { //таймер опроса кнопок
      case 0: if (btn_check) btn_tmr++; break; //считаем циклы
      case 1: if (btn_tmr > 0) btn_tmr--; break; //убираем дребезг
    }

    if (search) search_update(); //обновляем график

    if (timer_millis > 17) timer_millis -= 17; //если таймер больше 17мс
    else if (timer_millis) timer_millis = 0; //иначе сбрасываем таймер

    if (timer_melody > 17) timer_melody -= 17; //если таймер больше 17мс
    else if (timer_melody) timer_melody = 0; //иначе сбрасываем таймер

    if (!measur && !search) {
      time_total++; //микросекунды * 10

      switch (time_wdt) {
        case TIME_FACT_2: //обновление статистики
          if (++stat_upd_tmr >= STAT_UPD_TIME) { //если пришло время, обновляем статистику
            stat_upd_tmr = 0; //сбрасываем таймер

            time_save += time_sec - time_save_old; //добавляем время
            time_save_old = time_sec; //сбрасывае счетчик времени
            rad_dose_save += rad_dose - rad_dose_old; //добавляем дозу
            rad_dose_old = rad_dose; //сбрасывае счетчик дозы

            statistic_update(); //обновление статистики
          }
          break;

        case TIME_FACT_3: //расчет текущего фона этап-1
          rad_buff[0] = scan_buff; //смещаем 0-й элемент в 1-й для дальнейшей работы с ним
          scan_buff = 0; //сбрасываем счетчик импульсов
          tmp_buff = 0; //сбрасываем временный буфер

          if (geiger_time_now < BUFF_LENGTHY) geiger_time_now++; //прибавляем указатель заполненности буффера
          if (back_time_now < BUFF_LENGTHY) back_time_now++; //прибавляем указатель заполненности буффера для рассчета фона
          else {
            back_time_now = 1; //иначе сбрасываем в начало
            if (mid_time_now < MID_BUFF_LENGTHY) mid_time_now++; //прибавляем указатель заполненности буффера
          }

#if GEIGER_DEAD_TIME
          if (rad_buff[0] >= COUNT_RATE) rad_buff[0] = rad_buff[0] / (1 - rad_buff[0] * DEAD_TIME); //если скорость счета больше 100имп/с, учитываем мертвое время счетчика
#endif

          for (uint8_t i = 0; i < back_time_now; i++) tmp_buff += rad_buff[i]; //суммирование всех импульсов для расчета фона
          break;

        case TIME_FACT_4: //расчет текущего фона этап-2
          if (back_time_now >= BUFF_LENGTHY) { //если основной буфер перезаписался
            for (uint8_t k = MID_BUFF_LENGTHY - 1; k > 0; k--) rad_mid_buff[k] = rad_mid_buff[k - 1]; //перезапись массива
            rad_mid_buff[0] = tmp_buff; //записываем основной массив в массив усреднения
          }
          for (uint8_t i = 0; i < mid_time_now; i++) tmp_buff += rad_mid_buff[i]; //суммирование всех импульсов для расчета фона
          break;

        case TIME_FACT_5: //расчет текущего фона этап-3
          if (geiger_time_now >= GEIGER_CYCLE) { //если массив заполнен на минимум начала работы коэффициентов
            if (geiger_time_now <= GEIGER_MASS) { //если не достигли предела массива сравнения
              if (geiger_time_now >= (pgm_read_byte(&time_mass[mass_switch + 1][0]) + pgm_read_byte(&time_mass[mass_switch + 1][1]))) mass_switch++; //пересчитываем текущий номер элемента массива в зависимости от заполненности массива счета
            }

            time_1 = pgm_read_byte(&time_mass[mass_switch][0]); //получаем количество секундных замеров для первого плеча
            time_2 = pgm_read_byte(&time_mass[mass_switch][1]); //получаем количество секундных замеров для второго плеча

            coef_back = 1.00; //устанавливаем первичный коэффициент
            for (uint8_t i = 0; i < MASS_BACK; i++) {
              if (rad_back <= pgm_read_word(&back_mass[i])) {
                coef_back = pgm_read_float(&coef_back_mass[i]); //пересчитывем фон для коррекции по заданным коэффициентам в массиве
                break;
              }
            }
          }
          break;

        case TIME_FACT_6: //расчет текущего фона этап-4
          if (geiger_time_now >= GEIGER_CYCLE) { //если массив заполнен на минимум начала работы коэффициентов

            coef = pgm_read_float(&coef_time_mass[mass_switch]) * coef_back; //получаем коэффициент из массива для сравнения на скачок/спад

#if COEF_DEBUG //отладка коэффициента
            debug_coef = coef;
#endif

            temp_run = 0; //сбрасываем буффер первого плеча
            temp = 0; //сбрасываем буффер второго плеча
            for (uint8_t i = 0; i < time_1; i++) temp_run += rad_buff[i]; //запоняем буффер первого плеча
            for (uint8_t i = time_1; i < (time_1 + time_2); i++) temp += rad_buff[i]; //запоняем буффер вторго плеча
          }
          break;

        case TIME_FACT_7: //расчет текущего фона этап-5
          if (geiger_time_now >= GEIGER_CYCLE) { //если массив заполнен на минимум начала работы коэффициентов

            if (temp_run && temp) {
              now = ((float)temp_run / time_1) / ((float)temp / time_2); //получаем текущее соотношение первого плеча ко второму

              if (now > coef || now < (1.00 / coef)) { //если видим скачок или спад
                tmp_buff = 0; //сбрасываем текущий буфер
                for (uint8_t i = 0; i < pgm_read_byte(&time_mass[0][0]); i++) tmp_buff += rad_buff[i]; //запоняем буффер первого плеча
                back_time_now = geiger_time_now = pgm_read_byte(&time_mass[0][0]); //устанавливаем текущий размер буфера
                mid_time_now = 0; //сбрасываем рассчет среднего
                mass_switch = 0; //сбрасываем позицию переключения
              }
            }
          }
          break;

        case TIME_FACT_8: { //расчет текущего фона этап-6
            if (tmp_buff > 9999999) tmp_buff = 9999999; //переполнение буфера импульсов
#if APPROX_BACK_SCORE
            float imp_per_sec = 0; //текущее количество имп/с
            if (geiger_time_now > 1) imp_per_sec = (float)tmp_buff / ((uint16_t)mid_time_now * BUFF_LENGTHY + back_time_now); //расчет имп/с
#if GEIGER_OWN_BACK
            if (imp_per_sec > OWN_BACK) imp_per_sec -= OWN_BACK; //убираем собственный фон счетчика
            else imp_per_sec = tmp_buff = 0; //иначе ничего кроме собственного фона нету
#endif
            for (uint8_t i = 0; i < PATTERNS_APROX; i++) { //выбор паттерна
              if (imp_per_sec <= pgm_read_word(&back_aprox[i][0])) { //если имп/с совпадают с паттерном
                rad_back = imp_per_sec * (pumpSettings.geiger_time + pgm_read_word(&back_aprox[i][1])) - pgm_read_word(&back_aprox[i][2]) * 10.0; //рассчитываем фон в мкр/ч
                break;
              }
            }
#else
#if GEIGER_OWN_BACK
            float own_back_now = ((uint16_t)mid_time_now * BUFF_LENGTHY + back_time_now) * OWN_BACK; //рассчитываем количество импульсов собственного фона
            if (tmp_buff > own_back_now) tmp_buff -= own_back_now; //убираем собственный фон счетчика
            else tmp_buff = 0; //иначе ничего кроме собственного фона нету
#endif
            if (pumpSettings.geiger_time_now > 1) rad_back = tmp_buff * (pumpSettings.geiger_time / ((uint16_t)mid_time_now * BUFF_LENGTHY + back_time_now)); //расчет фона мкР/ч
#endif
            for (uint8_t k = BUFF_LENGTHY - 1; k > 0; k--) rad_buff[k] = rad_buff[k - 1]; //перезапись массива
          }
          break;

        case TIME_FACT_9: //рассчитываем точность
          accur_percent = _init_accur(tmp_buff); //рассчет точности
          break;

        case TIME_FACT_10: //минимальный и максимальный фон
          if (accur_percent <= RAD_ACCUR_START) { //если достаточно данных в массиве
            if (rad_back < rad_min) rad_min = rad_back; //фиксируем минимум фона
            if (rad_back > rad_max) rad_max = rad_back; //фиксируем максимум фона
          }
          else rad_min = rad_back; //фиксируем минимум фона
          break;

        case TIME_FACT_11: //расчет текущей дозы
          if ((rad_sum += rad_buff[0]) > 99999999) rad_sum = 99999999; //переполнение суммы импульсов
#if GEIGER_OWN_BACK
          rad_dose = ((rad_sum - time_sec * OWN_BACK) * pumpSettings.geiger_time / 3600); //расчитаем дозу с учетом собственного фона счетчика
#else
          rad_dose = (rad_sum * pumpSettings.geiger_time / 3600); //расчитаем дозу
#endif
          break;

        case TIME_FACT_12: { //расчет данных для графика
            uint16_t graf_max = 0; //максимальное значение графика
            for (uint8_t i = 0; i > 38; i--) if (rad_buff[i] > graf_max) graf_max = rad_buff[i]; //ищем максимум

            if (graf_max > 15) maxLevel_back = graf_max * GRAF_COEF_MAX; //если текущий замер больше максимума
            else maxLevel_back = 15; //иначе устанавливаем минимум
          }
          break;

        case TIME_FACT_13: //обработка тревоги
          if (mainSettings.alarm_dose && (rad_dose - alarm_dose_wait) >= mainSettings.alarm_level_dose) { //если тревога не запрещена и текущая(предыдущая) доза больше порога
#if LOGBOOK_RETURN
            if (!alarm_switch && bookSettings.logbook_warn) _logbook_data_update(0, 2, rad_dose); //обновление журнала
#endif
            alarm_switch = 2;  //превышение дозы 2
            break;
          }
          else if (mainSettings.alarm_dose && (rad_dose - warn_dose_wait) >= mainSettings.warn_level_dose) { //если предупреждения не запрещены и текущая(предыдущая) доза больше порога
            if (!alarm_switch) { //если это первая сработка тревоги
              melody_switch = 0; vibro_switch = 0; //сбрасываем переключатель мелодии и вибрации
#if LOGBOOK_RETURN
              if (bookSettings.logbook_alarm) _logbook_data_update(1, 2, rad_dose); //обновление журнала
#endif
            }
            alarm_switch = 4;  //превышение дозы 1
            break;
          }

          if (accur_percent <= RAD_ACCUR_WARN) {
            if (mainSettings.alarm_back && !alarm_back_wait && rad_back >= mainSettings.alarm_level_back) { //если тревога не запрещена и текущий фон больше порога
#if LOGBOOK_RETURN
              if (!alarm_switch && bookSettings.logbook_warn) _logbook_data_update(0, 1, rad_back); //обновление журнала
#endif
              alarm_switch = 1;  //превышение фона 2
              break;
            }
            else if (mainSettings.alarm_back && !warn_back_wait && rad_back >= mainSettings.warn_level_back) { //если предупреждения не запрещены и текущий фон больше порога
              if (!alarm_switch) { //если это первая сработка тревоги
                melody_switch = 0; vibro_switch = 0; //сбрасываем переключатель мелодии и вибрации
#if LOGBOOK_RETURN
                if (bookSettings.logbook_alarm) _logbook_data_update(1, 1, rad_back); //обновление журнала
#endif
              }
              alarm_switch = 3;  //превышение фона 1
              break;
            }
          }

          if (warn_back_wait && rad_back < (mainSettings.warn_level_back * ALARM_AUTO_GISTERESIS)) { //если текущий фон упал ниже порога + гистерезис
            warn_back_wait = 0; //сброс предупреждения
#if LOGBOOK_RETURN
            if (bookSettings.logbook_warn) bookSettings.logbook_warn = 2; //устанавливаем флаг пропущенного предупреждения
#endif
          }
          if (alarm_back_wait && rad_back < (mainSettings.alarm_level_back * ALARM_AUTO_GISTERESIS)) { //если текущий фон упал ниже порога + гистерезис
            alarm_back_wait = 0; //сброс тревоги
#if LOGBOOK_RETURN
            if (bookSettings.logbook_alarm) bookSettings.logbook_alarm = 2; //устанавливаем флаг пропущенной тревоги
#endif
          }

#if ALARM_AUTO_DISABLE
          switch (alarm_switch) {
            case 1:
            case 3:
              if (alarm_switch == 1 && rad_back < (mainSettings.alarm_level_back * ALARM_AUTO_GISTERESIS)) alarm_switch = 0;  //иначе ждем понижения фона тревоги 2
              if (rad_back < (mainSettings.warn_level_back * ALARM_AUTO_GISTERESIS)) { //иначе ждем понижения фона тревоги 1
                _vibro_off(); //выключаем вибрацию
                buzz_ret(); //чтение состояния щелчков
                melody_switch = 0; //сбрасываем переключатель мелодии
                vibro_switch = 0; //сбрасываем переключатель вибрации
                alarm_switch = 0; //устанавливаем признак отсутствия тревоги
              }
              break;
          }
#endif
          break;

        case TIME_FACT_14: //считаем пройденное время
          time_sec = (time_total * (pumpSettings.wdt_period / 100.00)) / 1000; //пересчитываем в секунды
          break;

#if USE_UART
        case TIME_FACT_21: //отправляем данные в порт
#if UART_SEND_BACK
          sendNumI(rad_back);
#endif
#if UART_SEND_DOSE
          sendNumI(rad_dose);
#endif
#if UART_SEND_IMP
          sendNumI(rad_buff[0]);
#endif
          break;
#endif
      }
    }

    switch (time_wdt) {
      case TIME_FACT_15: //обработка ошибок
        if (speed_pump >= HV_SPEED_ERROR) { //если текущая скорость накачки выше порога
#if LOGBOOK_RETURN
          if (error_switch < 2) _logbook_data_update(3, 2, speed_pump); //обновление журнала устанавливаем ошибку 2 - перегрузка преобразователя
          error_switch = 2; //поднимаем флаг ошибки
#else
          error_switch = 2; //поднимаем флаг ошибки
#endif
        }
        speed_hv = speed_pump; //текущая скорость накачки
        speed_pump = 0; //сбрасываем скорость накачки

        if (hv_adc < pumpSettings.ADC_value - HV_ADC_MIN) { //если значение АЦП преобразователя ниже на установленное значение
#if LOGBOOK_RETURN
          if (error_switch < 2) _logbook_data_update(3, 4, hv_adc); //обновление журнала устанавливаем ошибку 4 - низкое напряжение
          error_switch = 2; //поднимаем флаг ошибки
#else
          error_switch = 4; //поднимаем флаг ошибки
#endif
        }
        if (hv_adc < HV_ADC_ERROR) { //если значение АЦП преобразователя ниже порога
#if LOGBOOK_RETURN
          if (error_switch < 2) _logbook_data_update(3, 3, hv_adc); //обновление журнала устанавливаем ошибку 3 - кз преобразователя
          error_switch = 2; //поднимаем флаг ошибки
#else
          error_switch = 3; //поднимаем флаг ошибки
#endif
        }

        if (!rad_buff[0]) { //если нету импульсов в обменном буфере
          if (++tmr_nop_imp >= IMP_ERROR_TIME) { //считаем время до вывода предупреждения
#if LOGBOOK_RETURN
            if (error_switch < 2) _logbook_data_update(3, 5, 5); //обновление журнала устанавливаем ошибку 5 - нет импульсов
            error_switch = 2; //поднимаем флаг ошибки
#else
            error_switch = 5; //поднимаем флаг ошибки
#endif
            tmr_nop_imp = 0; //сбрасываем таймер
          }
        }
        else tmr_nop_imp = 0; //иначе импульсы возобновились

        if (tmr_upd_err >= ERROR_LENGTHY_TIME) {
          if (error_massege) {
            tmr_upd_err = 0; //сброс таймера
            error_massege = 0; //устанавливаем флаг для обновления сообщения об ошибке
          }
        }
        else tmr_upd_err++;
        break;

      case TIME_FACT_16: //разностный замер
        switch (measur) { //выбираем режим замера
          case 1: if (time_switch < (pgm_read_byte(&diff_measuring[mainSettings.measur_pos]) * 60)) time_switch ++; //прибавляем секунду
            else next_measur = 1; //иначе время вышло
            if (!next_measur) first_froze += scan_buff; //если идет замер, заполняем буфер первого замера
            rad_buff[0] = scan_buff; //смещаем 0-й элемент в 1-й для дальнейшей работы с ним
            scan_buff = 0; //сбрасывает счетчик частиц
            break;
          case 2: if (time_switch < (pgm_read_byte(&diff_measuring[mainSettings.measur_pos]) * 60)) time_switch ++; //прибавляем секунду
            else next_measur = 1; //иначе время вышло
            if (!next_measur) second_froze += scan_buff; //если идет замер, заполняем буфер второго замера
            rad_buff[0] = scan_buff; //смещаем 0-й элемент в 1-й для дальнейшей работы с ним
            scan_buff = 0; //сбрасывает счетчик частиц
            break;
        }
        break;

      case TIME_FACT_17: //считаем время до ухода в сон
        switch (mainSettings.sleep_switch) { //выбераем счет времени
          case 1: if (cnt_pwr <= mainSettings.time_bright) cnt_pwr++; break; //счет выключения подсветки
          case 2: if (cnt_pwr <= mainSettings.time_sleep) cnt_pwr++; break; //счет ухода в сон
        }
        break;

      case TIME_FACT_18: //управление энергосбережением
        switch (power_manager) {
          case 0: if (rad_buff[0] <= (IMP_PWR_MANAGER * IMP_PWR_GISTERESIS)) power_manager = 1; break; //если текущее количество импульсов меньше установленного порога включения энергосбережения
          case 1:
            if (rad_buff[0] > IMP_PWR_MANAGER) power_manager = 0; //если текущее количество импульсов больше установленного порога отключения энергосбережения
            else if (rad_buff[0] <= (IMP_PWR_DOWN * IMP_PWR_GISTERESIS)) power_manager = 2; //если текущее количество импульсов меньше установленного порога включения глубокого энергосбережения
            break;
          case 2: if (rad_buff[0] > IMP_PWR_DOWN) power_manager = 1; break; //если текущее количество импульсов больше установленного порога отключения глубокого энергосбережения
        }
        break;

      case TIME_FACT_19: //таймер обновления батареи
        if (tmr_upd_bat >= UPD_BAT_TIME) {
          tmr_upd_bat = 0; //сброс таймера
          _bat_check(); //опрос батареи
        }
        else tmr_upd_bat++;
        if (tmr_low_bat >= LOW_BAT_TIME) {
          if (low_bat_massege) {
            tmr_low_bat = 0; //сброс таймера
            low_bat_massege = 0; //устанавливаем флаг для обновления сообщения об разряженной акб
          }
        }
        else tmr_low_bat++;
        break;

      case TIME_FACT_20: //таймер обновления экрана
        if (!sleep) scr = 0; //устанавливаем флаг для обновления экрана
        if (search) rad_buff[0] = 0; //очищаем буфер
        break;
    }
  }
}
//-------------------------Расчет точности замера----------------------------------------------------
uint8_t _init_accur(uint32_t num) //расчет точности замера
{
  return (num) ? constrain(((mainSettings.sigma_pos + 1) / sqrtf((float)num)) * 100, 1, 99) : 99; //находим статистическую точность
}
//-------------------------Режим пониженного энергопотребления----------------------------------------------------
void low_pwr(void) //режим пониженного энергопотребления
{
  if (mainSettings.sleep_switch == 2 && power_manager) { //если сон разрешен и разрешено энергосбережение
    if (TIMSK1 || TIMSK2 || TIMSK0) waint_pwr(); //если включен бузер или шим подсветки или индикация частиц - режим ожидания
    else if (sleep && power_manager == 2) _sleep_pwr(); //если спим и разрешено глубокое энергосбережение
    else save_pwr(); //иначе - режим энергосбережения
  }
  else waint_pwr(); //иначе - режим ожидания

  if (rad_back > RAD_SLEEP_OUT) cnt_pwr = 0; //если фон выше установленного предела - просыпаемся

  if (cnt_pwr == mainSettings.time_sleep && mainSettings.sleep_switch == 2 && !sleep_disable) { //если пришло время спать и сон не запрещен
    enableSleep(); //уводим в сон дисплей
    sleep = 1; //выставляем флаг сна
    buzz_save(); //запрещаем щелчки

  }
  else if (cnt_pwr == mainSettings.time_bright) { //если пришло время выключить подсветку
    _LIGHT_OFF(); //выключаем подсветку
    light = 1; //выставляем флаг выключенной подсветки
  }
  else if (!cnt_pwr) sleep_out(); //если пора проснуться
}
//-------------------------------------Выход из сна--------------------------------------------------------
void sleep_out(void) //выход из сна
{
  if (sleep) //если спали
  {
    disableSleep(mainSettings.contrast); //выводим дисплей из сна
    _LIGHT_ON(); //включаем подсветку
    sleep = 0; //сбрасываем флаг сна
    light = 0; //сбрасываем флаг подсветки
    buzz_ret(); //восстанавливаем настройку щелчков
    scr = 0; //обновляем экран
  }
  if (light) //если выключели подсветку
  {
    _LIGHT_ON(); //включаем подсветку
    light = 0; //сбрасываем флаг подсветки
  }
}
//-------------------------------------Ожидание--------------------------------------------------------
void waint_pwr(void) //ожидание
{
  SMCR = (0x0 << 1) | (1 << SE);  //устанавливаем режим сна idle

  MCUCR = (0x03 << 5); //выкл bod
  MCUCR = (0x02 << 5);

  asm ("sleep");  //с этого момента спим.
}
//-------------------------------------Энергосбережение--------------------------------------------------------
void save_pwr(void) //энергосбережение
{
  SMCR = (0x6 << 1) | (1 << SE);  //устанавливаем режим сна standby

  MCUCR = (0x03 << 5); //выкл bod
  MCUCR = (0x02 << 5);

  asm ("sleep");  //с этого момента спим.
}
//-------------------------------------Глубокий сон--------------------------------------------------------
void _sleep_pwr(void) //энергосбережение
{
  SMCR = (0x2 << 1) | (1 << SE);  //устанавливаем режим сна powerdown

  MCUCR = (0x03 << 5); //выкл bod
  MCUCR = (0x02 << 5);

  asm ("sleep");  //с этого момента спим.
}
//---------------------------------------Включение питания------------------------------------------------------
#if PWR_ON_RETURN
EMPTY_INTERRUPT(INT1_vect); //внешнее прерывание на пине INT1 - включение питания
#endif
//-------------------------------------Выключение устройства----------------------------------------------------
void power_down(void) //выключение устройства
{
  //=======================================================
  time_save += time_sec - time_save_old; //добавляем время
  rad_dose_save += rad_dose - rad_dose_old; //добавляем дозу

  time_save_old = time_sec; //сбрасывае счетчик времени
  rad_dose_old = rad_dose; //сбрасывае счетчик дозы

  statistic_update(); //обновление статистики
  //=======================================================

  LIGHT_OFF; //выключаем подсветку
  enableSleep(); //выключаем дисплей
  SOUND_STOP; //выключаем таймер
  BUZZ_OFF; //выключаем бузер
  FLASH_OFF; //выключаем фонарь

  _wdt_disable();  //выключаем watchdog
  _adc_disable(); //выключаем питание АЦП

#if PWR_ON_RETURN
  EIMSK = 0b00000010; //разрешаем внешнее прерывание INT2

  while (1) { //цикл выключенного питания
    _sleep_pwr(); //спим

    uint16_t startDellay = POWER_ON_TIME; //устанавливаем таймер
    while (!OK_OUT) { //если кнопка не отжата
      if (startDellay) { //если время не истекло
        _delay_ms(1); //ждем 1мс
        startDellay--; //отнимаем от таймера 1 мс
      }
      else { //иначе включаем питание
        _adc_enable(); //включаем питание АЦП
        _bat_check(); //опрос батареи
        if (bat_adc < LOW_BAT_POWER) { //если батарея не разряжена
          disableSleep(mainSettings.contrast); //включаем дисплей
          LIGHT_ON; //включаем подсветку, если была включена настройками
          _init_logo(); //вывод логотипа
          _start_pump(); //первая накачка преобразователя

          while (!OK_OUT); //ждем пока отпустят кнопу

          _wdt_enable(); //запускаем WatchDog с пределителем 2
          EIMSK = 0b00000001; //разрешаем внешнее прерывание INT0

          scr = 0; //обновляем экран
          return; //выходим
        }
        else { //иначе выводим предупреждение об разряженной батарее
          disableSleep(mainSettings.contrast); //включаем дисплей
          _init_low_bat(); //отрисовка сообщения разряженной батареи
          _delay_ms(POWER_TIME); //ждём
          enableSleep(); //выключаем дисплей
          _adc_disable(); //выключаем питание ацп
        }
      }
    }
  }
#else
  EIMSK = 0b00000000; //запрещаем внешние прерывание
  _sleep_pwr(); //спим
#endif
}
//---------------------------------Индикация попадания частиц---------------------------------------
ISR(TIMER0_OVF_vect) //индикация попадания частиц
{
  static uint8_t i; //счетчик миллисекунд
  if (++i >= RAD_FLASH_TIME) { //если время пришло
    i = 0; //сбрасываем счетчик
    _RAD_FLASH_OFF; //выключаем все
  }
}
//---------------------------------Плавная подсветка---------------------------------------
ISR(TIMER2_OVF_vect) //плавная подсветка
{
  LIGHT_ON; //включаем подсветку
  switch (light_switch) { //выбераем режим 1 - разгорание | 0 - затухание
    case 0:
      if (OCR2A > 0) OCR2A--; //убавляем счетчик циклов шим
      else {
        LIGHT_OFF; //выключаем подсветку
        _LIGHT_STOP(); //выключаем все
      }
      break;
    case 1:
      if (OCR2A < 255) OCR2A++; //прибавляем счетчик циклов шим
      else {
        LIGHT_ON; //включаем подсветку
        _LIGHT_STOP(); //выключаем все
      }
      break;
  }
}
ISR(TIMER2_COMPA_vect, ISR_NAKED) {
  LIGHT_OFF; //выключаем подсветку
  reti(); //возврат
}
//---------------------------------Прерывание сигнала для пищалки---------------------------------------
ISR(TIMER1_OVF_vect, ISR_NAKED) //прерывание сигнала для пищалки
{
  BUZZ_ON; //включаем бузер
  reti(); //возврат
}
ISR(TIMER1_COMPA_vect) {
  BUZZ_OFF; //выключаем бузер

  switch (--cnt_puls) { //считаем циклы времени работы бузера
    case 0: SOUND_STOP; break; //если циклы кончились, выключаем таймер
  }
}
//--------------------------------Аналог tone(), с блекджеком и ...----------------------------------
void buzz_pulse(uint16_t freq, uint16_t time) //генерация частоты бузера (частота 10..10000, длительность мс.)
{
  cnt_puls = ((uint32_t)freq * (uint32_t)time) / 1000UL; //пересчитываем частоту и время в циклы таймера
  SOUND_START((F_CPU / SOUND_PRESCALER) / freq); //устанавливаем частоту и запускаем таймер
}
//--------------------------------Щелчок пищалкой-------------------------------------------------
inline void buzz_click(void) //щелчок пищалкой
{
  if (!TIMSK1) {
    cnt_puls = buzz_time; //устанавливаем длительность щелчка
    BUZZ_START(buzz_freq, buzz_vol); //устанавливаем частоту и запускаем таймер
  }
}
//---------------------------------Воспроизведение мелодии---------------------------------------
void _melody_chart(const uint16_t arr[][3], uint8_t n) //воспроизведение мелодии
{
  if (!timer_melody) { //если пришло время
    buzz_pulse(pgm_read_word(&arr[melody_switch][0]), pgm_read_word(&arr[melody_switch][1])); //запускаем звук с задоной частотой и временем
    timer_melody = pgm_read_word(&arr[melody_switch][2]); //устанавливаем паузу перед воспроизведением нового звука
    if (++melody_switch > n - 1) melody_switch = 0; //переключаем на следующий семпл
  }
}
//-----------------------------Проверка кнопок----------------------------------------------------
uint8_t check_keys(void) //проверка кнопок
{
  static uint8_t btn_set; //флаг признака действия
  static uint8_t btn_switch; //флаг мультиопроса кнопок

  switch (btn_switch) { //переключаемся в зависимости от состояния мультиопроса
    case 0:
      if (!OK_OUT) { //если нажата кл. ок
        btn_switch = 1; //выбираем клавишу опроса
        btn_state = 0; //обновляем текущее состояние кнопки
      }
      else if (!DOWN_OUT) { //если нажата кл. вниз
        btn_switch = 2; //выбираем клавишу опроса
        btn_state = 0; //обновляем текущее состояние кнопки
      }
      else if (!UP_OUT) { //если нажата кл. вверх
        btn_switch = 3; //выбираем клавишу опроса
        btn_state = 0; //обновляем текущее состояние кнопки
      }
      else btn_state = 1; //обновляем текущее состояние кнопки
      break;
    case 1: btn_state = OK_OUT; break; //опрашиваем клавишу ок
    case 2: btn_state = DOWN_OUT; break; //опрашиваем клавишу вниз
    case 3: btn_state = UP_OUT; break; //опрашиваем клавишу вверх
  }

  switch (btn_state) { //переключаемся в зависимости от состояния клавиши
    case 0:
      if (btn_check) { //если разрешена провекрка кнопки
        if (btn_tmr > BTN_HOLD_TICK) { //если таймер больше длительности удержания кнопки
          btn_tmr = BTN_GIST_TICK; //сбрасываем таймер на антидребезг
          if (!light && !sleep) { //если не спим и если подсветка включена
            btn_set = 2; //поднимаем признак удержания
            cnt_pwr = 0; //сбрасываем таймер сна
          }
          btn_check = 0; //запрещем проврку кнопки
        }
      }
      break;

    case 1:
      if (btn_tmr > BTN_GIST_TICK) { //если таймер больше времени антидребезга
        btn_tmr = BTN_GIST_TICK; //сбрасываем таймер на антидребезг
        if (!light && !sleep) btn_set = 1; //если не спим и если подсветка включена, поднимаем признак нажатия
        btn_check = 0; //запрещем проврку кнопки
        cnt_pwr = 0; //сбрасываем таймер сна
        if (!mainSettings.knock_disable) buzz_pulse(FREQ_BEEP, TIME_BEEP); //щелчок пищалкой
      }
      else if (!btn_tmr) {
        btn_check = 1; //разрешаем проврку кнопки
        btn_switch = 0; //сбрасываем мультиопрос кнопок
      }
      break;
  }

  switch (btn_set) { //переключаемся в зависимости от признака нажатия
    case 0: return 0; //клавиша не нажата, возвращаем 0
    case 1:
      btn_set = 0; //сбрасываем признак нажатия
      switch (btn_switch) { //переключаемся в зависимости от состояния мультиопроса
        case 1: return 5; //ok press, возвращаем 5
        case 2: return 2; //down press, возвращаем 2
        case 3: return 3; //up press, возвращаем 3
      }
      break;

    case 2:
      btn_set = 0; //сбрасываем признак нажатия
      switch (btn_switch) { //переключаемся в зависимости от состояния мультиопроса
        case 1: return 6; //ok hold, возвращаем 6
        case 2: return 1; //down hold, возвращаем 1
        case 3: return 4; //up hold, возвращаем 4
      }
      break;
  }
  return 0;
}
//-------------------------------Оостановка замера----------------------------------------------------------
void measur_stop(void) //остановка замера
{
  boolean n = 0; //курсор

  clrScr(); //очистка экрана
  print(M_STOP, CENTER, 8); //Остановить
  print(M_MEASUR, CENTER, 16); //замер?

  while (1) {
    data_convert(); //преобразование данных

    if (!scr) {
      scr = 1; //устанавливаем флаг
      choice_menu(n); //меню выбора
      showScr(); //вывод буфера на экран
    }

    switch (check_keys()) {

      case 2: //Down key
        n = 0;
        scr = 0; //разрешаем обновление экрана
        break;
      case 3: //Up key
        n = 1;
        scr = 0; //разрешаем обновление экрана
        break;

      case 5: //select key
        switch (n) {
          case 1:
            measur = 0; //выключаем замер
            time_switch = 0; //сбрасываем таймер
            next_measur = 1; //сбрасываем флаг продолжения замера
            alarm_measur = 1; //разрешаем оповещение окончания замера
            first_froze = 0; //сбрасываем счетчик 1-го замера
            second_froze = 0; //сбрасываем счетчик 2-го замера
            scan_buff = rad_buff[0] = 0; //очищаем 0-й и 1-й элемент буфера
            return;

          case 0:
            scr = 0; //разрешаем обновление экрана
            return;
        }
        break;
    }
  }
}
//-------------------------------Окончание замера----------------------------------------------------------
void measur_massege(void) //окончание замера
{
  if (next_measur && !alarm_measur) { //если поднят флаг следующего замера и оповещение окончания замера разешено

    sleep_out(); //просыпаемся если спали
    buzz_save(); //запрещаем щелчки

    clrScr(); //очистка экрана
    print(M_MEASURS, CENTER, 16); //Замер
    print(M_COMPLET, CENTER, 24); //завершен!

    showScr(); //вывод буфера на экран

    melody_switch = 0; //сбрасываем переключатель мелодии

    for (timer_millis = MASSEGE_TIME; timer_millis && !check_keys();) { //ждём
      data_convert(); //преобразование данных
      //==================================================================
#if MEASUR_SOUND
      _melody_chart(measur_sound, SAMPLS_MEASUR); //играем волшебную мелодию
#endif
      //==================================================================
    }
    switch (measur) {
      case 1: alarm_measur = 1; break; //запрещаем повторное оповещение
      case 2:
        measur = 0;
        time_switch = 0;
        alarm_measur = 1;
        scan_buff = rad_buff[0] = 0; //очищаем 0-й и 1-й элемент буфера
#if LOGBOOK_RETURN
        if (bookSettings.logbook_measur) {
          bookSettings.logbook_measur = 2; //устанавливаем признак новой записи
#if  TYPE_MEASUR_LOGBOOK
          _logbook_data_update(2, pgm_read_byte(&diff_measuring[mainSettings.measur_pos]), (first_froze < second_froze) ? (second_froze - first_froze) : 0); //обновление журнала ч/см2
#else
          _logbook_data_update(2, pgm_read_byte(&diff_measuring[mainSettings.measur_pos]), (first_froze < second_froze) ? (second_froze - first_froze) * (pumpSettings.geiger_time / (pgm_read_byte(&diff_measuring[mainSettings.measur_pos]) * 60)) : 0); //обновление журнала мкР/ч
#endif
        }
#else
#if  TYPE_MEASUR_LOGBOOK
        _logbook_data_update(2, pgm_read_byte(&diff_measuring[mainSettings.measur_pos]), (first_froze < second_froze) ? (second_froze - first_froze) : 0); //обновление журнала ч/см2
#else
        _logbook_data_update(2, pgm_read_byte(&diff_measuring[mainSettings.measur_pos]), (first_froze < second_froze) ? (second_froze - first_froze) * (pumpSettings.geiger_time / (pgm_read_byte(&diff_measuring[mainSettings.measur_pos]) * 60)) : 0); //обновление журнала мкР/ч
#endif
#endif
        break;
    }
    buzz_ret(); //считываем настроку щелчков
    cnt_pwr = 0; //обнуляем счетчик сна
    scr = 0; //разрешаем обновления экрана
  }
}
//-------------------------------Режим замера----------------------------------------------------------
void measur_menu(void) //режим замера
{
  uint32_t buff = 0;
  boolean n = 0; //анимация окончания замера

  alarm_measur = 1; //запрещаем оповещение окончания замера
  next_measur = 1; //поднимаем флаг продолжения замера

  scr = 0; //разрешаем обновления экрана

  while (1) {
    data_convert(); //преобразование данных
    bat_massege(); //обновление состояния батареи
    error_messege(); //обработка ошибок
    measur_massege(); //оповещение об окончании замера

    if (!scr) {
      scr = 1; //устанавливаем флаг

      clrScr(); //очистка экрана
      task_bar(M_MEASUR_BETA); //отрисовываем фон

      switch (measur) {
        case 0: //результат
          buff = (first_froze < second_froze) ? second_froze - first_froze : 0; //рассчитываем результат замера

          if (next_measur) {
            switch (n) {
              case 0:
                print(M_RESULT, CENTER, 24); //результат
                _init_couts_per_cm2((float)buff / pgm_read_byte(&diff_measuring[mainSettings.measur_pos])); //результат ч/см2*м
                n = 1;
                break;
              case 1:
                print(M_BACK_OK, CENTER, 24); //ок - замер фона
                _init_rads_unit(1, buff * (pumpSettings.geiger_time / (pgm_read_byte(&diff_measuring[mainSettings.measur_pos]) * 60)), 1, 4, 1, 8, 0, 54, 16); //результат мкр/ч
                n = 0;
                break;
            }
          }
          else print(M_RESULT, CENTER, 24); //результат

          _init_accur_percent(_init_accur(buff)); //отрисовка точности

          print(M_BACK_I, LEFT, 32); //строка 1 фон
          _init_small_couts_per_cm2((float)first_froze / pgm_read_byte(&diff_measuring[mainSettings.measur_pos]), 32);

          print(M_SAMP_I, LEFT, 40); //строка 2 обр
          _init_small_couts_per_cm2((float)second_froze / pgm_read_byte(&diff_measuring[mainSettings.measur_pos]), 40);

          break;

        case 1: //1-й замер
          if (next_measur) {
            switch (n) {
              case 0: print(M_BACK, CENTER, 24); n = 1; break; //замер фона
              case 1: print(M_SAMP_OK, CENTER, 24); n = 0; break; //ок - зам. образца
            }
          }
          else print(M_BACK, CENTER, 24); //замер фона
          _init_couts_per_cm2(first_froze / (((time_switch) ? time_switch : 1) / 60.0)); //рассчитываем результат замера в ч*см2/м); //первый замер ч/см2*м
          _init_accur_percent(_init_accur(first_froze)); //отрисовка точности
          break;

        case 2: //2-й замер
          _init_couts_per_cm2(second_froze / (((time_switch) ? time_switch : 1) / 60.0)); //второй замер ч/см2*м
          _init_accur_percent(_init_accur(second_froze)); //отрисовка точности
          print(M_SAMP, CENTER, 24); //замер образца
          break;
      }

      if (measur) { //если идет замер
        printNumI(pgm_read_byte(&diff_measuring[mainSettings.measur_pos]), 50, 40, 2, 32); //минут всего
        print(M_MIN, RIGHT, 40);            //строка 1 мин
#if (TYPE_CHAR_FILL > 44)
        printNumI(((pgm_read_byte(&diff_measuring[mainSettings.measur_pos]) * 60 - time_switch) / 60), 0, 40, 2, TYPE_CHAR_FILL); //минут
#else
        printNumI(((pgm_read_byte(&diff_measuring[mainSettings.measur_pos]) * 60 - time_switch) / 60), 0, 40, 2, 32); //минут
#endif
        print(M_TIME, 12, 40);            //строка 2
        printNumI((pgm_read_byte(&diff_measuring[mainSettings.measur_pos]) * 60 - time_switch) % 60, 18, 40, 2, 48); //секунд

        _screen_line(0, map(time_switch, 0, pgm_read_byte(&diff_measuring[mainSettings.measur_pos]) * 60, 5, 82), 1, 1, 32); //шкала пройденого времени
      }

      showScr(); //вывод буфера на экран
    }
    //+++++++++++++++++++++  опрос кнопок  +++++++++++++++++++++++++++
    switch (check_keys())
    {
      case 1: //Down key hold
        fast_light(); //быстрое включение подсветки
        break;

      case 2: //Down key
        if (measur) measur_stop(); //если идет замер, спрашиваем нужно ли остановить замер
        else {
          measur = 0; //выключаем замер
          time_switch = 0; //сбрасываем таймер
          next_measur = 1; //сбрасываем флаг следующего замера
          alarm_measur = 1; //разрешаем оповещение оканчания замера
          first_froze = 0; //сбрасываем счетчик 1-го замера
          second_froze = 0; //сбрасываем счетчик 2-го замера
          scan_buff = rad_buff[0] = 0; //очищаем 0-й и 1-й элемент буфера
        }
        scr = 0; //разрешаем обновления экрана
        break;

      case 3: //Up key
        if (measur) measur_stop(); //если идет замер, спрашиваем нужно ли остановить замер
        scr = 0; //разрешаем обновления экрана
        break;

      case 4: //Up key hold
        FLASH_SWITCH; //быстрое включение фонарика
        break;

      case 5: //select key
        if (!measur) {
          measur = 1; //включаем замер
          next_measur = 0; //сбрасываем флаг следующего замера
          alarm_measur = 0; //разрешаем оповещение оканчания замера
          first_froze = 0; //сбрасываем счетчик 1-го замера
          second_froze = 0; //сбрасываем счетчик 2-го замера
          scan_buff = 0; //очищаем 0-й элемент буфера
        }
        else if (next_measur && measur == 1) {
          measur = 2;
          next_measur = 0;
          time_switch = 0;
          alarm_measur = 0;
          scan_buff = 0; //очищаем 0-й элемент буфера
          n = 0;
        }
        scr = 0; //разрешаем обновления экрана
        break;

      case 6: //hold select key
        if (measur) measur_stop(); //если идет замер, спрашиваем нужно ли остановить замер
        switch (measur) {
          case 0: return; //выходим в меню
          case 1: scr = 0; break; //разрешаем обновления экрана
        }
        break;
    }
  }
}
//-------------------------------Частиц/см2*мин----------------------------------------------------------
void _init_couts_per_cm2(float num) //частиц/см2*мин
{
  num /= GEIGER_AREA;

  setFont(MediumNumbers); //установка шрифта
  printNumF(num, (num < 100) ? 1 : 0, 1, 8, 46, 4, TYPE_CHAR_FILL); //строка 1
  print(UNIT_COUNT_PER_SQUARE_CM, 54, 16); //строка 1 ч/см2
}
//-------------------------------Частиц/см2*мин----------------------------------------------------------
void _init_small_couts_per_cm2(float num, uint8_t pos_y) //частиц/см2*мин
{
  num /= GEIGER_AREA;

  print(UNIT_COUNT_PER_SQUARE_CM, 54, pos_y); //строка 2 ч/см2
#if (TYPE_CHAR_FILL > 44)
  printNumF(num, (num < 100) ? 1 : 0, 30, pos_y, 46, 4, TYPE_CHAR_FILL); //строка 2
#else
  printNumF(num, (num < 100) ? 1 : 0, 30, pos_y, 46, 4, 32);
#endif
}
//-------------------------------Выбор тревоги----------------------------------------------------------
void alarm_warning(void) //выбор тревоги
{
  switch (alarm_switch) {
    case 1: alarm_messege(0, mainSettings.alarm_back, A_BACK); break; //фон 2
    case 2: alarm_messege(1, mainSettings.alarm_dose, A_DOSE); break; //доза 2
    case 3: warn_messege(0, mainSettings.alarm_back); break; //фон 1
    case 4: warn_messege(1, mainSettings.alarm_dose); break; //доза 1
  }
}
//-------------------------------Предупреждение----------------------------------------------------------
void warn_messege(boolean set, uint8_t sound) //предупреждение
{
  buzz_save(); //запрещаем щелчки

  cnt_pwr = 0; //обнуляем счетчик сна

  switch (set) { //переключаемся на экран тревоги
    case 0:
      if (scr_mode) { //фон
        scr_mode = 0;
        return;
      }
      break;
    case 1:
      if (!scr_mode) { //доза
        scr_mode = 1;
        dose_mode = 0;
        return;
      }
      break;
  }
  //==================================================================
  switch (sound) {
    case 1: _melody_chart(warn_sound, SAMPLS_WARN); break; //играем волшебную мелодию
    case 2: _vibro_on(); break; //включаем вибрацию
    case 3: _melody_chart(warn_sound, SAMPLS_WARN); _vibro_on(); break; //играем волшебную мелодию и включаем вибрацию
  }
  //==================================================================
}
//-------------------------------Тревога-----------------------------------------------------
void alarm_messege(boolean set, uint8_t sound, const char *mode) //тревога
{
  sleep_out(); //просыпаемся если спали
  buzz_save(); //запрещаем щелчки
  //запретить звуковую индикацию импульсов

  melody_switch = 0; //сбрасываем переключатель мелодии
  vibro_switch = 0; //сбрасываем переключатель вибрации

  clrScr(); //очистка экрана
  drawBitmap(26, 0, rad_img, 32, 32);
  print(A_ALARM, CENTER, 32); //строка ТРЕВОГА!

  scr = 0; //разрешаем обновления экрана

  while (1) {
    data_convert(); //преобразование данных

    if (!scr) {
      scr = 1;
      clrRow(5); //очистка строки 5

#if TYPE_ALARM_IND != 2
      clrRow(4); //очистка строки 5
      _init_alarm_massage(1, 32); //тревога
#endif

      print(mode, LEFT, 40); //фон
      _init_rads_unit(0, (set) ? rad_dose : rad_back, 10, 5, RIGHT, 40, set, RIGHT, 40); //результат

      showScr(); //вывод буфера на экран
    }

    //==================================================================
    switch (sound) {
      case 1: _melody_chart(alarm_sound, SAMPLS_ALARM); break; //играем волшебную мелодию
      case 2: _vibro_on(); break; //включаем вибрацию
      case 3: _melody_chart(alarm_sound, SAMPLS_ALARM); _vibro_on(); break; //играем волшебную мелодию и включаем вибрацию
    }
    //==================================================================

#if ALARM_AUTO_DISABLE
    if (check_keys() || (!set && !alarm_switch)) //если нажата любая кнопка или фон упал отключаем тревогу
#else
    if (check_keys())
#endif
    {
      _vibro_off(); //выключаем вибрацию
      buzz_ret(); //восстанавливаем настроку щелчков

      switch (set) {
        case 0: alarm_back_wait = warn_back_wait = 1; break;
        case 1: alarm_dose_wait = warn_dose_wait = rad_dose; break;
      }

      melody_switch = 0; //сбрасываем переключатель мелодии
      vibro_switch = 0; //сбрасываем переключатель вибрации
      alarm_switch = 0; //устанавливаем признак отсутствия тревоги
      cnt_pwr = 0; //обнуляем счетчик сна
      scr = 0; //разрешаем обновление экрана
      return;
    }
  }
}
//--------------------------Инициализация сообщения тревоги---------------------------------
void _init_alarm_massage(boolean text, uint8_t pos) { //инициализация сообщения тревоги
  static boolean i = 0; //переключатель анимации

  if (i) {
    invertText(true);
    _screen_line(0, 84, 0, 0, pos); //рисуем линию
  }
  switch (text) {
    case 0: print(A_WARN, CENTER, pos); break; //строка ОПАСНОСТЬ!
    case 1: print(A_ALARM, CENTER, pos); break; //строка ТРЕВОГА!
  }
  invertText(false);
  i = !i; //меняем значение
}
//--------------------------Вибрация и световая индикация тревоги---------------------------------
void _vibro_on(void) //вибрация и световая индикация тревоги
{
  if (!timer_millis) { //если пришло время
    switch (pgm_read_word(&alarm_vibro[vibro_switch][0])) {
      case 0:
#if (TYPE_ALARM_IND == 1)
        VIBRO_ON;
        FLASH_ON;
#elif (TYPE_ALARM_IND == 2)
        VIBRO_ON;
        LIGHT_ON;
#else
        VIBRO_ON;
#endif
        break;

      case 1:
#if (TYPE_ALARM_IND == 1)
        VIBRO_OFF;
        FLASH_OFF;
#elif (TYPE_ALARM_IND == 2)
        VIBRO_OFF;
        LIGHT_OFF;
#else
        VIBRO_OFF;
#endif
        break;
    }
    timer_millis = pgm_read_word(&alarm_vibro[vibro_switch][1]); //устанавливаем паузу перед воспроизведением нового семпла
    if (++vibro_switch > SAMPLS_VIBRO - 1) vibro_switch = 0; //переключпем на следующий семпл
  }
}
//-----------------------Выключение вибрация и световой индикаци--------------------------------
void _vibro_off(void) //выключение вибрация и световой индикаци
{
#if (TYPE_ALARM_IND == 1)
  FLASH_OFF; //выключаем фонарик
  VIBRO_OFF; //выключаем вибрацию
#elif (TYPE_ALARM_IND == 2)
  if (light_switch) LIGHT_ON; //включаем подсветку, если была включена настройками
  else LIGHT_OFF; //выключаем подсветку
  VIBRO_OFF; //выключаем вибрацию
#else
  VIBRO_OFF; //выключаем вибрацию
#endif
}
//-----------------------------------Первая накачка--------------------------------------------
void _start_pump(void) //первая накачка
{
  uint16_t i = 0; //таймер авто-выхода
  print(LOAD, CENTER, 32); //загрузка...

  for (hv_adc = Read_HV(); hv_adc < pumpSettings.ADC_value; hv_adc = Read_HV()) { //значение АЦП при котором на выходе 400В

    CONV_ON; //пин накачки вкл
    for (uint8_t c = pumpSettings.puls; c > 0; c--) asm("nop"); //ждем
    CONV_OFF; //пин накачки выкл

    if (++i >= START_PUMP_TIME) break; //если время вышло, останавливаем накачку

    _screen_line(0, map(hv_adc, 0, pumpSettings.ADC_value, 0, 64), 0, 10, 40); //прогресс бар накачки преобразователя
    showScr(); //вывод буфера на экран
  }
}
//----------------------------Накачка по обратной связи с АЦП---------------------------------
void pump(void) //накачка по обратной связи с АЦП
{
  uint8_t i = 0; //счетчик циклов переполнения

  for (hv_adc = Read_HV(); hv_adc < pumpSettings.ADC_value; hv_adc = Read_HV()) { //значение АЦП при котором на выходе 400В

    CONV_ON; //пин накачки вкл
    for (uint8_t c = pumpSettings.puls; c > 0; c--) asm("nop"); //ждем
    CONV_OFF; //пин накачки выкл

    speed_pump++; //считаем скорость накачки

    if (++i >= CYCLE_OVERFLOW) break;  //защита от зацикливания
  }
}
//------------------------Чтение напряжения преобразователя-----------------------------------
uint8_t Read_HV(void) //чтение напряжения преобразователя
{
  uint16_t result = 0; //результат опроса АЦП внутреннего опорного напряжения
  ADCSRA |= 0b01000000; //запускаем преобразование

  for (uint8_t i = 0; i < 10; i++) { //делаем 10 замеров
    while (ADCSRA & 0b01000000); //ждем окончания преобразования
    result += ADCH; //прибавляем замер в буфер
    ADCSRA |= 0b01000000; //перезапускаем преобразование
  }
  return result / 10; //возвращаем результат опроса АЦП
}
//--------------------------------Чтение напряжения батареи-------------------------------------
uint8_t Read_VCC(void)  //чтение напряжения батареи
{
  ADMUX = 0b01101110; //выбор внешнего опорного+BG
  _delay_ms(5); //ждём пока опорное успокоится
  ADCSRA |= 0b01000000; //запускаем преобразование
  while (ADCSRA & 0b01000000); //ждем окончания преобразования

#if UNO_DIP //если при компилляции выбрана плата ArduinoUNO
  ADMUX = 0b11100101; //выбор внутреннего опорного 1,1В и А5
#else //если используется промини, нано или голый камень в tqfp
  ADMUX = 0b11100110; //выбор внутреннего опорного 1,1В и А6
#endif

  return ADCH; //возвращаем результат опроса АЦП
}
//-----------------------------------Опрос батареи-----------------------------------------------
void _bat_check(void) //опрос батареи
{
  bat_adc = Read_VCC(); //состояние батареи
  if (bat_adc == 255) bat_adc = 60; //защита от ложных данных

  if (bat_adc < MIN_BAT) { //мин.напр. 3v макс.нап. 4,2v
    if (bat_adc < MAX_BAT) bat = 5;  //если батарея заряжена
    else { //иначе расчитывает указатель заряда батареи
      bat = map(bat_adc, MIN_BAT, MAX_BAT, 0, 5); //переводим значение в полосы акб
      bat = (bat > 5) ? 5 : bat; //ограничиваем
    }
  }
  else bat = 0; //иначе акб разряжен
}
//-----------------------------------Отрисовка сообщения разряженной батареи----------------------------------------
void _init_low_bat(void) //отрисовка сообщения разряженной батареи
{
  drawBitmap(26, 0, low_bat_img, 32, 32); //рисуем заставку
  print(B_BAT, CENTER, 32); //Батарея
  print(B_LOW, CENTER, 40); //разряжена!
  showScr(); //вывод буфера на экран
}
//-----------------------------------Сообщение об разряженной батареи-----------------------------------------------
void bat_massege(void) //сообщение об разряженной батареи
{
  if (!low_bat_massege && bat_adc >= LOW_BAT_STAT) { //если флаг разрешения сообщения поднят и заряд ниже 3v, то выводим предупреждение
    low_bat_massege = 1; //запрещаем вывод сообщения

    sleep_out(); //просыпаемся если спали
    buzz_save(); //запрещаем щелчки
    //запретить звуковую индикацию импульсов
    melody_switch = 0; //сбрасываем переключатель мелодии

    clrScr(); // Очистка экрана
    _init_low_bat(); //отрисовка сообщения разряженной батареи

    for (timer_millis = MASSEGE_TIME; timer_millis && !check_keys();) { //ждём
      data_convert(); //преобразование данных
      //--------------------------------------------------------------------------------------
#if BAT_LOW_SOUND
      _melody_chart(bat_low_sound, SAMPLS_BAT_LOW); //играем волшебную мелодию
#endif
      //--------------------------------------------------------------------------------------
    }
    buzz_ret(); //считываем настроку щелчков
    cnt_pwr = 0; //обнуляем счетчик сна
    scr = 0; //разрешаем обновление экрана
    if (bat_adc >= LOW_BAT_POWER) power_down(); //выключение устройства
  }
}
//-------------------------Обновление данных поиска----------------------------------------------------
void search_update(void) //обновление данных поиска
{
  static uint8_t now_pos; //переключатель динамического изменения времени
  static uint16_t cnt; //счетчик тиков графика
  static uint16_t scan_now; //имп/с за период
  static uint16_t time_to_update; //текущее время обновления
  static uint32_t imp_s; //имп/с для расчетов

  if (++cnt >= now_pos) { //расчет показаний
    uint16_t graf_max = 0; //максимум графика
    uint32_t temp_buf = 0; //временный буфер расчета имп

    if (!search_disable) {
      if (search_time_now < SEARCH_BUF_SCORE) search_time_now++;

#if TYPE_GRAF_MOVE //слева-направо
      for (uint8_t i = 75; i > 0; i--) {
        search_buff[i] = search_buff[i - 1]; //сдвигаем массив
        if (search_buff[i] > graf_max) graf_max = search_buff[i];
      }
      search_buff[0] = scan_buff; //новое значение в последнюю ячейку

      if (search_buff[0] > graf_max) graf_max = search_buff[0];
#else //справа-налево
      for (uint8_t i = 0; i < 75; i++) {
        search_buff[i] = search_buff[i + 1]; //сдвигаем массив
        if (search_buff[i] > graf_max) graf_max = search_buff[i];
      }
      search_buff[75] = scan_buff; //новое значение в последнюю ячейку

      if (search_buff[75] > graf_max) graf_max = search_buff[75];
#endif

      if (graf_max > 22) maxLevel = graf_max * GRAF_COEF_MAX; //если текущий замер больше максимума
      else maxLevel = 22;
    }

    rad_buff[0] += scan_buff; //смещаем 0-й элемент в 1-й для дальнейшей работы с ним
    scan_buff = 0; //сбрасываем счетчик импульсов

#if TYPE_GRAF_MOVE //слева-направо
    for (uint8_t i = 0; i < search_time_now; i++) temp_buf += search_buff[i]; //сдвигаем массив
#else //справа-налево
    for (uint8_t i = 76 - search_time_now; i < 76; i++) temp_buf += search_buff[i]; //сдвигаем массив
#endif

    rad_imp = ((float)temp_buf / search_time_now) * ((time_to_update) ? (1000.00 / time_to_update) : 1); //персчет имп/сек.
    rad_imp_m = rad_imp * 60.0; //персчет импульсов в имп/мин.
    rad_search = rad_imp * pumpSettings.geiger_time; //считаем мкР/ч | мкЗ/ч

    imp_s = search_buff[0] * (1000.00 / time_to_update); //персчет имп/сек.
    time_to_update = (mainSettings.search_pos != 8) ? pgm_read_word(&search_time[mainSettings.search_pos]) : pgm_read_word(&search_time[map((imp_s > SEARCH_IND_MAX) ? SEARCH_IND_MAX : imp_s, 0, SEARCH_IND_MAX, 7, 0)]);

    now_pos = (float)time_to_update / ((float)pumpSettings.wdt_period / 100.0);

    cnt = 0; //сброс
    graf = 0; //разрешаем обновление графика
  }

  scan_now = (imp_s > SEARCH_IND_MAX) ? SEARCH_IND_MAX : imp_s; //устанавливаем точки максимумов
  scan_now = map(scan_now, 0, SEARCH_IND_MAX, 2, 51); //корректируем под коэффициент
  if (scan_now < scan_ind) scan_ind--; //добавляем плавности при уменьшении
  else scan_ind = scan_now; //если увеличелось, отображаем сразу
}
//-------------------------Инициализация режима поиск-----------------------------------------
void search_menu(void) //инициализация режима поиск
{
  uint8_t c = 0; //переключатель единиц графика
  search = 1; //устанавливаем флаг поиска
  graf = 0; //разрешаем обновление экрана

  while (1) {
    data_convert(); //преобразование данных
    bat_massege(); //обновление состояния батареи
    error_messege(); //обработка ошибок

    clrRow(2, scan_ind + 1, 54); //убираем лишнее
    drawBitmap(0, 16, scan_ind_img, scan_ind, 8); //рисуем полосу имп/с

    if (!graf) {
      graf = 1; //запрещаем обновление графика

      clrRow(0); //очистка строки 0
      clrRow(1); //очистка строки 1
      clrRow(2, 55, 83); //очистка строки 2

      task_bar(S_SEARCH); //отрисовываем фон
      if (search_disable) drawBitmap(59, 0, scan_stop_img, 6, 8); //рисуем паузу
      drawBitmap(0, 8, scan_ind_scale_img, 51, 8); //рисуем шкалу

      switch (c) {
        case 0:
          print(S_IMP_PER_SEC, RIGHT, 8); //имп/с
#if (TYPE_CHAR_FILL > 44)
          printNumF(rad_imp, (rad_imp < 100) ? 0 : 0, 54, 16, 46, 5, TYPE_CHAR_FILL); //строка 1
#else
          printNumF(rad_imp, (rad_imp < 100) ? 2 : 0, 54, 16, 46, 5, 32); //строка 1
#endif
          break;

        case 1:
          print(S_IMP_PER_MIN, RIGHT, 8); //имп/м
#if (TYPE_CHAR_FILL > 44)
          printNumF(rad_imp_m, (rad_imp_m < 100) ? 2 : 0, 54, 16, 46, 5, TYPE_CHAR_FILL); //строка 1
#else
          printNumF(rad_imp_m, (rad_imp_m < 100) ? 2 : 0, 54, 16, 46, 5, 32); //строка 1
#endif
          break;

        case 2:
          _init_rads_unit(0, rad_search, 10, 5, 54, 16, 0, RIGHT, 8); //результат
          break;
      }

#if TYPE_GRAF_MOVE //слева-направо
      for (uint8_t i = 4; i < 80; i++) {
        graf_lcd(map(search_buff[i - 4], 0, maxLevel, 0, 22), i, 22, 3); //инициализируем график
      }
#else //справа-налево
      for (uint8_t i = 79; i > 3; i--) {
        graf_lcd(map(search_buff[i - 4], 0, maxLevel, 0, 22), i, 22, 3); //инициализируем график
      }
#endif
      showScr(); //вывод буфера на экран
    }
    //+++++++++++++++++++++  опрос кнопок  +++++++++++++++++++++++++++
    switch (check_keys()) {
      case 1: //Down key hold //вкл/выкл посветки
        fast_light(); //быстрое включение посветки
        break;

      case 2: //Down key //сброс
        rad_imp = 0; //сбрасываем имп/с
        rad_imp_m = 0; //сбрасываем имп/м
        rad_search = 0; //сбрасываем счет импульсов
        search_time_now = 0; //сбрасываем время счета графика
        scan_buff = 0; //сбрасываем буфер
        rad_buff[0] = 0; //сбрасываем буфер
        search_disable = 0; //разрешаем обновление графика
        for (uint8_t i = 0; i < 76; i++) search_buff[i] = 0; //очищаем буфер графика
        graf = 0; //разрешаем обновления экрана
        break;

      case 4: //Up key hold //вкл/выкл фонарика
        FLASH_SWITCH; //быстрое включение фонарика
        break;

      case 3: //Up key //доп.действие
        search_disable = (search_disable) ? 0 : 1; //запрещаем обновление графика
        graf = 0; //разрешаем обновления экрана
        break;

      case 5: //Select key //выбор режима
        if (c < 2) c++; else c = 0;
        graf = 0; //разрешаем обновления экрана
        break;

      case 6: //hold select key //настройки
        scan_buff = 0; //сбрасываем счетчик импульсов
        rad_buff[0] = 0; //сбрасываем счетчик импульсов
        search = 0; //сбрасываем флаг поиска
        scr = 0; //разрешаем обновления экрана
        return;
    }
  }
}
//--------------------------------Отрисовка графика-------------------------------------
void graf_lcd(uint8_t r, uint8_t p, uint8_t max_g, uint8_t height) //отрисовка графика
{
  if (r > max_g) r = max_g; //ограничивываем максимум
  switch (height) {
    case 2:
      if (p == 4) drawBitmap(0, 32, scan_left_img, 4, 16); //рисуем левую шкалу
      if (p == 79) drawBitmap(80, 32, scan_right_img, 4, 16); //рисуем правую шкалу
      break;

    case 3:
      if (p == 4) drawBitmap(0, 24, scan_alt_left_img, 4, 24); //рисуем левую шкалу
      if (p == 79) drawBitmap(80, 24, scan_alt_right_img, 4, 24); //рисуем правую шкалу
      break;
  }

  for (uint8_t i = 0; i < height; i++) { //отрисовываем 3 строки
    uint8_t scale = 0; //устанавливаем столбец в ноль
    if (((r + 1) >> 3) > i) scale = 8; //если столбец полный, зарисовываем полностью
    else if (r >= ((i << 3) + (r & 0b111))) scale = (r & 0b111) + 1; //иначе отрисовываем остаток
    drawBitmap(p, 40 - (i << 3), (uint8_t*)pgm_read_word(&scan_scale[scale]), 1, 8); //отрисовка
  }
}
//-----------------------------------Параметры-----------------------------------------
float _convert_vcc_bat(uint8_t adc) //параметры
{
  return (pumpSettings.reference * 255.0) / adc; //состояние батареи
}
//-----------------------------------Параметры-----------------------------------------
uint16_t _convert_vcc_hv(uint8_t adc) //параметры
{
  return adc * pumpSettings.reference * pumpSettings.k_delitel / 255; //считем высокое перед выводом
}
//-----------------------------------Параметры-----------------------------------------
void parameters(void) //параметры
{
  uint8_t time_out = 0; //счетчик авто-выхода
  scr = 0; //разрешаем обновление экрана

  while (1) {
    data_convert(); //преобразование данных

    if (!scr) {
      scr = 1; //запрещаем обновление экрана

#if TIME_OUT_PARAM
      if (++time_out > TIME_OUT_PARAM) {
        scr = 0; //разрешаем обновления экрана
        return;
      }
#endif

      _bat_check(); //опрос батареи

      clrScr(); //очистка экрана
      task_bar(P_PARAM); //отрисовываем фон

      print(P_BAT, LEFT, 8); //Батарея:
      printNumF(_convert_vcc_bat(bat_adc), 2, RIGHT, 8, 46, 4, 48); //напряжение акб
      print(P_ADC_BAT, LEFT, 16); //Знач.АЦП:
      printNumI(bat_adc, RIGHT, 16); //значение ацп акб

      print(P_HV_PUMP, LEFT, 24); //Накачка ВВ:
      printNumI(_convert_vcc_hv(hv_adc), RIGHT, 24);//напряжение высокого
      print(P_PUMP_SPEED, LEFT, 32); //Скорость:
      printNumI(speed_hv, RIGHT, 32);//скорость накачки

      print(P_REFERENCE, LEFT, 40); //Опорное:
      printNumF(pumpSettings.reference, 2, RIGHT, 40, 46, 4, 48); //опорное напряжение

      showScr(); //вывод буфера на экран
    }

    switch (check_keys()) {
#if DEBUG_RETURN
      case 1: //Down key hold
      case 4: //Up key hold
        debug(); //отладка
        time_out = 0; //сбрасывает авто-выход
        scr = 0; //разрешаем обновление экрана
        break;
#endif

      case 6: //hold select key //выход
        scr = 0; //разрешаем обновление экрана
        return; //выход
    }
  }
}
//-----------------------------------Отладка---------------------------------
void debug(void) //отладка
{
  uint8_t time_out = 0;
  uint8_t n = 0; //курсор
  boolean set = ((uint8_t)pumpSettings.geiger_time < 100) ? 1 : 0; //режим знака счета времени
  scr = 0; //разрешаем обновление экрана

  while (1) {
    data_convert(); //преобразование данных

    if (!scr) {
      scr = 1; //запрещаем обновление экрана

#if TIME_OUT_DEBUG
      if (++time_out > TIME_OUT_DEBUG) {
        setings_save(1); //сохраняем настройки преобразователя
        error_switch = 0; //сбрасываем указатель ошибки
        scr = 0; //разрешаем обновления экрана
        return;
      }
#endif

      clrScr(); //очистка экрана
      task_bar(D_DEBUG); //отрисовываем фон

      _bat_check(); //опрос батареи

      print(D_BAT, LEFT, 8); //БАТ
      printNumF(_convert_vcc_bat(bat_adc), 2, 20, 8, 46, 4, 48); //напряжение акб
      print(D_ADC_BAT, 46, 8); //АЦП
      printNumI(bat_adc, RIGHT, 8); //значение ацп акб
      print(D_PUMP_SPEED, 0, 16); //СКР
      printNumI(speed_hv, 20, 16); //скорость накачки
      print(D_HV_PUMP, 46, 16); //ВВ
      printNumI(_convert_vcc_hv(hv_adc), RIGHT, 16); //напряжение высокого

      printNumI(pumpSettings.wdt_period, 20, 24); //период
      printNumF(pumpSettings.geiger_time, set, RIGHT, 24, 46, 4, 32); //счёт
      printNumF(pumpSettings.reference, 2, 20, 32, 46, 4, 48); //опорное напряжение
      printNumI(pumpSettings.puls, RIGHT, 32); //длинна импульса
      printNumI(pumpSettings.k_delitel, 20, 40); //коэффициент делителя
      printNumI(pumpSettings.ADC_value, RIGHT, 40); //значение АЦП для преобразователя

      for (uint8_t i = 0; i < 6; i++) {
        if (n == i) invertText(true); //включаем инверсию
        switch (i) {
          case 0: print(D_WDT_PER, LEFT, 24); break; //ПЕР
          case 1: print(D_GEIGER_TIME, 46, 24); break; //СЧ
          case 2: print(D_REFERENCE, LEFT, 32); break; //ОПР
          case 3: print(D_PULS_LEN, 46, 32); break; //ИМП
          case 4: print(D_COEF_DIV, LEFT, 40); break; //КДЛ
          case 5: print(D_PUMP_ADC, 46, 40); break; //АЦП
        }
        if (n == i) invertText(false); //выключаем инверсию
      }
      showScr(); //вывод буфера на экран
    }

    switch (check_keys()) {

      case 1: //Down key hold
      case 4: //Up key hold
        if (n == 1) {
          set = !set;
          pumpSettings.geiger_time = (uint8_t)pumpSettings.geiger_time;
        }
        break;

      case 3: //Up key //нажатие
        switch (n) {
          case 0: if (pumpSettings.wdt_period < MAX_WDT_PERIOD) pumpSettings.wdt_period++; break; //период
          case 1: if (pumpSettings.geiger_time < MAX_GEIGER_TIME) pumpSettings.geiger_time += (set) ? 0.1 : 1; if ((uint8_t)pumpSettings.geiger_time == 100) set = 0;  break; //счет
          case 2: if (pumpSettings.reference < 1.50) pumpSettings.reference += 0.01; break; //прибавляем опорное напряжение
          case 3: if (pumpSettings.puls < 30) pumpSettings.puls++; break; //прибавляем длинну импульса
          case 4: if (pumpSettings.k_delitel < 1500) pumpSettings.k_delitel++; break; //прибавляем коэффициент делителя
          case 5: if (pumpSettings.ADC_value < 254) pumpSettings.ADC_value++; break; //прибавляем значение АЦП для преобразователя
        }
        time_out = 0; //сбрасывает авто-выход
        scr = 0; //разрешаем обновление экрана
        break;

      case 2: //Down key //нажатие
        switch (n) {
          case 0: if (pumpSettings.wdt_period > MIN_WDT_PERIOD) pumpSettings.wdt_period--; break; //период
          case 1: if (pumpSettings.geiger_time > MIN_GEIGER_TIME) pumpSettings.geiger_time -= (set) ? 0.1 : 1; if ((uint8_t)pumpSettings.geiger_time == 100) set = 1; break; //счет
          case 2: if (pumpSettings.reference > 0.50) pumpSettings.reference -= 0.01; break; //убавляем опорное напряжение
          case 3: if (pumpSettings.puls > 1) pumpSettings.puls--; break; //убавляем длинну импульса
          case 4: if (pumpSettings.k_delitel > 10) pumpSettings.k_delitel--; break; //убавляем коэффициент делителя
          case 5: if (pumpSettings.ADC_value > 10) pumpSettings.ADC_value--; break; //убавляем значение АЦП для преобразователя
        }
        time_out = 0; //сбрасывает авто-выход
        scr = 0; //разрешаем обновление экрана
        break;

      case 5: //select key //нажатие
        if (++n > 5) n = 0;
        time_out = 0; //сбрасывает авто-выход
        scr = 0; //разрешаем обновление экрана
        break;

      case 6: //hold select key ///выход в настройки
        setings_save(1); //сохраняем настройки преобразователя
        error_switch = 0; //сбрасываем указатель ошибки
        scr = 0; //разрешаем обновление экрана
        return;
    }
  }
}
//------------------------------------Отрисовка пунктов------------------------------------------------------
void _setings_item_switch(boolean set, boolean inv, uint8_t num, uint8_t pos) //отрисовка пунктов
{
  uint8_t pos_row = (pos << 3) + 8; //переводим позицию в номер строки

  if (inv) invertText(true); //включаем инверсию

  switch (num) {
    case 0: //Сон
      switch (set) {
        case 0: print(S_ITEM_SLEEP, LEFT, pos_row); break; //Сон:
        case 1: if (mainSettings.sleep_switch < 2) print(ALL_SWITCH_OFF, RIGHT, pos_row); else printNumI(mainSettings.time_sleep, RIGHT, pos_row); break;
      }
      break;

    case 1: //Подсветка
      switch (set) {
        case 0: print(S_ITEM_LIGHT, LEFT, pos_row); break; //Подсветка:
        case 1: if (!mainSettings.sleep_switch) print(S_SWITCH_MANUAL, RIGHT, pos_row); else printNumI(mainSettings.time_bright, RIGHT, pos_row); break;
      }
      break;

    case 2: //Контраст
      switch (set) {
        case 0: print(S_ITEM_CONTRAST, LEFT, pos_row); break; //Контраст:
        case 1: printNumI(mainSettings.contrast, RIGHT, pos_row); break;
      }
      break;

    case 3: //Вспышки
      switch (set) {
        case 0: print(S_ITEM_FLASHES, LEFT, pos_row); break; //Вспышки:
        case 1: if (!mainSettings.rad_flash) print(ALL_SWITCH_OFF, RIGHT, pos_row); else if (mainSettings.rad_flash == 2) print(S_SWITCH_MANUAL_EXCEPT_SLEEP, RIGHT, pos_row); else print(ALL_SWITCH_ON, RIGHT, pos_row); break;
      }
      break;

    case 4: //Громкость
      switch (set) {
        case 0: print(S_ITEM_VOLUME, LEFT, pos_row); break; //Громкость:
        case 1: printNumI(mainSettings.volume, RIGHT, pos_row); break;
      }
      break;

    case 5: //Щелчки
      switch (set) {
        case 0: print(S_ITEM_CLICKS, LEFT, pos_row); break; //Щелчки:
        case 1: if (!mainSettings.buzz_switch) print(ALL_SWITCH_OFF, RIGHT, pos_row); else if (mainSettings.buzz_switch == 1) print(ALL_SWITCH_ON, RIGHT, pos_row); else print(S_SWITCH_BACK_1, RIGHT, pos_row); break;
      }
      break;

    case 6: //Зв.Кнопок
      switch (set) {
        case 0: print(S_ITEM_BUTT_SOUND, LEFT, pos_row); break; //Зв.Кнопок:
        case 1: if (mainSettings.knock_disable) print(ALL_SWITCH_OFF, RIGHT, pos_row); else print(ALL_SWITCH_ON, RIGHT, pos_row); break;
      }
      break;

    case 7: //Разн.зам
      switch (set) {
        case 0: print(S_ITEM_DIFF_MEASUR, LEFT, pos_row); break; //Разн.зам:
        case 1: printNumI(pgm_read_byte(&diff_measuring[mainSettings.measur_pos]), RIGHT, pos_row); break;
      }
      break;

    case 8: //Сигма
      switch (set) {
        case 0: print(S_ITEM_SIGMA, LEFT, pos_row); break; //Сигма:
        case 1: printNumI(mainSettings.sigma_pos + 1, RIGHT, pos_row); break;
      }
      break;

    case 9: //Поиск
      switch (set) {
        case 0: print(S_ITEM_SEARCH, LEFT, pos_row); break; //Поиск:
        case 1: if (mainSettings.search_pos != 8) printNumI(pgm_read_word(&search_time[mainSettings.search_pos]), RIGHT, pos_row); else print(S_SWITCH_AUTO, RIGHT, pos_row); break;
      }
      break;

    case 10: //Ед.измер
      switch (set) {
        case 0: print(S_ITEM_UNITS, LEFT, pos_row); break; //Ед.измер:
        case 1: if (!mainSettings.rad_mode) print(UNIT_UR, RIGHT, pos_row); else print(UNIT_USV, RIGHT, pos_row); break;
      }
      break;

    case 11: //Тревога Ф
      switch (set) {
        case 0: print(S_ITEM_ALARM_BACK, LEFT, pos_row); break; //Тревога Ф:
        case 1: if (!mainSettings.alarm_back) print(ALL_SWITCH_OFF, RIGHT, pos_row); else if (mainSettings.alarm_back == 1) print(S_SWITCH_SOUND, RIGHT, pos_row); else if (mainSettings.alarm_back == 2) print(S_SWITCH_VIBRO, RIGHT, pos_row); else print(S_SWITCH_SOUND_VIBRO, RIGHT, pos_row); break;
      }
      break;

    case 12: //Порог Ф1
      switch (set) {
        case 0: print(S_ITEM_ALARM_THRESHOLD_BACK_1, LEFT, pos_row); break; //Порог Ф1:
        case 1: printNumI(mainSettings.warn_level_back, RIGHT, pos_row); break;
      }
      break;

    case 13: //Порог Ф2
      switch (set) {
        case 0: print(S_ITEM_ALARM_THRESHOLD_BACK_2, LEFT, pos_row); break; //Порог Ф2:
        case 1: printNumI(mainSettings.alarm_level_back, RIGHT, pos_row); break;
      }
      break;

    case 14: //Тревога Д
      switch (set) {
        case 0: print(S_ITEM_ALARM_DOSE, LEFT, pos_row); break; //Тревога Д:
        case 1: if (!mainSettings.alarm_dose) print(ALL_SWITCH_OFF, RIGHT, pos_row); else if (mainSettings.alarm_dose == 1) print(S_SWITCH_SOUND, RIGHT, pos_row); else if (mainSettings.alarm_dose == 2) print(S_SWITCH_VIBRO, RIGHT, pos_row); else print(S_SWITCH_SOUND_VIBRO, RIGHT, pos_row); break;
      }
      break;

    case 15: //Порог Д1
      switch (set) {
        case 0: print(S_ITEM_ALARM_THRESHOLD_DOSE_1, LEFT, pos_row); break; //Порог Д1:
        case 1: printNumI(mainSettings.warn_level_dose, RIGHT, pos_row); break;
      }
      break;

    case 16: //Порог Д2
      switch (set) {
        case 0: print(S_ITEM_ALARM_THRESHOLD_DOSE_2, LEFT, pos_row); break; //Порог Д2:
        case 1: printNumI(mainSettings.alarm_level_dose, RIGHT, pos_row); break;
      }
      break;

#if USE_UART
    case 17:
      switch (set) {
        case 0: print(S_ITEM_UART_SET, LEFT, pos_row); break; //Порт:
        case 1: if (!UCSR0B) print(ALL_SWITCH_OFF, RIGHT, pos_row); else printNumI(UART_BAUND, RIGHT, pos_row); break;
      }

      break;
#endif
  }
  invertText(false); //выключаем инверсию
}
//------------------------------------Прибавление данных------------------------------------------------------
void _setings_data_up(uint8_t pos) //прибавление данных
{
  switch (pos)
  {
    case 0: //Сон
      switch (mainSettings.sleep_switch) {
        case 0: mainSettings.sleep_switch = 2; _LIGHT_ON(); break;
        case 1: mainSettings.sleep_switch = 2; mainSettings.time_bright = 5; break;
        case 2: if (mainSettings.time_sleep < 250) mainSettings.time_sleep += 5; break;
      }
      break;
    case 1: //Подсветка
      switch (mainSettings.sleep_switch) {
        case 0: mainSettings.sleep_switch = 1; LIGHT_ON; break;
        case 1: if (mainSettings.time_bright < 250) mainSettings.time_bright += 5; break;
        case 2: if (mainSettings.time_bright < mainSettings.time_sleep - 5) mainSettings.time_bright += 5; break;
      }
      break;
    case 2: if (mainSettings.contrast < 127) mainSettings.contrast++; setContrast(mainSettings.contrast); break; //Контраст
    case 3: switch (mainSettings.rad_flash) { //Вспышки
        case 0: mainSettings.rad_flash = 1; break;
        case 1: mainSettings.rad_flash = 2; break;
      }
      break;
    case 4: if (mainSettings.volume < 10) mainSettings.volume++; break; //Громкость
    case 5: switch (mainSettings.buzz_switch) { //Щелчки
        case 0: mainSettings.buzz_switch = 1; break;
        case 1: mainSettings.buzz_switch = 2; break;
      }
      break;
    case 6: mainSettings.knock_disable = 0; break; //Зв.кнопок

    case 7: if (mainSettings.measur_pos < 9) mainSettings.measur_pos++; break; //Разн.зам
    case 8: if (mainSettings.sigma_pos < 2) mainSettings.sigma_pos++; else mainSettings.sigma_pos = 0; break; //Сигма
    case 9: if (mainSettings.search_pos < 8) mainSettings.search_pos++; else mainSettings.search_pos = 0; break; //Поиск
    case 10: mainSettings.rad_mode = 1; break; //Ед.измер

    case 11: if (mainSettings.alarm_back < 3) mainSettings.alarm_back++; break; //Тревога Ф
    case 12: if (mainSettings.warn_level_back < 300) mainSettings.warn_level_back += 5; else mainSettings.warn_level_back = 30; break; //Порог Ф1
    case 13: if (mainSettings.alarm_level_back < 500) mainSettings.alarm_level_back += 10; else if (mainSettings.alarm_level_back < 1000) mainSettings.alarm_level_back += 50; else if (mainSettings.alarm_level_back < 65000) mainSettings.alarm_level_back += 100; else mainSettings.alarm_level_back = 300; break; //Порог Ф2
    case 14: if (mainSettings.alarm_dose < 3) mainSettings.alarm_dose++; break; //Тревога Д
    case 15: if (mainSettings.warn_level_dose < 300) mainSettings.warn_level_dose += 5; else mainSettings.warn_level_dose = 10; break; //Порог Д1
    case 16: if (mainSettings.alarm_level_dose < 500) mainSettings.alarm_level_dose += 10; else if (mainSettings.alarm_level_dose < 1000) mainSettings.alarm_level_dose += 50; else if (mainSettings.alarm_level_dose < 65000) mainSettings.alarm_level_dose += 100; else mainSettings.alarm_level_dose = 300; break; //Порог Д2
#if USE_UART
    case 17: if (!UCSR0B) dataChannelInit(); else dataChannelEnd(); break; //uart
#endif
  }
}
//------------------------------------Убавление данных------------------------------------------------------
void _setings_data_down(uint8_t pos) //убавление данных
{
  switch (pos)
  {
    case 0: if (mainSettings.time_sleep > 10) { //Сон
        mainSettings.time_sleep -= 5;
        if (mainSettings.time_bright == mainSettings.time_sleep) mainSettings.time_bright -= 5;
      }
      else if (mainSettings.sleep_switch == 2) mainSettings.sleep_switch = 1; break;
    case 1:
      if (mainSettings.time_bright > 5) mainSettings.time_bright -= 5; else mainSettings.sleep_switch = 0; break; //Подсветка
    case 2: if (mainSettings.contrast > 0) mainSettings.contrast--; setContrast(mainSettings.contrast); break; //Контраст
    case 3: switch (mainSettings.rad_flash) { //Вспышки
        case 1: mainSettings.rad_flash = 0; break;
        case 2: mainSettings.rad_flash = 1; break;
      }
      break;
    case 4: if (mainSettings.volume > 1) mainSettings.volume--; break; //Громкость
    case 5: switch (mainSettings.buzz_switch) { //Щелчки
        case 1:  break;
        case 2: mainSettings.buzz_switch = 1; break;
      }
      break;
    case 6: mainSettings.knock_disable = 1; break; //Зв.кнопок

    case 7: if (mainSettings.measur_pos > 0) mainSettings.measur_pos--;  break; //Разн.зам
    case 8: if (mainSettings.sigma_pos > 0) mainSettings.sigma_pos--; else mainSettings.sigma_pos = 2; break; //Сигма
    case 9: if (mainSettings.search_pos > 0) mainSettings.search_pos--; else mainSettings.search_pos = 8; break; //Поиск
    case 10: mainSettings.rad_mode = 0; break; //Ед.измер

    case 11: if (mainSettings.alarm_back > 0) mainSettings.alarm_back--; break; //Тревога Ф
    case 12: if (mainSettings.warn_level_back > 30) mainSettings.warn_level_back -= 5; else mainSettings.warn_level_back = 300; break; //Порог Ф1
    case 13: if (mainSettings.alarm_level_back > 1000) mainSettings.alarm_level_back -= 100; else if (mainSettings.alarm_level_back > 500) mainSettings.alarm_level_back -= 50; else if (mainSettings.alarm_level_back > 300) mainSettings.alarm_level_back -= 10; else mainSettings.alarm_level_back = 65000; break; //Порог Ф2
    case 14: if (mainSettings.alarm_dose > 0) mainSettings.alarm_dose--; break; //Тревога Д
    case 15: if (mainSettings.warn_level_dose > 10) mainSettings.warn_level_dose -= 5; else mainSettings.warn_level_dose = 300; break; //Порог Д1
    case 16: if (mainSettings.alarm_level_dose > 1000) mainSettings.alarm_level_dose -= 100; else if (mainSettings.alarm_level_dose > 500) mainSettings.alarm_level_dose -= 50; else if (mainSettings.alarm_level_dose > 300) mainSettings.alarm_level_dose -= 10; else mainSettings.alarm_level_dose = 65000; break; //Порог Д2
#if USE_UART
    case 17: if (!UCSR0B) dataChannelInit(); else dataChannelEnd(); break; //uart
#endif
  }
}
//------------------------------------Настройки------------------------------------------------------
void setings(void) //настройки
{
  uint8_t n = 0; //позиция
  uint8_t c = 0; //курсор
  boolean set = 0; //разрешение на настройку
  uint8_t time_out = 0; //таймер автовыхода
  scr = 0; //разрешаем обновления экрана

  while (1) {
    data_convert(); //преобразование данных

    //+++++++++++++++++++   вывод информации на экран  +++++++++++++++++++++++++
    if (!scr) {
      scr = 1; //запрещаем обновления экрана

#if TIME_OUT_SETTINGS
      if (++time_out > TIME_OUT_SETTINGS) {
        setings_save(0); //сохраняем настройки
        scr = 0; //разрешаем обновления экрана
        return;
      }
#endif

      clrScr(); // Очистка экрана
      task_bar(S_SETINGS); //отрисовываем фон

      for (uint8_t i = 0; i < 5; i++) { //отсчет строк
        for (uint8_t r = 0; r < 2; r++) { //отсчет позиции
          boolean inv = (i == c && r == set); //если курсор на нужной строке
          _setings_item_switch(r, inv, n - c + i, i); //отрисовываем пункты настроек
        }
      }
      showScr(); //вывод буфера на экран
    }
    //+++++++++++++++++++++  опрос кнопок  +++++++++++++++++++++++++++
    switch (check_keys()) {
      case 1: //Down key hold //вкл/выкл посветки
        fast_light(); //быстрое включение посветки
        break;

      case 2: //Down key //вниз
        switch (set) {
          case 0:
            if (n < 16 + USE_UART) { //изменяем позицию
              n++;
              if (c < 4) c++; //изменяем положение курсора
            }
            else { //иначе начало списка
              n = 0;
              c = 0;
            }
            break;
          case 1: _setings_data_down(n); break; //убавление данных
        }
        time_out = 0; //сбрасываем авто-выход
        scr = 0; //разрешаем обновления экрана
        break;

      case 3: //Up key  //вверх
        switch (set) {
          case 0:
            if (n > 0) { //изменяем позицию
              n--;
              if (c > 0) c--; //изменяем положение курсора
            }
            else { //иначе конец списка
              n = 16 + USE_UART;
              c = 4;
            }
            break;
          case 1: _setings_data_up(n); break; //прибавление данных
        }
        time_out = 0; //сбрасываем авто-выход
        scr = 0; //разрешаем обновления экрана
        break;

      case 4: //Up key hold //вкл/выкл фонарика
        FLASH_SWITCH; //быстрое включение фонарика
        break;

      case 5: //select key //выбор
        set = (set) ? 0 : 1;
        time_out = 0; //сбрасываем авто-выход
        scr = 0; //разрешаем обновления экрана
        break;

      case 6: //hold select key //выход из настроек
        setings_save(0); //сохраняем настройки
        scr = 0; //разрешаем обновления экрана
        return;
    }
  }
}
//------------------------------------Отрисовка пунктов------------------------------------------------------
void _menu_item_switch(boolean inv, uint8_t num, uint8_t pos) //отрисовка пунктов
{
  uint8_t pos_row = (pos << 3) + 8; //переводим позицию в номер строки

  if (inv) {
    _screen_line(0, 84, 0, 0, pos_row); //рисуем линию
    invertText(true); //включаем инверсию
  }

  switch (num) {
    case 0: print(MAIN_BACK_DOSE, CENTER, pos_row); break; //Фон / Доза
    case 1: print(MAIN_SEARCH, CENTER, pos_row); break; //Режим поиска
    case 2: print(MAIN_MEASUR, CENTER, pos_row); break; //Замер бета
    case 3: print(MAIN_LOGBOOK, CENTER, pos_row); break; //Журнал
    case 4: print(MAIN_SETINGS, CENTER, pos_row); break; //Настройки
    case 5: print(MAIN_PARAM, CENTER, pos_row); break; //Параметры
    case 6: print(MAIN_POWER_DOWN, CENTER, pos_row); break; //Выключение
  }
  invertText(false); //выключаем инверсию
}
//------------------------------------Меню------------------------------------------------------
void menu(void) //меню
{
  uint8_t n = 0; //позиция
  uint8_t c = 0; //курсор
  uint8_t time_out = 0; //таймер автовыхода

  sleep_disable = 1; //запрещаем сон
  scr = 0; //разрешаем обновления экрана

  while (1) {
    data_convert(); //преобразование данных

    //+++++++++++++++++++   вывод информации на экран  +++++++++++++++++++++++++
    if (!scr) {
      scr = 1; //запрещаем обновления экрана

#if TIME_OUT_MENU
      if (++time_out > TIME_OUT_MENU) {
        if (cnt_pwr > mainSettings.time_bright) cnt_pwr = mainSettings.time_bright + 1;
        sleep_disable = 0; //разрешаем сон
        scr = 0; //разрешаем обновления экрана
        return;
      }
#endif

      clrScr(); // Очистка экрана
      task_bar(MAIN_MENU); //отрисовываем фон

      for (uint8_t i = 0; i < 5; i++) _menu_item_switch((i == c) ? 1 : 0, n - c + i, i); //отрисовываем пункты настроек
      showScr(); //вывод буфера на экран
    }
    //+++++++++++++++++++++  опрос кнопок  +++++++++++++++++++++++++++
    switch (check_keys()) {
      case 1: //Down key hold //вкл/выкл посветки
        fast_light(); //быстрое включение посветки
        break;

      case 2: //Down key //вниз
        if (n < 6) { //изменяем позицию
          n++;
          if (c < 4) c++; //изменяем положение курсора
        }
        else { //иначе начало списка
          n = 0;
          c = 0;
        }
        time_out = 0; //сбрасываем авто-выход
        scr = 0; //разрешаем обновления экрана
        break;

      case 3: //Up key  //вверх
        if (n > 0) { //изменяем позицию
          n--;
          if (c > 0) c--; //изменяем положение курсора
        }
        else { //иначе конец списка
          n = 6;
          c = 4;
        }
        time_out = 0; //сбрасываем авто-выход
        scr = 0; //разрешаем обновления экрана
        break;

      case 4: //Up key hold //вкл/выкл фонарика
        FLASH_SWITCH; //быстрое включение фонарика
        break;

      case 5: //select key //выбор
        switch (n) {
          case 0:
            sleep_disable = 0; //разрешаем сон
            scr = 0; //разрешаем обновления экрана
            return;
          case 1: search_menu(); break;
          case 2: measur_menu(); break;
          case 3: logbook(); break;
          case 4: setings(); break;
          case 5: parameters(); break;
          case 6: power_down(); scr = 0; return;
        }
        time_out = 0; //сбрасываем авто-выход
        scr = 0; //разрешаем обновления экрана
        break;

      case 6: //hold select key //выход к главным экранам
        sleep_disable = 0; //разрешаем сон
        scr = 0; //разрешаем обновления экрана
        return;
    }
  }
}
//------------------------------------Отрисовка пунктов настроек журнала------------------------------------------------------
void _logbook_settings(boolean inv, uint8_t num, uint8_t pos) //отрисовка пунктов настроек журнала
{
  uint8_t pos_row = (pos << 3) + 8; //переводим позицию в номер строки

  if (inv) {
    _screen_line(0, 84, 0, 0, pos_row); //рисуем линию
    invertText(true); //включаем инверсию
  }

  switch (num) {
    case 0: print(L_SETINGS_ALARM, LEFT, pos_row); if (bookSettings.logbook_alarm) print(ALL_SWITCH_ON, RIGHT, pos_row); else print(ALL_SWITCH_OFF, RIGHT, pos_row); break; //Тревога
    case 1: print(L_SETINGS_WARN, LEFT, pos_row); if (bookSettings.logbook_warn) print(ALL_SWITCH_ON, RIGHT, pos_row); else print(ALL_SWITCH_OFF, RIGHT, pos_row); break; //Опасность
    case 2: print(L_SETINGS_MEASUR, LEFT, pos_row); if (bookSettings.logbook_measur) print(ALL_SWITCH_ON, RIGHT, pos_row); else print(ALL_SWITCH_OFF, RIGHT, pos_row); break; //Замеры бета
    case 3: print(L_SETINGS_CLEAR, CENTER, pos_row); break; //Очистить
  }
  invertText(false); //выключаем инверсию
}
//------------------------------------Отрисовка пунктов журнала------------------------------------------------------
void _logbook_item_switch(boolean inv, uint8_t num, uint8_t pos) //отрисовка пунктов журнала
{
  uint8_t pos_row = (pos << 3) + 8; //переводим позицию в номер строки

  if (inv) {
    _screen_line(0, 84, 0, 0, pos_row); //рисуем линию
    invertText(true); //включаем инверсию
  }

  switch (num) {
    case 0: print(L_ITEM_ALARM, CENTER, pos_row); if (bookSettings.logbook_alarm == 2) print(L_ITEM_ASTER, RIGHT, pos_row); break; //Тревога
    case 1: print(L_ITEM_WARN, CENTER, pos_row); if (bookSettings.logbook_warn == 2) print(L_ITEM_ASTER, RIGHT, pos_row); break; //Опасность
    case 2: print(L_ITEM_MEASUR, CENTER, pos_row); if (bookSettings.logbook_measur == 2) print(L_ITEM_ASTER, RIGHT, pos_row); break; //Замеры бета
    case 3: print(L_ITEM_ERRORS, CENTER, pos_row); if (error_switch) print(L_ITEM_ASTER, RIGHT, pos_row); break; //Ошибки
    case 4: print(L_ITEM_SETINGS, CENTER, pos_row); break; //Настройки
  }
  invertText(false); //выключаем инверсию
}
//------------------------------------Отрисовка информации журнала------------------------------------------------------
void _logbook_data_switch(boolean inv, uint8_t num, uint8_t pos, uint8_t data_num) //отрисовка информации журнала
{
  uint8_t pos_row = (pos << 3) + 8; //переводим позицию в номер строки

  uint8_t temp_byte = _data_read_byte(num, 200 + data_num * 10);
  uint32_t temp_dword = _data_read_dword(num, (uint16_t)240 + data_num * 40);

  if (inv) {
    _screen_line(0, 84, 0, 0, pos_row); //рисуем линию
    invertText(true); //включаем инверсию
  }

  if (temp_byte) {
#if LOGBOOK_RETURN
    switch (data_num) {
      case 0:
      case 1:
        if (temp_byte == 2) print(L_DATA_DOSE, LEFT, pos_row); //ДОЗА
        else print(L_DATA_BACK, LEFT, pos_row); //ФОН
        _init_rads_unit(0, temp_dword, 1, 4, RIGHT, pos_row, temp_byte - 1, RIGHT, pos_row); //единицы фона/дозы
        break;
      case 2:
        printNumI(temp_byte, LEFT, pos_row, 2); //время замера
        print(L_DATA_MINS, 12, pos_row); //м
#if TYPE_MEASUR_LOGBOOK
        _init_small_couts_per_cm2((float)temp_dword / temp_byte, pos_row); //отрисовываем ч/см2
#else
        _init_rads_unit(0, temp_dword, 1, 4, RIGHT, pos_row, 0, RIGHT, pos_row); //отрисовываем мкР/ч
#endif
        break;
      case 3:
        print(L_DATA_ERROR_NUM, LEFT, pos_row); //Ошибка #
        printNumI(temp_byte, RIGHT, pos_row); //номер ошибки
        break;
    }
#else
    printNumI(temp_byte, LEFT, pos_row, 2); //вркмя замера
    print(L_DATA_MINS, 12, pos_row); //м
#if TYPE_MEASUR_LOGBOOK
    _init_small_couts_per_cm2((float)temp_dword / temp_byte, pos_row); //отрисовываем ч/см2
#else
    _init_rads_unit(0, temp_dword, 1, 4, RIGHT, pos_row, 0, RIGHT, pos_row); //отрисовываем мкР/ч
#endif
#endif
  }
  else print(L_DATA_NULL, CENTER, pos_row); //- пусто -

  invertText(false); //выключаем инверсию
}
//------------------------------------Очистка журнала------------------------------------------------------
void _logbook_data_clear(void) //очистка журнала
{
  uint16_t byte_data = 200; //устанавливаем начальную позицию
  uint8_t dataByte_read[10] = {0, 0, 0, 0, 0, 0, 0, 0, 0, 0}; //буфер обнуления заглавлений данных
  for (uint8_t i = 0; i < 4; i++) {
    EEPROM_UpdateBlock((uint16_t)&dataByte_read, byte_data, sizeof(dataByte_read)); //стираем заглавления
    byte_data += 10; //переходим на следующий блок
  }
}
//------------------------------------Обновление журнала------------------------------------------------------
void _logbook_data_update(uint8_t data_num, uint8_t num, uint32_t data) //обновление журнала
{
  uint8_t dataByte_read[10]; //временный буфер данных
  uint32_t dataDword_read[10]; //временный буфер данных

  uint16_t byte_data = 200 + data_num * 10; //находим запрашиваемую позицию
  uint16_t dword_data = 240 + data_num * 40; //находим запрашиваемую позицию

  EEPROM_ReadBlock((uint16_t)&dataByte_read, byte_data, sizeof(dataByte_read)); //считываем информацию во временный буфер
  EEPROM_ReadBlock((uint16_t)&dataDword_read, dword_data, sizeof(dataDword_read)); //считываем информацию во временный буфер

  for (uint8_t b = 9; b; b--) dataByte_read[b] = dataByte_read[b - 1]; //смещаяем информацию в буфере
  dataByte_read[0] = num; //добавляем в начало буфера новое значение
  for (uint8_t d = 9; d; d--) dataDword_read[d] = dataDword_read[d - 1]; //смещаяем информацию в буфере
  dataDword_read[0] = data; //добавляем в начало буфера новое значение

  EEPROM_UpdateBlock((uint16_t)&dataByte_read, byte_data, sizeof(dataByte_read)); //записываем в память временный буфер
  EEPROM_UpdateBlock((uint16_t)&dataDword_read, dword_data, sizeof(dataDword_read)); //записываем в память временный буфер
}
//-----------------------------------Чтение журнала byte---------------------------------
uint8_t _data_read_byte(uint8_t num_byte, uint16_t data_byte) //чтение журнала byte
{
  uint8_t dataByte_read[10]; //временный буфер данных
  EEPROM_ReadBlock((uint16_t)&dataByte_read, data_byte, sizeof(dataByte_read)); //считываем информацию во временный буфер
  return dataByte_read[num_byte]; //возвращаем запрошенные данные
}
//-----------------------------------Чтение журнала dword---------------------------------
uint32_t _data_read_dword(uint8_t num_byte, uint16_t data_byte) //чтение журнала dword
{
  uint32_t dataDword_read[10]; //временный буфер данных
  EEPROM_ReadBlock((uint16_t)&dataDword_read, data_byte, sizeof(dataDword_read)); //считываем информацию во временный буфер
  return dataDword_read[num_byte]; //возвращаем запрошенные данные
}
//------------------------------------Журнал------------------------------------------------------
void logbook(void) //журнал
{
#if LOGBOOK_RETURN
  uint8_t n = 0; //позиция
  uint8_t c = 0; //курсор
  uint8_t p = 0; //пункт
  boolean err_sw = 0; //переключение подрежима ошибок
  uint8_t max_item = 4; //максимум пунктов
  uint8_t time_out = 0; //таймер автовыхода

  scr = 0; //разрешаем обновления экрана

  while (1) {
    data_convert(); //преобразование данных

    //+++++++++++++++++++   вывод информации на экран  +++++++++++++++++++++++++
    if (!scr) {
      scr = 1; //запрещаем обновления экрана

#if TIME_OUT_LOGBOOK
      if (++time_out > TIME_OUT_LOGBOOK) {
        scr = 0; //разрешаем обновления экрана
        return;
      }
#endif

      clrScr(); // Очистка экрана
      task_bar(L_LOGBOOK); //отрисовываем фон

      if (!err_sw) {
        for (uint8_t i = 0; i < 5; i++) {
          switch (p) {
            case 0: _logbook_item_switch((i == c) ? 1 : 0, n - c + i, i); break; //отрисовываем пункты настроек
            case 5: _logbook_settings((i == c) ? 1 : 0, n - c + i, i); break; //отрисовываем пункты настроек
            default: _logbook_data_switch((i == c) ? 1 : 0, n - c + i, i, p - 1); break; //отрисовывам информацию
          }
        }
      }
      else _init_error_messege(_data_read_byte(n, 230), _data_read_dword(n, 360)); //отрисовка информации
      showScr(); //вывод буфера на экран
    }
    //+++++++++++++++++++++  опрос кнопок  +++++++++++++++++++++++++++
    switch (check_keys()) {
      case 1: //Down key hold //вкл/выкл посветки
        fast_light(); //быстрое включение посветки
        break;

      case 2: //Down key //вниз
        if (n < max_item) { //изменяем позицию
          n++;
          if (c < 4) c++; //изменяем положение курсора
        }
        else { //иначе начало списка
          n = 0;
          c = 0;
        }
        time_out = 0; //сбрасываем авто-выход
        scr = 0; //разрешаем обновления экрана
        break;

      case 3: //Up key  //вверх
        if (n > 0) { //изменяем позицию
          n--;
          if (c > 0) c--; //изменяем положение курсора
        }
        else { //иначе конец списка
          n = max_item;
          c = (max_item < 4) ? max_item : 4;
        }
        time_out = 0; //сбрасываем авто-выход
        scr = 0; //разрешаем обновления экрана
        break;

      case 4: //Up key hold //вкл/выкл фонарика
        FLASH_SWITCH; //быстрое включение фонарика
        break;

      case 5: //select key //выбор
        switch (p) {
          case 0:
            p = n + 1;
            n = c = 0;
            max_item = (p != 5) ? 9 : 3;
            switch (p) {
              case 1: if (bookSettings.logbook_alarm) bookSettings.logbook_alarm = 1; break; //сбрасываем флаг журнала тревоги
              case 2: if (bookSettings.logbook_warn) bookSettings.logbook_warn = 1; break; //сбрасываем флаг журнала предупрежлений
              case 3: if (bookSettings.logbook_measur) bookSettings.logbook_measur = 1; break; //сбрасываем флаг журнала замеров
              case 4: if (error_switch) error_switch = 0; break; //сбрасываем флаг журнала ошибок
            }
            break;
          case 4: err_sw = (err_sw) ? 0 : 1; break; //переходим на предпросмотр ошибки
          case 5:
            switch (n) {
              case 0: bookSettings.logbook_alarm = (bookSettings.logbook_alarm) ? 0 : 1; break; //вкл/выкл журнала тревоги
              case 1: bookSettings.logbook_warn = (bookSettings.logbook_warn) ? 0 : 1; break; //вкл/выкл журнала предупреждений
              case 2: bookSettings.logbook_measur = (bookSettings.logbook_measur) ? 0 : 1; break; //вкл/выкл журнала замеров
              case 3: data_reset(2); break;
            }
            break;
        }
        time_out = 0; //сбрасываем авто-выход
        scr = 0; //разрешаем обновления экрана
        break;

      case 6: //hold select key //выход к главным экранам
        scr = 0; //разрешаем обновления экрана
        switch (p) {
          case 0: return;
          case 5: setings_save(2); n = c = p - 1; p = 0; max_item = 4; break; //сохраняем настройки
          default: n = c = p - 1; p = err_sw = 0; max_item = 4; break;
        }
        break;
    }
  }
#else
  uint8_t n = 0; //позиция
  uint8_t c = 0; //курсор
  uint8_t time_out = 0; //таймер автовыхода

  scr = 0; //разрешаем обновления экрана

  while (1) {
    data_convert(); //преобразование данных

    //+++++++++++++++++++   вывод информации на экран  +++++++++++++++++++++++++
    if (!scr) {
      scr = 1; //запрещаем обновления экрана

#if TIME_OUT_LOGBOOK
      if (++time_out > TIME_OUT_LOGBOOK) {
        scr = 0; //разрешаем обновления экрана
        return;
      }
#endif

      clrScr(); // Очистка экрана
      task_bar(L_LOGBOOK); //отрисовываем фон

      for (uint8_t i = 0; i < 5; i++) _logbook_data_switch((i == c) ? 1 : 0, n - c + i, i, 2); //отрисовывам информацию
      showScr(); //вывод буфера на экран
    }
    //+++++++++++++++++++++  опрос кнопок  +++++++++++++++++++++++++++
    switch (check_keys()) {
      case 1: //Down key hold //вкл/выкл посветки
        fast_light(); //быстрое включение посветки
        break;

      case 2: //Down key //вниз
        if (n < 9) { //изменяем позицию
          n++;
          if (c < 4) c++; //изменяем положение курсора
        }
        else { //иначе начало списка
          n = 0;
          c = 0;
        }
        time_out = 0; //сбрасываем авто-выход
        scr = 0; //разрешаем обновления экрана
        break;

      case 3: //Up key  //вверх
        if (n > 0) { //изменяем позицию
          n--;
          if (c > 0) c--; //изменяем положение курсора
        }
        else { //иначе конец списка
          n = 9;
          c = 4;
        }
        time_out = 0; //сбрасываем авто-выход
        scr = 0; //разрешаем обновления экрана
        break;

      case 4: //Up key hold //вкл/выкл фонарика
        FLASH_SWITCH; //быстрое включение фонарика
        break;

      case 5: //select key //выбор
        data_reset(2); //очистка журнала
        time_out = 0; //сбрасываем авто-выход
        scr = 0; //разрешаем обновления экрана
        break;

      case 6: //hold select key //выход к главным экранам
        scr = 0; //разрешаем обновления экрана
        return;
    }
  }
#endif
}
//-----------------------------------Вкл/выкл подсветки---------------------------------
void fast_light(void) //вкл/выкл подсветки
{
  if (!mainSettings.sleep_switch) { //если сон выключен
    if (light_switch) {
      _LIGHT_OFF(); //выключаем подсветку, если была включена настройками
    }
    else {
      _LIGHT_ON(); //включаем подсветку
    }
  }
}
//---------------------------------Отрисовка сообщения об ошибке---------------------------------------
void _init_error_messege(uint8_t err, uint32_t data) //отрисовка сообщения об ошибке
{
  clrScr(); //очистка экрана

  invertText(true);
  print(E_ERROR, CENTER, 0); //- ОШИБКА -
  invertText(false);

  switch (err) {
    case 0:
      print(E_ERROR_NULL, CENTER, 16); //пусто
      break;

    case 2:
      print(E_DATA_OVERLOAD, CENTER, 16); //Перегрузка
      print(E_DATA_PUMP, CENTER, 24); //преобразователя!
      print(E_DATA_SPEED, 18, 32); //СКР:
      printNumI(data, 43, 32);
      break;

    case 3:
      print(E_DATA_SHOT_CIRCUIT, CENTER, 16); //Короткое зам.
      print(E_DATA_PUMP, CENTER, 24); //преобразователя!
      print(E_DATA_HV, 18, 32); //НАП:
      printNumI(_convert_vcc_hv(data), 43, 32);
      break;

    case 4:
      print(E_DATA_LOW, CENTER, 16); //Низкое
      print(E_DATA_VOLTAGE, CENTER, 24); //напряжение
      print(E_DATA_PUMP, CENTER, 32); //преобразователя!
      print(E_DATA_HV, 18, 40); //НАП:
      printNumI(_convert_vcc_hv(data), 43, 40);
      break;

    case 5:
      print(E_DATA_NO_ACCOUNT, CENTER, 24); //Нет счета!
      break;
  }
  showScr(); //вывод буфера на экран
}
//---------------------------------Сообщение об ошибке---------------------------------------
void error_messege(void) //сообщение об ошибке
{
#if LOGBOOK_RETURN
  if (error_switch == 2 && !alarm_switch && !error_massege) { //если время вышло, выводим ошибку
#else
  if (error_switch && !alarm_switch && !error_massege) { //если время вышло, выводим ошибку
#endif
    error_massege = 1; //сбрасываем флаг отображения ошибки

    sleep_out(); //просыпаемся если спали
    buzz_save(); //запрещаем щелчки


#if LOGBOOK_RETURN
    _init_error_messege(_data_read_byte(0, 230), _data_read_dword(0, 360));
#else
    clrScr(); //очистка экрана

    melody_switch = 0; //сбрасываем переключатель мелодии

    invertText(true);
    print(E_ERROR, CENTER, 0); //- ОШИБКА -
    invertText(false);

    switch (error_switch) {
      case 0:
        print(E_ERROR_NULL, CENTER, 16); //пусто
        break;

      case 2:
        print(E_DATA_OVERLOAD, CENTER, 16); //Перегрузка
        print(E_DATA_PUMP, CENTER, 24); //преобразователя!
        print(E_DATA_SPEED, 18, 32); //СКР:
        printNumI(speed_hv, 43, 32);
        break;

      case 3:
        print(E_DATA_SHOT_CIRCUIT, CENTER, 16); //Короткое зам.
        print(E_DATA_PUMP, CENTER, 24); //преобразователя!
        print(E_DATA_HV, 18, 32); //НАП:
        printNumI(_convert_vcc_hv(hv_adc), 43, 32);
        break;

      case 4:
        print(E_DATA_LOW, CENTER, 16); //Низкое
        print(E_DATA_VOLTAGE, CENTER, 24); //напряжение
        print(E_DATA_PUMP, CENTER, 32); //преобразователя!
        print(E_DATA_HV, 18, 40); //НАП:
        printNumI(_convert_vcc_hv(hv_adc), 43, 40);
        break;

      case 5:
        print(E_DATA_NO_ACCOUNT, CENTER, 24); //Нет счета!
        break;
    }
    showScr(); //вывод буфера на экран
#endif

    for (timer_millis = ERROR_MASSEGE_TIME; timer_millis;) { //ждем
      data_convert(); //преобразование данных
      //==================================================================
      _melody_chart(error_sound, SAMPLS_ERROR); //играем волшебную мелодию
      //==================================================================
      if (check_keys()) {
        error_switch = 0; //сбрасываем флаг ошибки
        break;
      }
    }
    buzz_ret(); //считываем настроку щелчков
    cnt_pwr = 0; //обнуляем счетчик сна
#if LOGBOOK_RETURN
    error_switch = 1; //сбрасываем указатель ошибки
#else
    error_switch = 0; //сбрасываем указатель ошибки
#endif
    scr = 0; //разрешаем обновления экрана
  }
}
//---------------------------------------Стирание статистики--------------------------------------------------
void _statistic_erase(void) //стирание статистики
{
  cur_dose_cell = 0; //сбрасываем текущую ячейку
  for (uint16_t cell = 510; cell < 1024; cell++) EEPROM_UpdateByte(cell, 0); //стираем заглавления времени
}
//---------------------------------------Чтение статистики--------------------------------------------------
void statistic_read(void) //чтение статистики
{
  uint32_t maxData = 0; //максимальное значение ячейки
  uint32_t tempData = 0;
  for (uint8_t c = 0; c < 64; c++) {
    uint16_t search_cell = 510 + (4 * c); //находим запрашиваемую позицию
    EEPROM_ReadBlock((uint16_t)&tempData, search_cell, sizeof(tempData));
    if (maxData < tempData) { //если буфер меньше ячейки
      maxData = tempData; //записываем в буфер значение ячейки
    }
    else {
      cur_dose_cell = c; //устанавливаем последнюю ячейку
      break; //завершаем поиск
    }
  }
  if (maxData) { //если в буфере есть информация
    uint16_t time_cell = 510 + (4 * (cur_dose_cell - 1)); //находим запрашиваемую позицию
    EEPROM_ReadBlock((uint16_t)&tempData, time_cell, sizeof(tempData));
    time_save = tempData; //считываем время
    uint16_t dose_cell = 766 + (4 * (cur_dose_cell - 1)); //находим запрашиваемую позицию
    EEPROM_ReadBlock((uint16_t)&tempData, dose_cell, sizeof(tempData));
    rad_dose_save = tempData; //считываем дозу
  }
}
//--------------------------------------Обновление статистики-----------------------------------------------
void statistic_update(void) //обновление статистики
{
  uint16_t time_cell = 510 + (4 * cur_dose_cell); //находим запрашиваемую позицию
  EEPROM_UpdateBlock((uint16_t)&time_save, time_cell, sizeof(time_save)); //записываем время
  uint16_t dose_cell = 766 + (4 * cur_dose_cell); //находим запрашиваемую позицию
  EEPROM_UpdateBlock((uint16_t)&rad_dose_save, dose_cell, sizeof(rad_dose_save)); //записываем дозу
  if (cur_dose_cell < 63) cur_dose_cell++; else cur_dose_cell = 0; //меняем ячейку
}
//------------------------------------Чтение состояния щелчков----------------------------------------------
void buzz_ret(void) //чтение состояния щелчков
{
  mainSettings.buzz_switch = temp_buzz_switch;
}
//------------------------------------Чтение состояния щелчков----------------------------------------------
void buzz_save(void) //чтение состояния щелчков
{
  temp_buzz_switch = mainSettings.buzz_switch;
  mainSettings.buzz_switch = 0;
}
//---------------------------------------Сброс текущей дозы--------------------------------------------
void data_reset(uint8_t sw) //сброс текущей дозы
{
  uint8_t time_out = 0; //счетчик тайм-аута
  uint8_t state = 0; //курсор

  sleep_disable = 1; //запрещаем сон

  clrScr(); //очистка экрана
  switch (sw) {
    case 0: //текущая доза
      print(R_RESET, CENTER, 8); //Сбросить
      print(R_CURRENT_DOSE, CENTER, 16); //текущую дозу?
      break;

    case 1: //накопленная доза
      print(R_RESET, CENTER, 8); //Сбросить
      print(R_ALL_DOSE, CENTER, 16); //общую дозу?
      break;

    case 2: //журнал
      print(R_CLEAR, CENTER, 8); //Очистить
      print(R_ALL_LOGBOOK, CENTER, 16); //весь журнал?
      break;
  }

  while (1) {
    data_convert(); //преобразование данных

    if (!scr) {
      scr = 1; //запрещаем обновление экрана
#if TIME_OUT_DATA
      if (++time_out > TIME_OUT_DATA) {
        if (cnt_pwr > mainSettings.time_bright) cnt_pwr = mainSettings.time_bright + 1;
        sleep_disable = 0; //разрешаем сон
        scr = 0; //разрешаем обновления экрана
        return;
      }
#endif

      choice_menu(state); //меню выбора
      showScr(); //вывод буфера на экран
    }

    switch (check_keys()) {

      case 2: //Down key
        state = 0;
        time_out = 0; //сбрасывает авто-выход
        scr = 0; //разрешаем обновления экрана
        break;
      case 3: //Up key
        state = 1;
        time_out = 0; //сбрасывает авто-выход
        scr = 0; //разрешаем обновления экрана
        break;

      case 5: //select key
        switch (state) {
          case 1:
            clrScr(); //очистка экрана
            switch (sw) {
              case 0: //текущая доза
                rad_dose_save += rad_dose - rad_dose_old;
                rad_sum = 0;
                rad_dose = 0;
                rad_dose_old = 0;

                time_save += time_sec - time_save_old;
                time_save_old = 0;
                time_total = 0;
                time_sec = 0;

                stat_upd_tmr = 0;

                alarm_dose_wait = 0;
                warn_dose_wait = 0;

                print(R_SUCC_CURRENT_DOSE, CENTER, 16); //Текущая доза
                print(R_SUCC_RESET, CENTER, 24); //сброшена!
                break;

              case 1: //накопленная доза
                time_save = 0;
                rad_dose_save = 0;
                _statistic_erase(); //стирание статистики
                rad_dose_old = rad_dose;

                print(R_SUCC_ALL_DOSE, CENTER, 16); //Общая доза
                print(R_SUCC_RESET, CENTER, 24); //сброшена!
                break;

              case 2: //журнал
                _logbook_data_clear(); //очистка журнала

                print(R_SUCC_LOGBOOK, CENTER, 16); //Журнал
                print(R_SUCC_CLEAR, CENTER, 24); //очищен!
                break;
            }
            _waint(MASSEGE_TIME); //ждем
            sleep_disable = 0; //разрешаем сон
            return;

          case 0:
            sleep_disable = 0; //разрешаем сон
            return;
        }
        break;
    }
  }
}
//---------------------------------------Сохранить настройки--------------------------------------------
void setings_save(uint8_t sw) //сохранить настройки
{
  boolean state = 0; //курсор
  uint8_t time_out = 0; //таймер автовыхода

  switch (sw) {
    case 0:
      if (!(checkDataMemory((uint8_t*)&mainSettings, sizeof(mainSettings), EEPROM_BLOCK_CRC_MAIN))) return;
      break;
#if DEBUG_RETURN
    case 1:
      if (!(checkDataMemory((uint8_t*)&pumpSettings, sizeof(pumpSettings), EEPROM_BLOCK_CRC_PUMP))) return;
      break;
#endif
#if LOGBOOK_RETURN
    case 2:
      if (!(checkDataMemory((uint8_t*)&bookSettings, sizeof(bookSettings), EEPROM_BLOCK_CRC_BOOK))) return;
      break;
#endif
  }

  clrScr(); //очистка экрана
  print(W_SAVE, CENTER, 8); //Сохранить
  print(W_SETINGS, CENTER, 16); //настройки?

  while (1) {
    data_convert(); //преобразование данных

    if (!scr) {
      scr = 1; //сбрасываем флаг
#if TIME_OUT_SETTINGS
      if (++time_out > TIME_OUT_SETTINGS) {
        switch (sw) {
          case 0: EEPROM_ReadBlock((uint16_t)&mainSettings, EEPROM_BLOCK_SETTINGS_MAIN, sizeof(mainSettings)); break; //считываем настройки из памяти
#if DEBUG_RETURN || PUMP_READ_MEM
          case 1: EEPROM_ReadBlock((uint16_t)&pumpSettings, EEPROM_BLOCK_SETTINGS_PUMP, sizeof(pumpSettings)); break; //считываем настройки из памяти
#endif
#if LOGBOOK_RETURN
          case 2: EEPROM_ReadBlock((uint16_t)&bookSettings, EEPROM_BLOCK_SETTINGS_BOOK, sizeof(bookSettings)); break; //считываем настройки из памяти
#endif
        }
        scr = 0; //разрешаем обновления экрана
        return; //выходим
      }
#endif

      choice_menu(state); //меню выбора
      showScr(); //вывод буфера на экран
    }

    switch (check_keys()) {
      case 2: //Down key
        state = 0;
        time_out = 0; //сбрасывает авто-выход
        scr = 0; //разрешаем обновления экрана
        break;
      case 3: //Up key
        state = 1;
        time_out = 0; //сбрасывает авто-выход
        scr = 0; //разрешаем обновления экрана
        break;

      case 5: //select key
        switch (state) {
          case 1:
            clrScr(); //очистка экрана
            print(W_SETINGS_SUCC, CENTER, 16); //Настройки
            print(W_SAVE_SUCC, CENTER, 24); //Сохранены!
            switch (sw) {
              case 0: updateData((uint8_t*)&mainSettings, sizeof(mainSettings), EEPROM_BLOCK_SETTINGS_MAIN, EEPROM_BLOCK_CRC_MAIN); BUZZ_VOL_SET(mainSettings.volume); break; //обновляем настройки
#if DEBUG_RETURN
              case 1: updateData((uint8_t*)&pumpSettings, sizeof(pumpSettings), EEPROM_BLOCK_SETTINGS_PUMP, EEPROM_BLOCK_CRC_PUMP); break; //обновляем настройки
#endif
#if LOGBOOK_RETURN
              case 2: updateData((uint8_t*)&bookSettings, sizeof(bookSettings), EEPROM_BLOCK_SETTINGS_PUMP, EEPROM_BLOCK_CRC_BOOK); break; //обновляем настройки
#endif
            }
            _waint(MASSEGE_TIME); //ждем
            scr = 0; //разрешаем обновления экрана
            return;

          case 0:
            switch (sw) {
              case 0: EEPROM_ReadBlock((uint16_t)&mainSettings, EEPROM_BLOCK_SETTINGS_MAIN, sizeof(mainSettings)); break; //считываем настройки из памяти
#if DEBUG_RETURN || PUMP_READ_MEM
              case 1: EEPROM_ReadBlock((uint16_t)&pumpSettings, EEPROM_BLOCK_SETTINGS_PUMP, sizeof(pumpSettings)); break; //считываем настройки из памяти
#endif
#if LOGBOOK_RETURN
              case 2: EEPROM_ReadBlock((uint16_t)&bookSettings, EEPROM_BLOCK_SETTINGS_BOOK, sizeof(bookSettings)); break; //считываем настройки из памяти
#endif
            }
            scr = 0; //разрешаем обновления экрана
            return;
        }
        break;
    }
  }
}
//---------------------------------------Меню выбора--------------------------------------------
void choice_menu(boolean n) //меню выбора
{
  for (uint8_t i = 0; i < 2; i++) { //отрисовка пунктов
    if (n == i) invertText(true); //включаем инверсию
    switch (i) {
      case 0: print(ALL_NO, LEFT, 32); break; //нет
      case 1: print(ALL_YES, RIGHT, 32); break; //да
    }
    invertText(false); //выключаем инверсию
  }
}
// -----------------------------Отрисовка линий точности---------------------------------------
void _screen_line(uint8_t up_bar, uint8_t down_bar, uint8_t rent_bar, uint8_t start_bar, uint8_t pos_bar) //отрисовка линий
{
  for (uint8_t i = 0; i < down_bar; i++) { //рисуем верхнюю шкалу
    drawBitmap(i + start_bar, pos_bar, (uint8_t*)pgm_read_word(&_scale[rent_bar]), 1, 8); //шкала готовности общая
  }
  for (uint8_t i = down_bar; i < up_bar; i++) { //рисуем нижнюю шкалу
    drawBitmap(i + start_bar, pos_bar, (uint8_t*)pgm_read_word(&_scale[2]), 1, 8); //шкала готовности верхняя
  }
}
//----------------------------------Инициализация прочерков------------------------------------------------------
void _init_dash_unit(boolean type, uint8_t char_all, uint8_t char_unit, uint8_t num_x, uint8_t num_y) //инициализация прочерков
{
  for (uint8_t i = 0; i < char_all; i++) {
    if (type) setFont(MediumNumbers); //установка шрифта
    print("-", (num_x == RIGHT) ? 84 - char_all * cfont.x_size - char_unit + i * cfont.x_size : num_x + i * cfont.x_size, num_y);
  }
}
//----------------------------------Инициализация значений------------------------------------------------------
void _init_rads_unit(boolean type, uint32_t num, uint8_t divisor, uint8_t char_all, uint8_t num_x, uint8_t num_y, boolean unit, uint8_t unit_x, uint8_t unit_y, boolean dash) //инициализация значений
{
  uint8_t _ptr = (mainSettings.rad_mode) ? PATTERNS_SVH : PATTERNS_RH;

  for (uint8_t i = 0; i < _ptr; i++) { //перебираем патерны
    if (num <= pgm_read_dword(&pattern_all[mainSettings.rad_mode][i][0]) * divisor) { //если есть совпадение
      uint8_t char_unit = (_rads_unit(pgm_read_dword(&pattern_all[mainSettings.rad_mode][i][3]), unit, unit_x, unit_y) - 1) * cfont.x_size; //устанавливаем единицы измерения
      if (type) setFont(MediumNumbers); //установка шрифта
#if (TYPE_CHAR_FILL > 44)
      if (dash) _init_dash_unit(type, char_all, char_unit, num_x, num_y);
      else printNumF(float(num) / pgm_read_dword(&pattern_all[mainSettings.rad_mode][i][2]), pgm_read_dword(&pattern_all[mainSettings.rad_mode][i][1]), (num_x == RIGHT) ? 84 - char_all * cfont.x_size - char_unit : num_x, num_y, 46, char_all, TYPE_CHAR_FILL); //строка 1
#else
      if (dash) _init_dash_unit(type, char_all, char_unit, num_x, num_y);
      else printNumF(float(num) / pgm_read_dword(&pattern_all[mainSettings.rad_mode][i][2]), pgm_read_dword(&pattern_all[mainSettings.rad_mode][i][1]), (num_x == RIGHT) ? 84 - char_all * cfont.x_size - char_unit : num_x, num_y, 46, char_all, (type) ? TYPE_CHAR_FILL : 32); //строка 1
#endif
      break;
    }
  }
}
//----------------------------------Единицы измерения------------------------------------------------------
uint8_t _rads_unit(boolean set, boolean unit, uint8_t unit_x, uint8_t unit_y) //Единицы измерения
{
  switch (mainSettings.rad_mode)
  {
    case 0:
      //мкР
      switch (set) {
        case 0:
          switch (unit) {
            case 0: print(UNIT_UR_H, unit_x, unit_y); return sizeof(UNIT_UR_H); //строка 2 мкР/ч
            case 1: print(UNIT_UR, unit_x, unit_y); return sizeof(UNIT_UR); //строка 2 мкР
          }
          break;

        case 1:
          switch (unit) {
            case 0: print(UNIT_MR_H, unit_x, unit_y); return sizeof(UNIT_MR_H); //строка 2 мР/ч
            case 1: print(UNIT_MR, unit_x, unit_y); return sizeof(UNIT_MR); //строка 2 мР
          }
          break;
      }
      break;

    case 1:
      //мкЗв
      switch (set) {
        case 0:
          switch (unit) {
            case 0: print(UNIT_USV_H, unit_x, unit_y); return sizeof(UNIT_USV_H); //строка 2 мкЗ/ч
            case 1: print(UNIT_USV, unit_x, unit_y); return sizeof(UNIT_USV); //строка 2 мкЗ
          }
          break;

        case 1:
          switch (unit) {
            case 0: print(UNIT_MSV_H, unit_x, unit_y); return sizeof(UNIT_MSV_H); //строка 2 мЗ/ч
            case 1: print(UNIT_MSV, unit_x, unit_y); return sizeof(UNIT_MSV); //строка 2 мЗ
          }
          break;
      }
      break;
  }
}
//----------------------------------Индикация тревоги------------------------------------------------
void _alarm_init(uint8_t waint, uint8_t alarm) //индикация тревоги
{
  if (waint) drawBitmap(60, 0, beep_alt_waint_img, 7, 8); //если ждем понижения фона
  else {
    switch (alarm) //если тревога запрещена
    {
      case 0: drawBitmap(60, 0, buzz_alt_off_img, 7, 8); break; //тревога выключена
      case 1: drawBitmap(60, 0, buzz_alt_on_img, 7, 8); break; //только звук
      case 2: drawBitmap(60, 0, beep_alt_vibro_img, 7, 8); break; //только вибрация
      case 3: drawBitmap(60, 0, beep_alt_img, 8, 8); break; //звук и вибрация
    }
  }
}
//----------------------------------Шапка экрана------------------------------------------------
void task_bar(const char *title) //шапка экрана
{
  _screen_line(0, 84, 0, 0, 0); //рисуем линию
  drawBitmap(70, 0, font_bat_img, 12, 8); //устанавлваем фон батареи
  drawBitmap(70, 0, bat_alt_img, bat * 2, 8); //отображаем состояние батареи

  invertText(true);
  print(title, 1, 0);
  invertText(false);
}
//----------------------------------Отрисовка точности------------------------------------------------
void _init_accur_percent(uint8_t num) //отрисовка точности
{
  drawBitmap(54, 8, plus_minus_img, 3, 8); //±
  setFont(TinyNumbersDown); //установка шрифта
  printNumI(num, 58, 7, 2, 48); //точность
  drawBitmap(66, 8, percent_img, 6, 8); //%
  setFont(TinyNumbersDown); //установка шрифта
  printNumI(mainSettings.sigma_pos + 1, 75, 7); //сигма
  drawBitmap(79, 8, sigma_img, 5, 8); //σ
}
//----------------------------------Отрисовка предела фона------------------------------------------------
void _init_back_bar(uint32_t num) //отрисовка предела фона
{
  drawBitmap(0, 24, back_scale_img, 84, 8);
  for (uint8_t i = 0; i < PATTERNS_SCALE; i++) { //перебираем патерны
    uint32_t max_back = (uint32_t)pgm_read_word(&back_scale[i][0]) * 100; //устанавливаем максимум
    if (num <= max_back) { //если есть совпадение
      _screen_line(0, map(num, 0, max_back, (i) ? pgm_read_word(&back_scale[i - 1][1]) : 1, pgm_read_word(&back_scale[i][1])), 3, 2, 24); //рисуем шкалу
      return; //возврат
    }
  }
  _screen_line(0, 80, 3, 2, 24); //иначе рисуем полную шкалу
}
//----------------------------------Главные экраны------------------------------------------------------
void main_screen(void)
{
  static uint8_t back_mode; //переключатель режима фон

  //+++++++++++++++++++   вывод информации на экран  +++++++++++++++++++++++++
  if (!scr) { //обновление дисплея
    scr = 1; //сброс флага

    clrScr(); //очистка экрана

    //рисуем шапку экрана
    switch (scr_mode) {
      case 0: task_bar(MAIN_SCREEN_BACK); _alarm_init(alarm_back_wait + warn_back_wait, mainSettings.alarm_back); break;  //режим текущего фона
      case 1: task_bar(MAIN_SCREEN_DOSE); _alarm_init(0, mainSettings.alarm_dose); break;  //режим накопленной дозы
    }

    drawBitmap(55, 0, font_alarm_img, 5, 8); //устанавлваем фон звуков
    drawBitmap(43, 0, font_sound_img, 4, 8); //устанавлваем фон тревоги
    if (mainSettings.buzz_switch && !mainSettings.knock_disable) drawBitmap(47, 0, buzz_alt_on_img, 7, 8); //если щелчки и зв.кнопок включен
    else if (mainSettings.buzz_switch) drawBitmap(47, 0, buzz_alt_img, 7, 8); //если щелчки включены и зв.кнопок выключен
    else if (!mainSettings.knock_disable) drawBitmap(47, 0, beep_alt_waint_img, 7, 8); //если щелчки выключены и зв.кнопок включен
    else drawBitmap(47, 0, buzz_alt_off_img, 7, 8); //иначе выключено все

#if LOGBOOK_RETURN
    static boolean n; //переключатель мигания
    if (error_switch) {
      if (n) drawBitmap(27, 0, error_ico_img, 14, 8); //ERR
      n = (n) ? 0 : 1;
    }
    else {
      if (bookSettings.logbook_alarm == 2 || bookSettings.logbook_warn == 2 || bookSettings.logbook_measur == 2) {
        if (n) drawBitmap(32, 0, logbook_ico_img, 9, 8); //logbook
        n = (n) ? 0 : 1;
      }
      else if (bookSettings.logbook_alarm == 1 || bookSettings.logbook_warn == 1 || bookSettings.logbook_measur == 1) drawBitmap(32, 0, logbook_ico_img, 9, 8); //logbook
    }
#endif

#if COEF_DEBUG //отладка коэффициента
    switch (scr_mode)
    {
      case 0:
        invertText(true);
        setFont(TinyNumbersDown); //установка шрифта
        printNumF(now, 2, 19, 0, 46, 5, 43); //строка 1
        setFont(TinyNumbersDown); //установка шрифта
        printNumF(debug_coef, 2, 40, 0, 46, 5, 43); //строка 2
        invertText(false);
        break;
    }
#endif

    //===========================================================//
    switch (scr_mode) { //отрисовываем выбранный экран
      case 0: //режим измерения текущего фона
        switch (alarm_switch) {
          case 0:
#if BACK_SCALE_RETURN
            _init_back_bar(rad_back);
#else
            _screen_line(map(geiger_time_now, 0, BUFF_LENGTHY, 5, 82), map(mid_time_now, 0, MID_BUFF_LENGTHY, 5, 82), 1, 1, 24); //шкалы точности и усреднения
#endif
            break;
          case 3: _init_alarm_massage(0, 24); break; //предупреждение
        }

        switch (back_mode) {
          case 0: for (uint8_t i = 4; i < 80; i++) graf_lcd(map(rad_buff[(i >> 1) - 1], 0, maxLevel_back, 0, 15), i, 15, 2); break; //инициализируем график
          case 1: //максимальный и средний фон
            print(MAIN_SCREEN_BACK_MIN, 0, 32); //строка 2 мин:
            _init_rads_unit(0, rad_min, 1, 4, RIGHT, 32, 0, RIGHT, 32, (accur_percent > RAD_ACCUR_START) ? 1 : 0); //строка 2 минимальный

            print(MAIN_SCREEN_BACK_MAX, 0, 40); //строка 3 макс:
            _init_rads_unit(0, rad_max, 1, 4, RIGHT, 40, 0, RIGHT, 40); //строка 3 максимальный
            break;
        }

        _init_accur_percent(accur_percent); //отрисовка точности
        _init_rads_unit(1, rad_back, 1, 4, 1, 8, 0, 54, 16); //строка 1 основной фон

        break;
      //===========================================================//
      case 1: //режим накопленной дозы

        switch (dose_mode)
        {
          case 0: //текущая доза
            setFont(TinyNumbersDown); //установка шрифта
            printNumI(time_sec / 60 / 60 / 24, 34, 23, 2, 48); //дней
            drawBitmap(42, 24, day_img, 8, 8); //дн
            setFont(TinyNumbersDown); //установка шрифта
            printNumI((time_sec / 60 / 60) % 24, 54, 23, 2, 48); //часов
            drawBitmap(62, 24, colon_img, 3, 8); //:
            setFont(TinyNumbersDown); //установка шрифта
            printNumI((time_sec / 60) % 60, 65, 23, 2, 48); //минут
            drawBitmap(73, 24, colon_img, 3, 8); //:
            setFont(TinyNumbersDown); //установка шрифта
            printNumI(time_sec % 60, 76, 23, 2, 48); //секунд

            switch (alarm_switch) {
              case 0: _screen_line(0, map(stat_upd_tmr, 0, STAT_UPD_TIME, 5, 82), 1, 1, 32); break; //шкала времени до сохранения дозы
              case 4: _init_alarm_massage(0, 32); break; //предупреждение
            }

            _init_rads_unit(1, rad_dose, 10, 5, 1, 8, 1, 66, 16); //строка 1 текущая доза
            print(MAIN_SCREEN_CURRENT_DOSE_ALL, 0, 40); //строка 2 всего
            _init_rads_unit(0, rad_dose_save, 10, 5, RIGHT, 40, 1, RIGHT, 40); //строка 2 сохранённая доза
            break;

          case 1: //общая накопленная доза и время
            printNumI(time_save / 60 / 60 / 24, 8, 40, 2, 48);
            print(MAIN_SCREEN_DOSE_DAYS, 20, 40);
            printNumI((time_save / 60 / 60) % 24, 32, 40, 2, 48);
            print(MAIN_SCREEN_DOSE_HOURSE, 44, 40);
            printNumI((time_save / 60) % 60, 56, 40, 2, 48);
            print(MAIN_SCREEN_DOSE_MINS, 68, 40);

            print(MAIN_SCREEN_DOSE_ACCUM, CENTER, 24); //накоплено
            print(MAIN_SCREEN_DOSE_JUST_OVER, 16, 30); //всего за:

            _init_rads_unit(1, rad_dose_save, 10, 5, 1, 8, 1, 66, 16); //строка 1 сохранённая доза
            break;
        }
        break;
    }
    showScr(); //вывод буфера на экран
  }

  //+++++++++++++++++++++  опрос кнопок  +++++++++++++++++++++++++++
  switch (check_keys()) {
    case 1: //Down key hold //вкл/выкл посветки
      if (!alarm_switch) fast_light(); //быстрое включение посветки
      break;

    case 2: //Down key //сброс
      switch (alarm_switch) { //режим тревоги
        case 0:
          switch (scr_mode) { //основные экраны
            case 0: //сбрасываем фон
              for (uint8_t i = 0; i < BUFF_LENGTHY; i++) rad_buff[i] = 0; //очищаем буфер фона
              scan_buff = 0; //очищаем буфер счета
              back_time_now = geiger_time_now = 0; //сбрасываем счетчик накопления импульсов в буфере
              mid_time_now = 0; //сбрасываем рассчет среднего
              rad_back = 0; //сбрасываем фон

              switch (back_mode) {
                case 1: //сбрасываем максимальный фон и средний фон
                  rad_min = 0; //сбрасываем среднее значение фона
                  rad_max = 0; //сбрасываем максимальное значение фона
                  break;
              }
              break;

            case 1: data_reset(dose_mode); break; //сбрасываем дозу и время
          }
          break;
        case 3: warn_back_wait = 1; alarm_switch = 0; _vibro_off(); buzz_ret(); break; //фон
        case 4: warn_dose_wait = rad_dose; alarm_switch = 0; _vibro_off(); buzz_ret(); break; //доза
      }
      scr = 0; //разрешаем обновления экрана
      break;

    case 3: //Up key //доп.действие
      switch (alarm_switch) { //режим тревоги
        case 0:
          switch (scr_mode) { //основные экраны
            case 0: back_mode = !back_mode; break; //переключаем экраны фона
            case 1: dose_mode = !dose_mode; break; //переключаем экраны дозы
          }
          break;
        case 3: warn_back_wait = 1; alarm_switch = 0; _vibro_off(); buzz_ret(); break; //фон
        case 4: warn_dose_wait = rad_dose; alarm_switch = 0; _vibro_off(); buzz_ret(); break; //доза
      }
      scr = 0; //разрешаем обновления экрана
      break;

    case 4: //Up key hold //вкл/выкл фонарика
      if (!alarm_switch) FLASH_SWITCH; //быстрое включение фонарика
      break;

    case 5: //Select key //выбор режима
      switch (alarm_switch) { //режим тревоги
        case 0: scr_mode = !scr_mode; break; //переключение фон/доза
        case 3: warn_back_wait = 1; alarm_switch = 0; _vibro_off(); buzz_ret(); break; //фон
        case 4: warn_dose_wait = rad_dose; alarm_switch = 0; _vibro_off(); buzz_ret(); break; //доза
      }
      scr = 0; //разрешаем обновления экрана
      break;

    case 6: //hold select key //настройки
      if (!alarm_switch) menu(); //если нет тревоги
      scr = 0; //разрешаем обновления экрана
      break;
  }
}
