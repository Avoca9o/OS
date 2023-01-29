#!/bin/bash
echo -n "Enter two values and i will write the maximum of these two: "
# считывает входные данные, два числа
read a b
if [ $a -ge $b ] 
then
# если первое число оказалось больше либо равно второго, то выведем его
    echo "The maximum is $a"
else
# иначе выведем второе
    echo "The maximum is $b"
fi

