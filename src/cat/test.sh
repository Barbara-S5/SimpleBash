#!/bin/bash

touch test.txt
echo "
 








	
























" > test.txt
touch test2.txt
echo "

1
2
3
4
5
6
7
8
9
0



Hello wolrld
hello wolrld
HELLO WORLD?" > test2.txt
touch s21.txt
touch cat.txt

echo "1"
echo "test.txt"
./s21_cat test.txt > s21.txt
cat test.txt > cat.txt
diff s21.txt cat.txt
if [ $? -eq 0 ]; then
echo "Correct"
else
echo "N/A"
fi

echo "2"
echo "-b test.txt"
./s21_cat -b test.txt > s21.txt
cat -b test.txt > cat.txt
diff s21.txt cat.txt
if [ $? -eq 0 ]; then
echo "Correct"
else
echo "N/A"
fi

echo "3"
echo "-e test.txt"
./s21_cat -e test.txt > s21.txt
cat -e test.txt > cat.txt
diff s21.txt cat.txt
if [ $? -eq 0 ]; then
echo "Correct"
else
echo "N/A"
fi

echo "4"
echo "-n test.txt"
./s21_cat -n test.txt > s21.txt
cat -n test.txt > cat.txt
diff s21.txt cat.txt
if [ $? -eq 0 ]; then
echo "Correct"
else
echo "N/A"
fi

echo "5"
echo "-s test.txt"
./s21_cat -s test.txt > s21.txt
cat -s test.txt > cat.txt
diff s21.txt cat.txt
if [ $? -eq 0 ]; then
echo "Correct"
else
echo "N/A"
fi

echo "6"
echo "-t test.txt"
./s21_cat -t test.txt > s21.txt
cat -t test.txt > cat.txt
diff s21.txt cat.txt
if [ $? -eq 0 ]; then
echo "Correct"
else
echo "N/A"
fi

echo "7 тесты с двумя файлами"
echo "test.txt test2.txt"
./s21_cat test.txt test2.txt > s21.txt
cat test.txt test2.txt > cat.txt
diff s21.txt cat.txt
if [ $? -eq 0 ]; then
echo "Correct"
else
echo "N/A"
fi

echo "8"
echo "-b test.txt test2.txt"
./s21_cat -b test.txt test2.txt > s21.txt
cat -b test.txt test2.txt > cat.txt
diff s21.txt cat.txt
if [ $? -eq 0 ]; then
echo "Correct"
else
echo "N/A"
fi

echo "9"
echo "-e test.txt test2.txt"
./s21_cat -e test.txt test2.txt > s21.txt
cat -e test.txt test2.txt > cat.txt
diff s21.txt cat.txt
if [ $? -eq 0 ]; then
echo "Correct"
else
echo "N/A"
fi

echo "10"
echo "-n test.txt test2.txt"
./s21_cat -n test.txt test2.txt > s21.txt
cat -n test.txt test2.txt > cat.txt
diff s21.txt cat.txt
if [ $? -eq 0 ]; then
echo "Correct"
else
echo "N/A"
fi

echo "11"
echo "-s test.txt test2.txt"
./s21_cat -s test.txt test2.txt > s21.txt
cat -s test.txt test2.txt > cat.txt
diff s21.txt cat.txt
if [ $? -eq 0 ]; then
echo "Correct"
else
echo "N/A"
fi

echo "12"
echo "-t test.txt test2.txt"
./s21_cat -t test.txt test2.txt > s21.txt
cat -t test.txt test2.txt > cat.txt
diff s21.txt cat.txt
if [ $? -eq 0 ]; then
echo "Correct"
else
echo "N/A"
fi