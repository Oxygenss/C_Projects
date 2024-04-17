#ifndef OTHER_FUNCTIONS_H
#define OTHER_FUNCTIONS_H

#include "../decimal.h"

int my_floor(decimal value, decimal *result);

int my_round(decimal value, decimal *result);

int truncate(decimal value, decimal *result);

int negate(decimal value, decimal *result);

#endif