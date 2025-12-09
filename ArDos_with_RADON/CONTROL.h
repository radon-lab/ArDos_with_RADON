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

    search_imp_s = ((float)temp_buff / search_score_now) * (1000.00 / pgm_read_word(&search_time[mainSettings.search_pos])); //персчет имп/сек.
    search_imp_m = search_imp_s * 60.0; //персчет импульсов в имп/мин.
#if APPROX_BACK_SCORE
    search_back = _get_aprox_back(search_imp_s); //считаем мкР/ч
#else
    search_back = search_imp_s * pumpSettings.geiger_time; //считаем мкР/ч
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
  search_scan_ind = scan_now; //отображаем сразу
#else
  if (scan_now < search_scan_ind) search_scan_ind--; //добавляем плавности при уменьшении
  else search_scan_ind = scan_now; //если увеличелось то отображаем сразу
#endif
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
