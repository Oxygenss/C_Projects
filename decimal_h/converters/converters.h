#ifndef CONVERTERS_H
#define CONVERTERS_H
#include "../decimal.h"

int from_int_to_decimal(int src, decimal *dst);

int from_float_to_decimal(float src, decimal *dst);

int from_decimal_to_int(decimal src, int *dst);

int from_decimal_to_float(decimal src, float *dst);

#endif
