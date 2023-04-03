Отчет по домашнему заданию к семинару 8 
по дисциплине "Операционные системы"
Владимиров Дмитрий Андреевич, БПИ218

программа из презентации у меня не заработал,
поэтому написал свою с кольцевым буфером.

исходный код лежит в файлах writer.c и 
reader.c

задумка: writer.c принимает в качестве аргумента
входной текст, далее по 5 символов записывает его в файл буфера,
а программа reader.c считывает эти данные оттуда

входной текст нужно вводить одним словом
через аргумент к программе writer

да, логичнее было бы передавать через аргументы имя 
файла и считывать какой-то текст оттуда, но я это 
поздно понял и кажется это не главное для того чтобы
правильно воспользоваться семафорами для имитации
кольцевого буфера

пример работы программы:
avo@avo-Yoga-Slim-7-14IIL05:~/OS/sem6/OS/sem8$ gcc writer.c -o writer
avo@avo-Yoga-Slim-7-14IIL05:~/OS/sem6/OS/sem8$ gcc reader.c -o reader
avo@avo-Yoga-Slim-7-14IIL05:~/OS/sem6/OS/sem8$ ./writer LondonIsTheCapitalOfGreatBritain & ./reader 
[1] 6668
Writer wrote Londo
Reader read Londo
Writer wrote nIsTh
Reader read nIsTh
Writer wrote eCapi
Reader read eCapi
Writer wrote talOf
Reader read talOf
Writer wrote Great
Reader read Great
Writer wrote Brita
Reader read Brita
Writer wrote in
Reader read in

all operations done
[1]+  Done                    ./writer LondonIsTheCapitalOfGreatBritain

также приведу пример с угловым случаем,
где длина входного текста кратна 5

avo@avo-Yoga-Slim-7-14IIL05:~/OS/sem6/OS/sem8$ ./writer londo & ./reader
[1] 7000
Writer wrote londo
Reader read londo

all operations done
[1]+  Done                    ./writer londo

отмечу, что семафоры закрываются и корректно удаляются
при помощи команды unlink
