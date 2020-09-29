//Настройки преобразователя//
uint8_t ADC_value = 185; //значение АЦП при котором 400В с учетом вашего делителя напряжения (0..255). Для значений делителя с сайта srukami 163. alexadresat 185. 
uint16_t k_delitel = 500; //коефициент делителя напряжения, зависит от вашего делителя. Для значений делителя с сайта srukami k_delitel 576. alexadresat 500.
uint8_t puls = 2; //тонкая настройка длинны импульса высоковольтного транса

float opornoe = 1.10; //опорное напряжение

//Настройки времени//
uint8_t GEIGER_TIME = 36;  //время измерения, для СБМ-20 36 секунд (6..120)(s)
const uint8_t diff_measuring[10] {1, 2, 3, 5, 7, 10, 20, 30, 40, 60}; //массив времени разностных замеров(1..99)(m), не более 10 пресетов!
const uint8_t mid_rad_time[10] {1, 2, 3, 4, 5, 10, 15, 20, 25, 30}; //время усреднения показаний фона(1..99)(m), не более 10 пресетов!

//Настройки комплектации//
#define UNO_DIP      0 //если используется ArduinoUNO или плата на голой атмеге328 в корпусе DIP - установите 1. Это переключит чтение напряжения с делителя с ноги A6 на ногу A5.
#define LIGHT_INV    0 //если используется синий дисплей - установите 1. Это инвертирует управление подсветкой дисплея.
#define GEIGER_COUNT 1 //количество счетчиков подключенных параллельно. При использовании более одного счетчика, мертвое время не учитывается.

//Настройки алгоритмов//
#define MESSUR_OR_PWR     0 //выбор пункта быстрого меню(или выключение питания или разностный замер) (1 - выключение питания | 0 - разностный замер)
#define TYPE_FAST_MENU    1 //выбор типа выхода из быстрого меню (1 - выход автоматически или по зажатию клавиши "вверх" | 0 - выход только по зажатию клавиши "вверх")

#define SEARCH_RETURN     1 //вернуть режим поиска (1 - поиск доступен из интерфеса | 0 - поиск не доступен из интерфейса, график отображается в режиме "ФОН")
#define TYPE_SERCH_UNIT   1 //выбор типа отображения едениц на экране "ПОИСК" (1 - имп/с | 0 - общее кол-во частиц)
#define TYPE_GRAF_MOVE    1 //выбор направления движения графика (0 - справа<-налево | 1 - слева->направо)

#define DEBUG_RETURN     1 //вернуть отладку преобразователя (1 - отладка доступна из интерфеса | 0 - отладка не доступна из интерфейса)
#define PARAM_RETURN     1 //вернуть параметры устройства (1 - параметры доступны из интерфеса | 0 - параметры не доступны из интерфейса)
#define ERRORS_RETURN    1 //вернуть ошибки системы (1 - ошибки разрешены | 0 - ошибки запрещены)
#define PWR_ON_RETURN    1 //вернуть включение питания по удержанию клавиши (1 - включение по удержанию разрешено | 0 - включение по удержанию запрещено)

#define TYPE_ALARM_IND     0 //выбор типа индикации при тревоге (2 - вибрация и мигание подсветкой | 1 - вибрация и мигание фонариком | 0 - только вибрация)
#define ALARM_AUTO_DISABLE 1 //автоматическо отключение тревоги (0 - отключать только по нажатию клавиши | 1 - отключать по нажатию клавиши или спаду фона)
