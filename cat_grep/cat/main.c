#include "parse.h"
#include "reader.h"

int main(int argc, char *argv[]) {
  flags flag = {0};

  struct option long_flags[] = {{"number-nonblank", no_argument, NULL, 'b'},
                                {"number", no_argument, NULL, 'n'},
                                {"squeeze-blank", no_argument, NULL, 's'}};

  if (parse(argc, argv, "benstvET", long_flags, &flag)) {
    return 0;
  }

  reader(argc, argv, &flag);

  return 0;
}
