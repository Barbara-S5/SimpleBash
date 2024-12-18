#ifndef SRC_GREP_S21_GREP_H
#define SRC_GREP_S21_GREP_H

#include <stdbool.h>

typedef struct flags
    strfl;  // Определим псевдиним strfl как имя типа struct flags

//--- Структуры данных --------------------------------------

struct flags {
  bool find_key;  // переменная указывающая  на наличие ключа
  //--- Добавим логические переменные - флаги действия ключей ----
  bool regexp_patterns;  // флаг применяемый с шаблонами -e
  bool ignore_case;      // Игнорировать регистр -i
  bool invert_match;  // исключая шаблон вывести строки в которых не найден
                      // шаблон -v
  bool count;  // вывести общее количество строк в которых есть совпадение -c
  bool files_with_matches;  // вывести названия фалов в которых есть совпадения
                            // -l
  bool line_number;  // печатать номер строки в файле перед выводом строки. -n
  bool no_file_name;  // -h печатает строки, без названия файлов
  bool no_messages;  //-s не песчатает сообщение об ошибке
  bool file;  // -f file берёт регулярныевыражения из файлов
  bool only_matching;  // -o Печатает только совпадающие непустые части
                       // совпавшей строки
  bool mistake;
  char pattern[100][100];
  int counter; //Передаётся колличество паттернов
  int count_dont_file; // Колличество аргументов но не файлов
  int compl; //колличество метчингов между файлом и строкой
  int another_file; // счётчик для ещё одного текстового файла
  int tot_str; // колличество всех строк файла
};

//--- Прототипы функций -------------------------------------
void parse_short_keys1(char *argv[], strfl *grep_flags, int i);
void pattern_e(int argc, char *argv[], strfl *grep_flags);
void pattern_f(int argc, char *argv[], strfl *grep_flags);
void read_file(char *argv[], int i, strfl *grep_flags);


// void message(char *argument);
// bool parse_short_keys(char *argv[], int inshkey, strfl *grep_flags);
// int r_pat_file(char *shablon, char *namefi, int count_num, strfl
// *grep_flags); void prt_buff(int count_num, char *buff, char *namefi, int
// in_str); void print_enter(char *buff); int f_fl_func(char *f_patt, char
// *ppat);

#endif