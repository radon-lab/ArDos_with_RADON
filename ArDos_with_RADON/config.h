//Настройки преобразователя//
uint8_t ADC_value = 185; //значение АЦП при котором 400В с учетом вашего делителя напряжения (0..255). Для значений делителя с сайта srukami 163. alexadresat 185. 
uint16_t k_delitel = 500; //коефициент делителя напряжения, зависит от вашего делителя. Для значений делителя с сайта srukami k_delitel 576. alexadresat 500.
uint8_t puls = 2; //тонкая настройка длинны импульса высоковольтного транса

float opornoe = 1.10; //опорное напряжение


//Настройки пресетов//
const uint8_t diff_measuring[10] PROGMEM = {1, 2, 3, 5, 7, 10, 20, 30, 40, 60}; //массив времени разностных замеров(1..99)(m), не более 10 пресетов!
const uint8_t mid_rad_time[10] PROGMEM = {1, 2, 3, 4, 5, 10, 15, 20, 25, 30}; //время усреднения показаний фона(1..99)(m), не более 10 пресетов!
const uint16_t search_time[8] PROGMEM = {140, 280, 420, 560, 700, 840, 980, 1120}; //время обновления данных в режиме поиска(140..1120)(ms), не более 8 пресетов!


//Настройки комплектации//
#define UNO_DIP            0 //если используется ArduinoUNO или плата на голой атмеге328 в корпусе DIP - установите 1. Это переключит чтение напряжения с делителя с ноги A6 на ногу A5.
#define LIGHT_INV          0 //если используется синий дисплей - установите 1. Это инвертирует управление подсветкой дисплея.


//Настройки алгоритмов//
#define GEIGER_DEAD_TIME   1 //учет мертвого времени счетчика(только для одного счетчика) (1 - мертвое время счетчика учитывается | 0 - мертвое время счетчика не учитывается)
#define GEIGER_OWN_BACK    0 //учет собственного фона счетчика(только для одного счетчика) (1 - собственный фон счетчика учитывается | 0 - собственный фон счетчика не учитывается)

#define DEBUG_RETURN       1 //вернуть отладку преобразователя (1 - отладка доступна из интерфеса | 0 - отладка не доступна из интерфейса)
#define ERRORS_RETURN      1 //вернуть ошибки системы (1 - ошибки разрешены | 0 - ошибки запрещены)
#define PWR_ON_RETURN      1 //вернуть включение питания по удержанию клавиши (1 - включение по удержанию разрешено | 0 - включение по удержанию запрещено)

#define TYPE_GRAF_MOVE     1 //выбор направления движения графика (0 - справа<-налево | 1 - слева->направо)
#define TYPE_ALARM_IND     0 //выбор типа индикации при тревоге (2 - вибрация и мигание подсветкой | 1 - вибрация и мигание фонариком | 0 - только вибрация)
#define ALARM_AUTO_DISABLE 1 //автоматическо отключение тревоги (0 - отключать только по нажатию клавиши | 1 - отключать по нажатию клавиши или спаду фона)


//Конфигурация прошивки//
#define WDT_TIMEOUT         8000 //длительность тайм-аута колибровки WDT(50..10000)(ms)
#define START_TIME          1000 //длительность ожидания перед стартом прошивки(50..10000)(ms)
#define FONT_TIME           2000 //длительность ожидания заставки при первом включении(50..10000)(ms)
#define POWER_TIME          2000 //длительность ожидания отображениия разряженой акб при включении(50..10000)(ms)
#define MASSEGE_TIME        1000 //длительность отображения окон(50..10000)(ms)
#define START_PUMP_TIME     3000 //длительность до автоматического выхода из первой накачки преобразователя(50..10000)(ms)

#define ERROR_MASSEGE_TIME  3000 //длительность отображения окон ошибок(1000..10000)(ms)
#define ERROR_LENGTHY_TIME  10   //длительность до отображения следующей ошибки(10..100)(s)

#define ALARM_AUTO_GIST     3 //гистерезис(разница) автоматического отключения тревоги(1..99)(%)

#define TIME_OUT_SETTINGS   15 //тайм-аут автоматического выхода из настроек(0 - выкл)(5..250)(s)
#define TIME_OUT_MENU       15 //тайм-аут автоматического выхода из меню(0 - выкл)(5..250)(s)
#define TIME_OUT_DOSE       15 //тайм-аут автоматического выхода из сброса дозы(0 - выкл)(5..250)(s)
#define TIME_OUT_PARAM      30 //тайм-аут автоматического выхода из параметров(0 - выкл)(5..250)(s)
#define TIME_OUT_DEBUG      30 //тайм-аут автоматического выхода из отладки(0 - выкл)(5..250)(s)

#define STAT_UPD_TIME       60 //интервал записи статистики в память(60..3600)(s)

#define IMP_ERROR_TIME      60  //время после которого можно ститать что импульсы от счетчика отсутствуют(10..255)(s)
#define HV_SPEED_ERROR      500 //скорость накачки, при которой можно считать что преоразователь перегружен(100..1000)
#define HV_ADC_ERROR        10  //значение АЦП, при которой можно считать что преоразователь в коротком замыкании(0..255)

#define UPD_BAT_TIME        5  //частота обновлния информации о заряде батареи(1..255)(s)
#define LOW_BAT_TIME        30 //частота появления сообщения о разряде батареи(1..255)(s)
#define LOW_BAT_POWER       95 //при каком значение АЦП считать акб разряженной и не давать у-ву включиться(0..255)
#define LOW_BAT_STAT        90 //при каком значение АЦП считать акб разряженной(0..255)
#define MIN_BAT             95 //значение АЦП при разряженной батарее(0..255)
#define MAX_BAT             70 //значение АЦП при заряженной батарее(0..255)

#define SEARCH_IND_MAX        200  //максимум предела шкалы частиц/сек.(48..10000)(имп/с)
#define SEARCH_GEIGER_AREA    8    //площадь датчика для вычичления ч-ц/см2*мин(1..50)(см2)
#define SEARCH_BUF_SCORE      4    //количество ячеек буфера графика из которых рассчитываются единицы измерения(1..76)

#define GRAF_COEF_MAX         1.50 //коэффициент маштабирования графиков(1.00..2.00)

#define TYPE_CHAR_FILL      43 //выбор симола заполнителя на главных экранах(48 - "0" | 47 - "/" | 46 - "." | 45 - "-" | 44 - "_" | 43 - " ")

#define OWN_BACK            0.2    //собственный фон счетчика(0.1..1)(imp/s)
#define DEAD_TIME           0.0002 //мертвое время счетчика, 200мкрС для сбм-20(0.0001..0.0002)(us/1000000)
#define COUNT_RATE          100    //минимальная скорость счета для начала корректировки мертвого времени(50..500)(imp/s)


//Технические настройки
uint8_t GEIGER_TIME =    36; //время измерения, для СБМ-20 36 секунд (6..120)(s)
#define BUFF_LENGTHY     121 //длинна буфера секундных замеров(75..255)
#define TIME_CORRECT     0   //корректировка реального времени(-1750..1750)(us/10)
#define CYCLE_OVERFLOW   10  //количество циклов подкачки ВВ до аварийного выхода и выдачи ошибки(10..255)

#define BTN_GIST_TICK    2 //количество циклов для защиты от дребезга(0..255)
#define BTN_HOLD_TICK    30 //количество циклов после которого считается что кнопка зажата(0..255)

#define IMP_PWR_MANAGER  100 //порог отключения режима энергосбережения для более корректной работы устройства(100..1000)(imp/s)
#define IMP_PWR_DOWN     5   //порог отключения режима глубокого энергосбережения для более корректной работы устройства(0..100)(imp/s)
#define IMP_PWR_GIST     30  //гистерезис(разница) включения энергосбережения(1..99)(%)

#define RAD_SLEEP_OUT    100 //порог выхода из сна при высоких уровнях фона(100..10000)(uRh)
#define RAD_PRE_WARN     100 //порог начала работа тревоги фона при минимальном наборе массива данных(10..100)(uRh)

#define MIN_GEIGER_TIME  2 //минимальное время счета


#define COEF_DEBUG       0 //выводить отладку коэффициента рядом с надписью "ФОН"(0 - не выводить | 1 - выводить)
#define MASS_TIME        7 //всего данных в массиве коэффициентов времени
#define MASS_BACK        7 //всего данных в массиве коэффициентов фона

const uint8_t time_mass[MASS_TIME][2] PROGMEM = { //массив выборки элементов из основного буффера для сравнения(1..120)
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
#define FREQ_BUZZ  500 //частота щелчков(10..10000)(Hz)
#define TIME_BUZZ  10 //длительность щелчков(10..500)(ms)

#define FREQ_BEEP  2000 //частота звука клавиш(10..10000)(Hz)
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
  {3000, 100, 200}, //семпл 0 - частота(10..10000)(Hz) | длительность звука(50..500)(ms) | длительность паузы(50..1000)(ms)
  {3000, 100, 200}, //семпл 1 - частота(10..10000)(Hz) | длительность звука(50..500)(ms) | длительность паузы(50..1000)(ms)
  {3000, 100, 200}  //семпл 2 - частота(10..10000)(Hz) | длительность звука(50..500)(ms) | длительность паузы(50..1000)(ms)
};


//Конфигурация звука разряда акб//
#define BAT_LOW_SOUND   1 //звук разряда акб(1 - звук включен | 0 - звук выключен)
#define SAMPLS_BAT_LOW  3 //количество семплов в массиве мелодии замера(1..255)

const uint16_t bat_low_sound[SAMPLS_BAT_LOW][3] PROGMEM = { //массив семплов мелодии замера
  {3000, 200, 200}, //семпл 0 - частота(10..10000)(Hz) | длительность звука(50..500)(ms) | длительность паузы(50..1000)(ms)
  {2000, 200, 200}, //семпл 1 - частота(10..10000)(Hz) | длительность звука(50..500)(ms) | длительность паузы(50..1000)(ms)
  {1000, 200, 200}  //семпл 2 - частота(10..10000)(Hz) | длительность звука(50..500)(ms) | длительность паузы(50..1000)(ms)
};


//Конфигурация звука ошибки//
#define SAMPLS_ERROR  2 //количество семплов в массиве мелодии замера(1..255)

const uint16_t error_sound[SAMPLS_ERROR][3] PROGMEM = { //массив семплов мелодии замера
  {2000, 200, 200}, //семпл 0 - частота(10..10000)(Hz) | длительность звука(50..500)(ms) | длительность паузы(50..1000)(ms)
  {3000, 200, 600}  //семпл 1 - частота(10..10000)(Hz) | длительность звука(50..500)(ms) | длительность паузы(50..1000)(ms)
};


//Конфигурация звука предупреждения//
#define SAMPLS_WARN  4 //количество семплов в массиве мелодии замера(1..255)

const uint16_t warn_sound[SAMPLS_WARN][3] PROGMEM = { //массив семплов мелодии замера
  {3000, 200, 200}, //семпл 0 - частота(10..10000)(Hz) | длительность звука(50..500)(ms) | длительность паузы(50..1000)(ms)
  {2000, 200, 200}, //семпл 1 - частота(10..10000)(Hz) | длительность звука(50..500)(ms) | длительность паузы(50..1000)(ms)
  {3000, 200, 200}, //семпл 2 - частота(10..10000)(Hz) | длительность звука(50..500)(ms) | длительность паузы(50..1000)(ms)
  {2000, 200, 1000} //семпл 3 - частота(10..10000)(Hz) | длительность звука(50..500)(ms) | длительность паузы(50..1000)(ms)
};


//Конфигурация звука тревоги//
#define SAMPLS_ALARM  9 //количество семплов в массиве мелодии замера(1..255)

const uint16_t alarm_sound[SAMPLS_ALARM][3] PROGMEM = { //массив семплов мелодии замера
  {1100, 100, 150}, //семпл 0 - частота(10..10000)(Hz) | длительность звука(50..500)(ms) | длительность паузы(50..1000)(ms)
  {1100, 100, 150}, //семпл 1 - частота(10..10000)(Hz) | длительность звука(50..500)(ms) | длительность паузы(50..1000)(ms)
  {1100, 100, 150}, //семпл 2 - частота(10..10000)(Hz) | длительность звука(50..500)(ms) | длительность паузы(50..1000)(ms)
  {1100, 100, 150}, //семпл 3 - частота(10..10000)(Hz) | длительность звука(50..500)(ms) | длительность паузы(50..1000)(ms)
  {3000, 200, 250}, //семпл 4 - частота(10..10000)(Hz) | длительность звука(50..500)(ms) | длительность паузы(50..1000)(ms)
  {3000, 200, 250}, //семпл 5 - частота(10..10000)(Hz) | длительность звука(50..500)(ms) | длительность паузы(50..1000)(ms)
  {1100, 100, 150}, //семпл 6 - частота(10..10000)(Hz) | длительность звука(50..500)(ms) | длительность паузы(50..1000)(ms)
  {1100, 100, 150}, //семпл 7 - частота(10..10000)(Hz) | длительность звука(50..500)(ms) | длительность паузы(50..1000)(ms)
  {1100, 100, 550}  //семпл 8 - частота(10..10000)(Hz) | длительность звука(50..500)(ms) | длительность паузы(50..1000)(ms)
};
