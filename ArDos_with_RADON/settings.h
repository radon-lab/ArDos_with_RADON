//настройки основные
struct Settings_1 {
  uint8_t contrast = DEFAULT_CONTRAST; //контрастность дисплея
#if ROTATE_DISP_RETURN
  boolean rotation = DEFAULT_ROTATION; //флаг разворота дисплея
#endif
  uint8_t volume = DEFAULT_VOLUME; //громкость всех звуков
  uint8_t sensitiv = DEFAULT_SENSITIV; //чувствительность
  uint8_t alarm_back = DEFAULT_ALARM_BACK; //переключатель режимов тревоги фона
  uint8_t buzz_switch = DEFAULT_BUZ_SWITCH; //указатель на тип треска пищалкой
  boolean knock_disable = DEFAULT_KNOCK_DISABLE; //флаг запрет треска кнопками
  uint8_t measur_pos = DEFAULT_MEASUR_POS; //указатель на время разностного замера в массиве
  uint8_t alarm_dose = DEFAULT_ALARM_DOSE; //переключатель режимов тревоги дозы
  uint8_t sleep_switch = DEFAULT_SLEEP_MODE; //переключатель режимов сна
  uint8_t time_bright = DEFAULT_TIME_BRIGHT; //время до отключения подсветки
  uint8_t time_sleep = DEFAULT_TIME_SLEEP; //время до ухода в сон
  boolean rad_mode = DEFAULT_RAD_MODE; //единицы измерения дозы/фона(мкР/мкЗв)
  uint8_t rad_flash = DEFAULT_RAD_FLASH; //индикация попадания частиц
  uint8_t averag_time = DEFAULT_AVERAG; //длинна буфера усреднения замеров
  uint8_t sigma_lvl = DEFAULT_SIGMA_LVL; //уровень сигмы
  uint8_t search_score = DEFAULT_SEARCH_BUF; //количество ячеек буфера режима "поиск"
  uint8_t search_pos = DEFAULT_SEARCH_POS; //указатель на время время обновления графика в массиве
  uint16_t warn_level_back = DEFAULT_LEVEL_BACK_1; //уровень тревоги 1 фона
  uint16_t alarm_level_back = DEFAULT_LEVEL_BACK_2; //уровень тревоги 2 фона
  uint16_t warn_level_dose = DEFAULT_LEVEL_DOSE_1; //уровень тревоги 1 дозы
  uint16_t alarm_level_dose = DEFAULT_LEVEL_DOSE_2; //уровень тревоги 2 дозы
} mainSettings;

//настройки преобразователя
struct Settings_2 {
#if !PUMP_FEEDBACK
  uint8_t ADC_value = DEFAULT_ADC_VALUE; //значение АЦП при котором 400В
  uint16_t k_delitel = DEFAULT_DIV_FACTOR; //коефициент делителя напряжения
#endif
  uint16_t puls = DEFAULT_INDUCTION; //длинна импульса высоковольтного транса
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

const uint16_t pow_table[] PROGMEM = {1, 10, 100, 1000}; //таблица умножения чисел
const uint32_t div_table[] PROGMEM = {1000000000, 100000000, 10000000, 1000000, 100000, 10000, 1000, 100, 10, 1}; //таблица деления чисел
