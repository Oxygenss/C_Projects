#include "reader.h"

void reader(int argc, char *argv[], flags *flag) {
  int c;
  int count_n = 1;
  int count_string = 1;
  int count_empty_str = 0;
  int first = 1;
  int up_file = 1;
  for (int i = 1; i < argc; i++) {
    if (argv[i][0] == '-') {
      continue;
    }
    FILE *f = fopen(argv[i], "r");
    if (!f) {
      fprintf(stderr, "s21_cat: %s: No such file or directory\n", argv[i]);
      continue;
    }
    while ((c = fgetc(f)) != EOF) {
      if (flag->s && c == '\n') {
        count_empty_str++;
        if (count_empty_str > 2) {
          continue;
        } else if (up_file && count_empty_str > 1) {
          continue;
        }
      } else {
        up_file = 0;
        count_empty_str = 0;
      }

      if (flag->b) {
        if (c != '\n') {
          if (count_n) {
            printf("%6d\t", count_string);
            count_string++;
            count_n = 0;
          }
        } else {
          count_n = 1;
        }
      } else if (flag->n) {
        if (c == '\n') {
          if (c == '\n' && first) {
            printf("%6d\t", count_string);
            count_string++;
          }
          first = 1;
        } else {
          if (first) {
            printf("%6d\t", count_string);
            count_string++;
          }
          first = 0;
        }
      }

      if (flag->t && c == '\t') {
        printf("^I");
        continue;
      }

      if (flag->e && c == '\n') {
        printf("$%c", c);
        continue;
      }

      if (flag->v && c >= 0 && c < 32 && c != 9 && c != 10) {
        printf("^%c", c + 64);
        continue;
      } else if (flag->v && c >= 128) {
        printf("M-^%c", c);
        continue;
      } else if (flag->v && c == 127) {
        printf("^?");
        continue;
      }
      printf("%c", c);
    }
    fclose(f);
  }
}
