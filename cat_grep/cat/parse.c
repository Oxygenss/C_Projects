#include "parse.h"

int parse(int argc, char *argv[], char *short_flags, struct option long_flags[],
          flags *flag) {
  int res;
  int error = 0;
  int index = 0;
  while ((res = getopt_long(argc, argv, short_flags, long_flags, &index)) !=
         -1) {
    switch (res) {
      case 'b':
        flag->b = 1;
        break;
      case 'e':
        flag->e = 1;
        flag->v = 1;
        break;
      case 'n':
        flag->n = 1;
        break;
      case 's':
        flag->s = 1;
        break;
      case 't':
        flag->t = 1;
        flag->v = 1;
        break;
      case 'E':
        flag->e = 1;
        break;
      case 'T':
        flag->t = 1;
        break;
      case 'v':
        flag->v = 1;
        break;
      default:
        error = 1;
        break;
    }
  }

  return error;
}
