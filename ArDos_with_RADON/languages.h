//Языки для локализации
#define VERSION "3.6.0" //версия по

//---------------------------------------------//
#ifdef RUSSIAN //если выбран язык "русский"
//Основные
#define INTRO "-=HFLJY=-" //-=РАДОН=-

#define PLEASE "Gj;fkeqcnf" //Пожалуйста
#define WAINT "gjlj;lbnt..." //подождите...

#define LOAD "pfuheprf..." //загрузка...

//Замер бета
#define M_MEASUR_BETA "Pfvth ,tnf" //Замер бета

#define M_STOP "Jcnfyjdbnm" //Остановить
#define M_MEASUR "pfvth&" //замер?

#define M_MEASURS "Pfvth" //Замер
#define M_COMPLET "pfdthity!" //завершен!

#define M_RESULT "HTPEKMNFN" //РЕЗУЛЬТАТ
#define M_BACK_OK "JR-PFVTH AJYF" //ОК-ЗАМЕР ФОНА
#define M_BACK "PFVTH AJYF" //ЗАМЕР ФОНА
#define M_SAMP_OK "JR-PFV.J<HFPWF" //ОК-ЗАМ.ОБРАЗЦА
#define M_SAMP "PFVTH J<HFPWF" //ЗАМЕР ОБРАЗЦА
#define M_BACK_I "AJY" //ФОН
#define M_SAMP_I "J<H" //ОБР

#define M_MIN "vby" //мин
#define M_TIME "&" //:

//Тревога
#define A_ALARM "NHTDJUF!" //Тревога!
#define A_WARN "JGFCYJCNM!" //Опасность!

#define A_BACK "Ajy" //Фон
#define A_DOSE "Ljpf" //Доза

//Батарея
#define B_BAT "<fnfhtz" //Батарея
#define B_LOW "hfphz;tyf!" //разряжена!

//Поиск
#define S_SEARCH "Gjbcr" //Поиск

#define S_IMP_PER_SEC "bvg|c" //имп/с
#define S_IMP_PER_MIN "bvg|v" //имп/м

//Параметры
#define P_PARAM "Gfhfvtnhs" //Параметры

#define P_BAT "<fnfhtz&" //Батарея:
#define P_ADC_BAT "Pyfx.FWG&" //Знач.АЦП:
#define P_HV_PUMP "Yfrfxrf DD&" //Накачка ВВ:
#define P_PUMP_SPEED "Crjhjcnm&" //Скорость:
#define P_REFERENCE "Jgjhyjt&" //Опорное:

//Отладка
#define D_DEBUG "Jnkflrf" //Отладка

#define D_BAT "<FN" //БАТ
#define D_ADC_BAT "FWG" //АЦП
#define D_HV_PUMP "DD" //ВВ
#define D_PUMP_SPEED "CRH" //СКР
#define D_REFERENCE "JGH" //ОПР
#define D_PULS_LEN "BVG" //ИМП
#define D_COEF_DIV "RLK" //КДЛ
#define D_PUMP_ADC "FWG" //АЦП
#define D_WDT_PER "GTH" //ПЕР
#define D_GEIGER_TIME "CX" //СЧ

//Настройки
#define S_SETINGS "Yfcnhjqrb" //Настройки

#define S_ITEM_SLEEP "Cjy&" //Сон:
#define S_ITEM_LIGHT "Gjlcdtnrf&" //Подсветка:
#define S_ITEM_CONTRAST "Rjynhfcn&" //Контраст:
#define S_ITEM_FLASHES "Dcgsirb&" //Вспышки:
#define S_ITEM_CLICKS "Otkxrb&" //Щелчки:
#define S_ITEM_BUTT_SOUND "Pd.Ryjgjr&" //Зв.кнопок:
#define S_ITEM_DIFF_MEASUR "Hfpy.pfv&" //Разн.зам:
#define S_ITEM_SIGMA "Cbuvf&" //Сигма:
#define S_ITEM_SEARCH "Gjbcr&" //Поиск:
#define S_ITEM_UNITS "Tl.bpvth&" //Ед.измер:
#define S_ITEM_ALARM_BACK "Nhtdjuf A&" //Тревога Ф:
#define S_ITEM_ALARM_THRESHOLD_BACK_1 "Gjhju A1&" //Порог Ф1:
#define S_ITEM_ALARM_THRESHOLD_BACK_2 "Gjhju A2&" //Порог Ф2:
#define S_ITEM_ALARM_DOSE "Nhtdjuf L&" //Тревога Д:
#define S_ITEM_ALARM_THRESHOLD_DOSE_1 "Gjhju L1&" //Порог Д1:
#define S_ITEM_ALARM_THRESHOLD_DOSE_2 "Gjhju L2&" //Порог Д2:

#define S_SWITCH_MANUAL "HEXY" //РУЧН
#define S_SWITCH_AUTO "FDNJ" //АВТО
#define S_SWITCH_MANUAL_EXCEPT_SLEEP "RH.CYF" //КР.СНА
#define S_SWITCH_BACK_1 "AJY1" //ФОН1
#define S_SWITCH_SOUND "PDER" //ЗВУК
#define S_SWITCH_VIBRO "DB<H" //ВИБР
#define S_SWITCH_SOUND_VIBRO "D+PD" //З+ВБ

//Меню
#define MAIN_MENU "Vty/" //Меню

#define MAIN_BACK_DOSE "Ajy | Ljpf" //Фон / Доза
#define MAIN_SEARCH "Ht;bv gjbcrf" //Режим поиска
#define MAIN_MEASUR "Pfvth ,tnf" //Замер бета
#define MAIN_LOGBOOK ":ehyfk" //Журнал
#define MAIN_SETINGS "Yfcnhjqrb" //Настройки
#define MAIN_PARAM "Gfhfvtnhs" //Параметры
#define MAIN_POWER_DOWN "Dsrk/xtybt" //Выключение

//Журнал
#define L_LOGBOOK ":ehyfk" //Журнал

#define L_DATA_DOSE "LJPF" //ДОЗА
#define L_DATA_BACK "AJY" //ФОН
#define L_DATA_MINS "v" //м
#define L_DATA_ERROR_NUM "Jib,rf #" //Ошибка #
#define L_DATA_NULL "- gecnj -" //- пусто -

#define L_ITEM_ALARM "Nhtdjuf" //Тревога
#define L_ITEM_WARN "Jgfcyjcnm" //Опасность
#define L_ITEM_MEASUR "Pfvths ,tnf" //Замеры бета
#define L_ITEM_ERRORS "Jib,rb" //Ошибки
#define L_ITEM_SETINGS "Yfcnhjqrb" //Настройки
#define L_ITEM_ASTER "*" //*

#define L_SETINGS_ALARM "Nhtdjuf&" //Тревога:
#define L_SETINGS_WARN "Jgfcyjcnm&" //Опасность:
#define L_SETINGS_MEASUR "Pfvths&" //Замеры:
#define L_SETINGS_CLEAR "Jxbcnbnm" //Очистить

//Ошибки
#define E_ERROR " - JIB<RF - " //- ОШИБКА -
#define E_ERROR_NULL "* gecnj *" //* пусто *

#define E_DATA_OVERLOAD "Gthtuheprf" //Перегрузка
#define E_DATA_PUMP "ghtj,hfpjdfn!" //преобразоват!

#define E_DATA_LOW "Ybprjt" //Низкое
#define E_DATA_VOLTAGE "yfghz;tybt" //напряжение

#define E_DATA_SHOT_CIRCUIT "Rjhjnrjt pfv." //Короткое зам.
#define E_DATA_NO_ACCOUNT "Ytn cxtnf!" //Нет счета!

#define E_DATA_SPEED "CRH&" //СКР:
#define E_DATA_HV "YFG&" //НАП:

//Сброс данных
#define R_RESET "C,hjcbnm" //Сбросить
#define R_CURRENT_DOSE "ntreoe/ ljpe?" //текущую дозу?
#define R_ALL_DOSE "j,oe/ ljpe?" //общую дозу?
#define R_CLEAR "Jxbcnbnm" //Очистить
#define R_ALL_LOGBOOK "dtcm ;ehyfk?" //весь журнал?

#define R_SUCC_ALL_DOSE "J,ofz ljpf" //Общая доза
#define R_SUCC_CURRENT_DOSE "Ntreofz ljpf" //Текущая доза
#define R_SUCC_RESET "c,hjityf!" //сброшена!
#define R_SUCC_LOGBOOK ":ehyfk" //Журнал
#define R_SUCC_CLEAR "jxboty!" //очищен!

//Сохранение настроек
#define W_SAVE "Cj[hfybnm"     //Сохранить
#define W_SETINGS "yfcnhjqrb?" //настройки?

#define W_SETINGS_SUCC "Yfcnhjqrb" //Настройки
#define W_SAVE_SUCC "Cj[hfytys!"   //сохранены!

//Общие символы
#define ALL_SWITCH_OFF "DSRK" //ВЫКЛ
#define ALL_SWITCH_ON "DRK"   //ВКЛ

#define ALL_YES "  LF  " //ДА
#define ALL_NO "  YTN  " //НЕТ

//Главные экраны ФОН/ДОЗА
#define MAIN_SCREEN_BACK "Ajy" //Фон
#define MAIN_SCREEN_DOSE "Ljpf" //Доза

#define MAIN_SCREEN_BACK_MIN "VBY&" //МИН:
#define MAIN_SCREEN_BACK_MAX "VFRC&" //МАКС:

#define MAIN_SCREEN_CURRENT_DOSE_ALL "DCTUJ&" //ВСЕГО:

#define MAIN_SCREEN_DOSE_DAYS "l" //д
#define MAIN_SCREEN_DOSE_HOURSE "x" //ч
#define MAIN_SCREEN_DOSE_MINS "v" //м

#define MAIN_SCREEN_DOSE_ACCUM "yfrjgktyj" //накоплено
#define MAIN_SCREEN_DOSE_JUST_OVER "dctuj pf&" //всего за:


//Единицы измерения
#define UNIT_COUNT_PER_SQUARE_CM "x|cv2" //ч/см2

#define UNIT_UR "vrH"     //мкР
#define UNIT_UR_H "vrH|x" //мкР/ч
#define UNIT_MR "vH"      //мР
#define UNIT_MR_H "vH|x"  //мР/ч

#define UNIT_USV "vrP"    //мкЗ
#define UNIT_USV_H "vrP|x"//мкЗ/ч
#define UNIT_MSV "vP"     //мЗ
#define UNIT_MSV_H "vP|x" //мЗ/ч

#define FONT_DATA_NAME RusFont //Название шрифта
#endif
//---------------------------------------------//
#ifdef ENGLISH //если выбран язык "английский"
//Основные
#define INTRO "-=RADON=-" //-=РАДОН=-

#define PLEASE "Please" //Пожалуйста
#define WAINT "waint..." //подождите...

#define LOAD "Loading..." //загрузка...

//Замер бета
#define M_MEASUR_BETA "Measur mode" //Замер бета

#define M_STOP "Stop" //Остановить
#define M_MEASUR "measur:" //замер?

#define M_MEASURS "Measur" //Замер
#define M_COMPLET "complet!" //завершен!

#define M_RESULT "RESULT" //РЕЗУЛЬТАТ
#define M_BACK_OK "OK-NEXT BACK" //ОК-ЗАМЕР ФОНА
#define M_BACK "MEASUR BACK" //ЗАМЕР ФОНА
#define M_SAMP_OK "OK-NEXT SAMP" //ОК-ЗАМ.ОБРАЗЦА
#define M_SAMP "MEASUR SAMP" //ЗАМЕР ОБРАЗЦА
#define M_BACK_I "BACK" //ФОН
#define M_SAMP_I "SAMP" //ОБР

#define M_MIN "min" //мин
#define M_TIME ":" //:

//Тревога
#define A_ALARM "ALARM!" //Тревога!
#define A_WARN "WARNING!" //Опасность!

#define A_BACK "Back" //Фон
#define A_DOSE "Dose" //Доза

//Батарея
#define B_BAT "Battery" //Батарея
#define B_LOW "low!" //разряжена!

//Поиск
#define S_SEARCH "Search" //Поиск

#define S_IMP_PER_SEC "cps" //имп/с
#define S_IMP_PER_MIN "cpm" //имп/м

//Параметры
#define P_PARAM "Parametrs" //Параметры

#define P_BAT "Battery:" //Батарея:
#define P_ADC_BAT "ADC BAT:" //Знач.АЦП:
#define P_HV_PUMP "HV PUMP:" //Накачка ВВ:
#define P_PUMP_SPEED "Pump speed:" //Скорость:
#define P_REFERENCE "Reference:" //Опорное:

//Отладка
#define D_DEBUG "Debug" //Отладка

#define D_BAT "BAT" //БАТ
#define D_ADC_BAT "ADC" //АЦП
#define D_HV_PUMP "HV" //ВВ
#define D_PUMP_SPEED "SPD" //СКР
#define D_REFERENCE "REF" //ОПР
#define D_PULS_LEN "IMP" //ИМП
#define D_COEF_DIV "CDF" //КДЛ
#define D_PUMP_ADC "ADC" //АЦП
#define D_WDT_PER "WDT" //ПЕР
#define D_GEIGER_TIME "GT" //СЧ

//Настройки
#define S_SETINGS "Settings" //Настройки

#define S_ITEM_SLEEP "Sleep:" //Сон:
#define S_ITEM_LIGHT "Light:" //Подсветка:
#define S_ITEM_CONTRAST "Contrast:" //Контраст:
#define S_ITEM_FLASHES "Flashes:" //Вспышки:
#define S_ITEM_CLICKS "Clicks:" //Щелчки:
#define S_ITEM_BUTT_SOUND "Butt sound:" //Зв.кнопок:
#define S_ITEM_DIFF_MEASUR "Diff measur:" //Разн.зам:
#define S_ITEM_SIGMA "Sigma:" //Сигма:
#define S_ITEM_SEARCH "Search:" //Поиск:
#define S_ITEM_UNITS "Units:" //Ед.измер:
#define S_ITEM_ALARM_BACK "Alarm B:" //Тревога Ф:
#define S_ITEM_ALARM_THRESHOLD_BACK_1 "Back 1:" //Порог Ф1:
#define S_ITEM_ALARM_THRESHOLD_BACK_2 "Back 2:" //Порог Ф2:
#define S_ITEM_ALARM_DOSE "Alarm D:" //Тревога Д:
#define S_ITEM_ALARM_THRESHOLD_DOSE_1 "Dose 1:" //Порог Д1:
#define S_ITEM_ALARM_THRESHOLD_DOSE_2 "Dose 2:" //Порог Д2:

#define S_SWITCH_MANUAL "MANUAL" //РУЧН
#define S_SWITCH_AUTO "AUTO" //АВТО
#define S_SWITCH_MANUAL_EXCEPT_SLEEP "MES" //КР.СНА
#define S_SWITCH_BACK_1 "BACK1" //ФОН1
#define S_SWITCH_SOUND "SOUND" //ЗВУК
#define S_SWITCH_VIBRO "VIBRO" //ВИБР
#define S_SWITCH_SOUND_VIBRO "S+VIB" //З+ВБ

//Меню
#define MAIN_MENU "Menu" //Меню

#define MAIN_BACK_DOSE "Back / Dose" //Фон / Доза
#define MAIN_SEARCH "Search mode" //Режим поиска
#define MAIN_MEASUR "Measur mode" //Замер бета
#define MAIN_LOGBOOK "Logbook" //Журнал
#define MAIN_SETINGS "Settings" //Настройки
#define MAIN_PARAM "Parametrs" //Параметры
#define MAIN_POWER_DOWN "Turn off" //Выключение

//Журнал
#define L_LOGBOOK "Logbook" //Журнал

#define L_DATA_DOSE "DOSE" //ДОЗА
#define L_DATA_BACK "BACK" //ФОН
#define L_DATA_MINS "m" //м
#define L_DATA_ERROR_NUM "Error #" //Ошибка #
#define L_DATA_NULL "- null -" //- пусто -

#define L_ITEM_ALARM "Alarm" //Тревога
#define L_ITEM_WARN "Warning" //Опасность
#define L_ITEM_MEASUR "Measuring" //Замеры бета
#define L_ITEM_ERRORS "Errors" //Ошибки
#define L_ITEM_SETINGS "Settings" //Настройки
#define L_ITEM_ASTER "*" //*

#define L_SETINGS_ALARM "Alarm:" //Тревога:
#define L_SETINGS_WARN "Warning:" //Опасность:
#define L_SETINGS_MEASUR "Measur:" //Замеры:
#define L_SETINGS_CLEAR "Clear book" //Очистить

//Ошибки
#define E_ERROR " - ERROR - " //- ОШИБКА -
#define E_ERROR_NULL "* null *" //* пусто *

#define E_DATA_OVERLOAD "Overload" //Перегрузка
#define E_DATA_PUMP "pump!" //преобразоват!

#define E_DATA_LOW "Low" //Низкое
#define E_DATA_VOLTAGE "voltage" //напряжение

#define E_DATA_SHOT_CIRCUIT "Short circuit" //Короткое зам.
#define E_DATA_NO_ACCOUNT "No account!" //Нет счета!

#define E_DATA_SPEED "SPD:" //СКР:
#define E_DATA_HV " HV:" //НАП:

//Сброс данных
#define R_RESET "Reset" //Сбросить
#define R_CURRENT_DOSE "current dose?" //текущую дозу?
#define R_ALL_DOSE "all dose?" //общую дозу?
#define R_CLEAR "Clear" //Очистить
#define R_ALL_LOGBOOK "all logbook?" //весь журнал?

#define R_SUCC_ALL_DOSE "All dose" //Общая доза
#define R_SUCC_CURRENT_DOSE "Current dose" //Текущая доза
#define R_SUCC_RESET "clear!" //сброшена!
#define R_SUCC_LOGBOOK "Logbook" //Журнал
#define R_SUCC_CLEAR "clear!" //очищен!

//Сохранение настроек
#define W_SAVE "Seve" //Сохранить
#define W_SETINGS "settings?" //настройки?

#define W_SETINGS_SUCC "Settings" //Настройки
#define W_SAVE_SUCC "save!"   //сохранены!

//Общие символы
#define ALL_SWITCH_OFF "OFF" //ВЫКЛ
#define ALL_SWITCH_ON  "ON"   //ВКЛ

#define ALL_YES "  YES  " //ДА
#define ALL_NO  "  NO  " //НЕТ

//Главные экраны ФОН/ДОЗА
#define MAIN_SCREEN_BACK "Back" //Фон
#define MAIN_SCREEN_DOSE "Dose" //Доза

#define MAIN_SCREEN_BACK_MIN "MIN:" //МИН:
#define MAIN_SCREEN_BACK_MAX "MAX:" //МАКС:

#define MAIN_SCREEN_CURRENT_DOSE_ALL "ALL:" //ВСЕГО:

#define MAIN_SCREEN_DOSE_DAYS "d" //д
#define MAIN_SCREEN_DOSE_HOURSE "h" //ч
#define MAIN_SCREEN_DOSE_MINS "m" //м

#define MAIN_SCREEN_DOSE_ACCUM "accum" //накоплено
#define MAIN_SCREEN_DOSE_JUST_OVER "just over:" //всего за:


//Единицы измерения
#define UNIT_COUNT_PER_SQUARE_CM "c/cm2" //ч/см2

#define UNIT_UR "uR"     //мкР
#define UNIT_UR_H "uR/h" //мкР/ч
#define UNIT_MR "mR"      //мР
#define UNIT_MR_H "mR/h"  //мР/ч

#define UNIT_USV "uSv"    //мкЗ
#define UNIT_USV_H "uSv/h"//мкЗ/ч
#define UNIT_MSV "mSv"     //мЗ
#define UNIT_MSV_H "mSv/h" //мЗ/ч

#define FONT_DATA_NAME EngFont //Название шрифта
#endif
//---------------------------------------------//
