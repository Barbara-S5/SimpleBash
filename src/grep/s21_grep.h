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
                       // совпавшей строки.
  char pattern[100][100];
  int counter;
  int count_dont_file;
  int compl ;
  bool mistake;
  int another_file;
  int tot_str;
};

//--- Прототипы функций -------------------------------------
void parse_short_keys1(char *argv[], strfl *grep_flags, int i);
void pattern_e(int argc, char *argv[], strfl *grep_flags);
void pattern_f(int argc, char *argv[], strfl *grep_flags);
void read_file(char *argv[], int i, strfl *grep_flags);
void flag_n(strfl *grep_flags, int num_lne, char *argv[], int i, char *buff_r);
void flag_l(strfl *grep_flags, char *argv[], int i);
void flag_v(strfl *grep_flags, char *argv[], int i, char *buff_r);

#endif