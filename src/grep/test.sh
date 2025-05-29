#!/bin/bash
touch test.txt
echo -e "
aslj                        dhf

askjdhas hello   aksjhd kja  hello         hsd hello



sap ok      j   -was                

				askjdhas aksjhd

bb     -e         
v .hello asd asd hello


s s d q -e
one
two
three

test.txt


" > test.txt
touch test2.txt
echo -e "1
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
touch grep.txt
echo "1"
echo "hello test.txt"
./s21_grep "hello" test.txt > s21.txt
grep "hello" test.txt > grep.txt
diff s21.txt grep.txt
if [ $? -eq 0 ]; then
echo "Cool"
else
echo "Unluck"
fi
echo "2"
echo "hello test.txt test2.txt"
./s21_grep "hello" test.txt test2.txt > s21.txt
grep "hello" test.txt test2.txt > grep.txt
diff s21.txt grep.txt
if [ $? -eq 0 ]; then
echo "Cool"
else
echo "Unluck"
fi


echo "3"
echo "hello test.txt"
./s21_grep "hello" test.txt > s21.txt
grep "hello" test.txt > grep.txt
diff s21.txt grep.txt
if [ $? -eq 0 ]; then
echo "Cool"
else
echo "Unluck"
fi
echo "4"
echo "-e hello test.txt"
./s21_grep -e "hello" test.txt > s21.txt
grep -e "hello" test.txt > grep.txt
diff s21.txt grep.txt
if [ $? -eq 0 ]; then
echo "Cool"
else
echo "Unluck"
fi
echo "5"
echo "-e hello -e wo test.txt"
./s21_grep -e "hello" -e "wo" test.txt > s21.txt
grep -e "hello" -e "wo" test.txt > grep.txt
diff s21.txt grep.txt
if [ $? -eq 0 ]; then
echo "Cool"
else
echo "Unluck"
fi
echo "6"
echo "-i Hello test.txt"
./s21_grep -i "Hello" test.txt > s21.txt
grep -i "Hello" test.txt > grep.txt
diff s21.txt grep.txt
if [ $? -eq 0 ]; then
echo "Cool"
else
echo "Unluck"
fi
echo "7"
echo "-v hello test.txt"
./s21_grep -v "hello" test.txt > s21.txt
grep -v "hello" test.txt > grep.txt
diff s21.txt grep.txt
if [ $? -eq 0 ]; then
echo "Cool"
else
echo "Unluck"
fi
echo "8"
echo "-c hello test.txt"
./s21_grep -c "hello" test.txt > s21.txt
grep -c "hello" test.txt > grep.txt
diff s21.txt grep.txt
if [ $? -eq 0 ]; then
echo "Cool"
else
echo "Unluck"
fi
echo "9"
echo "-l hello test.txt"
./s21_grep -l "hello" test.txt > s21.txt
grep -l "hello" test.txt > grep.txt
diff s21.txt grep.txt
if [ $? -eq 0 ]; then
echo "Cool"
else
echo "Unluck"
fi
echo "10"
echo "-n hello test.txt"
./s21_grep -n "hello" test.txt > s21.txt
grep -n "hello" test.txt > grep.txt
diff s21.txt grep.txt
if [ $? -eq 0 ]; then
echo "Cool"
else
echo "Unluck"
fi
echo "11"
echo "-h hello test.txt"
./s21_grep -h "hello" test.txt > s21.txt
grep -h "hello" test.txt > grep.txt
diff s21.txt grep.txt
if [ $? -eq 0 ]; then
echo "Cool"
else
echo "Unluck"
fi
echo "12"
echo "-s hello test.txt"
./s21_grep -s "hello" test.tx > s21.txt
grep -s "hello" test.tx > grep.txt
diff s21.txt grep.txt
if [ $? -eq 0 ]; then
echo "Cool"
else
echo "Unluck"
fi
echo "13"
echo "-f test2.txt test.txt"
./s21_grep -f "test2.txt" test.txt > s21.txt
grep -f "test2.txt" test.txt > grep.txt
diff s21.txt grep.txt
if [ $? -eq 0 ]; then
echo "Cool"
else
echo "Unluck"
fi
echo "14 Тесты с двумя файлами"
echo "-e hello test.txt test2.txt"
./s21_grep -e "hello" test.txt test2.txt > s21.txt
grep -e "hello" test.txt test2.txt > grep.txt
diff s21.txt grep.txt
if [ $? -eq 0 ]; then
echo "Cool"
else
echo "Unluck"
fi
echo "15"
echo "-i Hello test.txt test2.txt"
./s21_grep -i "Hello" test.txt test2.txt > s21.txt
grep -i "Hello" test.txt test2.txt > grep.txt
diff s21.txt grep.txt
if [ $? -eq 0 ]; then
echo "Cool"
else
echo "Unluck"
fi
echo "16"
echo "-v hello test.txt test2.txt"
./s21_grep -v "hello" test.txt test2.txt > s21.txt
grep -v "hello" test.txt test2.txt > grep.txt
diff s21.txt grep.txt
if [ $? -eq 0 ]; then
echo "Cool"
else
echo "Unluck"
fi
echo "17"
echo "-c hello test.txt test2.txt"
./s21_grep -c "hello" test.txt test2.txt > s21.txt
grep -c "hello" test.txt test2.txt > grep.txt
diff s21.txt grep.txt
if [ $? -eq 0 ]; then
echo "Cool"
else
echo "Unluck"
fi
echo "18"
echo "-l hello test.txt test2.txt"
./s21_grep -l "hello" test.txt test2.txt > s21.txt
grep -l "hello" test.txt test2.txt > grep.txt
diff s21.txt grep.txt
if [ $? -eq 0 ]; then
echo "Cool"
else
echo "Unluck"
fi
echo "19"
echo "-n hello test.txt test2.txt"
./s21_grep -n "hello" test.txt test2.txt > s21.txt
grep -n "hello" test.txt test2.txt > grep.txt
diff s21.txt grep.txt
if [ $? -eq 0 ]; then
echo "Cool"
else
echo "Unluck"
fi
echo "20"
echo "-h hello test.txt test2.txt"
./s21_grep -h "hello" test.txt test2.txt > s21.txt
grep -h "hello" test.txt test2.txt > grep.txt
diff s21.txt grep.txt
if [ $? -eq 0 ]; then
echo "Cool"
else
echo "Unluck"
fi
echo "21"
echo "-s hello test.tx test2.txt"
./s21_grep -s "hello" test.tx test2.txt > s21.txt
grep -s "hello" test.tx test2.txt > grep.txt
diff s21.txt grep.txt
if [ $? -eq 0 ]; then
echo "Cool"
else
echo "Unluck"
fi
echo "22"
echo "-f test2.txt test.txt test2.txt"
./s21_grep -f "test2.txt" test.txt test2.txt > s21.txt
grep -f "test2.txt" test.txt test2.txt > grep.txt
diff s21.txt grep.txt
if [ $? -eq 0 ]; then
echo "Cool"
else
echo "Unluck"
fi
echo "23 Тесты комбинаций"
echo "-i -e hello test.txt"
./s21_grep -i -e "hello" test.txt > s21.txt
grep -i -e "hello" test.txt > grep.txt
diff s21.txt grep.txt
if [ $? -eq 0 ]; then
echo "Cool"
else
echo "Unluck"
fi
echo "24"
echo "-v -c hello test.txt"
./s21_grep -v -c "hello" test.txt > s21.txt
grep -v -c "hello" test.txt > grep.txt
diff s21.txt grep.txt
if [ $? -eq 0 ]; then
echo "Cool"
else
echo "Unluck"
fi
echo "25"
echo "-l -n hello test.txt"
./s21_grep -l -n "hello" test.txt > s21.txt
grep -l -n "hello" test.txt > grep.txt
diff s21.txt grep.txt
if [ $? -eq 0 ]; then
echo "Cool"
else
echo "Unluck"
fi
echo "26"
echo "-v -i hello test.txt"
./s21_grep -v -i "hello" test.txt > s21.txt
grep -v -i "hello" test.txt > grep.txt
diff s21.txt grep.txt
if [ $? -eq 0 ]; then
echo "Cool"
else
echo "Unluck"
fi
echo "27"
echo "-c -n hello test.txt"
./s21_grep -c -n "hello" test.txt > s21.txt
grep -c -n "hello" test.txt > grep.txt
diff s21.txt grep.txt
if [ $? -eq 0 ]; then
echo "Cool"
else
echo "Unluck"
fi
echo "28"
echo "-l -c hello test.txt"
./s21_grep -l -c "hello" test.txt > s21.txt
grep -l -c "hello" test.txt > grep.txt
diff s21.txt grep.txt
if [ $? -eq 0 ]; then
echo "Cool"
else
echo "Unluck"
fi
echo "29"
echo "-e hello -e 1 test.txt"
./s21_grep -e "hello" -e 1 test.txt > s21.txt
grep -e "hello" -e 1 test.txt > grep.txt
diff s21.txt grep.txt
if [ $? -eq 0 ]; then
echo "Cool"
else
echo "Unluck"
fi
echo "30"
echo "-i -n hello test.txt"
./s21_grep -i -n "hello" test.txt > s21.txt
grep -i -n "hello" test.txt > grep.txt
diff s21.txt grep.txt
if [ $? -eq 0 ]; then
echo "Cool"
else
echo "Unluck"
fi



