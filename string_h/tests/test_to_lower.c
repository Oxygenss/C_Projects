#include "../test.h"

START_TEST(to_lower_test_1) {
  char str[] = "Hello, world!";
  char res[] = "hello, world!";
  char *ptr = (char *)to_lower(str);
  ck_assert_pstr_eq(ptr, res);
  free(ptr);
}
END_TEST

START_TEST(to_lower_test_2) {
  char str[] = "hELLO, WORLD!";
  char res[] = "hello, world!";
  char *ptr = (char *)to_lower(str);
  ck_assert_pstr_eq(ptr, res);
  free(ptr);
}
END_TEST

START_TEST(to_lower_test_3) {
  char str[] = "Hello, worlD";
  char res[] = "hello, world";
  char *ptr = (char *)to_lower(str);
  ck_assert_pstr_eq(ptr, res);
  free(ptr);
}
END_TEST

START_TEST(to_lower_test_4) {
  char str[] = "1234567890";
  char res[] = "1234567890";
  char *ptr = (char *)to_lower(str);
  ck_assert_pstr_eq(ptr, res);
  free(ptr);
}
END_TEST

START_TEST(to_lower_test_5) {
  char str[] = "ABCDEFGHIJKLMNOPQRSTUVWXYZ";
  char res[] = "abcdefghijklmnopqrstuvwxyz";
  char *ptr = (char *)to_lower(str);
  ck_assert_pstr_eq(ptr, res);
  free(ptr);
}
END_TEST

START_TEST(to_lower_test_6) {
  char str[] = "";
  char *res = "";
  char *ptr = (char *)to_lower(str);
  ck_assert_pstr_eq(ptr, res);
  free(ptr);
}
END_TEST

START_TEST(to_lower_test_7) {
  char str[] = "!@#$%^&*()_+-=<>";
  char res[] = "!@#$%^&*()_+-=<>";
  char *ptr = (char *)to_lower(str);
  ck_assert_pstr_eq(ptr, res);
  free(ptr);
}
END_TEST

START_TEST(to_lower_test_8) {
  char str[] = "AaAaAaAaAaA";
  char res[] = "aaaaaaaaaaa";
  char *ptr = (char *)to_lower(str);
  ck_assert_pstr_eq(ptr, res);
  free(ptr);
}
END_TEST

Suite *test_to_lower() {
  Suite *s = suite_create("to_lower");
  TCase *tc_create = tcase_create("to_lower");
  tcase_add_test(tc_create, to_lower_test_1);
  tcase_add_test(tc_create, to_lower_test_2);
  tcase_add_test(tc_create, to_lower_test_3);
  tcase_add_test(tc_create, to_lower_test_4);
  tcase_add_test(tc_create, to_lower_test_5);
  tcase_add_test(tc_create, to_lower_test_6);
  tcase_add_test(tc_create, to_lower_test_7);
  tcase_add_test(tc_create, to_lower_test_8);
  suite_add_tcase(s, tc_create);
  return s;
}