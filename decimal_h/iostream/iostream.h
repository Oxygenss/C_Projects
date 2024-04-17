#ifndef IOSTREAM_H
#define IOSTREAM_H
#include "../decimal.h"

void scan_decimal(decimal* decimal, uint32_t scale, uint32_t high,
                  uint32_t mid, uint32_t low);
void scan_big_decimal(big_decimal* decimal, uint64_t a7, uint64_t a6,
                      uint64_t a5, uint64_t a4, uint64_t a3, uint64_t a2,
                      uint64_t a1, uint64_t a0);
void print_decimal(decimal decimal);
void print_big_decimal(big_decimal decimal);

#endif