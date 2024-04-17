#include "tests_main.h"

START_TEST(remove_matrix_part_1) {
  matrix_t A;
  create_matrix(3, 3, &A);
  remove_matrix(&A);
  ck_assert_int_eq(A.rows, 0);
  ck_assert_int_eq(A.columns, 0);
  remove_matrix(&A);
}
END_TEST

Suite *remove_matrix_suite() {
  Suite *s = suite_create("remove_matrix");
  TCase *tc_create = tcase_create("remove_matrix");
  tcase_add_test(tc_create, remove_matrix_part_1);
  suite_add_tcase(s, tc_create);
  return s;
}