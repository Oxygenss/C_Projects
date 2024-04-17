#include "tests_main.h"

START_TEST(transpose_part_1) {
  matrix_t A, result;
  create_matrix(3, 2, &A);

  A.matrix[0][0] = 1;
  A.matrix[0][1] = 4;

  A.matrix[1][0] = 2;
  A.matrix[1][1] = 5;

  A.matrix[2][0] = 3;
  A.matrix[2][1] = 6;

  ck_assert_int_eq(transpose(&A, &result), 0);
  ck_assert_double_eq(result.matrix[0][0], 1);
  ck_assert_double_eq(result.matrix[0][1], 2);
  ck_assert_double_eq(result.matrix[0][2], 3);

  ck_assert_double_eq(result.matrix[1][0], 4);
  ck_assert_double_eq(result.matrix[1][1], 5);
  ck_assert_double_eq(result.matrix[1][2], 6);
  remove_matrix(&A);
  remove_matrix(&result);
}
END_TEST

START_TEST(transpose_part_2) {
  matrix_t A;
  create_matrix(3, 2, &A);

  A.matrix[0][0] = 1;
  A.matrix[0][1] = 4;

  A.matrix[1][0] = 2;
  A.matrix[1][1] = 5;

  A.matrix[2][0] = 3;
  A.matrix[2][1] = 6;

  ck_assert_int_eq(transpose(&A, NULL), 1);
  remove_matrix(&A);
}
END_TEST

Suite *transpose_suite() {
  Suite *s = suite_create("transpose");
  TCase *tc_create = tcase_create("transpose");
  tcase_add_test(tc_create, transpose_part_1);
  tcase_add_test(tc_create, transpose_part_2);
  suite_add_tcase(s, tc_create);
  return s;
}