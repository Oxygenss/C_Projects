#include "../test.h"

START_TEST(test1_strpbrk) {
  char str1[] = "Hello, world!";
  char str2[] = "Hello, world!";
  ck_assert_pstr_eq(strpbrk(str1, str2), strpbrk(str1, str2));
}
END_TEST

START_TEST(test2_strpbrk) {
  char str1[] = "Hello, world!";
  char str2[] = "";
  ck_assert_pstr_eq(strpbrk(str1, str2), strpbrk(str1, str2));
}
END_TEST

START_TEST(test3_strpbrk) {
  char str1[] = "Hello, world!";
  char str2[] = "!";
  ck_assert_pstr_eq(strpbrk(str1, str2), strpbrk(str1, str2));
}
END_TEST

START_TEST(test4_strpbrk) {
  char str1[] = "Hello, world!";
  char str2[] = "H";
  ck_assert_pstr_eq(strpbrk(str1, str2), strpbrk(str1, str2));
}
END_TEST

START_TEST(test5_strpbrk) {
  char str1[] = "Hello, world!";
  char str2[] = "l";
  ck_assert_pstr_eq(strpbrk(str1, str2), strpbrk(str1, str2));
}
END_TEST

START_TEST(test6_strpbrk) {
  char str1[] = "Hello, world!";
  char str2[] = "\0";
  ck_assert_pstr_eq(strpbrk(str1, str2), strpbrk(str1, str2));
}
END_TEST

START_TEST(test7_strpbrk) {
  char str1[] = "Hello, world!";
  char str2[] = "a";
  ck_assert_pstr_eq(strpbrk(str1, str2), strpbrk(str1, str2));
}
END_TEST

START_TEST(test8_strpbrk) {
  char str1[] = "";
  char str2[] = "";
  ck_assert_pstr_eq(strpbrk(str1, str2), strpbrk(str1, str2));
}
END_TEST

START_TEST(test9_strpbrk) {
  char str1[] = "";
  char str2[] = "\0";
  ck_assert_pstr_eq(strpbrk(str1, str2), strpbrk(str1, str2));
}
END_TEST

START_TEST(test10_strpbrk) {
  char str1[] = "Hello, world!";
  char str2[] = " ,";
  ck_assert_pstr_eq(strpbrk(str1, str2), strpbrk(str1, str2));
}
END_TEST

Suite *test_strpbrk() {
  Suite *suite = suite_create("strpbrk");
  TCase *tcase = tcase_create("strpbrk_tcase");

  tcase_add_test(tcase, test1_strpbrk);
  tcase_add_test(tcase, test2_strpbrk);
  tcase_add_test(tcase, test3_strpbrk);
  tcase_add_test(tcase, test4_strpbrk);
  tcase_add_test(tcase, test5_strpbrk);
  tcase_add_test(tcase, test6_strpbrk);
  tcase_add_test(tcase, test7_strpbrk);
  tcase_add_test(tcase, test8_strpbrk);
  tcase_add_test(tcase, test9_strpbrk);
  tcase_add_test(tcase, test10_strpbrk);

  suite_add_tcase(suite, tcase);
  return suite;
}
