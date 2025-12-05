#define ALARM_AUTO_GISTERESIS (float)(1.00 - (ALARM_AUTO_GIST / 100.00)) //инвертируем проценты
#define IMP_PWR_GISTERESIS (float)(1.00 - (IMP_PWR_GIST / 100.00)) //инвертируем проценты

//-------------------------------Единицы измерения----------------------------------------------------
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
//------------------Количество импульсов в минуту для режима замера--------------------------
float _measur_get_imp_per_min(uint32_t imp) //количество импульсов в минуту для режима замера
{
  return ((float)imp / pgm_read_byte(&diff_measuring[mainSettings.measur_pos]));
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
//------------------------------Расчет точности замера----------------------------------------
uint8_t _get_accur(uint32_t num) //расчет точности замера
{
  return (num) ? constrain(((mainSettings.sigma_lvl + 1) / sqrtf((float)num)) * 100, 1, 99) : 99; //находим статистическую точность
}
