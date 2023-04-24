Отчет по домашнему заданию 10 
по дисциплине "Операционные системы"
Владимиров Дмитрий Андреевич, БПИ218

Исходный код лежит в файликах sender.c и receiver.c

Запускать необходимо обе программы одновременно (я делал
это в двух терминалах рядом). Сначала устанавливается
соединение (то есть необходимо сообщить каждой программе
айдишник той с которой нужно взаимодействовать). Это делается
просто, каждая программа выводит свой и запрашивает соседний, 
который нужно ввести в предлагаемое поле. После чего происходит
непосредственно обмен данными при помощи сигналов SIGUSR1 и SIGUSR2.
Завершается все тем, что программа-отправитель посылает сигнал об
окончании сообщения, после чего программа-получатель выводит на экран 
переданное число и завершает свою работу.

Примеры прогона трех подряд запусков:

Первый терминал (программа-отправитель)

vladimirovdma-x:sem10 vladimirovdma$ gcc sender.c -o sender
vladimirovdma-x:sem10 vladimirovdma$ ./sender 
Sender pid: 5375
Input receiver pid: 5376
Input decimal integer: 23
vladimirovdma-x:sem10 vladimirovdma$ ./sender 
Sender pid: 5384
Input receiver pid: 5385
Input decimal integer: -23
vladimirovdma-x:sem10 vladimirovdma$ ./sender 
Sender pid: 5386
Input receiver pid: 5387
Input decimal integer: 111111111

----------------------------------------------------------------

Второй термнал (программа-получатель)

vladimirovdma-x:sem10 vladimirovdma$ gcc receiver.c -o receiver
vladimirovdma-x:sem10 vladimirovdma$ ./receiver
Receiver pid: 5376
Input sender pid: 5375
got 23
vladimirovdma-x:sem10 vladimirovdma$ ./receiver
Receiver pid: 5385
Input sender pid: 5384
got -23
vladimirovdma-x:sem10 vladimirovdma$ ./receiver
Receiver pid: 5387
Input sender pid: 5386
got 111111111