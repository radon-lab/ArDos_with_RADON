#include <avr/pgmspace.h>

//Языки для локализации
const char VERSION[] PROGMEM = "4.2.1"; //версия программы

//---------------------------------------------//
#ifdef RUSSIAN //если выбран язык "русский"
//Основные
const char INTRO[] PROGMEM = "-=HFLJY=-"; //-=РАДОН=-

const char SETTINGS[] PROGMEM = "Yfcnhjqrb"; //Настройки
const char DAMAGED[] PROGMEM = "gjdht;ltys!"; //повреждены!
const char RESTORE[] PROGMEM = "Djccnfyjdbnm?"; //восстановить?

const char LOAD[] PROGMEM = "pfuheprf..."; //загрузка...
const char READ[] PROGMEM = "xntybt..."; //чтение...

//Сброс
const char RES_RESET[] PROGMEM = "C,hjcbnm"; //Сбросить
const char RES_MAIN[] PROGMEM = "jcyjdyst"; //основные
const char RES_SETTINGS_M[] PROGMEM = "yfcnhjqrb?"; //настройки?
const char RES_SETTINGS_P[] PROGMEM = "yfcnhjqrb"; //настройки
const char RES_PUMP[] PROGMEM = "rjydthnthf?"; //конвертера?
const char RES_DATA[] PROGMEM = "lfyyst"; //данные
const char RES_USER[] PROGMEM = "gjkmpjdfntkz?"; //пользователя?

//Замер бета
const char M_MEASUR_BETA[] PROGMEM = "Pfvth ,tnf"; //Замер бета

const char M_STOP[] PROGMEM = "Jcnfyjdbnm"; //Остановить
const char M_MEASUR[] PROGMEM = "pfvth&"; //замер?

const char M_MEASURS[] PROGMEM = "Pfvth"; //Замер
const char M_COMPLET[] PROGMEM = "pfdthity!"; //завершен!

const char M_RESULT[] PROGMEM = "HTPEKMNFN"; //РЕЗУЛЬТАТ
const char M_BACK_OK[] PROGMEM = "JR-PFVTH AJYF"; //ОК-ЗАМЕР ФОНА
const char M_BACK[] PROGMEM = "PFVTH AJYF"; //ЗАМЕР ФОНА
const char M_SAMP_OK[] PROGMEM = "JR-PFV.J<HFPWF"; //ОК-ЗАМ.ОБРАЗЦА
const char M_SAMP[] PROGMEM = "PFVTH J<HFPWF"; //ЗАМЕР ОБРАЗЦА
const char M_BACK_I[] PROGMEM = "AJY"; //ФОН
const char M_SAMP_I[] PROGMEM = "J<H"; //ОБР

const char M_MIN[] PROGMEM = "vby"; //мин
const char M_TIME[] PROGMEM = "&"; //:

//Тревога
const char A_ALARM[] PROGMEM = "NHTDJUF!"; //Тревога!
const char A_WARN[] PROGMEM = "JGFCYJCNM!"; //Опасность!

const char A_BACK[] PROGMEM = "Ajy"; //Фон
const char A_DOSE[] PROGMEM = "Ljpf"; //Доза

//Батарея
const char B_BAT[] PROGMEM = "<fnfhtz"; //Батарея
const char B_LOW[] PROGMEM = "hfphz;tyf!"; //разряжена!

//Поиск
const char S_SEARCH[] PROGMEM = "Gjbcr"; //Поиск

const char S_IMP_PER_SEC[] PROGMEM = "bvg|c"; //имп/с
const char S_IMP_PER_MIN[] PROGMEM = "bvg|v"; //имп/м

//Параметры
const char P_PARAM[] PROGMEM = "Gfhfvtnhs"; //Параметры

const char P_BAT[] PROGMEM = "<fnfhtz&"; //Батарея:
const char P_ADC_BAT[] PROGMEM = "Pyfx.FWG&"; //Знач.АЦП:
const char P_HV_PUMP[] PROGMEM = "Yfrfxrf DD&"; //Накачка ВВ:
const char P_PUMP_SPEED[] PROGMEM = "Crjhjcnm&"; //Скорость:
const char P_REFERENCE[] PROGMEM = "Jgjhyjt&"; //Опорное:

//Отладка
const char D_DEBUG[] PROGMEM = "Jnkflrf"; //Отладка

const char D_BAT[] PROGMEM = "<FN"; //БАТ
const char D_ADC_BAT[] PROGMEM = "FWG"; //АЦП
const char D_HV_PUMP[] PROGMEM = "DD"; //ВВ
const char D_PUMP_SPEED[] PROGMEM = "CRH"; //СКР
const char D_REFERENCE[] PROGMEM = "JGH"; //ОПР
const char D_PULS_LEN[] PROGMEM = "BVG"; //ИМП
const char D_COEF_DIV[] PROGMEM = "RLK"; //КДЛ
const char D_PUMP_ADC[] PROGMEM = "FWG"; //АЦП
const char D_WDT_PER[] PROGMEM = "GTH"; //ПЕР
const char D_GEIGER_TIME[] PROGMEM = "CX"; //СЧ

const char D_COEF_NOW[] PROGMEM = "NTREO&"; //ТЕКУЩ
const char D_COEF_LIMIT[] PROGMEM = "GJHJU&"; //ПОРОГ

//Настройки
const char S_SETTINGS[] PROGMEM = "Yfcnhjqrb"; //Настройки

const char S_ITEM_SLEEP[] PROGMEM = "Cjy&"; //Сон:
const char S_ITEM_LIGHT[] PROGMEM = "Gjlcdtnrf&"; //Подсветка:
const char S_ITEM_CONTRAST[] PROGMEM = "Rjynhfcn&"; //Контраст:
const char S_ITEM_BRIGHT[] PROGMEM = "Zhrjcnm&"; //Яркость:
const char S_ITEM_ROTATION[] PROGMEM = "Hfpdjhjn&"; //Разворот:
const char S_ITEM_FLASHES[] PROGMEM = "Dcgsirb&"; //Вспышки:
const char S_ITEM_VOLUME[] PROGMEM = "Uhjvrjcnm&"; //Громкость:
const char S_ITEM_CLICKS[] PROGMEM = "Otkxrb&"; //Щелчки:
const char S_ITEM_BUTT_SOUND[] PROGMEM = "Pd.ryjgjr&"; //Зв.кнопок:
const char S_ITEM_DIFF_MEASUR[] PROGMEM = "Hfpy.pfv&"; //Разн.зам:
const char S_ITEM_AVERAG[] PROGMEM = "Echtl.ajy&"; //Усред.фон:
const char S_ITEM_SIGMA[] PROGMEM = "Cbuvf&"; //Сигма:
const char S_ITEM_SEARCH[] PROGMEM = "Gjbcr&"; //Поиск:
const char S_ITEM_SPEED[] PROGMEM = "Crjhjcnm&"; //Скорость:
const char S_ITEM_UNITS[] PROGMEM = "Tl.bpvth&"; //Ед.измер:
const char S_ITEM_ALARM_BACK[] PROGMEM = "Nhtdjuf A&"; //Тревога Ф:
const char S_ITEM_ALARM_THRESHOLD_BACK_1[] PROGMEM = "Gjhju A1&"; //Порог Ф1:
const char S_ITEM_ALARM_THRESHOLD_BACK_2[] PROGMEM = "Gjhju A2&"; //Порог Ф2:
const char S_ITEM_ALARM_DOSE[] PROGMEM = "Nhtdjuf L&"; //Тревога Д:
const char S_ITEM_ALARM_THRESHOLD_DOSE_1[] PROGMEM = "Gjhju L1&"; //Порог Д1:
const char S_ITEM_ALARM_THRESHOLD_DOSE_2[] PROGMEM = "Gjhju L2&"; //Порог Д2:
const char S_ITEM_UART_SET[] PROGMEM = "Gjhn&"; //Порт:

const char S_SWITCH_MANUAL[] PROGMEM = "HEXY"; //РУЧН
const char S_SWITCH_AUTO[] PROGMEM = "FDNJ"; //АВТО
const char S_SWITCH_MANUAL_EXCEPT_SLEEP[] PROGMEM = "RH.CYF"; //КР.СНА
const char S_SWITCH_BACK_1[] PROGMEM = "AJY1"; //ФОН1
const char S_SWITCH_SOUND[] PROGMEM = "PDER"; //ЗВУК
const char S_SWITCH_VIBRO[] PROGMEM = "DB<H"; //ВИБР
const char S_SWITCH_SOUND_VIBRO[] PROGMEM = "D+PD"; //З+ВБ

//Меню
const char MAIN_MENU[] PROGMEM = "Vty/"; //Меню

const char MAIN_BACK_DOSE[] PROGMEM = "Ajy | Ljpf"; //Фон / Доза
const char MAIN_SEARCH[] PROGMEM = "Ht;bv gjbcrf"; //Режим поиска
const char MAIN_MEASUR[] PROGMEM = "Pfvth ,tnf"; //Замер бета
const char MAIN_LOGBOOK[] PROGMEM = ":ehyfk"; //Журнал
const char MAIN_SETTINGS[] PROGMEM = "Yfcnhjqrb"; //Настройки
const char MAIN_PARAM[] PROGMEM = "Gfhfvtnhs"; //Параметры
const char MAIN_POWER_DOWN[] PROGMEM = "Dsrk/xtybt"; //Выключение

//Журнал
const char L_LOGBOOK[] PROGMEM = ":ehyfk"; //Журнал

const char L_DATA_DOSE[] PROGMEM = "LJPF"; //ДОЗА
const char L_DATA_BACK[] PROGMEM = "AJY"; //ФОН
const char L_DATA_MINS[] PROGMEM = "v"; //м
const char L_DATA_ERROR_NUM[] PROGMEM = "Jib,rf #"; //Ошибка #
const char L_DATA_NULL[] PROGMEM = "- gecnj -"; //- пусто -

const char L_ITEM_ALARM[] PROGMEM = "Nhtdjuf"; //Тревога
const char L_ITEM_WARN[] PROGMEM = "Jgfcyjcnm"; //Опасность
const char L_ITEM_MEASUR[] PROGMEM = "Pfvths ,tnf"; //Замеры бета
const char L_ITEM_ERRORS[] PROGMEM = "Jib,rb"; //Ошибки
const char L_ITEM_SETTINGS[] PROGMEM = "Yfcnhjqrb"; //Настройки
const char L_ITEM_ASTER[] PROGMEM = "*"; //*

const char L_SETTINGS_ALARM[] PROGMEM = "Nhtdjuf&"; //Тревога:
const char L_SETTINGS_WARN[] PROGMEM = "Jgfcyjcnm&"; //Опасность:
const char L_SETTINGS_MEASUR[] PROGMEM = "Pfvths&"; //Замеры:
const char L_SETTINGS_CLEAR[] PROGMEM = "Jxbcnbnm"; //Очистить

//Ошибки
const char E_ERROR[] PROGMEM = " - JIB<RF - "; //- ОШИБКА -
const char E_ERROR_NULL[] PROGMEM = "* gecnj *"; //* пусто *

const char E_DATA_OVERLOAD[] PROGMEM = "Gthtuheprf"; //Перегрузка
const char E_DATA_PUMP[] PROGMEM = "rjydthnthf!"; //конвертера!

const char E_DATA_LOW[] PROGMEM = "Ybprjt"; //Низкое
const char E_DATA_VOLTAGE[] PROGMEM = "yfghz;tybt"; //напряжение

const char E_DATA_SHOT_CIRCUIT[] PROGMEM = "Rjhjnrjt pfv."; //Короткое зам.
const char E_DATA_NO_ACCOUNT[] PROGMEM = "Ytn cxtnf!"; //Нет счета!

const char E_DATA_OFF_SCALE[] PROGMEM = "bkb pfirfk"; //или зашкал!
const char E_DATA_DETECTOR[] PROGMEM = "ltntrnjhf!"; //детектора!

const char E_DATA_SPEED[] PROGMEM = "CRH&"; //СКР:
const char E_DATA_HV[] PROGMEM = "YFG&"; //НАП:

//Сброс данных
const char R_RESET[] PROGMEM = "C,hjcbnm"; //Сбросить
const char R_CURRENT_DOSE[] PROGMEM = "ntreoe/ ljpe?"; //текущую дозу?
const char R_ALL_DOSE[] PROGMEM = "j,oe/ ljpe?"; //общую дозу?
const char R_CLEAR[] PROGMEM = "Jxbcnbnm"; //Очистить
const char R_ALL_LOGBOOK[] PROGMEM = "dtcm ;ehyfk?"; //весь журнал?

const char R_SUCC_ALL_DOSE[] PROGMEM = "J,ofz ljpf"; //Общая доза
const char R_SUCC_CURRENT_DOSE[] PROGMEM = "Ntreofz ljpf"; //Текущая доза
const char R_SUCC_RESET[] PROGMEM = "c,hjityf!"; //сброшена!
const char R_SUCC_LOGBOOK[] PROGMEM = ":ehyfk"; //Журнал
const char R_SUCC_CLEAR[] PROGMEM = "jxboty!"; //очищен!

//Сохранение настроек
const char W_SAVE[] PROGMEM = "Cj[hfybnm";     //Сохранить
const char W_SETTINGS[] PROGMEM = "yfcnhjqrb?"; //настройки?

const char W_SETTINGS_SUCC[] PROGMEM = "Yfcnhjqrb"; //Настройки
const char W_SAVE_SUCC[] PROGMEM = "Cj[hfytys!";   //сохранены!

//Общие символы
const char ALL_SWITCH_OFF[] PROGMEM = "DSRK"; //ВЫКЛ
const char ALL_SWITCH_ON[] PROGMEM = "DRK";   //ВКЛ

const char ALL_YES[] PROGMEM = "  LF  "; //ДА
const char ALL_NO[] PROGMEM = "  YTN  "; //НЕТ

//Главные экраны ФОН/ДОЗА
const char MAIN_SCREEN_BACK[] PROGMEM = "Ajy"; //Фон
const char MAIN_SCREEN_DOSE[] PROGMEM = "Ljpf"; //Доза

const char MAIN_SCREEN_CURRENT_DOSE[] PROGMEM = "LJPF&"; //ДОЗА:
const char MAIN_SCREEN_BACK_MAX[] PROGMEM = "VFRC&"; //МАКС:

const char MAIN_SCREEN_CURRENT_DOSE_ALL[] PROGMEM = "DCTUJ&"; //ВСЕГО:

const char MAIN_SCREEN_GRAF_SEC[] PROGMEM = "CTR"; //СЕК
const char MAIN_SCREEN_GRAF_MIN[] PROGMEM = "VBY"; //МИН

const char MAIN_SCREEN_DOSE_DAYS[] PROGMEM = "l"; //д
const char MAIN_SCREEN_DOSE_HOURSE[] PROGMEM = "x"; //ч
const char MAIN_SCREEN_DOSE_MINS[] PROGMEM = "v"; //м

const char MAIN_SCREEN_DOSE_ACCUM[] PROGMEM = "yfrjgktyj"; //накоплено
const char MAIN_SCREEN_DOSE_JUST_OVER[] PROGMEM = "dctuj pf&"; //всего за:


//Единицы измерения
const char UNIT_COUNT_PER_SQUARE_CM[] PROGMEM = "x|cv2"; //ч/см2

const char UNIT_UR[] PROGMEM = "vrH";     //мкР
const char UNIT_UR_H[] PROGMEM = "vrH|x"; //мкР/ч
const char UNIT_MR[] PROGMEM = "vH";      //мР
const char UNIT_MR_H[] PROGMEM = "vH|x";  //мР/ч

const char UNIT_USV[] PROGMEM = "vrP";    //мкЗ
const char UNIT_USV_H[] PROGMEM = "vrP|x"; //мкЗ/ч
const char UNIT_MSV[] PROGMEM = "vP";     //мЗ
const char UNIT_MSV_H[] PROGMEM = "vP|x"; //мЗ/ч

const char UNIT_DASH[] PROGMEM = "-"; //-

#define FONT_DATA_NAME RusFont //Название шрифта
#endif
//---------------------------------------------//
#ifdef ENGLISH //если выбран язык "английский"
//Основные
const char INTRO[] PROGMEM = "-=RADON=-"; //-=РАДОН=-

const char SETTINGS[] PROGMEM = "Settings"; //Настройки
const char DAMAGED[] PROGMEM = "damaged!"; //повреждены!
const char RESTORE[] PROGMEM = "Restore?"; //восстановить?

const char LOAD[] PROGMEM = "load..."; //загрузка...
const char READ[] PROGMEM = "read..."; //чтение...

//Сброс
const char RES_RESET[] PROGMEM = "Clear"; //Сбросить
const char RES_MAIN[] PROGMEM = "main"; //основные
const char RES_SETTINGS_M[] PROGMEM = "settings?"; //настройки?
const char RES_SETTINGS_P[] PROGMEM = "converter"; //настройки
const char RES_PUMP[] PROGMEM = "settings?"; //конвертера?
const char RES_DATA[] PROGMEM = "user"; //данные
const char RES_USER[] PROGMEM = "data?"; //пользователя?

//Замер бета
const char M_MEASUR_BETA[] PROGMEM = "Measur mode"; //Замер бета

const char M_STOP[] PROGMEM = "Stop"; //Остановить
const char M_MEASUR[] PROGMEM = "measur:"; //замер?

const char M_MEASURS[] PROGMEM = "Measur"; //Замер
const char M_COMPLET[] PROGMEM = "complet!"; //завершен!

const char M_RESULT[] PROGMEM = "RESULT"; //РЕЗУЛЬТАТ
const char M_BACK_OK[] PROGMEM = "OK-NEXT BACK"; //ОК-ЗАМЕР ФОНА
const char M_BACK[] PROGMEM = "MEASUR BACK"; //ЗАМЕР ФОНА
const char M_SAMP_OK[] PROGMEM = "OK-NEXT SAMP"; //ОК-ЗАМ.ОБРАЗЦА
const char M_SAMP[] PROGMEM = "MEASUR SAMP"; //ЗАМЕР ОБРАЗЦА
const char M_BACK_I[] PROGMEM = "BACK"; //ФОН
const char M_SAMP_I[] PROGMEM = "SAMP"; //ОБР

const char M_MIN[] PROGMEM = "min"; //мин
const char M_TIME[] PROGMEM = ":"; //:

//Тревога
const char A_ALARM[] PROGMEM = "ALARM!"; //Тревога!
const char A_WARN[] PROGMEM = "WARNING!"; //Опасность!

const char A_BACK[] PROGMEM = "Back"; //Фон
const char A_DOSE[] PROGMEM = "Dose"; //Доза

//Батарея
const char B_BAT[] PROGMEM = "Battery"; //Батарея
const char B_LOW[] PROGMEM = "low!"; //разряжена!

//Поиск
const char S_SEARCH[] PROGMEM = "Search"; //Поиск

const char S_IMP_PER_SEC[] PROGMEM = "cps"; //имп/с
const char S_IMP_PER_MIN[] PROGMEM = "cpm"; //имп/м

//Параметры
const char P_PARAM[] PROGMEM = "Parametrs"; //Параметры

const char P_BAT[] PROGMEM = "Battery:"; //Батарея:
const char P_ADC_BAT[] PROGMEM = "ADC BAT:"; //Знач.АЦП:
const char P_HV_PUMP[] PROGMEM = "HV PUMP:"; //Накачка ВВ:
const char P_PUMP_SPEED[] PROGMEM = "Pump speed:"; //Скорость:
const char P_REFERENCE[] PROGMEM = "Reference:"; //Опорное:

//Отладка
const char D_DEBUG[] PROGMEM = "Debug"; //Отладка

const char D_BAT[] PROGMEM = "BAT"; //БАТ
const char D_ADC_BAT[] PROGMEM = "ADC"; //АЦП
const char D_HV_PUMP[] PROGMEM = "HV"; //ВВ
const char D_PUMP_SPEED[] PROGMEM = "SPD"; //СКР
const char D_REFERENCE[] PROGMEM = "REF"; //ОПР
const char D_PULS_LEN[] PROGMEM = "IMP"; //ИМП
const char D_COEF_DIV[] PROGMEM = "CDF"; //КДЛ
const char D_PUMP_ADC[] PROGMEM = "ADC"; //АЦП
const char D_WDT_PER[] PROGMEM = "WDT"; //ПЕР
const char D_GEIGER_TIME[] PROGMEM = "GT"; //СЧ

const char D_COEF_NOW[] PROGMEM = "NOW:"; //ТЕКУЩ
const char D_COEF_LIMIT[] PROGMEM = "LIMIT:"; //ПОРОГ

//Настройки
const char S_SETTINGS[] PROGMEM = "Settings"; //Настройки

const char S_ITEM_SLEEP[] PROGMEM = "Sleep:"; //Сон:
const char S_ITEM_LIGHT[] PROGMEM = "Light:"; //Подсветка:
const char S_ITEM_CONTRAST[] PROGMEM = "Contrast:"; //Контраст:
const char S_ITEM_BRIGHT[] PROGMEM = "Bright:"; //Яркость:
const char S_ITEM_ROTATION[] PROGMEM = "Rotate:"; //Разворот:
const char S_ITEM_FLASHES[] PROGMEM = "Flashes:"; //Вспышки:
const char S_ITEM_VOLUME[] PROGMEM = "Volume:"; //Громкость:
const char S_ITEM_CLICKS[] PROGMEM = "Clicks:"; //Щелчки:
const char S_ITEM_BUTT_SOUND[] PROGMEM = "Butt sound:"; //Зв.кнопок:
const char S_ITEM_DIFF_MEASUR[] PROGMEM = "Diff measur:"; //Разн.зам:
const char S_ITEM_AVERAG[] PROGMEM = "Averag:"; //Усред.фон:
const char S_ITEM_SIGMA[] PROGMEM = "Sigma:"; //Сигма:
const char S_ITEM_SEARCH[] PROGMEM = "Search:"; //Поиск:
const char S_ITEM_SPEED[] PROGMEM = "Speed:"; //Скорость:
const char S_ITEM_UNITS[] PROGMEM = "Units:"; //Ед.измер:
const char S_ITEM_ALARM_BACK[] PROGMEM = "Alarm B:"; //Тревога Ф:
const char S_ITEM_ALARM_THRESHOLD_BACK_1[] PROGMEM = "Back 1:"; //Порог Ф1:
const char S_ITEM_ALARM_THRESHOLD_BACK_2[] PROGMEM = "Back 2:"; //Порог Ф2:
const char S_ITEM_ALARM_DOSE[] PROGMEM = "Alarm D:"; //Тревога Д:
const char S_ITEM_ALARM_THRESHOLD_DOSE_1[] PROGMEM = "Dose 1:"; //Порог Д1:
const char S_ITEM_ALARM_THRESHOLD_DOSE_2[] PROGMEM = "Dose 2:"; //Порог Д2:
const char S_ITEM_UART_SET[] PROGMEM = "Uart:"; //Порт:

const char S_SWITCH_MANUAL[] PROGMEM = "MANUAL"; //РУЧН
const char S_SWITCH_AUTO[] PROGMEM = "AUTO"; //АВТО
const char S_SWITCH_MANUAL_EXCEPT_SLEEP[] PROGMEM = "MES"; //КР.СНА
const char S_SWITCH_BACK_1[] PROGMEM = "BACK1"; //ФОН1
const char S_SWITCH_SOUND[] PROGMEM = "SOUND"; //ЗВУК
const char S_SWITCH_VIBRO[] PROGMEM = "VIBRO"; //ВИБР
const char S_SWITCH_SOUND_VIBRO[] PROGMEM = "S+VIB"; //З+ВБ

//Меню
const char MAIN_MENU[] PROGMEM = "Menu"; //Меню

const char MAIN_BACK_DOSE[] PROGMEM = "Back / Dose"; //Фон / Доза
const char MAIN_SEARCH[] PROGMEM = "Search mode"; //Режим поиска
const char MAIN_MEASUR[] PROGMEM = "Measur mode"; //Замер бета
const char MAIN_LOGBOOK[] PROGMEM = "Logbook"; //Журнал
const char MAIN_SETTINGS[] PROGMEM = "Settings"; //Настройки
const char MAIN_PARAM[] PROGMEM = "Parametrs"; //Параметры
const char MAIN_POWER_DOWN[] PROGMEM = "Turn off"; //Выключение

//Журнал
const char L_LOGBOOK[] PROGMEM = "Logbook"; //Журнал

const char L_DATA_DOSE[] PROGMEM = "DOSE"; //ДОЗА
const char L_DATA_BACK[] PROGMEM = "BACK"; //ФОН
const char L_DATA_MINS[] PROGMEM = "m"; //м
const char L_DATA_ERROR_NUM[] PROGMEM = "Error #"; //Ошибка #
const char L_DATA_NULL[] PROGMEM = "- null -"; //- пусто -

const char L_ITEM_ALARM[] PROGMEM = "Alarm"; //Тревога
const char L_ITEM_WARN[] PROGMEM = "Warning"; //Опасность
const char L_ITEM_MEASUR[] PROGMEM = "Measuring"; //Замеры бета
const char L_ITEM_ERRORS[] PROGMEM = "Errors"; //Ошибки
const char L_ITEM_SETTINGS[] PROGMEM = "Settings"; //Настройки
const char L_ITEM_ASTER[] PROGMEM = "*"; //*

const char L_SETTINGS_ALARM[] PROGMEM = "Alarm:"; //Тревога:
const char L_SETTINGS_WARN[] PROGMEM = "Warning:"; //Опасность:
const char L_SETTINGS_MEASUR[] PROGMEM = "Measur:"; //Замеры:
const char L_SETTINGS_CLEAR[] PROGMEM = "Clear book"; //Очистить

//Ошибки
const char E_ERROR[] PROGMEM = " - ERROR - "; //- ОШИБКА -
const char E_ERROR_NULL[] PROGMEM = "* null *"; //* пусто *

const char E_DATA_OVERLOAD[] PROGMEM = "Overload"; //Перегрузка
const char E_DATA_PUMP[] PROGMEM = "converter!"; //конвертера!

const char E_DATA_LOW[] PROGMEM = "Low"; //Низкое
const char E_DATA_VOLTAGE[] PROGMEM = "voltage"; //напряжение

const char E_DATA_SHOT_CIRCUIT[] PROGMEM = "Short circuit"; //Короткое зам.
const char E_DATA_NO_ACCOUNT[] PROGMEM = "No account!"; //Нет счета!

const char E_DATA_OFF_SCALE[] PROGMEM = "or off scale"; //или зашкал!
const char E_DATA_DETECTOR[] PROGMEM = "detector!"; //детектора!

const char E_DATA_SPEED[] PROGMEM = "SPD:"; //СКР:
const char E_DATA_HV[] PROGMEM = " HV:"; //НАП:

//Сброс данных
const char R_RESET[] PROGMEM = "Reset"; //Сбросить
const char R_CURRENT_DOSE[] PROGMEM = "current dose?"; //текущую дозу?
const char R_ALL_DOSE[] PROGMEM = "all dose?"; //общую дозу?
const char R_CLEAR[] PROGMEM = "Clear"; //Очистить
const char R_ALL_LOGBOOK[] PROGMEM = "all logbook?"; //весь журнал?

const char R_SUCC_ALL_DOSE[] PROGMEM = "All dose"; //Общая доза
const char R_SUCC_CURRENT_DOSE[] PROGMEM = "Current dose"; //Текущая доза
const char R_SUCC_RESET[] PROGMEM = "clear!"; //сброшена!
const char R_SUCC_LOGBOOK[] PROGMEM = "Logbook"; //Журнал
const char R_SUCC_CLEAR[] PROGMEM = "clear!"; //очищен!

//Сохранение настроек
const char W_SAVE[] PROGMEM = "Seve"; //Сохранить
const char W_SETTINGS[] PROGMEM = "settings?"; //настройки?

const char W_SETTINGS_SUCC[] PROGMEM = "Settings"; //Настройки
const char W_SAVE_SUCC[] PROGMEM = "save!";   //сохранены!

//Общие символы
const char ALL_SWITCH_OFF[] PROGMEM = "OFF"; //ВЫКЛ
const char ALL_SWITCH_ON [] PROGMEM = "ON";   //ВКЛ

const char ALL_YES[] PROGMEM = "  YES  "; //ДА
const char ALL_NO [] PROGMEM = "  NO  "; //НЕТ

//Главные экраны ФОН/ДОЗА
const char MAIN_SCREEN_BACK[] PROGMEM = "Back"; //Фон
const char MAIN_SCREEN_DOSE[] PROGMEM = "Dose"; //Доза

const char MAIN_SCREEN_CURRENT_DOSE[] PROGMEM = "DOSE:"; //ДОЗА:
const char MAIN_SCREEN_BACK_MAX[] PROGMEM = "MAX:"; //МАКС:

const char MAIN_SCREEN_CURRENT_DOSE_ALL[] PROGMEM = "ALL:"; //ВСЕГО:

const char MAIN_SCREEN_DOSE_DAYS[] PROGMEM = "d"; //д
const char MAIN_SCREEN_DOSE_HOURSE[] PROGMEM = "h"; //ч
const char MAIN_SCREEN_DOSE_MINS[] PROGMEM = "m"; //м

const char MAIN_SCREEN_GRAF_SEC[] PROGMEM = "SEC"; //СЕК
const char MAIN_SCREEN_GRAF_MIN[] PROGMEM = "MIN"; //МИН

const char MAIN_SCREEN_DOSE_ACCUM[] PROGMEM = "accum"; //накоплено
const char MAIN_SCREEN_DOSE_JUST_OVER[] PROGMEM = "just over:"; //всего за:


//Единицы измерения
const char UNIT_COUNT_PER_SQUARE_CM[] PROGMEM = "c/cm2"; //ч/см2

const char UNIT_UR[] PROGMEM = "uR";      //мкР
const char UNIT_UR_H[] PROGMEM = "uR/h";  //мкР/ч
const char UNIT_MR[] PROGMEM = "mR";      //мР
const char UNIT_MR_H[] PROGMEM = "mR/h";  //мР/ч

const char UNIT_USV[] PROGMEM = "uSv";     //мкЗ
const char UNIT_USV_H[] PROGMEM = "uSv/h"; //мкЗ/ч
const char UNIT_MSV[] PROGMEM = "mSv";     //мЗ
const char UNIT_MSV_H[] PROGMEM = "mSv/h"; //мЗ/ч

const char UNIT_DASH[] PROGMEM = "-"; //-

#define FONT_DATA_NAME EngFont //Название шрифта
#endif
//---------------------------------------------//
