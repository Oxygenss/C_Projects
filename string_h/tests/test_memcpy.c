#include "../test.h"

START_TEST(test1_memcpy) {
  char str1[] = "Hello, world!";
  char str2[] = "Hello, world!";
  char str[] = "memcpy";
  size_t n = strlen(str);
  ck_assert_str_eq(memcpy(str1, str, n), memcpy(str2, str, n));
}
END_TEST

START_TEST(test2_memcpy) {
  char str1[] = "Hello, world!";
  char str2[] = "Hello, world!";
  char str[] = "\0";
  size_t n = strlen(str);
  ck_assert_str_eq(memcpy(str1, str, n), memcpy(str2, str, n));
}
END_TEST

START_TEST(test3_memcpy) {
  char str1[] = "Hello, world!";
  char str2[] = "Hello, world!";
  char str[] = "memcpy";
  size_t n = 0;
  ck_assert_str_eq(memcpy(str1, str, n), memcpy(str2, str, n));
}
END_TEST

START_TEST(test4_memcpy) {
  char str1[] = "Hello, world!";
  char str2[] = "Hello, world!";
  char str[] = "memcpy";
  size_t n = 1;
  ck_assert_str_eq(memcpy(str1, str, n), memcpy(str2, str, n));
}
END_TEST

START_TEST(test5_memcpy) {
  char str1[] = "";
  char str2[] = "";
  char str[] = "";
  size_t n = strlen(str);
  ck_assert_str_eq(memcpy(str1, str, n), memcpy(str2, str, n));
}
END_TEST

START_TEST(test6_memcpy) {
  char str1[] = "\0Hello, world! Hello, world!";
  char str2[] = "\0Hello, world! Hello, world!";
  char str[] = "Hello, world!";
  size_t n = strlen(str);
  ck_assert_str_eq(memcpy(str1, str, n), memcpy(str2, str, n));
}
END_TEST

START_TEST(test7_memcpy) {
  char str1[] = "Hello, world! Hello, world!";
  char str2[] = "Hello, world! Hello, world!";
  char str[] = "Hello, world!";
  size_t n = 2;
  ck_assert_str_eq(memcpy(str1, str, n), memcpy(str2, str, n));
}
END_TEST

START_TEST(test8_memcpy) {
  char str1[] = "Hello, world! Hello, world!";
  char str2[] = "Hello, world! Hello, world!";
  char str[] = "\n\0\t";
  size_t n = strlen(str);
  ck_assert_str_eq(memcpy(str1, str, n), memcpy(str2, str, n));
}
END_TEST

START_TEST(test9_memcpy) {
  char str1[] = "Hello, world";
  char str2[] = "Hello, world";
  char str[] = "!";
  size_t n = 1;
  ck_assert_str_eq(memcpy(str1, str, n), memcpy(str2, str, n));
}
END_TEST

START_TEST(test10_memcpy) {
  char str1[] = "Hello, world!";
  char str2[] = "Hello, world!";
  char str[] = "!!";
  size_t n = 2;
  ck_assert_str_eq(memcpy(str1, str, n), memcpy(str2, str, n));
}
END_TEST

Suite *test_memcpy() {
  Suite *suite = suite_create("memcpy");
  TCase *tcase = tcase_create("memcpy_tcase");

  tcase_add_test(tcase, test1_memcpy);
  tcase_add_test(tcase, test2_memcpy);
  tcase_add_test(tcase, test3_memcpy);
  tcase_add_test(tcase, test4_memcpy);
  tcase_add_test(tcase, test5_memcpy);
  tcase_add_test(tcase, test6_memcpy);
  tcase_add_test(tcase, test7_memcpy);
  tcase_add_test(tcase, test8_memcpy);
  tcase_add_test(tcase, test9_memcpy);
  tcase_add_test(tcase, test10_memcpy);

  suite_add_tcase(suite, tcase);
  return suite;
}
