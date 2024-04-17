#define MAX4BITE_MASK 0xffffffff;

#include <limits.h>
#include <math.h>
#include <stdint.h>
#include <stdio.h>

#include "./arithmetics/arithmetics.h"
#include "./binary/binary.h"
#include "./comparison/comparison.h"
#include "./converters/converters.h"
#include "./core/core.h"
#include "./iostream/iostream.h"
#include "./other_functions/other_functions.h"

#ifndef DECIMAL_H
#define DECIMAL_H

typedef struct {
  uint32_t bits[4];
} decimal;

typedef struct {
  uint64_t bits[8];
  uint16_t sign;
  uint16_t scale;
} big_decimal;

#endif