#include "./iostream.h"

// void print_decimal(decimal decimal) {
//   int flag = 0;
//   if (decimal.bits[2]) {
//     printf("%b ", decimal.bits[2]);
//     flag = 1;
//   }

//   if (flag) {
//     printf("%032b ", decimal.bits[1]);
//   } else {
//     if (decimal.bits[1]) {
//       flag = 1;
//       printf("%b ", decimal.bits[1]);
//     }
//   }

//   if (flag) {
//     printf("%032b ", decimal.bits[0]);
//   } else {
//     printf("%b ", decimal.bits[0]);
//   }
// }

void scan_decimal(decimal* decimal, uint32_t scale, uint32_t high,
                  uint32_t mid, uint32_t low) {
  decimal->bits[0] = low;
  decimal->bits[1] = mid;
  decimal->bits[2] = high;
  decimal->bits[3] = scale;
}

// void print_big_decimal(big_decimal decimal) {
//   int flag = 0;
//   if (decimal.bits[7]) {
//     printf("%lb ", decimal.bits[7]);
//     flag = 1;
//   }

//   if (flag) {
//     printf("%032b ", decimal.bits[6]);
//   } else {
//     if (decimal.bits[6]) {
//       flag = 1;
//       printf("%b ", decimal.bits[6]);
//     }
//   }

//   if (flag) {
//     printf("%032b ", decimal.bits[5]);
//   } else {
//     if (decimal.bits[5]) {
//       flag = 1;
//       printf("%b ", decimal.bits[5]);
//     }
//   }

//   if (flag) {
//     printf("%032b ", decimal.bits[4]);
//   } else {
//     if (decimal.bits[4]) {
//       flag = 1;
//       printf("%b ", decimal.bits[4]);
//     }
//   }

//   if (flag) {
//     printf("%032b ", decimal.bits[3]);
//   } else {
//     if (decimal.bits[3]) {
//       flag = 1;
//       printf("%b ", decimal.bits[3]);
//     }
//   }

//   if (flag) {
//     printf("%032b ", decimal.bits[2]);
//   } else {
//     if (decimal.bits[2]) {
//       flag = 1;
//       printf("%b ", decimal.bits[2]);
//     }
//   }

//   if (flag) {
//     printf("%032b ", decimal.bits[1]);
//   } else {
//     if (decimal.bits[1]) {
//       flag = 1;
//       printf("%b ", decimal.bits[1]);
//     }
//   }

//   if (flag) {
//     printf("%032b ", decimal.bits[0]);
//   } else {
//     if (decimal.bits[0]) {
//       flag = 1;
//       printf("%b ", decimal.bits[0]);
//     }
//   }
// }

void scan_big_decimal(big_decimal* decimal, uint64_t a7, uint64_t a6,
                      uint64_t a5, uint64_t a4, uint64_t a3, uint64_t a2,
                      uint64_t a1, uint64_t a0) {
  decimal->bits[0] = a0;
  decimal->bits[1] = a1;
  decimal->bits[2] = a2;
  decimal->bits[3] = a3;
  decimal->bits[4] = a4;
  decimal->bits[5] = a5;
  decimal->bits[6] = a6;
  decimal->bits[7] = a7;
}