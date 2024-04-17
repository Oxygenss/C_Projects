#include "../test.h"

START_TEST(test1_memset) {
  char str1[] = "Hello, world!";
  char str2[] = "Hello, world!";
  int ch = 'a';
  size_t n = strlen(str1);
  ck_assert_str_eq(memset(str1, ch, n), memset(str2, ch, n));
}
END_TEST

START_TEST(test2_memset) {
  char str1[] = "Hello, world!";
  char str2[] = "Hello, world!";
  int ch = '\0';
  size_t n = strlen(str1);
  ck_assert_str_eq(memset(str1, ch, n), memset(str2, ch, n));
}
END_TEST

START_TEST(test3_memset) {
  char str1[] = "Hello, world!";
  char str2[] = "Hello, world!";
  int ch = '\0';
  size_t n = 0;
  ck_assert_str_eq(memset(str1, ch, n), memset(str2, ch, n));
}
END_TEST

START_TEST(test4_memset) {
  char str1[] = "Hello, world!";
  char str2[] = "Hello, world!";
  int ch = '\0';
  size_t n = 1;
  ck_assert_str_eq(memset(str1, ch, n), memset(str2, ch, n));
}
END_TEST

START_TEST(test5_memset) {
  char str1[] = "Hello, world!";
  char str2[] = "Hello, world!";
  int ch = 'H';
  size_t n = 1;
  ck_assert_str_eq(memset(str1, ch, n), memset(str2, ch, n));
}
END_TEST

START_TEST(test6_memset) {
  char str1[] = "Hello, world!";
  char str2[] = "Hello, world!";
  int ch = 'a';
  size_t n = 2;
  ck_assert_str_eq(memset(str1, ch, n), memset(str2, ch, n));
}
END_TEST

START_TEST(test7_memset) {
  char str1[] = "Hello, world!";
  char str2[] = "Hello, world!";
  int ch = '\0';
  size_t n = 2;
  ck_assert_str_eq(memset(str1, ch, n), memset(str2, ch, n));
}
END_TEST

START_TEST(test8_memset) {
  char str1[] = "";
  char str2[] = "";
  int ch = '\0';
  size_t n = 1;
  ck_assert_str_eq(memset(str1, ch, n), memset(str2, ch, n));
}
END_TEST

START_TEST(test9_memset) {
  char str1[] = "Hello, world!";
  char str2[] = "Hello, world!";
  int ch = '\n';
  size_t n = 1;
  ck_assert_str_eq(memset(str1, ch, n), memset(str2, ch, n));
}
END_TEST

START_TEST(test10_memset) {
  char str1[] = "Hello, world!";
  char str2[] = "Hello, world!";
  int ch = '\n';
  size_t n = 5;
  ck_assert_str_eq(memset(str1, ch, n), memset(str2, ch, n));
}
END_TEST

Suite *test_memset() {
  Suite *suite = suite_create("memset");
  TCase *tcase = tcase_create("memset_tcase");

  tcase_add_test(tcase, test1_memset);
  tcase_add_test(tcase, test2_memset);
  tcase_add_test(tcase, test3_memset);
  tcase_add_test(tcase, test4_memset);
  tcase_add_test(tcase, test5_memset);
  tcase_add_test(tcase, test6_memset);
  tcase_add_test(tcase, test7_memset);
  tcase_add_test(tcase, test8_memset);
  tcase_add_test(tcase, test9_memset);
  tcase_add_test(tcase, test10_memset);

  suite_add_tcase(suite, tcase);
  return suite;
}
