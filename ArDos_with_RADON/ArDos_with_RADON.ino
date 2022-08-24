/*Arduino IDE 1.8.13
  Версия программы RADON v3.9.5 low_pwr release 24.08.22 специально для проекта ArDos
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
#include "settings.h"
#include "display.h"
#include "resources.c"
#include "connection.h"
#include "uartSender.h"

//-------------Для разработчиков-------------
const float ALARM_AUTO_GISTERESIS = (1.00 - (ALARM_AUTO_GIST / 100.00)); //инвертируем проценты
const float IMP_PWR_GISTERESIS = (1.00 - (IMP_PWR_GIST / 100.00)); //инвертируем проценты

const uint16_t buzz_time = ((uint32_t)FREQ_BUZZ * (uint32_t)TIME_BUZZ) / 1000; //пересчитываем частоту и время щелчков в циклы таймера
const uint16_t buzz_freq = (F_CPU / SOUND_PRESCALER) / FREQ_BUZZ; //устанавливаем частоту таймера щелчков
uint16_t buzz_vol; //устанавливаем громкость щелчков

uint8_t GEIGER_CYCLE; //минимум секунд для начала расчетов
uint8_t GEIGER_MASS; //максимум секунд для окончания смещения коэффициентов

//пищалка старт/стоп
#define BUZZ_START        cnt_puls = buzz_time; PRR &= ~(1 << 3); ICR1 = buzz_freq; OCR1A = buzz_vol; TCNT1 = 0; TIMSK1 = 0b00000011
#define BUZZ_VOL_SET(vol) buzz_vol = (buzz_freq / 2) / 10 * vol;
#define SOUND_START(freq) PRR &= ~(1 << 3); ICR1 = freq; OCR1A = ((freq / 2) / 10 * mainSettings.volume); TCNT1 = 0; TIMSK1 = 0b00000011
#define _SOUND_STOP        TIMSK1 = 0b00000000; PRR |= (1 << 3)

//вспышки старт/стоп
#define _RAD_FLASH_ON  {PRR &= ~(1 << 5); TIMSK0 = 0b00000001; RAD_FLASH_ON;}
#define _RAD_FLASH_OFF {TIMSK0 = 0b00000000; PRR |= (1 << 5); RAD_FLASH_OFF;}

//перевод напряжения в значение ацп
#define LOW_BAT_POWER (uint8_t)((DEFAULT_REFERENCE * 255.0) / LOW_BAT_POWER_V)
#define LOW_BAT_STAT (uint8_t)((DEFAULT_REFERENCE * 255.0) / LOW_BAT_STAT_V)
#define MIN_BAT (uint8_t)((DEFAULT_REFERENCE * 255.0) / MIN_BAT_V)
#define MAX_BAT (uint8_t)((DEFAULT_REFERENCE * 255.0) / MAX_BAT_V)

volatile uint16_t main_buff; //основная переменная для счета импульсов от датчика
uint16_t scan_buff; //переменная сканирования импульсов
uint16_t search_buff[76]; //буфер поиска
uint16_t rad_buff[BUFF_LENGTHY]; //массив секундных замеров для расчета фона
uint32_t rad_mid_buff[MID_BUFF_LENGTHY]; //массив секундных замеров для усреднения фона

#define TIME_FACT_0  1 //секундные интервалы 0
#define TIME_FACT_1  3 //секундные интервалы 1
#define TIME_FACT_2  5 //секундные интервалы 2
#define TIME_FACT_3  7 //секундные интервалы 3
#define TIME_FACT_4  9 //секундные интервалы 4
#define TIME_FACT_5  11 //секундные интервалы 5
#define TIME_FACT_6  13 //секундные интервалы 6
#define TIME_FACT_7  15 //секундные интервалы 7
#define TIME_FACT_8  17 //секундные интервалы 8
#define TIME_FACT_9  19 //секундные интервалы 9
#define TIME_FACT_10 21 //секундные интервалы 10
#define TIME_FACT_11 23 //секундные интервалы 11
#define TIME_FACT_12 25 //секундные интервалы 12
#define TIME_FACT_13 27 //секундные интервалы 13
#define TIME_FACT_14 29 //секундные интервалы 14
#define TIME_FACT_15 31 //секундные интервалы 15
#define TIME_FACT_16 33 //секундные интервалы 16
#define TIME_FACT_17 35 //секундные интервалы 17
#define TIME_FACT_18 37 //секундные интервалы 18
#define TIME_FACT_19 39 //секундные интервалы 19

enum {
  KEY_NULL,        //кнопка не нажата
  UP_KEY_PRESS,    //клик кнопкой вверх
  UP_KEY_HOLD,     //удержание кнопки вверх
  DOWN_KEY_PRESS,  //клик кнопкой вниз
  DOWN_KEY_HOLD,   //удержание кнопки вниз
  SEL_KEY_PRESS,   //клик кнопкой ок
  SEL_KEY_HOLD     //удержание кнопки ок
};

enum {
  INIT_PROGRAM,       //инициализация
  MAIN_PROGRAM,       //основной экран
  SEARCH_PROGRAM,     //режим поиск
  MEASUR_PROGRAM,     //режим замер
  LOGBOOK_PROGRAM,    //режим журнал
  SETTINGS_PROGRAM,   //настройки
  PARAMETERS_PROGRAM, //параметры
  POWER_DOWN_PROGRAM, //отключение питания
  MENU_PROGRAM,       //основное меню
  DEBUG_PROGRAM       //отладка
};

enum {
  _SET_TIME_SLEEP,       //сон
  _SET_TIME_BRIGHT,      //подсветка
  _SET_CONTRAST,         //контраст
#if ROTATE_DISP_RETURN
  _SET_ROTATION,         //разворот
#endif
  _SET_RAD_FLASH,        //вспышки
  _SET_VOLUME,           //громкость
  _SET_BUZZ_SWITCH,      //щелчки
  _SET_KNOCK_DISABLE,    //звук кнопок
  _SET_MEASUR_POS,       //разностный замер
  _SET_SIGMA_POS,        //сигма
  _SET_SEARCH_POS,       //поиск
  _SET_RAD_MOD,          //единицы измерения
  _SET_ALARM_BACK,       //тревога фон
  _SET_WARN_LEVEL_BACK,  //порог фон 1
  _SET_ALARM_LEVEL_BACK, //порог фон 2
  _SET_ALARM_DOSE,       //тревога доза
  _SET_WARN_LEVEL_DOSE,  //порог доза 1
  _SET_ALARM_LEVEL_DOSE, //порог доза 2
#if USE_UART
  _SET_UART_MOD,         //последовательный порт
#endif
  _SET_MENU_ALL          //всего пунктов меню
};

uint16_t stat_upd_tmr; //таймер записи статистики в память

#if GEIGER_OWN_BACK
uint16_t rad_sum_timer; //таймер секунду между расчетами дозы
#endif
uint16_t rad_sum; //сумма импульсов за все время
uint32_t rad_back; //текущий фон
uint32_t rad_dose; //текущая доза
uint32_t rad_min; //минимальный фон
uint32_t rad_max; //максимальный фон

uint8_t accur_percent; //точность процентов

float rad_imp; //импульсы в секунду
float rad_imp_m; //импульсы в минуту
uint16_t scan_ind; //шкала имп/с
uint32_t rad_search; //фон в режиме поиск

uint16_t graf_max = 15; //максимальный уровень маштабирования графика

boolean search_disable = 0; //флаг запрета движения графика
uint8_t cur_dose_cell = 0; //текущая ячейка хранения дозы

uint32_t time_save; //время из памяти
uint32_t rad_dose_save; //доза из памяти
uint32_t time_save_old; //предыдущее значение сохраненного времени
uint32_t rad_dose_old; //предыдущее значение дозы

//счетчики времени
uint32_t time_sec = 0; //секунды реального времени
uint8_t time_out = 0; //счетчик авто-выхода
uint8_t mid_time_now = 0; //текущий номер набранного массива усреднения
uint8_t back_time_now = 0; //текущий номер набранной секунды счета фона
uint8_t geiger_time_now = 0; //текущий номер набранной секунды счета
uint8_t search_time_now = 0; //текущий номер набранной секунды графика

volatile uint8_t tick_buff; //счетчик тиков для обработки данных
uint8_t cnt_pwr; //счетчик ухода в сон
uint16_t timer_millis; //таймер отсчета миллисекунд
uint16_t timer_melody; //таймер отсчета миллисекунд для мелодий

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
boolean graf = 0; //флаг обновления режима поиск

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

//переменные работы со звуками
struct soundData {
  uint8_t replay; //флаг повтора мелодии
  uint16_t semp; //текущий семпл мелодии
  uint16_t link; //ссылка на мелодию
  uint16_t size; //количество семплов мелодии
} sound;

//технические переменные
volatile uint16_t cnt_puls; //количество циклов для работы пищалки
uint8_t vibro_switch; //переключатель вибрации

uint8_t mainTask = MAIN_PROGRAM; //переключать подпрограмм

uint8_t error_switch = 0; //указатель на активность ошибки
boolean light_switch = 1; //переключатель вкл/выкл подсветки дисплея

float now = 0.00; //текущее соотношение ячеек сравнения
#if COEF_DEBUG //отладка коэффициента
float debug_coef = 0.00; //для  вывода общего коэффициента в дебаг
#endif

//Перечисления системных звуков
enum {
  SOUND_MEASUR, //звук оповещения о готовности замера
  SOUND_BAT_LOW, //звук оповещения о разряде акб
  SOUND_ERROR, //звук оповещения об ошибке
  SOUND_WARN, //звук оповещения о предупреждении порога
  SOUND_ALARM //звук оповещения о тревоге порога
};

//Перечисления режимов воспроизведения мелодий
enum {
  REPLAY_STOP, //остановить воспроизведение
  REPLAY_ONCE, //проиграть один раз
  REPLAY_CYCLE //проиграть по кругу
};

#define RESET_SYSTEM __asm__ __volatile__ ("JMP 0x0000") //перезагрузка

#define EEPROM_BLOCK_SETTINGS_MAIN (EEPROM_BLOCK_NULL)
#define EEPROM_BLOCK_SETTINGS_BOOK (EEPROM_BLOCK_SETTINGS_MAIN + sizeof(mainSettings))
#define EEPROM_BLOCK_SETTINGS_PUMP (EEPROM_BLOCK_SETTINGS_BOOK + sizeof(bookSettings))
#define EEPROM_BLOCK_CRC_MAIN (EEPROM_BLOCK_SETTINGS_PUMP + sizeof(pumpSettings)) //ячейка контрольной суммы основных настроек
#define EEPROM_BLOCK_CRC_BOOK (EEPROM_BLOCK_CRC_MAIN + 1) //ячейка контрольной суммы настроек журнала
#define EEPROM_BLOCK_CRC_PUMP (EEPROM_BLOCK_CRC_BOOK + 1) //ячейка контрольной суммы настроек преобразователя
#define EEPROM_BLOCK_CRC_STRUCT (EEPROM_BLOCK_CRC_PUMP + 1) //ячейка контрольной суммы структур данных

void _init_rads_unit(boolean type, uint32_t num, uint8_t divisor, uint8_t char_all, uint8_t num_x, uint8_t num_y, boolean unit, uint8_t unit_x, uint8_t unit_y, boolean dash = 0); //отрисовка данных
//--------------------------------------Главный цикл программ---------------------------------------------------
int main(void) //главный цикл программ
{
  INIT_SYSTEM(); //инициализация

  for (;;) {
    scr = 0; //разрешаем обновления экрана
    switch (mainTask) {
      default: RESET_SYSTEM; break; //перезагрузка
      case MAIN_PROGRAM: mainTask = main_screen(); break; //основной экран
      case SEARCH_PROGRAM: mainTask = search_menu(); break; //режим поиск
      case MEASUR_PROGRAM: mainTask = measur_menu(); break; //режим замера
      case LOGBOOK_PROGRAM: mainTask = logbook(); break; //журнал
      case SETTINGS_PROGRAM: mainTask = settings(); break; //настройки
      case PARAMETERS_PROGRAM: mainTask = parameters(); break; //параметры
      case POWER_DOWN_PROGRAM: mainTask = power_down(); break; //отключение питания
      case MENU_PROGRAM: mainTask = menu(); break; //меню
      case DEBUG_PROGRAM: mainTask = debug(); break; //отладка
    }
  }
  return INIT_PROGRAM;
}
//--------------------------------------Инициализация---------------------------------------------------
void INIT_SYSTEM(void) //инициализация
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

  SEL_INIT; //инициализация кнопки "ок"
  DOWN_INIT; //инициализация кнопки "вниз"
  UP_INIT; //инициализация кнопки "вверх"

  _delay_ms(START_TIME); //ждем
  _init_timers(); //инициализация таймеров;

  PRR = 0b11101110; //отключаем все лишнее (I2C | TIMER2 | TIMER0 | TIMER1 | SPI | UART)
  ACSR |= 0b10000000; //отключаем компаратор

  _init_lcd(); //инициализируем дисплей
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

  _wait(FONT_TIME); //ждем

  clrScr(); //очистка экрана
}
//-------------------Проверка и чтение данных из памяти-------------------------------------------
void _read_memory(void) //проверка и чтение данных из памяти
{
  uint8_t dataReg = 0; //регистр очистки данных
  uint8_t crc = 0; //контрольная сумма

  for (uint8_t n = 0; n < sizeof(mainSettings); n++) checkCRC(&crc, *((uint8_t*)(&mainSettings) + n)); //рассчитываем контрольную сумму для основных настроек
  for (uint8_t n = 0; n < sizeof(bookSettings); n++) checkCRC(&crc, *((uint8_t*)(&bookSettings) + n)); //рассчитываем контрольную сумму для настроек журнала
  for (uint8_t n = 0; n < sizeof(pumpSettings); n++) checkCRC(&crc, *((uint8_t*)(&pumpSettings) + n)); //рассчитываем контрольную сумму для настроек преобразователя

  if (!SEL_CHK || crc != EEPROM_ReadByte(EEPROM_BLOCK_CRC_STRUCT)) { //если зажата кнопка "ОК" или данные структур изменились
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
    tick_buff = 0; //очищаем буфер тиков
    drawLine(5, 10, map(i, 0, 4, 0, 64), 0xFF); //прогресс бар загрузки данных
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
  boolean cursor = 0; //положение курсора

  while (1) {
    for (; tick_buff; tick_buff--) { //если был тик, обрабатываем данные

      switch (btn_state) { //таймер опроса кнопок
        case 0: if (btn_check) btn_tmr++; break; //считаем циклы
        case 1: if (btn_tmr) btn_tmr--; break; //убираем дребезг
      }

      switch (check_keys()) {
        case DOWN_KEY_PRESS: cursor = 0; break; //выбор нет
        case UP_KEY_PRESS: cursor = 1; break; //выбор да
        case SEL_KEY_PRESS: return cursor; //выбор пункта
      }

      if (!scr) { //обновление дисплея
        scr = 1; //сброс флага
        choice_menu(cursor); //меню выбора
        showScr(); //вывод буфера на экран
      }
    }
  }
  return 0;
}
//-----------------------------Инициализация таймеров-----------------------------------------------
void _wait(uint32_t timer) //инициализация таймеров
{
  for (timer_millis = timer; timer_millis && !check_keys();) _data_update(); // ждем, преобразование данных
}
//-----------------------------Очистка строк загрузки-----------------------------------------------
void _rows_clear(void) //очистка строк загрузки
{
  drawLine(4); //очистка строки 4
  drawLine(5); //очистка строки 5
}
//---------------------------------Вывод логотипа---------------------------------------------------
void _init_logo(void) //вывод логотипа
{
  drawBitmap(0, 0, logo_img, 84, 24); //выводим лого
}
//------------------------------Инициализация таймеров----------------------------------------------
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
}
//-----------------------------Инициализация параметров----------------------------------------------
void _init_param(void) //инициализация параметров
{
  GEIGER_CYCLE = (pgm_read_byte(&time_mass[0][0]) + pgm_read_byte(&time_mass[0][1])); //минимум секунд для начала расчетов
  GEIGER_MASS = (pgm_read_byte(&time_mass[MASS_TIME - 1][0]) + pgm_read_byte(&time_mass[MASS_TIME - 1][1])); //максимум секунд для окончания смещения коэффициентов

  setContrast(mainSettings.contrast); //установка контрастности
  BUZZ_VOL_SET(mainSettings.volume); //устанавливаем громкость щелчков
  main_buff = 0; //очищаем основной буфер
}
//----------------------------------Включение WDT----------------------------------------------------
void _wdt_enable(void) //включение WDT
{
  cli(); //запрещаем прерывания
  WDTCSR = ((0x01 << WDCE) | (0x01 << WDE)); //разрешаем изменения
  WDTCSR = 0x40; //устанавливаем пределитель 2(режим прерываний)
  sei(); //разрешаем прерывания
}
//----------------------------------Выключение WDT---------------------------------------------------
void _wdt_disable(void) //выключение WDT
{
  WDTCSR = ((0x01 << WDCE) | (0x01 << WDE)); //сбрасываем собаку
  WDTCSR = 0x00; //выключаем собаку
}
//----------------------------------Включение ADC----------------------------------------------------
void _adc_enable(void) //включение ADC
{
  PRR &= ~ (1 << 0); //включаем питание АЦП
  ADCSRA = 0b10000111; //настройка АЦП
}
//----------------------------------Выключение ADC---------------------------------------------------
void _adc_disable(void) //выключение ADC
{
  ADCSRA = 0b00000111; //настройка АЦП
  PRR |= (1 << 0); //выключаем питание ацп
}
//-------------------------------Детектирование частиц------------------------------------------------
ISR(INT0_vect) //внешнее прерывание на пине INT0 - считаем импульсы от счетчика 1
{
  main_buff++; //прибавляем импульс в основной буфер
}
//--------------------------------Счет тиков WatchDog-------------------------------------------------
ISR(WDT_vect) //cчет тиков WatchDog
{
  if (++tick_buff == REBOOT_TICK) RESET_SYSTEM; //если буфер переполнен то перезагружаемся
}
//----------------------------------Преобразование данных---------------------------------------------
boolean _data_update(void) //преобразование данных
{
  static boolean puls_det; //флаг обнаружения импульсов со счетчика
  static uint8_t tick_switch; //счетчик тиков для обработки данных
  static uint8_t tmr_nop_imp; //таймер отсутствия импульсов
  static uint8_t tmr_upd_bat; //таймер обновления состояния акб
  static uint8_t tmr_low_bat; //таймер вывода сообщения об разряженой акб
  static uint8_t tmr_upd_err; //таймер вывода сообщения об ошибке
  static uint32_t time_total; //счетчик реального времени
  static uint32_t temp_buff; //общий буфер

  static uint8_t mass_switch; //переключатель массива
  static uint8_t time_right; //секундные замеры второго плеча
  static uint8_t time_left; //секундные замеры первого плеча
  static uint32_t temp_right; //буффер второго плеча
  static uint32_t temp_left; //буффер первого плеча
  static float coef_now; //коэффициент сравнения
  static float coef_back; //коэффициент поправки на фон
  static float coef_main; //основной коэффициент

  if (!tick_buff) _low_pwr(); //отключение дисплея и подсветки, уход в сон для экономии энергии
  _pump_converter(); //накачка по обратной связи с АЦП

  if (main_buff) { //если есть импульс в основном буфере
    uint16_t temp_main_puls = main_buff; //копируем количество импульсов
    main_buff = 0; //очищаем основной буфер
    puls_det = 1; //установили флаг обнаружения импульса

    if (65535 - scan_buff >= temp_main_puls) scan_buff += temp_main_puls; //если буфер сканирования не переполнен прибавляем импульсы
    else scan_buff = 65535; //иначе установили максимум

    if (!TIMSK0) { //если индикация не включена
      switch (mainSettings.rad_flash) { //в зависимости от режима
        case 1: _RAD_FLASH_ON break; //индикация попадания частиц
        case 2: if (!sleep) _RAD_FLASH_ON break; //индикация попадания частиц
      }
    }
    if (!TIMSK1) { //если бузер не включен
      switch (mainSettings.buzz_switch) { //в зависимости от режима
        case 1: BUZZ_START; break; //щелчок пищалкой
        case 2:
          if (rad_back >= mainSettings.warn_level_back) { //если фон выше установленного
            BUZZ_START; //щелчок пищалкой
          }
          break;
      }
    }
  }

  if (tick_buff) { //если был тик то обрабатываем данные
    tick_buff--; //убавили тик

    switch (btn_state) { //таймер опроса кнопок
      case 0: if (btn_check) btn_tmr++; break; //считаем циклы
      case 1: if (btn_tmr) btn_tmr--; break; //убираем дребезг
    }

    _bat_massege(); //обработка сообщения разряженой батареи

    if (timer_millis > 16) timer_millis -= 16; //если таймер больше 16мс
    else if (timer_millis) timer_millis = 0; //иначе сбрасываем таймер

    if (timer_melody > 16) timer_melody -= 16; //если таймер больше 16мс
    else if (timer_melody) timer_melody = 0; //иначе сбрасываем таймер

    melodyUpdate();  //воспроизведение мелодии

    time_total += pumpSettings.wdt_period; //добавляем ко времени период таймера
    if (time_total > 100000UL) { //если прошла секунда
      time_total -= 100000UL; //оставляем остаток
      tick_switch = 0; //сбросили тики обработки данных
    }
    tick_switch++; //прибавили тик обработки данных

    if (mainTask != MEASUR_PROGRAM && mainTask != SEARCH_PROGRAM) { //если не идет замер/поиск
      switch (tick_switch) { //блок обработки данных режима фон/доза
        case TIME_FACT_0: //обновление секунд
          time_sec++; //прибавляем секунду
          break;

        case TIME_FACT_1: //обновление статистики
          if (++stat_upd_tmr >= STAT_UPD_TIME) { //если пришло время, обновляем статистику
            stat_upd_tmr = 0; //сбрасываем таймер
            statistic_update(); //обновление статистики
          }
          break;

        case TIME_FACT_2: //расчет текущего фона этап-1
          rad_buff[0] = scan_buff; //смещаем 0-й элемент в 1-й для дальнейшей работы с ним
          scan_buff = 0; //сбрасываем счетчик импульсов
          temp_buff = 0; //сбрасываем временный буфер

          if (geiger_time_now < BUFF_LENGTHY) geiger_time_now++; //прибавляем указатель заполненности буффера
          if (back_time_now < BUFF_LENGTHY) back_time_now++; //прибавляем указатель заполненности буффера для рассчета фона
          else {
            back_time_now = 1; //иначе сбрасываем в начало
            if (mid_time_now < MID_BUFF_LENGTHY) mid_time_now++; //прибавляем указатель заполненности буффера
          }

#if GEIGER_DEAD_TIME
          if (rad_buff[0] >= COUNT_RATE) rad_buff[0] = rad_buff[0] / (1 - rad_buff[0] * DEAD_TIME); //если скорость счета больше 100имп/с, учитываем мертвое время счетчика
#endif

          for (uint8_t i = 0; i < back_time_now; i++) temp_buff += rad_buff[i]; //суммирование всех импульсов для расчета фона
          break;

        case TIME_FACT_3: //копирование буфера усреднения
          if (back_time_now >= BUFF_LENGTHY) { //если основной буфер перезаписался
            for (uint8_t k = MID_BUFF_LENGTHY - 1; k > 0; k--) rad_mid_buff[k] = rad_mid_buff[k - 1]; //перезапись массива
            rad_mid_buff[0] = temp_buff; //записываем основной массив в массив усреднения
          }
          for (uint8_t i = 0; i < mid_time_now; i++) temp_buff += rad_mid_buff[i]; //суммирование всех импульсов для расчета фона
          break;

        case TIME_FACT_4: //расчет текущего фона этап-3
          if (geiger_time_now >= GEIGER_CYCLE) { //если массив заполнен на минимум начала работы коэффициентов
            if (geiger_time_now <= GEIGER_MASS) { //если не достигли предела массива сравнения
              if (geiger_time_now >= (pgm_read_byte(&time_mass[mass_switch + 1][0]) + pgm_read_byte(&time_mass[mass_switch + 1][1]))) { //пересчитываем текущий номер элемента массива в зависимости от заполненности массива счета
                mass_switch++; //смещаем положение переключателя
                time_left = pgm_read_byte(&time_mass[mass_switch][0]); //получаем количество секундных замеров для первого плеча
                time_right = pgm_read_byte(&time_mass[mass_switch][1]); //получаем количество секундных замеров для второго плеча
              }
            }

            coef_back = 1.00; //устанавливаем первичный коэффициент
            for (uint8_t i = 0; i < MASS_BACK; i++) {
              if (rad_back <= pgm_read_word(&back_mass[i])) {
                coef_back = pgm_read_float(&coef_back_mass[i]); //пересчитывем фон для коррекции по заданным коэффициентам в массиве
                break;
              }
            }
          }
          break;

        case TIME_FACT_5: //расчет текущего фона этап-4
          if (geiger_time_now >= GEIGER_CYCLE) { //если массив заполнен на минимум начала работы коэффициентов
            coef_now = pgm_read_float(&coef_time_mass[mass_switch]) * coef_back; //получаем коэффициент из массива для сравнения на скачок/спад
            temp_left = 1; //сбрасываем буффер первого плеча
            for (uint8_t i = 0; i < time_left; i++) temp_left += rad_buff[i]; //запоняем буффер первого плеча
            temp_right = 1; //сбрасываем буффер второго плеча
            for (uint8_t i = time_left; i < (time_left + time_right); i++) temp_right += rad_buff[i]; //запоняем буффер вторго плеча
          }
          break;

        case TIME_FACT_6:  //расчет текущего фона этап-5
          if (geiger_time_now >= GEIGER_CYCLE) { //если массив заполнен на минимум начала работы коэффициентов
            coef_main = ((float)temp_left / time_left) / ((float)temp_right / time_right); //получаем текущее соотношение первого плеча ко второму

            if (coef_main > coef_now || coef_main < (1.00 / coef_now)) { //если видим скачок или спад
              temp_buff = 0; //сбрасываем текущий буфер
              for (uint8_t i = 0; i < pgm_read_byte(&time_mass[0][0]); i++) temp_buff += rad_buff[i]; //запоняем буффер первого плеча
              back_time_now = geiger_time_now = pgm_read_byte(&time_mass[0][0]); //устанавливаем текущий размер буфера
              mid_time_now = 0; //сбрасываем рассчет среднего
              mass_switch = 0; //сбрасываем позицию переключения
            }
          }
          break;
        case TIME_FACT_7: { //расчет текущего фона
#if APPROX_BACK_SCORE
            float imp_per_sec = 0; //текущее количество имп/с
            if (geiger_time_now > 1) imp_per_sec = (float)temp_buff / ((uint16_t)mid_time_now * BUFF_LENGTHY + back_time_now); //расчет имп/с
#if GEIGER_OWN_BACK
            if (imp_per_sec > OWN_BACK) imp_per_sec -= OWN_BACK; //убираем собственный фон счетчика
            else imp_per_sec = temp_buff = 0; //иначе ничего кроме собственного фона нету
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
            if (temp_buff > own_back_now) temp_buff -= own_back_now; //убираем собственный фон счетчика
            else temp_buff = 0; //иначе ничего кроме собственного фона нету
#endif
            if (geiger_time_now > 1) rad_back = temp_buff * (pumpSettings.geiger_time / ((uint16_t)mid_time_now * BUFF_LENGTHY + back_time_now)); //расчет фона мкР/ч
#endif
          }
          break;

        case TIME_FACT_8: //перезапись массива секундных замеров и поиск максимума для графика
          graf_max = 15; //сбрасываем максимум графика
          for (uint8_t i = BUFF_LENGTHY - 1; i > 0; i--) { //перезапись массива
            rad_buff[i] = rad_buff[i - 1]; //смещаем ячейку
            if (i < 39 && rad_buff[i] > graf_max) graf_max = rad_buff[i]; //ищем максимум
          }
          break;

        case TIME_FACT_9: //рассчитываем точность
          accur_percent = _init_accur(temp_buff); //рассчет точности
          break;

        case TIME_FACT_10: //минимальный и максимальный фон
          if (accur_percent <= RAD_ACCUR_START) { //если достаточно данных в массиве
            if (rad_back < rad_min) rad_min = rad_back; //фиксируем минимум фона
            if (rad_back > rad_max) rad_max = rad_back; //фиксируем максимум фона
          }
          else rad_min = rad_back; //фиксируем минимум фона
          break;

        case TIME_FACT_11: { //расчет текущей дозы
#if GEIGER_OWN_BACK
            if (rad_sum_timer != 65535) rad_sum_timer++;
            uint16_t puls_per_ur = (3600 / pumpSettings.geiger_time) + (rad_sum_timer * OWN_BACK);
            if ((rad_sum += rad_buff[0]) >= puls_per_ur) {
              rad_dose += rad_sum / puls_per_ur;
              rad_sum = rad_sum % puls_per_ur;
              rad_sum_timer = 0;
            }
#else
            uint16_t puls_per_ur = 3600 / pumpSettings.geiger_time;
            if ((rad_sum += rad_buff[0]) >= puls_per_ur) {
              rad_dose += rad_sum / puls_per_ur;
              rad_sum = rad_sum % puls_per_ur;
            }
#endif
          }
          break;

        case TIME_FACT_12: //обработка тревоги
          if (mainSettings.alarm_dose && (rad_dose - alarm_dose_wait) >= mainSettings.alarm_level_dose) { //если тревога не запрещена и текущая(предыдущая) доза больше порога
#if LOGBOOK_RETURN
            if (!alarm_switch && bookSettings.logbook_warn) _logbook_data_update(0, 2, rad_dose); //обновление журнала
#endif
            alarm_switch = 2;  //превышение дозы 2
            break;
          }
          else if (mainSettings.alarm_dose && (rad_dose - warn_dose_wait) >= mainSettings.warn_level_dose) { //если предупреждения не запрещены и текущая(предыдущая) доза больше порога
            if (!alarm_switch) { //если это первая сработка тревоги
              _sleep_out(); //выход из сна
              warn_messege(1, mainSettings.alarm_dose); //доза 1
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
                _sleep_out(); //выход из сна
                warn_messege(0, mainSettings.alarm_back); //фон 1
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
                melodyStop(); //сброс воспроизведения мелодии
                alarm_switch = 0; //устанавливаем признак отсутствия тревоги
              }
              break;
          }
#endif
          break;
#if USE_UART
        case TIME_FACT_13: //отправляем данные в порт
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

    switch (tick_switch) { //основной блок обрабоки данных
      case TIME_FACT_14: //обработка ошибок
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

        if (!puls_det) { //если не было импульса со счетчика
          if (++tmr_nop_imp >= IMP_ERROR_TIME) { //считаем время до вывода предупреждения
#if LOGBOOK_RETURN
            if (error_switch < 2) _logbook_data_update(3, 5, 5); //обновление журнала устанавливаем ошибку 5 - нет импульсов
            error_switch = 2; //поднимаем флаг ошибки
#else
            error_switch = 5; //поднимаем флаг ошибки
#endif
            tmr_nop_imp = 0; //сбросили таймер
          }
        }
        else { //иначе импульсы возобновились
          puls_det = 0; //сбросили флаг обнаружения импульсов
          tmr_nop_imp = 0; //сбросили таймер
        }

        if (tmr_upd_err >= ERROR_LENGTHY_TIME) {
          if (error_massege) {
            tmr_upd_err = 0; //сброс таймера
            error_massege = 0; //устанавливаем флаг для обновления сообщения об ошибке
          }
        }
        else tmr_upd_err++;
        break;

      case TIME_FACT_15: //разностный замер
        if (mainTask == MEASUR_PROGRAM) {
          switch (measur) { //выбираем режим замера
            case 1: if (time_switch < (pgm_read_byte(&diff_measuring[mainSettings.measur_pos]) * 60)) time_switch++; //прибавляем секунду
              else next_measur = 1; //иначе время вышло
              if (!next_measur) first_froze += scan_buff; //если идет замер, заполняем буфер первого замера
              break;
            case 2: if (time_switch < (pgm_read_byte(&diff_measuring[mainSettings.measur_pos]) * 60)) time_switch++; //прибавляем секунду
              else next_measur = 1; //иначе время вышло
              if (!next_measur) second_froze += scan_buff; //если идет замер, заполняем буфер второго замера
              break;
          }
          scan_buff = 0; //сбрасывает счетчик частиц
        }
        break;

      case TIME_FACT_16: //считаем время до ухода в сон
        if (mainSettings.sleep_switch) { //если сон не выключен
          if (cnt_pwr <= (sleep_disable) ? mainSettings.time_bright : mainSettings.time_sleep) cnt_pwr++; //счет ухода в сон
        }
        if (cnt_pwr == mainSettings.time_sleep && mainSettings.sleep_switch == 2) { //если пришло время спать и сон не запрещен
          enableSleep(); //уводим в сон дисплей
          sleep = 1; //выставляем флаг сна
          _buzz_disable(); //запрещаем щелчки
        }
        else if (cnt_pwr == mainSettings.time_bright) { //если пришло время выключить подсветку
          _LIGHT_OFF(); //выключаем подсветку
          light = 1; //выставляем флаг выключенной подсветки
        }
        break;

      case TIME_FACT_17: { //управление энергосбережением
          if (!sleep_disable) { //если сон разрешен
            uint16_t _imp_per_second = rad_back / pumpSettings.geiger_time; //получили имп/с
            switch (power_manager) {
              case 0: if (_imp_per_second <= (IMP_PWR_MANAGER * IMP_PWR_GISTERESIS)) power_manager = 1; break; //если текущее количество импульсов меньше установленного порога включения энергосбережения
              case 1:
                if (_imp_per_second > IMP_PWR_MANAGER) power_manager = 0; //если текущее количество импульсов больше установленного порога отключения энергосбережения
                else if (_imp_per_second <= (IMP_PWR_DOWN * IMP_PWR_GISTERESIS)) power_manager = 2; //если текущее количество импульсов меньше установленного порога включения глубокого энергосбережения
                break;
              case 2: if (_imp_per_second > IMP_PWR_DOWN) power_manager = 1; break; //если текущее количество импульсов больше установленного порога отключения глубокого энергосбережения
            }
            if (rad_back > RAD_SLEEP_OUT) _sleep_out(); //выход из сна
          }
        }
        break;

      case TIME_FACT_18: //таймер обновления состояния батареи
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

      case TIME_FACT_19: //таймер обновления экрана
        if (!sleep) scr = 0; //устанавливаем флаг для обновления экрана
        break;
    }
    return 1; //разрешаем обновить данные
  }
  return 0; //запрещаем обновить данные
}
//-------------------------Режим пониженного энергопотребления----------------------------------------------------
void _low_pwr(void) //режим пониженного энергопотребления
{
  if (mainSettings.sleep_switch == 2 && power_manager) { //если сон разрешен и разрешено энергосбережение
    if (TIMSK1 || TIMSK2 || TIMSK0) _wait_pwr(); //если включен бузер или шим подсветки или индикация частиц - режим ожидания
    else if (sleep && power_manager == 2) _sleep_pwr(); //если спим и разрешено глубокое энергосбережение
    else _save_pwr(); //иначе - режим энергосбережения
  }
  else _wait_pwr(); //иначе - режим ожидания
}
//-------------------------------------Выход из сна--------------------------------------------------------
void _sleep_out(void) //выход из сна
{
  if (light) { //если выключели подсветку
    _LIGHT_ON(); //включаем подсветку
    light = 0; //сбрасываем флаг подсветки
    if (sleep) { //если спали
      disableSleep(mainSettings.contrast); //выводим дисплей из сна
      sleep = 0; //сбрасываем флаг сна
      scr = 0; //разрешаем обновления экрана
      _buzz_enable(); //восстанавливаем настройку щелчков
    }
  }
  cnt_pwr = 0; //обнуляем счетчик сна
}
//------------------------------Выход из сна и сброс флагов-----------------------------------------------
void _disable_sleep(void) //выход из сна
{
  _sleep_out(); //выход из сна
  scr = 0; //разрешаем обновления экрана
  time_out = 0; //сбрасываем счетчик авто-выхода
}
//---------------------------------------Ожидание---------------------------------------------------------
void _wait_pwr(void) //ожидание
{
  SMCR = (0x0 << 1) | (1 << SE);  //устанавливаем режим сна idle

  MCUCR = (0x03 << 5); //выкл bod
  MCUCR = (0x02 << 5);

  asm ("sleep");  //с этого момента спим.
}
//-------------------------------------Энергосбережение---------------------------------------------------
void _save_pwr(void) //энергосбережение
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
uint8_t power_down(void) //выключение устройства
{
  cli(); //запрещаем прерывания

  _wdt_disable(); //выключаем watchdog
  _adc_disable(); //выключаем питание АЦП

  LIGHT_OFF; //выключаем подсветку
  BUZZ_OFF; //выключаем бузер
  FLASH_OFF; //выключаем фонарь
  _SOUND_STOP; //выключаем таймер бузера
  _LIGHT_STOP(); //выключаем шим подсветки
  _RAD_FLASH_OFF; //выключаем индикацию
  enableSleep(); //выключаем дисплей

  statistic_update(); //обновление статистики

  sei(); //разрешаем прерывания

#if PWR_ON_RETURN
  EIMSK = 0b00000010; //разрешаем внешнее прерывание INT1

  while (1) { //цикл выключенного питания
    _sleep_pwr(); //спим

    uint16_t startDellay = POWER_ON_TIME; //устанавливаем таймер
    while (!SEL_CHK) { //если кнопка не отжата
      if (startDellay) { //если время не истекло
        _delay_ms(1); //ждем 1мс
        startDellay--; //отнимаем от таймера 1 мс
      }
      else { //иначе включаем питание
        _adc_enable(); //включаем питание АЦП
        _bat_check(); //опрос батареи
        disableSleep(mainSettings.contrast); //включаем дисплей
        if (bat_adc < LOW_BAT_POWER) { //если батарея не разряжена
          LIGHT_ON; //включаем подсветку, если была включена настройками
          _wdt_enable(); //запускаем WDT
          _init_logo(); //вывод логотипа
          _start_pump(); //первая накачка преобразователя
          btn_check = 0; //запрещем проврку кнопки
          EIMSK = 0b00000001; //разрешаем внешнее прерывание INT0
          return MAIN_PROGRAM; //выходим
        }
        else { //иначе выводим предупреждение об разряженной батарее
          _adc_disable(); //выключаем питание ацп
          _init_low_bat(); //отрисовка сообщения разряженной батареи
          _delay_ms(POWER_TIME); //ждём
          enableSleep(); //выключаем дисплей
        }
      }
    }
  }
#else
  EIMSK = 0b00000000; //запрещаем внешние прерывание
  _sleep_pwr(); //спим
#endif
  return INIT_PROGRAM;
}
//------------------------------Индикация попадания частиц---------------------------------
ISR(TIMER0_OVF_vect) //индикация попадания частиц
{
  static uint8_t i; //счетчик миллисекунд
  if (++i >= RAD_FLASH_TIME) { //если время пришло
    i = 0; //сбрасываем счетчик
    _RAD_FLASH_OFF; //выключаем все
  }
}
//--------------------------------Подсветка старт/стоп-------------------------------------
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
//---------------------------------Прерывание сигнала для пищалки---------------------------
ISR(TIMER1_OVF_vect, ISR_NAKED) //прерывание сигнала для пищалки
{
  BUZZ_ON; //включаем бузер
  reti(); //возврат
}
ISR(TIMER1_COMPA_vect) {
  BUZZ_OFF; //выключаем бузер

  switch (--cnt_puls) { //считаем циклы времени работы бузера
    case 0: _SOUND_STOP; break; //если циклы кончились, выключаем таймер
  }
}
//-------------------------------Аналог tone(), с блекджеком и ...---------------------------
void buzz_pulse(uint16_t freq, uint16_t time) //генерация частоты бузера (частота 10..10000, длительность мс.)
{
  cnt_puls = ((uint32_t)freq * (uint32_t)time) / 1000UL; //пересчитываем частоту и время в циклы таймера
  SOUND_START((F_CPU / SOUND_PRESCALER) / freq); //устанавливаем частоту и запускаем таймер
}
//---------------------------------Воспроизведение мелодии-----------------------------------------------
void melodyUpdate(void) //воспроизведение мелодии
{
  if (sound.replay && !timer_melody) { //если пришло время
    buzz_pulse(pgm_read_word(sound.link + sound.semp), pgm_read_word(sound.link + sound.semp + 2)); //запускаем звук с задоной частотой и временем
    timer_melody = pgm_read_word(sound.link + sound.semp + 4); //устанавливаем паузу перед воспроизведением нового звука
    if ((sound.semp += 6) >= sound.size) { //переключаем на следующий семпл
      if (sound.replay == REPLAY_ONCE) melodyStop(); //если повтор выключен то остановка воспроизведения мелодии
      sound.semp = 0; //сбросили семпл
    }
  }
}
//-----------------------------Запуск воспроизведения мелодии--------------------------------------------
void melodyPlay(uint8_t melody, uint8_t replay) //запуск воспроизведения мелодии
{
  sound.semp = 0; //сбросили позицию семпла
  sound.replay = replay; //установили повтор
  sound.link = pgm_read_word(&general_sound + (melody << 2)); //установили ссылку
  sound.size = pgm_read_word(&general_sound + (melody << 2) + 2); //установили размер
  timer_melody = 0; //сбросили таймер
  _buzz_disable(); //запрещаем щелчки
}
//---------------------------Остановка воспроизведения мелодии-------------------------------------------
void melodyStop(void) //остановка воспроизведения мелодии
{
  sound.replay = REPLAY_STOP; //сбросили воспроизведение
  timer_melody = 0; //сбросили таймер
  _buzz_enable(); //разрешаем щелчки
}
//----------------------Конвертация напряжения преобразователя--------------------------------
uint16_t _convert_vcc_hv(uint8_t adc) //конвертация напряжения преобразователя
{
  return adc * pumpSettings.reference * pumpSettings.k_delitel / 255; //считем высокое перед выводом
}
//------------------------Чтение напряжения преобразователя-----------------------------------
uint8_t Read_HV(void) //чтение напряжения преобразователя
{
  ADCSRA |= 0b01000000; //запускаем преобразование
  while (ADCSRA & 0b01000000); //ждем окончания преобразования
  return ADCH; //возвращаем результат опроса АЦП
}
//-----------------------------------Первая накачка-------------------------------------------
void _start_pump(void) //первая накачка
{
  uint16_t timer = 0; //таймер авто-выхода
  print(LOAD, CENTER, 32); //загрузка...

  for (hv_adc = Read_HV(); hv_adc < pumpSettings.ADC_value; hv_adc = Read_HV()) { //значение АЦП при котором на выходе 400В
    _pump_puls(pumpSettings.puls); //ипульс на преобразователь

    if (++timer >= START_PUMP_IMP) break; //если время вышло то останавливаем накачку
    tick_buff = 0; //очищаем буфер тиков

    drawLine(5, 10, map(hv_adc, 0, pumpSettings.ADC_value, 0, 64), 0xFF); //прогресс бар накачки преобразователя
    showScr(); //вывод буфера на экран
  }
}
//----------------------------Накачка по обратной связи с АЦП---------------------------------
void _pump_converter(void) //накачка по обратной связи с АЦП
{
  uint8_t timer = 0; //счетчик циклов переполнения

  for (hv_adc = Read_HV(); hv_adc < pumpSettings.ADC_value; hv_adc = Read_HV()) { //значение АЦП при котором на выходе 400В
    _pump_puls(pumpSettings.puls); //ипульс на преобразователь

    speed_pump++; //считаем скорость накачки
    if (++timer >= CYCLE_OVERFLOW) break; //защита от зацикливания
  }
}
//-------------------------------Ипульс на преобразователь------------------------------------
void _pump_puls(uint8_t puls) //ипульс на преобразователь
{
  __asm__ __volatile__ (
    "SBI %[PORT], %[PIN]  \n\t" //HIGH на выход пина
    "_LOOP_START_%=:      \n\t" //цикл задержки
    "DEC %[COUNT]         \n\t" //декремент счетчика циклов
    "BRNE _LOOP_START_%=  \n\t" //переход в начало цикла если счетчик не равен нулю
    "CBI %[PORT], %[PIN]  \n\t" //LOW на выход пина
    :"=r"(puls)
    :[COUNT]"0"(puls),
    [PORT]"I"(_SFR_IO_ADDR(CONV_PORT)),
    [PIN]"I"(CONV_BIT)
  );
}
//--------------------------Конвертация напряжения батареи-----------------------------------
float _convert_vcc_bat(uint8_t adc) //конвертация напряжения батареи
{
  return (pumpSettings.reference * 255.0) / adc; //состояние батареи
}
//-----------------------------Чтение напряжения батареи-------------------------------------
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
//--------------------------------Опрос батареи----------------------------------------------
void _bat_check(void) //опрос батареи
{
  bat_adc = Read_VCC(); //состояние батареи
  if (bat_adc == 255) bat_adc = 60; //защита от ложных данных

  if (bat_adc < MIN_BAT) { //мин.напр. 3v макс.нап. 4,2v
    if (bat_adc < MAX_BAT) bat = 5;  //если батарея заряжена
    else { //иначе расчитывает указатель заряда батареи
      bat = map(bat_adc, MIN_BAT, MAX_BAT, 0, 6); //переводим значение в полосы акб
      bat = (bat > 5) ? 5 : bat; //ограничиваем
    }
  }
  else bat = 0; //иначе акб разряжен
}
//------------------------------Проверка кнопок---------------------------------------------
uint8_t check_keys(void) //проверка кнопок
{
  static uint8_t btn_switch; //флаг мультиопроса кнопок

  switch (btn_switch) { //переключаемся в зависимости от состояния мультиопроса
    case 0:
      if (!SEL_CHK) { //если нажата кл. ок
        btn_switch = 1; //выбираем клавишу опроса
        btn_state = 0; //обновляем текущее состояние кнопки
      }
      else if (!DOWN_CHK) { //если нажата кл. вниз
        btn_switch = 2; //выбираем клавишу опроса
        btn_state = 0; //обновляем текущее состояние кнопки
      }
      else if (!UP_CHK) { //если нажата кл. вверх
        btn_switch = 3; //выбираем клавишу опроса
        btn_state = 0; //обновляем текущее состояние кнопки
      }
      else btn_state = 1; //обновляем текущее состояние кнопки
      break;
    case 1: btn_state = SEL_CHK; break; //опрашиваем клавишу ок
    case 2: btn_state = DOWN_CHK; break; //опрашиваем клавишу вниз
    case 3: btn_state = UP_CHK; break; //опрашиваем клавишу вверх
  }

  switch (btn_state) { //переключаемся в зависимости от состояния клавиши
    case 0:
      if (btn_check) { //если разрешена провекрка кнопки
        if (btn_tmr > BTN_HOLD_TICK) { //если таймер больше длительности удержания кнопки
          btn_tmr = BTN_GIST_TICK; //сбрасываем таймер на антидребезг
          btn_check = 0; //запрещем проврку кнопки
          melodyStop(); //сброс воспроизведения мелодии
          if (!sleep) { //если не спим
            _disable_sleep(); //выход из сна
            switch (btn_switch) { //переключаемся в зависимости от состояния мультиопроса
              case 1: return SEL_KEY_HOLD; //удержание кнопки ок
              case 2: return DOWN_KEY_HOLD; //удержание кнопки вниз
              case 3: return UP_KEY_HOLD; //удержание кнопки вверх
            }
          }
        }
      }
      break;

    case 1:
      if (btn_tmr > BTN_GIST_TICK) { //если таймер больше времени антидребезга
        btn_tmr = BTN_GIST_TICK; //сбрасываем таймер на антидребезг
        btn_check = 0; //запрещем проврку кнопки
        if (!mainSettings.knock_disable) buzz_pulse(FREQ_BEEP, TIME_BEEP); //щелчок пищалкой
        melodyStop(); //сброс воспроизведения мелодии
        if (!light && !sleep) { //если не спим и если подсветка включена, поднимаем признак нажатия
          _disable_sleep(); //выход из сна
          switch (btn_switch) { //переключаемся в зависимости от состояния мультиопроса
            case 1: return SEL_KEY_PRESS; //клик кнопкой ок
            case 2: return DOWN_KEY_PRESS; //клик кнопкой вниз
            case 3: return UP_KEY_PRESS; //клик кнопкой вверх
          }
        }
        else _disable_sleep(); //выход из сна
      }
      else if (!btn_tmr) {
        btn_check = 1; //разрешаем проврку кнопки
        btn_switch = 0; //сбрасываем мультиопрос кнопок
      }
      break;
  }
  return KEY_NULL;
}
//-------------------------------Оостановка замера------------------------------------------------------
void measur_stop(void) //остановка замера
{
  boolean cursor = 0; //курсор

  clrScr(); //очистка экрана
  print(M_STOP, CENTER, 8); //Остановить
  print(M_MEASUR, CENTER, 16); //замер?

  while (1) {
    if (_data_update()) { //обработка данных
      switch (check_keys()) {
        case DOWN_KEY_PRESS: cursor = 0; break; //выбор нет
        case UP_KEY_PRESS: cursor = 1; break; //выбор да

        case SEL_KEY_PRESS: //выбор пункта
          switch (cursor) {
            case 1:
              measur = 0; //выключаем замер
              time_switch = 0; //сбрасываем таймер
              next_measur = 1; //сбрасываем флаг продолжения замера
              alarm_measur = 1; //разрешаем оповещение окончания замера
              first_froze = 0; //сбрасываем счетчик 1-го замера
              second_froze = 0; //сбрасываем счетчик 2-го замера
              break;
          }
          return; //выход
      }

      if (!scr) {
        scr = 1; //устанавливаем флаг
        choice_menu(cursor); //меню выбора
        showScr(); //вывод буфера на экран
      }
    }
  }
}
//-------------------------------Окончание замера----------------------------------------------------------
void _measur_massege(void) //окончание замера
{
  if (next_measur && !alarm_measur) { //если поднят флаг следующего замера и оповещение окончания замера разешено

    _disable_sleep(); //просыпаемся если спали

    clrScr(); //очистка экрана
    print(M_MEASURS, CENTER, 16); //Замер
    print(M_COMPLET, CENTER, 24); //завершен!

    showScr(); //вывод буфера на экран
#if MEASUR_SOUND
    melodyPlay(SOUND_MEASUR, REPLAY_ONCE); //звук окончания замера
#endif

    _wait(MASSEGE_TIME); //ждём

    switch (measur) {
      case 1: alarm_measur = 1; break; //запрещаем повторное оповещение
      case 2:
        measur = 0;
        time_switch = 0;
        alarm_measur = 1;
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
  }
}
//-------------------------------Режим замера----------------------------------------------------------
uint8_t measur_menu(void) //режим замера
{
  uint32_t buff = 0;
  boolean anim = 0; //анимация окончания замера

  alarm_measur = 1; //запрещаем оповещение окончания замера
  next_measur = 1; //поднимаем флаг продолжения замера

  while (1) {
    if (_data_update()) { //обработка данных
      _error_messege(); //обработка ошибок
      _measur_massege(); //оповещение об окончании замера

      switch (check_keys())
      {
        case DOWN_KEY_HOLD: //удержание кнопки вниз
          fast_light(); //быстрое включение подсветки
          break;

        case DOWN_KEY_PRESS: //клик кнопки вниз
          if (measur) measur_stop(); //если идет замер, спрашиваем нужно ли остановить замер
          else {
            measur = 0; //выключаем замер
            time_switch = 0; //сбрасываем таймер
            next_measur = 1; //сбрасываем флаг следующего замера
            alarm_measur = 1; //разрешаем оповещение оканчания замера
            first_froze = 0; //сбрасываем счетчик 1-го замера
            second_froze = 0; //сбрасываем счетчик 2-го замера
          }
          break;

        case UP_KEY_PRESS: //клик кнопки вверх
          if (measur) measur_stop(); //если идет замер, спрашиваем нужно ли остановить замер
          break;

        case UP_KEY_HOLD: //удержание кнопки вверх
          FLASH_SWITCH; //быстрое включение фонарика
          break;

        case SEL_KEY_PRESS: //клик кнопки выбора
          if (!measur) {
            measur = 1; //включаем замер
            next_measur = 0; //сбрасываем флаг следующего замера
            alarm_measur = 0; //разрешаем оповещение оканчания замера
            first_froze = 0; //сбрасываем счетчик 1-го замера
            second_froze = 0; //сбрасываем счетчик 2-го замера
          }
          else if (next_measur && measur == 1) {
            measur = 2;
            next_measur = 0;
            time_switch = 0;
            alarm_measur = 0;
            anim = 0;
          }
          break;

        case SEL_KEY_HOLD: //удержание кнопки выбора
          if (measur) measur_stop(); //если идет замер, спрашиваем нужно ли остановить замер
          else return MENU_PROGRAM; //выходим в меню
          break;
      }

      if (!scr) {
        scr = 1; //устанавливаем флаг

        clrScr(); //очистка экрана
        task_bar(M_MEASUR_BETA); //отрисовываем фон

        switch (measur) {
          case 0: //результат
            buff = (first_froze < second_froze) ? second_froze - first_froze : 0; //рассчитываем результат замера

            if (next_measur) {
              switch (anim) {
                case 0:
                  print(M_RESULT, CENTER, 24); //результат
                  _init_couts_per_cm2((float)buff / pgm_read_byte(&diff_measuring[mainSettings.measur_pos])); //результат ч/см2*м
                  break;
                case 1:
                  print(M_BACK_OK, CENTER, 24); //ок - замер фона
                  _init_rads_unit(1, buff * (pumpSettings.geiger_time / (pgm_read_byte(&diff_measuring[mainSettings.measur_pos]) * 60)), 1, 4, 1, 8, 0, 54, 16); //результат мкр/ч
                  break;
              }
              anim = !anim;
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
              switch (anim) {
                case 0: print(M_BACK, CENTER, 24); break; //замер фона
                case 1: print(M_SAMP_OK, CENTER, 24); break; //ок - зам. образца
              }
              anim = !anim;
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

          drawLine(4, 1, map(time_switch, 0, pgm_read_byte(&diff_measuring[mainSettings.measur_pos]) * 60, 5, 82), 0x30); //шкала пройденого времени
        }

        showScr(); //вывод буфера на экран
      }
    }
  }
  return INIT_PROGRAM;
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
//----------------------------Расчет точности замера----------------------------------------------------
uint8_t _init_accur(uint32_t num) //расчет точности замера
{
  return (num) ? constrain(((mainSettings.sigma_pos + 1) / sqrtf((float)num)) * 100, 1, 99) : 99; //находим статистическую точность
}
//-------------------------------Выбор тревоги----------------------------------------------------------
void _alarm_warning(void) //выбор тревоги
{
  switch (alarm_switch) {
    case 1: alarm_messege(0, mainSettings.alarm_back, A_BACK); break; //фон 2
    case 2: alarm_messege(1, mainSettings.alarm_dose, A_DOSE); break; //доза 2
    case 3: _vibro_on(mainSettings.alarm_back); break; //фон 1
    case 4: _vibro_on(mainSettings.alarm_dose); break; //доза 1
  }
}
//----------------------------------Сброс предупреждения------------------------------------------------
boolean skip_warn_messege(void) //сброс предупреждения
{
  switch (alarm_switch) { //режим тревоги
    case 0: return 1;
    case 3: warn_back_wait = 1; break; //сбросить тревогу фон
    case 4: warn_dose_wait = rad_dose; break; //сбросить тревогу доза
  }
  alarm_switch = 0;
  _vibro_off();
  return 0;
}
//-------------------------------Предупреждение----------------------------------------------------------
void warn_messege(boolean set, uint8_t sound) //предупреждение
{
  if (set != scr_mode) { //переключаемся на экран тревоги
    scr_mode = set;
    dose_mode = 0;
  }

  switch (sound) {
    case 1:
    case 3:
      melodyPlay(SOUND_WARN, REPLAY_CYCLE); //звук предупреждения
      break;
  }
}
//-------------------------------Тревога-----------------------------------------------------
void alarm_messege(boolean set, uint8_t sound, const char *mode) //тревога
{
  _disable_sleep(); //просыпаемся если спали
  switch (sound) {
    case 1:
    case 3:
      melodyPlay(SOUND_ALARM, REPLAY_CYCLE); //звук тревоги
      break;
  }

  clrScr(); //очистка экрана
  drawBitmap(26, 0, rad_img, 32, 32);
  print(A_ALARM, CENTER, 32); //строка ТРЕВОГА!

  while (1) {
    if (_data_update()) { //обработка данных
      _vibro_on(sound); //включаем вибрацию

#if ALARM_AUTO_DISABLE
      if (check_keys() || (!set && !alarm_switch)) //если нажата любая кнопка или фон упал то отключаем тревогу
#else
      if (check_keys()) //если нажата любая кнопка то отключаем тревогу
#endif
      {
        _vibro_off(); //выключаем вибрацию

        switch (set) {
          case 0: alarm_back_wait = warn_back_wait = 1; break;
          case 1: alarm_dose_wait = warn_dose_wait = rad_dose; break;
        }

        alarm_switch = 0; //устанавливаем признак отсутствия тревоги
        scr = 0; //разрешаем обновление экрана
        return;
      }

      if (!scr) {
        scr = 1; //сбросили флаг обновления экрана

#if TYPE_ALARM_IND != 2
        drawLine(4); //очистка строки 4
        _init_alarm_massage(1, 32); //тревога
#endif

        drawLine(5); //очистка строки 5
        print(mode, LEFT, 40); //фон
        _init_rads_unit(0, (set) ? rad_dose : rad_back, 10, 5, RIGHT, 40, set, RIGHT, 40); //результат

        showScr(); //вывод буфера на экран
      }
    }
  }
}
//--------------------------Инициализация сообщения тревоги---------------------------------
void _init_alarm_massage(boolean text, uint8_t pos) { //инициализация сообщения тревоги
  static boolean anim = 0; //переключатель анимации

  if (anim) {
    invertText(true);
    drawLine(pos / 8, 0, 83, 0xFF); //рисуем линию
  }
  switch (text) {
    case 0: print(A_WARN, CENTER, pos); break; //строка ОПАСНОСТЬ!
    case 1: print(A_ALARM, CENTER, pos); break; //строка ТРЕВОГА!
  }
  invertText(false);
  anim = !anim; //меняем значение
}
//--------------------------Вибрация и световая индикация тревоги---------------------------------
void _vibro_on(uint8_t vibro) //вибрация и световая индикация тревоги
{
  cnt_pwr = 0; //сбросили счетчик сна

  switch (vibro) {
    case 2:
    case 3:
      if (!timer_millis) { //если пришло время
        switch (pgm_read_word(&alarm_vibro[vibro_switch][0])) {
          case 0:
#if (TYPE_ALARM_IND == 1)
            FLASH_ON;
#elif (TYPE_ALARM_IND == 2)
            LIGHT_ON;
#endif
            VIBRO_ON;
            break;

          case 1:
#if (TYPE_ALARM_IND == 1)
            FLASH_OFF;
#elif (TYPE_ALARM_IND == 2)
            LIGHT_OFF;
#endif
            VIBRO_OFF;
            break;
        }
        timer_millis = pgm_read_word(&alarm_vibro[vibro_switch][1]); //устанавливаем паузу перед воспроизведением нового семпла
        if (++vibro_switch > (sizeof(alarm_vibro) / 4) - 1) vibro_switch = 0; //переключпем на следующий семпл
      }
      break;
  }
}
//-----------------------Выключение вибрация и световой индикаци--------------------------------
void _vibro_off(void) //выключение вибрация и световой индикаци
{
  vibro_switch = 0; //сбрасываем переключатель вибрации
#if (TYPE_ALARM_IND == 1)
  FLASH_OFF; //выключаем фонарик
#elif (TYPE_ALARM_IND == 2)
  if (light_switch) LIGHT_ON; //включаем подсветку, если была включена настройками
  else LIGHT_OFF; //выключаем подсветку
#endif
  VIBRO_OFF; //выключаем вибрацию
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
void _bat_massege(void) //сообщение об разряженной батареи
{
  if (!low_bat_massege && bat_adc >= LOW_BAT_STAT) { //если флаг разрешения сообщения поднят и заряд ниже 3v, то выводим предупреждение
    low_bat_massege = 1; //запрещаем вывод сообщения

    _disable_sleep(); //просыпаемся если спали

#if BAT_LOW_SOUND
    melodyPlay(SOUND_BAT_LOW, REPLAY_ONCE); //звук разряженной батареи
#endif

    clrScr(); // Очистка экрана
    _init_low_bat(); //отрисовка сообщения разряженной батареи
    _wait(MASSEGE_TIME); //ждём

    if (bat_adc >= LOW_BAT_POWER) power_down(); //выключение устройства
  }
}
//-------------------------Обновление данных поиска----------------------------------------------------
void _search_update(void) //обновление данных поиска
{
  static uint8_t now_pos; //переключатель динамического изменения времени
  static uint16_t cnt; //счетчик тиков графика
  static uint16_t scan_now; //имп/с за период
  static uint16_t time_to_update; //текущее время обновления
  static uint32_t imp_s; //имп/с для расчетов

  if (++cnt >= now_pos) { //расчет показаний
    uint32_t temp_buff = 0; //временный буфер расчета имп
    graf_max = 22; //сбрасываем максимум графика

    uint16_t temp_data = scan_buff; //запомнили текущее количество импульсов
    scan_buff = 0; //сбрасываем счетчик импульсов

    if (!search_disable) {
      if (search_time_now < SEARCH_BUF_SCORE) search_time_now++;

#if TYPE_GRAF_MOVE //слева-направо
      for (uint8_t i = 75; i > 0; i--) {
        search_buff[i] = search_buff[i - 1]; //сдвигаем массив
        if (search_buff[i] > graf_max) graf_max = search_buff[i];
      }
      search_buff[0] = temp_data; //новое значение в последнюю ячейку

      if (search_buff[0] > graf_max) graf_max = search_buff[0];
#else //справа-налево
      for (uint8_t i = 0; i < 75; i++) {
        search_buff[i] = search_buff[i + 1]; //сдвигаем массив
        if (search_buff[i] > graf_max) graf_max = search_buff[i];
      }
      search_buff[75] = temp_data; //новое значение в последнюю ячейку

      if (search_buff[75] > graf_max) graf_max = search_buff[75];
#endif
    }

#if TYPE_GRAF_MOVE //слева-направо
    for (uint8_t i = 0; i < search_time_now; i++) temp_buff += search_buff[i]; //сдвигаем массив
#else //справа-налево
    for (uint8_t i = 76 - search_time_now; i < 76; i++) temp_buff += search_buff[i]; //сдвигаем массив
#endif

    rad_imp = ((float)temp_buff / search_time_now) * ((time_to_update) ? (1000.00 / time_to_update) : 1); //персчет имп/сек.
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
uint8_t search_menu(void) //инициализация режима поиск
{
  uint8_t units = 0; //переключатель единиц графика
  graf = 0; //разрешаем обновление экрана

  while (1) {
    if (_data_update()) { //обработка данных
      _search_update(); //обновляем данные поика
      _error_messege(); //обработка ошибок

      switch (check_keys()) {
        case DOWN_KEY_HOLD: //вкл/выкл посветки
          fast_light(); //быстрое включение посветки
          break;

        case DOWN_KEY_PRESS: //сброс
          rad_imp = 0; //сбрасываем имп/с
          rad_imp_m = 0; //сбрасываем имп/м
          rad_search = 0; //сбрасываем счет импульсов
          search_time_now = 0; //сбрасываем время счета графика
          search_disable = 0; //разрешаем обновление графика
          for (uint8_t i = 0; i < 76; i++) search_buff[i] = 0; //очищаем буфер графика
          graf = 0; //разрешаем обновления экрана
          break;

        case UP_KEY_HOLD: //вкл/выкл фонарика
          FLASH_SWITCH; //быстрое включение фонарика
          break;

        case UP_KEY_PRESS: //доп.действие
          search_disable = (search_disable) ? 0 : 1; //запрещаем обновление графика
          graf = 0; //разрешаем обновления экрана
          break;

        case SEL_KEY_PRESS: //выбор режима
          if (units < 2) units++; else units = 0;
          graf = 0; //разрешаем обновления экрана
          break;

        case SEL_KEY_HOLD: //настройки
          scan_buff = 0; //сбрасываем счетчик импульсов
          return MENU_PROGRAM;
      }

      if (!graf) {
        graf = 1; //запрещаем обновление графика

        clrScr(); //очистка экрана

        task_bar(S_SEARCH); //отрисовываем фон
        if (search_disable) drawBitmap(59, 0, scan_stop_img, 6, 8); //рисуем паузу
        drawBitmap(0, 8, scan_ind_scale_img, 51, 8); //рисуем шкалу
        drawLine(2, 0, 1, 0x3E); //рисуем шкалу

        switch (units) {
          case 0:
            print(S_IMP_PER_SEC, RIGHT, 8); //имп/с
#if (TYPE_CHAR_FILL > 44)
            printNumF(rad_imp, (rad_imp < 100) ? 2 : 0, 54, 16, 46, 5, TYPE_CHAR_FILL); //строка 1
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
          graf_lcd(map(search_buff[i - 4], 0, graf_max, 0, 22), i, 22, 3); //инициализируем график
        }
#else //справа-налево
        for (uint8_t i = 79; i > 3; i--) {
          graf_lcd(map(search_buff[i - 4], 0, graf_max, 0, 22), i, 22, 3); //инициализируем график
        }
#endif
      }

      drawLine(2, scan_ind + 1, 54); //убираем лишнее
      drawLine(2, 2, scan_ind, 0x3E); //рисуем полосу имп/с
      showScr(); //вывод буфера на экран
    }
  }
  return INIT_PROGRAM;
}
//--------------------------------Отрисовка графика-------------------------------------
void graf_lcd(uint8_t val, uint8_t pos, uint8_t max_val, uint8_t height) //отрисовка графика
{
  if (val > max_val) val = max_val; //ограничивываем максимум
  switch (height) {
    case 2:
      if (pos == 4) drawBitmap(0, 32, scan_left_img, 4, 16); //рисуем левую шкалу
      if (pos == 79) drawBitmap(80, 32, scan_right_img, 4, 16); //рисуем правую шкалу
      break;

    case 3:
      if (pos == 4) drawBitmap(0, 24, scan_alt_left_img, 4, 24); //рисуем левую шкалу
      if (pos == 79) drawBitmap(80, 24, scan_alt_right_img, 4, 24); //рисуем правую шкалу
      break;
  }

  for (uint8_t i = 0; i < height; i++) { //отрисовываем 3 строки
    uint8_t bits = 0; //буфер бит
    if (val >= 8) { //если уровень больше 8
      bits = 0xFF; //устанавливаем заполненный столбец
      val -= 8; //отнимаем уровень
    }
    else { //если уровень меньше 8
      while (val) { //пока есть уровень
        bits >>= 0x01; //смещаем буфер бит
        bits |= 0x80; //устанавливаем бит в буфер
        val--; //отнимаем уровень
      }
    }
    drawLine(5 - i, pos, pos, bits); //отрисовка
  }
}
//-----------------------------------Параметры-----------------------------------------
uint8_t parameters(void) //параметры
{
  while (1) {
    if (_data_update()) { //обработка данных
      switch (check_keys()) {
#if DEBUG_RETURN
        case DOWN_KEY_HOLD: //удержание кнопки вниз
        case UP_KEY_HOLD: //удержание кнопки вверх
          return DEBUG_PROGRAM;
#endif

        case SEL_KEY_HOLD: //удержание кнопки выбора
          return MENU_PROGRAM; //выход
      }

      if (!scr) {
        scr = 1; //запрещаем обновление экрана

#if TIME_OUT_PARAM
        if (++time_out > TIME_OUT_PARAM) return MAIN_PROGRAM;
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
    }
  }
  return INIT_PROGRAM;
}
//-----------------------------------Отладка---------------------------------
uint8_t debug(void) //отладка
{
  uint8_t cursor = 0; //курсор
  boolean set = ((uint8_t)pumpSettings.geiger_time < 100) ? 1 : 0; //режим знака счета времени

  while (1) {
    if (_data_update()) { //обработка данных
      switch (check_keys()) {

        case DOWN_KEY_HOLD: //переключение дробной части
        case UP_KEY_HOLD:
          if (cursor == 1) {
            set = !set;
            pumpSettings.geiger_time = (uint8_t)pumpSettings.geiger_time;
          }
          break;

        case UP_KEY_PRESS: //прибавить значение
          switch (cursor) {
            case 0: if (pumpSettings.wdt_period < MAX_WDT_PERIOD) pumpSettings.wdt_period++; break; //период
            case 1: if (pumpSettings.geiger_time < MAX_GEIGER_TIME) pumpSettings.geiger_time += (set) ? 0.1 : 1; if ((uint8_t)pumpSettings.geiger_time == 100) set = 0;  break; //счет
            case 2: if (pumpSettings.reference < 1.50) pumpSettings.reference += 0.01; break; //прибавляем опорное напряжение
            case 3: if (pumpSettings.puls < 49) pumpSettings.puls++; break; //прибавляем длинну импульса
            case 4: if (pumpSettings.k_delitel < 1500) pumpSettings.k_delitel++; break; //прибавляем коэффициент делителя
            case 5: if (pumpSettings.ADC_value < 254) pumpSettings.ADC_value++; break; //прибавляем значение АЦП для преобразователя
          }
          break;

        case DOWN_KEY_PRESS: //убавить значение
          switch (cursor) {
            case 0: if (pumpSettings.wdt_period > MIN_WDT_PERIOD) pumpSettings.wdt_period--; break; //период
            case 1: if (pumpSettings.geiger_time > MIN_GEIGER_TIME) pumpSettings.geiger_time -= (set) ? 0.1 : 1; if ((uint8_t)pumpSettings.geiger_time == 100) set = 1; break; //счет
            case 2: if (pumpSettings.reference > 0.50) pumpSettings.reference -= 0.01; break; //убавляем опорное напряжение
            case 3: if (pumpSettings.puls > 1) pumpSettings.puls--; break; //убавляем длинну импульса
            case 4: if (pumpSettings.k_delitel > 10) pumpSettings.k_delitel--; break; //убавляем коэффициент делителя
            case 5: if (pumpSettings.ADC_value > 10) pumpSettings.ADC_value--; break; //убавляем значение АЦП для преобразователя
          }
          break;

        case SEL_KEY_PRESS: //переключение пунктов
          if (++cursor > 5) cursor = 0;
          break;

        case SEL_KEY_HOLD: //выход в настройки
          settings_save(1); //сохраняем настройки преобразователя
          error_switch = 0; //сбрасываем указатель ошибки
          return MENU_PROGRAM;
      }

      if (!scr) {
        scr = 1; //запрещаем обновление экрана

#if TIME_OUT_DEBUG
        if (++time_out > TIME_OUT_DEBUG) {
          settings_save(1); //сохраняем настройки преобразователя
          error_switch = 0; //сбрасываем указатель ошибки
          return MAIN_PROGRAM;
        }
#endif

        _bat_check(); //опрос батареи

        clrScr(); //очистка экрана
        task_bar(D_DEBUG); //отрисовываем фон

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
        printNumF(0.2 * pumpSettings.puls, 1, RIGHT, 32, 46, 3, 32); //длинна импульса
        printNumI(pumpSettings.k_delitel, 20, 40); //коэффициент делителя
        printNumI(pumpSettings.ADC_value, RIGHT, 40); //значение АЦП для преобразователя

        for (uint8_t i = 0; i < 6; i++) {
          if (cursor == i) invertText(true); //включаем инверсию
          switch (i) {
            case 0: print(D_WDT_PER, LEFT, 24); break; //ПЕР
            case 1: print(D_GEIGER_TIME, 46, 24); break; //СЧ
            case 2: print(D_REFERENCE, LEFT, 32); break; //ОПР
            case 3: print(D_PULS_LEN, 46, 32); break; //ИМП
            case 4: print(D_COEF_DIV, LEFT, 40); break; //КДЛ
            case 5: print(D_PUMP_ADC, 46, 40); break; //АЦП
          }
          if (cursor == i) invertText(false); //выключаем инверсию
        }
        showScr(); //вывод буфера на экран
      }
    }
  }
  return INIT_PROGRAM;
}
//------------------------------------Отрисовка пунктов------------------------------------------------------
void _settings_item_switch(boolean set, boolean inv, uint8_t num, uint8_t pos) //отрисовка пунктов
{
  uint8_t pos_row = (pos << 3) + 8; //переводим позицию в номер строки

  if (inv) invertText(true); //включаем инверсию

  switch (num) {
    case _SET_TIME_SLEEP: //Сон
      switch (set) {
        case 0: print(S_ITEM_SLEEP, LEFT, pos_row); break; //Сон:
        case 1: if (mainSettings.sleep_switch < 2) print(ALL_SWITCH_OFF, RIGHT, pos_row); else printNumI(mainSettings.time_sleep, RIGHT, pos_row); break;
      }
      break;

    case _SET_TIME_BRIGHT: //Подсветка
      switch (set) {
        case 0: print(S_ITEM_LIGHT, LEFT, pos_row); break; //Подсветка:
        case 1: if (!mainSettings.sleep_switch) print(S_SWITCH_MANUAL, RIGHT, pos_row); else printNumI(mainSettings.time_bright, RIGHT, pos_row); break;
      }
      break;

    case _SET_CONTRAST: //Контраст
      switch (set) {
        case 0: print(S_ITEM_CONTRAST, LEFT, pos_row); break; //Контраст:
        case 1: printNumI(mainSettings.contrast, RIGHT, pos_row); break;
      }
      break;

#if ROTATE_DISP_RETURN
    case _SET_ROTATION: //Разворот
      switch (set) {
        case 0: print(S_ITEM_ROTATION, LEFT, pos_row); break; //Контраст:
        case 1: printNumI((mainSettings.rotation) ? 180 : 0, RIGHT, pos_row); break;
      }
      break;
#endif

    case _SET_RAD_FLASH: //Вспышки
      switch (set) {
        case 0: print(S_ITEM_FLASHES, LEFT, pos_row); break; //Вспышки:
        case 1: if (!mainSettings.rad_flash) print(ALL_SWITCH_OFF, RIGHT, pos_row); else if (mainSettings.rad_flash == 2) print(S_SWITCH_MANUAL_EXCEPT_SLEEP, RIGHT, pos_row); else print(ALL_SWITCH_ON, RIGHT, pos_row); break;
      }
      break;

    case _SET_VOLUME: //Громкость
      switch (set) {
        case 0: print(S_ITEM_VOLUME, LEFT, pos_row); break; //Громкость:
        case 1: printNumI(mainSettings.volume, RIGHT, pos_row); break;
      }
      break;

    case _SET_BUZZ_SWITCH: //Щелчки
      switch (set) {
        case 0: print(S_ITEM_CLICKS, LEFT, pos_row); break; //Щелчки:
        case 1: if (!mainSettings.buzz_switch) print(ALL_SWITCH_OFF, RIGHT, pos_row); else if (mainSettings.buzz_switch == 1) print(ALL_SWITCH_ON, RIGHT, pos_row); else print(S_SWITCH_BACK_1, RIGHT, pos_row); break;
      }
      break;

    case _SET_KNOCK_DISABLE: //Зв.Кнопок
      switch (set) {
        case 0: print(S_ITEM_BUTT_SOUND, LEFT, pos_row); break; //Зв.Кнопок:
        case 1: if (mainSettings.knock_disable) print(ALL_SWITCH_OFF, RIGHT, pos_row); else print(ALL_SWITCH_ON, RIGHT, pos_row); break;
      }
      break;

    case _SET_MEASUR_POS: //Разн.зам
      switch (set) {
        case 0: print(S_ITEM_DIFF_MEASUR, LEFT, pos_row); break; //Разн.зам:
        case 1: printNumI(pgm_read_byte(&diff_measuring[mainSettings.measur_pos]), RIGHT, pos_row); break;
      }
      break;

    case _SET_SIGMA_POS: //Сигма
      switch (set) {
        case 0: print(S_ITEM_SIGMA, LEFT, pos_row); break; //Сигма:
        case 1: printNumI(mainSettings.sigma_pos + 1, RIGHT, pos_row); break;
      }
      break;

    case _SET_SEARCH_POS: //Поиск
      switch (set) {
        case 0: print(S_ITEM_SEARCH, LEFT, pos_row); break; //Поиск:
        case 1: if (mainSettings.search_pos != 8) printNumI(pgm_read_word(&search_time[mainSettings.search_pos]), RIGHT, pos_row); else print(S_SWITCH_AUTO, RIGHT, pos_row); break;
      }
      break;

    case _SET_RAD_MOD: //Ед.измер
      switch (set) {
        case 0: print(S_ITEM_UNITS, LEFT, pos_row); break; //Ед.измер:
        case 1: if (!mainSettings.rad_mode) print(UNIT_UR, RIGHT, pos_row); else print(UNIT_USV, RIGHT, pos_row); break;
      }
      break;

    case _SET_ALARM_BACK: //Тревога Ф
      switch (set) {
        case 0: print(S_ITEM_ALARM_BACK, LEFT, pos_row); break; //Тревога Ф:
        case 1: if (!mainSettings.alarm_back) print(ALL_SWITCH_OFF, RIGHT, pos_row); else if (mainSettings.alarm_back == 1) print(S_SWITCH_SOUND, RIGHT, pos_row); else if (mainSettings.alarm_back == 2) print(S_SWITCH_VIBRO, RIGHT, pos_row); else print(S_SWITCH_SOUND_VIBRO, RIGHT, pos_row); break;
      }
      break;

    case _SET_WARN_LEVEL_BACK: //Порог Ф1
      switch (set) {
        case 0: print(S_ITEM_ALARM_THRESHOLD_BACK_1, LEFT, pos_row); break; //Порог Ф1:
        case 1: printNumI(mainSettings.warn_level_back, RIGHT, pos_row); break;
      }
      break;

    case _SET_ALARM_LEVEL_BACK: //Порог Ф2
      switch (set) {
        case 0: print(S_ITEM_ALARM_THRESHOLD_BACK_2, LEFT, pos_row); break; //Порог Ф2:
        case 1: printNumI(mainSettings.alarm_level_back, RIGHT, pos_row); break;
      }
      break;

    case _SET_ALARM_DOSE: //Тревога Д
      switch (set) {
        case 0: print(S_ITEM_ALARM_DOSE, LEFT, pos_row); break; //Тревога Д:
        case 1: if (!mainSettings.alarm_dose) print(ALL_SWITCH_OFF, RIGHT, pos_row); else if (mainSettings.alarm_dose == 1) print(S_SWITCH_SOUND, RIGHT, pos_row); else if (mainSettings.alarm_dose == 2) print(S_SWITCH_VIBRO, RIGHT, pos_row); else print(S_SWITCH_SOUND_VIBRO, RIGHT, pos_row); break;
      }
      break;

    case _SET_WARN_LEVEL_DOSE: //Порог Д1
      switch (set) {
        case 0: print(S_ITEM_ALARM_THRESHOLD_DOSE_1, LEFT, pos_row); break; //Порог Д1:
        case 1: printNumI(mainSettings.warn_level_dose, RIGHT, pos_row); break;
      }
      break;

    case _SET_ALARM_LEVEL_DOSE: //Порог Д2
      switch (set) {
        case 0: print(S_ITEM_ALARM_THRESHOLD_DOSE_2, LEFT, pos_row); break; //Порог Д2:
        case 1: printNumI(mainSettings.alarm_level_dose, RIGHT, pos_row); break;
      }
      break;

#if USE_UART
    case _SET_UART_MOD:
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
void _settings_data_up(uint8_t pos) //прибавление данных
{
  switch (pos)
  {
    case _SET_TIME_SLEEP: //Сон
      switch (mainSettings.sleep_switch) {
        case 0: mainSettings.sleep_switch = 2; _LIGHT_ON(); break;
        case 1: mainSettings.sleep_switch = 2; mainSettings.time_bright = 5; break;
        case 2: if (mainSettings.time_sleep < 250) mainSettings.time_sleep += 5; break;
      }
      break;
    case _SET_TIME_BRIGHT: //Подсветка
      switch (mainSettings.sleep_switch) {
        case 0: mainSettings.sleep_switch = 1; LIGHT_ON; break;
        case 1: if (mainSettings.time_bright < 250) mainSettings.time_bright += 5; break;
        case 2: if (mainSettings.time_bright < mainSettings.time_sleep - 5) mainSettings.time_bright += 5; break;
      }
      break;
    case _SET_CONTRAST: if (mainSettings.contrast < 127) setContrast(++mainSettings.contrast); break; //Контраст
#if ROTATE_DISP_RETURN
    case _SET_ROTATION: mainSettings.rotation = 1; break; //Разворот
#endif
    case _SET_RAD_FLASH: if (mainSettings.rad_flash < 2) mainSettings.rad_flash++; break; //Вспышки
    case _SET_VOLUME: if (mainSettings.volume < 10) mainSettings.volume++; break; //Громкость
    case _SET_BUZZ_SWITCH: if (mainSettings.buzz_switch < 2) mainSettings.buzz_switch++; break; //Щелчки
    case _SET_KNOCK_DISABLE: mainSettings.knock_disable = 0; break; //Зв.кнопок

    case _SET_MEASUR_POS: if (mainSettings.measur_pos < 9) mainSettings.measur_pos++; break; //Разн.зам
    case _SET_SIGMA_POS: if (mainSettings.sigma_pos < 2) mainSettings.sigma_pos++; else mainSettings.sigma_pos = 0; break; //Сигма
    case _SET_SEARCH_POS: if (mainSettings.search_pos < 8) mainSettings.search_pos++; else mainSettings.search_pos = 0; break; //Поиск
    case _SET_RAD_MOD: mainSettings.rad_mode = 1; break; //Ед.измер

    case _SET_ALARM_BACK: if (mainSettings.alarm_back < 3) mainSettings.alarm_back++; break; //Тревога Ф
    case _SET_WARN_LEVEL_BACK: if (mainSettings.warn_level_back < 300) mainSettings.warn_level_back += 5; else mainSettings.warn_level_back = 30; break; //Порог Ф1
    case _SET_ALARM_LEVEL_BACK: if (mainSettings.alarm_level_back < 500) mainSettings.alarm_level_back += 10; else if (mainSettings.alarm_level_back < 1000) mainSettings.alarm_level_back += 50; else if (mainSettings.alarm_level_back < 65000) mainSettings.alarm_level_back += 100; else mainSettings.alarm_level_back = 300; break; //Порог Ф2
    case _SET_ALARM_DOSE: if (mainSettings.alarm_dose < 3) mainSettings.alarm_dose++; break; //Тревога Д
    case _SET_WARN_LEVEL_DOSE: if (mainSettings.warn_level_dose < 300) mainSettings.warn_level_dose += 5; else mainSettings.warn_level_dose = 10; break; //Порог Д1
    case _SET_ALARM_LEVEL_DOSE: if (mainSettings.alarm_level_dose < 500) mainSettings.alarm_level_dose += 10; else if (mainSettings.alarm_level_dose < 1000) mainSettings.alarm_level_dose += 50; else if (mainSettings.alarm_level_dose < 65000) mainSettings.alarm_level_dose += 100; else mainSettings.alarm_level_dose = 300; break; //Порог Д2
#if USE_UART
    case _SET_UART_MOD: if (!UCSR0B) dataChannelInit(); else dataChannelEnd(); break; //Порт
#endif
  }
}
//------------------------------------Убавление данных------------------------------------------------------
void _settings_data_down(uint8_t pos) //убавление данных
{
  switch (pos)
  {
    case _SET_TIME_SLEEP: if (mainSettings.time_sleep > 10) { //Сон
        mainSettings.time_sleep -= 5;
        if (mainSettings.time_bright == mainSettings.time_sleep) mainSettings.time_bright -= 5;
      }
      else if (mainSettings.sleep_switch == 2) mainSettings.sleep_switch = 1; break;
    case _SET_TIME_BRIGHT: if (mainSettings.time_bright > 5) mainSettings.time_bright -= 5; else mainSettings.sleep_switch = 0; break; //Подсветка
    case _SET_CONTRAST: if (mainSettings.contrast) setContrast(--mainSettings.contrast); break; //Контраст
#if ROTATE_DISP_RETURN
    case _SET_ROTATION: mainSettings.rotation = 0; break; //Разворот
#endif
    case _SET_RAD_FLASH: if (mainSettings.rad_flash) mainSettings.rad_flash--; break; //Вспышки
    case _SET_VOLUME: if (mainSettings.volume > 1) mainSettings.volume--; break; //Громкость
    case _SET_BUZZ_SWITCH: if (mainSettings.buzz_switch) mainSettings.buzz_switch--; break; //Щелчки
    case _SET_KNOCK_DISABLE: mainSettings.knock_disable = 1; break; //Зв.кнопок

    case _SET_MEASUR_POS: if (mainSettings.measur_pos) mainSettings.measur_pos--;  break; //Разн.зам
    case _SET_SIGMA_POS: if (mainSettings.sigma_pos) mainSettings.sigma_pos--; else mainSettings.sigma_pos = 2; break; //Сигма
    case _SET_SEARCH_POS: if (mainSettings.search_pos) mainSettings.search_pos--; else mainSettings.search_pos = 8; break; //Поиск
    case _SET_RAD_MOD: mainSettings.rad_mode = 0; break; //Ед.измер

    case _SET_ALARM_BACK: if (mainSettings.alarm_back) mainSettings.alarm_back--; break; //Тревога Ф
    case _SET_WARN_LEVEL_BACK: if (mainSettings.warn_level_back > 30) mainSettings.warn_level_back -= 5; else mainSettings.warn_level_back = 300; break; //Порог Ф1
    case _SET_ALARM_LEVEL_BACK: if (mainSettings.alarm_level_back > 1000) mainSettings.alarm_level_back -= 100; else if (mainSettings.alarm_level_back > 500) mainSettings.alarm_level_back -= 50; else if (mainSettings.alarm_level_back > 300) mainSettings.alarm_level_back -= 10; else mainSettings.alarm_level_back = 65000; break; //Порог Ф2
    case _SET_ALARM_DOSE: if (mainSettings.alarm_dose) mainSettings.alarm_dose--; break; //Тревога Д
    case _SET_WARN_LEVEL_DOSE: if (mainSettings.warn_level_dose > 10) mainSettings.warn_level_dose -= 5; else mainSettings.warn_level_dose = 300; break; //Порог Д1
    case _SET_ALARM_LEVEL_DOSE: if (mainSettings.alarm_level_dose > 1000) mainSettings.alarm_level_dose -= 100; else if (mainSettings.alarm_level_dose > 500) mainSettings.alarm_level_dose -= 50; else if (mainSettings.alarm_level_dose > 300) mainSettings.alarm_level_dose -= 10; else mainSettings.alarm_level_dose = 65000; break; //Порог Д2
#if USE_UART
    case _SET_UART_MOD: if (!UCSR0B) dataChannelInit(); else dataChannelEnd(); break; //Порт
#endif
  }
}
//------------------------------------Настройки------------------------------------------------------
uint8_t settings(void) //настройки
{
  uint8_t pos = 0; //позиция
  uint8_t cursor = 0; //курсор
  boolean set = 0; //разрешение на настройку

  while (1) {
    if (_data_update()) { //обработка данных
      switch (check_keys()) {
        case DOWN_KEY_HOLD: //вкл/выкл посветки
          fast_light(); //быстрое включение посветки
          break;

        case DOWN_KEY_PRESS: //вниз
          switch (set) {
            case 0:
              if (pos < _SET_MENU_ALL - 1) { //изменяем позицию
                pos++;
                if (cursor < 4) cursor++; //изменяем положение курсора
              }
              else { //иначе начало списка
                pos = 0;
                cursor = 0;
              }
              break;
            case 1: _settings_data_down(pos); break; //убавление данных
          }
          break;

        case UP_KEY_PRESS: //вверх
          switch (set) {
            case 0:
              if (pos > 0) { //изменяем позицию
                pos--;
                if (cursor > 0) cursor--; //изменяем положение курсора
              }
              else { //иначе конец списка
                pos = _SET_MENU_ALL - 1;
                cursor = 4;
              }
              break;
            case 1: _settings_data_up(pos); break; //прибавление данных
          }
          break;

        case UP_KEY_HOLD: //вкл/выкл фонарика
          FLASH_SWITCH; //быстрое включение фонарика
          break;

        case SEL_KEY_PRESS: //select key //выбор
          set = !set;
          break;

        case SEL_KEY_HOLD: //выход из настроек
          settings_save(0); //сохраняем настройки
          return MAIN_PROGRAM;
      }

      if (!scr) {
        scr = 1; //запрещаем обновления экрана

#if TIME_OUT_SETTINGS
        if (++time_out > TIME_OUT_SETTINGS) {
          settings_save(0); //сохраняем настройки
          return MAIN_PROGRAM;
        }
#endif

        clrScr(); // Очистка экрана
        task_bar(S_SETTINGS); //отрисовываем фон

        for (uint8_t i = 0; i < 5; i++) { //отсчет строк
          for (uint8_t r = 0; r < 2; r++) { //отсчет позиции
            boolean inv = (i == cursor && r == set); //если курсор на нужной строке
            _settings_item_switch(r, inv, pos - cursor + i, i); //отрисовываем пункты настроек
          }
        }
        showScr(); //вывод буфера на экран
      }
    }
  }
  return INIT_PROGRAM;
}
//------------------------------------Отрисовка пунктов------------------------------------------------------
void _menu_item_switch(boolean inv, uint8_t num, uint8_t pos) //отрисовка пунктов
{
  uint8_t pos_row = (pos << 3) + 8; //переводим позицию в номер строки

  if (inv) {
    drawLine(pos + 1, 0, 83, 0xFF); //рисуем линию
    invertText(true); //включаем инверсию
  }

  switch (num) {
    case MAIN_PROGRAM: print(MAIN_BACK_DOSE, CENTER, pos_row); break; //Фон / Доза
    case SEARCH_PROGRAM: print(MAIN_SEARCH, CENTER, pos_row); break; //Режим поиска
    case MEASUR_PROGRAM: print(MAIN_MEASUR, CENTER, pos_row); break; //Замер бета
    case LOGBOOK_PROGRAM: print(MAIN_LOGBOOK, CENTER, pos_row); break; //Журнал
    case SETTINGS_PROGRAM: print(MAIN_SETTINGS, CENTER, pos_row); break; //Настройки
    case PARAMETERS_PROGRAM: print(MAIN_PARAM, CENTER, pos_row); break; //Параметры
    case POWER_DOWN_PROGRAM: print(MAIN_POWER_DOWN, CENTER, pos_row); break; //Выключение
  }
  invertText(false); //выключаем инверсию
}
//------------------------------------Меню------------------------------------------------------
uint8_t menu(void) //меню
{
  static uint8_t pos; //позиция
  static uint8_t cursor; //курсор

  sleep_disable = 1; //запрещаем сон
  power_manager = 0; //сбрасываем менеджер питания

  while (1) {
    if (_data_update()) { //обработка данных
      switch (check_keys()) {
        case DOWN_KEY_HOLD: //вкл/выкл посветки
          fast_light(); //быстрое включение посветки
          break;

        case DOWN_KEY_PRESS: //вниз
          if (pos < 6) { //изменяем позицию
            pos++;
            if (cursor < 4) cursor++; //изменяем положение курсора
          }
          else { //иначе начало списка
            pos = 0;
            cursor = 0;
          }
          break;

        case UP_KEY_PRESS: //вверх
          if (pos > 0) { //изменяем позицию
            pos--;
            if (cursor > 0) cursor--; //изменяем положение курсора
          }
          else { //иначе конец списка
            pos = 6;
            cursor = 4;
          }
          break;

        case UP_KEY_HOLD: //вкл/выкл фонарика
          FLASH_SWITCH; //быстрое включение фонарика
          break;

        case SEL_KEY_PRESS: //выбор пункта
          return pos + 1; //возвращаем выбранный пункт меню


        case SEL_KEY_HOLD: //выход к главным экранам
          return MAIN_PROGRAM;
      }

      if (!scr) {
        scr = 1; //запрещаем обновления экрана

#if TIME_OUT_MENU
        if (++time_out > TIME_OUT_MENU) return MAIN_PROGRAM;
#endif

        clrScr(); // Очистка экрана
        task_bar(MAIN_MENU); //отрисовываем фон

        for (uint8_t i = 0; i < 5; i++) _menu_item_switch((i == cursor) ? 1 : 0, pos - cursor + i + 1, i); //отрисовываем пункты настроек
        showScr(); //вывод буфера на экран
      }
    }
  }
  return INIT_PROGRAM;
}
//------------------------------------Отрисовка пунктов настроек журнала------------------------------------------------------
void _logbook_settings(boolean inv, uint8_t num, uint8_t pos) //отрисовка пунктов настроек журнала
{
  uint8_t pos_row = (pos << 3) + 8; //переводим позицию в номер строки

  if (inv) {
    drawLine(pos + 1, 0, 83, 0xFF); //рисуем линию
    invertText(true); //включаем инверсию
  }

  switch (num) {
    case 0: print(L_SETTINGS_ALARM, LEFT, pos_row); if (bookSettings.logbook_alarm) print(ALL_SWITCH_ON, RIGHT, pos_row); else print(ALL_SWITCH_OFF, RIGHT, pos_row); break; //Тревога
    case 1: print(L_SETTINGS_WARN, LEFT, pos_row); if (bookSettings.logbook_warn) print(ALL_SWITCH_ON, RIGHT, pos_row); else print(ALL_SWITCH_OFF, RIGHT, pos_row); break; //Опасность
    case 2: print(L_SETTINGS_MEASUR, LEFT, pos_row); if (bookSettings.logbook_measur) print(ALL_SWITCH_ON, RIGHT, pos_row); else print(ALL_SWITCH_OFF, RIGHT, pos_row); break; //Замеры бета
    case 3: print(L_SETTINGS_CLEAR, CENTER, pos_row); break; //Очистить
  }
  invertText(false); //выключаем инверсию
}
//------------------------------------Отрисовка пунктов журнала------------------------------------------------------
void _logbook_item_switch(boolean inv, uint8_t num, uint8_t pos) //отрисовка пунктов журнала
{
  uint8_t pos_row = (pos << 3) + 8; //переводим позицию в номер строки

  if (inv) {
    drawLine(pos + 1, 0, 83, 0xFF); //рисуем линию
    invertText(true); //включаем инверсию
  }

  switch (num) {
    case 0: print(L_ITEM_ALARM, CENTER, pos_row); if (bookSettings.logbook_alarm == 2) print(L_ITEM_ASTER, RIGHT, pos_row); break; //Тревога
    case 1: print(L_ITEM_WARN, CENTER, pos_row); if (bookSettings.logbook_warn == 2) print(L_ITEM_ASTER, RIGHT, pos_row); break; //Опасность
    case 2: print(L_ITEM_MEASUR, CENTER, pos_row); if (bookSettings.logbook_measur == 2) print(L_ITEM_ASTER, RIGHT, pos_row); break; //Замеры бета
    case 3: print(L_ITEM_ERRORS, CENTER, pos_row); if (error_switch) print(L_ITEM_ASTER, RIGHT, pos_row); break; //Ошибки
    case 4: print(L_ITEM_SETTINGS, CENTER, pos_row); break; //Настройки
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
    drawLine(pos + 1, 0, 83, 0xFF); //рисуем линию
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
  for (uint16_t cell = 200; cell < 240; cell++) EEPROM_UpdateByte(cell, 0); //стираем заглавления
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
uint8_t logbook(void) //журнал
{
#if LOGBOOK_RETURN
  uint8_t pos = 0; //позиция
  uint8_t cursor = 0; //курсор
  uint8_t point = 0; //пункт
  boolean err_sw = 0; //переключение подрежима ошибок
  uint8_t max_item = 4; //максимум пунктов

  while (1) {
    if (_data_update()) { //обработка данных
      switch (check_keys()) {
        case DOWN_KEY_HOLD: //вкл/выкл посветки
          fast_light(); //быстрое включение посветки
          break;

        case DOWN_KEY_PRESS: //вниз
          if (pos < max_item) { //изменяем позицию
            pos++;
            if (cursor < 4) cursor++; //изменяем положение курсора
          }
          else { //иначе начало списка
            pos = 0;
            cursor = 0;
          }
          break;

        case UP_KEY_PRESS: //вверх
          if (pos > 0) { //изменяем позицию
            pos--;
            if (cursor > 0) cursor--; //изменяем положение курсора
          }
          else { //иначе конец списка
            pos = max_item;
            cursor = (max_item < 4) ? max_item : 4;
          }
          break;

        case UP_KEY_HOLD: //вкл/выкл фонарика
          FLASH_SWITCH; //быстрое включение фонарика
          break;

        case SEL_KEY_PRESS: //выбор
          switch (point) {
            case 0:
              point = pos + 1;
              pos = cursor = 0;
              max_item = (point != 5) ? 9 : 3;
              switch (point) {
                case 1: if (bookSettings.logbook_alarm) bookSettings.logbook_alarm = 1; break; //сбрасываем флаг журнала тревоги
                case 2: if (bookSettings.logbook_warn) bookSettings.logbook_warn = 1; break; //сбрасываем флаг журнала предупрежлений
                case 3: if (bookSettings.logbook_measur) bookSettings.logbook_measur = 1; break; //сбрасываем флаг журнала замеров
                case 4: if (error_switch) error_switch = 0; break; //сбрасываем флаг журнала ошибок
              }
              break;
            case 4: err_sw = (err_sw) ? 0 : 1; break; //переходим на предпросмотр ошибки
            case 5:
              switch (pos) {
                case 0: bookSettings.logbook_alarm = (bookSettings.logbook_alarm) ? 0 : 1; break; //вкл/выкл журнала тревоги
                case 1: bookSettings.logbook_warn = (bookSettings.logbook_warn) ? 0 : 1; break; //вкл/выкл журнала предупреждений
                case 2: bookSettings.logbook_measur = (bookSettings.logbook_measur) ? 0 : 1; break; //вкл/выкл журнала замеров
                case 3: data_reset(2); break;
              }
              break;
          }
          break;

        case SEL_KEY_HOLD: //выход к главным экранам
          switch (point) {
            case 0: return MENU_PROGRAM;
            case 5: settings_save(2); pos = cursor = point - 1; point = 0; max_item = 4; break; //сохраняем настройки
            default: pos = cursor = point - 1; point = err_sw = 0; max_item = 4; break;
          }
          break;
      }

      if (!scr) {
        scr = 1; //запрещаем обновления экрана

#if TIME_OUT_LOGBOOK
        if (++time_out > TIME_OUT_LOGBOOK) return MAIN_PROGRAM;
#endif

        clrScr(); // Очистка экрана
        task_bar(L_LOGBOOK); //отрисовываем фон

        if (!err_sw) {
          for (uint8_t i = 0; i < 5; i++) {
            switch (point) {
              case 0: _logbook_item_switch((i == cursor) ? 1 : 0, pos - cursor + i, i); break; //отрисовываем пункты настроек
              case 5: _logbook_settings((i == cursor) ? 1 : 0, pos - cursor + i, i); break; //отрисовываем пункты настроек
              default: _logbook_data_switch((i == cursor) ? 1 : 0, pos - cursor + i, i, point - 1); break; //отрисовывам информацию
            }
          }
        }
        else _init_error_messege(_data_read_byte(pos, 230), _data_read_dword(pos, 360)); //отрисовка информации
        showScr(); //вывод буфера на экран
      }
    }
  }
#else
  uint8_t pos = 0; //позиция
  uint8_t cursor = 0; //курсор

  while (1) {
    if (_data_update()) { //обработка данных
      switch (check_keys()) {
        case DOWN_KEY_HOLD: //вкл/выкл посветки
          fast_light(); //быстрое включение посветки
          break;

        case DOWN_KEY_PRESS: //вниз
          if (pos < 9) { //изменяем позицию
            pos++;
            if (cursor < 4) cursor++; //изменяем положение курсора
          }
          else { //иначе начало списка
            pos = 0;
            cursor = 0;
          }
          break;

        case UP_KEY_PRESS: //вверх
          if (pos > 0) { //изменяем позицию
            pos--;
            if (cursor > 0) cursor--; //изменяем положение курсора
          }
          else { //иначе конец списка
            pos = 9;
            cursor = 4;
          }
          break;

        case UP_KEY_HOLD: //вкл/выкл фонарика
          FLASH_SWITCH; //быстрое включение фонарика
          break;

        case SEL_KEY_PRESS: //выбор
          data_reset(2); //очистка журнала
          break;

        case SEL_KEY_HOLD: //выход к главным экранам
          return MENU_PROGRAM;
      }

      if (!scr) {
        scr = 1; //запрещаем обновления экрана

#if TIME_OUT_LOGBOOK
        if (++time_out > TIME_OUT_LOGBOOK) return MAIN_PROGRAM;
#endif

        clrScr(); // Очистка экрана
        task_bar(L_LOGBOOK); //отрисовываем фон

        for (uint8_t i = 0; i < 5; i++) _logbook_data_switch((i == cursor) ? 1 : 0, pos - cursor + i, i, 2); //отрисовывам информацию
        showScr(); //вывод буфера на экран
      }
    }
  }
#endif
  return INIT_PROGRAM;
}
//-----------------------------------Вкл/выкл подсветки---------------------------------
void fast_light(void) //вкл/выкл подсветки
{
  if (!mainSettings.sleep_switch) { //если сон выключен
    if (light_switch) _LIGHT_OFF(); //выключаем подсветку, если была включена настройками
    else _LIGHT_ON(); //включаем подсветку
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
void _error_messege(void) //сообщение об ошибке
{
#if LOGBOOK_RETURN
  if (error_switch == 2 && !alarm_switch && !error_massege) { //если время вышло, выводим ошибку
#else
  if (error_switch && !alarm_switch && !error_massege) { //если время вышло, выводим ошибку
#endif
    error_massege = 1; //сбрасываем флаг отображения ошибки

    _disable_sleep(); //просыпаемся если спали

#if LOGBOOK_RETURN
    _init_error_messege(_data_read_byte(0, 230), _data_read_dword(0, 360));
#else
    clrScr(); //очистка экрана

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

    melodyPlay(SOUND_ERROR, REPLAY_ONCE); //звук ошибки

    for (timer_millis = ERROR_MASSEGE_TIME; timer_millis;) { //ждем
      if (_data_update() && check_keys()) { //обработка данных
        error_switch = 0; //сбрасываем флаг ошибки
        return;
      }
    }
#if LOGBOOK_RETURN
    error_switch = 1; //сбрасываем указатель ошибки
#else
    error_switch = 0; //сбрасываем указатель ошибки
#endif
  }
}
//---------------------------------------Стирание статистики--------------------------------------------------
void _statistic_erase(void) //стирание статистики
{
  cur_dose_cell = 0; //сбрасываем текущую ячейку
  for (uint16_t cell = 510; cell < 766; cell++) EEPROM_UpdateByte(cell, 0); //стираем заглавления времени
}
//---------------------------------------Чтение статистики--------------------------------------------------
void statistic_read(void) //чтение статистики
{
  uint32_t maxData = 0; //максимальное значение ячейки
  uint32_t tempData = 0; //временный буфер
  for (uint8_t c = 0; c < 64; c++) {
    uint16_t search_cell = 510 + (4 * c); //находим запрашиваемую позицию
    EEPROM_ReadBlock((uint16_t)&tempData, search_cell, sizeof(tempData));
    if (maxData < tempData) { //если буфер меньше ячейки
      maxData = tempData; //записываем в буфер значение ячейки
      cur_dose_cell = c; //устанавливаем последнюю ячейку
    }
    else break; //завершаем поиск
  }
  if (maxData) { //если в буфере есть информация
    uint16_t time_cell = 510 + (4 * cur_dose_cell); //находим запрашиваемую позицию
    EEPROM_ReadBlock((uint16_t)&tempData, time_cell, sizeof(tempData));
    time_save = tempData; //считываем время
    uint16_t dose_cell = 766 + (4 * cur_dose_cell); //находим запрашиваемую позицию
    EEPROM_ReadBlock((uint16_t)&tempData, dose_cell, sizeof(tempData));
    rad_dose_save = tempData; //считываем дозу
    if (++cur_dose_cell > 63) cur_dose_cell = 0; //меняем ячейку
  }
}
//----------------------------------Обновление статистики------------------------------------------
void statistic_update(void) //обновление статистики
{
  time_save += time_sec - time_save_old; //добавляем время
  time_save_old = time_sec; //сбрасывае счетчик времени
  rad_dose_save += rad_dose - rad_dose_old; //добавляем дозу
  rad_dose_old = rad_dose; //сбрасывае счетчик дозы

  uint16_t time_cell = 510 + (4 * cur_dose_cell); //находим запрашиваемую позицию
  EEPROM_UpdateBlock((uint16_t)&time_save, time_cell, sizeof(time_save)); //записываем время
  uint16_t dose_cell = 766 + (4 * cur_dose_cell); //находим запрашиваемую позицию
  EEPROM_UpdateBlock((uint16_t)&rad_dose_save, dose_cell, sizeof(rad_dose_save)); //записываем дозу
  if (++cur_dose_cell > 63) cur_dose_cell = 0; //меняем ячейку
}
//------------------------------------Разрешить щелчки----------------------------------------------
void _buzz_enable(void) //разрешить щелчки
{
  mainSettings.buzz_switch &= ~0x80;
}
//------------------------------------Запретить щелчки----------------------------------------------
void _buzz_disable(void) //запретить щелчки
{
  mainSettings.buzz_switch |= 0x80;
}
//----------------------------------Сброс текущей дозы----------------------------------------------
void data_reset(uint8_t sw) //сброс текущей дозы
{
  uint8_t cursor = 0; //курсор
  sleep_disable = 1; //запрещаем сон
  power_manager = 0; //сбрасываем менеджер питания

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
    if (_data_update()) { //обработка данных
      switch (check_keys()) {
        case DOWN_KEY_PRESS: cursor = 0; break; //выбор нет
        case UP_KEY_PRESS: cursor = 1; break; //выбор да

        case SEL_KEY_PRESS: //выбор пункта
          switch (cursor) {
            case 1:
              clrScr(); //очистка экрана
              switch (sw) {
                case 0: //текущая доза
#if GEIGER_OWN_BACK
                  rad_sum_timer = 0;
#endif
                  rad_sum = 0;
                  rad_dose = 0;
                  rad_dose_old = 0;

                  rad_dose_save += rad_dose - rad_dose_old;
                  time_save += time_sec - time_save_old;
                  time_save_old = 0;
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
              showScr(); //вывод буфера на экран
              _wait(MASSEGE_TIME); //ждем
              break;
          }
          return; //выход
      }

      if (!scr) {
        scr = 1; //запрещаем обновление экрана
#if TIME_OUT_DATA
        if (++time_out > TIME_OUT_DATA) return;
#endif

        choice_menu(cursor); //меню выбора
        showScr(); //вывод буфера на экран
      }
    }
  }
}
//---------------------------------------Сохранить настройки--------------------------------------------
void settings_save(uint8_t sw) //сохранить настройки
{
  boolean cursor = 0; //курсор

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

  _disable_sleep(); //выход из сна

  clrScr(); //очистка экрана
  print(W_SAVE, CENTER, 8); //Сохранить
  print(W_SETTINGS, CENTER, 16); //настройки?

  while (1) {
    if (_data_update()) { //обработка данных
      switch (check_keys()) {
        case DOWN_KEY_PRESS: cursor = 0; break; //выбор нет
        case UP_KEY_PRESS: cursor = 1; break; //выбор да

        case SEL_KEY_PRESS: //выбор пункта
          switch (cursor) {
            case 1:
              clrScr(); //очистка экрана
              print(W_SETTINGS_SUCC, CENTER, 16); //Настройки
              print(W_SAVE_SUCC, CENTER, 24); //Сохранены!
              switch (sw) {
                case 0: updateData((uint8_t*)&mainSettings, sizeof(mainSettings), EEPROM_BLOCK_SETTINGS_MAIN, EEPROM_BLOCK_CRC_MAIN); BUZZ_VOL_SET(mainSettings.volume); break; //обновляем настройки
#if DEBUG_RETURN
                case 1: updateData((uint8_t*)&pumpSettings, sizeof(pumpSettings), EEPROM_BLOCK_SETTINGS_PUMP, EEPROM_BLOCK_CRC_PUMP); break; //обновляем настройки
#endif
#if LOGBOOK_RETURN
                case 2: updateData((uint8_t*)&bookSettings, sizeof(bookSettings), EEPROM_BLOCK_SETTINGS_BOOK, EEPROM_BLOCK_CRC_BOOK); break; //обновляем настройки
#endif
              }
              showScr(); //вывод буфера на экран
              _wait(MASSEGE_TIME); //ждем
              break;

            case 0:
              switch (sw) {
                case 0: EEPROM_ReadBlock((uint16_t)&mainSettings, EEPROM_BLOCK_SETTINGS_MAIN, sizeof(mainSettings)); setContrast(mainSettings.contrast); break; //считываем настройки из памяти
#if DEBUG_RETURN || PUMP_READ_MEM
                case 1: EEPROM_ReadBlock((uint16_t)&pumpSettings, EEPROM_BLOCK_SETTINGS_PUMP, sizeof(pumpSettings)); break; //считываем настройки из памяти
#endif
#if LOGBOOK_RETURN
                case 2: EEPROM_ReadBlock((uint16_t)&bookSettings, EEPROM_BLOCK_SETTINGS_BOOK, sizeof(bookSettings)); break; //считываем настройки из памяти
#endif
              }
              break;
          }
          return;
      }

      if (!scr) {
        scr = 1; //сбрасываем флаг
#if TIME_OUT_SETTINGS
        if (++time_out > TIME_OUT_SETTINGS) {
          switch (sw) {
            case 0: EEPROM_ReadBlock((uint16_t)&mainSettings, EEPROM_BLOCK_SETTINGS_MAIN, sizeof(mainSettings)); setContrast(mainSettings.contrast); break; //считываем настройки из памяти
#if DEBUG_RETURN || PUMP_READ_MEM
            case 1: EEPROM_ReadBlock((uint16_t)&pumpSettings, EEPROM_BLOCK_SETTINGS_PUMP, sizeof(pumpSettings)); break; //считываем настройки из памяти
#endif
#if LOGBOOK_RETURN
            case 2: EEPROM_ReadBlock((uint16_t)&bookSettings, EEPROM_BLOCK_SETTINGS_BOOK, sizeof(bookSettings)); break; //считываем настройки из памяти
#endif
          }
          return; //выходим
        }
#endif

        choice_menu(cursor); //меню выбора
        showScr(); //вывод буфера на экран
      }
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
//----------------------------------Инициализация прочерков------------------------------------------------------
void _init_dash_unit(boolean type, uint8_t char_all, uint8_t char_unit, uint8_t num_x, uint8_t num_y) //инициализация прочерков
{
  for (uint8_t i = 0; i < char_all; i++) {
    if (type) setFont(MediumNumbers); //установка шрифта
    print(UNIT_DASH, (num_x == RIGHT) ? 84 - char_all * cfont.x_size - char_unit + i * cfont.x_size : num_x + i * cfont.x_size, num_y);
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
void _alarm_init(uint8_t wait, uint8_t alarm) //индикация тревоги
{
  if (wait) drawBitmap(60, 0, beep_alt_wait_img, 7, 8); //если ждем понижения фона
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
  drawLine(0, 0, 83, 0xFF); //рисуем линию
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
      drawLine(3, 2, map(num, 0, max_back, (i) ? pgm_read_word(&back_scale[i - 1][1]) : 2, pgm_read_word(&back_scale[i][1])), 0x18); //рисуем шкалу
      return; //возврат
    }
  }
  drawLine(3, 2, 81, 0x18); //иначе рисуем полную шкалу
}
//----------------------------------Главные экраны------------------------------------------------------
uint8_t main_screen(void)
{
  static uint8_t back_mode; //переключатель режима фон
  sleep_disable = 0; //разрешаем сон

  while (1) {
    if (_data_update()) { //обработка данных
      _error_messege(); //обработка сообщений ошибок
      _alarm_warning(); //обработка сообщений тревоги

      switch (check_keys()) {
        case DOWN_KEY_HOLD: //вкл/выкл посветки
          fast_light(); //быстрое включение посветки
          break;

        case DOWN_KEY_PRESS: //сброс
          if (skip_warn_messege()) { //если нет предупреждения
            switch (scr_mode) { //основные экраны
              case 0: //сбрасываем фон
                for (uint8_t i = 0; i < BUFF_LENGTHY; i++) rad_buff[i] = 0; //очищаем буфер фона
                accur_percent = 99; //сбрасываем статистическую точность
                back_time_now = geiger_time_now = 0; //сбрасываем счетчик накопления импульсов в буфере
                mid_time_now = 0; //сбрасываем рассчет среднего
                rad_back = 0; //сбрасываем фон

                if (back_mode) { //сбрасываем максимальный фон и средний фон
                  rad_min = 0; //сбрасываем среднее значение фона
                  rad_max = 0; //сбрасываем максимальное значение фона
                }
                break;

              case 1: data_reset(dose_mode); return MAIN_PROGRAM; //сбрасываем дозу и время
            }
          }
          break;

        case UP_KEY_PRESS: //доп.действие
          if (skip_warn_messege()) { //если нет предупреждения
            switch (scr_mode) { //основные экраны
              case 0: back_mode = !back_mode; break; //переключаем экраны фона
              case 1: dose_mode = !dose_mode; break; //переключаем экраны дозы
            }
          }
          break;

        case UP_KEY_HOLD: //вкл/выкл фонарика
          if (skip_warn_messege()) FLASH_SWITCH; //быстрое включение фонарика
          break;

        case SEL_KEY_PRESS: //выбор режима
          if (skip_warn_messege()) scr_mode = !scr_mode; break; //переключение фон/доза
          break;

        case SEL_KEY_HOLD: //настройки
          if (skip_warn_messege()) return MENU_PROGRAM; //если нет тревоги
          break;
      }

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
        else if (!mainSettings.knock_disable) drawBitmap(47, 0, beep_alt_wait_img, 7, 8); //если щелчки выключены и зв.кнопок включен
        else drawBitmap(47, 0, buzz_alt_off_img, 7, 8); //иначе выключено все

#if LOGBOOK_RETURN
        static boolean anim; //переключатель мигания
        if (error_switch) {
          if (anim) drawBitmap(27, 0, error_ico_img, 14, 8); //ERR
          anim = !anim;
        }
        else {
          if (bookSettings.logbook_alarm == 2 || bookSettings.logbook_warn == 2 || bookSettings.logbook_measur == 2) {
            if (anim) drawBitmap(32, 0, logbook_ico_img, 9, 8); //logbook
            anim = !anim;
          }
          else if (bookSettings.logbook_alarm == 1 || bookSettings.logbook_warn == 1 || bookSettings.logbook_measur == 1) drawBitmap(32, 0, logbook_ico_img, 9, 8); //logbook
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
                drawLine(3, 1, map(geiger_time_now, 0, BUFF_LENGTHY, 5, 82), 0x06); //шкала точности
                drawLine(3, 1, map(mid_time_now, 0, MID_BUFF_LENGTHY, 5, 82), 0x30); //шкала усреднения
#endif
                break;
              case 3: _init_alarm_massage(0, 24); break; //предупреждение
            }

            switch (back_mode) {
              case 0: for (uint8_t i = 4; i < 80; i++) graf_lcd(map(rad_buff[(i >> 1) - 1], 0, (graf_max < 15) ? 15 : graf_max, 0, 15), i, 15, 2); break; //инициализируем график
              case 1: //максимальный и средний фон
#if COEF_DEBUG //отладка коэффициента
                print(D_COEF_NOW, 0, 32); //строка 1 текущ:
                printNumF(now, 2, RIGHT, 32, 46, 5, 43); //строка 1

                print(D_COEF_LIMIT, 0, 40); //строка 2
                printNumF(debug_coef, 2, RIGHT, 40, 46, 5, 43); //строка 2
#else
                print(MAIN_SCREEN_BACK_MIN, 0, 32); //строка 1 мин:
                _init_rads_unit(0, rad_min, 1, 4, RIGHT, 32, 0, RIGHT, 32, (accur_percent > RAD_ACCUR_START) ? 1 : 0); //строка 2 минимальный

                print(MAIN_SCREEN_BACK_MAX, 0, 40); //строка 2 макс:
                _init_rads_unit(0, rad_max, 1, 4, RIGHT, 40, 0, RIGHT, 40, (accur_percent > RAD_ACCUR_START) ? 1 : 0); //строка 3 максимальный
#endif
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
                  case 0: drawLine(4, 1, map(stat_upd_tmr, 0, STAT_UPD_TIME, 5, 82), 0x30); break; //шкала времени до сохранения дозы
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
    }
  }
  return INIT_PROGRAM;
}
