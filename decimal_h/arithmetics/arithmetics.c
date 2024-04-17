#include "arithmetics.h"

int add(decimal value_1, decimal value_2, decimal *result) {
  int res = 0;

  big_decimal big_value_1 = to_big(value_1);
  big_decimal big_value_2 = to_big(value_2);

  big_decimal big_result;
  scan_big_decimal(&big_result, 0, 0, 0, 0, 0, 0, 0, 0);

  int sign_1 = get_sign(value_1);
  int sign_2 = get_sign(value_2);

  set_sign(&value_1, 0);
  set_sign(&value_2, 0);

  normalization_big(&big_value_1, &big_value_2);
  big_result.scale = big_value_1.scale;

  if (sign_1 == sign_2) {
    addition(big_value_1, big_value_2, &big_result);
    big_result.sign = sign_1;
  } else {
    if (is_greater(value_1, value_2)) {
      subtraction(big_value_1, big_value_2, &big_result);
      big_result.sign = sign_1;
    } else {
      subtraction(big_value_2, big_value_1, &big_result);
      big_result.sign = sign_2;
    }
  }

  if (to_normal(&big_result) && big_result.sign == 0) {
    res = 1;
  } else if (to_normal(&big_result) && big_result.sign == 1) {
    res = 2;
  }

  if (res == 0) {
    *result = to_decimal(big_result);
  }

  return res;
}

int sub(decimal value_1, decimal value_2, decimal *result) {
  int res = 0;
  big_decimal big_value_1 = to_big(value_1);
  big_decimal big_value_2 = to_big(value_2);
  big_decimal big_result;
  scan_big_decimal(&big_result, 0, 0, 0, 0, 0, 0, 0, 0);
  int sign_1 = get_sign(value_1);
  int sign_2 = get_sign(value_2);
  set_sign(&value_1, 0);
  set_sign(&value_2, 0);
  normalization_big(&big_value_1, &big_value_2);
  big_result.scale = big_value_1.scale;
  if (sign_1 == sign_2) {
    if (sign_1) {
      if (is_greater(value_1, value_2)) {
        subtraction(big_value_1, big_value_2, &big_result);
        big_result.sign = 1;
      } else {
        subtraction(big_value_2, big_value_1, &big_result);
        big_result.sign = 0;
      }
    } else {
      if (is_greater(value_1, value_2)) {
        subtraction(big_value_1, big_value_2, &big_result);
        big_result.sign = 0;
      } else {
        subtraction(big_value_2, big_value_1, &big_result);
        big_result.sign = 1;
      }
    }
  } else {
    addition(big_value_1, big_value_2, &big_result);
    big_result.sign = sign_1;
  }

  if (to_normal(&big_result) && big_result.sign == 0) {
    res = 1;
  } else if (to_normal(&big_result) && big_result.sign == 1) {
    res = 2;
  }

  if (res == 0) {
    *result = to_decimal(big_result);
  }
  return res;
}

int mul(decimal value_1, decimal value_2, decimal *result) {
  int res = 0;

  big_decimal big_value_1 = to_big(value_1);
  big_decimal big_value_2 = to_big(value_2);
  big_decimal big_result;

  scan_big_decimal(&big_result, 0, 0, 0, 0, 0, 0, 0, 0);

  if (big_value_1.sign != big_value_2.sign) {
    big_result.sign = 1;
  } else {
    big_result.sign = 0;
  }

  big_result.scale = big_value_1.scale + big_value_2.scale;

  big_result.bits[0] = big_value_1.bits[0] * big_value_2.bits[0];
  big_result.bits[1] = big_value_1.bits[1] * big_value_2.bits[0] +
                       big_value_1.bits[0] * big_value_2.bits[1];
  big_result.bits[2] = big_value_1.bits[0] * big_value_2.bits[2] +
                       big_value_1.bits[1] * big_value_2.bits[1] +
                       big_value_1.bits[2] * big_value_2.bits[0];
  big_result.bits[3] = big_value_1.bits[1] * big_value_2.bits[2] +
                       big_value_1.bits[2] * big_value_2.bits[1];
  big_result.bits[4] = big_value_1.bits[2] * big_value_2.bits[2];

  getoverflow(&big_result);

  if (to_normal(&big_result) && big_result.sign == 0) {
    res = 1;
  } else if (to_normal(&big_result) && big_result.sign == 1) {
    res = 2;
  }

  if (res == 0) {
    *result = to_decimal(big_result);
  }

  return res;
}

int div(decimal value_1, decimal value_2, decimal *result) {
  int res = 0;
  int sign = 0;
  if (get_sign(value_1) != get_sign(value_2)) {
    sign = 1;
  }
  set_sign(&value_1, 0);
  set_sign(&value_2, 0);

  if (decimal_is_zero(value_1)) {
    result->bits[0] = 0;
    result->bits[1] = 0;
    result->bits[2] = 0;
    result->bits[3] = 0;
  } else if (decimal_is_zero(value_2)) {
    res = 3;
  } else if (decimal_is_one(value_2)) {
    result->bits[0] = value_1.bits[0];
    result->bits[1] = value_1.bits[1];
    result->bits[2] = value_1.bits[2];
    set_sign(result, sign);
  } else {
    big_decimal temp_1, temp_2;
    temp_1 = to_big(value_1);
    temp_2 = to_big(value_2);
    normalization_big(&temp_1, &temp_2);
    value_1 = to_decimal(temp_1);
    value_2 = to_decimal(temp_2);

    decimal rest = value_1;
    big_decimal big_result;
    int scale = get_scale(value_1) - get_scale(value_2);
    decimal div, one;
    scan_decimal(&div, 0, 0, 0, 0);
    scan_decimal(&one, 0, 0, 0, 1);

    while (is_less(rest, value_2)) {
      big_decimal big_rest;
      big_rest = to_big(rest);
      mul_on_ten(&big_rest);
      rest = to_decimal(big_rest);
      set_scale(&rest, get_scale(rest) - 1);
      scale++;
    }

    while (!decimal_is_zero(rest) && scale < 27) {
      while (is_greater_or_equal(rest, value_2)) {
        sub(rest, value_2, &rest);
        add(div, one, &div);
      }
      // printf("div == %d\n", div.bits[0]);
      // printf("scale_div == %d\n", get_scale(div));
      // printf("result == %d\n", result[0]);
      // printf("scale_result == %d\n", get_scale(*result));

      add(div, *result, result);
      // printf("result == %d\n", result[0]);
      // printf("\n");

      if (!decimal_is_zero(rest)) {
        big_result = to_big(*result);
        mul_on_ten(&big_result);
        *result = to_decimal(big_result);
        set_scale(result, get_scale(*result) - 1);

        scale++;
      }

      mul_on_ten_decimal(&rest);
      scan_decimal(&div, 0, 0, 0, 0);
    }

    if (scale < 0) {
      res = 2;
      scan_decimal(result, 0, 0, 0, 0);
    } else {
      set_scale(result, scale);
    }
    set_sign(result, sign);
  }
  return res;
}