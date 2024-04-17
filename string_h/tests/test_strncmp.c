#include "../test.h"

START_TEST(test1_strncmp) {
  char str1[] = "Hello, world!";
  char str2[] = "Hello, world!";
  size_t n = strlen(str1);
  int res1 = strncmp(str1, str2, n);
  int res2 = strncmp(str1, str2, n);
  if (res1 > 0) res1 = 1;
  if (res1 < 0) res1 = -1;
  if (res2 > 0) res2 = 1;
  if (res2 < 0) res2 = -1;
  ck_assert_int_eq(res1, res2);
}
END_TEST

START_TEST(test2_strncmp) {
  char str1[] = "Hello, world!";
  char str2[] = "Hello, world!";
  size_t n = 0;
  int res1 = strncmp(str1, str2, n);
  int res2 = strncmp(str1, str2, n);
  if (res1 > 0) res1 = 1;
  if (res1 < 0) res1 = -1;
  if (res2 > 0) res2 = 1;
  if (res2 < 0) res2 = -1;
  ck_assert_int_eq(res1, res2);
}
END_TEST

START_TEST(test3_strncmp) {
  char str1[] = "Hello, world!";
  char str2[] = "Hello, world!";
  size_t n = 1;
  int res1 = strncmp(str1, str2, n);
  int res2 = strncmp(str1, str2, n);
  if (res1 > 0) res1 = 1;
  if (res1 < 0) res1 = -1;
  if (res2 > 0) res2 = 1;
  if (res2 < 0) res2 = -1;
  ck_assert_int_eq(res1, res2);
}
END_TEST

START_TEST(test4_strncmp) {
  char str1[] = "Hello, world!";
  char str2[] = "Hello, world!";
  size_t n = 2;
  int res1 = strncmp(str1, str2, n);
  int res2 = strncmp(str1, str2, n);
  if (res1 > 0) res1 = 1;
  if (res1 < 0) res1 = -1;
  if (res2 > 0) res2 = 1;
  if (res2 < 0) res2 = -1;
  ck_assert_int_eq(res1, res2);
}
END_TEST

START_TEST(test5_strncmp) {
  char str1[] = "Hello, world!";
  char str2[] = "hello, world!";
  size_t n = 1;
  int res1 = strncmp(str1, str2, n);
  int res2 = strncmp(str1, str2, n);
  if (res1 > 0) res1 = 1;
  if (res1 < 0) res1 = -1;
  if (res2 > 0) res2 = 1;
  if (res2 < 0) res2 = -1;
  ck_assert_int_eq(res1, res2);
}
END_TEST

START_TEST(test6_strncmp) {
  char str1[] = "Hello, world!";
  char str2[] = "Hello, world";
  size_t n = strlen(str1);
  int res1 = strncmp(str1, str2, n);
  int res2 = strncmp(str1, str2, n);
  if (res1 > 0) res1 = 1;
  if (res1 < 0) res1 = -1;
  if (res2 > 0) res2 = 1;
  if (res2 < 0) res2 = -1;
  ck_assert_int_eq(res1, res2);
}
END_TEST

START_TEST(test7_strncmp) {
  char str1[] = "Hello, world";
  char str2[] = "Hello, world!";
  size_t n = strlen(str1);
  int res1 = strncmp(str1, str2, n);
  int res2 = strncmp(str1, str2, n);
  if (res1 > 0) res1 = 1;
  if (res1 < 0) res1 = -1;
  if (res2 > 0) res2 = 1;
  if (res2 < 0) res2 = -1;
  ck_assert_int_eq(res1, res2);
}
END_TEST

START_TEST(test8_strncmp) {
  char str1[] = "Hello, world";
  char str2[] = "Hello, worlD";
  size_t n = strlen(str1);
  int res1 = strncmp(str1, str2, n);
  int res2 = strncmp(str1, str2, n);
  if (res1 > 0) res1 = 1;
  if (res1 < 0) res1 = -1;
  if (res2 > 0) res2 = 1;
  if (res2 < 0) res2 = -1;
  ck_assert_int_eq(res1, res2);
}
END_TEST

START_TEST(test9_strncmp) {
  char str1[] = "Hello, worlD";
  char str2[] = "Hello, world";
  size_t n = strlen(str1);
  int res1 = strncmp(str1, str2, n);
  int res2 = strncmp(str1, str2, n);
  if (res1 > 0) res1 = 1;
  if (res1 < 0) res1 = -1;
  if (res2 > 0) res2 = 1;
  if (res2 < 0) res2 = -1;
  ck_assert_int_eq(res1, res2);
}
END_TEST

START_TEST(test10_strncmp) {
  char str1[] = "";
  char str2[] = "";
  size_t n = strlen(str1);
  int res1 = strncmp(str1, str2, n);
  int res2 = strncmp(str1, str2, n);
  if (res1 > 0) res1 = 1;
  if (res1 < 0) res1 = -1;
  if (res2 > 0) res2 = 1;
  if (res2 < 0) res2 = -1;
  ck_assert_int_eq(res1, res2);
}
END_TEST

Suite *test_strncmp() {
  Suite *suite = suite_create("strncmp");
  TCase *tcase = tcase_create("strncmp_tcase");

  tcase_add_test(tcase, test1_strncmp);
  tcase_add_test(tcase, test2_strncmp);
  tcase_add_test(tcase, test3_strncmp);
  tcase_add_test(tcase, test4_strncmp);
  tcase_add_test(tcase, test5_strncmp);
  tcase_add_test(tcase, test6_strncmp);
  tcase_add_test(tcase, test7_strncmp);
  tcase_add_test(tcase, test8_strncmp);
  tcase_add_test(tcase, test9_strncmp);
  tcase_add_test(tcase, test10_strncmp);

  suite_add_tcase(suite, tcase);
  return suite;
}
