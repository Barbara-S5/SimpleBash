#ifndef SRC_CAT_S21_CAT_H
#define SRC_CAT_S21_CAT_H

#include <stdbool.h>

typedef struct flags {
  bool find_key;

  //--- Добавим логические переменные - флаги действия ключей ----
  bool number_nonblank;  // флаг применения только к непустым строкам
  bool number;    // нумеровать строки
  bool show_end;  // отображать символ конца строки
  bool show_nonprinting;  // отображать ^M там, где есть невидимые символы или
                          // Табы
  bool show_tabs;         // отображать Табы как ^I
  bool squeeze_blank;  // сжимать смежные пустые строки
} strfl;

void rpcat();
bool parse_long_keys(char *argv[], int *inlngkey, int *count_num, strfl *flags);
bool parse_short_keys(char *argv[], int *inshkey, int *count_num, strfl *flags);

int io_file(char *namefi, strfl *flags);

#endif
