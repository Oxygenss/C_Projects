#include "tests_main.h"

START_TEST(calc_complements_part_1) {
  matrix_t A, result;
  create_matrix(1, 1, &A);
  ck_assert_int_eq(calc_complements(&A, &result), 0);
  ck_assert_double_eq(result.matrix[0][0], 1);
  remove_matrix(&A);
  remove_matrix(&result);
}
END_TEST

START_TEST(calc_complements_part_2) {
  matrix_t A, result;
  create_matrix(2, 4, &A);
  ck_assert_int_eq(calc_complements(&A, &result), 2);
  remove_matrix(&A);
}
END_TEST

START_TEST(calc_complements_part_3) {
  matrix_t A;
  create_matrix(2, 4, &A);
  ck_assert_int_eq(calc_complements(&A, NULL), 1);
  remove_matrix(&A);
}
END_TEST

Suite *calc_complements_suite() {
  Suite *s = suite_create("calc_complements");
  TCase *tc_create = tcase_create("calc_complements");
  tcase_add_test(tc_create, calc_complements_part_1);
  tcase_add_test(tc_create, calc_complements_part_2);
  tcase_add_test(tc_create, calc_complements_part_3);
  suite_add_tcase(s, tc_create);
  return s;
}