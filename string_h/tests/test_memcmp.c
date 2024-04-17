#include "../test.h"

START_TEST(test1_memcmp) {
  char str1[] = "Hello, world!";
  char str2[] = "Hello, world!";
  size_t n = strlen(str1);
  int res1 = memcmp(str1, str2, n);
  int res2 = memcmp(str1, str2, n);
  if (res1 > 0) res1 = 1;
  if (res1 < 0) res1 = -1;
  if (res2 > 0) res2 = 1;
  if (res2 < 0) res2 = -1;
  ck_assert_int_eq(res1, res2);
}
END_TEST

START_TEST(test2_memcmp) {
  char str1[] = "Hello, world!";
  char str2[] = "Hello, world!";
  size_t n = 0;
  int res1 = memcmp(str1, str2, n);
  int res2 = memcmp(str1, str2, n);
  if (res1 > 0) res1 = 1;
  if (res1 < 0) res1 = -1;
  if (res2 > 0) res2 = 1;
  if (res2 < 0) res2 = -1;
  ck_assert_int_eq(res1, res2);
}
END_TEST

START_TEST(test3_memcmp) {
  char str1[] = "";
  char str2[] = "";
  size_t n = strlen(str1);
  int res1 = memcmp(str1, str2, n);
  int res2 = memcmp(str1, str2, n);
  if (res1 > 0) res1 = 1;
  if (res1 < 0) res1 = -1;
  if (res2 > 0) res2 = 1;
  if (res2 < 0) res2 = -1;
  ck_assert_int_eq(res1, res2);
}
END_TEST

START_TEST(test4_memcmp) {
  char str1[] = "";
  char str2[] = "\0";
  size_t n = strlen(str1);
  int res1 = memcmp(str1, str2, n);
  int res2 = memcmp(str1, str2, n);
  if (res1 > 0) res1 = 1;
  if (res1 < 0) res1 = -1;
  if (res2 > 0) res2 = 1;
  if (res2 < 0) res2 = -1;
  ck_assert_int_eq(res1, res2);
}
END_TEST

START_TEST(test5_memcmp) {
  char str1[] = "Hello";
  char str2[] = "Hello, world!";
  size_t n = strlen(str1);
  int res1 = memcmp(str1, str2, n);
  int res2 = memcmp(str1, str2, n);
  if (res1 > 0) res1 = 1;
  if (res1 < 0) res1 = -1;
  if (res2 > 0) res2 = 1;
  if (res2 < 0) res2 = -1;
  ck_assert_int_eq(res1, res2);
}
END_TEST

START_TEST(test6_memcmp) {
  char str1[] = "Hello, world!";
  char str2[] = "Hello";
  size_t n = strlen(str1);
  int res1 = memcmp(str1, str2, n);
  int res2 = memcmp(str1, str2, n);
  if (res1 > 0) res1 = 1;
  if (res1 < 0) res1 = -1;
  if (res2 > 0) res2 = 1;
  if (res2 < 0) res2 = -1;
  ck_assert_int_eq(res1, res2);
}
END_TEST

START_TEST(test7_memcmp) {
  char str1[] = "hello, world!";
  char str2[] = "Hello, world!";
  size_t n = strlen(str1);
  int res1 = memcmp(str1, str2, n);
  int res2 = memcmp(str1, str2, n);
  if (res1 > 0) res1 = 1;
  if (res1 < 0) res1 = -1;
  if (res2 > 0) res2 = 1;
  if (res2 < 0) res2 = -1;
  ck_assert_int_eq(res1, res2);
}
END_TEST

START_TEST(test8_memcmp) {
  char str1[] = "Hello, world!";
  char str2[] = "hello, world!";
  size_t n = strlen(str1);
  int res1 = memcmp(str1, str2, n);
  int res2 = memcmp(str1, str2, n);
  if (res1 > 0) res1 = 1;
  if (res1 < 0) res1 = -1;
  if (res2 > 0) res2 = 1;
  if (res2 < 0) res2 = -1;
  ck_assert_int_eq(res1, res2);
}
END_TEST

START_TEST(test9_memcmp) {
  char str1[] = "Hello, worlD";
  char str2[] = "Hello, world";
  size_t n = strlen(str1);
  int res1 = memcmp(str1, str2, n);
  int res2 = memcmp(str1, str2, n);
  if (res1 > 0) res1 = 1;
  if (res1 < 0) res1 = -1;
  if (res2 > 0) res2 = 1;
  if (res2 < 0) res2 = -1;
  ck_assert_int_eq(res1, res2);
}
END_TEST

START_TEST(test10_memcmp) {
  char str1[] = "Hello, world";
  char str2[] = "Hello, worlD";
  size_t n = strlen(str1);
  int res1 = memcmp(str1, str2, n);
  int res2 = memcmp(str1, str2, n);
  if (res1 > 0) res1 = 1;
  if (res1 < 0) res1 = -1;
  if (res2 > 0) res2 = 1;
  if (res2 < 0) res2 = -1;
  ck_assert_int_eq(res1, res2);
}
END_TEST

Suite *test_memcmp() {
  Suite *suite = suite_create("memcmp");
  TCase *tcase = tcase_create("memcmp_tcase");

  tcase_add_test(tcase, test1_memcmp);
  tcase_add_test(tcase, test2_memcmp);
  tcase_add_test(tcase, test3_memcmp);
  tcase_add_test(tcase, test4_memcmp);
  tcase_add_test(tcase, test5_memcmp);
  tcase_add_test(tcase, test6_memcmp);
  tcase_add_test(tcase, test7_memcmp);
  tcase_add_test(tcase, test8_memcmp);
  tcase_add_test(tcase, test9_memcmp);
  tcase_add_test(tcase, test10_memcmp);

  suite_add_tcase(suite, tcase);
  return suite;
}
