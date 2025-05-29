#include "pars_line_fun.h"

#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>

// -----Функция парсинга командной строки-----
bool parse_arg(int argc, char *argv[], int *inshkey, int *inlngkey, int *infile,
               int *count_num) {
  int i;
  bool res = false;
  int s = count_num[0];
  int l = count_num[1];
  int fi = count_num[2];

  for (i = 1; i < argc; i++) {
    if (argv[i][0] == '-') {
      if (argv[i][1] == '-') {
        inlngkey[l] = i;
        l++;
        count_num[1] = l;
      } else {
        inshkey[s] = i;
        s++;
        count_num[0] = s;
      }
      res = true;
    } else {
      infile[fi] = i;
      fi++;
      count_num[2] = fi;
    }
  }
  return res;
}