Отчет по домашнему заданию 9
по дисциплине "Операционные системы"
Владимиров Дмитрий, БПИ218

Задача: реализовать для родительского
и дочернего процесса двухстороннюю связь с использованием
только одного неименованного канала и циклической организацией 
обмена посредством семафора (используя семафоры из unix system v)


Идея:
10 раз происходит следующая последовательность:
- родительский поток ждет открытия семафора писателя, а 
дочерний поток ждет открытия семафора читателя (изначально
семафор писателя равен 1, а читателя - 0)
- родительский поток уменьшает значение семафора писателя,
записывает в канал рандомно сгенерированное число, после чего
увеличивает семафор читателя. 
- дочерний поток после увеличения семафора читателя родительским
потоком начинает свою работу. А именно он считывает из канала
сгенерированное родительским поток число, выводим его в консоль,
после чего увеличивает семафор писателя и умирает

исходный код лежит в файле main.c

пример работы программы:

avo@avo-Yoga-Slim-7-14IIL05:~/OS/sem9$ ./a.out 
Parent wrote 5
Reader read 5
Parent wrote 5
Reader read 5
Parent wrote 8
Reader read 8
Parent wrote 5
Reader read 5
Parent wrote 8
Reader read 8
Parent wrote 4
Reader read 4
Parent wrote 5
Reader read 5
Parent wrote 3
Reader read 3
Parent wrote 7
Reader read 7
Parent wrote 3
Reader read 3
The end

