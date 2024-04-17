#include "../test.h"

START_TEST(test1_strcspn) {
  char str1[] = "Hello, world!";
  char str2[] = "";
  ck_assert_int_eq(strcspn(str1, str2), strcspn(str1, str2));
}
END_TEST

START_TEST(test2_strcspn) {
  char str1[] = "Hello, world!";
  char str2[] = "\0";
  ck_assert_int_eq(strcspn(str1, str2), strcspn(str1, str2));
}
END_TEST

START_TEST(test3_strcspn) {
  char str1[] = "Hello, world!";
  char str2[] = "l";
  ck_assert_int_eq(strcspn(str1, str2), strcspn(str1, str2));
}
END_TEST

START_TEST(test4_strcspn) {
  char str1[] = "Hello, world!";
  char str2[] = "a";
  ck_assert_int_eq(strcspn(str1, str2), strcspn(str1, str2));
}
END_TEST

START_TEST(test5_strcspn) {
  char str1[] = "";
  char str2[] = "\0";
  ck_assert_int_eq(strcspn(str1, str2), strcspn(str1, str2));
}
END_TEST

START_TEST(test6_strcspn) {
  char str1[] = "";
  char str2[] = "";
  ck_assert_int_eq(strcspn(str1, str2), strcspn(str1, str2));
}
END_TEST

START_TEST(test7_strcspn) {
  char str1[] = "Hello, world!";
  char str2[] = "!";
  ck_assert_int_eq(strcspn(str1, str2), strcspn(str1, str2));
}
END_TEST

START_TEST(test8_strcspn) {
  char str1[] = "Hello, world!";
  char str2[] = "H";
  ck_assert_int_eq(strcspn(str1, str2), strcspn(str1, str2));
}
END_TEST

START_TEST(test9_strcspn) {
  char str1[] = "Hello, world!";
  char str2[] = "!dlrow";
  ck_assert_int_eq(strcspn(str1, str2), strcspn(str1, str2));
}
END_TEST

START_TEST(test10_strcspn) {
  char str1[] = "Hello, world!";
  char str2[] = "world! ";
  ck_assert_int_eq(strcspn(str1, str2), strcspn(str1, str2));
}
END_TEST

Suite *test_strcspn() {
  Suite *suite = suite_create("strcspn");
  TCase *tcase = tcase_create("strcspn_tcase");

  tcase_add_test(tcase, test1_strcspn);
  tcase_add_test(tcase, test2_strcspn);
  tcase_add_test(tcase, test3_strcspn);
  tcase_add_test(tcase, test4_strcspn);
  tcase_add_test(tcase, test5_strcspn);
  tcase_add_test(tcase, test6_strcspn);
  tcase_add_test(tcase, test7_strcspn);
  tcase_add_test(tcase, test8_strcspn);
  tcase_add_test(tcase, test9_strcspn);
  tcase_add_test(tcase, test10_strcspn);

  suite_add_tcase(suite, tcase);
  return suite;
}
