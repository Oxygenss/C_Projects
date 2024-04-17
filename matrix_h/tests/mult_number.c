#include "tests_main.h"

START_TEST(mult_number_part_1) {
  matrix_t A, result;
  create_matrix(2, 2, &A);
  A.matrix[0][0] = 3;
  A.matrix[0][1] = 5;

  A.matrix[1][0] = 7;
  A.matrix[1][1] = 2;

  ck_assert_int_eq(mult_number(&A, 2, &result), 0);
  ck_assert_double_eq(result.matrix[0][0], 6);
  ck_assert_double_eq(result.matrix[0][1], 10);

  ck_assert_double_eq(result.matrix[1][0], 14);
  ck_assert_double_eq(result.matrix[1][1], 4);
  remove_matrix(&A);
  remove_matrix(&result);
}
END_TEST

START_TEST(mult_number_part_2) {
  matrix_t A;
  create_matrix(2, 2, &A);
  A.matrix[0][0] = 3;
  A.matrix[0][1] = 5;

  A.matrix[1][0] = 7;
  A.matrix[1][1] = 2;

  ck_assert_int_eq(mult_number(&A, 2, NULL), 1);
  remove_matrix(&A);
}
END_TEST

START_TEST(mult_number_part_3) {
  matrix_t A, result;
  create_matrix(2, 2, &A);
  A.matrix[0][0] = 3;
  A.matrix[0][1] = 0.0 / 0.0;

  A.matrix[1][0] = 7;
  A.matrix[1][1] = 2;

  ck_assert_int_eq(mult_number(&A, 2, &result), 2);
  remove_matrix(&A);
}
END_TEST

Suite *mult_number_suite() {
  Suite *s = suite_create("mult_number");
  TCase *tc_create = tcase_create("mult_number");
  tcase_add_test(tc_create, mult_number_part_1);
  tcase_add_test(tc_create, mult_number_part_2);
  tcase_add_test(tc_create, mult_number_part_3);
  suite_add_tcase(s, tc_create);
  return s;
}