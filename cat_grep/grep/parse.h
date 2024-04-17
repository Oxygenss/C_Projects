#ifndef PARSE_H
#define PARSE_H

#include <getopt.h>
#include <stdio.h>
#include <string.h>
typedef struct {
  int e;
  int i;
  int v;
  int c;
  int l;
  int n;
  int h;
  int s;
  int o;
  int f;
  char argument[256];
} flags;

int parse(int argc, char *argv[], flags *flag);

#endif
