#!/bin/bash
echo "Введите последовательность целых чисел, оканчивающуюся нулем,"
echo "а я выведу сумму этих чисел"
echo -n "Введите число: "
# Считываем число, с которого начинается последвоательность
read x
# 
s=0 
# пока текущее число не равно нулю
while [ $x -ne 0 ]
do
# добавляем к сумме текущее число
    s=$(($s+$x))
    echo -n "Введите число: "
    # считываем следующее число в последовательности
    read x
done
# выводим итоговую сумму
echo "Итоговая сумма равна $s"

