#include "../test.h"

START_TEST(test1_strrchr) {
  char str[] = "Hello, world!";
  int c = 'l';
  ck_assert_pstr_eq(strrchr(str, c), strrchr(str, c));
}
END_TEST

START_TEST(test2_strrchr) {
  char str[] = "Hello, world!";
  int c = '\0';
  ck_assert_pstr_eq(strrchr(str, c), strrchr(str, c));
}
END_TEST

START_TEST(test3_strrchr) {
  char str[] = "Hello, world!";
  int c = 'H';
  ck_assert_pstr_eq(strrchr(str, c), strrchr(str, c));
}
END_TEST

START_TEST(test4_strrchr) {
  char str[] = "Hello, world!";
  int c = 'h';
  ck_assert_pstr_eq(strrchr(str, c), strrchr(str, c));
}
END_TEST

START_TEST(test5_strrchr) {
  char str[] = "Hello, world!";
  int c = ' ';
  ck_assert_pstr_eq(strrchr(str, c), strrchr(str, c));
}
END_TEST

START_TEST(test6_strrchr) {
  char str[] = "";
  int c = '\0';
  ck_assert_pstr_eq(strrchr(str, c), strrchr(str, c));
}
END_TEST

START_TEST(test7_strrchr) {
  char str[] = "Hello, world!";
  int c = '!';
  ck_assert_pstr_eq(strrchr(str, c), strrchr(str, c));
}
END_TEST

START_TEST(test8_strrchr) {
  char str[] = "Hello, world!";
  int c = 0;
  ck_assert_pstr_eq(strrchr(str, c), strrchr(str, c));
}
END_TEST

START_TEST(test9_strrchr) {
  char str[] = "Hello, world!";
  int c = 'a';
  ck_assert_pstr_eq(strrchr(str, c), strrchr(str, c));
}
END_TEST

START_TEST(test10_strrchr) {
  char str[] = "Hello, world!";
  int c = 'o';
  ck_assert_pstr_eq(strrchr(str, c), strrchr(str, c));
}
END_TEST

Suite *test_strrchr() {
  Suite *suite = suite_create("strrchr");
  TCase *tcase = tcase_create("strrchr_tcase");

  tcase_add_test(tcase, test1_strrchr);
  tcase_add_test(tcase, test2_strrchr);
  tcase_add_test(tcase, test3_strrchr);
  tcase_add_test(tcase, test4_strrchr);
  tcase_add_test(tcase, test5_strrchr);
  tcase_add_test(tcase, test6_strrchr);
  tcase_add_test(tcase, test7_strrchr);
  tcase_add_test(tcase, test8_strrchr);
  tcase_add_test(tcase, test9_strrchr);
  tcase_add_test(tcase, test10_strrchr);

  suite_add_tcase(suite, tcase);
  return suite;
}
