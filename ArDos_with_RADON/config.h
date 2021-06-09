//Язык системы//
#define RUSSIAN //для смены языка необходимо добавить метаданные в файл "languages", по умолчанию доступны - RUSSIAN(русский) и ENGLISH(английский)

//Передача данных//
#define USE_UART 0 //использовать UART для передачи данных(0 - выключить вывод данных | 1 - включить вывод данных)
#define UART_BAUND 57600 //скорость UART для передачи данных(9600 | 19200 | 38400 | 57600 | 74880 | 115200)
#define UART_SEND_BACK 1 //отправлять фон в мкр/ч
#define UART_SEND_DOSE 0 //отправлять дозу в мкр
#define UART_SEND_IMP 0 //отправлять количество имп накопленных за секунду


//Настройки преобразователя и отладки по умолчанию//
#define PUMP_READ_MEM          0 //считывать предыдущие настройки преобразователя из памяти при отключеной отладке (1 - настройки считываются из памяти, указанные при прошивке игнорируются | 0 - настройки из памяти игнорируются, считываются только указанные при прошивке)

#define DEFAULT_ADC_VALUE      185 //значение АЦП при котором 400В с учетом вашего делителя напряжения (0..255). Для значений делителя с сайта srukami 163. alexadresat 185.
#define DEFAULT_DIV_FACTOR     500 //коеффициент делителя напряжения, зависит от вашего делителя (10..1500). Для значений делителя с сайта srukami k_delitel 576. alexadresat 500.
#define DEFAULT_PULS           2 //тонкая настройка длинны импульса высоковольтного трансформатора (1..30)
#define DEFAULT_REFERENCE      1.10 //опорное напряжение (0.5..1.5)(v)
#define DEFAULT_GEIGER_TIME    36.0 //время измерения, для СБМ-20 36 секунд (2.0..99.9, 100..150)(s)


//Настройки системы по умолчанию//
#define DEFAULT_CONTRAST       70 //контрастность дисплея (0..127)
#define DEFAULT_VOLUME         10 //громкость всех звуков (1..10)
#define DEFAULT_TIME_BRIGHT    5 //время до отключения подсветки (5..250)(s)
#define DEFAULT_TIME_SLEEP     10 //время до ухода в сон(должно быть больше чем время подсветки) (10..250)(s)
#define DEFAULT_SLEEP_MODE     0 //режим сна (0 - сон выкл | 1 - только подсветка | 2 - сон вкл)
#define DEFAULT_RAD_FLASH      1 //индикация попадания частиц (0 - выкл | 1 - вкл)
#define DEFAULT_BUZ_SWITCH     0 //тип треска пищалкой (0 - выкл | 1 - вкл | 2 - фон1)
#define DEFAULT_KNOCK_DISABLE  0 //запрет треска кнопками (1 - вкл | 0 - выкл)
#define DEFAULT_MEASUR_POS     0 //указатель на время разностного замера в массиве (0..9)
#define DEFAULT_SEARCH_POS     8 //указатель на время время обновления графика в массиве (0..9)
#define DEFAULT_SIGMA_POS      1 //указатель сигмы (0 - 1 сигма | 1 - 2 сигмы | 2 - 3 сигмы)
#define DEFAULT_RAD_MODE       0 //единицы измерения дозы/фона (0 - мкР | 1 - мкЗв)
#define DEFAULT_ALARM_BACK     0 //режим тревоги фона (0 - выкл | 1 - звук | 2 - вибрация | 3 - звук+вибрация)
#define DEFAULT_LEVEL_BACK_1   30 //уровень тревоги 1 фона (30..300)
#define DEFAULT_LEVEL_BACK_2   300 //уровень тревоги 2 фона (300..65500)
#define DEFAULT_ALARM_DOSE     0 //режим тревоги дозы (0 - выкл | 1 - звук | 2 - вибрация | 3 - звук+вибрация)
#define DEFAULT_LEVEL_DOSE_1   10 //уровень тревоги 1 дозы (10..300)
#define DEFAULT_LEVEL_DOSE_2   300 //уровень тревоги 2 дозы (300..65500)

#define DEFAULT_LOGBOOK_ALARM  1 //разрешить запись тревоги в журнал (0 - выкл | 1 - вкл)
#define DEFAULT_LOGBOOK_WARN   1 //разрешить запись предупреждений в журнал (0 - выкл | 1 - вкл)
#define DEFAULT_LOGBOOK_MEASUR 1 //разрешить запись замеров бета в журнал (0 - выкл | 1 - вкл)


//Настройки комплектации//
#define UNO_DIP            0 //если используется ArduinoUNO или плата на голой атмеге328 в корпусе DIP - установите 1. Это переключит чтение напряжения с делителя с ноги A6 на ногу A5.
#define LIGHT_INV          0 //если используется синий дисплей - установите 1. Это инвертирует управление подсветкой дисплея.
#define ROTATE_DISP        0 //если необходимо перевернуть дисплей на 180° - установите 1. Это перевернет отображение информации на дисплее.


//Настройки алгоритмов//
#define GEIGER_DEAD_TIME   1 //учет мертвого времени счетчика (1 - мертвое время счетчика учитывается | 0 - мертвое время счетчика не учитывается)
#define GEIGER_OWN_BACK    0 //учет собственного фона счетчика (1 - собственный фон счетчика учитывается | 0 - собственный фон счетчика не учитывается)
#define APPROX_BACK_SCORE  1 //аппроксимированный счет фона (1 - аппроксимированный счет | 0 - линейный счет фона)

#define DEBUG_RETURN       1 //вернуть отладку преобразователя (1 - отладка доступна из интерфеса | 0 - отладка не доступна из интерфейса)
#define LOGBOOK_RETURN     1 //вернуть журнал всех данных (1 - доступен полный журнал(тревога/предупреждения/замеры/ошибки) | 0 - доступен только журнал замеров)
#define PWR_ON_RETURN      1 //вернуть включение питания по удержанию клавиши (1 - включение по удержанию разрешено | 0 - включение по удержанию запрещено)
#define BACK_SCALE_RETURN  0 //вернуть шкалу предела фона (1 - шкала предела фона | 0 - шкалы заполнености буфера)

#define TYPE_GRAF_MOVE      1 //выбор направления движения графика (0 - справа<-налево | 1 - слева->направо)
#define TYPE_ALARM_IND      1 //выбор типа индикации при тревоге (0 - только вибрация | 1 - вибрация и мигание фонариком | 2 - вибрация и мигание подсветкой)
#define TYPE_MEASUR_LOGBOOK 0 //тип данных записываемых в журнал замеров бета (0 - мкР/ч | 1 - ч/см2)
#define ALARM_AUTO_DISABLE  1 //автоматическо отключение тревоги (0 - отключать только по нажатию клавиши | 1 - отключать по нажатию клавиши или спаду фона)


//Конфигурация прошивки//
#define START_TIME          1000 //длительность ожидания перед стартом прошивки(50..10000)(ms)
#define FONT_TIME           2000 //длительность ожидания заставки при первом включении(50..10000)(ms)
#define POWER_TIME          2000 //длительность ожидания отображениия разряженой акб при включении(50..10000)(ms)
#define POWER_ON_TIME       2000 //длительность удержания кнопки включения(50..10000)(ms)
#define MASSEGE_TIME        1000 //длительность отображения окон(50..10000)(ms)
#define START_PUMP_TIME     3000 //длительность до автоматического выхода из первой накачки преобразователя(50..10000)(ms)

#define ERROR_MASSEGE_TIME  3000 //длительность отображения окон ошибок(1000..10000)(ms)
#define ERROR_LENGTHY_TIME  10   //длительность до отображения следующей ошибки(10..100)(s)

#define ALARM_AUTO_GIST     3  //гистерезис(разница) автоматического отключения тревоги(1..99)(%)

#define TIME_OUT_SETTINGS   15 //тайм-аут автоматического выхода из настроек(0 - выкл)(5..250)(s)
#define TIME_OUT_MENU       15 //тайм-аут автоматического выхода из меню(0 - выкл)(5..250)(s)
#define TIME_OUT_DATA       15 //тайм-аут автоматического выхода из сброса дозы(0 - выкл)(5..250)(s)
#define TIME_OUT_PARAM      30 //тайм-аут автоматического выхода из параметров(0 - выкл)(5..250)(s)
#define TIME_OUT_DEBUG      30 //тайм-аут автоматического выхода из отладки(0 - выкл)(5..250)(s)
#define TIME_OUT_LOGBOOK    30 //тайм-аут автоматического выхода из журнала(0 - выкл)(5..250)(s)

#define STAT_UPD_TIME       60  //интервал записи статистики в память(10..3600)(s)

#define IMP_ERROR_TIME      60  //время после которого можно ститать что импульсы от счетчика отсутствуют(10..255)(s)
#define HV_SPEED_ERROR      500 //скорость накачки, при которой можно считать что преоразователь перегружен(100..1000)
#define HV_ADC_ERROR        10  //значение АЦП, при которой можно считать что преоразователь в коротком замыкании(0..255)
#define HV_ADC_MIN          5   //если значение АЦП меньше на указанное количество едениц, то можно считать что напряжение преобразователя занижено(0..255)

#define UPD_BAT_TIME        5  //частота обновлния информации о заряде батареи(1..255)(s)
#define LOW_BAT_TIME        30 //частота появления сообщения о разряде батареи(1..255)(s)
#define LOW_BAT_POWER       95 //при каком значение АЦП считать акб разряженной и не давать у-ву включиться(0..255)
#define LOW_BAT_STAT        90 //при каком значение АЦП считать акб разряженной(0..255)
#define MIN_BAT             95 //значение АЦП при разряженной батарее(0..255)
#define MAX_BAT             70 //значение АЦП при заряженной батарее(0..255)

#define SEARCH_IND_MAX      200  //максимум предела шкалы частиц/сек. режима "поиск"(48..10000)(имп/с)
#define SEARCH_BUF_SCORE    4    //количество ячеек буфера графика режима "поиск" из которых рассчитываются единицы измерения(1..76)

#define GRAF_COEF_MAX       1.50 //коэффициент маштабирования графиков(1.00..2.00)

#define TYPE_CHAR_FILL      43   //выбор симола заполнителя на главных экранах(48 - "0" | 47 - "/" | 46 - "." | 45 - "-" | 44 - "_" | 43 - " ")


//Технические настройки
#define MAX_GEIGER_TIME  150    //максимальное время счета (10..255)(s)
#define MIN_GEIGER_TIME  2      //минимальное время счета (2..10)(s)

#define OWN_BACK         0.2    //собственный фон счетчика(0.1..1)(imp/s)
#define DEAD_TIME        0.0002 //мертвое время счетчика, 200мкрС для сбм-20(0.0001..0.0002)(us/1000000)
#define GEIGER_AREA      8      //площадь датчика для вычичления ч-ц/см2*мин(1..50)(см2)
#define COUNT_RATE       100    //минимальная скорость счета для начала корректировки мертвого времени(50..500)(imp/s)

#define BUFF_LENGTHY     60  //длинна буфера секундных замеров(38..255)
#define MID_BUFF_LENGTHY 10  //длинна буфера усреднения замеров(1..20)
#define CYCLE_OVERFLOW   10  //количество циклов подкачки ВВ до аварийного выхода(10..255)

#define BTN_GIST_TICK    2   //количество циклов для защиты от дребезга(0..255)(1 цикл -> +-17.5мс)
#define BTN_HOLD_TICK    30  //количество циклов после которого считается что кнопка зажата(0..255)(1 цикл -> +-17.5мс)

#define DEF_WDT_PERIOD   1750 //период wdt по умолчанию(1600..1800)(us/10)
#define MAX_WDT_PERIOD   1850 //максимальный wdt период(1750..1850)(us/10)
#define MIN_WDT_PERIOD   1650 //минимальный wdt период(1650..1750)(us/10)

#define IMP_PWR_MANAGER  100 //порог отключения режима энергосбережения для более корректной работы устройства(100..1000)(imp/s)
#define IMP_PWR_DOWN     5   //порог отключения режима глубокого энергосбережения для более корректной работы устройства(0..100)(imp/s)
#define IMP_PWR_GIST     30  //гистерезис(разница) включения энергосбережения(1..99)(%)

#define RAD_SLEEP_OUT    100 //порог выхода из сна при высоких уровнях фона(100..10000)(uRh)
#define RAD_ACCUR_WARN   70  //порог начала работа тревоги фона в зависимости от набранной точности(1..99)(%)
#define RAD_ACCUR_START  70  //порог начала обработки данных в зависимости от набранной точности(1..99)(%)

#define RAD_FLASH_TIME   20  //время индикации поподания частиц(1..255)(ms)

#define SOUND_PRESCALER  256 //пределитель частоты для пищалки


//Настройки пресетов//
const uint8_t diff_measuring[10] PROGMEM = {1, 2, 3, 5, 7, 10, 20, 30, 40, 60}; //массив времени разностных замеров(1..99)(m), не более 10 пресетов!
const uint16_t search_time[8] PROGMEM = {140, 280, 420, 560, 700, 840, 980, 1120}; //время обновления данных в режиме поиска(140..1120)(ms), не более 8 пресетов!


//Настройки коэффициентов
#define COEF_DEBUG       0 //выводить отладку коэффициента рядом с надписью "ФОН"(0 - не выводить | 1 - выводить)
#define MASS_TIME        7 //всего данных в массиве коэффициентов времени
#define MASS_BACK        7 //всего данных в массиве коэффициентов фона

const uint8_t time_mass[MASS_TIME][2] PROGMEM = { //массив выборки элементов из основного буффера для сравнения(1..60)
  {2, 6},  //0-й порог
  {3, 9},  //1-й порог
  {4, 12}, //2-й порог
  {5, 15}, //3-й порог
  {6, 18}, //4-й порог
  {7, 21}, //5-й порог
  {8, 24}  //6-й порог
};

const float coef_time_mass[MASS_TIME] PROGMEM = { //массив коэффициентов сравнения для выявления скачков/спадов(1.00..10.00)
  5.00, //0-й порог
  4.00, //1-й порог
  3.00, //2-й порог
  2.50, //3-й порог
  2.00, //4-й порог
  1.70, //5-й порог
  1.50  //6-й порог
};

const uint16_t back_mass[MASS_BACK] PROGMEM = { //массив квантования коэффициентов поправки на текущий фон(0..65500)
  15,    //0-й порог
  30,    //1-й порог
  100,   //2-й порог
  1000,  //3-й порог
  10000, //4-й порог
  35200, //5-й порог
  65500  //6-й порог
};

const float coef_back_mass[MASS_BACK] PROGMEM = { //массив коэффициентов поправки на текущий фон(1.00..10.00)
  5.00, //0-й порог
  4.00, //1-й порог
  3.00, //2-й порог
  2.50, //3-й порог
  2.00, //4-й порог
  1.75, //5-й порог
  1.50  //6-й порог
};

//конфигурация счета фона
#define PATTERNS_APROX  6 //количество патернов счета фона

const uint16_t back_aprox[PATTERNS_APROX][3] PROGMEM = { //массив счета фона
  {200, 0, 0}, //паттерн 0 - порог имп/с | коррекция времени счета | коррекция / 10
  {400, 6, 120}, //паттерн 1 - порог имп/с | коррекция времени счета | коррекция / 10
  {800, 13, 380}, //паттерн 2 - порог имп/с | коррекция времени счета | коррекция / 10
  {1300, 24, 1300}, //паттерн 3 - порог имп/с | коррекция времени счета | коррекция / 10
  {1800, 36, 2860}, //паттерн 4 - порог имп/с | коррекция времени счета | коррекция / 10
  {22000, 62, 7450} //паттерн 5 - порог имп/с | коррекция времени счета | коррекция / 10
};

//конфигурация шкалы фона
#define PATTERNS_SCALE  3 //количество патернов шкалы фона

const uint16_t back_scale[PATTERNS_SCALE][2] PROGMEM = { //массив шкалы фона
  {1, 25}, //паттерн 0 - порог мкЗ/ч | максимум шкалы(1..80)
  {10, 40}, //паттерн 1 - порог мкЗ/ч | максимум шкалы(1..80)
  {1440, 80}, //паттерн 2 - порог мкЗ/ч | максимум шкалы(1..80)
};


//конфигурация переключателей едениц
#define PATTERNS_RH  3 //количество патернов мкР
#define PATTERNS_SVH  4 //количество патернов мкЗв

const uint32_t pattern_all[][4][4] PROGMEM = { //[][строки][столбцы]
  { //паттерн значений переключения единиц мкР
    {9999, 0, 1, 0}, //паттерн 0 - сравнитель | знаков полсе запятой | делитель | ед.измер
    {99999, 1, 1000, 1}, //паттерн 1 - сравнитель | знаков полсе запятой | делитель | ед.измер
    {9999999, 0, 1000, 1} //паттерн 2 - сравнитель | знаков полсе запятой | делитель | ед.измер
  },
  { //паттерн значений переключения единиц мкЗв
    {999, 2, 100, 0}, //паттерн 0 - сравнитель | знаков полсе запятой | делитель | ед.измер
    {9999, 1, 100, 0}, //паттерн 1 - сравнитель | знаков полсе запятой | делитель | ед.измер
    {999999, 2, 100000, 1}, //паттерн 2 - сравнитель | знаков полсе запятой | делитель | ед.измер
    {9999999, 1, 100000, 1} //паттерн 3 - сравнитель | знаков полсе запятой | делитель | ед.измер
  }
};


//Конфигурация звуков//
#define FREQ_BUZZ  250 //частота щелчков(10..10000)(Hz)
#define TIME_BUZZ  10 //длительность щелчков(10..500)(ms)

#define FREQ_BEEP  1000 //частота звука клавиш(10..10000)(Hz)
#define TIME_BEEP  30 //длительность звука клавиш(10..500)(ms)


//Конфигурация вибрации тревоги//
#define SAMPLS_VIBRO  6 //количество семплов в массиве вибрации тревоги(1..255)

const uint16_t alarm_vibro[SAMPLS_VIBRO][2] PROGMEM = { //массив семплов вибрации тревоги
  {1, 150}, //семпл 0 - (1 - вкл 0 - выкл) | длительность (50..1000)(ms)
  {0, 250}, //семпл 1 - (1 - вкл 0 - выкл) | длительность (50..1000)(ms)
  {1, 150}, //семпл 2 - (1 - вкл 0 - выкл) | длительность (50..1000)(ms)
  {0, 250}, //семпл 3 - (1 - вкл 0 - выкл) | длительность (50..1000)(ms)
  {1, 150}, //семпл 4 - (1 - вкл 0 - выкл) | длительность (50..1000)(ms)
  {0, 550}, //семпл 5 - (1 - вкл 0 - выкл) | длительность (50..1000)(ms)
};


//Конфигурация звука оповещения о готовности замера//
#define MEASUR_SOUND   1 //вкл/выкл звука готовности замера(1 - звук включен | 0 - звук выключен)
#define SAMPLS_MEASUR  3 //количество семплов в массиве мелодии замера(1..255)

const uint16_t measur_sound[SAMPLS_MEASUR][3] PROGMEM = { //массив семплов мелодии замера
  {1500, 100, 200}, //семпл 0 - частота(10..10000)(Hz) | длительность звука(50..500)(ms) | длительность паузы(50..1000)(ms)
  {1500, 100, 200}, //семпл 1 - частота(10..10000)(Hz) | длительность звука(50..500)(ms) | длительность паузы(50..1000)(ms)
  {1500, 100, 200}  //семпл 2 - частота(10..10000)(Hz) | длительность звука(50..500)(ms) | длительность паузы(50..1000)(ms)
};


//Конфигурация звука разряда акб//
#define BAT_LOW_SOUND   1 //звук разряда акб(1 - звук включен | 0 - звук выключен)
#define SAMPLS_BAT_LOW  3 //количество семплов в массиве мелодии замера(1..255)

const uint16_t bat_low_sound[SAMPLS_BAT_LOW][3] PROGMEM = { //массив семплов мелодии замера
  {1500, 200, 200}, //семпл 0 - частота(10..10000)(Hz) | длительность звука(50..500)(ms) | длительность паузы(50..1000)(ms)
  {1000, 200, 200}, //семпл 1 - частота(10..10000)(Hz) | длительность звука(50..500)(ms) | длительность паузы(50..1000)(ms)
  {500, 200, 200}  //семпл 2 - частота(10..10000)(Hz) | длительность звука(50..500)(ms) | длительность паузы(50..1000)(ms)
};


//Конфигурация звука ошибки//
#define SAMPLS_ERROR  2 //количество семплов в массиве мелодии замера(1..255)

const uint16_t error_sound[SAMPLS_ERROR][3] PROGMEM = { //массив семплов мелодии замера
  {1000, 200, 200}, //семпл 0 - частота(10..10000)(Hz) | длительность звука(50..500)(ms) | длительность паузы(50..1000)(ms)
  {1500, 200, 600}  //семпл 1 - частота(10..10000)(Hz) | длительность звука(50..500)(ms) | длительность паузы(50..1000)(ms)
};


//Конфигурация звука предупреждения//
#define SAMPLS_WARN  4 //количество семплов в массиве мелодии замера(1..255)

const uint16_t warn_sound[SAMPLS_WARN][3] PROGMEM = { //массив семплов мелодии замера
  {1500, 200, 200}, //семпл 0 - частота(10..10000)(Hz) | длительность звука(50..500)(ms) | длительность паузы(50..1000)(ms)
  {1000, 200, 200}, //семпл 1 - частота(10..10000)(Hz) | длительность звука(50..500)(ms) | длительность паузы(50..1000)(ms)
  {1500, 200, 200}, //семпл 2 - частота(10..10000)(Hz) | длительность звука(50..500)(ms) | длительность паузы(50..1000)(ms)
  {1000, 200, 1000} //семпл 3 - частота(10..10000)(Hz) | длительность звука(50..500)(ms) | длительность паузы(50..1000)(ms)
};


//Конфигурация звука тревоги//
#define SAMPLS_ALARM  9 //количество семплов в массиве мелодии замера(1..255)

const uint16_t alarm_sound[SAMPLS_ALARM][3] PROGMEM = { //массив семплов мелодии замера
  {550, 100, 150}, //семпл 0 - частота(10..10000)(Hz) | длительность звука(50..500)(ms) | длительность паузы(50..1000)(ms)
  {5500, 100, 150}, //семпл 1 - частота(10..10000)(Hz) | длительность звука(50..500)(ms) | длительность паузы(50..1000)(ms)
  {5500, 100, 150}, //семпл 2 - частота(10..10000)(Hz) | длительность звука(50..500)(ms) | длительность паузы(50..1000)(ms)
  {5500, 100, 150}, //семпл 3 - частота(10..10000)(Hz) | длительность звука(50..500)(ms) | длительность паузы(50..1000)(ms)
  {1500, 200, 250}, //семпл 4 - частота(10..10000)(Hz) | длительность звука(50..500)(ms) | длительность паузы(50..1000)(ms)
  {1500, 200, 250}, //семпл 5 - частота(10..10000)(Hz) | длительность звука(50..500)(ms) | длительность паузы(50..1000)(ms)
  {550, 100, 150}, //семпл 6 - частота(10..10000)(Hz) | длительность звука(50..500)(ms) | длительность паузы(50..1000)(ms)
  {550, 100, 150}, //семпл 7 - частота(10..10000)(Hz) | длительность звука(50..500)(ms) | длительность паузы(50..1000)(ms)
  {550, 100, 550}  //семпл 8 - частота(10..10000)(Hz) | длительность звука(50..500)(ms) | длительность паузы(50..1000)(ms)
};
