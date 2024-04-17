#include "../test.h"

START_TEST(trim_test_1) {
  char s1[30] = "-?hello, world!";
  char s3[] = "!?-";
  char s4[] = "hello, world";
  char *ptr = (char *)trim(s1, s3);
  ck_assert_pstr_eq(s4, ptr);
  free(ptr);
}
END_TEST

START_TEST(trim_test_2) {
  char s1[30] = "";
  char s3[] = "";
  char *s4 = "";
  char *ptr = (char *)trim(s1, s3);
  ck_assert_pstr_eq(s4, ptr);
  free(ptr);
}
END_TEST

START_TEST(trim_test_3) {
  char *s1 = NULL;
  char s3[] = "";
  char *s4 = NULL;
  char *ptr = (char *)trim(s1, s3);
  ck_assert_pstr_eq(s4, ptr);
  free(ptr);
}
END_TEST

START_TEST(trim_test_4) {
  char s1[30] = "!!!abcdefghij!?!";
  char s3[] = "!?";
  char s4[] = "abcdefghij";
  char *ptr = (char *)trim(s1, s3);
  ck_assert_pstr_eq(s4, ptr);
  free(ptr);
}
END_TEST

START_TEST(trim_test_5) {
  char s1[30] = "abc";
  char s3[] = "333";
  char *s4 = "abc";
  char *ptr = (char *)trim(s1, s3);
  ck_assert_pstr_eq(s4, ptr);
  free(ptr);
}
END_TEST

START_TEST(trim_test_6) {
  char s1[30] = "hello, world!";
  char s3[] = "?!";
  char *s4 = "hello, world";
  char *ptr = (char *)trim(s1, s3);
  ck_assert_pstr_eq(s4, ptr);
  free(ptr);
}
END_TEST

START_TEST(trim_test_7) {
  char *s1 = NULL;
  char *s3 = NULL;
  char *s4 = NULL;
  char *ptr = (char *)trim(s1, s3);
  ck_assert_pstr_eq(s4, ptr);
  free(ptr);
}
END_TEST

START_TEST(trim_test_9) {
  char s1[30] = " wtf ";
  char *s3 = NULL;
  char *s4 = " wtf ";
  char *ptr = (char *)trim(s1, s3);
  ck_assert_pstr_eq(s4, ptr);
  free(ptr);
}
END_TEST

START_TEST(trim_test_10) {
  char s1[] = " wtf ";
  char *s3 = "";
  char *s4 = " wtf ";
  char *ptr = (char *)trim(s1, s3);
  ck_assert_pstr_eq(s4, ptr);
  free(ptr);
}
END_TEST

Suite *test_trim() {
  Suite *s = suite_create("trim");
  TCase *tc_create = tcase_create("trim");
  tcase_add_test(tc_create, trim_test_1);
  tcase_add_test(tc_create, trim_test_2);
  tcase_add_test(tc_create, trim_test_3);
  tcase_add_test(tc_create, trim_test_4);
  tcase_add_test(tc_create, trim_test_5);
  tcase_add_test(tc_create, trim_test_6);
  tcase_add_test(tc_create, trim_test_7);
  tcase_add_test(tc_create, trim_test_9);
  tcase_add_test(tc_create, trim_test_10);

  suite_add_tcase(s, tc_create);
  return s;
}