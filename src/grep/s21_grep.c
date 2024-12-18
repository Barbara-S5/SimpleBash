#include "s21_grep.h"

#include <regex.h>
#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "../common/com_line_fun.h"

int main(int argc, char *argv[]) {
  strfl grep_flags = {0};
  for (int i = 1; i < argc; i++) {
    if (argv[i][0] == '-') {
      parse_short_keys1(argv, &grep_flags, i);
    }
  }
  if (grep_flags.regexp_patterns == true || grep_flags.file == true) {
    pattern_e(argc, argv, &grep_flags);
    pattern_f(argc, argv, &grep_flags);
    // несколько паттернов
  } else {
    for (int i = 1; i < argc; i++) {
      if (argv[i][0] != '-') {
        strcpy(grep_flags.pattern[0], argv[i]);
        grep_flags.counter = 1;
        grep_flags.count_dont_file++;
        i = argc;
      }
    }  //  один паттерн
  }
  for (int i = 1; i < argc; i++) {
    if (argv[i][0] != '-') {
      if (grep_flags.count_dont_file != 0) {
        grep_flags.count_dont_file--;
      } else if (!grep_flags.mistake) {
        if (i + 1 != argc) {
          grep_flags.another_file = 1;
        }
        read_file(argv, i, &grep_flags);
        // function of opening file
      }
    }
  }
  // Нужно среди флагов и паттернов найти файлы
  // чтоб их открыть
  return 0;
}

void parse_short_keys1(char *argv[], strfl *grep_flags, int i) {
  char getsymb;
  for (size_t j = 1; j < strlen(argv[i]); j++) {
    getsymb = argv[i][j];
    switch (getsymb) {
      case 'e':
        grep_flags->regexp_patterns = true;
        break;
      case 'i':
        grep_flags->ignore_case = true;
        break;
      case 'v':
        grep_flags->invert_match = true;
        break;
      case 'c':
        grep_flags->count = true;
        break;
      case 'l':
        grep_flags->files_with_matches = true;
        break;
      case 'n':
        grep_flags->line_number = true;
        break;
      case 'h':
        grep_flags->no_file_name = true;
        break;
      case 's':
        grep_flags->no_messages = true;
        break;
      case 'f':
        grep_flags->file = true;
        break;
      case 'o':
        grep_flags->only_matching = true;
        break;
      default:
        grep_flags->mistake = true;
        // if (!grep_flags->no_messages) {
        printf("n/a\n");
        break;
    }
  }
}

void pattern_e(int argc, char *argv[], strfl *grep_flags) {
  for (int i = 1; i < argc; i++) {
    if (argv[i][0] == '-') {
      if (strchr(argv[i], 'e')) {
        strcpy(grep_flags->pattern[grep_flags->counter], argv[i + 1]);
        grep_flags->counter++;
        grep_flags->count_dont_file++;
      }
    }
  }
}

void pattern_f(int argc, char *argv[], strfl *grep_flags) {
  char buff[1024];
  for (int i = 1; i < argc; i++) {
    if (argv[i][0] == '-' && strchr(argv[i], 'f')) {
      FILE *pat = fopen(argv[i + 1], "r");
      if (pat == NULL) {
        printf("n/a\n");
      } else {
        while (fgets(buff, 1024, pat) != NULL) {
          strcpy(grep_flags->pattern[grep_flags->counter], buff);
          int f = (strlen(grep_flags->pattern[grep_flags->counter]) - 1);  //
          char c = grep_flags->pattern[grep_flags->counter][f];
          c == '\n' ? grep_flags->pattern[grep_flags->counter][f] = '\0' : 0;
          grep_flags->counter++;
        }
        grep_flags->count_dont_file++;
        fclose(pat);
      }
    }
  }
}

void read_file(char *argv[], int i, strfl *grep_flags) {
  char buff_r[1024];
  int cflags = 0;
  int tls = 0;
  grep_flags->tot_str = 0;
  regex_t regexp;
  FILE *fpoint = fopen(argv[i], "r");
  if (fpoint == NULL) {
    printf("n/a\n");
  } else {
    if (grep_flags->ignore_case) {
      cflags = REG_ICASE;
    }  // условие при использовании флага i
    while (fgets(buff_r, 1024, fpoint) != NULL) {
      for (int p = 0; p < grep_flags->counter; p++) {
        if (regcomp(&regexp, grep_flags->pattern[p], cflags) == 0) {
          if (regexec(&regexp, buff_r, 0, NULL, cflags) == 0) {
            grep_flags->compl = 1;
          }
          regfree(&regexp);//построчное чтение файла и компиляция паттернов и их мэтчинг
        }
      }
      if (grep_flags->compl != 0 && !grep_flags->invert_match) {
        if (grep_flags->count == 1) {
          grep_flags->tot_str++;
          grep_flags->compl = 0;
        } else {
          if (grep_flags->another_file == 1) {
            printf("%s:%d", argv[i], grep_flags->tot_str);
            grep_flags->compl = 0;
          } else {
            printf("%d", grep_flags->tot_str);
            grep_flags->compl = 0;
          }
        }
      }

      if (grep_flags->invert_match && grep_flags->compl == 0) {
        if (grep_flags->another_file == 1) {
          printf("%s:%s", argv[i], buff_r);
        } else {
          printf("%s", buff_r);
          grep_flags->compl = 0;
        }
        } else {
      // if (grep_flags->count) {
      //   if (grep_flags->another_file == 1) {
      //     printf("%s:%d", argv[i], grep_flags->tot_str);
      //   } else {
      //     printf("%d", grep_flags->tot_str);
      //   }
        grep_flags->compl = 0;
          }  // флаг v

      if (grep_flags->count && grep_flags->compl != 0) {
        if (grep_flags->another_file == 1) {
          printf("%s:", argv[i]);
        }
      }
    }
    if (grep_flags->count == 1) { // функция флага c
      if (grep_flags->another_file == 1) {
        printf("%s:%d\n", argv[i], grep_flags->tot_str);
        grep_flags->compl = 0;
      } else {
        printf("%d\n", grep_flags->tot_str);
        grep_flags->compl = 0;
      } 
    }

    if (grep_flags->files_with_matches && !grep_flags->invert_match && grep_flags->compl == 0){
      printf("%s\n", argv[i]);
    }

    if (grep_flags->line_number && grep_flags->compl != 0){
      tls = grep_flags->tot_str;
      if (tls != 0) printf("%d:", tls);
    }

    if (grep_flags->only_matching) {
      if (grep_flags->another_file == 1) {
        printf("%s:", argv[i]);
              if (grep_flags->tot_str != 0) printf("%d:", grep_flags->tot_str);
            }
            printf("%.*s", (int) (match.rm_eo - match.rm_so),
                   buff_r + match.rm_so);
            printf("\n");

    }
  }
  
    fclose(fpoint);
  }

// принимаешь имя файла
// принимаешь структуру
// открываешь файл
// запускаешь цикл строк
// в этом цикле на одну строку, компилируешь все паттерны на 1 строку
