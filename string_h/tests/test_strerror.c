#include "../test.h"

START_TEST(test1_strerror) {
  for (int i = 0; i < 107; i++) {
    ck_assert_str_eq(strerror(i), strerror(i));
  }
}
END_TEST

Suite *test_strerror() {
  Suite *suite = suite_create("strerror");
  TCase *tcase = tcase_create("strerror_tcase");

  tcase_add_test(tcase, test1_strerror);

  suite_add_tcase(suite, tcase);
  return suite;
}
