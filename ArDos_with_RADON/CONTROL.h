//--------------------------------------Сброс режима замера----------------------------------------------
void _measur_reset(void) //сброс режима замера
{
  measur_state = 0; //выключаем замер
  measur_time_switch = 0; //сбрасываем таймер
  measur_next = 1; //сбрасываем флаг следующего замера
  measur_alarm = 1; //разрешаем оповещение оканчания замера
  measur_first_froze = 0; //сбрасываем счетчик 1-го замера
  measur_second_froze = 0; //сбрасываем счетчик 2-го замера
  measur_back = 0; //сбрасываем результат замера в мкр/ч
  measur_imp = 0; //сбрасываем результат замера в имп
}
//---------------------------------Проверка значений уровня тревоги--------------------------------------
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
//----------------------------------------Сброс предупреждения--------------------------------------------
boolean _skip_warn_messege(void) //сброс предупреждения
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
//-----------------------------------------Звук предупреждения---------------------------------------------
void _warn_messege(boolean set, uint8_t state, uint8_t sound) //звук предупреждения
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
//----------------------------------------------Выбор тревоги-----------------------------------------------
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
        _warn_messege(0, mainSettings.alarm_back, SOUND_WARN); //фон 1
#if LOGBOOK_RETURN
        if (bookSettings.logbook_warn) _logbook_data_update(1, 1, rad_back); //обновление журнала
#endif
        break;
      case 2: //доза 1
        _warn_messege(1, mainSettings.alarm_dose, SOUND_WARN); //доза 1
#if LOGBOOK_RETURN
        if (bookSettings.logbook_warn) _logbook_data_update(1, 2, rad_dose); //обновление журнала
#endif
        break;
      case 3: //фон 2
        _warn_messege(0, mainSettings.alarm_back, SOUND_ALARM); //фон 2
#if LOGBOOK_RETURN
        if (bookSettings.logbook_alarm) _logbook_data_update(0, 1, rad_back); //обновление журнала
#endif
        break;
      case 4: //доза 2
        _warn_messege(1, mainSettings.alarm_dose, SOUND_ALARM); //доза 2
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
