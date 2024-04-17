#include "../test.h"

START_TEST(test1_strchr) {
  char str[] = "Hello, world!";
  char ch = 'l';
  ck_assert_pstr_eq(strchr(str, ch), strchr(str, ch));
}
END_TEST

START_TEST(test2_strchr) {
  char str[] = "Hello, world!";
  char ch = '\0';
  ck_assert_pstr_eq(strchr(str, ch), strchr(str, ch));
}
END_TEST

START_TEST(test3_strchr) {
  char str[] = "Hello, world!";
  char ch = 'H';
  ck_assert_pstr_eq(strchr(str, ch), strchr(str, ch));
}
END_TEST

START_TEST(test4_strchr) {
  char str[] = "Hello, world!";
  char ch = '!';
  ck_assert_pstr_eq(strchr(str, ch), strchr(str, ch));
}
END_TEST

START_TEST(test5_strchr) {
  char str[] = "Hello, world!";
  char ch = 'h';
  ck_assert_pstr_eq(strchr(str, ch), strchr(str, ch));
}
END_TEST

START_TEST(test6_strchr) {
  char str[] = "Hello, world!";
  char ch = 'l';
  ck_assert_pstr_eq(strchr(str, ch), strchr(str, ch));
}
END_TEST

START_TEST(test7_strchr) {
  char str[] = "Hello, world!";
  char ch = 'a';
  ck_assert_pstr_eq(strchr(str, ch), strchr(str, ch));
}
END_TEST

START_TEST(test8_strchr) {
  char str[] = "";
  char ch = '\0';
  ck_assert_pstr_eq(strchr(str, ch), strchr(str, ch));
}
END_TEST

START_TEST(test9_strchr) {
  char str[] = "H";
  char ch = 'H';
  ck_assert_pstr_eq(strchr(str, ch), strchr(str, ch));
}
END_TEST

START_TEST(test10_strchr) {
  char str[] = "";
  char ch = 'a';
  ck_assert_pstr_eq(strchr(str, ch), strchr(str, ch));
}
END_TEST

Suite *test_strchr() {
  Suite *suite = suite_create("strchr");
  TCase *tcase = tcase_create("strchr_tcase");

  tcase_add_test(tcase, test1_strchr);
  tcase_add_test(tcase, test2_strchr);
  tcase_add_test(tcase, test3_strchr);
  tcase_add_test(tcase, test4_strchr);
  tcase_add_test(tcase, test5_strchr);
  tcase_add_test(tcase, test6_strchr);
  tcase_add_test(tcase, test7_strchr);
  tcase_add_test(tcase, test8_strchr);
  tcase_add_test(tcase, test9_strchr);
  tcase_add_test(tcase, test10_strchr);

  suite_add_tcase(suite, tcase);
  return suite;
}
