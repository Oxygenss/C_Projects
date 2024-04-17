#include "../test.h"

START_TEST(test1_insert) {
  char s1[30] = "hello, world!";
  char s3[] = "hELLO, WORLD!";
  char s4[] = "hello, hELLO, WORLD!world!";
  my_size_t num = 7;
  ck_assert_pstr_eq(s4, insert(s1, s3, num));
}
END_TEST

START_TEST(test2_insert) {
  char s1[30] = "";
  char s3[1] = "";
  char *s4 = NULL;
  my_size_t num = 7;
  ck_assert_pstr_eq(s4, insert(s1, s3, num));
}
END_TEST

START_TEST(test3_insert) {
  char s1[] = "";
  char s3[] = "";
  char *s4 = s1;
  my_size_t num = 0;
  ck_assert_pstr_eq(s4, insert(s1, s3, num));
}
END_TEST

START_TEST(test4_insert) {
  char s1[30] = "abcdefghij";
  char s3[] = "\'I WAS HERE\'";
  char s4[] = "abc\'I WAS HERE\'defghij";
  my_size_t num = 3;
  ck_assert_pstr_eq(s4, insert(s1, s3, num));
}
END_TEST

START_TEST(test5_insert) {
  char s1[30] = "abc";
  char s3[] = "333";
  char *s4 = NULL;
  my_size_t num = 10;
  ck_assert_pstr_eq(s4, insert(s1, s3, num));
}
END_TEST

START_TEST(test6_insert) {
  char s1[30] = "hello, world!";
  char s3[] = "hELLO, WORLD!";
  char *s4 = NULL;
  my_size_t num = -1;
  ck_assert_pstr_eq(s4, insert(s1, s3, num));
}
END_TEST

START_TEST(test7_insert) {
  char *s1 = NULL;
  char *s3 = NULL;
  char *s4 = NULL;
  my_size_t num = 0;
  ck_assert_pstr_eq(s4, insert(s1, s3, num));
}
END_TEST

START_TEST(test8_insert) {
  char s1[30] = "";
  char s3[] = "";
  char s4[] = "";
  my_size_t num = 0;
  ck_assert_pstr_eq(s4, insert(s1, s3, num));
}
END_TEST

START_TEST(test9_insert) {
  char s1[] = "wtf";
  char *s3 = NULL;
  char *s4 = NULL;
  my_size_t num = 0;
  ck_assert_pstr_eq(s4, insert(s1, s3, num));
}
END_TEST

START_TEST(test10_insert) {
  char s1[] = "";
  char *s3 = NULL;
  char *s4 = NULL;
  my_size_t num = 0;
  ck_assert_pstr_eq(s4, insert(s1, s3, num));
}
END_TEST

Suite *test_insert() {
  Suite *suite = suite_create("insert");
  TCase *tcase = tcase_create("insert_tcase");

  tcase_add_test(tcase, test1_insert);
  tcase_add_test(tcase, test2_insert);
  tcase_add_test(tcase, test3_insert);
  tcase_add_test(tcase, test4_insert);
  tcase_add_test(tcase, test5_insert);
  tcase_add_test(tcase, test6_insert);
  tcase_add_test(tcase, test7_insert);
  tcase_add_test(tcase, test8_insert);
  tcase_add_test(tcase, test9_insert);
  tcase_add_test(tcase, test10_insert);

  suite_add_tcase(suite, tcase);
  return suite;
}
