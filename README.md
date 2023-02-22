# OS
Домашнее задание по семинару 5
Владимиров Дмитрий Андреевич, БПИ218

Взаимодействие двух программ по именованным каналам предполагается следующим образом:
Пользователь задает вопрос первой программе, она отправляет его в буфер, после чего 
вторая программа считывает этот вопрос из буфера, показывает его пользователю, получает
от него ответ, который точно так же прокидывается первой программе обратно. 
Так происходит, пока обе программы не закончат свою работу через ^C.

Примечание: реализован так же ввод через аргументы командной строки

Для тестирования лучше запускать разные программы из разных терминалов, вот демонстрация

Терминал 1:

avo@avo-Yoga-Slim-7-14IIL05:~/OS/sem5$ gcc hw1.c -o hw1
avo@avo-Yoga-Slim-7-14IIL05:~/OS/sem5$ ./hw1 buffer.fifo
What do you want to answer? How old are you?
Programm 2: Just a few seconds

What do you want to answer? How much would be 2 + 2?
Programm 2: 4

What do you want to answer? Who are you?
Programm 2: asdf

What do you want to answer? ^C
avo@avo-Yoga-Slim-7-14IIL05:~/OS/sem5$ 

--------------------------------------------------------------

Терминал 2:

avo@avo-Yoga-Slim-7-14IIL05:~/OS/sem5$ gcc hw2.c -o hw2
avo@avo-Yoga-Slim-7-14IIL05:~/OS/sem5$ ./hw2 buffer.fifo
User1: How old are you?

What can you answer? Just a few seconds
User1: How much would be 2 + 2?

What can you answer? 4
User1: Who are you?

What can you answer? asdf
^C
avo@avo-Yoga-Slim-7-14IIL05:~/OS/sem5$ ^C
