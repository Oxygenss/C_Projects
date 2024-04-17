#include "tests_main.h"

START_TEST(eq_matrix_part_1) {
  matrix_t A, B;
  create_matrix(3, 3, &A);
  create_matrix(3, 3, &B);
  A.matrix[0][0] = 1;
  A.matrix[0][1] = 2;
  A.matrix[0][2] = 3;

  A.matrix[1][0] = 4;
  A.matrix[1][1] = 5;
  A.matrix[1][2] = 6;

  A.matrix[2][0] = 7;
  A.matrix[2][1] = 8;
  A.matrix[2][2] = 9;

  B.matrix[0][0] = 1;
  B.matrix[0][1] = 2;
  B.matrix[0][2] = 3;

  B.matrix[1][0] = 4;
  B.matrix[1][1] = 5;
  B.matrix[1][2] = 6;

  B.matrix[2][0] = 7;
  B.matrix[2][1] = 8;
  B.matrix[2][2] = 9;

  ck_assert_int_eq(eq_matrix(&A, &B), 1);
  remove_matrix(&A);
  remove_matrix(&B);
}
END_TEST

START_TEST(eq_matrix_part_2) {
  matrix_t A, B;
  create_matrix(3, 3, &A);
  create_matrix(3, 3, &B);
  A.matrix[0][0] = 1;
  A.matrix[0][1] = 2;
  A.matrix[0][2] = 3;

  A.matrix[1][0] = 4;
  A.matrix[1][1] = 5;
  A.matrix[1][2] = 6;

  A.matrix[2][0] = 7;
  A.matrix[2][1] = 8;
  A.matrix[2][2] = 9;

  B.matrix[0][0] = 1;
  B.matrix[0][1] = 87;
  B.matrix[0][2] = 3;

  B.matrix[1][0] = 4;
  B.matrix[1][1] = 5;
  B.matrix[1][2] = 6;

  B.matrix[2][0] = 7;
  B.matrix[2][1] = 8;
  B.matrix[2][2] = 9;

  ck_assert_int_eq(eq_matrix(&A, &B), 0);
  remove_matrix(&A);
  remove_matrix(&B);
}
END_TEST

START_TEST(eq_matrix_part_3) {
  matrix_t A, B;
  create_matrix(3, 3, &A);
  create_matrix(2, 3, &B);
  ck_assert_int_eq(eq_matrix(&A, &B), 0);
  remove_matrix(&A);
  remove_matrix(&B);
}
END_TEST

START_TEST(eq_matrix_part_4) {
  matrix_t A, B;
  create_matrix(1, 5, &A);
  create_matrix(1, 5, &B);

  A.matrix[0][0] = 1;
  A.matrix[0][1] = 2;
  A.matrix[0][2] = 3;
  A.matrix[0][3] = 4;
  A.matrix[0][4] = 5;

  B.matrix[0][0] = 1;
  B.matrix[0][1] = 2;
  B.matrix[0][2] = 3;
  B.matrix[0][3] = 4;
  B.matrix[0][4] = 5;

  ck_assert_int_eq(eq_matrix(&A, &B), 1);
  remove_matrix(&A);
  remove_matrix(&B);
}
END_TEST

Suite *eq_matrix_suite() {
  Suite *s = suite_create("eq_matrix");
  TCase *tc_create = tcase_create("eq_matrix");
  tcase_add_test(tc_create, eq_matrix_part_1);
  tcase_add_test(tc_create, eq_matrix_part_2);
  tcase_add_test(tc_create, eq_matrix_part_3);
  tcase_add_test(tc_create, eq_matrix_part_4);
  suite_add_tcase(s, tc_create);
  return s;
}