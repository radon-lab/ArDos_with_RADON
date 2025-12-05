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

//переменные работы со звуками
struct soundData {
  uint8_t replay; //флаг повтора мелодии
  uint16_t semp; //текущий семпл мелодии
  uint16_t link; //ссылка на мелодию
  uint16_t size; //количество семплов мелодии
} sound;
uint16_t buzz_vol; //громкость щелчков

volatile uint16_t cnt_puls; //количество циклов для работы пищалки
uint8_t vibro_switch; //переключатель вибрации

//Технические макросы звука
#define SOUND_PRESCALER 64 //пределитель частоты для пищалки
#define SOUND_STOP TIMSK1 = 0x00; PRR |= (0x01 << PRTIM1); power_status &= ~(0x01 << WAIT_TIM1)

#define BUZZ_CYCLE (uint16_t)(((uint32_t)FREQ_BUZZ * (uint32_t)TIME_BUZZ) / 1000) //пересчитываем частоту и время щелчков в циклы таймера
#define BUZZ_TIMER (uint16_t)((F_CPU / SOUND_PRESCALER) / FREQ_BUZZ) //пересчитываем частоту в время таймера

void _buzz_enable(void); //разрешить щелчки
void _buzz_disable(void); //запретить щелчки

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
//---------------------------------------Пищалка старт/стоп---------------------------------------------
void _buzz_play_sound(void) {
  cnt_puls = BUZZ_CYCLE;
  PRR &= ~(0x01 << PRTIM1);
  ICR1 = BUZZ_TIMER;
  OCR1A = buzz_vol;
  TCNT1 = 0x00;
  TIMSK1 = (0x01 << OCIE1A) | (0x01 << TOIE1);
  power_status |= (0x01 << WAIT_TIM1);
}
void _buzz_set_vol(uint8_t vol) {
  buzz_vol = (BUZZ_TIMER / 2) / 10 * vol;
}
//---------------------------------Генерация частоты бузера----------------------------------------------
void soundPulse(uint16_t freq, uint16_t time) //генерация частоты бузера (частота 10..10000, длительность мс.)
{
  cnt_puls = ((uint32_t)freq * (uint32_t)time) / 1000UL; //пересчитываем частоту и время в циклы таймера
  PRR &= ~(0x01 << PRTIM1); //включаем питание таймера
  ICR1 = (F_CPU / SOUND_PRESCALER) / freq; //устанавливаем предел
  OCR1A = ((((F_CPU / SOUND_PRESCALER) / 20) / freq) * mainSettings.volume); //рассчитывааем громкость
  TCNT1 = 0x00; //сбрасываем счетчик
  TIMSK1 = (0x01 << OCIE1A) | (0x01 << TOIE1); //разрешаем прерывания
  power_status |= (0x01 << WAIT_TIM1);
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
//----------------------------------Воспроизведение мелодии-----------------------------------------------
void melodyUpdate(void) //воспроизведение мелодии
{
  if (sound.replay && !timer_melody) { //если пришло время
    soundPulse(pgm_read_word(sound.link + sound.semp), pgm_read_word(sound.link + sound.semp + 2)); //запускаем звук с задоной частотой и временем
    timer_melody = pgm_read_word(sound.link + sound.semp + 4); //устанавливаем паузу перед воспроизведением нового звука
    if ((sound.semp += 6) >= sound.size) { //переключаем на следующий семпл
      if (sound.replay == REPLAY_ONCE) melodyStop(); //если повтор выключен то остановка воспроизведения мелодии
      sound.semp = 0; //сбросили семпл
    }
  }
}
