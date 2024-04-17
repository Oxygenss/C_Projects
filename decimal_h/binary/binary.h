#ifndef BINARY_H
#define BINARY_H
#include "../decimal.h"

int get_bit(decimal decimal, int bit_number);

void set_bit(decimal* decimal, int bit_number, int bit);

int get_sign(decimal decimal);

void set_sign(decimal* decimal, int bit);

int get_scale(decimal decimal);

void set_scale(decimal* decimal, int scale);

int get_big_bit(big_decimal decimal, int bit_number);

void set_big_bit(big_decimal* decimal, int bit_number, int bit);
#endif