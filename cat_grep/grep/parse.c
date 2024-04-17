#include "parse.h"

int flag_f(char *file, flags *flag) {
  char buffer[1024];
  FILE *f = fopen(file, "r");
  if (!f) {
    fprintf(stderr, "s21_grep: %s: No such file or directory\n", file);
  } else {
    while (fgets(buffer, 1024, f)) {
      if (buffer[strlen(buffer) - 1] == '\n') {
        buffer[strlen(buffer) - 1] = '\0';
      }
      strcat(flag->argument, buffer);
      strcat(flag->argument, "|");
    }
    fclose(f);
  }
  return 0;
}

int parse(int argc, char *argv[], flags *flag) {
  int res;
  int error = 0;
  while ((res = getopt(argc, argv, "e:ivclnhsf:o")) != -1) {
    switch (res) {
      case 'e':
        flag->e = 1;
        strcat(flag->argument, optarg);
        strcat(flag->argument, "|");
        break;
      case 'i':
        flag->i = 1;
        break;
      case 'v':
        flag->v = 1;
        break;
      case 'c':
        flag->c = 1;
        break;
      case 'l':
        flag->l = 1;
        break;
      case 'n':
        flag->n = 1;
        break;
      case 'h':
        flag->h = 1;
        break;
      case 's':
        flag->s = 1;
        break;
      case 'f':
        flag->f = 1;
        flag_f(optarg, &(*flag));
        break;
      case 'o':
        flag->o = 1;
        break;
      default:
        error = 1;
        break;
    }
  }

  if (flag->e || flag->f) {
    flag->argument[strlen(flag->argument) - 1] = '\0';
  } else {
    strcat(flag->argument, argv[optind]);
    optind++;
  }
  return error;
}
