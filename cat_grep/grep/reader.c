#include "reader.h"

int reader(int argc, char *argv[], flags *flag) {
  int gap = argc - optind;
  char buffer[1024];
  for (int i = optind; i < argc; i++) {
    FILE *f = fopen(argv[i], "r");
    if (!f) {
      if (!flag->s) {
        fprintf(stderr, "s21_grep: %s: No such file or directory\n", argv[i]);
      }
      continue;
    }

    int var_regex = REG_EXTENDED;
    if (flag->i) {
      var_regex |= REG_ICASE;
    }
    regex_t reg;
    regmatch_t start[10];
    regcomp(&reg, flag->argument, var_regex);
    int c = 0;
    int count = 0;
    while (fgets(buffer, 1024, f)) {
      int match = regexec(&reg, buffer, 10, start, 0);
      count++;

      if (flag->v) {
        match = !match;
      }
      if (!match) {
        c++;
      }

      if (!match) {
        if (flag->l) {
          printf("%s\n", argv[i]);
          break;
        }
        if (!flag->c) {
          if (gap >= 2 && !flag->h) {
            printf("%s:", argv[i]);
          }
          if (flag->n) {
            printf("%d:", count);
          }
          if (flag->o) {
            for (int j = 0; j < 10 && start[j].rm_so != -1; j++) {
              for (int k = start[j].rm_so; k < start[j].rm_eo; k++) {
                printf("%c", buffer[k]);
              }
              printf("\n");
            }
          } else {
            printf("%s", buffer);
            if (buffer[strlen(buffer) - 1] != '\n') {
              printf("\n");
            }
          }
        }
      }
    }
    if (flag->c && !flag->l) {
      if (gap >= 2 && !flag->h) {
        printf("%s:", argv[i]);
      }
      printf("%d\n", c);
    }

    regfree(&reg);
    fclose(f);
  }
  return 0;
}
