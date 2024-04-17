#include <check.h>
#include <limits.h>

#include "../decimal.h"
void init_decimal(decimal *decimal);
void init_decimal(decimal *decimal) {
  for (int i = 0; i < 4; i++) {
    decimal->bits[i] = 0;
  }
}
void run_test(Suite *thesuit) {
  SRunner *therunner = srunner_create(thesuit);
  srunner_set_fork_status(therunner, CK_NOFORK);
  srunner_run_all(therunner, CK_NORMAL);
  srunner_ntests_failed(therunner);
  srunner_free(therunner);
  printf("\n");
}

//================= arithmetic functions tests =================
// add
START_TEST(part1_add_normal) {
  decimal value_1 = {0};
  decimal value_2 = {0};
  decimal result = {0};
  decimal test = {{1535}};
  value_1.bits[0] = 150;
  value_2.bits[0] = 35;
  set_scale(&value_2, 1);
  int res = add(value_1, value_2, &result);
  ck_assert_uint_eq(result.bits[0], test.bits[0]);
  ck_assert_int_eq(get_scale(result), 1);
  ck_assert_int_eq(get_sign(result), 0);
  ck_assert_int_eq(res, 0);
}
END_TEST

START_TEST(part1_add_both_neg) {
  decimal value_1 = {0};
  decimal value_2 = {0};
  decimal result = {0};
  decimal test = {{1535}};
  value_1.bits[0] = 150;
  value_2.bits[0] = 35;
  set_sign(&value_2, 1);
  set_sign(&value_1, 1);
  set_scale(&value_2, 1);
  int res = add(value_1, value_2, &result);
  ck_assert_uint_eq(result.bits[0], test.bits[0]);
  ck_assert_int_eq(get_scale(result), 1);
  ck_assert_int_eq(get_sign(result), 1);
  ck_assert_int_eq(res, 0);
}
END_TEST

START_TEST(part1_add_error) {
  decimal value_1 = {0};
  decimal value_2 = {0};
  decimal result = {0};
  value_1.bits[0] = 4294967295;
  value_1.bits[1] = 4294967295;
  value_1.bits[2] = 4294967295;
  value_2.bits[0] = 35;
  int res = add(value_1, value_2, &result);
  ck_assert_int_eq(res, 1);
  set_sign(&value_2, 1);
  set_sign(&value_1, 1);

  memset(&result, 0, sizeof(decimal));
  res = add(value_1, value_2, &result);
  ck_assert_int_eq(res, 2);
}
END_TEST

START_TEST(part1_add_one_greater) {
  decimal value_1 = {0};
  decimal value_2 = {0};
  decimal result = {0};
  value_1.bits[0] = 540;
  value_2.bits[0] = 560;
  decimal test = {{20}};
  set_sign(&value_2, 1);
  add(value_1, value_2, &result);
  ck_assert_int_eq(result.bits[0], test.bits[0]);
  ck_assert_int_eq(get_sign(result), 1);
}
END_TEST

START_TEST(part1_add_one_sign) {
  decimal value_1 = {{150}};
  decimal value_2 = {{50}};
  decimal result = {0};
  decimal test = {{100}};
  set_sign(&value_1, 1);
  add(value_1, value_2, &result);
  ck_assert_uint_eq(result.bits[0], test.bits[0]);
  ck_assert_int_eq(get_scale(result), 0);
  ck_assert_int_eq(get_sign(result), 1);
  set_sign(&value_1, 0);
  set_sign(&value_2, 1);
  memset(&result, 0, sizeof(decimal));
  int res = add(value_1, value_2, &result);
  ck_assert_uint_eq(result.bits[0], test.bits[0]);
  ck_assert_int_eq(get_scale(result), 0);
  ck_assert_int_eq(get_sign(result), 0);
  ck_assert_int_eq(res, 0);
}
END_TEST

// sub
START_TEST(part1_sub_normal) {
  decimal value_1 = {0};
  decimal value_2 = {0};
  decimal result = {0};

  value_1.bits[0] = 155;
  value_2.bits[0] = 55;
  sub(value_1, value_2, &result);
  decimal test = {0};
  test.bits[0] = 100;
  ck_assert_uint_eq(result.bits[0], test.bits[0]);
  memset(&result, 0, sizeof(decimal));
  value_1.bits[0] = (unsigned int)50;
  value_2.bits[0] = (unsigned int)150;
  sub(value_1, value_2, &result);
  int sign = get_sign(result);
  ck_assert_uint_eq(result.bits[0], test.bits[0]);
  ck_assert_int_eq(sign, 1);

  memset(&value_1, 0, sizeof(decimal));
  memset(&value_2, 0, sizeof(decimal));
  memset(&result, 0, sizeof(decimal));
  value_1.bits[0] = (unsigned int)50;
  value_2.bits[0] = (unsigned int)15;
  memset(&result, 0, sizeof(decimal));
  set_scale(&value_2, 1);
  sub(value_1, value_2, &result);
  ck_assert_uint_eq(result.bits[0], 485);
  ck_assert_uint_eq(get_scale(result), 1);
  ck_assert_uint_eq(get_sign(result), 0);
}
END_TEST

START_TEST(part1_sub_inf) {
  decimal value_1 = {0};
  decimal value_2 = {0};
  decimal result = {0};
  value_1.bits[0] = 4294967295;
  value_1.bits[1] = 4294967295;
  value_1.bits[2] = 4294967295;
  value_2.bits[0] = 55;
  set_sign(&value_1, 1);
  int res = sub(value_1, value_2, &result);
  ck_assert_uint_eq(res, 2);
}
END_TEST

START_TEST(part1_sub_one_sign) {
  decimal value_1 = {0};
  decimal value_2 = {0};
  decimal result = {0};
  value_1.bits[0] = 150;
  value_2.bits[0] = 50;
  set_sign(&value_1, 1);
  sub(value_1, value_2, &result);
  decimal test = {0};
  test.bits[0] = 200;
  ck_assert_int_eq(result.bits[0], test.bits[0]);
  int sign = get_sign(result);
  ck_assert_int_eq(sign, 1);
  memset(&result, 0, sizeof(decimal));
  set_sign(&value_1, 0);
  set_sign(&value_2, 1);
  sub(value_1, value_2, &result);
  ck_assert_int_eq(result.bits[0], test.bits[0]);
  int sign1 = get_sign(result);
  ck_assert_int_eq(sign1, 0);
}
END_TEST

START_TEST(part1_sub_two_sign) {
  decimal value_1 = {0};
  decimal value_2 = {0};
  decimal result = {0};
  value_1.bits[0] = 150;
  value_2.bits[0] = 50;
  set_sign(&value_1, 1);
  set_sign(&value_2, 1);

  sub(value_1, value_2, &result);
  decimal test = {0};
  test.bits[0] = 100;
  ck_assert_int_eq(result.bits[0], test.bits[0]);
  int sign = get_sign(result);
  ck_assert_int_eq(sign, 1);
  memset(&result, 0, sizeof(decimal));
  sub(value_1, value_2, &result);
  ck_assert_int_eq(result.bits[0], test.bits[0]);
  int sign1 = get_sign(result);
  ck_assert_int_eq(sign1, 1);
  value_1.bits[0] = 50;
  value_2.bits[0] = 150;
  memset(&result, 0, sizeof(decimal));
  sub(value_1, value_2, &result);
  ck_assert_int_eq(result.bits[0], test.bits[0]);
  sign1 = get_sign(result);
  ck_assert_int_eq(sign1, 0);
}
END_TEST

// mult
START_TEST(part1_mult_value_1_is_one) {
  decimal value_1 = {0};
  decimal value_2 = {0};
  decimal result = {0};
  decimal test = {0};
  value_1.bits[0] = 1;
  value_2.bits[0] = 10;
  test.bits[0] = 10;
  mul(value_1, value_2, &result);
  ck_assert_uint_eq(result.bits[0], test.bits[0]);
  set_sign(&value_1, 1);
  memset(&result, 0, sizeof(decimal));
  mul(value_1, value_2, &result);
  ck_assert_uint_eq(result.bits[0], test.bits[0]);
  ck_assert_uint_eq(get_sign(result), 1);
}
END_TEST

START_TEST(part1_mult_value_2_is_one) {
  decimal value_1 = {0};
  decimal value_2 = {0};
  decimal result = {0};
  decimal test = {0};
  value_1.bits[0] = 15;
  value_2.bits[0] = 1;
  test.bits[0] = 15;
  mul(value_1, value_2, &result);
  ck_assert_uint_eq(result.bits[0], test.bits[0]);
}
END_TEST

START_TEST(part1_mult_value_1_is_zero) {
  decimal value_1 = {0};
  decimal value_2 = {0};
  decimal result = {0};
  decimal test = {0};
  value_1.bits[0] = 0;
  value_2.bits[0] = 100;
  test.bits[0] = 0;
  mul(value_1, value_2, &result);
  ck_assert_uint_eq(result.bits[0], test.bits[0]);
}
END_TEST

START_TEST(part1_mult_value_2_is_zero) {
  decimal value_1 = {0};
  decimal value_2 = {0};
  decimal result = {0};
  decimal test = {0};
  value_1.bits[0] = 7;
  value_2.bits[0] = 0;
  test.bits[0] = 0;
  mul(value_1, value_2, &result);
  ck_assert_uint_eq(result.bits[0], test.bits[0]);
}
END_TEST

START_TEST(part1_mult_max) {
  decimal value_1 = {0};
  decimal value_2 = {0};
  decimal result = {0};
  value_1.bits[0] = 4294967295;
  value_1.bits[1] = 4294967295;
  value_1.bits[2] = 4294967295;
  value_2.bits[0] = 5;
  int res = mul(value_1, value_2, &result);
  ck_assert_uint_eq(res, 1);

  set_sign(&value_2, 1);
  res = mul(value_1, value_2, &result);
  ck_assert_uint_eq(res, 2);
}
END_TEST

START_TEST(part1_mult_big_power) {
  decimal value_1 = {0};
  decimal value_2 = {0};
  decimal result = {0};
  decimal test = {0};
  value_1.bits[0] = 2147483647;
  value_2.bits[0] = 255;
  test.bits[0] = 2147483393;
  test.bits[1] = 127;
  set_scale(&value_2, 10);
  int res = mul(value_1, value_2, &result);
  ck_assert_uint_eq(result.bits[0], test.bits[0]);
  ck_assert_uint_eq(result.bits[1], test.bits[1]);
  ck_assert_uint_eq(get_scale(result), 10);
  ck_assert_uint_eq(get_sign(result), 0);
  ck_assert_uint_eq(res, 0);
}
END_TEST

START_TEST(part1_mult_big_negative_over) {
  decimal value_1 = {0};
  decimal value_2 = {0};
  decimal result = {0};
  value_1.bits[0] = 2147483647;
  value_1.bits[1] = 2147483647;
  value_1.bits[2] = 2147483647;
  value_2.bits[0] = 15;
  set_scale(&value_2, 1);
  set_sign(&value_2, 1);
  int res = mul(value_1, value_2, &result);
  ck_assert_uint_eq(res, 0);
}
END_TEST

START_TEST(part1_mult_big_over) {
  decimal value_1 = {0};
  decimal value_2 = {0};
  decimal result = {0};
  value_1.bits[0] = 2147483647;
  value_1.bits[1] = 2147483647;
  value_1.bits[2] = 2147483647;
  value_2.bits[0] = 15;
  set_scale(&value_2, 1);
  int res = mul(value_1, value_2, &result);
  ck_assert_uint_eq(res, 0);
}
END_TEST

START_TEST(part1_mult_value_1_is_minus) {
  decimal value_1 = {0};
  decimal value_2 = {0};
  decimal result = {0};
  decimal test = {0};
  set_sign(&value_1, 1);
  value_1.bits[0] = 15;
  value_2.bits[0] = 1;
  test.bits[0] = 15;
  mul(value_1, value_2, &result);
  ck_assert_uint_eq(result.bits[0], test.bits[0]);
  ck_assert_uint_eq(get_sign(result), 1);
}
END_TEST

START_TEST(part1_mult_value_2_is_minus) {
  decimal value_1 = {0};
  decimal value_2 = {0};
  decimal result = {0};
  decimal test = {0};
  value_1.bits[0] = 15;
  set_sign(&value_2, 1);
  value_2.bits[0] = 1;
  test.bits[0] = 15;
  mul(value_1, value_2, &result);
  ck_assert_uint_eq(result.bits[0], test.bits[0]);
  ck_assert_uint_eq(get_sign(result), 1);
}
END_TEST

START_TEST(part1_mult_value_1_is_zero_minus) {
  decimal value_1 = {0};
  decimal value_2 = {0};
  decimal result = {0};
  decimal test = {0};
  set_sign(&value_1, 1);
  value_1.bits[0] = 0;
  value_2.bits[0] = 100;
  test.bits[0] = 0;
  mul(value_1, value_2, &result);
  ck_assert_uint_eq(result.bits[0], test.bits[0]);
  ck_assert_uint_eq(get_sign(result), 1);
}
END_TEST

START_TEST(part1_mult_value_2_is_zero_minus) {
  decimal value_1 = {0};
  decimal value_2 = {0};
  decimal result = {0};
  decimal test = {0};
  value_1.bits[0] = 7;
  set_sign(&value_2, 1);
  value_2.bits[0] = 0;
  test.bits[0] = 0;
  mul(value_1, value_2, &result);
  ck_assert_uint_eq(result.bits[0], test.bits[0]);
  ck_assert_uint_eq(get_sign(result), 1);
}
END_TEST

START_TEST(part1_mult_value_1_2_is_minus) {
  decimal value_1 = {0};
  decimal value_2 = {0};
  decimal result = {0};
  decimal test = {0};
  set_sign(&value_1, 1);
  set_sign(&value_2, 1);
  value_1.bits[0] = 0;
  value_2.bits[0] = 100;
  test.bits[0] = 0;
  mul(value_1, value_2, &result);
  ck_assert_uint_eq(result.bits[0], test.bits[0]);
  ck_assert_uint_eq(get_sign(result), 0);
  set_scale(&value_1, 5);
  set_scale(&value_2, 29);
  mul(value_1, value_2, &result);
  ck_assert_uint_eq(result.bits[0], test.bits[0]);
}
END_TEST

// === division === //
START_TEST(div_0) {
  decimal value_1 = {{20, 0, 0, 0}};
  decimal value_2 = {{2, 0, 0, 0}};
  decimal result = {0};
  decimal test = {0};
  test.bits[0] = 10;
  set_bit(&value_1, 127, 0);
  set_bit(&value_2, 127, 1);
  int res = div(value_1, value_2, &result);
  // dec_output(result);
  // printf("RES: %d\n", res);
  ck_assert_uint_eq(result.bits[0], test.bits[0]);
  ck_assert_uint_eq(get_bit(result, 127), 1);
  ck_assert_uint_eq(get_scale(result), 0);
  ck_assert_uint_eq(res, 0);
}
END_TEST

START_TEST(div_1) {
  decimal val1 = {{8, 0, 0, 0}};
  decimal val2 = {{3, 0, 0, 0}};
  decimal res = {0};
  ck_assert_int_eq(0, div(val1, val2, &res));
}
END_TEST

START_TEST(div_2) {
  decimal val1 = {{2, 0, 0, 0}};
  decimal val2 = {{2, 0, 0, 0}};
  decimal res = {{0}};
  set_scale(&val1, ~(UINT_MAX / 2));
  set_scale(&val2, ~(UINT_MAX / 2));
  ck_assert_int_eq(0, div(val1, val2, &res));
}
END_TEST

START_TEST(div_3) {
  decimal val1 = {{2, 0, 0, 0}};
  decimal val2 = {{0, 0, 0, 0}};
  decimal res = {{0}};
  ck_assert_int_eq(3, div(val1, val2, &res));
}
END_TEST

START_TEST(div_4) {
  decimal val1 = {{2, 0, 0, 0}};
  decimal val2 = {{2, 0, 0, 0}};
  set_bit(&val1, 127, 0);
  set_bit(&val2, 127, 0);
  set_scale(&val1, 1);
  set_scale(&val2, 3);
  decimal res = {{0}};
  decimal result = {{100, 0, 0, 0}};
  ck_assert_int_eq(0, div(val1, val2, &res));
  ck_assert_uint_eq(is_equal(result, res), 1);
}
END_TEST

START_TEST(div_5) {
  decimal value_1 = {{4, 0, 0, 0}};
  decimal value_2 = {{4, 0, 0, 0}};
  decimal result = {0};
  decimal test = {0};
  set_scale(&value_1, 0);
  set_scale(&value_2, 3);
  test.bits[0] = 1000;
  int res = div(value_1, value_2, &result);
  ck_assert_uint_eq(result.bits[0], test.bits[0]);
  ck_assert_uint_eq(get_bit(result, 127), 0);
  ck_assert_uint_eq(get_scale(result), 0);
  ck_assert_uint_eq(res, 0);
}
END_TEST

START_TEST(div_6) {
  decimal value_1 = {{1, 0, 0, 0}};
  decimal value_2 = {{5, 0, 0, 0}};
  decimal result = {0};
  decimal test = {{2, 0, 0, 0}};
  set_scale(&value_1, 0);
  set_scale(&value_2, 0);
  set_scale(&test, 1);
  int res = div(value_1, value_2, &result);
  ck_assert_uint_eq(is_equal(result, test), 1);
  ck_assert_uint_eq(get_bit(result, 127), 0);
  ck_assert_uint_eq(res, 0);
}
END_TEST

START_TEST(div_7) {
  decimal value_1 = {{4294967295, 4294967295, 4294967295, 1}};
  decimal value_2 = {{1, 0, 0, 1}};
  decimal result = {0};
  set_scale(&value_1, 0);
  set_scale(&value_2, 0);
  int res = div(value_1, value_2, &result);
  ck_assert_uint_eq(is_equal(value_1, result), 1);

  ck_assert_uint_eq(res, 0);
}
END_TEST

START_TEST(div_8) {
  decimal value_1 = {{4294967295, 4294967295, 4294967295, 1}};
  decimal value_2 = {{1, 0, 0, 1}};
  decimal result = {0};
  set_bit(&value_1, 127, 1);
  set_scale(&value_1, 0);
  set_scale(&value_2, 0);
  int res = div(value_1, value_2, &result);
  ck_assert_uint_eq(is_equal(value_1, result), 1);
  ck_assert_uint_eq(res, 0);
}

//================= comparison functions tests =================
// === is_less === //
START_TEST(is_less_plus_both) {  // 1337 < 1338 == 1 yes
  decimal num1 = {0};
  from_int_to_decimal(1337, &num1);
  decimal num2 = {0};
  from_int_to_decimal(1338, &num2);
  ck_assert_int_eq(1, is_less(num1, num2));
}
END_TEST

START_TEST(is_less_min_num1) {  // -1337 < 1338 == 1 yes
  decimal num1 = {0};
  from_int_to_decimal(-1337, &num1);
  decimal num2 = {0};
  from_int_to_decimal(1338, &num2);
  ck_assert_int_eq(1, is_less(num1, num2));
}
END_TEST

START_TEST(is_less_min_num2) {  // 1337 < -1338 == 0 no
  decimal num1 = {0};
  from_int_to_decimal(1337, &num1);
  decimal num2 = {0};
  from_int_to_decimal(-1338, &num2);
  ck_assert_int_eq(0, is_less(num1, num2));
}
END_TEST

START_TEST(is_less_min_both) {  // -1337 < -1338 == 0 no
  decimal num1 = {0};
  from_int_to_decimal(-1337, &num1);
  decimal num2 = {0};
  from_int_to_decimal(-1338, &num2);
  ck_assert_int_eq(0, is_less(num1, num2));
}
END_TEST

// === is_greater === //
START_TEST(is_greater_plus_both) {  // 1337 > 1338 == 0 no
  decimal num1 = {0};
  from_int_to_decimal(1337, &num1);
  decimal num2 = {0};
  from_int_to_decimal(1338, &num2);
  ck_assert_int_eq(0, is_greater(num1, num2));
}
END_TEST

START_TEST(is_greater_min_num1) {  // -1337 > 1338 == 0 no
  decimal num1 = {0};
  from_int_to_decimal(-1337, &num1);
  decimal num2 = {0};
  from_int_to_decimal(1338, &num2);
  ck_assert_int_eq(0, is_greater(num1, num2));
}
END_TEST

START_TEST(is_greater_min_num2) {  // 1337 > -1338 == 1 yes
  decimal num1 = {0};
  from_int_to_decimal(1337, &num1);
  decimal num2 = {0};
  from_int_to_decimal(-1338, &num2);
  ck_assert_int_eq(1, is_greater(num1, num2));
}
END_TEST

START_TEST(is_greater_min_both) {  // -1337 > -1338 == 1 yes
  decimal num1 = {0};
  from_int_to_decimal(-1337, &num1);
  decimal num2 = {0};
  from_int_to_decimal(-1338, &num2);
  ck_assert_int_eq(1, is_greater(num1, num2));
}
END_TEST

// === is_less_or_equal === //
START_TEST(is_less_or_equal_num1_less) {  // 1337 <= 1338 == 1 yes
  decimal num1 = {0};
  from_int_to_decimal(1337, &num1);
  decimal num2 = {0};
  from_int_to_decimal(1338, &num2);
  ck_assert_int_eq(1, is_less_or_equal(num1, num2));
}
END_TEST

START_TEST(is_less_or_equal_num2_less) {  // 1338 <= 1337 == 0 no
  decimal num1 = {0};
  from_int_to_decimal(1338, &num1);
  decimal num2 = {0};
  from_int_to_decimal(1337, &num2);
  ck_assert_int_eq(0, is_less_or_equal(num1, num2));
}
END_TEST

START_TEST(is_less_or_equal_both_equal) {  // 1337 <= 1337 == 1 yes
  decimal num1 = {0};
  from_int_to_decimal(1337, &num1);
  decimal num2 = {0};
  from_int_to_decimal(1337, &num2);
  ck_assert_int_eq(1, is_less_or_equal(num1, num2));
}
END_TEST

// === is_greater_or_equal === //
START_TEST(is_greater_or_equal_num1_less) {  // 1337 >= 1338 == 0 no
  decimal num1 = {0};
  from_int_to_decimal(1337, &num1);
  decimal num2 = {0};
  from_int_to_decimal(1338, &num2);
  ck_assert_int_eq(0, is_greater_or_equal(num1, num2));
}
END_TEST

START_TEST(is_greater_or_equal_num2_less) {  // 1338 >= 1337 == 1 yes
  decimal num1 = {0};
  from_int_to_decimal(1338, &num1);
  decimal num2 = {0};
  from_int_to_decimal(1337, &num2);
  ck_assert_int_eq(1, is_greater_or_equal(num1, num2));
}
END_TEST

START_TEST(is_greater_or_equal_both_equal) {  // 1337 >= 1337 == 1 yes
  decimal num1 = {0};
  from_int_to_decimal(1337, &num1);
  decimal num2 = {0};
  from_int_to_decimal(1337, &num2);
  ck_assert_int_eq(1, is_greater_or_equal(num1, num2));
}
END_TEST

// === is_equal === //
START_TEST(is_equal_true) {  // 1337 = 1337 == 1 yes
  decimal num1 = {0};
  from_int_to_decimal(1337, &num1);
  decimal num2 = {0};
  from_int_to_decimal(1337, &num2);
  ck_assert_int_eq(1, is_equal(num1, num2));
}
END_TEST

START_TEST(is_equal_false) {  // 1337 = 1338 == 0 no
  decimal num1 = {0};
  from_int_to_decimal(1337, &num1);
  decimal num2 = {0};
  from_int_to_decimal(1338, &num2);
  ck_assert_int_eq(0, is_equal(num1, num2));
}
END_TEST

START_TEST(is_equal_min_num1) {  // 1337 = 1338 == 0 no
  decimal num1 = {0};
  from_int_to_decimal(-1337, &num1);
  decimal num2 = {0};
  from_int_to_decimal(1338, &num2);
  ck_assert_int_eq(0, is_equal(num1, num2));
}
END_TEST

START_TEST(is_equal_min_num2) {  // 1337 = 1338 == 0 no
  decimal num1 = {0};
  from_int_to_decimal(1337, &num1);
  decimal num2 = {0};
  from_int_to_decimal(-1338, &num2);
  ck_assert_int_eq(0, is_equal(num1, num2));
}
END_TEST

START_TEST(is_equal_min_both) {  // 1337 = 1338 == 0 no
  decimal num1 = {0};
  from_int_to_decimal(-1337, &num1);
  decimal num2 = {0};
  from_int_to_decimal(-1338, &num2);
  ck_assert_int_eq(0, is_equal(num1, num2));
}
END_TEST

// === is_not_equal === //
START_TEST(is_not_equal_true) {  // 1337 != 1338 == 1 yes
  decimal num1 = {0};
  from_int_to_decimal(1337, &num1);
  decimal num2 = {0};
  from_int_to_decimal(1338, &num2);
  ck_assert_int_eq(1, is_not_equal(num1, num2));
}
END_TEST

START_TEST(is_not_equal_false) {  // 1337 != 1337 == 0 no
  decimal num1 = {0};
  from_int_to_decimal(1337, &num1);
  decimal num2 = {0};
  from_int_to_decimal(1337, &num2);
  ck_assert_int_eq(0, is_not_equal(num1, num2));
}
END_TEST

// //================= converter functions tests =================
// from_int_to_decimal
START_TEST(part1_conv_int) {
  int a = 123123;
  decimal result = {0};
  from_int_to_decimal(a, &result);
  ck_assert_uint_eq(result.bits[0], a);
  ck_assert_int_eq(get_sign(result), 0);
  ck_assert_int_eq(get_scale(result), 0);
  a = 2147483647;
  from_int_to_decimal(a, &result);
  ck_assert_uint_eq(result.bits[0], a);
  ck_assert_int_eq(get_sign(result), 0);
  ck_assert_int_eq(get_scale(result), 0);
  a = -2147483648;
  from_int_to_decimal(a, &result);
  ck_assert_uint_eq(result.bits[0], 2147483648);
  ck_assert_int_eq(get_sign(result), 1);
  ck_assert_int_eq(get_scale(result), 0);

  a = 0;
  decimal temp;
  init_decimal(&temp);
  temp.bits[0] = 1U;
  set_sign(&temp, 1);
  from_decimal_to_int(temp, &a);
  ck_assert_int_eq(a, -1);

  a = 0;
  init_decimal(&temp);
  temp.bits[0] = 1U;
  temp.bits[3] = 0;
  from_decimal_to_int(temp, &a);
  ck_assert_int_eq(a, 1);

  a = 0;
  init_decimal(&temp);
  temp.bits[0] = 123;
  temp.bits[1] = 123;
  int res = 0;
  res = from_decimal_to_int(temp, &a);
  ck_assert_uint_eq(res, 1);
}
END_TEST

// FLOAT

START_TEST(part1_conv_float) {
  decimal temp;
  init_decimal(&temp);
  float a = 0.0;
  from_float_to_decimal(a, &temp);
  ck_assert_int_eq(temp.bits[0], 0);
  ck_assert_int_eq(get_sign(temp), 0);

  init_decimal(&temp);
  a = 20.0;
  from_float_to_decimal(a, &temp);
  ck_assert_int_eq(temp.bits[0], 20);
  ck_assert_int_eq(get_sign(temp), 0);
  ck_assert_int_eq(get_scale(temp), 0);

  init_decimal(&temp);
  a = -20.0;
  from_float_to_decimal(a, &temp);
  ck_assert_int_eq(temp.bits[0], 20);
  ck_assert_int_eq(get_sign(temp), 1);
  ck_assert_int_eq(get_scale(temp), 0);

  init_decimal(&temp);
  a = 0.0 / 0.0;
  int res = from_float_to_decimal(a, &temp);
  ck_assert_int_eq(res, 1);

  init_decimal(&temp);
  a = 1.0 / 0.0;
  res = 0;
  res = from_float_to_decimal(a, &temp);
  ck_assert_int_eq(res, 1);

  init_decimal(&temp);
  a = -1.0 / 0.0;
  res = 0;
  res = from_float_to_decimal(a, &temp);
  ck_assert_int_eq(res, 1);

  init_decimal(&temp);
  a = 0;
  temp.bits[0] = 45;
  set_scale(&temp, 1);
  from_decimal_to_float(temp, &a);
  ck_assert_float_eq(a, 4.5);

  init_decimal(&temp);
  a = 0;
  temp.bits[0] = 45;
  set_scale(&temp, 1);
  set_sign(&temp, 1);
  from_decimal_to_float(temp, &a);
  ck_assert_float_eq(a, -4.5);
}
END_TEST

//================= other functions tests =================
// negate =================>
START_TEST(part1_negate_zero) {
  decimal value_1 = {0};
  decimal result = {0};
  decimal test = {0};
  negate(value_1, &result);
  ck_assert_uint_eq(result.bits[0], test.bits[0]);
  ck_assert_int_eq(get_sign(result), 1);
}
END_TEST

START_TEST(part2_negate_zero_signed) {
  decimal value_1 = {0};
  decimal result = {0};
  decimal test = {0};
  set_sign(&value_1, 1);
  negate(value_1, &result);
  ck_assert_uint_eq(result.bits[0], test.bits[0]);
  ck_assert_int_eq(get_sign(result), 0);
}
END_TEST

START_TEST(part3_negate_one) {
  decimal value_1 = {{1, 0, 0, 0}};
  decimal result = {0};
  decimal test = {{1, 0, 0, 0}};
  // set_sign(&test, 1);
  negate(value_1, &result);
  ck_assert_uint_eq(result.bits[0], test.bits[0]);
  ck_assert_int_eq(get_sign(result), 1);
}
END_TEST

START_TEST(part4_negate_one_signed) {
  decimal value_1 = {{1, 0, 0, 0}};
  decimal result = {0};
  decimal test = {{1, 0, 0, 0}};
  set_sign(&value_1, 1);
  negate(value_1, &result);
  ck_assert_uint_eq(result.bits[0], test.bits[0]);
  ck_assert_int_eq(get_sign(result), 0);
}
END_TEST

START_TEST(part5_negate_num) {
  decimal value_1 = {{422142, 0, 0, 0}};
  decimal result = {0};
  decimal test = {{422142}};
  negate(value_1, &result);
  ck_assert_uint_eq(result.bits[0], test.bits[0]);
  ck_assert_int_eq(get_sign(result), 1);
}
END_TEST

START_TEST(part6_negate_num_signed) {
  decimal value_1 = {{422142, 0, 0, 0}};
  decimal result = {0};
  decimal test = {{422142, 0, 0, 0}};
  set_sign(&value_1, 1);
  negate(value_1, &result);
  ck_assert_uint_eq(result.bits[0], test.bits[0]);
  ck_assert_int_eq(get_sign(result), 0);
}
END_TEST

START_TEST(part7_negate_pow) {
  decimal value_1 = {{422142, 0, 0, 0}};
  decimal result = {0};
  decimal test = {{422142, 0, 0, 0}};
  set_scale(&value_1, 2);
  negate(value_1, &result);
  ck_assert_uint_eq(result.bits[0], test.bits[0]);
  ck_assert_int_eq(get_sign(result), 1);
  ck_assert_int_eq(get_scale(result), 2);
}
END_TEST

START_TEST(part8_negate_pow_signed) {
  decimal value_1 = {{422142, 0, 0, 0}};
  decimal result = {0};
  decimal test = {{422142, 0, 0, 0}};
  set_sign(&value_1, 1);
  set_scale(&value_1, 2);
  negate(value_1, &result);
  ck_assert_uint_eq(result.bits[0], test.bits[0]);
  ck_assert_int_eq(get_sign(result), 0);
  ck_assert_int_eq(get_scale(result), 2);
}
END_TEST

// truncate =================>
START_TEST(part1_truncate_zero) {
  decimal value_1 = {0};
  decimal result = {0};
  decimal test = {0};
  truncate(value_1, &result);
  ck_assert_uint_eq(result.bits[0], test.bits[0]);
  ck_assert_int_eq(get_sign(result), 0);
  ck_assert_int_eq(get_scale(result), 0);

  set_sign(&value_1, 1);
  truncate(value_1, &result);
  ck_assert_uint_eq(result.bits[0], test.bits[0]);
  ck_assert_int_eq(get_sign(result), 1);
  ck_assert_int_eq(get_scale(result), 0);
}
END_TEST

START_TEST(part2_truncate_zero_pow) {
  decimal value_1 = {0};
  decimal result = {0};
  decimal test = {0};
  test.bits[0] = 0;
  set_scale(&value_1, 21);
  truncate(value_1, &result);
  ck_assert_uint_eq(result.bits[0], test.bits[0]);
  ck_assert_int_eq(get_sign(result), 0);
  ck_assert_int_eq(get_scale(result), 0);

  set_sign(&value_1, 1);
  truncate(value_1, &result);
  ck_assert_uint_eq(result.bits[0], test.bits[0]);
  ck_assert_int_eq(get_sign(result), 1);
  ck_assert_int_eq(get_scale(result), 0);
}
END_TEST

START_TEST(part3_truncate_one) {
  decimal value_1 = {0};
  decimal result = {0};
  decimal test = {0};
  value_1.bits[0] = 1;
  test.bits[0] = 1;
  truncate(value_1, &result);
  ck_assert_uint_eq(result.bits[0], test.bits[0]);
  ck_assert_int_eq(get_sign(result), 0);
  ck_assert_int_eq(get_scale(result), 0);

  set_sign(&value_1, 1);
  truncate(value_1, &result);
  ck_assert_uint_eq(result.bits[0], test.bits[0]);
  ck_assert_int_eq(get_sign(result), 1);
  ck_assert_int_eq(get_scale(result), 0);
}
END_TEST

START_TEST(part4_truncate_num1) {
  decimal value_1 = {{422142, 0, 0, 0}};
  decimal result = {0};
  decimal test = {{422142, 0, 0, 0}};
  truncate(value_1, &result);
  ck_assert_uint_eq(result.bits[0], test.bits[0]);
  ck_assert_int_eq(get_sign(result), 0);
  ck_assert_int_eq(get_scale(result), 0);

  set_sign(&value_1, 1);
  truncate(value_1, &result);
  ck_assert_uint_eq(result.bits[0], test.bits[0]);
  ck_assert_int_eq(get_sign(result), 1);
  ck_assert_int_eq(get_scale(result), 0);
}
END_TEST

START_TEST(part5_truncate_num2) {
  decimal value_1 = {{422142, 0, 422142, 0}};
  decimal result = {0};
  decimal test = {{422142, 0, 422142, 0}};
  truncate(value_1, &result);
  ck_assert_uint_eq(result.bits[0], test.bits[0]);
  ck_assert_uint_eq(result.bits[2], test.bits[2]);
  ck_assert_int_eq(get_sign(result), 0);
  ck_assert_int_eq(get_scale(result), 0);

  set_sign(&value_1, 1);
  truncate(value_1, &result);
  ck_assert_uint_eq(result.bits[0], test.bits[0]);
  ck_assert_uint_eq(result.bits[2], test.bits[2]);
  ck_assert_int_eq(get_sign(result), 1);
  ck_assert_int_eq(get_scale(result), 0);
}
END_TEST

START_TEST(part6_truncate_pow1) {
  decimal value_1 = {{422142, 0, 0, 0}};
  decimal result = {0};
  decimal test = {{422, 0, 0, 0}};
  set_scale(&value_1, 3);
  truncate(value_1, &result);
  ck_assert_uint_eq(result.bits[0], test.bits[0]);
  ck_assert_int_eq(get_sign(result), 0);
  ck_assert_int_eq(get_scale(result), 0);

  set_sign(&value_1, 1);
  truncate(value_1, &result);
  ck_assert_uint_eq(result.bits[0], test.bits[0]);
  ck_assert_int_eq(get_sign(result), 1);
  ck_assert_int_eq(get_scale(result), 0);
}
END_TEST

START_TEST(part7_truncate_pow2) {
  decimal value_1 = {{422142, 422142, 0, 0}};
  decimal result = {0};
  decimal test = {{609885778, 422, 0, 0}};
  set_scale(&value_1, 3);
  truncate(value_1, &result);
  ck_assert_uint_eq(result.bits[0], test.bits[0]);
  ck_assert_uint_eq(result.bits[1], test.bits[1]);
  ck_assert_int_eq(get_sign(result), 0);
  ck_assert_int_eq(get_scale(result), 0);

  set_sign(&value_1, 1);
  truncate(value_1, &result);
  ck_assert_uint_eq(result.bits[0], test.bits[0]);
  ck_assert_uint_eq(result.bits[1], test.bits[1]);
  ck_assert_int_eq(get_sign(result), 1);
  ck_assert_int_eq(get_scale(result), 0);
}
END_TEST

START_TEST(part8_truncate_pow3) {
  decimal value_1 = {{422142, 422142, 0, 0}};
  decimal result = {0};
  decimal test = {{181308, 0, 0, 0}};
  set_scale(&value_1, 10);
  truncate(value_1, &result);
  ck_assert_uint_eq(result.bits[0], test.bits[0]);
  ck_assert_uint_eq(result.bits[1], test.bits[1]);
  ck_assert_int_eq(get_sign(result), 0);
  ck_assert_int_eq(get_scale(result), 0);

  set_sign(&value_1, 1);
  truncate(value_1, &result);
  ck_assert_uint_eq(result.bits[0], test.bits[0]);
  ck_assert_uint_eq(result.bits[1], test.bits[1]);
  ck_assert_int_eq(get_sign(result), 1);
  ck_assert_int_eq(get_scale(result), 0);
}
END_TEST

// my_floor =================>
START_TEST(part1_my_floor_zero) {
  decimal value_1 = {0};
  decimal result = {0};
  decimal test = {0};
  set_scale(&value_1, 1);
  my_floor(value_1, &result);
  ck_assert_uint_eq(result.bits[0], test.bits[0]);
  ck_assert_int_eq(get_sign(result), 0);
  ck_assert_int_eq(get_scale(result), 0);

  set_sign(&value_1, 1);
  my_floor(value_1, &result);
  ck_assert_uint_eq(result.bits[0], test.bits[0]);
  ck_assert_int_eq(get_sign(result), 1);
  ck_assert_int_eq(get_scale(result), 0);
}
END_TEST

START_TEST(part2_my_floor_one) {
  decimal value_1 = {{1, 0, 0, 0}};
  decimal result = {0};
  decimal test = {{1, 0, 0, 0}};
  my_floor(value_1, &result);
  ck_assert_uint_eq(result.bits[0], test.bits[0]);
  ck_assert_int_eq(get_sign(result), 0);
  ck_assert_int_eq(get_scale(result), 0);

  set_sign(&value_1, 1);
  my_floor(value_1, &result);
  ck_assert_uint_eq(result.bits[0], test.bits[0]);
  ck_assert_int_eq(get_sign(result), 1);
  ck_assert_int_eq(get_scale(result), 0);
}
END_TEST

START_TEST(part3_my_floor_num) {
  decimal value_1 = {{422142, 0, 422142, 0}};
  decimal result = {0};
  decimal test = {{422142, 0, 422142, 0}};
  my_floor(value_1, &result);
  ck_assert_uint_eq(result.bits[0], test.bits[0]);
  ck_assert_uint_eq(result.bits[2], test.bits[2]);
  ck_assert_int_eq(get_sign(result), 0);
  ck_assert_int_eq(get_scale(result), 0);

  set_sign(&value_1, 1);
  my_floor(value_1, &result);
  ck_assert_uint_eq(result.bits[0], test.bits[0]);
  ck_assert_uint_eq(result.bits[2], test.bits[2]);
  ck_assert_int_eq(get_sign(result), 1);
  ck_assert_int_eq(get_scale(result), 0);
}
END_TEST

START_TEST(part4_my_floor_pow1) {
  decimal value_1 = {{422142, 0, 0, 0}};
  decimal result = {0};
  decimal test = {{422, 0, 0, 0}};
  set_scale(&value_1, 3);
  my_floor(value_1, &result);
  ck_assert_uint_eq(result.bits[0], test.bits[0]);
  ck_assert_int_eq(get_sign(result), 0);
  ck_assert_int_eq(get_scale(result), 0);

  test.bits[0] = 423;
  set_sign(&value_1, 1);
  my_floor(value_1, &result);
  ck_assert_uint_eq(result.bits[0], test.bits[0]);
  ck_assert_int_eq(get_sign(result), 1);
  ck_assert_int_eq(get_scale(result), 0);
}
END_TEST

START_TEST(part5_my_floor_pow2) {
  decimal value_1 = {{422142, 422142, 0, 0}};
  decimal result = {0};
  decimal test = {{609885778, 422, 0, 0}};
  set_scale(&value_1, 3);
  my_floor(value_1, &result);
  ck_assert_uint_eq(result.bits[0], test.bits[0]);
  ck_assert_uint_eq(result.bits[1], test.bits[1]);
  ck_assert_int_eq(get_sign(result), 0);
  ck_assert_int_eq(get_scale(result), 0);

  test.bits[0] = 609885779;
  set_sign(&value_1, 1);
  my_floor(value_1, &result);
  ck_assert_uint_eq(result.bits[0], test.bits[0]);
  ck_assert_uint_eq(result.bits[1], test.bits[1]);
  ck_assert_int_eq(get_sign(result), 1);
  ck_assert_int_eq(get_scale(result), 0);
}
END_TEST

START_TEST(part6_my_floor_pow3) {
  decimal value_1 = {{422942, 422142, 0, 0}};
  decimal result = {0};
  decimal test = {{181308, 422, 0, 0}};
  set_scale(&value_1, 10);
  my_floor(value_1, &result);
  ck_assert_uint_eq(result.bits[0], test.bits[0]);
  ck_assert_int_eq(get_sign(result), 0);
  ck_assert_int_eq(get_scale(result), 0);

  test.bits[0] = 181309;
  set_sign(&value_1, 1);
  my_floor(value_1, &result);
  ck_assert_uint_eq(result.bits[0], test.bits[0]);
  ck_assert_int_eq(get_sign(result), 1);
  ck_assert_int_eq(get_scale(result), 0);
}
END_TEST

// my_round =================>
START_TEST(part1_my_round_zero) {
  decimal value_1 = {0};
  decimal result = {0};
  decimal test = {0};
  set_scale(&value_1, 1);
  my_round(value_1, &result);
  ck_assert_uint_eq(result.bits[0], test.bits[0]);
  ck_assert_int_eq(get_sign(result), 0);
  ck_assert_int_eq(get_scale(result), 0);

  set_sign(&value_1, 1);
  my_round(value_1, &result);
  ck_assert_uint_eq(result.bits[0], test.bits[0]);
  ck_assert_int_eq(get_scale(result), 0);
}
END_TEST

START_TEST(part2_my_round_one) {
  decimal value_1 = {{1, 0, 0, 0}};
  decimal result = {0};
  decimal test = {{1, 0, 0, 0}};
  my_round(value_1, &result);
  ck_assert_uint_eq(result.bits[0], test.bits[0]);
  ck_assert_int_eq(get_sign(result), 0);
  ck_assert_int_eq(get_scale(result), 0);

  set_sign(&value_1, 1);
  my_round(value_1, &result);
  ck_assert_uint_eq(result.bits[0], test.bits[0]);
  ck_assert_int_eq(get_sign(result), 1);
  ck_assert_int_eq(get_scale(result), 0);
}
END_TEST

START_TEST(part3_my_round_num) {
  decimal value_1 = {{422142, 0, 0, 0}};
  decimal result = {0};
  decimal test = {{422142, 0, 0, 0}};
  my_round(value_1, &result);
  ck_assert_uint_eq(result.bits[0], test.bits[0]);
  ck_assert_int_eq(get_sign(result), 0);
  ck_assert_int_eq(get_scale(result), 0);

  set_sign(&value_1, 1);
  my_round(value_1, &result);
  ck_assert_uint_eq(result.bits[0], test.bits[0]);
  ck_assert_int_eq(get_sign(result), 1);
  ck_assert_int_eq(get_scale(result), 0);
}
END_TEST

START_TEST(part4_my_round_pow1) {
  decimal value_1 = {{4221425, 0, 0, 0}};
  decimal result = {0};
  decimal test = {{422143, 0, 0, 0}};
  set_scale(&value_1, 1);
  my_round(value_1, &result);
  ck_assert_uint_eq(result.bits[0], test.bits[0]);
  ck_assert_int_eq(get_sign(result), 0);
  ck_assert_int_eq(get_scale(result), 0);

  set_sign(&value_1, 1);
  my_round(value_1, &result);
  ck_assert_uint_eq(result.bits[0], test.bits[0]);
  ck_assert_int_eq(get_sign(result), 1);
  ck_assert_int_eq(get_scale(result), 0);
}
END_TEST

START_TEST(part5_my_round_pow2) {
  decimal value_1 = {{4221424, 0, 0, 0}};
  decimal result = {0};
  decimal test = {{422142, 0, 0, 0}};
  set_scale(&value_1, 1);
  my_round(value_1, &result);
  ck_assert_uint_eq(result.bits[0], test.bits[0]);
  ck_assert_int_eq(get_sign(result), 0);
  ck_assert_int_eq(get_scale(result), 0);

  set_sign(&value_1, 1);
  my_round(value_1, &result);
  ck_assert_uint_eq(result.bits[0], test.bits[0]);
  ck_assert_int_eq(get_sign(result), 1);
  ck_assert_int_eq(get_scale(result), 0);
}
END_TEST

START_TEST(part6_my_round_pow3) {
  decimal value_1 = {{4221426, 0, 0, 0}};
  decimal result = {0};
  decimal test = {{422143, 0, 0, 0}};
  set_scale(&value_1, 1);
  my_round(value_1, &result);
  ck_assert_uint_eq(result.bits[0], test.bits[0]);
  ck_assert_int_eq(get_sign(result), 0);
  ck_assert_int_eq(get_scale(result), 0);

  set_sign(&value_1, 1);
  my_round(value_1, &result);
  ck_assert_uint_eq(result.bits[0], test.bits[0]);
  ck_assert_int_eq(get_sign(result), 1);
  ck_assert_int_eq(get_scale(result), 0);
}
END_TEST

START_TEST(part7_my_round_pow4) {
  decimal value_1 = {{422142, 422142, 0, 0}};
  decimal result = {0};
  decimal test = {{609885778, 422, 0, 0}};
  set_scale(&value_1, 3);
  my_round(value_1, &result);
  ck_assert_uint_eq(result.bits[0], test.bits[0]);
  ck_assert_int_eq(get_sign(result), 0);
  ck_assert_int_eq(get_scale(result), 0);

  set_sign(&value_1, 1);
  my_round(value_1, &result);
  ck_assert_uint_eq(result.bits[0], test.bits[0]);
  ck_assert_int_eq(get_sign(result), 1);
  ck_assert_int_eq(get_scale(result), 0);
}
END_TEST

START_TEST(part8_my_round_pow5) {
  decimal value_1 = {{420521, 422142, 0, 0}};
  decimal result = {0};
  decimal test = {{609885777, 422, 0, 0}};
  set_scale(&value_1, 3);
  my_round(value_1, &result);
  ck_assert_uint_eq(result.bits[0], test.bits[0]);
  ck_assert_int_eq(get_sign(result), 0);
  ck_assert_int_eq(get_scale(result), 0);

  set_sign(&value_1, 1);
  my_round(value_1, &result);
  ck_assert_uint_eq(result.bits[0], test.bits[0]);
  ck_assert_int_eq(get_sign(result), 1);
  ck_assert_int_eq(get_scale(result), 0);
}
END_TEST

START_TEST(addition_test) {
  decimal result,
      val1[7] = {{{0}},
                 {{21, 0, 0, -2147483648}},
                 {{42, 0, 0, 0}},
                 {390078125, 0, 0, -2147024896},
                 {76540625, 0, 0, 262144},
                 {{-1, -1, -1, 0}},
                 {{-1, -1, -1, -2147483648}}},
      val2[7] = {{{0}},
                 {{21, 0, 0, -2147483648}},
                 {{21, 0, 0, -2147483648}},
                 {1261658125, 0, 0, 458752},
                 {1261658175, 0, 0, 458752},
                 {{21, 0, 0, 0}},
                 {{21, 0, 0, -2147483648}}};
  int answers[5][4] = {{0},
                       {42, 0, 0, -2147483648},
                       {21, 0, 0, 0},
                       {871580000, 0, 0, 458752},
                       {492871847, 18, 0, 458752}};
  for (int i = 0; i < 5; i++) {
    add(val1[i], val2[i], &result);
    for (int j = 0; j < 4; j++) {
      ck_assert(result.bits[j] == answers[i][j]);
    };
  };
  ck_assert(add(val1[5], val2[5], &result) == 1);
  ck_assert(add(val1[6], val2[6], &result) == 2);
}
END_TEST

START_TEST(substraction) {
  decimal result,
      val1[7] = {{{0}},
                 {{42, 0, 0, -2147483648}},
                 {{42, 0, 0, 0}},
                 {390078125, 0, 0, -2147024896},
                 {76540625, 0, 0, 262144},
                 {{-1, -1, -1, 0}},
                 {{-1, -1, -1, -2147483648}}},
      val2[7] = {{{0}},
                 {{21, 0, 0, -2147483648}},
                 {{21, 0, 0, -2147483648}},
                 {1261658125, 0, 0, 458752},
                 {1261658175, 0, 0, 458752},
                 {{21, 0, 0, -2147483648}},
                 {{21, 0, 0, 0}}};
  int answers[5][4] = {{0},
                       {21, 0, 0, -2147483648},
                       {63, 0, 0, 0},
                       {1651736250, 0, 0, -2147024896},
                       {-2030444503, 17, 0, 458752}};
  for (int i = 0; i < 5; i++) {
    sub(val1[i], val2[i], &result);
    for (int j = 0; j < 4; j++) {
      ck_assert(result.bits[j] == answers[i][j]);
    };
  };
  ck_assert(sub(val1[5], val2[5], &result) == 1);
  ck_assert(sub(val1[6], val2[6], &result) == 2);
}
END_TEST

START_TEST(multiplication) {
  decimal result,
      val1[6] = {{{0}},
                 {{21, 0, 0, -2147483648}},
                 {{42, 0, 0, 0}},
                 {{8125, 0, 0, -2147287040}},
                 {{-1, -1, -1, 0}},
                 {{-1, -1, -1, -2147483648}}},
      val2[6] = {{{0}},
                 {{0, 0, 2, -2147483648}},
                 {{5, 0, 0, -2147418112}},
                 {{44, 0, 0, -2147352576}},
                 {{21, 0, 0, 0}},
                 {{21, 0, 21, 0}}};
  int answers[4][4] = {
      {0}, {0, 0, 42, 0}, {210, 0, 0, -2147418112}, {357500, 0, 0, 327680}};
  for (int i = 0; i < 4; i++) {
    mul(val1[i], val2[i], &result);
    for (int j = 0; j < 4; j++) {
      ck_assert(result.bits[j] == answers[i][j]);
    };
  };
  // ck_assert(mul(val1[5], val2[5], &result) == 1);
  // ck_assert(mul(val1[6], val2[6], &result) == 2);
}
END_TEST

// 4+
START_TEST(division) {
  decimal result,
      val1[5] = {{{0}},
                 {{42, 0, 0, -2147483648}},
                 {{42, 0, 0, 0}},
                 {{-1, -1, -1, 0}},
                 {{-1, -1, -1, -2147483648}}},

      val2[5] = {{{1, 0, 0, 0}},
                 {{2, 0, 0, -2147483648}},
                 {{21, 0, 0, -2147483648}},
                 {{5, 0, 0, -2147418112}},
                 {{5, 0, 0, -2147418112}}};

  int answers[5][4] = {
      {0},
      {21, 0, 0, 0},
      {2, 0, 0, -2147483648},
  };

  for (int i = 0; i < 3; i++) {
    div(val1[i], val2[i], &result);
    for (int j = 0; j < 4; j++) {
      ck_assert(result.bits[j] == answers[i][j]);
    };
  };
  // ck_assert(div(val1[5], val2[5], &result) == 2);
  // ck_assert(div(val1[6], val2[6], &result) == 1);
  ck_assert(div(val1[1], val1[0], &result) == 3);
}
END_TEST

START_TEST(less) {
  decimal val2[5] = {{{0}},
                         {{21, 0, 1, 0}},
                         {{42, 0, 0, -2147483648}},
                         {{21, 0, 0, 0}},
                         {{42, 0, 0, -2147483648}}},
              val1[5] = {{{0}},
                         {{21, 1, 0, 0}},
                         {{42, 1, 0, -2147483648}},
                         {{21, 0, 0, -2147483648}},
                         {{42, 0, 0, -2147287040}}};
  int answers[5] = {0, 1, 1, 1, 0};
  for (int i = 0; i < 5; i++) {
    ck_assert(is_less(val1[i], val2[i]) == answers[i]);
  };
}
END_TEST

START_TEST(less_equal) {
  decimal val2[5] = {{{0}},
                         {{21, 0, 1, 0}},
                         {{42, 0, 0, -2147483648}},
                         {{21, 0, 0, 0}},
                         {{42, 0, 0, -2147483648}}},
              val1[5] = {{{0}},
                         {{21, 1, 0, 0}},
                         {{42, 1, 0, -2147483648}},
                         {{21, 0, 0, -2147483648}},
                         {{42, 0, 0, -2147287040}}};
  int answers[5] = {1, 1, 1, 1, 0};
  for (int i = 0; i < 5; i++) {
    ck_assert(is_less_or_equal(val1[i], val2[i]) == answers[i]);
  };
}
END_TEST

START_TEST(greater) {
  decimal val1[5] = {{{0}},
                         {{21, 0, 1, 0}},
                         {{42, 0, 0, -2147483648}},
                         {{21, 0, 0, 0}},
                         {{42, 0, 0, -2147483648}}},
              val2[5] = {{{0}},
                         {{21, 1, 0, 0}},
                         {{42, 1, 0, -2147483648}},
                         {{21, 0, 0, -2147483648}},
                         {{42, 0, 0, -2147287040}}};
  int answers[5] = {0, 1, 1, 1, 0};
  for (int i = 0; i < 5; i++) {
    ck_assert(is_greater(val1[i], val2[i]) == answers[i]);
  };
}
END_TEST

START_TEST(greater_equal) {
  decimal val1[5] = {{{0}},
                         {{21, 0, 1, 0}},
                         {{42, 0, 0, -2147483648}},
                         {{21, 0, 0, 0}},
                         {{42, 0, 0, -2147483648}}},
              val2[5] = {{{0}},
                         {{21, 1, 0, 0}},
                         {{42, 1, 0, -2147483648}},
                         {{21, 0, 0, -2147483648}},
                         {{42, 0, 0, -2147287040}}};
  int answers[5] = {1, 1, 1, 1, 0};
  for (int i = 0; i < 5; i++) {
    ck_assert(is_greater_or_equal(val1[i], val2[i]) == answers[i]);
  };
}
END_TEST

START_TEST(equal) {
  decimal val1[5] = {{{0}},
                         {{21, 0, 0, 0}},
                         {{42, 0, 0, -2147483648}},
                         {{21, 0, 0, 0}},
                         {{42, 0, 0, -2147483648}}},
              val2[5] = {{{0}},
                         {{21, 0, 1, 0}},
                         {{42, 0, 0, -2147483648}},
                         {{21, 0, 0, 0}},
                         {{42, 0, 0, 196608}}};
  int answers[5] = {1, 0, 1, 1, 0};
  for (int i = 0; i < 5; i++) {
    ck_assert(is_equal(val1[i], val2[i]) == answers[i]);
  };
}
END_TEST

START_TEST(not_equal) {
  decimal val1[5] = {{{0}},
                         {{21, 0, 0, 0}},
                         {{42, 0, 0, -2147483648}},
                         {{21, 0, 0, 0}},
                         {{42, 0, 0, -2147483648}}},
              val2[5] = {{{0}},
                         {{21, 0, 1, 0}},
                         {{42, 0, 0, -2147483648}},
                         {{21, 0, 0, 0}},
                         {{42, 0, 0, 196608}}};
  int answers[5] = {0, 1, 0, 0, 1};
  for (int i = 0; i < 5; i++) {
    ck_assert(is_not_equal(val1[i], val2[i]) == answers[i]);
  };
}
END_TEST

START_TEST(int_to_decimal) {
  decimal dst;
  int src[5] = {-0, 21, -42, 2147483647, -2147483648};
  int answers[5][4] = {{0},
                       {21, 0, 0, 0},
                       {42, 0, 0, -2147483648},
                       {2147483647, 0, 0, 0},
                       {-2147483648, 0, 0, -2147483648}};
  for (int i = 0; i < 5; i++) {
    from_int_to_decimal(src[i], &dst);
    for (int j = 0; j < 4; j++) {
      ck_assert(dst.bits[j] == answers[i][j]);
    };
  };
}
END_TEST

START_TEST(float_to_decimal) {
  decimal dst;
  float src[7] = {0.0,         -0.25,       0.9876543210,    -39.0078125,
                  -7654.06250, 14294967296, -624192697401344};
  int answers[7][4] = {{0},
                       {25, 0, 0, -2147352576},
                       {9876543, 0, 0, 458752},
                       {390078125, 0, 0, -2147024896},
                       {76540625, 0, 0, -2147221504},
                       {1410065408, 3, 0, 0},
                       {805306368, 145331, 0, -2147483648}};
  for (int i = 0; i < 7; i++) {
    from_float_to_decimal(src[i], &dst);
    for (int j = 0; j < 4; j++) {
      ck_assert(dst.bits[j] == answers[i][j]);
    };
  };
  ck_assert(from_float_to_decimal(1.0 / 0.0, &dst) == 1);
  ck_assert(from_float_to_decimal(-1.0 / 0.0, &dst) == 1);
  ck_assert(from_float_to_decimal(8e31, &dst) == 1);
}
END_TEST

// 13+
START_TEST(decimal_to_int) {
  decimal src[4] = {{{0}},
                        {{21, 0, 0, 0}},
                        {{4221, 0, 0, 131072}},
                        {{2142, 0, 0, -2147352576}}};
  int dst, answer[4] = {0, 21, 42, -21};
  for (int i = 0; i < 4; i++) {
    from_decimal_to_int(src[i], &dst);
    ck_assert(dst == answer[i]);
  };
}
END_TEST

START_TEST(decimal_to_float) {
  decimal src[4] = {{{0}},
                        {{42, 0, 0, 0}},
                        {{4221, 0, 0, 131072}},
                        {{2142, 0, 0, -2147352576}}};
  float dst, answer[4] = {0.0, 42.0, 42.21, -21.42};
  for (int i = 0; i < 4; i++) {
    from_decimal_to_float(src[i], &dst);
    ck_assert(dst == answer[i]);
  };
}
END_TEST

START_TEST(dec_my_floor) {
  decimal result, value[4] = {{{0}},
                                  {{42, 0, 0, 0}},
                                  {{2199, 0, 0, 131072}},
                                  {{2142, 0, 0, -2147352576}}};
  int answer[4][4] = {
      {0}, {42, 0, 0, 0}, {21, 0, 0, 0}, {22, 0, 0, -2147483648}};
  for (int i = 0; i < 4; i++) {
    my_floor(value[i], &result);
    for (int j = 0; j < 4; j++) {
      ck_assert(result.bits[j] == answer[i][j]);
    };
  };
}
END_TEST

START_TEST(dec_my_round) {
  decimal result, value[4] = {{{0}},
                                  {{42, 0, 0, 0}},
                                  {{2177, 0, 0, 131072}},
                                  {{2142, 0, 0, -2147352576}}};
  int answer[4][4] = {
      {0}, {42, 0, 0, 0}, {22, 0, 0, 0}, {21, 0, 0, -2147483648}};
  for (int i = 0; i < 4; i++) {
    my_round(value[i], &result);
    for (int j = 0; j < 4; j++) {
      ck_assert(result.bits[j] == answer[i][j]);
    };
  };
}
END_TEST

START_TEST(truncate_test) {
  decimal result, value[4] = {{{0}},
                                  {{21, 0, 0, 0}},
                                  {{4221, 0, 0, 131072}},
                                  {{2142, 0, 0, -2147352576}}};
  int answer[4][4] = {
      {0}, {21, 0, 0, 0}, {42, 0, 0, 0}, {21, 0, 0, -2147483648}};
  for (int i = 0; i < 4; i++) {
    truncate(value[i], &result);
    for (int j = 0; j < 4; j++) {
      ck_assert(result.bits[j] == answer[i][j]);
    };
  };
}
END_TEST

START_TEST(negate_test) {
  decimal result,
      values[3] = {{{0}}, {{21, 0, 0, 0}}, {{42, 0, 0, -2147483648}}};
  int answers[3][4] = {{0}, {21, 0, 0, -2147483648}, {42, 0, 0, 0}};
  for (int i = 0; i < 3; i++) {
    negate(values[i], &result);
    for (int j = 0; j < 4; j++) {
      ck_assert(result.bits[j] == answers[i][j]);
    };
  };
}
END_TEST

// dec_output(value_1); printf("\n"); dec_output(test); printf("\n");
// dec_output(result); printf("\n"); dec_output(test); printf("\n");
// printf("\n%d %d\n", result.bits[0], test.bits[0]);

//================= SUITES =================
Suite *arithmetic_test_suite() {
  Suite *s = suite_create("arithmetic_test_suite");
  TCase *tc_add = tcase_create("tc_add");
  TCase *tc_sub = tcase_create("tc_sub");
  TCase *tc_mult = tcase_create("tc_mult");
  TCase *tc_div = tcase_create("tc_div");
  // TCase *tc_div = tcase_create("tc_div");

  tcase_add_test(tc_add, part1_add_normal);
  tcase_add_test(tc_add, part1_add_both_neg);
  tcase_add_test(tc_add, part1_add_error);
  tcase_add_test(tc_add, part1_add_one_sign);
  tcase_add_test(tc_add, part1_add_one_greater);

  tcase_add_test(tc_sub, part1_sub_normal);
  tcase_add_test(tc_sub, part1_sub_inf);
  tcase_add_test(tc_sub, part1_sub_one_sign);
  tcase_add_test(tc_sub, part1_sub_two_sign);

  tcase_add_test(tc_mult, part1_mult_value_1_is_one);
  tcase_add_test(tc_mult, part1_mult_value_2_is_one);
  tcase_add_test(tc_mult, part1_mult_value_1_is_zero);
  tcase_add_test(tc_mult, part1_mult_value_2_is_zero);
  tcase_add_test(tc_mult, part1_mult_max);
  tcase_add_test(tc_mult, part1_mult_big_power);
  tcase_add_test(tc_mult, part1_mult_big_over);
  tcase_add_test(tc_mult, part1_mult_big_negative_over);
  tcase_add_test(tc_mult, part1_mult_value_1_is_minus);
  tcase_add_test(tc_mult, part1_mult_value_2_is_minus);
  tcase_add_test(tc_mult, part1_mult_value_1_is_zero_minus);
  tcase_add_test(tc_mult, part1_mult_value_2_is_zero_minus);
  tcase_add_test(tc_mult, part1_mult_value_1_2_is_minus);

  tcase_add_test(tc_div, div_0);
  tcase_add_test(tc_div, div_1);
  tcase_add_test(tc_div, div_2);
  tcase_add_test(tc_div, div_3);
  tcase_add_test(tc_div, div_4);
  tcase_add_test(tc_div, div_5);
  tcase_add_test(tc_div, div_6);
  tcase_add_test(tc_div, div_7);
  tcase_add_test(tc_div, div_8);

  Suite *suite_s21 = suite_create("suite");
  TCase *tcase_s21 = tcase_create("tcase");

  tcase_add_test(tcase_s21, addition_test);
  tcase_add_test(tcase_s21, substraction);
  tcase_add_test(tcase_s21, multiplication);
  tcase_add_test(tcase_s21, division);
  tcase_add_test(tcase_s21, less);
  tcase_add_test(tcase_s21, less_equal);
  tcase_add_test(tcase_s21, greater);
  tcase_add_test(tcase_s21, greater_equal);
  tcase_add_test(tcase_s21, equal);
  tcase_add_test(tcase_s21, not_equal);
  tcase_add_test(tcase_s21, int_to_decimal);
  tcase_add_test(tcase_s21, float_to_decimal);
  tcase_add_test(tcase_s21, decimal_to_int);
  tcase_add_test(tcase_s21, decimal_to_float);
  tcase_add_test(tcase_s21, dec_my_floor);
  tcase_add_test(tcase_s21, dec_my_round);
  tcase_add_test(tcase_s21, truncate_test);
  tcase_add_test(tcase_s21, negate_test);

  suite_add_tcase(suite_s21, tcase_s21);
  suite_add_tcase(s, tc_add);
  suite_add_tcase(s, tc_sub);
  suite_add_tcase(s, tc_mult);
  suite_add_tcase(s, tc_div);

  return s;
}

Suite *comparison_test_suite(void) {
  Suite *s = suite_create("comparison_test_suite");

  TCase *is_less = tcase_create("IS_LESS");
  tcase_add_test(is_less, is_less_plus_both);
  tcase_add_test(is_less, is_less_min_num1);
  tcase_add_test(is_less, is_less_min_num2);
  tcase_add_test(is_less, is_less_min_both);
  suite_add_tcase(s, is_less);

  TCase *is_greater = tcase_create("IS_GREATER");
  tcase_add_test(is_greater, is_greater_plus_both);
  tcase_add_test(is_greater, is_greater_min_num1);
  tcase_add_test(is_greater, is_greater_min_num2);
  tcase_add_test(is_greater, is_greater_min_both);
  suite_add_tcase(s, is_greater);

  TCase *is_less_or_equal = tcase_create("IS_LESS_OR_EQUAL");
  tcase_add_test(is_less_or_equal, is_less_or_equal_num1_less);
  tcase_add_test(is_less_or_equal, is_less_or_equal_num2_less);
  tcase_add_test(is_less_or_equal, is_less_or_equal_both_equal);
  suite_add_tcase(s, is_less_or_equal);

  TCase *is_greater_or_equal = tcase_create("IS_GREATER_OR_EQUAL");
  tcase_add_test(is_greater_or_equal, is_greater_or_equal_num1_less);
  tcase_add_test(is_greater_or_equal, is_greater_or_equal_num2_less);
  tcase_add_test(is_greater_or_equal, is_greater_or_equal_both_equal);
  suite_add_tcase(s, is_greater_or_equal);

  TCase *is_equal = tcase_create("IS_EQUAL");
  tcase_add_test(is_equal, is_equal_false);
  tcase_add_test(is_equal, is_equal_true);
  tcase_add_test(is_equal, is_equal_min_num1);
  tcase_add_test(is_equal, is_equal_min_num2);
  tcase_add_test(is_equal, is_equal_min_both);
  suite_add_tcase(s, is_equal);

  TCase *is_not_equal = tcase_create("IS_NOT_EQUAL");
  tcase_add_test(is_not_equal, is_not_equal_false);
  tcase_add_test(is_not_equal, is_not_equal_true);
  suite_add_tcase(s, is_not_equal);

  return s;
}

Suite *converter_test_suite() {
  Suite *s = suite_create("converter_test_suite");

  TCase *tc_int = tcase_create("tc_int");
  TCase *tc_float = tcase_create("tc_float");

  tcase_add_test(tc_int, part1_conv_int);
  tcase_add_test(tc_float, part1_conv_float);

  suite_add_tcase(s, tc_int);
  suite_add_tcase(s, tc_float);

  return s;
}

Suite *other_test_suite() {
  Suite *s = suite_create("other_test_suite");

  TCase *tc_negate = tcase_create("tc_negate");
  TCase *tc_truncate = tcase_create("tc_truncate");
  TCase *tc_my_floor = tcase_create("tc_my_floor");
  TCase *tc_my_round = tcase_create("tc_my_round");

  tcase_add_test(tc_negate, part1_negate_zero);
  tcase_add_test(tc_negate, part2_negate_zero_signed);
  tcase_add_test(tc_negate, part3_negate_one);
  tcase_add_test(tc_negate, part4_negate_one_signed);
  tcase_add_test(tc_negate, part5_negate_num);
  tcase_add_test(tc_negate, part6_negate_num_signed);
  tcase_add_test(tc_negate, part7_negate_pow);
  tcase_add_test(tc_negate, part8_negate_pow_signed);

  tcase_add_test(tc_truncate, part1_truncate_zero);
  tcase_add_test(tc_truncate, part2_truncate_zero_pow);
  tcase_add_test(tc_truncate, part3_truncate_one);
  tcase_add_test(tc_truncate, part4_truncate_num1);
  tcase_add_test(tc_truncate, part5_truncate_num2);
  tcase_add_test(tc_truncate, part6_truncate_pow1);
  tcase_add_test(tc_truncate, part7_truncate_pow2);
  tcase_add_test(tc_truncate, part8_truncate_pow3);

  tcase_add_test(tc_my_floor, part1_my_floor_zero);
  tcase_add_test(tc_my_floor, part2_my_floor_one);
  tcase_add_test(tc_my_floor, part3_my_floor_num);
  tcase_add_test(tc_my_floor, part4_my_floor_pow1);
  tcase_add_test(tc_my_floor, part5_my_floor_pow2);
  tcase_add_test(tc_my_floor, part6_my_floor_pow3);

  tcase_add_test(tc_my_round, part1_my_round_zero);
  tcase_add_test(tc_my_round, part2_my_round_one);
  tcase_add_test(tc_my_round, part3_my_round_num);
  tcase_add_test(tc_my_round, part4_my_round_pow1);
  tcase_add_test(tc_my_round, part5_my_round_pow2);
  tcase_add_test(tc_my_round, part6_my_round_pow3);
  tcase_add_test(tc_my_round, part7_my_round_pow4);
  tcase_add_test(tc_my_round, part8_my_round_pow5);

  suite_add_tcase(s, tc_negate);
  suite_add_tcase(s, tc_my_floor);
  suite_add_tcase(s, tc_my_round);
  suite_add_tcase(s, tc_truncate);

  return s;
}

int main() {
  printf("================= TESTING =================\n\n");
  Suite *s_1 = arithmetic_test_suite();
  Suite *s_2 = comparison_test_suite();
  Suite *s_3 = converter_test_suite();
  Suite *s_4 = other_test_suite();
  run_test(s_1);
  run_test(s_2);
  run_test(s_3);
  run_test(s_4);
  printf("================= END =================\n");
  return 0;
}
