#include "converters.h"

#include "math.h"

int from_int_to_decimal(int src, decimal *dst) {
  int result = 0;
  if (src > INT_MAX || src < INT_MIN) result = 1;
  if (dst && !result) {
    dst->bits[0] = 0;
    dst->bits[1] = 0;
    dst->bits[2] = 0;
    dst->bits[3] = 0;
    if (src < 0) {
      negate(*dst, dst);
      src = -src;
    }
    dst->bits[0] = src;
  } else {
    result = 1;
  }
  return result;
}

int from_float_to_decimal(float src, decimal *dst) {
  int result = 0;
  if (isnan(src) || isinf(src)) {
    result = 1;
  }
  if (dst && !result) {
    dst->bits[0] = 0;
    dst->bits[1] = 0;
    dst->bits[2] = 0;
    dst->bits[3] = 0;
    int sign = 0;
    if (src < 0) {
      sign = 1;
      src = -(src);
    }
    int new = (int)src;
    int exp = 0;
    while (src - ((float)new / (int)(pow(10, exp))) != 0) {
      exp++;
      new = src *(int)(pow(10, exp));
    }
    from_int_to_decimal(new, dst);

    if (sign) {
      negate(*dst, dst);
    }
    dst->bits[3] += exp << 16;

  } else {
    result = 1;
  }
  return result;
}

int from_decimal_to_int(decimal src, int *dst) {
  int result = 0;
  if (dst == NULL) {
    result = 1;
  } else {
    decimal buf;
    truncate(src, &buf);

    if (get_first_non_zero_bit_for_decimal(buf) > 31) {
      result = 1;
    } else {
      *dst = src.bits[0];
    }

    if (get_sign(src)) {
      *dst = -*dst;
    }
  }
  return result;
}

int from_decimal_to_float(decimal src, float *dst) {
  int result = 0;
  if (dst == NULL) {
    result = 1;
  } else {
    *dst = 0;

    for (int i = 0; i < 96; i++) {
      if (get_bit(src, i)) {
        *dst += pow(2, i);
      }
    }

    *dst = *dst * pow(10, -get_scale(src));

    if (get_sign(src)) {
      *dst = -*dst;
    }
  }
  return result;
}