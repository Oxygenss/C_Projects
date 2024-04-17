#ifndef ARITHMETICS_H
#define ARITHMETICS_H
#include "../decimal.h"

int add(decimal value_1, decimal value_2, decimal *result);
int sub(decimal value_1, decimal value_2, decimal *result);
int mul(decimal value_1, decimal value_2, decimal *result);

int div(decimal value_1, decimal value_2, decimal *result);
#endif