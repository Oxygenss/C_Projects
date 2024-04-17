#include "../test.h"
START_TEST(test1_strncpy) {
  char str1[] = "Hello, world!";
  char str2[] = "Hello, world!";
  char str[] = "strncpy";
  size_t n = strlen(str);
  ck_assert_str_eq(strncpy(str1, str, n), strncpy(str2, str, n));
}
END_TEST

START_TEST(test2_strncpy) {
  char str1[] = "Hello, world!";
  char str2[] = "Hello, world!";
  char str[] = "\0";
  size_t n = strlen(str);
  ck_assert_str_eq(strncpy(str1, str, n), strncpy(str2, str, n));
}
END_TEST

START_TEST(test3_strncpy) {
  char str1[] = "Hello, world!";
  char str2[] = "Hello, world!";
  char str[] = "strncpy";
  size_t n = 0;
  ck_assert_str_eq(strncpy(str1, str, n), strncpy(str2, str, n));
}
END_TEST

START_TEST(test4_strncpy) {
  char str1[] = "Hello, world!";
  char str2[] = "Hello, world!";
  char str[] = "strncpy";
  size_t n = 1;
  ck_assert_str_eq(strncpy(str1, str, n), strncpy(str2, str, n));
}
END_TEST

START_TEST(test5_strncpy) {
  char str1[] = "";
  char str2[] = "";
  char str[] = "";
  size_t n = strlen(str);
  ck_assert_str_eq(strncpy(str1, str, n), strncpy(str2, str, n));
}
END_TEST

START_TEST(test6_strncpy) {
  char str1[] = "Hello, world!";
  char str2[] = "Hello, world!";
  char str[] = "Hello, world!";
  size_t n = strlen(str);
  ck_assert_str_eq(strncpy(str1, str, n), strncpy(str2, str, n));
}
END_TEST

START_TEST(test7_strncpy) {
  char str1[] = "Hello, world!";
  char str2[] = "Hello, world!";
  char str[] = "Hello, world!";
  size_t n = 0;
  ck_assert_str_eq(strncpy(str1, str, n), strncpy(str2, str, n));
}
END_TEST

START_TEST(test8_strncpy) {
  char str1[] = "Hello, world!";
  char str2[] = "Hello, world!";
  char str[] = "\n\0\t";
  size_t n = strlen(str);
  ck_assert_str_eq(strncpy(str1, str, n), strncpy(str2, str, n));
}
END_TEST

START_TEST(test9_strncpy) {
  char str1[] = "Hello, world";
  char str2[] = "Hello, world";
  char str[] = "!";
  size_t n = 1;
  ck_assert_str_eq(strncpy(str1, str, n), strncpy(str2, str, n));
}
END_TEST

START_TEST(test10_strncpy) {
  char str1[] = "Hello, world!";
  char str2[] = "Hello, world!";
  char str[] = "!!";
  size_t n = 2;
  ck_assert_str_eq(strncpy(str1, str, n), strncpy(str2, str, n));
}
END_TEST

Suite *test_strncpy() {
  Suite *suite = suite_create("strncpy");
  TCase *tcase = tcase_create("strncpy_tcase");

  tcase_add_test(tcase, test1_strncpy);
  tcase_add_test(tcase, test2_strncpy);
  tcase_add_test(tcase, test3_strncpy);
  tcase_add_test(tcase, test4_strncpy);
  tcase_add_test(tcase, test5_strncpy);
  tcase_add_test(tcase, test6_strncpy);
  tcase_add_test(tcase, test7_strncpy);
  tcase_add_test(tcase, test8_strncpy);
  tcase_add_test(tcase, test9_strncpy);
  tcase_add_test(tcase, test10_strncpy);

  suite_add_tcase(suite, tcase);
  return suite;
}
