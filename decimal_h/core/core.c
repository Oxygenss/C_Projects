#include "core.h"
#include "../decimal.h"
// int get_scale_float(float a)
// {
//     int scale = 0;
//     unsigned int bits = *((unsigned int*)&a);

//     unsigned int mask = 0x7F800000;

//     scale = ((mask & bits) >> 23) - 127;

//     return scale;
// }

int mul_on_ten(big_decimal* bg_decimal) {
  int result = -1;
  big_decimal copy = *bg_decimal;

  for (int i = 0; i < 8; i++) {
    copy.bits[i] *= 10;
  }

  if (!getoverflow(&copy)) {
    result = 0;
    *bg_decimal = copy;
    bg_decimal->scale++;
  } else {
    result = 1;
    printf("OVERFLOW\n");
  }
  return result;
}

int mul_on_ten_decimal(decimal* decimal) {
  int result = -1;

  for (int i = 0; i < 3; i++) {
    decimal->bits[i] *= 10;
  }

  return result;
}

int div_on_ten(big_decimal* big_decimal) {
  uint64_t remainder = 0;
  for (int i = 7; i >= 0; i--) {
    big_decimal->bits[i] += remainder << 32;
    remainder = big_decimal->bits[i] % 10;
    big_decimal->bits[i] /= 10;
  }
  big_decimal->scale--;

  return remainder;
}

void addition(big_decimal value_1, big_decimal value_2,
              big_decimal* result) {
  for (int i = 0; i < 8; i++) {
    result->bits[i] = value_1.bits[i] + value_2.bits[i];
  }
  getoverflow(result);
}

void subtraction(big_decimal value_1, big_decimal value_2,
                 big_decimal* result) {
  for (int i = 0; i < 8; i++) {
    value_2.bits[i] = ~value_2.bits[i];
    value_2.bits[i]++;
  }

  for (int i = 0; i < 8; i++) {
    result->bits[i] = value_1.bits[i] + value_2.bits[i];
  }
  getoverflow(result);
}

int getoverflow(big_decimal* bg_decimal) {
  big_decimal copy = *bg_decimal;

  int result = 0;
  uint32_t overflow = 0;
  for (int i = 0; i < 8; i++) {
    copy.bits[i] += overflow;
    overflow = copy.bits[i] >> 32;
    copy.bits[i] &= MAX4BITE_MASK;

    if (i == 7 && overflow) {
      result = 1;
    }
  }

  if (result == 0) {
    *bg_decimal = copy;
  }

  return result;
}

void normalization_big(big_decimal* value_1, big_decimal* value_2) {
  if (value_1->scale > value_2->scale) {
    while (value_2->scale < value_1->scale) {
      mul_on_ten(value_2);
    }
  } else {
    while (value_1->scale < value_2->scale) {
      mul_on_ten(value_1);
    }
  }
}

int to_normal(big_decimal* big_decimal) {
  int result = 0;
  while ((big_decimal->bits[3] || big_decimal->bits[4] ||
          big_decimal->bits[5] || big_decimal->bits[6] ||
          big_decimal->bits[7]) &&
         big_decimal->scale > 0) {
    div_on_ten(big_decimal);
  }

  if ((big_decimal->bits[3] != 0 || big_decimal->bits[4] != 0 ||
       big_decimal->bits[5] != 0 || big_decimal->bits[6] != 0 ||
       big_decimal->bits[7] != 0) &&
      big_decimal->scale == 0) {
    result = 1;
  }

  return result;
}

big_decimal to_big(decimal decimal) {
  big_decimal big_decimal;

  scan_big_decimal(&big_decimal, 0, 0, 0, 0, 0, 0, 0, 0);
  big_decimal.scale = get_scale(decimal);
  big_decimal.sign = get_sign(decimal);

  big_decimal.bits[0] = decimal.bits[0] & MAX4BITE_MASK;
  big_decimal.bits[1] = decimal.bits[1] & MAX4BITE_MASK;
  big_decimal.bits[2] = decimal.bits[2] & MAX4BITE_MASK;

  return big_decimal;
}

decimal to_decimal(big_decimal big_decimal) {
  decimal decimal;

  scan_decimal(&decimal, 0, 0, 0, 0);
  set_scale(&decimal, big_decimal.scale);
  set_sign(&decimal, big_decimal.sign);

  decimal.bits[0] = big_decimal.bits[0] & MAX4BITE_MASK;
  decimal.bits[1] = big_decimal.bits[1] & MAX4BITE_MASK;
  decimal.bits[2] = big_decimal.bits[2] & MAX4BITE_MASK;

  return decimal;
}

int get_first_non_zero_bit_for_big(big_decimal big_decimal) {
  int result = 0;

  for (int i = 255; i >= 0; i--) {
    if (get_big_bit(big_decimal, i)) {
      result = i;
      break;
    }
  }
  return result;
}

int get_first_non_zero_bit_for_decimal(decimal decimal) {
  int result = 0;

  for (int i = 95; i >= 0; i--) {
    if (get_bit(decimal, i)) {
      result = i;
      break;
    }
  }
  return result;
}

// 0-False, 1-TRUE
int decimal_is_zero(decimal decimal) {
  int res = 1;
  for (int i = 0; i < 3; i++)
    if (decimal.bits[i] != 0) res = 0;
  return res;
}

int decimal_is_one(decimal decimal) {
  int res = 0;
  if (decimal.bits[1] == 0 && decimal.bits[2] == 0 && decimal.bits[0] == 1 &&
      get_scale(decimal) == 0) {
    res = 1;
  }
  return res;
}

// int big_decimal_is_zero(big_decimal decimal) {
//   int res = 1;
//   for (int i = 0; i < 9; i++)
//     if (decimal.bits[i] != 0) res = 0;
//   return res;
// }
