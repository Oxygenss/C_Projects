#include "../test.h"

START_TEST(test1_strlen) {
  char str[] = "Hello, world!";
  ck_assert_int_eq(strlen(str), strlen(str));
}
END_TEST

START_TEST(test2_strlen) {
  char str[] = "";
  ck_assert_int_eq(strlen(str), strlen(str));
}
END_TEST

START_TEST(test3_strlen) {
  char str[] = "Hello,\0 world!";
  ck_assert_int_eq(strlen(str), strlen(str));
}
END_TEST

START_TEST(test4_strlen) {
  char str[] = "\0";
  ck_assert_int_eq(strlen(str), strlen(str));
}
END_TEST

START_TEST(test5_strlen) {
  char str[] = "   ";
  ck_assert_int_eq(strlen(str), strlen(str));
}
END_TEST

START_TEST(test6_strlen) {
  char str[] = "H";
  ck_assert_int_eq(strlen(str), strlen(str));
}
END_TEST

START_TEST(test7_strlen) {
  char str[] = "He";
  ck_assert_int_eq(strlen(str), strlen(str));
}
END_TEST

START_TEST(test8_strlen) {
  char str[] = "Hel";
  ck_assert_int_eq(strlen(str), strlen(str));
}
END_TEST

START_TEST(test9_strlen) {
  char str[] = "Hell";
  ck_assert_int_eq(strlen(str), strlen(str));
}
END_TEST

START_TEST(test10_strlen) {
  char str[] = "Hello";
  ck_assert_int_eq(strlen(str), strlen(str));
}
END_TEST

Suite *test_strlen() {
  Suite *suite = suite_create("strlen");
  TCase *tcase = tcase_create("strlen_tcase");

  tcase_add_test(tcase, test1_strlen);
  tcase_add_test(tcase, test2_strlen);
  tcase_add_test(tcase, test3_strlen);
  tcase_add_test(tcase, test4_strlen);
  tcase_add_test(tcase, test5_strlen);
  tcase_add_test(tcase, test6_strlen);
  tcase_add_test(tcase, test7_strlen);
  tcase_add_test(tcase, test8_strlen);
  tcase_add_test(tcase, test9_strlen);
  tcase_add_test(tcase, test10_strlen);

  suite_add_tcase(suite, tcase);
  return suite;
}
