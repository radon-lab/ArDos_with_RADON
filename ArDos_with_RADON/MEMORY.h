#define EEPROM_SIZE_STATISTIC 256 //размер блока статистики
#define EEPROM_BLOCK_STATISTIC 510 //первая ячейка блока статистики

#define EEPROM_SIZE_LOGBOOK_INFO 10 //размер блока информации
#define EEPROM_SIZE_LOGBOOK_DATA 40 //размер блока данных
#define EEPROM_BLOCK_LOGBOOK_INFO 200 //первая ячейка блока информации
#define EEPROM_BLOCK_LOGBOOK_DATA 240 //первая ячейка блока данных

#define EEPROM_BLOCK_SETTINGS_MAIN (EEPROM_BLOCK_NULL) //ячейка основных настроек
#define EEPROM_BLOCK_SETTINGS_BOOK (EEPROM_BLOCK_SETTINGS_MAIN + sizeof(mainSettings)) //ячейка настроек журнала
#define EEPROM_BLOCK_SETTINGS_PUMP (EEPROM_BLOCK_SETTINGS_BOOK + sizeof(bookSettings)) //ячейка настроек преобразователя
#define EEPROM_BLOCK_CRC_MAIN (EEPROM_BLOCK_SETTINGS_PUMP + sizeof(pumpSettings)) //ячейка контрольной суммы основных настроек
#define EEPROM_BLOCK_CRC_BOOK (EEPROM_BLOCK_CRC_MAIN + 1) //ячейка контрольной суммы настроек журнала
#define EEPROM_BLOCK_CRC_PUMP (EEPROM_BLOCK_CRC_BOOK + 1) //ячейка контрольной суммы настроек преобразователя
#define EEPROM_BLOCK_CRC_STRUCT (EEPROM_BLOCK_CRC_PUMP + 1) //ячейка контрольной суммы структур данных

uint8_t cur_dose_cell = 0; //текущая ячейка хранения дозы
uint32_t time_save; //время из памяти
uint32_t rad_dose_save; //доза из памяти
uint32_t time_save_old; //предыдущее значение сохраненного времени
uint32_t rad_dose_old; //предыдущее значение дозы

uint8_t logbook_info_buff[10]; //буфер информации о данных журнала
uint32_t logbook_data_buff[10]; //буфер данных журнала

//------------------------Сверка контрольной суммы--------------------------------------------------
void _check_crc(uint8_t* crc, uint8_t data) //сверка контрольной суммы
{
  for (uint8_t i = 0; i < 8; i++) { //считаем для всех бит
    *crc = ((*crc ^ data) & 0x01) ? (*crc >> 0x01) ^ 0x8C : (*crc >> 0x01); //рассчитываем значение
    data >>= 0x01; //сдвигаем буфер
  }
}
//------------------------Сравнение данных в памяти--------------------------------------------------
boolean checkDataMemory(uint8_t* str, uint8_t size, uint8_t cellCRC) //сравнение данных в памяти
{
  uint8_t crc = 0;
  for (uint8_t n = 0; n < size; n++) _check_crc(&crc, str[n]);
  if (crc != EEPROM_ReadByte(cellCRC)) return 1;
  return 0;
}
//------------------------Проверка данных в памяти--------------------------------------------------
boolean checkData(uint8_t size, uint8_t cell, uint8_t cellCRC) //проверка данных в памяти
{
  uint8_t crc = 0;
  for (uint8_t n = 0; n < size; n++) _check_crc(&crc, EEPROM_ReadByte(cell + n));
  if (crc != EEPROM_ReadByte(cellCRC)) return 1;
  return 0;
}
//------------------------Обновление данных в памяти--------------------------------------------------
void updateData(uint8_t* str, uint8_t size, uint8_t cell, uint8_t cellCRC) //обновление данных в памяти
{
  uint8_t crc = 0;
  for (uint8_t n = 0; n < size; n++) _check_crc(&crc, str[n]);
  EEPROM_UpdateBlock((uint16_t)str, cell, size);
  EEPROM_UpdateByte(cellCRC, crc);
}
//-----------------------------------Чтение журнала byte---------------------------------
uint8_t _logbook_read_byte(uint8_t byte_num) //чтение журнала byte
{
  return logbook_info_buff[byte_num]; //возвращаем запрошенные данные
}
//-----------------------------------Чтение журнала dword---------------------------------
uint32_t _logbook_read_dword(uint8_t dword_num) //чтение журнала dword
{
  return logbook_data_buff[dword_num]; //возвращаем запрошенные данные
}
//------------------------------------Очистка журнала------------------------------------------------------
void _logbook_data_clear(void) //очистка журнала
{
  EEPROM_ClearBlock(EEPROM_BLOCK_LOGBOOK_INFO, EEPROM_SIZE_LOGBOOK_INFO * 4); //стирание блока заглавлений в EEPROM
}
//--------------------------------------Чтение журнала--------------------------------------------------------
void _logbook_data_read(uint8_t data_num) //чтение журнала
{
  EEPROM_ReadBlock((uint16_t)&logbook_info_buff, (uint16_t)EEPROM_BLOCK_LOGBOOK_INFO + (data_num * EEPROM_SIZE_LOGBOOK_INFO), sizeof(logbook_info_buff)); //считываем информацию в буфер
  EEPROM_ReadBlock((uint16_t)&logbook_data_buff, (uint16_t)EEPROM_BLOCK_LOGBOOK_DATA + (data_num * EEPROM_SIZE_LOGBOOK_DATA), sizeof(logbook_data_buff)); //считываем информацию в буфер
}
//------------------------------------Обновление журнала------------------------------------------------------
void _logbook_data_update(uint8_t data_num, uint8_t num, uint32_t data) //обновление журнала
{
  uint16_t byte_data = (uint16_t)EEPROM_BLOCK_LOGBOOK_INFO + (data_num * EEPROM_SIZE_LOGBOOK_INFO); //находим запрашиваемую позицию
  uint16_t dword_data = (uint16_t)EEPROM_BLOCK_LOGBOOK_DATA + (data_num * EEPROM_SIZE_LOGBOOK_DATA); //находим запрашиваемую позицию

  EEPROM_ReadBlock((uint16_t)&logbook_info_buff, byte_data, sizeof(logbook_info_buff)); //считываем информацию во временный буфер
  EEPROM_ReadBlock((uint16_t)&logbook_data_buff, dword_data, sizeof(logbook_data_buff)); //считываем информацию во временный буфер

  for (uint8_t b = 9; b; b--) logbook_info_buff[b] = logbook_info_buff[b - 1]; //смещаяем информацию в буфере
  logbook_info_buff[0] = num; //добавляем в начало буфера новое значение
  for (uint8_t d = 9; d; d--) logbook_data_buff[d] = logbook_data_buff[d - 1]; //смещаяем информацию в буфере
  logbook_data_buff[0] = data; //добавляем в начало буфера новое значение

  EEPROM_UpdateBlock((uint16_t)&logbook_info_buff, byte_data, sizeof(logbook_info_buff)); //записываем в память временный буфер
  EEPROM_UpdateBlock((uint16_t)&logbook_data_buff, dword_data, sizeof(logbook_data_buff)); //записываем в память временный буфер
}
//---------------------------------------Стирание статистики--------------------------------------------------
void _statistic_erase(void) //стирание статистики
{
  cur_dose_cell = 0; //сбрасываем текущую ячейку
  EEPROM_ClearBlock(EEPROM_BLOCK_STATISTIC, EEPROM_SIZE_STATISTIC); //стирание блока заглавлений времени в EEPROM
}
//---------------------------------------Чтение статистики--------------------------------------------------
void statistic_read(void) //чтение статистики
{
  uint32_t maxData = 0; //максимальное значение ячейки
  uint32_t tempData = 0; //временный буфер данных
  for (uint8_t c = 0; c < (EEPROM_SIZE_STATISTIC / 4); c++) {
    uint16_t search_cell = EEPROM_BLOCK_STATISTIC + ((uint16_t)c * 4); //находим запрашиваемую позицию
    EEPROM_ReadBlock((uint16_t)&tempData, search_cell, sizeof(tempData));
    if (maxData < tempData) { //если буфер меньше ячейки
      maxData = tempData; //записываем в буфер значение ячейки
      cur_dose_cell = c; //устанавливаем последнюю ячейку
    }
    else break; //завершаем поиск
  }
  if (maxData) { //если в буфере есть информация
    uint16_t time_cell = EEPROM_BLOCK_STATISTIC + ((uint16_t)cur_dose_cell * 4); //находим запрашиваемую позицию
    EEPROM_ReadBlock((uint16_t)&tempData, time_cell, sizeof(tempData));
    time_save = tempData; //считываем время
    uint16_t dose_cell = (EEPROM_BLOCK_STATISTIC + EEPROM_SIZE_STATISTIC) + ((uint16_t)cur_dose_cell * 4); //находим запрашиваемую позицию
    EEPROM_ReadBlock((uint16_t)&tempData, dose_cell, sizeof(tempData));
    rad_dose_save = tempData; //считываем дозу
    if (++cur_dose_cell > ((EEPROM_SIZE_STATISTIC / 4) - 1)) cur_dose_cell = 0; //меняем ячейку
  }
}
//----------------------------------Обновление статистики------------------------------------------
void _statistic_update(void) //обновление статистики
{
  time_save += time_sec - time_save_old; //добавляем время
  time_save_old = time_sec; //сбрасывае счетчик времени
  rad_dose_save += rad_dose - rad_dose_old; //добавляем дозу
  rad_dose_old = rad_dose; //сбрасывае счетчик дозы

  uint16_t time_cell = EEPROM_BLOCK_STATISTIC + ((uint16_t)cur_dose_cell * 4); //находим запрашиваемую позицию
  EEPROM_UpdateBlock((uint16_t)&time_save, time_cell, sizeof(time_save)); //записываем время
  uint16_t dose_cell = (EEPROM_BLOCK_STATISTIC + EEPROM_SIZE_STATISTIC) + ((uint16_t)cur_dose_cell * 4); //находим запрашиваемую позицию
  EEPROM_UpdateBlock((uint16_t)&rad_dose_save, dose_cell, sizeof(rad_dose_save)); //записываем дозу
  if (++cur_dose_cell > ((EEPROM_SIZE_STATISTIC / 4) - 1)) cur_dose_cell = 0; //меняем ячейку
}
