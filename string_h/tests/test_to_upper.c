#include "../test.h"

START_TEST(to_upper_test_1) {
  char str[] = "Hello, world!";
  char res[] = "HELLO, WORLD!";
  char *ptr = (char *)to_upper(str);
  ck_assert_pstr_eq(ptr, res);
  free(ptr);
}
END_TEST

START_TEST(to_upper_test_2) {
  char str[] = "hELLO, WORLD!";
  char res[] = "HELLO, WORLD!";
  char *ptr = (char *)to_upper(str);
  ck_assert_pstr_eq(ptr, res);
  free(ptr);
}
END_TEST

START_TEST(to_upper_test_3) {
  char str[] = "Hello, worlD";
  char res[] = "HELLO, WORLD";
  char *ptr = (char *)to_upper(str);
  ck_assert_pstr_eq(ptr, res);
  free(ptr);
}
END_TEST

START_TEST(to_upper_test_4) {
  char str[] = "1234567890";
  char res[] = "1234567890";
  char *ptr = (char *)to_upper(str);
  ck_assert_pstr_eq(ptr, res);
  free(ptr);
}
END_TEST

START_TEST(to_upper_test_5) {
  char str[] = "abcdefghijklmnopqrstuvwxyz";
  char res[] = "ABCDEFGHIJKLMNOPQRSTUVWXYZ";
  char *ptr = (char *)to_upper(str);
  ck_assert_pstr_eq(ptr, res);
  free(ptr);
}
END_TEST

START_TEST(to_upper_test_6) {
  char str[] = "";
  char *res = "";
  char *ptr = (char *)to_upper(str);
  ck_assert_pstr_eq(ptr, res);
  free(ptr);
}
END_TEST

START_TEST(to_upper_test_7) {
  char str[] = "!@#$%^&*()_+-=<>";
  char res[] = "!@#$%^&*()_+-=<>";
  char *ptr = (char *)to_upper(str);
  ck_assert_pstr_eq(ptr, res);
  free(ptr);
}
END_TEST

START_TEST(to_upper_test_8) {
  char str[] = "AaAaAaAaAaA";
  char res[] = "AAAAAAAAAAA";
  char *ptr = (char *)to_upper(str);
  ck_assert_pstr_eq(ptr, res);
  free(ptr);
}
END_TEST

Suite *test_to_upper() {
  Suite *s = suite_create("to_upper");
  TCase *tc_create = tcase_create("to_upper");
  tcase_add_test(tc_create, to_upper_test_1);
  tcase_add_test(tc_create, to_upper_test_2);
  tcase_add_test(tc_create, to_upper_test_3);
  tcase_add_test(tc_create, to_upper_test_4);
  tcase_add_test(tc_create, to_upper_test_5);
  tcase_add_test(tc_create, to_upper_test_6);
  tcase_add_test(tc_create, to_upper_test_7);
  tcase_add_test(tc_create, to_upper_test_8);

  suite_add_tcase(s, tc_create);
  return s;
}