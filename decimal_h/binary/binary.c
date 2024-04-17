#include "binary.h"

int get_bit(decimal decimal, int bit_number) {
  int result = -1;
  int int_number = bit_number / 32;
  bit_number %= 32;
  result = ((1 << bit_number) & decimal.bits[int_number]) >> bit_number;
  return result;
}

void set_bit(decimal* decimal, int bit_number, int bit) {
  int int_number = bit_number / 32;
  bit_number %= 32;
  if (bit == 1) {
    decimal->bits[int_number] |= 1 << bit_number;
  } else if (bit == 0) {
    decimal->bits[int_number] &= ~(1 << bit_number);
  }
}

int get_sign(decimal decimal) { return get_bit(decimal, 127); }

void set_sign(decimal* decimal, int bit) { set_bit(&(*decimal), 127, bit); }

int get_scale(decimal decimal) {
  return (decimal.bits[3] & (0xFF << 16)) >> 16;
}

void set_scale(decimal* decimal, int scale) {
  for (int i = 112; i < 120; i++) {
    int bit_insert = ((1 << (i - 112)) & scale) >> (i - 112);
    set_bit(&(*decimal), i, bit_insert);
  }
}

int get_big_bit(big_decimal decimal, int bit_number) {
  int result = -1;
  int int_number = bit_number / 32;
  bit_number %= 32;
  result = ((1 << bit_number) & decimal.bits[int_number]) >> bit_number;
  return result;
}

// void set_big_bit(big_decimal* decimal, int bit_number, int bit)
// {
//     int int_number = bit_number / 32;
//     bit_number %= 32;
//     if(bit == 1)
//     {
//         decimal->bits[int_number] |= 1 << bit_number;
//     }
//     else if(bit == 0)
//     {
//         decimal->bits[int_number] &= ~(1 << bit_number);
//     }
// }
