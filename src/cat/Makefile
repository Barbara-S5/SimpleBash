CC=gcc
CFLAGS=-std=c11 -Wall -Werror -Wextra
CAT=../cat/
COM=../common/

cat: main

main: s21_cat.o com_line_fun.o
	$(CC) $(CFLAGS) s21_cat.o com_line_fun.o -o $(CAT)s21_cat

s21_cat.o: $(CAT)s21_cat.c $(CAT)s21_cat.h $(COM)com_line_fun.h
	$(CC) $(CFLAGS) -c s21_cat.c

com_line_fun.o: $(COM)com_line_fun.c $(COM)com_line_fun.h
	$(CC) $(CFLAGS) -c $(COM)com_line_fun.c 

clean: 
	rm -rf *.o $(CAT)s21_cat

rebuild: clean cat
