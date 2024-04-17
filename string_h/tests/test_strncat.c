#include "../test.h"

START_TEST(test1_strncat) {
  char str1[30] = "Hello, world!";
  char str2[30] = "Hello, world!";
  char str[] = "Hello, world!";
  size_t n = 1;
  ck_assert_pstr_eq(strncat(str1, str, n), strncat(str2, str, n));
}
END_TEST

START_TEST(test2_strncat) {
  char str1[30] = "Hello, world!";
  char str2[30] = "Hello, world!";
  char str[] = "\0";
  size_t n = 1;
  ck_assert_pstr_eq(strncat(str1, str, n), strncat(str2, str, n));
}
END_TEST

START_TEST(test3_strncat) {
  char str1[30] = "Hello, world!";
  char str2[30] = "Hello, world!";
  char str[] = "\n\0\t";
  size_t n = 3;
  ck_assert_pstr_eq(strncat(str1, str, n), strncat(str2, str, n));
}
END_TEST

START_TEST(test4_strncat) {
  char str1[30] = "Hello, world!";
  char str2[30] = "Hello, world!";
  char str[] = "";
  size_t n = 0;
  ck_assert_pstr_eq(strncat(str1, str, n), strncat(str2, str, n));
}
END_TEST

START_TEST(test5_strncat) {
  char str1[30] = "";
  char str2[30] = "";
  char str[] = "Hello, world!";
  size_t n = 13;
  ck_assert_pstr_eq(strncat(str1, str, n), strncat(str2, str, n));
}
END_TEST

START_TEST(test6_strncat) {
  char str1[100] = "Hello, world!";
  char str2[100] = "Hello, world!";
  char str[] = "Hello, world! Hello, world!";
  size_t n = 6;
  ck_assert_pstr_eq(strncat(str1, str, n), strncat(str2, str, n));
}
END_TEST

START_TEST(test7_strncat) {
  char str1[30] = "";
  char str2[30] = "";
  char str[] = "Hello, world!";
  size_t n = 3;
  ck_assert_pstr_eq(strncat(str1, str, n), strncat(str2, str, n));
}
END_TEST

START_TEST(test8_strncat) {
  char str1[100] = "Hello, world!";
  char str2[100] = "Hello, world!";
  char str[] = "My name is Polina.";
  size_t n = 2;
  ck_assert_pstr_eq(strncat(str1, str, n), strncat(str2, str, n));
}
END_TEST

START_TEST(test9_strncat) {
  char str1[100] = "";
  char str2[100] = "";
  char str[] = "";
  size_t n = 10;
  ck_assert_pstr_eq(strncat(str1, str, n), strncat(str2, str, n));
}
END_TEST

START_TEST(test10_strncat) {
  char str1[100] = "Hello\0, world!";
  char str2[100] = "Hello\0, world!";
  char str[] = "Hello\0, world!";
  size_t n = 15;
  ck_assert_pstr_eq(strncat(str1, str, n), strncat(str2, str, n));
}
END_TEST

Suite *test_strncat() {
  Suite *suite = suite_create("strncat");
  TCase *tcase = tcase_create("strncat_tcase");

  tcase_add_test(tcase, test1_strncat);
  tcase_add_test(tcase, test2_strncat);
  tcase_add_test(tcase, test3_strncat);
  tcase_add_test(tcase, test4_strncat);
  tcase_add_test(tcase, test5_strncat);
  tcase_add_test(tcase, test6_strncat);
  tcase_add_test(tcase, test7_strncat);
  tcase_add_test(tcase, test8_strncat);
  tcase_add_test(tcase, test9_strncat);
  tcase_add_test(tcase, test10_strncat);

  suite_add_tcase(suite, tcase);
  return suite;
}
