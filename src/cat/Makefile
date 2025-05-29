CC=gcc
CFLAGS=-std=c11 -Wall -Werror -Wextra
CAT=../cat/

cat: main

main: s21_cat.o pars_line_fun.o
	$(CC) $(CFLAGS) s21_cat.o pars_line_fun.o -o $(CAT)s21_cat

s21_cat.o: $(CAT)s21_cat.c $(CAT)s21_cat.h $(CAT)pars_line_fun.h
	$(CC) $(CFLAGS) -c s21_cat.c

pars_line_fun.o: $(CAT)pars_line_fun.c $(CAT)pars_line_fun.h
	$(CC) $(CFLAGS) -c $(CAT)pars_line_fun.c 

clean: 
	rm -rf *.o $(CAT)s21_cat

rebuild: clean cat
