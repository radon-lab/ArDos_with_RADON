#if USE_UART
//----------------------------------Инициализация UART----------------------------------
void dataChannelInit(void) //инициализация UART
{
  PRR &= ~(0x01 << 1); //включаем питание UART
  UBRR0 = (F_CPU / (8UL * UART_BAUND)) - 1; //устанавливаем битрейт
  UCSR0A = (0x01 << U2X0); //устанавливаем удвоение скорости
  UCSR0B = ((0x01 << TXEN0)); //разрешаем передачу
  UCSR0C = ((0x01 << UCSZ01) | (0x01 << UCSZ00)); //длинна пакета 8бит
}
//----------------------------------Выключение UART----------------------------------
void dataChannelEnd(void) //выключение UART
{
  UCSR0B = 0; //выключаем UART
  PRR |= (0x01 << 1); //включаем питание UART
}
//----------------------------------Отправка команды----------------------------------
void sendNumI(uint32_t num) //отправка команды
{
  char buf[15];
  uint8_t c = 0;

  buf[c++] = '\n'; //перевод строки
  buf[c++] = '\r'; //установка курсора в начало строки
  buf[c++] = '\0'; //конец строки

  if (num) {
    while (num > 0) {
      buf[c++] = 48 + (num % 10);
      num = (num - (num % 10)) / 10;
    }
  }
  else buf[c++] = 48;

  while (c) {
    while (!(UCSR0A & (1 << UDRE0)));
    UDR0 = buf[--c];
  }
}
#endif
