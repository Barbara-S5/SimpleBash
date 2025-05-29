CC=gcc
CFLAGS=-std=c11 -Wall -Werror -Wextra 
GREP=../grep/
COM=../common/

grep: main

main: s21_grep.o
	$(CC) $(CFLAGS) s21_grep.o -o $(GREP)s21_grep

s21_grep.o: $(GREP)s21_grep.c $(GREP)s21_grep.h
	$(CC) $(CFLAGS) -c s21_grep.c

clean: 
	rm -rf *.o $(GREP)s21_grep

rebuild: clean grep 