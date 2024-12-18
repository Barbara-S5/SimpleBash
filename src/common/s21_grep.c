#include "s21_grep.h"
#include <regex.h>
#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "../common/com_line_fun.h"

int main(int argc, char *argv[]) {
  int inshkey[16];  // Массив для записи порядковых номеров коротких ключей
  int inlngkey[16];  // Массив для записи порядковых номеров длинных ключей
  int infile[16];  // Массив для записи порядковых номеров входящих файлов
  int count_num[3] = {0, 0, 0};  // массив для хранения колличества найденных

  strfl grep_flags = {false};
  if (argc == 1) {
    printf("n/a\n");
    return 1;
  }
  grep_flags.find_key =
      parse_arg(argc, argv, inshkey, inlngkey, infile, count_num);
  if (count_num[0] != 0) {
    for (int ish = 0; ish < count_num[0]; ish++) {
      parse_short_keys(argv, inshkey[ish],
                       &grep_flags);  // функция которая работает с флагами
    }
  }
  for (int i = 1; i < count_num[2]; i++) {
    r_pat_file(argv[infile[0]], argv[infile[i]], count_num[2], &grep_flags);
  }
  return 0;
}

int r_pat_file(char *shablon, char *namefi, int count_num, strfl *grep_flags) {
  char buff[128] = {""};
  char pattern[512] = {""};
  char ppat[512] = {""};
  regex_t regexp;
  regmatch_t match;
  int reg = 0;
  int tot_str = 0;
  int cflags = 0;
  int in_str_tmp = 0;
  int al_str_fi = 0;
  strcpy(pattern, shablon);
  if (grep_flags->ignore_case) {
    cflags = REG_ICASE;
  }
  // } else if (grep_flags->file) {
  //   if (f_fl_func(shablon, ppat) != 0) { //ЭТО ВЫКЛЮЧИЛ ЕГОР
  //     return 1;
  //   }
  // cflags = REG_EXTENDED;
  // strcpy(pattern, ppat);
  // } else {
  //   cflags = 0;
  // }

  reg = regcomp(&regexp, pattern, cflags);

  FILE *point = fopen(namefi, "r");
  if (point == NULL) {
    if (!grep_flags->no_messages) {
      printf("n/a\n");
      return 1;
    }
    // if (grep_flags->regexp_patterns) {
    // prt_buff(count_num, buff, namefi, 0);
  } else {
    while (fgets(buff, sizeof(buff), point)) {
      al_str_fi++;
      reg = regexec(&regexp, buff, 1, &match, 0);
      if (reg == 0) {
        tot_str++;
        if (!grep_flags->invert_match && !grep_flags->count &&
            !grep_flags->files_with_matches) {
          if (grep_flags->line_number) {
            in_str_tmp = al_str_fi;
          }
          if (grep_flags->no_file_name) {
            count_num = 2;
          }
          if (grep_flags->only_matching) {
            if (count_num > 2) {
              printf("%s:", namefi);
              if (al_str_fi != 0) printf("%d:", al_str_fi);
            }
            printf("%.*s", (int)(match.rm_eo - match.rm_so),
                   buff + match.rm_so);
            printf("\n");
          } else {
            prt_buff(count_num, buff, namefi, in_str_tmp);
          }
        }
      } else if (reg == REG_NOMATCH) {
        if (grep_flags->invert_match) {
          prt_buff(count_num, buff, namefi, 0);
        }
      }
    }
    if (grep_flags->file && count_num >= 2) {
      printf("Я зашёл\n");
      f_fl_func(shablon, ppat);
      prt_buff(count_num, buff, namefi, in_str_tmp);
    }
    if (grep_flags->files_with_matches && tot_str > 0) {
      printf("%s", namefi);
      if (EOF != '\n') printf("\n");
      // print_enter(buff);
    }
    if (grep_flags->count) {
      if (count_num > 2) {
        printf("%s", namefi);
        printf(":");
      }
      printf("%d", tot_str);
      if (EOF != '\n') printf("\n");
    }
    // if (EOF != '\n') printf("\n");  //---!надо понаблюдать
  }
  regfree(&regexp);
  fclose(point);
  return 0;
}

int f_fl_func(char *f_patt, char *ppat) {
  char p_buff[124];
  ppat[0] = '(';
  int st_len;
  FILE *pat_point = fopen(f_patt, "r");
  if (pat_point == NULL) {
    printf("n/a\n");
    return 1;
  } else {
    while (fgets(p_buff, sizeof(p_buff), pat_point)) {
      st_len = strlen(p_buff);
      st_len--;
      if (p_buff[st_len] == '\n') {
        p_buff[st_len] = '|';
      }
      strcat(ppat, p_buff);
    }
    strcat(ppat, ")");
    printf("%s", ppat);
    fclose(pat_point);
  }
  return 0;
}

void prt_buff(int count_num, char *buff, char *namefi, int in_str) {
  if (count_num > 2) {
    printf("%s:", namefi);
  }
  if (in_str != 0) printf("%d:", in_str);
  printf("%s", buff);
  print_enter(buff);
}

void print_enter(char *buff) {
  int vrem_c = strlen(buff);
  vrem_c--;
  if (buff[vrem_c] != '\n') {
    printf("\n");
  }
}

// работаем с короткими ключами
bool parse_short_keys(char *argv[], int inshkey, strfl *grep_flags) {
  char getsymb;
  for (size_t j = 1; j < strlen(argv[inshkey]); j++) {
    getsymb = argv[inshkey][j];
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
        printf("Я включился\n");
        break;
      case 'o':
        grep_flags->only_matching = true;
        break;
      default:
        printf("n/a\n");
        return 1;
    }
  }
  return 0;
}