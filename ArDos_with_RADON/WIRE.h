#define WIRE_PULL 1 //подтяжка шины I2C(0 - внешняя подтяжка | 1 - внутренняя подтяжка)
#define WIRE_SPEED 1 //скорость шины I2C(0 - 100kHz | 1 - 400kHz)

//---------------------------------------Инициализация wire--------------------------------------------
void wireInit(void) //инициализация wire
{
#if WIRE_PULL
  PORTC |= 0x30; //включаем подтяжку SDA и SCL
#else
  PORTC &= 0xCF; //отключаем подтяжку SDA и SCL
#endif
  DDRC &= 0xCF; //устанавливаем SDA и SCL как входы
#if WIRE_SPEED
  TWBR = 12; //устанавливаем скорость 400kHz
#else
  TWBR = 72; //устанавливаем скорость 100kHz
#endif
  TWSR = 0; //устанавливаем пределитель 1
}
//-----------------------------------Ожидание готовности шины------------------------------------------
boolean wireWait(void) //ожидание готовности шины
{
  for (uint16_t i = 500; i; i--) { //ждем флага прерывания
    if (TWCR & (0x01 << TWINT)) return (boolean)((TWSR & 0xF8) == 0x20 || (TWSR & 0xF8) == 0x30); //возвращаем состояние шины
  }
  return 1; //возвращаем ошибку
}
//----------------------------------------Запуск шины wire---------------------------------------------
void wireStart(void) //запуск шины wire
{
  TWCR = (0x01 << TWSTA) | (0x01 << TWEN) | (0x01 << TWINT); //отправляем команду старт и устанавливаем флаг выполнить задачу
  wireWait(); //ожидание готовности шины
}
//---------------------------------------Остановка шины wire-------------------------------------------
void wireEnd(void) //остановка шины wire
{
  TWCR = (0x01 << TWSTO) | (0x01 << TWEN) | (0x01 << TWINT); //отправляем команду стоп и устанавливаем флаг выполнить задачу
}
//---------------------------------------Отправка байта------------------------------------------------
void wireWrite(uint8_t data) //отправка байта
{
  TWDR = data; //записываем данные в регистр
  TWCR = (0x01 << TWEN) | (0x01 << TWINT); //запустить передачу
  wireWait(); //ожидание готовности шины
}
//--------------------------------------Запуск передачи------------------------------------------------
void wireBeginTransmission(uint8_t addr, uint8_t mode) //запуск передачи
{
  wireStart(); //запуск шины wire
  wireWrite(addr << 0x01); //отправка устройству адреса с битом write
  if (wireWait()) { //ожидаем окончание передачи
    wireEnd(); //остановка шины wire
    return; //возвращаем ошибку
  }
  wireWrite(mode); //отправляем режим записи
}