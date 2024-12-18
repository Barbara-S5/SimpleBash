CC=gcc
CFLAGS=-std=c11 -Wall -Werror -Wextra 
GREP=../grep/
COM=../common/

grep: main

main: s21_grep.o com_line_fun.o
	$(CC) $(CFLAGS) s21_grep.o com_line_fun.o -o $(GREP)s21_grep

s21_grep.o: $(GREP)s21_grep.c $(GREP)s21_grep.h $(COM)com_line_fun.h
	$(CC) $(CFLAGS) -c s21_grep.c

com_line_fun.o: $(COM)com_line_fun.c $(COM)com_line_fun.h
	$(CC) $(CFLAGS) -c $(COM)com_line_fun.c 

clean: 
	rm -rf *.o $(GREP)s21_grep

rebuild: clean grep 