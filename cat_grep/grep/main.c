#include "parse.h"
#include "reader.h"

int main(int argc, char *argv[]) {
  flags flag = {0};
  if (!parse(argc, argv, &flag)) {
    reader(argc, argv, &flag);
  }
  return 0;
}
