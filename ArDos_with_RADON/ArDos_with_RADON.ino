/*Arduino IDE 1.8.13
  Версия программы RADON v4.4.5 low_pwr release 17.02.25 специально для проекта ArDos
  Страница проекта ArDos http://arduino.ru/forum/proekty/ardos-dozimetr-prodolzhenie-temy-chast-%E2%84%962 и прошивки RADON https://github.com/radon-lab/ArDos_with_RADON
  Желательна установка OptiBoot v8 https://github.com/Optiboot/optiboot


  Внимание!!! При выключении пункта "СОН" в меню настроек влечет увеличением энергопотребления, но тем самым увеличивается производительность устройства.

  Для полного сброса настроек(в том числе данных журнала и статистики накопленной дозы) необходимо удерживать клавишу "ОК" при включении питания.
  Если что-то идет или работает не так, в первую очередь пробуйте сброс настроек хот-кеем как описано выше!!!
  При первом запуске после прошивки обязательно выполните сброс всех настроек и пользовательских данных!

  После выключения устройства при низком напряжении акб, включить его можно или передергиванием выключателя питания или удержанием кнопки "OK" более чем на 2 сек.


  -Обозначения иконок-

  - Иконка "Динамик"
  Две скобки - щелчки частиц включены всегда
  Горизонтальная волна - щелчки включены только после преодоления порога фон1
  Крестик - щелчки выключены всегда

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

  - Иконка "Глаз"
  Мигающая - Режим сна заблокирован

  - Иконка "Пауза"
  Режим "поиск" приостановлен


  -Действия клавиш-

  - На экране ФОН
  Вверх - выбор (график | средн. и макс. фон | бета и гамма), удерж. - вкл/выкл фонарик
  Вниз - сбросить текущий фон и (график | средн. и макс. фон | бета и гамма), удерж. - вкл/выкл подсветку(или заблокировать сон)
  Ок - переключить экран (фон | доза), удерж. - выход в меню

  - На экране ДОЗА
  Вверх - смена подрежима(текущая доза | доза за все время), удерж. - вкл/выкл фонарик
  Вниз - сброс показаний(текущей дозы | дозы за все время), удерж. - вкл/выкл подсветку(или заблокировать сон)
  Ок - переключить экран, удерж. - выход в меню

  - На экране ПОИСК
  Вверх - пауза графика и показателей, удерж. - вкл/выкл фонарик
  Вниз - сброс графика и показателей, удерж. - вкл/выкл подсветку
  Ок - переключить экран, удерж. - выход в меню

  - На экране БЕТА
  Вверх - остановить замер, удерж. - вкл/выкл фонарик
  Вниз - принудительный сброс при замере, удерж. - вкл/выкл подсветку
  Ок - начать замер / следующий замер, удерж. - выход в меню

  - На экране НАСТРОЙКИ
  Вверх - позиция выше/прибавить показания, удерж. - позиция выше/прибавить показания
  Вниз - позиция ниже/убавить показания, удерж. - позиция ниже/убавить показания
  Ок - перейти к настройкам/перйти к выбору позиции, удерж. - выход в меню

  - На экране МЕНЮ
  Вверх - позиция выше, удерж. - позиция выше
  Вниз - позиция ниже, удерж. - позиция ниже
  Ок - выбор позиции, удерж. - выход в основные экраны

  - На экранах ЖУРНАЛ
  Вверх - позиция выше, удерж. - позиция выше
  Вниз - позиция ниже, удерж. - позиция ниже
  Ок - выбор позиции, удерж. - выход из журнала

  - На экранах ИНФОРМАЦИЯ
  Вверх - позиция выше, удерж. - нет действия
  Вниз - позиция ниже, удерж. - нет действия
  Ок - выбор позиции, удерж. - выход из информации

  - На экранах ПАРАМЕТРЫ
  Вверх - нет действия, удерж. - нет действия
  Вниз - нет действия, удерж. - нет действия
  Ок - нет действия, удерж. - выход из параметров

  - На экране ОТЛАДКА
  Вверх - прибавить показания, удерж. - прибавить показания
  Вниз - убавить показания, удерж. - убавить показания
  Ок - выбор позиции, удерж. - выход из отладки

  - На экране ОШИБКА
  Вверх - выход, удерж. - выход
  Вниз - выход, удерж. - выход
  Ок - выход, удерж. - выход


  -Ошибки-

  - Перегрузка преобразователя
  Преобразователь ВВ перегружен либо не правильно настроен, проверьте цепи преобразователя и установленные параметры DEFAULT_ADC_VALUE / DEFAULT_DIV_FACTOR / DEFAULT_INDUCTION.

  - Короткое замыкание преобразователя
  Короткое замыкание преобразователя ВВ либо не правильно настроен, проверьте цепи преобразователя и установленные параметры DEFAULT_ADC_VALUE / DEFAULT_DIV_FACTOR / DEFAULT_INDUCTION.

  - Низкое напряжение преобразователя
  Низкое напряжение преобразователя ВВ либо не правильно настроен, проверьте цепи преобразователя и установленные параметры DEFAULT_ADC_VALUE / DEFAULT_DIV_FACTOR / DEFAULT_INDUCTION.

  - Нет счета
  Отсутствуют импульсы от счетчика, проверьте цепи подключения счетчика, сам счетчик или преобразователь.

  - Короткое замыкание или зашкал детектора
  Вход детектора находится в низком уровне слишком долго, возможно короткое замыкание в цепи детектора импульсов или тлеющий разряд в счетчике.
*/

//-------------Версия прошивки--------------
#define FW_VERSION "4.4.5"

//----------------Библиотеки----------------
#include <util/delay.h>

//---------------Конфигурации---------------
#include "EEPROM.h"
#include "config.h"
#include "settings.h"
#include "connection.h"
#include "uartSender.h"
#include "display.h"

//-------------Для разработчиков-------------
#define ALARM_AUTO_GISTERESIS (float)(1.00 - (ALARM_AUTO_GIST / 100.00)) //инвертируем проценты
#define IMP_PWR_GISTERESIS (float)(1.00 - (IMP_PWR_GIST / 100.00)) //инвертируем проценты

uint8_t GEIGER_CYCLE; //минимум секунд для начала расчетов
uint8_t GEIGER_MASS; //максимум секунд для окончания смещения коэффициентов

//пищалка стоп
#define SOUND_PRESCALER 64 //пределитель частоты для пищалки
#define SOUND_STOP TIMSK1 = 0x00; PRR |= (0x01 << PRTIM1); power_status &= ~(0x01 << WAIT_TIM1)

#define BUZZ_CYCLE (uint16_t)(((uint32_t)FREQ_BUZZ * (uint32_t)TIME_BUZZ) / 1000) //пересчитываем частоту и время щелчков в циклы таймера
#define BUZZ_TIMER (uint16_t)((F_CPU / SOUND_PRESCALER) / FREQ_BUZZ) //пересчитываем частоту в время таймера

//перевод напряжения в значение ацп
uint8_t LOW_BAT_POWER; //минимальное рабочее напряжение батареи
uint8_t LOW_BAT_STAT; //напряжение оповещения о разряде батареи
uint8_t MIN_BAT; //минимальное напряжение батареи
uint8_t MAX_BAT; //максимальное напряжение батареи

volatile uint16_t main_buff; //основная переменная для счета импульсов от датчика
uint16_t scan_buff; //переменная сканирования импульсов
uint16_t search_buff[76]; //буфер поиска
uint16_t rad_buff[60]; //массив секундных замеров для расчета фона
uint32_t rad_mid_buff[60]; //массив секундных замеров для усреднения фона

uint8_t logbook_info_buff[10]; //буфер информации о данных журнала
uint32_t logbook_data_buff[10]; //буфер данных журнала

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

enum {
  INIT_PROGRAM, //инициализация
  MAIN_PROGRAM, //основной экран
  SEARCH_PROGRAM, //режим поиск
  MEASUR_PROGRAM, //режим замер
  LOGBOOK_PROGRAM, //режим журнал
  SETTINGS_PROGRAM, //настройки
  INFORMATION_PROGRAM, //информация
  POWER_DOWN_PROGRAM, //отключение питания
  MENU_PROGRAM, //основное меню
  PARAMETERS_PROGRAM, //параметры
  DEBUG_PROGRAM //отладка
};

enum {
  _SET_TIME_SLEEP, //сон
  _SET_TIME_BRIGHT, //подсветка
  _SET_CONTRAST, //контраст
#if ROTATE_DISP_RETURN
  _SET_ROTATION, //разворот
#endif
  _SET_RAD_FLASH, //вспышки
  _SET_BUZZ_SWITCH, //щелчки
  _SET_KNOCK_DISABLE, //звук кнопок
  _SET_VOLUME, //громкость
  _SET_SENSITIV, //чувствительность
  _SET_SIGMA_LVL, //сигма
  _SET_AVERAG_POS, //усреднение фона
  _SET_MEASUR_POS, //разностный замер
  _SET_SEARCH_POS, //время поиска
  _SET_SPEED_POS, //скорость поиска
  _SET_RAD_MOD, //единицы измерения
  _SET_ALARM_BACK, //тревога фон
  _SET_WARN_LEVEL_BACK, //порог фон 1
  _SET_ALARM_LEVEL_BACK, //порог фон 2
  _SET_ALARM_DOSE, //тревога доза
  _SET_WARN_LEVEL_DOSE, //порог доза 1
  _SET_ALARM_LEVEL_DOSE, //порог доза 2
#if USE_UART && (UART_SEND_BACK || UART_SEND_DOSE || UART_SEND_IMP)
  _SET_UART_MOD, //последовательный порт
#endif
  _SET_MENU_ALL //всего пунктов меню
};

uint16_t stat_upd_tmr; //таймер записи статистики в память

#if GEIGER_OWN_BACK
uint16_t rad_sum_timer; //таймер секунду между расчетами дозы
#endif
uint16_t rad_sum; //сумма импульсов за все время
uint32_t rad_max; //максимальный фон
uint32_t rad_back; //текущий фон
uint32_t rad_dose; //текущая доза

uint8_t accur_percent; //точность процентов

float rad_imp; //импульсы в секунду
float rad_imp_m; //импульсы в минуту
uint16_t scan_ind; //шкала имп/с
uint32_t rad_search; //фон в режиме поиск

uint16_t graf_max = MIN_IMP_MAIN_BUFF; //максимальный уровень маштабирования секундного графика
uint32_t graf_mid_max = MIN_IMP_MID_BUFF; //максимальный уровень маштабирования минутного графика

boolean search_disable = 0; //флаг запрета движения графика
uint8_t search_time_now = 0; //установленное время поиска
uint8_t search_score_now = 0; //текущий номер набранной секунды графика

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

volatile uint8_t tick_buff; //счетчик тиков для обработки данных
volatile uint8_t time_buff; //счетчик времени для обработки подсветки и вспышек

uint8_t timer_wait; //таймер отсчета миллисекунд для замера батареи
uint8_t timer_flash; //таймер отсчета миллисекунд для вспышек
uint8_t timer_light; //таймер отсчета миллисекунд для подсветки
uint16_t timer_millis; //таймер отсчета миллисекунд
uint16_t timer_melody; //таймер отсчета миллисекунд для мелодий

//флаги режимов
boolean scr_mode = 0; //текущий режим(фон/доза)
boolean dose_mode = 0; //режим отображения дозы(текущая/общая)
uint8_t back_mode = 0; //переключатель режима фон

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

//флаги обновления информации
boolean screen_update = 0; //флаг обновления экрана
boolean screen_anim = 0; //флаг анимации экрана

boolean low_bat_massege = 0; //флаг разрешения вывода сообщения об разряженой акб

//технические флаги
uint8_t alarm_switch = 0; //указатель текущей тревоги

boolean alarm_back_wait = 0; //флаг ожидания выключения запрета тревоги фона
boolean warn_back_wait = 0; //флаг ожидания выключения запрета предупреждения фона
uint16_t alarm_dose_set = 0; //предыдущая установка тревоги дозы
uint16_t warn_dose_set = 0; //предыдущая установка предупреждения дозы
uint32_t alarm_dose_wait = 0; //предыдущее значение тревоги дозы
uint32_t warn_dose_wait = 0; //предыдущее значение предупреждения дозы

uint8_t sleep_count = 0; //счетчик ухода в сон
uint8_t sleep_mode = 0; //переключатель состояния сна
uint8_t sleep_manual = 0; //флаг ручной блокировки сна
boolean sleep_disable = 0; //флаг запрета сна

uint8_t power_manager = 2; //переключатель режимов питания мк

//переменные режима замер бета
boolean alarm_measur = 0; //флаг запрета повторного оповещения
boolean next_measur = 0; //флаг следующего замера
uint8_t measur = 0; //текущий статус замера
uint16_t time_switch = 0; //счетчик времени замера
uint32_t first_froze = 0; //счетчик 1-го замера
uint32_t second_froze = 0; //счетчик 2-го замера
uint32_t measur_imp = 0; //текущий результат замера в имп
uint32_t measur_back = 0; //текущий результат замера в мкр/ч

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

//переменные работы со звуками
struct soundData {
  uint8_t replay; //флаг повтора мелодии
  uint16_t semp; //текущий семпл мелодии
  uint16_t link; //ссылка на мелодию
  uint16_t size; //количество семплов мелодии
} sound;
uint16_t buzz_vol; //громкость щелчков

//технические переменные
volatile uint16_t cnt_puls; //количество циклов для работы пищалки
uint8_t vibro_switch; //переключатель вибрации

uint8_t mainTask = POWER_DOWN_PROGRAM; //переключать подпрограмм

uint8_t error_switch = 0; //указатель на активность ошибки
boolean light_switch = 1; //переключатель вкл/выкл подсветки дисплея

#if COEF_DEBUG //отладка коэффициента
float debug_now = 0.00; //текущее соотношение ячеек сравнения
float debug_coef = 0.00; //установленное соотношение ячеек сравнения
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

#define RESET_WDT __asm__ __volatile__ ("WDR") //сброс WDT
#define RESET_SYSTEM __asm__ __volatile__ ("JMP 0x0000") //перезагрузка

#define EEPROM_SIZE_STATISTIC 256 //размер блока статистики
#define EEPROM_BLOCK_STATISTIC 510 //первая ячейка блока статистики

#define EEPROM_SIZE_LOGBOOK_INFO 10 //размер блока информации
#define EEPROM_SIZE_LOGBOOK_DATA 40 //размер блока данных
#define EEPROM_BLOCK_LOGBOOK_INFO 200 //первая ячейка блока информации
#define EEPROM_BLOCK_LOGBOOK_DATA 240 //первая ячейка блока данных

#define EEPROM_BLOCK_SETTINGS_MAIN (EEPROM_BLOCK_NULL) //ячейка основных настроек
#define EEPROM_BLOCK_SETTINGS_BOOK (EEPROM_BLOCK_SETTINGS_MAIN + sizeof(mainSettings)) //ячейка настроек журнала
#define EEPROM_BLOCK_SETTINGS_PUMP (EEPROM_BLOCK_SETTINGS_BOOK + sizeof(bookSettings)) //ячейка настроек преобразователя
#define EEPROM_BLOCK_CRC_MAIN (EEPROM_BLOCK_SETTINGS_PUMP + sizeof(pumpSettings)) //ячейка контрольной суммы основных настроек
#define EEPROM_BLOCK_CRC_BOOK (EEPROM_BLOCK_CRC_MAIN + 1) //ячейка контрольной суммы настроек журнала
#define EEPROM_BLOCK_CRC_PUMP (EEPROM_BLOCK_CRC_BOOK + 1) //ячейка контрольной суммы настроек преобразователя
#define EEPROM_BLOCK_CRC_STRUCT (EEPROM_BLOCK_CRC_PUMP + 1) //ячейка контрольной суммы структур данных

void _print_rads_unit(boolean type, uint32_t num, boolean divisor, uint8_t char_all, uint8_t num_x, uint8_t num_y, boolean unit, uint8_t unit_x, uint8_t unit_y, boolean dash = 0); //отрисовка данных
//--------------------------------------Главный цикл программ---------------------------------------------------
int main(void) //главный цикл программ
{
  _wdt_start_mode(); //первичный запуск WDT

  INIT_SYSTEM(); //инициализация

  for (;;) {
    screen_update = 0; //разрешаем обновления экрана
    screen_anim = 0; //сбросили анимацию экрана
    switch (mainTask) {
      default: RESET_SYSTEM; break; //перезагрузка
      case MAIN_PROGRAM: mainTask = main_screen(); break; //основной экран
      case SEARCH_PROGRAM: mainTask = search_menu(); break; //режим поиск
      case MEASUR_PROGRAM: mainTask = measur_menu(); break; //режим замера
#if !LOGBOOK_RETURN
      case LOGBOOK_PROGRAM: mainTask = logbook_measur(); break; //журнал замеров
#else
      case LOGBOOK_PROGRAM: mainTask = logbook(); break; //журнал
#endif
      case SETTINGS_PROGRAM: mainTask = settings(); break; //настройки
      case INFORMATION_PROGRAM: mainTask = information(); break; //информация
      case POWER_DOWN_PROGRAM: mainTask = power_down(); break; //отключение питания
      case MENU_PROGRAM: mainTask = menu(); break; //меню
#if DEBUG_RETURN
      case DEBUG_PROGRAM: mainTask = debug(); break; //отладка
#else
      case PARAMETERS_PROGRAM: mainTask = parameters(); break; //параметры
#endif
    }
  }
  return INIT_PROGRAM;
}
//--------------------------------------Инициализация---------------------------------------------------
void INIT_SYSTEM(void) //инициализация
{
  dataChannelEnd(); //выключение UART

  CONV_INIT; //инициализация преобразователя
  BUZZ_INIT; //инициализация бузера
  DET_INIT; //инициализация детектора частиц
  RAD_FLASH_INIT; //инициализация фонарика
  FLASH_INIT; //инициализация индикатора частиц
  VIBRO_INIT; //инициализация вибромотора
  PWR_LCD_INIT;//инициализация питания дисплея

#ifdef PCD8544
  BACKL_INIT; //инициализация подсветки
  LCD_INIT; //инициализация пинов дисплея
#endif

  SEL_INIT; //инициализация кнопки "ок"
  DOWN_INIT; //инициализация кнопки "вниз"
  UP_INIT; //инициализация кнопки "вверх"

#if PUMP_FEEDBACK
  COMP_INIT; //инициализация компаратора
#endif

  _delay_ms(START_TIME); //ждем
  _init_timers(); //инициализация таймеров

#ifdef PRR0
  PRR0 = (0x01 << PRTWI0) | (0x01 << PRTIM2) | (0x01 << PRTIM0) | (0x01 << PRUSART1) | (0x01 << PRTIM1) | (0x01 << PRSPI0) | (0x01 << PRUSART0) | (0x01 << PRADC); //отключаем все лишнее (I2C | TIMER2 | TIMER0 | TIMER1 | SPI | UART)
  PRR1 = (0x01 << PRTWI1) | (0x01 << PRPTC) | (0x01 << PRTIM4) | (0x01 << PRSPI1) | (0x01 << PRTIM3);
#else
  PRR = (0x01 << PRTWI) | (0x01 << PRTIM2) | (0x01 << PRTIM0) | (0x01 << PRTIM1) | (0x01 << PRSPI) | (0x01 << PRUSART0); //отключаем все лишнее (I2C | TIMER2 | TIMER0 | TIMER1 | SPI | UART)
#endif

#if PUMP_FEEDBACK != 1
  ACSR |= (0x01 << ACD); //отключаем компаратор
#else
  ACSR = (0x01 << ACBG) | (0x01 << ACIS1); //включаем компаратор
#if PUMP_FEEDBACK_PULL
  ACSR |= (0x01 << ACIS0); //включаем компаратор
#endif
  DIDR1 |= (0x01 << AIN1D); //запрещаем использование цифрового входа
#endif

  EIMSK = 0x00; //запрещаем внешние прерывания

  _init_lcd(); //инициализируем дисплей
  _wdt_enable(); //запускаем WatchDog
#ifdef PCD8544
  _BACKL_ON(); //включаем подсветку
#endif

  _read_memory(); //проверка и чтение данных из памяти
  _rows_clear(); //очистка строк

  _init_battery(); //инициализация настроек акб
  _init_settings(); //инициализация настроек

#if !PUMP_FEEDBACK
  _adc_enable(); //включаем питание АЦП
#endif
  _bat_update(); //опрос батареи

  _start_pump(); //первая накачка преобразователя

  _rows_clear(); //очистка строк
  print(INTRO, CENTER, 32); //интро прошивки
  print(VERSION, CENTER, 40); //версия прошивки

#if GEIGER_INT_PULL
  EICRA = (0x01 << ISC11) | (0x01 << ISC01); //настраиваем внешнее прерывание по спаду импульса на INT0 и INT1
#else
  EICRA = (0x01 << ISC11) | (0x01 << ISC01) | (0x01 << ISC00); //настраиваем внешнее прерывание по спаду импульса на INT1 и возрастанию на INT0
#endif
  EIFR |= (0x01 << INTF1) | (0x01 << INTF0); //сбросили флаги прерывания портов
  EIMSK = (0x01 << INT0); //разрешаем внешнее прерывание INT0

  main_buff = 0; //очищаем основной буфер
  mainTask = MAIN_PROGRAM; //установили основную программу

  _wait(FONT_TIME); //ждем
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
    if (dialogSwitch(0)) dataReg |= 0x03; //если ответ да то устанавливаем флаг сброса
    clrScr(); //очистка экрана
#if DEBUG_RETURN
    print(RES_RESET, CENTER, 0); //Сбросить
    print(RES_SETTINGS_P, CENTER, 8); //настройки
    print(RES_PUMP, CENTER, 16); //конвертера?
    if (dialogSwitch(0)) dataReg |= 0x04; //если ответ да то устанавливаем флаг сброса
    clrScr(); //очистка экрана
#endif
    print(RES_RESET, CENTER, 0); //Сбросить
    print(RES_DATA, CENTER, 8); //данные
    print(RES_USER, CENTER, 16); //пользователя?
    if (dialogSwitch(0)) dataReg |= 0x18; //если ответ да то устанавливаем флаг сброса

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
      if (!dialogSwitch(0)) dataReg = 0; //если ответ нет то сбрасываем флаги
    }
  }

  clrScr(); //очистка экрана
  _init_logo(); //вывод логотипа
  _init_load_bar(READ); //чтение...

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
    _set_load_bar(i, 0, 4); //прогресс бар загрузки данных
    _wait_now(LOAD_TIME); //ждем
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
//---------------------------------Проверка инверсии кнопок----------------------------------------------
uint8_t buttonSwitch(uint8_t _switch) //проверка инверсии кнопок
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
inline uint8_t buttonState(void) //проверка кнопок
{
  uint8_t button = button_state; //запоминаем текущее состояние кнопки
  button_state = 0; //сбрасываем текущее состояние кнопки
  return button; //возвращаем состояние кнопки
}
//---------------------------------------Обновление кнопок------------------------------------------------
inline uint8_t buttonStateUpdate(void) //обновление кнопок
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
            switch (buttonSwitch(btn_switch)) { //переключаемся в зависимости от состояния мультиопроса
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
            switch (buttonSwitch(btn_switch)) { //переключаемся в зависимости от состояния мультиопроса
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
          if (!mainSettings.knock_disable) buzz_pulse(FREQ_BEEP, TIME_BEEP); //щелчок пищалкой
          _disable_sleep(); //выход из сна
          switch (buttonSwitch(btn_switch)) { //переключаемся в зависимости от состояния мультиопроса
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
//-----------------------------Инициализация таймеров------------------------------------------------
boolean _check_screen(void) //инициализация таймеров
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
  for (timer_millis = timer; timer_millis && !buttonState();) _data_update(); // ждем, преобразование данных
}
//--------------------------Ожидание без выхода по кнопке--------------------------------------------
void _wait_now(uint32_t timer) //ожидание без выхода по кнопке
{
  for (timer_millis = timer; timer_millis || display_update;) _data_update(); // ждем, преобразование данных
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
  _BUZZ_VOL_SET(mainSettings.volume); //устанавливаем громкость щелчков
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
//----------------------------------Преобразование данных---------------------------------------------
boolean _data_update(void) //преобразование данных
{
  static boolean puls_det; //флаг обнаружения импульсов со счетчика
  static uint8_t tick_switch; //счетчик тиков для обработки данных
  static uint8_t tmr_det_low; //таймер замыкания счетчика
  static uint8_t tmr_nop_imp; //таймер отсутствия импульсов
  static uint8_t tmr_upd_bat; //таймер обновления состояния акб
  static uint8_t tmr_low_bat; //таймер вывода сообщения об разряженой акб
  static uint8_t tmr_upd_err; //таймер вывода сообщения об ошибке
  static uint32_t time_total; //счетчик реального времени
  static uint32_t temp_buff; //общий буфер

  static float coef_now; //коэффициент сравнения
  static float coef_prev; //коэффициент поправки на фон

#if PUMP_FEEDBACK
  static boolean pump_imp_det; //флаг обновления состояния преобразователя по импульсц со счетчика
  static uint8_t pump_imp_cnt; //счетчик импульсов до следующего обновления состояния преобразователя
  static uint8_t pump_imp_pos = 10; //текущее количество импульсов до следующего обновления состояния преобразователя
  static uint8_t tmr_upd_pump; //таймер обновления состояния преобразователя
#endif

#if USE_UART && (UART_SEND_BACK || UART_SEND_DOSE || UART_SEND_IMP)
  dataChannelUpdate(); //обработка UART
#endif

  _update_lcd(); //обработка дисплея
  _analog_update(); //обработка аналоговых входов

#if PUMP_FEEDBACK
  if (_pump_status_compleated()) {
    _pump_status_compleated_reset();
    if ((9999 - speed_pump) >= speed_puls) speed_pump += speed_puls;
    else speed_pump = 9999;
    if (speed_puls) speed_puls--;

    if (!pump_imp_det) {
      if (speed_puls > 20) pump_imp_time = 1;
      else if (speed_puls > 2) {
        if (pump_imp_time > 50) pump_imp_time -= 10;
        else if (pump_imp_time > 10) pump_imp_time -= 5;
        else if (pump_imp_time > 1) pump_imp_time -= 1;
      }
      else {
        if (pump_imp_time < 10) pump_imp_time += 1;
        else if (pump_imp_time < 50) pump_imp_time += 5;
        else if (pump_imp_time < 250) pump_imp_time += 10;
      }
    }
    else {
      if (speed_puls > 20) pump_imp_pos = 1;
      else if (speed_puls > 2) {
        if (pump_imp_pos > 1) pump_imp_pos--;
      }
      else {
        if (pump_imp_pos < 20) pump_imp_pos++;
      }
      pump_imp_det = 0;
    }
    pump_imp_cnt = 0;
    speed_puls = 0;
  }
#endif

  _low_pwr(); //отключение дисплея и подсветки, уход в сон для экономии энергии

  if (main_buff) { //если есть импульс в основном буфере
    cli(); //запретили прерывания
    uint16_t temp_main_puls = main_buff; //копируем количество импульсов
    main_buff = 0; //очищаем основной буфер
    sei(); //разрешили прерывания
    puls_det = 1; //установили флаг обнаружения импульса

    if (65535 - scan_buff >= temp_main_puls) scan_buff += temp_main_puls; //если буфер сканирования не переполнен прибавляем импульсы
    else scan_buff = 65535; //иначе установили максимум

    if (!timer_flash) { //если индикация не включена
      switch (mainSettings.rad_flash) { //в зависимости от режима
        case 1: _RAD_FLASH_ON(); break; //индикация попадания частиц
        case 2: if (sleep_mode != 2) _RAD_FLASH_ON(); break; //индикация попадания частиц
      }
    }
    if (!TIMSK1) { //если бузер не включен
      switch (mainSettings.buzz_switch) { //в зависимости от режима
        case 1: _BUZZ_START(); break; //щелчок пищалкой
        case 2: if (rad_back >= mainSettings.warn_level_back) _BUZZ_START(); break; //если фон выше установленного
      }
    }

#if PUMP_FEEDBACK
    if (!_pump_status()) {
      if ((uint8_t)(255 - pump_imp_cnt) >= temp_main_puls) pump_imp_cnt += temp_main_puls;
      else pump_imp_cnt = 255;

      if (pump_imp_cnt >= pump_imp_pos) {
        if (COMP_CHK) {
          pump_imp_det = 1; //установили флаг признака накачки
          _pump_update(); //накачка по обратной связи
        }
        else {
          pump_imp_cnt = 0; //сбросили флаг признака накачки
          _pump_status_compleated_set(); //накачка завершена
        }
      }
    }
#else
    _pump_update(); //накачка по обратной связи с АЦП
#endif
  }

  if (time_buff) { //отсчет миллисекунд
    time_buff--; //убавили счетчик

    if (timer_wait) timer_wait--; //отсчет миллисекунд для замера батареи

    if (timer_flash) { //отсчет миллисекунд для вспышек
      timer_flash--;
      if (!timer_flash) RAD_FLASH_OFF; //выключаем индикацию
    }

#ifdef PCD8544
    if (timer_light) { //отсчет миллисекунд для подсветки
      timer_light--;
      if (!timer_light) {
        switch (light_switch) { //в зависимости от направления
          case 0:
            if (OCR2A > 5) {
              OCR2A--; //убавляем счетчик циклов шим
              timer_light = 4; //установили таймер
            }
            else {
              TIMSK2 &= ~(0x01 << OCIE2A); //отключили шим
              BACKL_OFF; //выключаем подсветку
            }
            break;
          case 1:
            if (OCR2A < 250) {
              OCR2A++; //прибавляем счетчик циклов шим
              timer_light = 4; //установили таймер
            }
            else {
              TIMSK2 &= ~(0x01 << OCIE2A); //отключили шим
              BACKL_ON; //включаем подсветку
            }
            break;
        }
      }
    }

    if (!timer_flash && !timer_light && !timer_wait) _TIMER_STOP(); //выключаем таймер
#else
    if (!timer_flash && !timer_wait) _TIMER_STOP(); //выключаем таймер
#endif
  }

  if (tick_buff) { //если был тик то обрабатываем данные
    if (--tick_buff) power_status |= (0x01 << WAIT_WDT); //убавили тик
    else power_status &= ~(0x01 << WAIT_WDT); //разрешили сон

    uint8_t _button = buttonStateUpdate(); //обновление состояния кнопок
    if (_button) { //если кнопка нажата
      button_state = _button; //записали новое действие кнопки
    }

    if (timer_millis > 16) timer_millis -= 16; //если таймер больше 16мс
    else if (timer_millis) timer_millis = 0; //иначе сбрасываем таймер

    if (timer_melody > 16) timer_melody -= 16; //если таймер больше 16мс
    else if (timer_melody) timer_melody = 0; //иначе сбрасываем таймер

    melodyUpdate();  //воспроизведение мелодии

    if (mainTask != POWER_DOWN_PROGRAM) { //если не инициализация
#if PUMP_FEEDBACK
      if (++tmr_upd_pump >= pump_imp_time) {
        tmr_upd_pump = 0;
        if (!_pump_status()) {
          if (COMP_CHK) _pump_update(); //накачка по обратной связи
          else _pump_status_compleated_set(); //накачка завершена
        }
      }
#else
      _pump_update(); //накачка по обратной связи с АЦП
#endif

      time_total += pumpSettings.wdt_period; //добавляем ко времени период таймера
      if (time_total > 100000UL) { //если прошла секунда
        time_total -= 100000UL; //оставляем остаток
        tick_switch = 0; //сбросили тики обработки данных
      }
      tick_switch++; //прибавили тик обработки данных

      if (mainTask != MEASUR_PROGRAM && mainTask != SEARCH_PROGRAM) { //если не идет замер/поиск
        switch (tick_switch) { //блок обработки данных режима фон/доза
          case TASK_UPDATE_TIME: //обновление секунд
            time_sec++; //прибавляем секунду
            break;

          case TASK_UPDATE_STAT: //обновление статистики
            if (++stat_upd_tmr >= STAT_UPD_TIME) { //если пришло время, обновляем статистику
              stat_upd_tmr = 0; //сбрасываем таймер
              statistic_update(); //обновление статистики
            }
            break;

          case TASK_CALC_BACK_1: //расчет текущего фона этап-1
            graf_max = MIN_IMP_MAIN_BUFF; //сбрасываем максимум графика
            for (uint8_t i = 59; i > 0; i--) { //перезапись массива
              rad_buff[i] = rad_buff[i - 1]; //смещаем элемент массива
              if (rad_buff[i] > graf_max) graf_max = rad_buff[i]; //ищем максимум
            }
            rad_buff[0] = scan_buff; //копируем счетчик импульсов в массив импульсов
            scan_buff = 0; //сбрасываем счетчик импульсов
            if (rad_buff[0] > graf_max) graf_max = rad_buff[0]; //ищем максимум
            break;

          case TASK_CALC_BACK_2: { //расчет текущего фона этап-2
              temp_buff = 0; //сбрасываем временный буфер

              if (geiger_time_now < 60) geiger_time_now++; //прибавляем указатель заполненности буффера
              if (back_time_now < 60) back_time_now++; //прибавляем указатель заполненности буффера для рассчета фона
              else {
                back_time_now = 1; //иначе сбрасываем в начало
                if (mid_time_now < mainSettings.averag_time) mid_time_now++; //прибавляем указатель заполненности буффера
              }

#if !APPROX_BACK_SCORE && GEIGER_DEAD_TIME
              if (rad_buff[0] >= COUNT_RATE) { //если скорость счета больше 100имп/с
                uint32_t count_buff = rad_buff[0] / (1.00 - rad_buff[0] * DEAD_TIME); //учитываем мертвое время счетчика
                if (count_buff < 65535) rad_buff[0] = count_buff; //если счетчик не переполнен
                else rad_buff[0] = 65535; //иначе переполнение
              }
#endif
              for (uint8_t i = 0; i < back_time_now; i++) temp_buff += rad_buff[i]; //суммирование всех импульсов для расчета фона
            }
            break;

          case TASK_CALC_BACK_3: //перезапись массива буфера усреднения этап-3
            if (back_time_now >= 60) { //если основной буфер перезаписался
              graf_mid_max = MIN_IMP_MID_BUFF; //сбрасываем максимум графика
              for (uint8_t i = 59; i > 0; i--) { //перезапись массива
                rad_mid_buff[i] = rad_mid_buff[i - 1]; //смещаем элемент массива
                if (rad_mid_buff[i] > graf_mid_max) graf_mid_max = rad_mid_buff[i]; //ищем максимум
              }
              rad_mid_buff[0] = temp_buff; //записываем основной массив в массив усреднения
              if (rad_mid_buff[0] > graf_mid_max) graf_mid_max = rad_mid_buff[0]; //ищем максимум
            }
            break;

          case TASK_CALC_BACK_4: //копирование буфера усреднения этап-4
            for (uint8_t i = 0; i < mid_time_now; i++) { //копирование массива
              temp_buff += rad_mid_buff[i]; //суммирование всех импульсов для расчета фона
            }
            break;

          case TASK_CALC_BACK_5: { //расчет текущего фона этап-5
              uint16_t buff[RESET_BUFF_NUM];

              for (uint8_t i = 0; i < RESET_BUFF_NUM; i++) buff[i] = rad_buff[i];
              for (uint16_t i = 0; i <= ((RESET_BUFF_NUM / 2) + 1); i++) {
                for (uint16_t f = 0; f < (RESET_BUFF_NUM - 1) - i; f++) {
                  if (buff[f] > buff[f + 1]) {
                    uint16_t temp = buff[f];
                    buff[f] = buff[f + 1];
                    buff[f + 1] = temp;
                  }
                }
              }

              coef_now = (buff[RESET_BUFF_NUM / 2] > 1) ? sqrtf(buff[RESET_BUFF_NUM / 2]) : 1;

              uint16_t diff = abs(coef_prev - coef_now) * 10;

              if (diff > mainSettings.sensitiv) { //если видим скачок или спад
                temp_buff = 0; //сбрасываем текущий буфер
                for (uint8_t i = 0; i < ((RESET_BUFF_NUM / 2) + 1); i++) temp_buff += rad_buff[i]; //запоняем буффер первого плеча
                back_time_now = geiger_time_now = ((RESET_BUFF_NUM / 2) + 1); //устанавливаем текущий размер буфера
                mid_time_now = 0; //сбрасываем рассчет среднего
#if COEF_DEBUG //отладка коэффициента
                debug_now++; //текущее количество сбросов
                debug_coef = diff; //коэффициент сброса
#endif
              }
              coef_prev = coef_now;
            }
            break;
          case TASK_CALC_BACK_6: { //расчет текущего фона этап-6
#if APPROX_BACK_SCORE
              float imp_per_sec = 0; //текущее количество имп/с
              if (geiger_time_now > 1) imp_per_sec = (float)temp_buff / ((uint16_t)mid_time_now * 60 + back_time_now); //расчет имп/с
#if GEIGER_OWN_BACK
              if (imp_per_sec > OWN_BACK) imp_per_sec -= OWN_BACK; //убираем собственный фон счетчика
              else imp_per_sec = temp_buff = 0; //иначе ничего кроме собственного фона нету
#endif
              rad_back = _get_aprox_back(imp_per_sec); //получить аппроксимированный фон в мкр/ч
#else
#if GEIGER_OWN_BACK
              float own_back_now = ((uint16_t)mid_time_now * 60 + back_time_now) * OWN_BACK; //рассчитываем количество импульсов собственного фона
              if (temp_buff > own_back_now) temp_buff -= own_back_now; //убираем собственный фон счетчика
              else temp_buff = 0; //иначе ничего кроме собственного фона нету
#endif
              if (geiger_time_now > 1) rad_back = temp_buff * (pumpSettings.geiger_time / ((uint16_t)mid_time_now * 60 + back_time_now)); //расчет фона мкР/ч
#endif
            }
            break;

          case TASK_UPDATE_ACCUR: //рассчитываем точность
            accur_percent = _get_accur(temp_buff); //рассчет точности
            break;

          case TASK_MAX_BACK: //минимальный и максимальный фон
            if (accur_percent <= RAD_ACCUR_START) { //если достаточно данных в массиве
              if (rad_back > rad_max) rad_max = rad_back; //фиксируем максимум фона
            }
            break;

          case TASK_CALC_DOSE: { //расчет текущей дозы
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

          case TASK_UPDATE_ALARM: //обработка тревоги
            if (warn_back_wait && (rad_back < (mainSettings.warn_level_back * ALARM_AUTO_GISTERESIS))) { //если текущий фон упал ниже порога + гистерезис
              warn_back_wait = 0; //сброс предупреждения
            }
            if (alarm_back_wait && (rad_back < (mainSettings.alarm_level_back * ALARM_AUTO_GISTERESIS))) { //если текущий фон упал ниже порога + гистерезис
              alarm_back_wait = 0; //сброс тревоги
            }

            if (!sleep_disable) { //если сон разрешен
              if (alarm_switch != 3) { //если нет тревоги по фону
                if (mainSettings.alarm_dose) {
                  if ((rad_dose - alarm_dose_wait) >= mainSettings.alarm_level_dose) { //если тревога не запрещена и текущая(предыдущая) доза больше порога
                    alarm_switch = 4;  //превышение дозы 2
                    break;
                  }
                  else if ((rad_dose - warn_dose_wait) >= mainSettings.warn_level_dose) { //если предупреждения не запрещены и текущая(предыдущая) доза больше порога
                    alarm_switch = 2;  //превышение дозы 1
                    break;
                  }
                }
              }

              if (accur_percent <= RAD_ACCUR_WARN) { //если достигли порога точности
                if (mainSettings.alarm_back) {
                  if (!alarm_back_wait && (rad_back >= mainSettings.alarm_level_back)) { //если тревога не запрещена и текущий фон больше порога
                    alarm_switch = 3;  //превышение фона 2
                    break;
                  }
                  else if (!warn_back_wait && (rad_back >= mainSettings.warn_level_back)) { //если предупреждения не запрещены и текущий фон больше порога
                    alarm_switch = 1;  //превышение фона 1
                    break;
                  }
                }
              }
            }
            break;
#if USE_UART && (UART_SEND_BACK || UART_SEND_DOSE || UART_SEND_IMP)
          case TASK_UPDATE_UART: //отправляем данные в порт
            if (!dataChannelState()) { //если порт включен
#if UART_SEND_BACK
              sendNum(rad_back, 'B', ' '); //отправка данных
#endif
#if UART_SEND_DOSE
              sendNum(rad_dose, 'D', ' '); //отправка данных
#endif
#if UART_SEND_IMP
              sendNum(rad_buff[0], 'I', ' '); //отправка данных
#endif
              sendEnd(); //отправка конца строки
            }
            break;
#endif
        }
      }

      switch (tick_switch) { //основной блок обрабоки данных
        case TASK_UPDATE_ERROR: //обработка ошибок
          speed_hv = speed_pump; //текущая скорость накачки
          speed_pump = 0; //сбрасываем скорость накачки

          if (tmr_upd_err >= CONV_ERROR_TIME) {
            if (speed_hv >= HV_SPEED_ERROR) { //если текущая скорость накачки выше порога
#if LOGBOOK_RETURN
              _logbook_data_update(3, 2, speed_hv); //обновление журнала устанавливаем ошибку 2 - перегрузка преобразователя
              error_switch = 2; //поднимаем флаг ошибки
#else
              error_switch = 2; //поднимаем флаг ошибки
#endif
              tmr_upd_err = 0; //сброс таймера
            }
#if !PUMP_FEEDBACK
            if (hv_adc < pumpSettings.ADC_value - HV_ADC_MIN) { //если значение АЦП преобразователя ниже на установленное значение
#if LOGBOOK_RETURN
              _logbook_data_update(3, 4, hv_adc); //обновление журнала устанавливаем ошибку 4 - низкое напряжение
              error_switch = 2; //поднимаем флаг ошибки
#else
              error_switch = 4; //поднимаем флаг ошибки
#endif
              tmr_upd_err = 0; //сброс таймера
            }

            if (hv_adc < HV_ADC_ERROR) { //если значение АЦП преобразователя ниже порога
#if LOGBOOK_RETURN
              _logbook_data_update(3, 3, hv_adc); //обновление журнала устанавливаем ошибку 3 - кз преобразователя
              error_switch = 2; //поднимаем флаг ошибки
#else
              error_switch = 3; //поднимаем флаг ошибки
#endif
              tmr_upd_err = 0; //сброс таймера
            }
#endif
          }
          else tmr_upd_err++;

          if (!puls_det) { //если не было импульса со счетчика
            if (++tmr_nop_imp >= IMP_ERROR_TIME) { //считаем время до вывода предупреждения
#if LOGBOOK_RETURN
              _logbook_data_update(3, 5, 5); //обновление журнала устанавливаем ошибку 5 - нет импульсов
              error_switch = 2; //поднимаем флаг ошибки
#else
              error_switch = 5; //поднимаем флаг ошибки
#endif
              tmr_nop_imp = 0; //сбросили таймер
            }

            if (DET_CHK) { //если вход детектора в ненормальном состоянии
              if (++tmr_det_low >= DET_ERROR_TIME) { //считаем время до вывода предупреждения
#if LOGBOOK_RETURN
                _logbook_data_update(3, 6, 6); //обновление журнала устанавливаем ошибку 6 - зашкал детектора
                error_switch = 2; //поднимаем флаг ошибки
#else
                error_switch = 6; //поднимаем флаг ошибки
#endif
                tmr_det_low = 0; //сбросили таймер
              }
            }
            else { //иначе счетчик в высоком уровне
              tmr_det_low = 0; //сбросили таймер
            }
          }
          else { //иначе импульсы возобновились
            puls_det = 0; //сбросили флаг обнаружения импульсов
            tmr_det_low = 0; //сбросили таймер
            tmr_nop_imp = 0; //сбросили таймер
          }
          break;

        case TASK_UPDATE_MEASUR: //разностный замер
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

        case TASK_UPDATE_SLEEP: //считаем время до ухода в сон
          if (mainSettings.sleep_switch && !sleep_manual) { //если сон не выключен
            if (sleep_count <= ((sleep_disable) ? mainSettings.time_bright : mainSettings.time_sleep)) sleep_count++; //счет ухода в сон
            if ((sleep_count == mainSettings.time_sleep) && (mainSettings.sleep_switch == 2)) { //если пришло время спать и сон не запрещен
              _enable_sleep_lcd(); //уводим в сон дисплей
              _buzz_disable(); //запрещаем щелчки
              sleep_mode = 2; //выставляем флаг сна
            }
            else if (sleep_count == mainSettings.time_bright) { //если пришло время выключить подсветку
#ifdef PCD8544
              _BACKL_OFF(); //выключаем подсветку
#endif
#ifdef SSD1306
              _set_contrast_lcd(OFF_BACKL); //установка минимальной яркости
#endif
              sleep_mode = 1; //выставляем флаг выключенной подсветки
            }
          }
          break;

        case TASK_UPDATE_POWER: { //управление энергосбережением
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
              if (rad_back > RAD_SLEEP_OUT) { //если фон привысил порог
                if (!(sleep_manual & 0x02)) { //если сон не заблокирован
                  _sleep_out(); //выход из сна
                  sleep_manual |= 0x02; //установили флаг ручной блокировки сна
                }
              }
              else if (sleep_manual & 0x02) { //иначе если сон был заблокирован
                sleep_manual &= ~0x02; //сбросили флаг ручной блокировки сна
              }

              if ((mainSettings.sleep_switch == 2) && power_manager) { //иначе если сон разрешен
                if ((sleep_mode == 2) && (power_manager == 2)) { //режим глубокого энергосбережения
                  power_status &= ~(0x01 << WAIT_PWR1);
                  power_status &= ~(0x01 << WAIT_PWR2);
                }
                else { //режим энергосбережения
                  power_status &= ~(0x01 << WAIT_PWR1);
                  power_status |= (0x01 << WAIT_PWR2);
                }
              }
              else { //режим ожидания
                power_status &= ~(0x01 << WAIT_PWR2);
                power_status |= (0x01 << WAIT_PWR1);
              }
            }
            else { //режим ожидания
              power_status &= ~(0x01 << WAIT_PWR2);
              power_status |= (0x01 << WAIT_PWR1);
            }
#if USE_UART && (UART_SEND_BACK || UART_SEND_DOSE || UART_SEND_IMP)
            if (sendCheck()) { //режим ожидания
              power_status &= ~(0x01 << WAIT_PWR2);
              power_status |= (0x01 << WAIT_PWR1);
            }
#endif
          }
          break;

        case TASK_UPDATE_BAT: //таймер обновления состояния батареи
          if ((mainTask == DEBUG_PROGRAM) || (mainTask == PARAMETERS_PROGRAM)) { //если режим отладки
            low_bat_massege = 0; //сбрасываем флаг обновления сообщения об разряженной акб
            tmr_upd_bat = 0; //сброс таймера
            tmr_low_bat = 0; //сброс таймера
            _bat_update(); //опрос батареи
          }
          else { //иначе обычный режим
            if (tmr_upd_bat >= UPD_BAT_TIME) { //если пришло время опросить акб
              tmr_upd_bat = 0; //сброс таймера
              _bat_update(); //опрос батареи
            }
            else tmr_upd_bat++; //прибавляем к счетчику времени

            if (tmr_low_bat < LOW_BAT_TIME) tmr_low_bat++; //прибавляем к счетчику времени
            else if (bat_adc >= LOW_BAT_STAT) { //если напряжение ниже порога
              if (!low_bat_massege) { //если флаг вывода сообщения не установлен
                low_bat_massege = 1; //устанавливаем флаг вывода сообщения об разряженной акб
                tmr_low_bat = 0; //сброс таймера
              }
            }
          }
          break;

        case TASK_UPDATE_SCREEN: //таймер обновления экрана
          if ((sleep_mode != 2) && (mainTask != SEARCH_PROGRAM)) { //если не спим и не в режиме поиска
            screen_update = 0; //устанавливаем флаг для обновления экрана
            screen_anim = !screen_anim; //изменили анимацию экрана
          }
          break;
      }
    }
    return 1; //разрешаем обновить данные
  }
  return 0; //запрещаем обновить данные
}
//-------------------------Режим пониженного энергопотребления----------------------------------------------------
void _low_pwr(void) //режим пониженного энергопотребления
{
  if (!power_status) _sleep_pwr(); //режим глубокого энергосбережения
  else if (!(power_status & ((0x01 << WAIT_WDT) | (0x01 << WAIT_DSP) | (0x01 << WAIT_ADC) | (0x01 << WAIT_COMP) | (0x01 << WAIT_TIM1) | (0x01 << WAIT_TIM2) | (0x01 << WAIT_PWR1)))) _save_pwr(); //режим энергосбережения
  else if (!(power_status & ((0x01 << WAIT_WDT) | (0x01 << WAIT_DSP) | (0x01 << WAIT_COMP)))) _wait_pwr(); //режим ожидания
}
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
//-------------------------------------Выход из сна--------------------------------------------------------
void _sleep_out(void) //выход из сна
{
  if (sleep_mode) { //если выключели подсветку
#ifdef PCD8544
    _BACKL_ON(); //включаем подсветку
#endif
    if (sleep_mode == 2) { //если спали
      _disable_sleep_lcd(); //выводим дисплей из сна
      _buzz_enable(); //восстанавливаем настройку щелчков
      screen_update = 0; //разрешаем обновления экрана
    }
#ifdef SSD1306
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
uint8_t power_down(void) //выключение устройства
{
  cli(); //запрещаем прерывания

  _wdt_disable(); //выключаем watchdog
  _adc_disable(); //выключаем питание АЦП

#if PUMP_FEEDBACK == 1
  ACSR |= (0x01 << ACD); //отключаем компаратор
#endif

  _TIMER_STOP(); //выключаем таймер

#ifdef PCD8544
  BACKL_OFF; //выключаем подсветку
#endif
  SOUND_STOP; //выключаем таймер бузера
  BUZZ_OFF; //выключаем бузер

  FLASH_OFF; //выключаем фонарь
  RAD_FLASH_OFF; //выключаем индикацию

  _enable_sleep_lcd(); //выключаем дисплей
#ifdef PCD8544
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
#ifdef PCD8544
          _BACKL_ON(); //включаем подсветку
#endif
#if PUMP_FEEDBACK == 1
          ACSR = (0x01 << ACBG) | (0x01 << ACIS1); //включаем компаратор
#if !PUMP_FEEDBACK_PULL
          ACSR |= (0x01 << ACIS1); //включаем компаратор
#endif
#endif
          _init_logo(); //вывод логотипа
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
              _TIMER_WAIT(5); //включили таймер ожидания для выравнивания напряжения ИОН
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
          _TIMER_WAIT(7); //включили таймер ожидания для выравнивания напряжения ИОН
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
//-------------------------------Обновить длину импульса--------------------------------------
void _update_pump_puls(void) //обновить длину импульса
{
  uint16_t vcc = (uint16_t)((pumpSettings.reference * 256000UL) / ((bat_adc > MIN_BAT) ? MIN_BAT : bat_adc)); //напряжение батареи
  pump_puls_now = (uint8_t)((469UL * pumpSettings.puls) / vcc); //находим длину импульса
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
//-----------------------------------Первая накачка-------------------------------------------
void _start_pump(void) //первая накачка
{
  uint8_t timer = (START_PUMP_TIME / 50); //таймер авто-выхода

  _init_load_bar(LOAD); //загрузка...
  _pump_update(); //накачка по обратной связи с АЦП

  while (1) { //первая накачка
    _data_update(); //обновление данных

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
  while (analogState) _data_update(); //обработка аналоговых входов
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
#ifdef PCD8544
          BACKL_ON;
#endif
#endif
          VIBRO_ON;
          break;

        case 1:
#if (TYPE_ALARM_IND == 1)
          FLASH_OFF;
#elif (TYPE_ALARM_IND == 2)
#ifdef PCD8544
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
#ifdef PCD8544
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
#ifdef SSD1306
    _enable_sleep_lcd(); //выключаем подсветку, если была включена настройками
    _buzz_disable(); //запрещаем щелчки
    sleep_mode = 2; //выставляем флаг сна
#endif
#ifdef PCD8544
    if (light_switch) _BACKL_OFF(); //выключаем подсветку, если была включена настройками
    else _BACKL_ON(); //включаем подсветку
#endif
  }
  else if (!sleep_disable) sleep_manual ^= 0x01; //иначе переключаем ручную блокировку сна
}
//------------------------Таймер общего назначения старт/стоп-------------------------------
void _TIMER_WAIT(uint8_t _time) {
  PRR &= ~(0x01 << PRTIM2); //включаем питание таймера
  TIMSK2 |= (0x01 << TOIE2); //разрешаем прерывания
  power_status |= (0x01 << WAIT_TIM2);
  timer_wait = _time; //установили время
}
void _RAD_FLASH_ON(void) {
  PRR &= ~(0x01 << PRTIM2); //включаем питание таймера
  TIMSK2 |= (0x01 << TOIE2); //разрешаем прерывания
  timer_flash = RAD_FLASH_TIME; //установили время
  power_status |= (0x01 << WAIT_TIM2);
  RAD_FLASH_ON; //включили индикацию
}
void _BACKL_ON(void) { //подсветка старт
  PRR &= ~(0x01 << PRTIM2); //включаем питание таймера
  if (OCR2A < 5) OCR2A = 5; //установили минимальный шим
  TIFR2 |= (0x01 << OCF2A); //сбрасываем флаг прерывания
  TIMSK2 |= (0x01 << OCIE2A) | (0x01 << TOIE2); //разрешаем прерывания
  timer_light = 4; //установили таймер
  power_status |= (0x01 << WAIT_TIM2);
  light_switch = 1; //устанасвливаем флаг разгорания подсветки
}
void _BACKL_OFF(void) { //подсветка стоп
  PRR &= ~(0x01 << PRTIM2); //включаем питание таймера
  if (OCR2A > 250) OCR2A = 250; //установили максимальный шим
  TIFR2 |= (0x01 << OCF2A); //сбрасываем флаг прерывания
  TIMSK2 |= (0x01 << OCIE2A) | (0x01 << TOIE2); //разрешаем прерывания
  timer_light = 4; //установили таймер
  power_status |= (0x01 << WAIT_TIM2);
  light_switch = 0; //устанасвливаем флаг затухания подсветки
}
void _TIMER_STOP(void) { //таймер стоп
  TCNT2 = TIMSK2 = 0x00; //сбрасываем счетный регистр и отключаем прерывания
  PRR |= (0x01 << PRTIM2); //выключаем питание таймера
  power_status &= ~(0x01 << WAIT_TIM2);
}
//------------------------------------Таймер общего назначения-------------------------------------------
ISR(TIMER2_OVF_vect) //плавная подсветка
{
#ifdef PCD8544
  if (TIMSK2 & (0x01 << OCIE2A)) BACKL_ON; //включаем подсветку
#endif
  if (time_buff < 255) time_buff++;
}
#ifdef PCD8544
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
//---------------------------------------Пищалка старт/стоп---------------------------------------------
void _BUZZ_START(void) {
  cnt_puls = BUZZ_CYCLE;
  PRR &= ~(0x01 << PRTIM1);
  ICR1 = BUZZ_TIMER;
  OCR1A = buzz_vol;
  TCNT1 = 0x00;
  TIMSK1 = (0x01 << OCIE1A) | (0x01 << TOIE1);
  power_status |= (0x01 << WAIT_TIM1);
}
void _BUZZ_VOL_SET(uint8_t vol) {
  buzz_vol = (BUZZ_TIMER / 2) / 10 * vol;
}
//---------------------------------Прерывание сигнала для пищалки---------------------------------------
ISR(TIMER1_OVF_vect, ISR_NAKED) //прерывание сигнала для пищалки
{
  __asm__ __volatile__ (
    "SBI %[_BUZZ_PORT], %[_BUZZ_BIT] \n\t" //HIGH на выход пина
    "RETI                            \n\t" //выход из прерывания
    :
    : [_BUZZ_PORT]"I"(_SFR_IO_ADDR(BUZZ_PORT)),
    [_BUZZ_BIT]"I"(BUZZ_BIT)
  );
}
ISR(TIMER1_COMPA_vect) {
  BUZZ_OFF; //выключаем бузер
  cnt_puls--; //убавляем цикл таймера
  if (!cnt_puls) { //если циклы закончились
    SOUND_STOP; //выключаем таймер
  }
}
//---------------------------------Генерация частоты бузера----------------------------------------------
void buzz_pulse(uint16_t freq, uint16_t time) //генерация частоты бузера (частота 10..10000, длительность мс.)
{
  cnt_puls = ((uint32_t)freq * (uint32_t)time) / 1000UL; //пересчитываем частоту и время в циклы таймера
  PRR &= ~(0x01 << PRTIM1); //включаем питание таймера
  ICR1 = (F_CPU / SOUND_PRESCALER) / freq; //устанавливаем предел
  OCR1A = ((((F_CPU / SOUND_PRESCALER) / 20) / freq) * mainSettings.volume); //рассчитывааем громкость
  TCNT1 = 0x00; //сбрасываем счетчик
  TIMSK1 = (0x01 << OCIE1A) | (0x01 << TOIE1); //разрешаем прерывания
  power_status |= (0x01 << WAIT_TIM1);
}
//----------------------------------Воспроизведение мелодии-----------------------------------------------
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
//-------------------------------Запуск воспроизведения мелодии-------------------------------------------
void melodyPlay(uint8_t melody, uint8_t replay) //запуск воспроизведения мелодии
{
  sound.semp = 0; //сбросили позицию семпла
  sound.replay = replay; //установили повтор
  sound.link = pgm_read_word(&general_sound[melody][0]); //установили ссылку
  sound.size = pgm_read_word(&general_sound[melody][1]); //установили размер
  timer_melody = 0; //сбросили таймер
  _buzz_disable(); //запрещаем щелчки
}
//------------------------------Остановка воспроизведения мелодии-----------------------------------------
void melodyStop(void) //остановка воспроизведения мелодии
{
  sound.replay = REPLAY_STOP; //сбросили воспроизведение
  timer_melody = 0; //сбросили таймер
  _buzz_enable(); //разрешаем щелчки
}
//-------------------------Получить аппроксимированный фон-----------------------------------
uint32_t _get_aprox_back(float _imp) //получить аппроксимированный фон
{
  if ((uint16_t)_imp >= pgm_read_word(&back_aprox_imp[PATTERNS_APROX - 1])) {
    for (uint8_t i = 0; i < PATTERNS_APROX; i++) { //выбор паттерна
      if ((uint16_t)_imp >= pgm_read_word(&back_aprox_imp[i])) { //если имп/с совпадают с паттерном
#if GEIGER_DEAD_TIME
        return (pumpSettings.geiger_time / (pgm_read_float(&back_aprox_coef[i]) * ((1.0 / _imp) - DEAD_TIME))); //рассчитываем фон в мкр/ч с поправкой на скорость счета и мертвое время
#else
        return (pumpSettings.geiger_time / (pgm_read_float(&back_aprox_coef[i]) * (1.0 / _imp))); //рассчитываем фон в мкр/ч с поправкой на скорость счета
#endif
        break;
      }
    }
  }

  return (_imp * pumpSettings.geiger_time); //рассчитываем фон в мкр/ч
}
//---------------------------------------Расчет точности замера---------------------------------------------------
uint8_t _get_accur(uint32_t num) //расчет точности замера
{
  return (num) ? constrain(((mainSettings.sigma_lvl + 1) / sqrtf((float)num)) * 100, 1, 99) : 99; //находим статистическую точность
}
//------------------------------------------Частиц/см2*мин--------------------------------------------------------
void _print_couts_per_cm2(float num) //частиц/см2*мин
{
  num /= GEIGER_AREA; //рассчитываем ч*см2/м

  setFont(MediumNumbers); //установка шрифта
  printNumF(num, (num < 100) ? 1 : 0, 1, 8, 46, 4, TYPE_CHAR_FILL); //строка 1
  print(UNIT_COUNT_PER_SQUARE_CM, 54, 16); //строка 1 ч/см2
}
//------------------------------------------Частиц/см2*мин--------------------------------------------------------
void _print_small_couts_per_cm2(float num, uint8_t pos_y) //частиц/см2*мин
{
  num /= GEIGER_AREA; //рассчитываем ч*см2/м

  print(UNIT_COUNT_PER_SQUARE_CM, 54, pos_y); //строка 2 ч/см2
#if (TYPE_CHAR_FILL > 44)
  printNumF(num, (num < 100) ? 1 : 0, 30, pos_y, 46, 4, TYPE_CHAR_FILL); //строка 2
#else
  printNumF(num, (num < 100) ? 1 : 0, 30, pos_y, 46, 4, 32);
#endif
}
//-----------------------------------Отрисовка сообщения разряженной батареи----------------------------------------
void _low_bat_show(void) //отрисовка сообщения разряженной батареи
{
  drawBitmap(26, 0, low_bat_img, 32, 32); //рисуем заставку
  print(B_BAT, CENTER, 32); //Батарея
  print(B_LOW, CENTER, 40); //разряжена!
}
//-----------------------------------Сообщение об разряженной батареи-----------------------------------------------
boolean _bat_massege(void) //сообщение об разряженной батареи
{
  if (low_bat_massege) { //если флаг разрешения сообщения поднят и заряд ниже установленного то выводим предупреждение
    low_bat_massege = 0; //запрещаем вывод сообщения

    _disable_sleep(); //просыпаемся если спали

#if BAT_LOW_SOUND
    melodyPlay(SOUND_BAT_LOW, REPLAY_ONCE); //звук разряженной батареи
#endif

    clrScr(); // Очистка экрана
    _low_bat_show(); //отрисовка сообщения разряженной батареи
    _wait(MASSEGE_TIME); //ждём

    if (bat_adc >= LOW_BAT_POWER) return 1; //выключение устройства
  }
  return 0; //нормальное состояние
}
//---------------------------------------------Диалог выбора---------------------------------------------------------
boolean dialogSwitch(uint8_t timer) //диалог выбора
{
  boolean cursor = 0; //положение курсора

  while (1) {
    if (_data_update()) { //если был тик, обрабатываем данные
      switch (buttonState()) {
        case DOWN_KEY_PRESS: cursor = 0; break; //выбор нет
        case UP_KEY_PRESS: cursor = 1; break; //выбор да
        case SEL_KEY_PRESS: return cursor; //выбор пункта
      }

      if (_check_screen()) { //обновление дисплея
        if (timer) { //если включен таймаут
          if (++time_out > timer) return 0; //выходим по таймауту
        }

        choice_menu(cursor); //меню выбора
      }
    }
  }
  return 0;
}
//----------------------------------------------Меню выбора----------------------------------------------------------
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
//------------------------------------------Отображение значений------------------------------------------------------
void _print_rads_unit(boolean type, uint32_t num, boolean divisor, uint8_t char_all, uint8_t num_x, uint8_t num_y, boolean unit, uint8_t unit_x, uint8_t unit_y, boolean dash) //отображение значений
{
  boolean mode = 0; //режим единиц
  uint8_t div = 0; //пределитель
  uint8_t dec = 0; //десятые доли

  uint32_t data = (divisor) ? (num / 10) : num; //пределитель увеличения разрядности

  if (mainSettings.rad_mode) { //если мкЗ
    if (data >= 10000000) { //предел 4
      if (data >= 100000000) num = (divisor) ? 99999 : 9999; //ограничение
      else div = 5; //пределитель 5
      mode = 1; //режим мЗ
    }
    else if (data >= 1000000) { //предел 3
      div = 4; //пределитель 4
      dec = 1; //десятые 1
      mode = 1; //режим мЗ
    }
    else if (data >= 10000) { //предел 2
      div = 3; //пределитель 3
      dec = 2; //десятые 2
      mode = 1; //режим мЗ
    }
    else if (data >= 1000) { //предел 1
      div = 1; //пределитель 1
      dec = 1; //десятые 1
    }
    else dec = 2; //предел 0
  }
  else { //иначе мкР
    if (data >= 100000) { //предел 2
      if (data >= 10000000) num = (divisor) ? 99999 : 9999; //ограничение
      else div = 3; //пределитель 3
      mode = 1; //режим мР
    }
    else if (data >= 10000) { //предел 1
      div = 2; //пределитель 2
      dec = 1; //десятые 1
      mode = 1; //режим мР
    }
  }

  if (num_x != RIGHT) print(_rads_unit(mode, unit), unit_x, unit_y); //устанавливаем единицы измерения

  _clear_buff();
  if (dash) {
    while (char_all) {
      char_all--;
      _add_text(UNIT_DASH);
    }
  }
  else {
#if (TYPE_CHAR_FILL > 44)
    _add_num_int_f(num, dec, div, '.', char_all, TYPE_CHAR_FILL); //вывод чисел
#else
    _add_num_int_f(num, dec, div, '.', char_all, (type) ? TYPE_CHAR_FILL : 32); //вывод чисел
#endif
  }

  if (num_x == RIGHT) {
    _add_text(_rads_unit(mode, unit));
  }
  if (type) setFont(MediumNumbers); //установка шрифта
  _print_text(num_x, num_y);
}
//----------------------------------Единицы измерения------------------------------------------------------
const char* _rads_unit(boolean set, boolean unit) //единицы измерения
{
  if (!mainSettings.rad_mode) { //рентген
    if (!set) { //мкР
      if (!unit) return UNIT_UR_H; //строка 2 мкР/ч
      else return UNIT_UR; //строка 2 мкР
    }
    else { //мР
      if (!unit) return UNIT_MR_H; //строка 2 мР/ч
      else return UNIT_MR; //строка 2 мР
    }
  }
  else { //зиверт
    if (!set) { //мкЗв
      if (!unit) return UNIT_USV_H; //строка 2 мкЗ/ч
      else return UNIT_USV; //строка 2 мкЗ
    }
    else { //мЗв
      if (!unit) return UNIT_MSV_H; //строка 2 мЗ/ч
      else return UNIT_MSV; //строка 2 мЗ
    }
  }
}
//---------------------------------Проверка значений уровня тревоги-----------------------------------------------
void _check_alarm_level(void) //проверка значений уровня тревоги
{
  if (alarm_dose_set != mainSettings.alarm_level_dose) { //если предыдущая установка тревоги дозы не равна текущей
    alarm_dose_set = mainSettings.alarm_level_dose; //запомнили текущую установку тревоги дозы
    if ((rad_dose - alarm_dose_wait) >= alarm_dose_set) alarm_dose_wait = rad_dose; //сбросили буфер тревоги дозы
  }
  if (warn_dose_set != mainSettings.warn_level_dose) { //если предыдущая установка предупреждения дозы не равна текущей
    warn_dose_set = mainSettings.warn_level_dose; //запомнили текущую установку предупреждения дозы
    if ((rad_dose - warn_dose_wait) >= warn_dose_set) warn_dose_wait = rad_dose; //сбросили буфер предупреждения дозы
  }
}
//--------------------------------Отображение значений уровня тревоги---------------------------------------------
void _print_alarm_level(uint16_t lvl, uint8_t y, uint8_t mode)
{
  _clear_buff();
  if (!mainSettings.rad_mode) _add_num_int(lvl);
  else _add_num_int_f(lvl, mode ? 1 : 2, mode);
  _print_text(RIGHT, y);
}
//----------------------------------------Индикация тревоги-------------------------------------------------------
void _alarm_show(uint8_t wait, uint8_t alarm) //индикация тревоги
{
  if (wait) drawBitmap(60, 0, beep_alt_wait_img, 7, 8); //если ждем понижения фона
  else {
    switch (alarm) { //если тревога запрещена
      case 0: drawBitmap(60, 0, buzz_alt_off_img, 7, 8); break; //тревога выключена
      case 1: drawBitmap(60, 0, buzz_alt_on_img, 7, 8); break; //только звук
      case 2: drawBitmap(60, 0, beep_alt_vibro_img, 7, 8); break; //только вибрация
      case 3: drawBitmap(60, 0, beep_alt_img, 8, 8); break; //звук и вибрация
    }
  }
}
//------------------------------------------Выбор тревоги----------------------------------------------------------
void _alarm_warning(void) //выбор тревоги
{
  static uint8_t alarm_state;

  if (alarm_state != alarm_switch) {
    alarm_state = alarm_switch;

    melodyStop(); //сброс воспроизведения мелодии
    _vibro_off(); //выключаем вибрацию
    _disable_sleep(); //просыпаемся если спали

    sleep_manual &= ~0x04; //отключили ручную блокировку сна

    switch (alarm_switch) {
      case 1: //фон 1
        warn_messege(0, mainSettings.alarm_back, SOUND_WARN); //фон 1
#if LOGBOOK_RETURN
        if (bookSettings.logbook_warn) _logbook_data_update(1, 1, rad_back); //обновление журнала
#endif
        break;
      case 2: //доза 1
        warn_messege(1, mainSettings.alarm_dose, SOUND_WARN); //доза 1
#if LOGBOOK_RETURN
        if (bookSettings.logbook_warn) _logbook_data_update(1, 2, rad_dose); //обновление журнала
#endif
        break;
      case 3: //фон 2
        warn_messege(0, mainSettings.alarm_back, SOUND_ALARM); //фон 2
#if LOGBOOK_RETURN
        if (bookSettings.logbook_alarm) _logbook_data_update(0, 1, rad_back); //обновление журнала
#endif
        break;
      case 4: //доза 2
        warn_messege(1, mainSettings.alarm_dose, SOUND_ALARM); //доза 2
#if LOGBOOK_RETURN
        if (bookSettings.logbook_alarm) _logbook_data_update(0, 2, rad_dose); //обновление журнала
#endif
        break;
    }
  }

  switch (alarm_switch) { //управление виброоткликом
    case 1: //фон 1
    case 3: //фон 2
      _vibro_on(mainSettings.alarm_back);
      break;
    case 2: //доза 1
    case 4: //доза 2
      _vibro_on(mainSettings.alarm_dose);
      break;
  }
}
//-------------------------------------Звук предупреждения-------------------------------------------------
void warn_messege(boolean set, uint8_t state, uint8_t sound) //звук предупреждения
{
  scr_mode = set; //переключаемся на экран тревоги
  if (set) dose_mode = 0; //переходим к текущей дозе

  sleep_manual |= 0x04; //включили ручную блокировку сна

  switch (state) { //в зависимости от режима
    case 1: //мелодия
    case 3: //мелодия + вибро
      melodyPlay(sound, REPLAY_CYCLE); //звук предупреждения
      break;
  }
}
//-------------------------------------Сброс предупреждения------------------------------------------------
boolean skip_warn_messege(void) //сброс предупреждения
{
  switch (alarm_switch) { //режим тревоги
    case 0: return 1;
    case 1: warn_back_wait = 1; break; //сбросить предупреждение фон
    case 2: warn_dose_wait = rad_dose; break; //сбросить предупреждение доза
    case 3: alarm_back_wait = warn_back_wait = 1; break; //сбросить тревогу фон
    case 4: alarm_dose_wait = warn_dose_wait = rad_dose; break; //сбросить тревогу доза
  }
  alarm_switch = 0;
  return 0;
}
//--------------------------------Отображение сообщения тревоги--------------------------------------------
void alarm_massage_show(boolean text, uint8_t pos) { //отображение сообщения тревоги
  if (screen_anim) {
    invertText(true);
    drawLine(pos / 8, 0, 83, 0xFF); //рисуем линию
  }
  if (!text) print(A_WARN, CENTER, pos); //строка ОПАСНОСТЬ!
  else print(A_ALARM, CENTER, pos); //строка ТРЕВОГА!

  invertText(false);
}
//-------------------------------------------Тревога--------------------------------------------------------
boolean alarm_messege(void) //тревога
{
#if ALARM_AUTO_DISABLE
  if (alarm_switch) {
    switch (alarm_switch) { //режим тревоги
      case 1: //фон 1
        if (rad_back < (mainSettings.warn_level_back * ALARM_AUTO_GISTERESIS)) { //иначе ждем понижения фона тревоги 1
#if TIME_OUT_ALARM
          time_out = TIME_OUT_ALARM; //устанавливаем признак отсутствия тревоги
#else
#if LOGBOOK_RETURN
          if (bookSettings.logbook_alarm) bookSettings.logbook_alarm = 2; //устанавливаем флаг пропущенной тревоги
#endif
          skip_warn_messege(); //сброс предупреждения
#endif
        }
        break;
      case 3: //фон 2
        if (rad_back < (mainSettings.alarm_level_back * ALARM_AUTO_GISTERESIS)) { //иначе ждем понижения фона тревоги 2
#if TIME_OUT_ALARM
          time_out = TIME_OUT_ALARM; //устанавливаем признак отсутствия тревоги
#else
#if LOGBOOK_RETURN
          if (bookSettings.logbook_warn) bookSettings.logbook_warn = 2; //устанавливаем флаг пропущенного предупреждения
#endif
          skip_warn_messege(); //сброс предупреждения
#endif
        }
        break;
    }

#if TIME_OUT_ALARM
    if (++time_out > TIME_OUT_ALARM) { //если время вышло
#if LOGBOOK_RETURN
      switch (alarm_switch) { //управление виброоткликом
        case 1: //фон 1
        case 2: //доза 1
          if (bookSettings.logbook_warn) bookSettings.logbook_warn = 2; //устанавливаем флаг пропущенного предупреждения
          break;
        case 3: //фон 2
        case 4: //доза 2
          if (bookSettings.logbook_alarm) bookSettings.logbook_alarm = 2; //устанавливаем флаг пропущенной тревоги
          break;
      }
#endif
      skip_warn_messege(); //сброс предупреждения
    }
#endif
  }
#endif

  if (alarm_switch > 2) { //если режим тревоги
    drawBitmap(26, 0, rad_img, 32, 32);
#if TYPE_ALARM_IND == 2
    print(A_ALARM, CENTER, 32); //строка ТРЕВОГА!
#endif

#if TYPE_ALARM_IND != 2
    drawLine(4); //очистка строки 4
    alarm_massage_show(1, 32); //тревога
#endif

    drawLine(5); //очистка строки 5
    switch (alarm_switch) {
      case 3: //фон 2
        print(A_BACK, LEFT, 40); //фон
        _print_rads_unit(0, rad_back, 1, 5, RIGHT, 40, 0, RIGHT, 40); //текущий фон
        break;

      case 4://доза 2
        print(A_DOSE, LEFT, 40); //доза
        _print_rads_unit(0, rad_dose, 1, 5, RIGHT, 40, 1, RIGHT, 40); //текущая доза
        break;
    }

    return 1;
  }
  return 0;
}
//------------------------------------Шапка экрана----------------------------------------------------
void _print_task_bar(const char *title) //шапка экрана
{
  drawLine(0, 0, 83, 0xFF); //рисуем линию
  drawBitmap(70, 0, font_bat_img, 12, 8); //устанавлваем фон батареи
  drawBitmap(70, 0, bat_alt_img, bat * 2, 8); //отображаем состояние батареи

  invertText(true);
  print(title, 1, 0);
  invertText(false);
}
//----------------------------------Отрисовка точности------------------------------------------------
void _print_accur_percent(uint8_t num) //отрисовка точности
{
  drawBitmap(54, 8, plus_minus_img, 3, 8); //±
  setFont(TinyNumbersDown); //установка шрифта
  printNumI(num, 58, 7, 2, 48); //точность
  drawBitmap(66, 8, percent_img, 6, 8); //%
  setFont(TinyNumbersDown); //установка шрифта
  printNumI(mainSettings.sigma_lvl + 1, 75, 7); //сигма
  drawBitmap(79, 8, sigma_img, 5, 8); //σ
}
//--------------------------------Отрисовка предела фона----------------------------------------------
void _print_back_bar(uint32_t num) //отрисовка предела фона
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
//-----------------------------Отрисовка сохранения дозы--------------------------------------------
void _print_time_bar(uint16_t num) //отрисовка сохранения дозы
{
  drawBitmap(0, 32, back_scale_img, 84, 8);
  uint8_t _start = map(num, 0, STAT_UPD_TIME - 1, 0, 70);
  drawLine(4, 2 + _start, 12 + _start, 0x18); //рисуем шкалу
}
//---------------------------------Вывод логотипа---------------------------------------------------
void _init_logo(void) //вывод логотипа
{
#ifdef RADON
  drawBitmap(0, 0, radon_img, 84, 24); //выводим лого
  drawLine(3, 19, 63, 0x02); //рисуем линию
#else
  drawBitmap(0, 0, logo_img, 84, 24); //выводим лого
#endif
}
//-------------------------------Вывод рамки загрузки-----------------------------------------------
void _init_load_bar(const char* txt) //вывод рамки загрузки
{
  print(txt, CENTER, 31); //надпись
  drawLine(5, 9, 73, 0x81); //рамка
  drawLine(5, 9, 9, 0xFF);
  drawLine(5, 73, 73, 0xFF);
}
//-----------------------------Установка полосы загрузки--------------------------------------------
inline void _set_load_bar(uint8_t data, uint8_t min, uint8_t max) //установка полосы загрузки
{
  drawLine(5, 9, map(data, min, max, 0, 73), 0x7E); //прогресс бар загрузки
}
//-----------------------------Очистка строк загрузки-----------------------------------------------
void _rows_clear(void) //очистка строк загрузки
{
  drawLine(4); //очистка строки 4
  drawLine(5); //очистка строки 5
}
//----------------Количество импульсов в минуту для режима замера--------------------------------------
float _measur_get_imp_per_min(uint32_t imp) //количество импульсов в минуту для режима замера
{
  return ((float)imp / pgm_read_byte(&diff_measuring[mainSettings.measur_pos]));
}
//----------------------------Сброс режима замера------------------------------------------------------
void _measur_reset(void) //сброс режима замера
{
  measur = 0; //выключаем замер
  time_switch = 0; //сбрасываем таймер
  next_measur = 1; //сбрасываем флаг следующего замера
  alarm_measur = 1; //разрешаем оповещение оканчания замера
  first_froze = 0; //сбрасываем счетчик 1-го замера
  second_froze = 0; //сбрасываем счетчик 2-го замера
  measur_back = 0; //сбрасываем результат замера в мкр/ч
  measur_imp = 0; //сбрасываем результат замера в имп
}
//-------------------------------Оостановка замера------------------------------------------------------
void _measur_stop(void) //остановка замера
{
  boolean cursor = 0; //курсор

  clrScr(); //очистка экрана
  print(M_STOP, CENTER, 8); //Остановить
  print(M_MEASUR, CENTER, 16); //замер?

  while (1) {
    if (_data_update()) { //обработка данных
      switch (buttonState()) {
        case DOWN_KEY_PRESS: cursor = 0; break; //выбор нет
        case UP_KEY_PRESS: cursor = 1; break; //выбор да

        case SEL_KEY_PRESS: //выбор пункта
          if (cursor) _measur_reset(); //сброс режима замера
          return; //выход
      }

      if (_check_screen()) {
        choice_menu(cursor); //меню выбора
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

#if MEASUR_SOUND
    melodyPlay(SOUND_MEASUR, REPLAY_ONCE); //звук окончания замера
#endif

    _wait(MASSEGE_TIME); //ждём

    switch (measur) {
      case 1: alarm_measur = 1; break; //запрещаем повторное оповещение
      case 2: {
          measur = 0; //возвращаемся к результату
          time_switch = 0; //сбрасываем таймер
          alarm_measur = 1; //разрешаем оповещение

          measur_imp = (first_froze < second_froze) ? second_froze - first_froze : 0; //текущий результат замера в ч*см2/м
#if APPROX_BACK_SCORE
          measur_back = (measur_imp) ? (_get_aprox_back(_measur_get_imp_per_min(second_froze) / 60) - _get_aprox_back(_measur_get_imp_per_min(first_froze) / 60)) : 0; //текущий результат замера в мкр/ч
#else
          measur_back = (measur_imp) ? (pumpSettings.geiger_time * (_measur_get_imp_per_min(measur_imp) / 60)) : 0; //текущий результат замера в мкр/ч
#endif

#if LOGBOOK_RETURN
          if (bookSettings.logbook_measur) {
            bookSettings.logbook_measur = 2; //устанавливаем признак новой записи
#if  TYPE_MEASUR_LOGBOOK
            _logbook_data_update(2, pgm_read_byte(&diff_measuring[mainSettings.measur_pos]), measur_imp); //обновление журнала ч/см2
#else
            _logbook_data_update(2, pgm_read_byte(&diff_measuring[mainSettings.measur_pos]), measur_back); //обновление журнала мкР/ч
#endif
          }
#else
#if  TYPE_MEASUR_LOGBOOK
          _logbook_data_update(2, pgm_read_byte(&diff_measuring[mainSettings.measur_pos]), measur_imp); //обновление журнала ч/см2
#else
          _logbook_data_update(2, pgm_read_byte(&diff_measuring[mainSettings.measur_pos]), measur_back); //обновление журнала мкР/ч
#endif
#endif
        }
        break;
    }
  }
}
//-------------------------------Режим замера----------------------------------------------------------
uint8_t measur_menu(void) //режим замера
{
  _measur_reset(); //сброс режима замера

  while (1) {
    if (_data_update()) { //обработка данных
      _error_messege(); //обработка ошибок
      _measur_massege(); //оповещение об окончании замера
      if (_bat_massege()) return POWER_DOWN_PROGRAM; //обработка сообщения разряженой батареи

      switch (buttonState()) {
#ifdef PCD8544
#if BUTTON_MODE
        case UP_KEY_PRESS: //клик кнопки вверх
#else
        case DOWN_KEY_HOLD: //удержание кнопки вниз
#endif
          _fast_light(); //быстрое включение посветки
          break;
#endif

#if BUTTON_MODE
        case DOWN_KEY_HOLD: //удержание кнопки вниз
#else
        case DOWN_KEY_PRESS: //клик кнопки вниз
#endif
          if (measur) _measur_stop(); //если идет замер, спрашиваем нужно ли остановить замер
          else _measur_reset(); //сброс режима замера
          break;

#if BUTTON_MODE
        case DOWN_KEY_PRESS: //клик кнопки вниз
#else
        case UP_KEY_PRESS: //клик кнопки вверх
#endif
          if (measur) _measur_stop(); //если идет замер, спрашиваем нужно ли остановить замер
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
            screen_anim = 0;
          }
          break;

        case SEL_KEY_HOLD: //удержание кнопки выбора
          if (measur) _measur_stop(); //если идет замер, спрашиваем нужно ли остановить замер
          else return MENU_PROGRAM; //выходим в меню
          break;
      }

      if (_check_screen()) {
        clrScr(); //очистка экрана
        _print_task_bar(M_MEASUR_BETA); //отрисовываем фон

        switch (measur) {
          case 0: //результат
            if (next_measur) {
              if (!screen_anim) {
                print(M_RESULT, CENTER, 24); //результат
                _print_couts_per_cm2(_measur_get_imp_per_min(measur_imp)); //результат ч*см2/м
              }
              else {
                print(M_BACK_OK, CENTER, 24); //ок - замер фона
                _print_rads_unit(1, measur_back, 0, 4, 1, 8, 0, 54, 16); //результат мкр/ч
              }
            }
            else print(M_RESULT, CENTER, 24); //результат

            _print_accur_percent(_get_accur(measur_imp)); //отрисовка точности

            print(M_BACK_I, LEFT, 32); //строка 1 фон
            _print_small_couts_per_cm2(_measur_get_imp_per_min(first_froze), 32);

            print(M_SAMP_I, LEFT, 40); //строка 2 обр
            _print_small_couts_per_cm2(_measur_get_imp_per_min(second_froze), 40);

            break;

          case 1: //1-й замер
            if (next_measur) {
              switch (screen_anim) {
                case 0: print(M_BACK, CENTER, 24); break; //замер фона
                case 1: print(M_SAMP_OK, CENTER, 24); break; //ок - зам. образца
              }
            }
            else print(M_BACK, CENTER, 24); //замер фона
            _print_couts_per_cm2((float)first_froze / (((time_switch) ? time_switch : 1) / 60.0)); //первый замер ч*см2/м
            _print_accur_percent(_get_accur(first_froze)); //отрисовка точности
            break;

          case 2: //2-й замер
            _print_couts_per_cm2((float)second_froze / (((time_switch) ? time_switch : 1) / 60.0)); //второй замер ч*см2/м
            _print_accur_percent(_get_accur(second_froze)); //отрисовка точности
            print(M_SAMP, CENTER, 24); //замер образца
            break;
        }

        if (measur) { //если идет замер
          drawLine(4, 1, map(time_switch, 0, pgm_read_byte(&diff_measuring[mainSettings.measur_pos]) * 60, 5, 82), 0x30); //шкала пройденого времени

          _clear_buff(); //очистка буфера
          _add_num_int(pgm_read_byte(&diff_measuring[mainSettings.measur_pos]), 2, 32); //минут всего
          _add_text(M_MIN); //строка 1 мин
          _print_text(RIGHT, 40); //вывод текста

          _clear_buff(); //очистка буфера
          _add_num_int(((pgm_read_byte(&diff_measuring[mainSettings.measur_pos]) * 60 - time_switch) / 60), 2, '0'); //минут
          _add_text(M_TIME); //строка 2
          _add_num_int((pgm_read_byte(&diff_measuring[mainSettings.measur_pos]) * 60 - time_switch) % 60, 2, 48); //секунд
          _print_text(LEFT, 40); //вывод текста
        }
      }
    }
  }
  return INIT_PROGRAM;
}
//-------------------------Обновление данных поиска----------------------------------------------------
void _search_update(void) //обновление данных поиска
{
  static uint8_t score_now; //текущее количество ячеек
  static uint16_t score_cnt; //счетчик тиков графика
  static uint16_t scan_now; //имп/с за период
  static uint32_t imp_s; //имп/с для расчетов

  if (++score_cnt >= search_time_now) { //расчет показаний
    uint32_t temp_buff = 0; //временный буфер расчета имп
    uint16_t temp_data = scan_buff; //запомнили текущее количество импульсов
    scan_buff = 0; //сбрасываем счетчик импульсов

    if (!search_disable) {
      if (search_score_now < score_now) search_score_now++;
      else search_score_now = score_now;
      graf_max = MIN_IMP_SEARCH_BUFF; //сбрасываем максимум графика

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
    for (uint8_t i = 0; i < search_score_now; i++) temp_buff += search_buff[i]; //сдвигаем массив
#else //справа-налево
    for (uint8_t i = 76 - search_score_now; i < 76; i++) temp_buff += search_buff[i]; //сдвигаем массив
#endif

    rad_imp = ((float)temp_buff / search_score_now) * (1000.00 / pgm_read_word(&search_time[mainSettings.search_pos])); //персчет имп/сек.
    rad_imp_m = rad_imp * 60.0; //персчет импульсов в имп/мин.
#if APPROX_BACK_SCORE
    rad_search = _get_aprox_back(rad_imp); //считаем мкР/ч
#else
    rad_search = rad_imp * pumpSettings.geiger_time; //считаем мкР/ч
#endif

    imp_s = search_buff[0] * (1000.00 / pgm_read_word(&search_time[mainSettings.search_pos])); //персчет имп/сек.

    score_now = (mainSettings.search_score != 8) ? mainSettings.search_score : map((imp_s > SEARCH_IND_MAX) ? SEARCH_IND_MAX : imp_s, 0, SEARCH_IND_MAX, 7, 0);
    score_now = pgm_read_byte(&search_score[score_now]);

    score_cnt = 0; //сброс
    screen_update = 0; //разрешаем обновление графика
  }

  scan_now = (imp_s > SEARCH_IND_MAX) ? SEARCH_IND_MAX : imp_s; //устанавливаем точки максимумов
  scan_now = map(scan_now, 0, SEARCH_IND_MAX, 0, 50); //корректируем под коэффициент
#if SEARCH_ANIM_DISABLE
  scan_ind = scan_now; //отображаем сразу
#else
  if (scan_now < scan_ind) scan_ind--; //добавляем плавности при уменьшении
  else scan_ind = scan_now; //если увеличелось то отображаем сразу
#endif
}
//-------------------------Инициализация режима поиск-----------------------------------------
uint8_t search_menu(void) //инициализация режима поиск
{
  uint8_t units = 0; //переключатель единиц графика

  search_time_now = (float)pgm_read_word(&search_time[mainSettings.search_pos]) / ((float)pumpSettings.wdt_period / 100.0); //переключатель динамического изменения времени

  while (1) {
    if (_data_update()) { //обработка данных
      _search_update(); //обновляем данные поика
      _error_messege(); //обработка ошибок
      if (_bat_massege()) return POWER_DOWN_PROGRAM; //обработка сообщения разряженой батареи

      switch (buttonState()) {
#ifdef PCD8544
#if BUTTON_MODE
        case UP_KEY_PRESS: //нажатие кнопки вверх
#else
        case DOWN_KEY_HOLD: //удержание кнопки вниз
#endif
          _fast_light(); //быстрое включение посветки
          break;
#endif

#if BUTTON_MODE
        case DOWN_KEY_HOLD: //удержание кнопки вниз
#else
        case DOWN_KEY_PRESS: //нажатие кнопки вниз
#endif
          rad_imp = 0; //сбрасываем имп/с
          rad_imp_m = 0; //сбрасываем имп/м
          rad_search = 0; //сбрасываем счет импульсов
          search_score_now = 0; //сбрасываем время счета графика
          search_disable = 0; //разрешаем обновление графика
          for (uint8_t i = 0; i < 76; i++) search_buff[i] = 0; //очищаем буфер графика
          break;

        case UP_KEY_HOLD: //удержание кнопки вверх
          FLASH_SWITCH; //вкл/выкл фонарика
          break;

#if BUTTON_MODE
        case DOWN_KEY_PRESS: //нажатие кнопки вниз
#else
        case UP_KEY_PRESS: //нажатие кнопки вверх
#endif
          search_disable = !search_disable; //запрещаем обновление графика
          break;

        case SEL_KEY_PRESS: //нажатие кнопки выбора
          if (units < 2) units++; else units = 0; //выбор режима
          break;

        case SEL_KEY_HOLD: //удержание кнопки выбора
          scan_buff = 0; //сбрасываем счетчик импульсов
          return MENU_PROGRAM; //выходим
      }

      if (_check_screen()) {
        clrScr(); //очистка экрана

        _print_task_bar(S_SEARCH); //отрисовываем фон
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
            _print_rads_unit(0, rad_search, 1, 5, 54, 16, 0, RIGHT, 8); //мкр/ч
            break;
        }

        drawBitmap(0, 24, scan_alt_left_img, 4, 24); //рисуем левую шкалу
        drawBitmap(80, 24, scan_alt_right_img, 4, 24); //рисуем правую шкалу
#if TYPE_GRAF_MOVE //слева-направо
        for (uint8_t x = 0; x < 76; x++) {
#else //справа-налево
        for (uint8_t x = 76; x;) {
          x--;
#endif
          drawGraf(map(search_buff[x], 0, graf_max, 1, 22), x, 3); //инициализируем график
        }
        drawDashLine(3, 8, 9, 4, 0x02);
#if SEARCH_ANIM_DISABLE
        drawLine(2, scan_ind + 1, 54); //убираем лишнее
        drawLine(2, 2, scan_ind, 0x3E); //рисуем полосу имп/с
#endif
      }

#if !SEARCH_ANIM_DISABLE
      drawLine(2, scan_ind + 1, 54); //убираем лишнее
      drawLine(2, 2, scan_ind, 0x3E); //рисуем полосу имп/с
#endif
    }
  }
  return INIT_PROGRAM;
}
//-----------------------------------Информация----------------------------------------
uint8_t information(void) //информация
{
  boolean mode = 0; //текущий режим

  while (1) {
    if (_data_update()) { //обработка данных
      switch (buttonState()) {
        case DOWN_KEY_PRESS: //клик кнопки вниз
        case UP_KEY_PRESS: //клик кнопки вверх
          mode = !mode; //переключили режим
          break;

        case SEL_KEY_PRESS: //клик кнопки выбора
          if (mode) { //сброс настроек
            EEPROM_UpdateByte(EEPROM_BLOCK_CRC_STRUCT, EEPROM_ReadByte(EEPROM_BLOCK_CRC_STRUCT) ^ 0xFF); //сбросили настройки
            RESET_SYSTEM; //перезагрузка
          }
          else { //меню отладки/параметров
#if DEBUG_RETURN
            return DEBUG_PROGRAM;
#else
            return PARAMETERS_PROGRAM;
#endif
          }
          break;
        case SEL_KEY_HOLD: //удержание кнопки выбора
          return MENU_PROGRAM; //выход
      }

      if (_check_screen()) {
#if TIME_OUT_INFO
        if (++time_out > TIME_OUT_INFO) return MAIN_PROGRAM;
#endif

        clrScr(); //очистка экрана
        _print_task_bar(I_INFO); //отрисовываем фон

        drawBitmap(0, 8, radon_img, 84, 24); //выводим лого

        drawLine(mode ? 5 : 4, 0, 83, 0xFF); //рисуем линию
        for (uint8_t i = 0; i < 2; i++) {
          if (mode == i) invertText(true); //включаем инверсию
          switch (i) {
            case 0:
#if DEBUG_RETURN
              print(I_DEBUG, CENTER, 32); //Отладка
#else
              print(I_PARAMETERS, CENTER, 32); //Параметры
#endif
              break;
            case 1: print(I_RESET, CENTER, 40); break; //Сброс настроек
          }
          if (mode == i) invertText(false); //выключаем инверсию
        }
      }
    }
  }
}
//-----------------------------------Параметры-----------------------------------------
uint8_t parameters(void) //параметры
{
  while (1) {
    if (_data_update()) { //обработка данных
      switch (buttonState()) {
        case SEL_KEY_HOLD: //удержание кнопки выбора
          return MENU_PROGRAM; //выход
      }

      if (_check_screen()) {
#if TIME_OUT_PARAM
        if (++time_out > TIME_OUT_PARAM) return MAIN_PROGRAM;
#endif

        clrScr(); //очистка экрана
        _print_task_bar(P_PARAM); //отрисовываем фон

        print(P_BAT, LEFT, 8); //Батарея:
        printNumF(_convert_vcc_bat(bat_adc), 2, RIGHT, 8, 46, 4, 48); //напряжение акб
        print(P_IMP_PUMP, LEFT, 16); //Импульс:
        printNumI(pump_puls_now, RIGHT, 16); //значение импульса
#if !PUMP_FEEDBACK
        print(P_HV_PUMP, LEFT, 24); //Напряжение:
        printNumI(_convert_vcc_hv(hv_adc), RIGHT, 24);//напряжение высокого

        print(P_PUMP_SPEED, LEFT, 32); //Скорость:
        printNumI(speed_hv, RIGHT, 32);//скорость накачки

        print(P_REFERENCE, LEFT, 40); //Опорное:
        printNumF(pumpSettings.reference, 2, RIGHT, 40, 46, 4, 48); //опорное напряжение
#else
        print(P_PUMP_SPEED, LEFT, 24); //Скорость:
        printNumI(speed_hv, RIGHT, 24);//скорость накачки

        print(P_REFERENCE, LEFT, 32); //Опорное:
        printNumF(pumpSettings.reference, 2, RIGHT, 32, 46, 4, 48); //опорное напряжение
#endif
      }
    }
  }
  return INIT_PROGRAM;
}
//-----------------------------------Отладка---------------------------------
uint8_t debug(void) //отладка
{
  uint8_t cursor = 0; //курсор
  btn_check = 0; //запрещем проверку кнопок

  while (1) {
    if (_data_update()) { //обработка данных
      switch (buttonState()) {
        case UP_KEY_PRESS: //прибавить значение
        case UP_KEY_KEEP: //удержание кнопки вверх
          switch (cursor) {
            case 0: if (pumpSettings.wdt_period < MAX_WDT_PERIOD) pumpSettings.wdt_period++; break; //период
            case 1: if (pumpSettings.geiger_time < MAX_GEIGER_TIME) pumpSettings.geiger_time += ((uint8_t)pumpSettings.geiger_time < 100) ? 0.1 : 1; break; //счет
            case 2: if (pumpSettings.reference < 1.50) pumpSettings.reference += 0.01; break; //прибавляем опорное напряжение
            case 3: if (pumpSettings.puls < 700) pumpSettings.puls += 10; break; //прибавляем длинну импульса
#if !PUMP_FEEDBACK
            case 4: if (pumpSettings.k_delitel < 1500) pumpSettings.k_delitel++; break; //прибавляем коэффициент делителя
            case 5: if (pumpSettings.ADC_value < 254) pumpSettings.ADC_value++; break; //прибавляем значение АЦП для преобразователя
#endif
          }
          break;

        case DOWN_KEY_PRESS: //убавить значение
        case DOWN_KEY_KEEP: //удержание кнопки вниз
          switch (cursor) {
            case 0: if (pumpSettings.wdt_period > MIN_WDT_PERIOD) pumpSettings.wdt_period--; break; //период
            case 1: if (pumpSettings.geiger_time > MIN_GEIGER_TIME) pumpSettings.geiger_time -= ((uint8_t)pumpSettings.geiger_time < 100) ? 0.1 : 1; break; //счет
            case 2: if (pumpSettings.reference > 0.50) pumpSettings.reference -= 0.01; break; //убавляем опорное напряжение
            case 3: if (pumpSettings.puls > 40) pumpSettings.puls -= 10; break; //убавляем длинну импульса
#if !PUMP_FEEDBACK
            case 4: if (pumpSettings.k_delitel > 10) pumpSettings.k_delitel--; break; //убавляем коэффициент делителя
            case 5: if (pumpSettings.ADC_value > 10) pumpSettings.ADC_value--; break; //убавляем значение АЦП для преобразователя
#endif
          }
          break;

        case SEL_KEY_PRESS: //переключение пунктов
          if (++cursor > ((!PUMP_FEEDBACK) ? 5 : 3)) cursor = 0;
          break;

        case SEL_KEY_HOLD: //выход в настройки
          settings_save(1); //сохраняем настройки преобразователя
          error_switch = 0; //сбрасываем указатель ошибки
          return MENU_PROGRAM;
      }

      if (_check_screen()) {
#if TIME_OUT_DEBUG
        if (++time_out > TIME_OUT_DEBUG) {
          settings_save(1); //сохраняем настройки преобразователя
          error_switch = 0; //сбрасываем указатель ошибки
          return MAIN_PROGRAM;
        }
#endif

        clrScr(); //очистка экрана
        _print_task_bar(D_DEBUG); //отрисовываем фон

        print(D_BAT, LEFT, 8); //БАТ
        printNumF(_convert_vcc_bat(bat_adc), 2, 20, 8, 46, 4, 48); //напряжение акб
        print(D_PULS_LEN, 46, 8); //ИМП
        printNumI(pump_puls_now, RIGHT, 8); //значение ацп акб
        print(D_PUMP_SPEED, 0, 16); //СКР
        printNumI(speed_hv, 20, 16); //скорость накачки
#if !PUMP_FEEDBACK
        print(D_HV_PUMP, 46, 16); //ВВ
        printNumI(_convert_vcc_hv(hv_adc), RIGHT, 16); //напряжение высокого
#else
        print(D_TIME_PUMP, 46, 16); //ВПН
        printNumI(pump_imp_time, RIGHT, 16); //период проверки напряжения
#endif

        printNumI(pumpSettings.wdt_period, 20, 24); //период
        printNumF(pumpSettings.geiger_time, ((uint8_t)pumpSettings.geiger_time < 100), RIGHT, 24, 46, 4, 32); //счёт
        printNumF(pumpSettings.reference, 2, 20, 32, 46, 4, 48); //опорное напряжение
        printNumI(pumpSettings.puls, RIGHT, 32); //длинна импульса
#if !PUMP_FEEDBACK
        printNumI(pumpSettings.k_delitel, 20, 40, 4); //коэффициент делителя
        printNumI(pumpSettings.ADC_value, RIGHT, 40); //значение АЦП для преобразователя
#endif

        for (uint8_t i = 0; i < ((!PUMP_FEEDBACK) ? 6 : 4); i++) {
          if (cursor == i) invertText(true); //включаем инверсию
          switch (i) {
            case 0: print(D_WDT_PER, LEFT, 24); break; //ПЕР
            case 1: print(D_GEIGER_TIME, 46, 24); break; //СЧ
            case 2: print(D_REFERENCE, LEFT, 32); break; //ОПР
            case 3: print(D_PULS_IND, 46, 32); break; //МТЛ
#if !PUMP_FEEDBACK
            case 4: print(D_COEF_DIV, LEFT, 40); break; //КДЛ
            case 5: print(D_PUMP_ADC, 46, 40); break; //АЦП
#endif
          }
          if (cursor == i) invertText(false); //выключаем инверсию
        }
      }
    }
  }
  return INIT_PROGRAM;
}
//------------------------------------Отрисовка пунктов------------------------------------------------------
void _settings_item_switch(boolean set, boolean inv, uint8_t num, uint8_t pos) //отрисовка пунктов
{
  uint8_t pos_row = (pos + 1) * 8; //переводим позицию в номер строки

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
        case 0: print(S_ITEM_BACKL, LEFT, pos_row); break; //Подсветка:
        case 1: if (!mainSettings.sleep_switch) print(S_SWITCH_MANUAL, RIGHT, pos_row); else printNumI(mainSettings.time_bright, RIGHT, pos_row); break;
      }
      break;

    case _SET_CONTRAST: //Контраст(Яркость)
      switch (set) {
        case 0:
#ifdef PCD8544
          print(S_ITEM_CONTRAST, LEFT, pos_row); //Контраст:
#endif
#ifdef SSD1306
          print(S_ITEM_BRIGHT, LEFT, pos_row); //Яркость:
#endif
          break;
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

    case _SET_VOLUME: //Громкость
      switch (set) {
        case 0: print(S_ITEM_VOLUME, LEFT, pos_row); break; //Громкость:
        case 1: printNumI(mainSettings.volume, RIGHT, pos_row); break;
      }
      break;

    case _SET_SENSITIV: //Чувствительность
      switch (set) {
        case 0: print(S_ITEM_SENSITIV, LEFT, pos_row); break; //Чувств:
        case 1: printNumI(map(mainSettings.sensitiv, 3, 13, 100, 0), RIGHT, pos_row); break;
      }
      break;

    case _SET_SIGMA_LVL: //Сигма
      switch (set) {
        case 0: print(S_ITEM_SIGMA, LEFT, pos_row); break; //Сигма:
        case 1: printNumI(mainSettings.sigma_lvl + 1, RIGHT, pos_row); break;
      }
      break;

    case _SET_AVERAG_POS: //Усред.фон
      switch (set) {
        case 0: print(S_ITEM_AVERAG, LEFT, pos_row); break; //Усред.фон:
        case 1: if (!mainSettings.averag_time) print(ALL_SWITCH_OFF, RIGHT, pos_row); else printNumI(mainSettings.averag_time, RIGHT, pos_row); break;
      }
      break;

    case _SET_MEASUR_POS: //Разн.зам
      switch (set) {
        case 0: print(S_ITEM_DIFF_MEASUR, LEFT, pos_row); break; //Разн.зам:
        case 1: printNumI(pgm_read_byte(&diff_measuring[mainSettings.measur_pos]), RIGHT, pos_row); break;
      }
      break;

    case _SET_SEARCH_POS: //Поиск
      switch (set) {
        case 0: print(S_ITEM_SEARCH, LEFT, pos_row); break; //Поиск:
        case 1: if (mainSettings.search_score != 8) printNumI(pgm_read_byte(&search_score[mainSettings.search_score]), RIGHT, pos_row); else print(S_SWITCH_AUTO, RIGHT, pos_row); break;
      }
      break;

    case _SET_SPEED_POS: //Скорость
      switch (set) {
        case 0: print(S_ITEM_SPEED, LEFT, pos_row); break; //Скорость:
        case 1: printNumIntF(pgm_read_word(&search_time[mainSettings.search_pos]), 2, 1, RIGHT, pos_row); break;
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
        case 1: _print_alarm_level(mainSettings.warn_level_back, pos_row, 0); break;
      }
      break;

    case _SET_ALARM_LEVEL_BACK: //Порог Ф2
      switch (set) {
        case 0: print(S_ITEM_ALARM_THRESHOLD_BACK_2, LEFT, pos_row); break; //Порог Ф2:
        case 1: _print_alarm_level(mainSettings.alarm_level_back, pos_row, 1); break;
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
        case 1: _print_alarm_level(mainSettings.warn_level_dose, pos_row, 0); break;
      }
      break;

    case _SET_ALARM_LEVEL_DOSE: //Порог Д2
      switch (set) {
        case 0: print(S_ITEM_ALARM_THRESHOLD_DOSE_2, LEFT, pos_row); break; //Порог Д2:
        case 1: _print_alarm_level(mainSettings.alarm_level_dose, pos_row, 1); break;
      }
      break;

#if USE_UART && (UART_SEND_BACK || UART_SEND_DOSE || UART_SEND_IMP)
    case _SET_UART_MOD:
      switch (set) {
        case 0: print(S_ITEM_UART_SET, LEFT, pos_row); break; //Порт:
        case 1: if (dataChannelState()) print(ALL_SWITCH_OFF, RIGHT, pos_row); else printNumI(UART_BAUND, RIGHT, pos_row); break;
      }
      break;
#endif
  }
  invertText(false); //выключаем инверсию
}
//------------------------------------Прибавление данных------------------------------------------------------
void _settings_data_up(uint8_t pos) //прибавление данных
{
  switch (pos) {
    case _SET_TIME_SLEEP: //Сон
      switch (mainSettings.sleep_switch) {
        case 0:
          mainSettings.sleep_switch = 2;
#ifdef PCD8544
          BACKL_ON;
#endif
          break;
        case 1: mainSettings.sleep_switch = 2; mainSettings.time_bright = 5; break;
        case 2: if (mainSettings.time_sleep < 250) mainSettings.time_sleep += 5; break;
      }
      break;
    case _SET_TIME_BRIGHT: //Подсветка
      switch (mainSettings.sleep_switch) {
        case 0:
          mainSettings.sleep_switch = 1;
#ifdef PCD8544
          BACKL_ON;
#endif
          break;
        case 1: if (mainSettings.time_bright < 250) mainSettings.time_bright += 5; break;
        case 2: if (mainSettings.time_bright < mainSettings.time_sleep - 5) mainSettings.time_bright += 5; break;
      }
      break;
    case _SET_CONTRAST: if (mainSettings.contrast < MAX_CONTRAST) _set_contrast_lcd(mainSettings.contrast += STEP_CONTRAST); break; //Контраст
#if ROTATE_DISP_RETURN
    case _SET_ROTATION: mainSettings.rotation = 1; break; //Разворот
#endif
    case _SET_RAD_FLASH: if (mainSettings.rad_flash < 2) mainSettings.rad_flash++; break; //Вспышки
    case _SET_BUZZ_SWITCH: if (mainSettings.buzz_switch < 2) mainSettings.buzz_switch++; break; //Щелчки
    case _SET_KNOCK_DISABLE: mainSettings.knock_disable = 0; break; //Зв.кнопок
    case _SET_VOLUME: if (mainSettings.volume < 10) mainSettings.volume++; break; //Громкость

    case _SET_SENSITIV: if (mainSettings.sensitiv > 3) mainSettings.sensitiv--; break; //Чувствительность
    case _SET_SIGMA_LVL: if (mainSettings.sigma_lvl < 2) mainSettings.sigma_lvl++; else mainSettings.sigma_lvl = 0; break; //Сигма
    case _SET_AVERAG_POS: if (mainSettings.averag_time < 60) mainSettings.averag_time++; else mainSettings.averag_time = 0; break; //Усред.фон

    case _SET_MEASUR_POS: if (mainSettings.measur_pos < 9) mainSettings.measur_pos++; break; //Разн.зам
    case _SET_SEARCH_POS: if (mainSettings.search_score < 8) mainSettings.search_score++; else mainSettings.search_score = 0; break; //Поиск
    case _SET_SPEED_POS: if (mainSettings.search_pos < 7) mainSettings.search_pos++; else mainSettings.search_pos = 0; break; //Скорость

    case _SET_RAD_MOD: mainSettings.rad_mode = 1; break; //Ед.измер

    case _SET_ALARM_BACK: if (mainSettings.alarm_back < 3) mainSettings.alarm_back++; break; //Тревога Ф
    case _SET_WARN_LEVEL_BACK: if (mainSettings.warn_level_back < 300) mainSettings.warn_level_back += 5; else mainSettings.warn_level_back = 30; break; //Порог Ф1
    case _SET_ALARM_LEVEL_BACK: if (mainSettings.alarm_level_back < 500) mainSettings.alarm_level_back += 10; else if (mainSettings.alarm_level_back < 1000) mainSettings.alarm_level_back += 50; else if (mainSettings.alarm_level_back < 65000) mainSettings.alarm_level_back += 100; else mainSettings.alarm_level_back = 300; break; //Порог Ф2
    case _SET_ALARM_DOSE: if (mainSettings.alarm_dose < 3) mainSettings.alarm_dose++; break; //Тревога Д
    case _SET_WARN_LEVEL_DOSE: if (mainSettings.warn_level_dose < 300) mainSettings.warn_level_dose += 5; else mainSettings.warn_level_dose = 10; break; //Порог Д1
    case _SET_ALARM_LEVEL_DOSE: if (mainSettings.alarm_level_dose < 500) mainSettings.alarm_level_dose += 10; else if (mainSettings.alarm_level_dose < 1000) mainSettings.alarm_level_dose += 50; else if (mainSettings.alarm_level_dose < 65000) mainSettings.alarm_level_dose += 100; else mainSettings.alarm_level_dose = 300; break; //Порог Д2
#if USE_UART && (UART_SEND_BACK || UART_SEND_DOSE || UART_SEND_IMP)
    case _SET_UART_MOD: if (dataChannelState()) dataChannelInit(); else dataChannelEnd(); break; //Порт
#endif
  }
}
//------------------------------------Убавление данных------------------------------------------------------
void _settings_data_down(uint8_t pos) //убавление данных
{
  switch (pos) {
    case _SET_TIME_SLEEP: if (mainSettings.time_sleep > 10) { //Сон
        mainSettings.time_sleep -= 5;
        if (mainSettings.time_bright == mainSettings.time_sleep) mainSettings.time_bright -= 5;
      }
      else if (mainSettings.sleep_switch == 2) mainSettings.sleep_switch = 1; break;
    case _SET_TIME_BRIGHT: if (mainSettings.time_bright > 5) mainSettings.time_bright -= 5; else mainSettings.sleep_switch = 0; break; //Подсветка
    case _SET_CONTRAST: if (mainSettings.contrast > MIN_CONTRAST) _set_contrast_lcd(mainSettings.contrast -= STEP_CONTRAST); break; //Контраст
#if ROTATE_DISP_RETURN
    case _SET_ROTATION: mainSettings.rotation = 0; break; //Разворот
#endif
    case _SET_RAD_FLASH: if (mainSettings.rad_flash) mainSettings.rad_flash--; break; //Вспышки
    case _SET_BUZZ_SWITCH: if (mainSettings.buzz_switch) mainSettings.buzz_switch--; break; //Щелчки
    case _SET_KNOCK_DISABLE: mainSettings.knock_disable = 1; break; //Зв.кнопок
    case _SET_VOLUME: if (mainSettings.volume > 1) mainSettings.volume--; break; //Громкость

    case _SET_SENSITIV: if (mainSettings.sensitiv < 13) mainSettings.sensitiv++; break; //Чувствительность
    case _SET_SIGMA_LVL: if (mainSettings.sigma_lvl) mainSettings.sigma_lvl--; else mainSettings.sigma_lvl = 2; break; //Сигма
    case _SET_AVERAG_POS: if (mainSettings.averag_time) mainSettings.averag_time--; else mainSettings.averag_time = 60; break; //Усред.фон

    case _SET_MEASUR_POS: if (mainSettings.measur_pos) mainSettings.measur_pos--;  break; //Разн.зам
    case _SET_SEARCH_POS: if (mainSettings.search_score) mainSettings.search_score--; else mainSettings.search_score = 8; break; //Поиск
    case _SET_SPEED_POS: if (mainSettings.search_pos) mainSettings.search_pos--; else mainSettings.search_pos = 7; break; //Скорость

    case _SET_RAD_MOD: mainSettings.rad_mode = 0; break; //Ед.измер

    case _SET_ALARM_BACK: if (mainSettings.alarm_back) mainSettings.alarm_back--; break; //Тревога Ф
    case _SET_WARN_LEVEL_BACK: if (mainSettings.warn_level_back > 30) mainSettings.warn_level_back -= 5; else mainSettings.warn_level_back = 300; break; //Порог Ф1
    case _SET_ALARM_LEVEL_BACK: if (mainSettings.alarm_level_back > 1000) mainSettings.alarm_level_back -= 100; else if (mainSettings.alarm_level_back > 500) mainSettings.alarm_level_back -= 50; else if (mainSettings.alarm_level_back > 300) mainSettings.alarm_level_back -= 10; else mainSettings.alarm_level_back = 65000; break; //Порог Ф2
    case _SET_ALARM_DOSE: if (mainSettings.alarm_dose) mainSettings.alarm_dose--; break; //Тревога Д
    case _SET_WARN_LEVEL_DOSE: if (mainSettings.warn_level_dose > 10) mainSettings.warn_level_dose -= 5; else mainSettings.warn_level_dose = 300; break; //Порог Д1
    case _SET_ALARM_LEVEL_DOSE: if (mainSettings.alarm_level_dose > 1000) mainSettings.alarm_level_dose -= 100; else if (mainSettings.alarm_level_dose > 500) mainSettings.alarm_level_dose -= 50; else if (mainSettings.alarm_level_dose > 300) mainSettings.alarm_level_dose -= 10; else mainSettings.alarm_level_dose = 65000; break; //Порог Д2
#if USE_UART && (UART_SEND_BACK || UART_SEND_DOSE || UART_SEND_IMP)
    case _SET_UART_MOD: if (dataChannelState()) dataChannelInit(); else dataChannelEnd(); break; //Порт
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
      switch (buttonState()) {
        case DOWN_KEY_PRESS: //вниз
        case DOWN_KEY_KEEP: //удержание кнопки вниз
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
        case UP_KEY_KEEP: //удержание кнопки вверх
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

        case SEL_KEY_PRESS: //select key //выбор
          set = !set;
          break;

        case SEL_KEY_HOLD: //выход из настроек
          settings_save(0); //сохраняем настройки
          return MENU_PROGRAM;
      }

      if (_check_screen()) {
#if TIME_OUT_SETTINGS
        if (++time_out > TIME_OUT_SETTINGS) {
          settings_save(0); //сохраняем настройки
          return MAIN_PROGRAM;
        }
#endif

        clrScr(); // Очистка экрана
        _print_task_bar(S_SETTINGS); //отрисовываем фон

        for (uint8_t i = 0; i < 5; i++) { //отсчет строк
          for (uint8_t r = 0; r < 2; r++) { //отсчет позиции
            boolean inv = (i == cursor && r == set); //если курсор на нужной строке
            _settings_item_switch(r, inv, pos - cursor + i, i); //отрисовываем пункты настроек
          }
        }
      }
    }
  }
  return INIT_PROGRAM;
}
//------------------------------------Отрисовка пунктов------------------------------------------------------
void _menu_item_switch(boolean inv, uint8_t num, uint8_t pos) //отрисовка пунктов
{
  uint8_t pos_row = (pos + 1) * 8; //переводим позицию в номер строки

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
    case INFORMATION_PROGRAM: print(MAIN_INFORMATION, CENTER, pos_row); break; //Информация
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
  sleep_manual = 0; //отключили ручную блокировку сна
  power_manager = 0; //сбрасываем менеджер питания

  while (1) {
    if (_data_update()) { //обработка данных
      switch (buttonState()) {
        case DOWN_KEY_PRESS: //вниз
        case DOWN_KEY_KEEP: //удержание кнопки вниз
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
        case UP_KEY_KEEP: //удержание кнопки вверх
          if (pos > 0) { //изменяем позицию
            pos--;
            if (cursor > 0) cursor--; //изменяем положение курсора
          }
          else { //иначе конец списка
            pos = 6;
            cursor = 4;
          }
          break;

        case SEL_KEY_PRESS: //выбор пункта
          if ((pos + 1) == POWER_DOWN_PROGRAM) statistic_update(); //обновление статистики
          return pos + 1; //возвращаем выбранный пункт меню


        case SEL_KEY_HOLD: //выход к главным экранам
          return MAIN_PROGRAM;
      }

      if (_check_screen()) {
#if TIME_OUT_MENU
        if (++time_out > TIME_OUT_MENU) return MAIN_PROGRAM;
#endif

        clrScr(); // Очистка экрана
        _print_task_bar(MAIN_MENU); //отрисовываем фон

        for (uint8_t i = 0; i < 5; i++) _menu_item_switch((i == cursor) ? 1 : 0, pos - cursor + i + 1, i); //отрисовываем пункты настроек
      }
    }
  }
  return INIT_PROGRAM;
}
//------------------------------------Очистка журнала------------------------------------------------------
void _logbook_data_clear(void) //очистка журнала
{
  EEPROM_ClearBlock(EEPROM_BLOCK_LOGBOOK_INFO, EEPROM_SIZE_LOGBOOK_INFO * 4); //стирание блока заглавлений в EEPROM
}
//--------------------------------------Чтение журнала--------------------------------------------------------
void _logbook_data_read(uint8_t data_num) //чтение журнала
{
  EEPROM_ReadBlock((uint16_t)&logbook_info_buff, (uint16_t)EEPROM_BLOCK_LOGBOOK_INFO + (data_num * EEPROM_SIZE_LOGBOOK_INFO), sizeof(logbook_info_buff)); //считываем информацию в буфер
  EEPROM_ReadBlock((uint16_t)&logbook_data_buff, (uint16_t)EEPROM_BLOCK_LOGBOOK_DATA + (data_num * EEPROM_SIZE_LOGBOOK_DATA), sizeof(logbook_data_buff)); //считываем информацию в буфер
}
//------------------------------------Обновление журнала------------------------------------------------------
void _logbook_data_update(uint8_t data_num, uint8_t num, uint32_t data) //обновление журнала
{
  uint16_t byte_data = (uint16_t)EEPROM_BLOCK_LOGBOOK_INFO + (data_num * EEPROM_SIZE_LOGBOOK_INFO); //находим запрашиваемую позицию
  uint16_t dword_data = (uint16_t)EEPROM_BLOCK_LOGBOOK_DATA + (data_num * EEPROM_SIZE_LOGBOOK_DATA); //находим запрашиваемую позицию

  EEPROM_ReadBlock((uint16_t)&logbook_info_buff, byte_data, sizeof(logbook_info_buff)); //считываем информацию во временный буфер
  EEPROM_ReadBlock((uint16_t)&logbook_data_buff, dword_data, sizeof(logbook_data_buff)); //считываем информацию во временный буфер

  for (uint8_t b = 9; b; b--) logbook_info_buff[b] = logbook_info_buff[b - 1]; //смещаяем информацию в буфере
  logbook_info_buff[0] = num; //добавляем в начало буфера новое значение
  for (uint8_t d = 9; d; d--) logbook_data_buff[d] = logbook_data_buff[d - 1]; //смещаяем информацию в буфере
  logbook_data_buff[0] = data; //добавляем в начало буфера новое значение

  EEPROM_UpdateBlock((uint16_t)&logbook_info_buff, byte_data, sizeof(logbook_info_buff)); //записываем в память временный буфер
  EEPROM_UpdateBlock((uint16_t)&logbook_data_buff, dword_data, sizeof(logbook_data_buff)); //записываем в память временный буфер
}
//-----------------------------------Чтение журнала byte---------------------------------
uint8_t _data_read_byte(uint8_t byte_num) //чтение журнала byte
{
  return logbook_info_buff[byte_num]; //возвращаем запрошенные данные
}
//-----------------------------------Чтение журнала dword---------------------------------
uint32_t _data_read_dword(uint8_t dword_num) //чтение журнала dword
{
  return logbook_data_buff[dword_num]; //возвращаем запрошенные данные
}
//------------------------------------Отрисовка пунктов настроек журнала------------------------------------------------------
void _logbook_settings(boolean inv, uint8_t num, uint8_t pos) //отрисовка пунктов настроек журнала
{
  uint8_t pos_row = (pos + 1) * 8; //переводим позицию в номер строки

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
  uint8_t pos_row = (pos + 1) * 8; //переводим позицию в номер строки

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
  uint8_t pos_row = (pos + 1) * 8; //переводим позицию в номер строки

  uint8_t temp_byte = _data_read_byte(num);
  uint32_t temp_dword = _data_read_dword(num);

  if (inv) {
    drawLine(pos + 1, 0, 83, 0xFF); //рисуем линию
    invertText(true); //включаем инверсию
  }

  if (temp_byte) {
    switch (data_num) {
      case 0:
      case 1:
        if (temp_byte == 2) print(L_DATA_DOSE, LEFT, pos_row); //ДОЗА
        else print(L_DATA_BACK, LEFT, pos_row); //ФОН
        _print_rads_unit(0, temp_dword, 0, 4, RIGHT, pos_row, temp_byte - 1, RIGHT, pos_row); //единицы фона/дозы
        break;
      case 2:
        printNumI(temp_byte, LEFT, pos_row, 2); //время замера
        print(L_DATA_MINS, 12, pos_row); //м
#if TYPE_MEASUR_LOGBOOK
        _print_small_couts_per_cm2((float)temp_dword / temp_byte, pos_row); //отрисовываем ч/см2
#else
        _print_rads_unit(0, temp_dword, 0, 4, RIGHT, pos_row, 0, RIGHT, pos_row); //отрисовываем мкР/ч
#endif
        break;
      case 3:
        print(L_DATA_ERROR_NUM, LEFT, pos_row); //Ошибка #
        printNumI(temp_byte, RIGHT, pos_row); //номер ошибки
        break;
    }
  }
  else print(L_DATA_NULL, CENTER, pos_row); //- пусто -

  invertText(false); //выключаем инверсию
}
//------------------------------------Отрисовка журнала замеров------------------------------------------------------
void _logbook_measur_switch(boolean inv, uint8_t num, uint8_t pos) //отрисовка журнала замеров
{
  uint8_t pos_row = (pos + 1) * 8; //переводим позицию в номер строки

  uint8_t temp_byte = _data_read_byte(num);
  uint32_t temp_dword = _data_read_dword(num);

  if (inv) {
    drawLine(pos + 1, 0, 83, 0xFF); //рисуем линию
    invertText(true); //включаем инверсию
  }

  if (temp_byte) {
    printNumI(temp_byte, LEFT, pos_row, 2); //время замера
    print(L_DATA_MINS, 12, pos_row); //м
#if TYPE_MEASUR_LOGBOOK
    _print_small_couts_per_cm2((float)temp_dword / temp_byte, pos_row); //отрисовываем ч/см2
#else
    _print_rads_unit(0, temp_dword, 0, 4, RIGHT, pos_row, 0, RIGHT, pos_row); //отрисовываем мкР/ч
#endif
  }
  else print(L_DATA_NULL, CENTER, pos_row); //- пусто -

  invertText(false); //выключаем инверсию
}
//------------------------------------Журнал------------------------------------------------------
uint8_t logbook(void) //журнал
{
  uint8_t pos = 0; //позиция
  uint8_t point = 0; //пункт
  uint8_t cursor = 0; //курсор
  uint8_t max_item = 4; //максимум пунктов
  boolean err_mode = 0; //режим отображения ошибок

  while (1) {
    if (_data_update()) { //обработка данных
      switch (buttonState()) {
        case DOWN_KEY_PRESS: //вниз
        case DOWN_KEY_KEEP: //удержание кнопки вниз
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
        case UP_KEY_KEEP: //удержание кнопки вверх
          if (pos > 0) { //изменяем позицию
            pos--;
            if (cursor > 0) cursor--; //изменяем положение курсора
          }
          else { //иначе конец списка
            pos = max_item;
            cursor = (max_item < 4) ? max_item : 4;
          }
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
            case 4: err_mode = (err_mode) ? 0 : 1; break; //переходим на предпросмотр ошибки
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
            default: pos = cursor = point - 1; point = err_mode = 0; max_item = 4; break;
          }
          break;
      }

      if (_check_screen()) {
#if TIME_OUT_LOGBOOK
        if (++time_out > TIME_OUT_LOGBOOK) return MAIN_PROGRAM;
#endif

        clrScr(); // Очистка экрана
        _print_task_bar(L_LOGBOOK); //отрисовываем фон

        if ((point > 0) && (point < 5)) _logbook_data_read(point - 1); //чтение журнала

        for (uint8_t i = 0; i < 5; i++) {
          switch (point) {
            case 0: _logbook_item_switch((i == cursor) ? 1 : 0, pos - cursor + i, i); break; //отрисовываем пункты журнала
            case 5: _logbook_settings((i == cursor) ? 1 : 0, pos - cursor + i, i); break; //отрисовываем пункты настроек
            default:
              if (!err_mode) _logbook_data_switch((i == cursor) ? 1 : 0, pos - cursor + i, i, point - 1); //отрисовываем информацию
              else _error_messege_show(_data_read_byte(pos), _data_read_dword(pos)); //отрисовываем ошибку
              break;
          }
        }
      }
    }
  }

  return INIT_PROGRAM;
}
//------------------------------------Журнал замеров------------------------------------------------------
uint8_t logbook_measur(void) //журнал замеров
{
  uint8_t pos = 0; //позиция
  uint8_t cursor = 0; //курсор

  while (1) {
    if (_data_update()) { //обработка данных
      switch (buttonState()) {
        case DOWN_KEY_PRESS: //вниз
        case DOWN_KEY_KEEP: //удержание кнопки вниз
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
        case UP_KEY_KEEP: //удержание кнопки вверх
          if (pos > 0) { //изменяем позицию
            pos--;
            if (cursor > 0) cursor--; //изменяем положение курсора
          }
          else { //иначе конец списка
            pos = 9;
            cursor = 4;
          }
          break;

        case SEL_KEY_PRESS: //выбор
          data_reset(2); //очистка журнала
          break;

        case SEL_KEY_HOLD: //выход к главным экранам
          return MENU_PROGRAM;
      }

      if (_check_screen()) {
#if TIME_OUT_LOGBOOK
        if (++time_out > TIME_OUT_LOGBOOK) return MAIN_PROGRAM;
#endif

        clrScr(); // Очистка экрана
        _print_task_bar(L_LOGBOOK); //отрисовываем фон

        _logbook_data_read(2); //чтение журнала
        for (uint8_t i = 0; i < 5; i++) _logbook_measur_switch((i == cursor) ? 1 : 0, pos - cursor + i, i); //отрисовывам информацию
      }
    }
  }

  return INIT_PROGRAM;
}
//---------------------------------Отрисовка сообщения об ошибке---------------------------------------
void _error_messege_show(uint8_t err, uint32_t data) //отрисовка сообщения об ошибке
{
  clrScr(); //очистка экрана

  invertText(true);
  print(E_ERROR, CENTER, 0); //- ВНИМАНИЕ -
  invertText(false);

  switch (err) {
    case 0:
      print(E_ERROR_NULL, CENTER, 24); //- Нет данных -
      break;

    case 2:
      print(E_DATA_OVERLOAD, CENTER, 16); //Перегрузка
      print(E_DATA_PUMP, CENTER, 24); //преобразователя!
      _clear_buff(); //очистка буфера
      _add_text(E_DATA_SPEED); //СКР:
      _add_num_int(data); //скорость
      _print_text(CENTER, 32); //вывод текста
      break;
#if !PUMP_FEEDBACK
    case 3:
      print(E_DATA_SHOT_CIRCUIT, CENTER, 16); //Короткое зам.
      print(E_DATA_PUMP, CENTER, 24); //преобразователя!
      _clear_buff(); //очистка буфера
      _add_text(E_DATA_HV); //НАП:
      _add_num_int(_convert_vcc_hv(data)); //напряжение
      _print_text(CENTER, 32); //вывод текста
      break;

    case 4:
      print(E_DATA_LOW, CENTER, 16); //Низкое
      print(E_DATA_VOLTAGE, CENTER, 24); //напряжение
      print(E_DATA_PUMP, CENTER, 32); //преобразователя!
      _clear_buff(); //очистка буфера
      _add_text(E_DATA_HV); //НАП:
      _add_num_int(_convert_vcc_hv(data)); //напряжение
      _print_text(CENTER, 40); //вывод текста
      break;
#endif
    case 5:
      print(E_DATA_NO_ACCOUNT, CENTER, 24); //Нет счета!
      break;

    case 6:
      print(E_DATA_SHOT_CIRCUIT, CENTER, 16); //Короткое зам.
      print(E_DATA_OFF_SCALE, CENTER, 24); //или зашкал!
      print(E_DATA_DETECTOR, CENTER, 32); //детектора!
      break;
  }
}
//---------------------------------Сообщение об ошибке---------------------------------------
void _error_messege(void) //сообщение об ошибке
{
#if LOGBOOK_RETURN
  if (error_switch == 2 && !alarm_switch) { //если время вышло, выводим ошибку
#else
  if (error_switch && !alarm_switch) { //если время вышло, выводим ошибку
#endif
    btn_check = 0; //запрещем проверку кнопок

    _disable_sleep(); //просыпаемся если спали

#if LOGBOOK_RETURN
    _logbook_data_read(3); //чтение журнала
    _error_messege_show(_data_read_byte(0), _data_read_dword(0));
#elif !PUMP_FEEDBACK
    _error_messege_show(error_switch, (error_switch == 2) ? speed_hv : hv_adc);
#else
    _error_messege_show(error_switch, speed_hv);
#endif

    melodyPlay(SOUND_ERROR, REPLAY_ONCE); //звук ошибки

    for (timer_millis = ERROR_MASSEGE_TIME; timer_millis;) { //ждем
      if (_data_update() && buttonState()) { //обработка данных
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
  EEPROM_ClearBlock(EEPROM_BLOCK_STATISTIC, EEPROM_SIZE_STATISTIC); //стирание блока заглавлений времени в EEPROM
}
//---------------------------------------Чтение статистики--------------------------------------------------
void statistic_read(void) //чтение статистики
{
  uint32_t maxData = 0; //максимальное значение ячейки
  uint32_t tempData = 0; //временный буфер данных
  for (uint8_t c = 0; c < (EEPROM_SIZE_STATISTIC / 4); c++) {
    uint16_t search_cell = EEPROM_BLOCK_STATISTIC + ((uint16_t)c * 4); //находим запрашиваемую позицию
    EEPROM_ReadBlock((uint16_t)&tempData, search_cell, sizeof(tempData));
    if (maxData < tempData) { //если буфер меньше ячейки
      maxData = tempData; //записываем в буфер значение ячейки
      cur_dose_cell = c; //устанавливаем последнюю ячейку
    }
    else break; //завершаем поиск
  }
  if (maxData) { //если в буфере есть информация
    uint16_t time_cell = EEPROM_BLOCK_STATISTIC + ((uint16_t)cur_dose_cell * 4); //находим запрашиваемую позицию
    EEPROM_ReadBlock((uint16_t)&tempData, time_cell, sizeof(tempData));
    time_save = tempData; //считываем время
    uint16_t dose_cell = (EEPROM_BLOCK_STATISTIC + EEPROM_SIZE_STATISTIC) + ((uint16_t)cur_dose_cell * 4); //находим запрашиваемую позицию
    EEPROM_ReadBlock((uint16_t)&tempData, dose_cell, sizeof(tempData));
    rad_dose_save = tempData; //считываем дозу
    if (++cur_dose_cell > ((EEPROM_SIZE_STATISTIC / 4) - 1)) cur_dose_cell = 0; //меняем ячейку
  }
}
//----------------------------------Обновление статистики------------------------------------------
void statistic_update(void) //обновление статистики
{
  time_save += time_sec - time_save_old; //добавляем время
  time_save_old = time_sec; //сбрасывае счетчик времени
  rad_dose_save += rad_dose - rad_dose_old; //добавляем дозу
  rad_dose_old = rad_dose; //сбрасывае счетчик дозы

  uint16_t time_cell = EEPROM_BLOCK_STATISTIC + ((uint16_t)cur_dose_cell * 4); //находим запрашиваемую позицию
  EEPROM_UpdateBlock((uint16_t)&time_save, time_cell, sizeof(time_save)); //записываем время
  uint16_t dose_cell = (EEPROM_BLOCK_STATISTIC + EEPROM_SIZE_STATISTIC) + ((uint16_t)cur_dose_cell * 4); //находим запрашиваемую позицию
  EEPROM_UpdateBlock((uint16_t)&rad_dose_save, dose_cell, sizeof(rad_dose_save)); //записываем дозу
  if (++cur_dose_cell > ((EEPROM_SIZE_STATISTIC / 4) - 1)) cur_dose_cell = 0; //меняем ячейку
}
//----------------------------------Сброс текущей дозы----------------------------------------------
void data_reset(uint8_t mode) //сброс текущей дозы
{
  sleep_disable = 1; //запрещаем сон
  sleep_manual = 0; //отключили ручную блокировку сна
  power_manager = 0; //сбрасываем менеджер питания

  clrScr(); //очистка экрана

  switch (mode) {
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


  if (dialogSwitch(TIME_OUT_DATA)) { //подтверждение
    clrScr(); //очистка экрана

    switch (mode) {
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

        if (bookSettings.logbook_alarm == 2) bookSettings.logbook_alarm = 1; //сброс флага тревоги
        if (bookSettings.logbook_warn == 2) bookSettings.logbook_warn = 1; //сброс флага опасности
        if (bookSettings.logbook_measur == 2) bookSettings.logbook_measur = 1; //сброс флага замеров

        print(R_SUCC_LOGBOOK, CENTER, 16); //Журнал
        print(R_SUCC_CLEAR, CENTER, 24); //очищен!
        break;
    }
    _wait(MASSEGE_TIME); //ждем
  }
}
//---------------------------------------Сохранить настройки--------------------------------------------
void settings_save(uint8_t mode) //сохранить настройки
{
  switch (mode) {
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

  if (!dialogSwitch(TIME_OUT_DATA)) { //отказ
    switch (mode) {
      case 0: EEPROM_ReadBlock((uint16_t)&mainSettings, EEPROM_BLOCK_SETTINGS_MAIN, sizeof(mainSettings)); _set_contrast_lcd(mainSettings.contrast); break; //считываем настройки из памяти
#if DEBUG_RETURN || PUMP_READ_MEM
      case 1: EEPROM_ReadBlock((uint16_t)&pumpSettings, EEPROM_BLOCK_SETTINGS_PUMP, sizeof(pumpSettings)); break; //считываем настройки из памяти
#endif
#if LOGBOOK_RETURN
      case 2: EEPROM_ReadBlock((uint16_t)&bookSettings, EEPROM_BLOCK_SETTINGS_BOOK, sizeof(bookSettings)); break; //считываем настройки из памяти
#endif
    }
  }
  else { //подтверждение
    clrScr(); //очистка экрана
    print(W_SETTINGS_SUCC, CENTER, 16); //Настройки
    print(W_SAVE_SUCC, CENTER, 24); //Сохранены!

    switch (mode) {
      case 0: updateData((uint8_t*)&mainSettings, sizeof(mainSettings), EEPROM_BLOCK_SETTINGS_MAIN, EEPROM_BLOCK_CRC_MAIN); _BUZZ_VOL_SET(mainSettings.volume); break; //обновляем настройки
#if DEBUG_RETURN
      case 1: updateData((uint8_t*)&pumpSettings, sizeof(pumpSettings), EEPROM_BLOCK_SETTINGS_PUMP, EEPROM_BLOCK_CRC_PUMP); _init_battery(); break; //обновляем настройки
#endif
#if LOGBOOK_RETURN
      case 2: updateData((uint8_t*)&bookSettings, sizeof(bookSettings), EEPROM_BLOCK_SETTINGS_BOOK, EEPROM_BLOCK_CRC_BOOK); break; //обновляем настройки
#endif
    }
    _wait(MASSEGE_TIME); //ждем
  }
}
//----------------------------------Главные экраны------------------------------------------------------
uint8_t main_screen(void)
{
  sleep_disable = 0; //отключили запрет сон
  sleep_manual = 0; //отключили ручную блокировку сна

  _check_alarm_level(); //проверка значений уровня тревоги

  while (1) {
    if (_data_update()) { //обработка данных
      _error_messege(); //обработка сообщений ошибок
      _alarm_warning(); //обработка сообщений тревоги
      if (_bat_massege()) return POWER_DOWN_PROGRAM; //обработка сообщения разряженой батареи

      switch (buttonState()) {
#if BUTTON_MODE
        case UP_KEY_PRESS: //вкл/выкл посветки
#else
        case DOWN_KEY_HOLD: //вкл/выкл посветки
#endif
          if (skip_warn_messege()) _fast_light(); //быстрое включение посветки
          break;

#if BUTTON_MODE
        case DOWN_KEY_HOLD: //сброс
#else
        case DOWN_KEY_PRESS: //сброс
#endif
          if (skip_warn_messege()) { //если нет предупреждения
            switch (scr_mode) { //основные экраны
              case 0: //сбрасываем фон
                accur_percent = 99; //сбрасываем статистическую точность
                back_time_now = geiger_time_now = 0; //сбрасываем счетчик накопления импульсов в буфере
                mid_time_now = 0; //сбрасываем рассчет среднего
                rad_back = 0; //сбрасываем фон

                switch (back_mode) {
                  case 0: for (uint8_t i = 0; i < 60; i++) rad_buff[i] = 0; break; //очищаем буфер фона
                  case 1: for (uint8_t i = 0; i < 60; i++) rad_mid_buff[i] = 0; break; //очищаем буфер усреденения
                  case 2: rad_max = 0; break; //сбрасываем максимальное значение фона
                }
                break;

              case 1: data_reset(dose_mode); return MAIN_PROGRAM; //сбрасываем дозу и время
            }
          }
          break;

#if BUTTON_MODE
        case SEL_KEY_PRESS: //доп.действие
#else
        case UP_KEY_PRESS: //доп.действие
#endif
          if (skip_warn_messege()) { //если нет предупреждения
            switch (scr_mode) { //основные экраны
              case 0: if (back_mode < 2) back_mode++; else back_mode = 0; break; //переключаем экраны фона
              case 1: dose_mode = !dose_mode; break; //переключаем экраны дозы
            }
          }
          break;

        case UP_KEY_HOLD: //вкл/выкл фонарика
          if (skip_warn_messege()) FLASH_SWITCH; //быстрое включение фонарика
          break;

#if BUTTON_MODE
        case DOWN_KEY_PRESS: //выбор режима
#else
        case SEL_KEY_PRESS: //выбор режима
#endif
          if (skip_warn_messege()) scr_mode = !scr_mode; break; //переключение фон/доза
          break;

        case SEL_KEY_HOLD: //настройки
          if (skip_warn_messege()) return MENU_PROGRAM; //если нет тревоги
          break;
      }

      if (_check_screen()) { //обновление дисплея
        clrScr(); //очистка экрана

        if (!alarm_messege()) { //если нет тревоги
          if (!scr_mode) { //режим текущего фона
            _print_task_bar(MAIN_SCREEN_BACK); //Фон
            _alarm_show(alarm_back_wait + warn_back_wait, mainSettings.alarm_back); //устанавлваем состояние тревоги
          }
          else { //режим накопленной дозы
            _print_task_bar(MAIN_SCREEN_DOSE); //Доза
            _alarm_show(0, mainSettings.alarm_dose); //устанавлваем состояние тревоги
          }

          drawBitmap(55, 0, font_alarm_img, 5, 8); //устанавлваем фон тревоги
          drawBitmap(43, 0, font_sound_img, 4, 8); //устанавлваем фон звуков
          if ((mainSettings.buzz_switch & 0x7F) == 1) drawBitmap(47, 0, buzz_alt_on_img, 7, 8); //если щелчки включены полностью
          else if ((mainSettings.buzz_switch & 0x7F) == 2) drawBitmap(47, 0, buzz_alt_img, 7, 8); //иначе если щелчки включены только при фон1
          else drawBitmap(47, 0, buzz_alt_off_img, 7, 8); //иначе щелчки выключены

#if LOGBOOK_RETURN
          if (error_switch) {
            if (screen_anim) drawBitmap(27, 0, error_ico_img, 14, 8); //ERR
          }
          else {
#endif
            if (mainSettings.sleep_switch && sleep_manual) {
              if (screen_anim || (sleep_manual & 0xFE)) drawBitmap(32, 0, sleep_ico_img, 8, 8); //sleep
            }
#if LOGBOOK_RETURN
            else if (bookSettings.logbook_alarm == 2 || bookSettings.logbook_warn == 2 || bookSettings.logbook_measur == 2) {
              if (screen_anim) drawBitmap(31, 0, logbook_ico_img, 9, 8); //logbook
            }
            else if (bookSettings.logbook_alarm == 1 || bookSettings.logbook_warn == 1 || bookSettings.logbook_measur == 1) drawBitmap(31, 0, logbook_ico_img, 9, 8); //logbook
          }
#endif

          //===========================================================//
          if (!scr_mode) { //режим измерения текущего фона
            if (alarm_switch == 1) alarm_massage_show(0, 24); //предупреждение
            else {
#if BUFF_SCALE_RETURN || COEF_DEBUG
              drawLine(3, 1, map(geiger_time_now, 0, 60, 5, 82), 0x06); //шкала точности
              drawLine(3, 1, map(mid_time_now, 0, mainSettings.averag_time, 5, 82), 0x30); //шкала усреднения
#else
              _print_back_bar(rad_back);
#endif
            }

            if (back_mode != 2) {
              drawBitmap(0, 32, scan_left_img, 4, 16); //рисуем левую шкалу
#if TYPE_GRAF_MOVE
              for (uint8_t x = 0; x < 60; x++) { //слева-направо
#else
              for (uint8_t x = 60; x;) { //справа-налево
                x--;
#endif
                drawGraf(map((back_mode) ? rad_mid_buff[x] : rad_buff[x], 0, (back_mode) ? graf_mid_max : graf_max, 1, 15), x, 2); //инициализируем график
              }
              drawDashLine(4, 6, 15, 2, 0x01);
              drawLine(4, 65, 83, 0xFF);
              drawLine(5, 65, 83, 0xFF);
              invertText(true);
              printNumI(60, 68, 32); //строка 1
              print((back_mode) ? MAIN_SCREEN_GRAF_MIN : MAIN_SCREEN_GRAF_SEC, 65, 40); //строка 2
              invertText(false);
            }
            else { //максимальный и средний фон
#if COEF_DEBUG //отладка коэффициента
              print(D_COEF_NOW, 0, 32); //строка 1 текущ:
              printNumI(debug_now, RIGHT, 32, 5); //строка 1

              print(D_COEF_LIMIT, 0, 40); //строка 2
              printNumF(debug_coef, 1, RIGHT, 40, 5); //строка 2
#else
              print(MAIN_SCREEN_BACK_MAX, 0, 32); //строка 1 макс:
              _print_rads_unit(0, rad_max, 0, 4, RIGHT, 32, 0, RIGHT, 32, !rad_max); //строка 1 максимальный фон

              print(MAIN_SCREEN_CURRENT_DOSE, 0, 40); //строка 2 доза:
              _print_rads_unit(0, rad_dose, 1, 5, RIGHT, 40, 1, RIGHT, 40); //строка 2 текущая доза
#endif
            }

            _print_accur_percent(accur_percent); //отрисовка точности
            _print_rads_unit(1, rad_back, 0, 4, 1, 8, 0, 54, 16); //строка 1 основной фон

          }
          else { //режим накопленной дозы
            if (!dose_mode) { //текущая доза
              setFont(TinyNumbersDown); //установка шрифта
              printNumI(time_sec / 60 / 60 / 24, 24, 23, 5, 44); //дней
              drawBitmap(44, 24, day_img, 8, 8); //дн
              setFont(TinyNumbersDown); //установка шрифта
              printNumI((time_sec / 60 / 60) % 24, 56, 23, 2, '0'); //часов
              drawBitmap(63, 24, colon_img, 3, 8); //:
              setFont(TinyNumbersDown); //установка шрифта
              printNumI((time_sec / 60) % 60, 66, 23, 2, '0'); //минут
              drawBitmap(73, 24, colon_img, 3, 8); //:
              setFont(TinyNumbersDown); //установка шрифта
              printNumI(time_sec % 60, 76, 23, 2, '0'); //секунд

              if (alarm_switch == 2) alarm_massage_show(0, 32); //предупреждение
              else _print_time_bar(stat_upd_tmr); //шкала времени до сохранения дозы

              _print_rads_unit(1, rad_dose, 1, 5, 1, 8, 1, 66, 16); //строка 1 текущая доза
              print(MAIN_SCREEN_CURRENT_DOSE_ALL, 0, 40); //строка 2 всего
              _print_rads_unit(0, rad_dose_save, 1, 5, RIGHT, 40, 1, RIGHT, 40); //строка 2 сохранённая доза
            }
            else { //общая накопленная доза и время
              _clear_buff(); //очистка буфера
              _add_num_int(time_save / 60 / 60 / 24, 2, '0');
              _add_text(MAIN_SCREEN_DOSE_DAYS);
              _add_num_int((time_save / 60 / 60) % 24, 2, '0');
              _add_text(MAIN_SCREEN_DOSE_HOURSE);
              _add_num_int((time_save / 60) % 60, 2, '0');
              _add_text(MAIN_SCREEN_DOSE_MINS);
              _print_text(CENTER, 40); //вывод текста

              print(MAIN_SCREEN_DOSE_ACCUM, CENTER, 24); //накоплено
              print(MAIN_SCREEN_DOSE_JUST_OVER, 16, 31); //всего за:

              _print_rads_unit(1, rad_dose_save, 1, 5, 1, 8, 1, 66, 16); //строка 1 сохранённая доза
            }
          }
        }
      }
    }
  }
  return INIT_PROGRAM;
}
