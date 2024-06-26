//-----------------------------------Стирание блока в EEPROM--------------------------------------------
void EEPROM_ClearBlock(uint16_t addr, uint16_t sizeData) //стирание блока в EEPROM
{
  while (sizeData) { //стираем побайтно блок данных
    sizeData--; //убавили счетчик байт
    while (EECR & (0x01 << EEPE)); //ждем окончания записи
    EEAR = addr; //загружаем адрес
    EECR |= (0x01 << EERE); //запускаем чтение
    if (EEDR) { //если байт изменился
      EEDR = 0x00; //загружаем байт данных
      EECR |= 1 << EEMPE; //разрешаем запись
      EECR |= 1 << EEPE; //сбрасываем флаг записи
    }
    addr++; //сместили адрес
  }
}
//-----------------------------------Запись блока в EEPROM--------------------------------------------
void EEPROM_WriteBlock(uint16_t data, uint16_t addr, uint8_t sizeData) //запись блока в EEPROM
{
  while (sizeData) { //записываем побайтно блок данных
    sizeData--; //убавили счетчик байт
    while (EECR & (0x01 << EEPE)); //ждем окончания записи
    EEAR = addr; //загружаем адрес
    EEDR = *(uint8_t*)data; //загружаем байт данных
    EECR |= 1 << EEMPE; //разрешаем запись
    EECR |= 1 << EEPE; //сбрасываем флаг записи
    addr++; //сместили адрес
    data++; //сместили ячейку памяти
  }
}
//-----------------------------------Обновление блока в EEPROM----------------------------------------
void EEPROM_UpdateBlock(uint16_t data, uint16_t addr, uint8_t sizeData) //обновление блока в EEPROM
{
  while (sizeData) { //записываем побайтно блок данных
    sizeData--; //убавили счетчик байт
    while (EECR & (0x01 << EEPE)); //ждем окончания записи
    EEAR = addr; //загружаем адрес
    EECR |= (0x01 << EERE); //запускаем чтение
    if (EEDR != *(uint8_t*)data) { //если байт изменился
      EEDR = *(uint8_t*)data; //загружаем байт данных
      EECR |= 1 << EEMPE; //разрешаем запись
      EECR |= 1 << EEPE; //сбрасываем флаг записи
    }
    addr++; //сместили адрес
    data++; //сместили ячейку памяти
  }
}
//-----------------------------------Чтение блока из EEPROM-------------------------------------------
void EEPROM_ReadBlock(uint16_t data, uint16_t addr, uint8_t sizeData) //чтение блока из EEPROM
{
  while (sizeData) { //читаем побайтно блок данных
    sizeData--; //убавили счетчик байт
    while (EECR & (0x01 << EEPE)); //ждем окончания записи
    EEAR = addr; //загружаем адрес
    EECR |= (0x01 << EERE); //запускаем чтение
    *(uint8_t*)data = EEDR; //записываем байт в блок памяти
    addr++; //сместили адрес
    data++; //сместили ячейку памяти
  }
}
//-----------------------------------Запись байта в EEPROM--------------------------------------------
void EEPROM_WriteByte(uint16_t addr, uint8_t data) //запись байта в EEPROM
{
  while (EECR & (0x01 << EEPE)); //ждем окончания записи
  EEAR = addr; //загружаем адрес
  EEDR = data; //загружаем байт данных
  EECR |= 1 << EEMPE; //разрешаем запись
  EECR |= 1 << EEPE; //сбрасываем флаг записи
}
//-----------------------------------Обновление байта в EEPROM---------------------------------------
void EEPROM_UpdateByte(uint16_t addr, uint8_t data) //обновление байта в EEPROM
{
  while (EECR & (0x01 << EEPE)); //ждем окончания записи
  EEAR = addr; //загружаем адрес
  EECR |= (0x01 << EERE); //запускаем чтение
  if (EEDR != data) { //если байт изменился
    EEDR = data; //загружаем байт данных
    EECR |= 1 << EEMPE; //разрешаем запись
    EECR |= 1 << EEPE; //сбрасываем флаг записи
  }
}
//-----------------------------------Чтение байта из EEPROM-------------------------------------------
uint8_t EEPROM_ReadByte(uint16_t addr) //чтение байта из EEPROM
{
  while (EECR & (0x01 << EEPE)); //ждем окончания записи
  EEAR = addr; //загружаем адрес
  EECR |= (0x01 << EERE); //запускаем чтение
  return EEDR; //возвращаем результат
}
