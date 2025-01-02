#define UART_BUFFER_SIZE 32 //размер буфера отправки данных(16..64)

char sendBuff[UART_BUFFER_SIZE]; //буфер отправки данных
uint8_t sendBuffStart; //начало передачи
uint8_t sendBuffEnd; //конец передачи
boolean sendBuffStatus; //состояние передачи

//---------------------------------Прерывание UART-------------------------------------
EMPTY_INTERRUPT(USART_TX_vect); //прерывание UART
//--------------------------------Инициализация UART-----------------------------------
void dataChannelInit(void) //инициализация UART
{
  PRR &= ~(0x01 << PRUSART0); //включаем питание UART
  UBRR0 = (F_CPU / (8UL * UART_BAUND)) - 1; //устанавливаем битрейт
  UCSR0A = (0x01 << U2X0); //устанавливаем удвоение скорости
  UCSR0B = (0x01 << TXEN0) | (0x01 << TXCIE0); //разрешаем передачу
  UCSR0C = ((0x01 << UCSZ01) | (0x01 << UCSZ00)); //длинна пакета 8бит
}
//----------------------------------Выключение UART-----------------------------------
void dataChannelEnd(void) //выключение UART
{
  UCSR0B = 0; //выключаем UART
  DDRD &= 0xFC; //устанавливаем пины как входы
  PORTD &= 0xFC; //устанавливаем пины в низкий уровень
  PRR |= (0x01 << PRUSART0); //включаем питание UART
}
//-----------------------------------Состояние UART-----------------------------------
boolean dataChannelState(void) //состояние UART
{
  return (PRR & (0x01 << PRUSART0)); //возвращаем состояние питания
}
//----------------------------------Обновление UART-----------------------------------
void dataChannelUpdate(void) //обновление UART
{
  if (sendBuffStatus && (UCSR0A & (0x01 << UDRE0))) { //ждем пока отправится байт
    UDR0 = sendBuff[sendBuffStart]; //записываем байт
    if (++sendBuffStart >= UART_BUFFER_SIZE) sendBuffStart = 0; //смещаем указатель
    if (sendBuffStart == sendBuffEnd) sendBuffStatus = 0; //завершаем передачу
  }
}
//-----------------------------Состояние отправки данных------------------------------
boolean sendCheck(void) //состояние отправки данных
{
  if (sendBuffStart != sendBuffEnd) { //если в буфере есть данные
    sendBuffStatus = 1; //разрешаем отправку
    return 1; //возвращаем состояние
  }
  return 0;
}
//---------------------------------Отправка символа-----------------------------------
void sendChar(char data) //отправка символа
{
  uint8_t temp = sendBuffEnd; //записали указатель
  if (++temp >= UART_BUFFER_SIZE) temp = 0; //сместили временный указатель
  if (temp != sendBuffStart) { //если буфер не перепонен
    sendBuff[sendBuffEnd] = data; //записали нанные
    sendBuffEnd = temp; //записали новый указатель
  }
}
//------------------------------Отправка конца строки---------------------------------
void sendEnd(void) //отправка конца строки
{
  const char buff[] = {'\0', '\r', '\n'}; //буфер конца строки
  for (uint8_t i = 0; i < sizeof(buff); i++) sendChar(buff[i]); //отправляем буфер конца строки
}
//-----------------------------------Отправка числа-----------------------------------
void sendNum(uint32_t num, char start, char end) //отправка числа
{
  boolean st = 0;
  uint8_t ch = 0;
  uint8_t cnt = 0;
  uint32_t tbl = 0;

  sendChar(start); //установили символ разделитель

  if (num) {
    while (cnt < 10) {
      ch = 0;
      tbl = pgm_read_dword(&div_table[cnt]);
      while ((num >= tbl) && (ch < 9)) {
        num -= tbl;
        ch += 1;
      }
      if (ch) st = 1;
      if (st) sendChar(ch + '0');
      cnt++;
    }
  }
  else sendChar('0');

  sendChar(end); //установили символ разделитель
}
