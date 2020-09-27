Страница проекта ArDos http://arduino.ru/forum/proekty/delaem-dozimetr

Для сброса настроек необходимо зажать клавишу "ОК" и включить питание, появится сообщение об успешном сбросе.
  Если что-то идет или работает не так, в первую очередь пробуйте сброс настроек хот-кеем как описано выше!!!

  Не забудьте установить свои настройки ADC_value и k_delitel в файле SETUP, если вы не настраивали параметры утилитой ранее!!! Этот файл также можно сохранить отдельно и вставлять в новые версии программы.

  После выключения устройства при низком напряжении акб, включить его можно или передергиванием выключателя питания или зажать кнопку "OK" более чем на 2 сек.


  -Обозначения иконок-

  - Иконка "Динамик"
  Две скобки - звки клавиш и треск включен
  Горизонтальная волна - звук клвиш выключен, треск включен
  Звёздочка - звук клавиш включен, треск выключен
  Крестик - звук клавиш и треск выключены

  - Иконка "Колокольчик"
  Волна и две скобки - звки и вибрация при тревоге включены
  Две волны - звук тревоги выключен, вибрация включена
  Звёздочка - ожидание понижения фона
  Крестик - звки и вибрация при тревоге выключены


  -Действия клавиш-

  - На экране ФОН
  Вверх - следующий экран, удерж. - быстрое меню
  Вниз - предыдущий экран, удерж. - сброс показаний среднего и максимального фона(сбросить текущий фон и график/средн. и макс.)
  Ок - сбросить текущий фон(выбор - график или средн. и макс. фон), удерж. - настройки

  - На экране ДОЗА
  Вверх - следующий экран, удерж. - быстрое меню
  Вниз - предыдущий экран, удерж. - сброс показаний текущей дозы / дозы за все время
  Ок - смена подрежима(текущая доза / доза за все время), удерж. - настройки

  - На экране ПОИСК
  Вверх - следующий экран, удерж. - быстрое меню
  Вниз - предыдущий экран, удерж. - сброс графика и показателей
  Ок - пауза графика и показателей, удерж. - настройки

  - На экране БЕТА
  Вверх - остановить замер, удерж. - нет действия
  Вниз - остановить замер, удерж. - принудительный сброс при замере
  Ок - начать замер / следующий замер, удерж. - выход

  - На экране НАСТРОЙКИ
  Вверх - позиция выше/прибавить показания, удерж. - отладка(если выбрано настройками)
  Вниз - позиция ниже/убавить показания, удерж. - параметры(если выбрано настройками)
  Ок - перейти к настройкам/перйти к выбору позиции, удерж. - выход из настроек

  - На экране БЫСТРОЕ МЕНЮ
  Вверх - режим замера бета, удерж. - выход
  Вниз - подсветка экрана вкл/выкл, удерж. - нет действия
  Ок - фонарик вкл/выкл, удерж. - нет действия

  - На экранах ПАРАМЕТРЫ
  Вверх - нет действия, удерж. - нет действия
  Вниз - нет действия, удерж. - нет действия
  Ок - выход из статистики, удерж. - нет действия

  - На экране ОТЛАДКА
  Вверх - прибавить показания, удерж. - нет действия
  Вниз - убавить показания, удерж. - нет действия
  Ок - выбор позиции, удерж. - выход из debug menu

  - На экране ОШИБКА
  Вверх - выход, удерж. - нет действия
  Вниз - выход, удерж. - нет действия
  Ок - меню настроек импульса и опорного(отладка), удерж. - нет действия


  -Ошибки-

  - Сбой работы таймера
  Видимо что-то пошло не так и таймер не смог откалиброваться, зачастую проблема в напряжении питания и его источнике, попробуйте перезапустить от лбп с напряжением 5в.

  - Перегрузка преобразователя
  Преобразователь напряжения перегружен либо не правильно настроен, проверьте цепи преобразователя и установленные параметры ADC_value / k_delitel / puls.

  - Короткое замыкание преобразователя
  Короткое замыкание преобразователя напряжения либо не правильно настроен, проверьте цепи преобразователя и установленные параметры ADC_value / k_delitel / puls.
  
  - Нет счета
  Отсутствуют импульсы от счетчика, проверьте цепи подключения счетчика, сам счетчик или преобразователь.
