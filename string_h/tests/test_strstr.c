#include "../test.h"

START_TEST(test1_strstr) {
  char str1[] = "Hello, world!";
  char str2[] = "Hello, world!";
  ck_assert_pstr_eq(strstr(str1, str2), strstr(str1, str2));
}
END_TEST

START_TEST(test2_strstr) {
  char str1[] = "Hello, world!";
  char str2[] = "Hello";
  ck_assert_pstr_eq(strstr(str1, str2), strstr(str1, str2));
}
END_TEST

START_TEST(test3_strstr) {
  char str1[] = "Hello, world!";
  char str2[] = "world!";
  ck_assert_pstr_eq(strstr(str1, str2), strstr(str1, str2));
}
END_TEST

START_TEST(test4_strstr) {
  char str1[] = "Hello, world!";
  char str2[] = "ello, world";
  ck_assert_pstr_eq(strstr(str1, str2), strstr(str1, str2));
}
END_TEST

START_TEST(test5_strstr) {
  char str1[] = "Hello, world!";
  char str2[] = "Hello, world";
  ck_assert_pstr_eq(strstr(str1, str2), strstr(str1, str2));
}
END_TEST

START_TEST(test6_strstr) {
  char str1[] = "Hello, world!";
  char str2[] = "ello, world!";
  ck_assert_pstr_eq(strstr(str1, str2), strstr(str1, str2));
}
END_TEST

START_TEST(test7_strstr) {
  char str1[] = "Hello, world!";
  char str2[] = "H";
  ck_assert_pstr_eq(strstr(str1, str2), strstr(str1, str2));
}
END_TEST

START_TEST(test8_strstr) {
  char str1[] = "Hello, world!";
  char str2[] = "!";
  ck_assert_pstr_eq(strstr(str1, str2), strstr(str1, str2));
}
END_TEST

START_TEST(test9_strstr) {
  char str1[] = "";
  char str2[] = "";
  ck_assert_pstr_eq(strstr(str1, str2), strstr(str1, str2));
}
END_TEST

START_TEST(test10_strstr) {
  char str1[] = "Hello, world!";
  char str2[] = "";
  ck_assert_pstr_eq(strstr(str1, str2), strstr(str1, str2));
}
END_TEST

START_TEST(test11_strstr) {
  char str1[] = "Hello, world!";
  char str2[] = "\0";
  ck_assert_pstr_eq(strstr(str1, str2), strstr(str1, str2));
}
END_TEST

START_TEST(test12_strstr) {
  char str1[] = "Hello, world!";
  char str2[] = "strstr";
  ck_assert_pstr_eq(strstr(str1, str2), strstr(str1, str2));
}
END_TEST

Suite *test_strstr() {
  Suite *suite = suite_create("strstr");
  TCase *tcase = tcase_create("strstr_tcase");

  tcase_add_test(tcase, test1_strstr);
  tcase_add_test(tcase, test2_strstr);
  tcase_add_test(tcase, test3_strstr);
  tcase_add_test(tcase, test4_strstr);
  tcase_add_test(tcase, test5_strstr);
  tcase_add_test(tcase, test6_strstr);
  tcase_add_test(tcase, test7_strstr);
  tcase_add_test(tcase, test8_strstr);
  tcase_add_test(tcase, test9_strstr);
  tcase_add_test(tcase, test10_strstr);
  tcase_add_test(tcase, test11_strstr);
  tcase_add_test(tcase, test12_strstr);

  suite_add_tcase(suite, tcase);
  return suite;
}
