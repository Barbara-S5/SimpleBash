#include "s21_cat.h"

#include <locale.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "../common/com_line_fun.h"

int main(int argc, char *argv[]) {
  setlocale(LC_ALL, "ru_RU.UTF8");

  int inshkey[16];  // Массив для записи порядковых номеров коротких ключей
  int inlngkey[16];  // Массив для записи порядковых номеров длинных ключей
  int infile[16];  // Массив для записи порядковых номеров входящих файлов
  int count_num[3] = {0, 0, 0};  // массив для хранения колличества найденных
                                 // при парсинге типов аргументов
  strfl flags = {false};

  if (argc == 1) {
    rpcat();
  }

  flags.find_key = parse_arg(argc, argv, inshkey, inlngkey, infile, count_num);
  parse_long_keys(argv, inlngkey, count_num, &flags);
  parse_short_keys(argv, inshkey, count_num, &flags);

  flags.find_key = parse_arg(argc, argv, inshkey, inlngkey, infile, count_num);
  for (int i = 1; i < argc; i++) {
    if (argv[i][0] != '-') {
      io_file(argv[i], &flags);
    }
  }

  return 0;
}

// --- чтения текста с клавиатуры и вывод его же в терминал
void rpcat() {
  int letters;
  letters = getchar();
  printf("%c", letters);
  while ((letters = getchar()) != EOF) {
    putchar(letters);
  }
}

// ----- займёмся длинными ключами----
bool parse_long_keys(char *argv[], int *inlngkey, int *count_num,
                     strfl *flags) {
  if (count_num[1] != 0) {
    for (int il = 0; il < count_num[1]; il++) {
      if (strcmp(argv[inlngkey[il]], "--number-nonblank") == 0) {
        flags->number = true;
        flags->number_nonblank = true;
      } else if (strcmp(argv[inlngkey[il]], "--number") == 0) {
        flags->number = true;
      } else if (strcmp(argv[inlngkey[il]], "--squeeze-blank") == 0) {
        flags->squeeze_blank = true;
      } else {
        printf("n/a\n");
      }
    }
  }
  return false;
}

bool parse_short_keys(char *argv[], int *inshkey, int *count_num,
                      strfl *flags) {
  //-----Короч, короткие ключи----
  if (count_num[0] != 0) {
    char getsymb;
    for (int ish = 0; ish < count_num[0]; ish++) {
      //----распарсим аргимент коротких ключей (орущий котёнок)-----
      for (size_t j = 1; j < strlen(argv[inshkey[ish]]); j++) {
        getsymb = argv[inshkey[ish]][j];
        switch (getsymb) {
          case 'b':
            flags->number = true;
            flags->number_nonblank = true;
            break;
          case 'e':
            flags->show_end = true;
            flags->show_nonprinting = true;
            break;
          case 'v':
            flags->show_nonprinting = true;
            break;
          case 'n':
            flags->number = true;
            break;
          case 's':
            flags->squeeze_blank = true;
            break;
          case 't':
            flags->show_tabs = true;
            flags->show_nonprinting = true;
            break;
          case 'T':
            flags->show_tabs = true;
            break;
          case 'E':
            flags->show_end = true;
            break;
          default:
            printf("n/a\n");
        }
      }
    }
  }
  return 0;
}

//----функция чтения файла в буф и вывода из буф на экран----
int io_file(char *namefi, strfl *flags) {
  FILE *filep = fopen(namefi, "r");
  char c;
  char prev_c = '\n';
  int empty_printed = 0;
  int end = 1;
  int count = 1;
  if (filep != NULL) {
    while ((c = fgetc(filep)) != EOF) {
      if (flags->number_nonblank == 1 && end == 1 && c != '\n') {  // флаг -b
        printf("%6d\t", count);
        count++;
        end = 0;
      }
      if (flags->number && end && flags->number_nonblank == 0) {
        printf("%6d\t", count);
        count++;  // ФЛАГ -n
        end = 0;
      }
      if (flags->show_nonprinting == 1 &&  // флаг v
          (((c >= 0 && c <= 31) && (c != '\n' && c != '\t')) || (c == 127))) {
        if (c == 127) {
          printf("^");
          c = c - 64;
        } else {
          printf("^");
          c = c + 64;
        }
      }
      if (flags->show_tabs && c == '\t') {
        printf("^");
        c = c + 64;
      }
      if ((c == '\n' && (prev_c == '\n' && empty_printed == 0)) ||
          (c == '\n' && prev_c != '\n') ||
          (c == '\n' && !(flags->squeeze_blank))) {
        end = 1;
      }
      if (flags->show_end && end == 1 && (c == '\n' || c == '\0') &&
          !(flags->squeeze_blank && empty_printed == 1)) {
        printf("$");
      }
      if (!(flags->squeeze_blank && prev_c == '\n' && c == '\n')) {
        printf("%c", c);
      }
      if ((flags->squeeze_blank && prev_c == '\n' && c == '\n' &&
           empty_printed == 0)) {
        printf("%c", c);
      }
      if (prev_c == '\n' && c == '\n')
        empty_printed = 1;
      else
        empty_printed = 0;
      prev_c = c;
    }
  } else {
    printf("n/a");
    fclose(filep);
  }
  return 0;
}
