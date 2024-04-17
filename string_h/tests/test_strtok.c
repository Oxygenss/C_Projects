#include "../test.h"

START_TEST(test1_strtok) {
  char str1[] = "Hello, world!";
  char str2[] = "Hello, world!";
  char str[] = "\0";
  ck_assert_pstr_eq(strtok(str1, str), strtok(str2, str));
}
END_TEST

START_TEST(test2_strtok) {
  char str1[] = "Hello, world!";
  char str2[] = "Hello, world!";
  char str[] = "";
  ck_assert_pstr_eq(strtok(str1, str), strtok(str2, str));
}
END_TEST

START_TEST(test3_strtok) {
  char str1[] = "Hello, world!";
  char str2[] = "Hello, world!";
  char str[] = " ";
  ck_assert_pstr_eq(strtok(str1, str), strtok(str2, str));
}
END_TEST

START_TEST(test4_strtok) {
  char str1[] = "Hello, world!";
  char str2[] = "Hello, world!";
  char str[] = "l";
  ck_assert_pstr_eq(strtok(str1, str), strtok(str2, str));
}
END_TEST

START_TEST(test5_strtok) {
  char str1[] = "Hello, world!";
  char str2[] = "Hello, world!";
  char str[] = "H";
  ck_assert_pstr_eq(strtok(str1, str), strtok(str2, str));
}
END_TEST

START_TEST(test6_strtok) {
  char str1[] = "Hello, world!";
  char str2[] = "Hello, world!";
  char str[] = "!";
  ck_assert_pstr_eq(strtok(str1, str), strtok(str2, str));
}
END_TEST

START_TEST(test7_strtok) {
  char str1[] = "Hello, world!Hello, world!";
  char str2[] = "Hello, world!Hello, world!";
  char str[] = "l";
  ck_assert_pstr_eq(strtok(str1, str), strtok(str2, str));
}
END_TEST

START_TEST(test8_strtok) {
  char str1[] = "Hello, world!Hello, world!";
  char str2[] = "Hello, world!Hello, world!";
  char str[] = "h";
  ck_assert_pstr_eq(strtok(str1, str), strtok(str2, str));
}
END_TEST

START_TEST(test9_strtok) {
  char str1[] = "Hello, world! Hello, world!";
  char str2[] = "Hello, world! Hello, world!";
  char str[] = "ll";
  ck_assert_pstr_eq(strtok(str1, str), strtok(str2, str));
}
END_TEST

START_TEST(test10_strtok) {
  char str1[] = "Hello, world!";
  char str2[] = "Hello, world!";
  char str[] = "ll";
  ck_assert_pstr_eq(strtok(str1, str), strtok(str2, str));
}
END_TEST

Suite *test_strtok() {
  Suite *suite = suite_create("strtok");
  TCase *tcase = tcase_create("strtok_tcase");

  tcase_add_test(tcase, test1_strtok);
  tcase_add_test(tcase, test2_strtok);
  tcase_add_test(tcase, test3_strtok);
  tcase_add_test(tcase, test4_strtok);
  tcase_add_test(tcase, test5_strtok);
  tcase_add_test(tcase, test6_strtok);
  tcase_add_test(tcase, test7_strtok);
  tcase_add_test(tcase, test8_strtok);
  tcase_add_test(tcase, test9_strtok);
  tcase_add_test(tcase, test10_strtok);

  suite_add_tcase(suite, tcase);
  return suite;
}
