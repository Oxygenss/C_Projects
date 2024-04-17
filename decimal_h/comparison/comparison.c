#include "comparison.h"

int is_equal(decimal value_1, decimal value_2) {
  int result = 1;

  if (get_sign(value_1) != get_sign(value_2)) {
    result = 0;
  } else if (get_scale(value_1) == get_scale(value_2)) {
    for (int i = 2; i >= 0; i--) {
      if (value_1.bits[i] != value_2.bits[i]) {
        result = 0;
        break;
      }
    }
  } else {
    big_decimal big_value_1 = to_big(value_1);
    big_decimal big_value_2 = to_big(value_2);

    normalization_big(&big_value_1, &big_value_2);

    for (int i = 0; i < 8; i++) {
      if (big_value_1.bits[i] != big_value_2.bits[i]) {
        result = 0;
        break;
      }
    }
  }

  return result;
}

int is_less(decimal value_1, decimal value_2) {
  int result = 1;
  if (is_not_equal(value_1, value_2)) {
    if (get_sign(value_1) < get_sign(value_2)) {
      result = 0;
    } else if (get_sign(value_1) > get_sign(value_2)) {
      result = 1;
    } else if (get_scale(value_1) == get_scale(value_2)) {
      for (int i = 3; i >= 0; i--) {
        if (value_1.bits[i] > value_2.bits[i]) {
          result = 0;
          break;
        }
      }
    } else {
      big_decimal big_value_1 = to_big(value_1);
      big_decimal big_value_2 = to_big(value_2);

      normalization_big(&big_value_1, &big_value_2);

      for (int i = 0; i < 8; i++) {
        if (big_value_1.bits[i] > big_value_2.bits[i]) {
          result = 0;
          break;
        }
      }
    }
  } else {
    result = 0;
  }

  if (get_sign(value_1) == 1 && get_sign(value_2) == 1) {
    result = result ? 0 : 1;
  }

  return result;
}

int is_not_equal(decimal value_1, decimal value_2) {
  return !is_equal(value_1, value_2);
}

int is_greater_or_equal(decimal value_1, decimal value_2) {
  return is_greater(value_1, value_2) || is_equal(value_1, value_2);
}

int is_less_or_equal(decimal value_1, decimal value_2) {
  return is_less(value_1, value_2) || is_equal(value_1, value_2);
}

int is_greater(decimal value_1, decimal value_2) {
  return !is_less(value_1, value_2) && !is_equal(value_1, value_2);
}
