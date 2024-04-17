#include "../test.h"

START_TEST(test1_memchr) {
  char str[] = "Hello, world!";
  size_t n = strlen(str);
  int c = 'a';
  ck_assert_ptr_eq(memchr(str, c, n), memchr(str, c, n));
}
END_TEST

START_TEST(test2_memchr) {
  char str[] = "Hello, world!";
  size_t n = 0;
  int c = 'l';
  ck_assert_ptr_eq(memchr(str, c, n), memchr(str, c, n));
}
END_TEST

START_TEST(test3_memchr) {
  char str[] = "Hello, world!";
  size_t n = 1;
  int c = 'l';
  ck_assert_ptr_eq(memchr(str, c, n), memchr(str, c, n));
}
END_TEST

START_TEST(test4_memchr) {
  char str[] = "Hello, world!";
  size_t n = 2;
  int c = 'l';
  ck_assert_ptr_eq(memchr(str, c, n), memchr(str, c, n));
}
END_TEST

START_TEST(test5_memchr) {
  char str[] = "Hello, world!";
  size_t n = 3;
  int c = 'l';
  ck_assert_ptr_eq(memchr(str, c, n), memchr(str, c, n));
}
END_TEST

START_TEST(test6_memchr) {
  char str[] = "Hello, world!";
  size_t n = strlen(str);
  int c = '!';
  ck_assert_ptr_eq(memchr(str, c, n), memchr(str, c, n));
}
END_TEST

START_TEST(test7_memchr) {
  char str[] = "Hello, world!";
  size_t n = strlen(str);
  int c = 'h';
  ck_assert_ptr_eq(memchr(str, c, n), memchr(str, c, n));
}
END_TEST

START_TEST(test8_memchr) {
  char str[] = "Hello, world!";
  size_t n = strlen(str);
  int c = 'H';
  ck_assert_ptr_eq(memchr(str, c, n), memchr(str, c, n));
}
END_TEST

START_TEST(test9_memchr) {
  char str[] = "Hello, world!";
  size_t n = strlen(str);
  int c = '\0';
  ck_assert_ptr_eq(memchr(str, c, n), memchr(str, c, n));
}
END_TEST

START_TEST(test10_memchr) {
  char str[] = "Hello, world!";
  size_t n = strlen(str);
  int c = 0;
  ck_assert_ptr_eq(memchr(str, c, n), memchr(str, c, n));
}
END_TEST

Suite *test_memchr() {
  Suite *suite = suite_create("memchr");
  TCase *tcase = tcase_create("memchr_tcase");

  tcase_add_test(tcase, test1_memchr);
  tcase_add_test(tcase, test2_memchr);
  tcase_add_test(tcase, test3_memchr);
  tcase_add_test(tcase, test4_memchr);
  tcase_add_test(tcase, test5_memchr);
  tcase_add_test(tcase, test6_memchr);
  tcase_add_test(tcase, test7_memchr);
  tcase_add_test(tcase, test8_memchr);
  tcase_add_test(tcase, test9_memchr);
  tcase_add_test(tcase, test10_memchr);

  suite_add_tcase(suite, tcase);
  return suite;
}
