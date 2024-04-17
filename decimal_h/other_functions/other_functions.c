#include "./other_functions.h"

int my_floor(decimal value, decimal *result) {
  int res = 0, flag = 0;
  if (result == NULL) {
    res = 1;
  } else {
    if (decimal_is_zero(value)) {
      result->bits[0] = 0;
      result->bits[1] = 0;
      result->bits[2] = 0;
      set_sign(result, get_sign(value));
      set_scale(result, get_scale(*result));
    } else {
      big_decimal big_value = to_big(value);
      while (big_value.scale > 0) {
        div_on_ten(&big_value);
        flag = 1;
      }

      if (big_value.sign == 1 && flag) {
        big_value.bits[0]++;
      }

      if (get_first_non_zero_bit_for_big(big_value) >
          95)  // Не уверен, что такое когда-либо сработает
      {
        res = 1;
      } else {
        *result = to_decimal(big_value);
      }
    }
  }
  return res;
}

int my_round(decimal value, decimal *result) {
  int res = 0;
  if (result == NULL) {
    res = 1;
  } else {
    int buff = 0;
    big_decimal big_value = to_big(value);
    while (big_value.scale > 1) {
      buff = div_on_ten(&big_value);
    }

    while (big_value.scale > 0) {
      buff = div_on_ten(&big_value);
    }
    if (buff > 4) {
      big_value.bits[0]++;
    }

    *result = to_decimal(big_value);
  }
  return res;
}

int truncate(decimal value, decimal *result) {
  int res = 0;
  if (result == NULL) {
    res = 1;
  } else {
    // Сделать функцию деления на 10 для обычного децимала, чтобы не
    // конвентировать его здесь в биг
    big_decimal big_value = to_big(value);
    while (big_value.scale > 0) {
      div_on_ten(&big_value);
    }

    *result = to_decimal(big_value);
  }
  return res;
}

int negate(decimal value, decimal *result) {
  int res = 0;
  if (result == NULL) {
    res = 1;
  } else {
    *result = value;
    if (get_sign(value)) {
      set_sign(result, 0);
    } else {
      set_sign(result, 1);
    }
  }
  return res;
}