#include <check.h>
#include <math.h>
#include <stdlib.h>

#include "my_math.h"

START_TEST(test_my_abs) {
  ck_assert_int_eq(my_abs(2), abs(2));
  ck_assert_int_eq(my_abs(-25), abs(-25));
  ck_assert_int_eq(my_abs(1), abs(1));
  ck_assert_int_eq(my_abs(-1), abs(-1));
  ck_assert_int_eq(my_abs(0), abs(0));
  ck_assert_int_eq(my_abs(-999999999), abs(-999999999));
  ck_assert_int_eq(my_abs(999999999), abs(999999999));
  ck_assert_int_eq(my_abs(5), abs(5));
  ck_assert_int_eq(my_abs(-5), abs(-5));
}
END_TEST

START_TEST(test_my_fabs) {
  ck_assert_double_eq(my_fabs(2.526624), fabs(2.526624));
  ck_assert_double_eq(my_fabs(-25.000331), fabs(-25.000331));
  ck_assert_double_eq(my_fabs(1.), fabs(1.));
  ck_assert_double_eq(my_fabs(0.), fabs(0.));
  ck_assert_ldouble_nan(my_fabs(my_NAN));
  ck_assert_ldouble_infinite(my_fabs(my_POSITIVE_INF));
  ck_assert_ldouble_eq(my_fabs(-21.45673), fabs(-21.45673));
  ck_assert_ldouble_eq(my_fabs(1e308), fabs(1e308));
  ck_assert_ldouble_eq(my_fabs(-1e308), fabs(-1e308));
  ck_assert_ldouble_eq(my_fabs(-0.0), fabs(-0.0));
  ck_assert_ldouble_eq(my_fabs(1.0), fabs(1.0));
}
END_TEST

START_TEST(test_my_ceil) {
  ck_assert_double_eq(my_ceil(0.), ceil(0.));
  ck_assert_double_eq(my_ceil(1.), ceil(1.));
  ck_assert_double_eq(my_ceil(2.526624), ceil(2.526624));
  ck_assert_double_eq(my_ceil(-2.526624), ceil(-2.526624));
  ck_assert_ldouble_nan(my_ceil(my_NAN));
  ck_assert_ldouble_infinite(my_ceil(my_POSITIVE_INF));
  ck_assert_ldouble_infinite(my_ceil(my_NEGATIVE_INF));
  ck_assert_ldouble_eq(my_ceil(0.0), ceil(0.0));
  ck_assert_ldouble_eq(my_ceil(21.45673), ceil(21.45673));
  ck_assert_ldouble_eq(my_ceil(-21.45673), ceil(-21.45673));
  ck_assert_ldouble_eq(my_ceil(-0.5), ceil(-0.5));
}
END_TEST

START_TEST(test_my_floor) {
  ck_assert_double_eq(my_floor(0.), floor(0.));
  ck_assert_double_eq(my_floor(1.), floor(1.));
  ck_assert_double_eq(my_floor(2.526624), floor(2.526624));
  ck_assert_double_eq(my_floor(-2.526624), floor(-2.526624));
  ck_assert_ldouble_nan(my_floor(my_NAN));
  ck_assert_ldouble_infinite(my_floor(my_POSITIVE_INF));
  ck_assert_ldouble_infinite(my_floor(my_NEGATIVE_INF));
}
END_TEST

START_TEST(test_my_exp) {
  ck_assert_double_eq(my_exp(0.), exp(0.));
  ck_assert_double_eq_tol(my_exp(1.), exp(1.), 0.000001);
  ck_assert_double_eq_tol(my_exp(2.526624), exp(2.526624), 0.000001);
  ck_assert_double_eq_tol(my_exp(-2.526624), exp(-2.526624), 0.000001);
  ck_assert_double_eq_tol(my_exp(20), exp(20), 0.000001);
  ck_assert_ldouble_infinite(my_exp(9999999999999999.0));
  ck_assert_ldouble_infinite(my_exp(1.7976931348623158e+308));
  ck_assert_ldouble_nan(my_exp(my_NAN));
  ck_assert_ldouble_infinite(my_exp(my_POSITIVE_INF));
  ck_assert_double_eq(my_exp(my_NEGATIVE_INF), exp(my_NEGATIVE_INF));
  ck_assert_ldouble_infinite(my_exp(1e+308));
}
END_TEST

START_TEST(test_my_log) {
  ck_assert_double_eq_tol(my_log(1.), log(1.), 0.000001);
  ck_assert_ldouble_infinite(my_log(0.));
  ck_assert_double_eq_tol(my_log(628), log(628), 0.000001);
  ck_assert_ldouble_nan(my_log(-2.526624));
  ck_assert_ldouble_nan(my_log(-1));
  ck_assert_ldouble_nan(my_log(my_NAN));
  ck_assert_ldouble_infinite(my_log(my_POSITIVE_INF));
  ck_assert_double_eq_tol(my_log(2.526624), log(2.526624), 0.000001);
  ck_assert_double_eq_tol(my_log(1.7976931348623158e+308),
                          log(1.7976931348623158e+308), 0.000001);
  ck_assert_double_eq_tol(my_log(9999999999999999.0), log(9999999999999999.0),
                          0.000001);
  ck_assert_double_eq_tol(my_log(0.0000006), log(0.0000006), 0.000001);
  ck_assert_ldouble_eq_tol(my_log(1e308), log(1e308), 0.0000001);
}
END_TEST

START_TEST(test_my_sqrt) {
  ck_assert_double_eq_tol(my_sqrt(0.), sqrt(0.), 0.000001);
  ck_assert_double_eq_tol(my_sqrt(1.), sqrt(1.), 0.000001);
  ck_assert_ldouble_nan(my_sqrt(-1.));
  ck_assert_double_eq_tol(my_sqrt(2.526624), sqrt(2.526624), 0.000001);
  ck_assert_double_eq_tol(my_sqrt(9999999999999999.0),
                          sqrt(9999999999999999.0), 0.000001);
  ck_assert_ldouble_nan(my_sqrt(-2.526624));
  ck_assert_ldouble_nan(my_sqrt(my_NAN));
  ck_assert_ldouble_infinite(my_sqrt(my_POSITIVE_INF));
  ck_assert_ldouble_nan(my_sqrt(my_NEGATIVE_INF));
  ck_assert_double_eq_tol(my_sqrt(628), sqrt(628), 0.000001);
}
END_TEST

START_TEST(test_my_fmod) {
  ck_assert_ldouble_nan(my_fmod(0., 0.));
  ck_assert_ldouble_nan(my_fmod(2.526624, 0.));
  ck_assert_ldouble_nan(my_fmod(my_NAN, my_NAN));
  ck_assert_ldouble_nan(my_fmod(my_NAN, 2.526624));
  ck_assert_ldouble_nan(my_fmod(2.526624, my_NAN));
  ck_assert_ldouble_nan(my_fmod(my_POSITIVE_INF, my_POSITIVE_INF));
  ck_assert_ldouble_nan(my_fmod(my_POSITIVE_INF, 2.5));
  ck_assert_ldouble_nan(my_fmod(my_NAN, my_POSITIVE_INF));
  ck_assert_ldouble_nan(my_fmod(my_POSITIVE_INF, my_NAN));
  ck_assert_double_eq(my_fmod(0., 2.526624), fmod(0., 2.526624));
  ck_assert_double_eq(my_fmod(2.526624, my_POSITIVE_INF),
                      fmod(2.526624, my_POSITIVE_INF));
  ck_assert_double_eq(my_fmod(5.897357, 5.897357), fmod(5.897357, 5.897357));
  ck_assert_double_eq(my_fmod(-5.897357, 3.326624), fmod(-5.897357, 3.326624));
  ck_assert_double_eq(my_fmod(5.897357, -3.326624), fmod(5.897357, -3.326624));
  ck_assert_ldouble_eq(my_fmod(24.5435, -54.3454), fmod(24.5435, -54.3454));
  ck_assert_ldouble_eq(my_fmod(-54.3454, 24.5435), fmod(-54.3454, 24.5435));
  ck_assert_ldouble_eq(my_fmod(5, my_POSITIVE_INF),
                       fmod(5, my_POSITIVE_INF));
  ck_assert_ldouble_eq(my_fmod(5, my_NEGATIVE_INF),
                       fmod(5, my_NEGATIVE_INF));
  ck_assert_ldouble_nan(my_fmod(my_POSITIVE_INF, 5));
  ck_assert_ldouble_nan(my_fmod(my_NEGATIVE_INF, 5));
  ck_assert_ldouble_nan(my_fmod(my_NAN, 5));
  ck_assert_ldouble_nan(my_fmod(5, my_NAN));
}
END_TEST

START_TEST(test_my_pow) {
  ck_assert_double_eq_tol(my_pow(-1., my_POSITIVE_INF),
                          pow(-1., my_POSITIVE_INF), 0.000001);
  ck_assert_double_eq_tol(my_pow(0., 0.), pow(0., 0.), 0.000001);
  ck_assert_double_eq_tol(my_pow(1., 1.), pow(1., 1.), 0.000001);
  ck_assert_double_eq_tol(my_pow(1., 2), pow(1., 2), 0.000001);
  ck_assert_double_eq_tol(my_pow(2.526624, 0.), pow(2.526624, 0.), 0.000001);
  ck_assert_double_eq_tol(my_pow(2.526624, 2.526624), pow(2.526624, 2.526624),
                          0.000001);
  ck_assert_double_eq_tol(my_pow(1., my_NAN), pow(1., my_NAN), 0.000001);
  ck_assert_double_eq_tol(my_pow(1., my_POSITIVE_INF),
                          pow(1., my_POSITIVE_INF), 0.000001);
  ck_assert_double_eq_tol(my_pow(1., my_NEGATIVE_INF),
                          pow(1., my_NEGATIVE_INF), 0.000001);
  ck_assert_ldouble_nan(my_pow(2.526624, my_NAN));
  ck_assert_ldouble_infinite(my_pow(2.526624, my_POSITIVE_INF));
  ck_assert_double_eq_tol(my_pow(2.526624, my_NEGATIVE_INF),
                          pow(2.526624, my_NEGATIVE_INF), 0.000001);
  ck_assert_double_eq_tol(my_pow(0., 2), pow(0., 2), 0.000001);
  ck_assert_ldouble_nan(my_pow(0., my_NAN));
  ck_assert_double_eq_tol(my_pow(0., my_POSITIVE_INF),
                          pow(0., my_POSITIVE_INF), 0.000001);
  ck_assert_ldouble_infinite(my_pow(0., my_NEGATIVE_INF));
  ck_assert_double_eq_tol(my_pow(685, 3), pow(685, 3), 0.000001);
  ck_assert_double_eq_tol(my_pow(-2.526624, 3), pow(-2.526624, 3), 0.000001);
  ck_assert_double_eq_tol(my_pow(-2.526624, -3), pow(-2.526624, -3), 0.000001);
  ck_assert_double_eq_tol(my_pow(2.526624, -3), pow(2.526624, -3), 0.000001);
  ck_assert_double_eq_tol(my_pow(2.526624, 3), pow(2.526624, 3), 0.000001);
  ck_assert_double_eq_tol(my_pow(2.526624, 3.5), pow(2.526624, 3.5), 0.000001);
  ck_assert_double_eq_tol(my_pow(2.526624, -3.5), pow(2.526624, -3.5),
                          0.000001);
  ck_assert_ldouble_nan(my_pow(my_NAN, 2));
  ck_assert_ldouble_infinite(my_pow(my_POSITIVE_INF, 2));
  ck_assert_ldouble_infinite(my_pow(my_NEGATIVE_INF, 2));
  ck_assert_ldouble_infinite(my_pow(my_NEGATIVE_INF, 2.5));
  ck_assert_ldouble_infinite(my_pow(my_POSITIVE_INF, my_POSITIVE_INF));
  ck_assert_ldouble_infinite(my_pow(1.7976931348623158e+308, 2));
  ck_assert_ldouble_infinite(my_pow(2, 1.7976931348623158e+308));
  ck_assert_ldouble_eq(my_pow(2134, 0), pow(2134, 0));
  ck_assert_ldouble_eq(my_pow(-1234.234, 0), pow(-1234.234, 0));
  ck_assert_ldouble_eq(my_pow(0, -234.23432), pow(0, -234.23432));
  ck_assert_ldouble_eq(my_pow(0, 1234.234), pow(0, 1234.234));
  ck_assert_ldouble_eq(my_pow(my_POSITIVE_INF, 1234.123),
                       pow(my_POSITIVE_INF, 1234.123));
  ck_assert_ldouble_eq(my_pow(my_POSITIVE_INF, -1234.234),
                       pow(my_POSITIVE_INF, -1234.234));
  ck_assert_ldouble_eq(my_pow(my_NEGATIVE_INF, -1234.234),
                       pow(my_NEGATIVE_INF, -1234.234));
  ck_assert_ldouble_eq(my_pow(my_NEGATIVE_INF, -1234.234),
                       pow(my_NEGATIVE_INF, -1234.234));
  ck_assert_ldouble_eq(my_pow(-1234.234, my_NEGATIVE_INF),
                       pow(-1234.234, my_NEGATIVE_INF));
  ck_assert_ldouble_eq(my_pow(1234.123, my_NEGATIVE_INF),
                       pow(1234.123, my_NEGATIVE_INF));
  ck_assert_ldouble_eq(my_pow(1234.123, my_POSITIVE_INF),
                       pow(1234.123, my_POSITIVE_INF));
  ck_assert_ldouble_eq(my_pow(my_POSITIVE_INF, my_POSITIVE_INF),
                       pow(my_POSITIVE_INF, my_POSITIVE_INF));
  ck_assert_ldouble_eq(my_pow(my_NEGATIVE_INF, my_NEGATIVE_INF),
                       pow(my_NEGATIVE_INF, my_NEGATIVE_INF));
  ck_assert_ldouble_nan(my_pow(my_NAN, -2345.2345));
  ck_assert_ldouble_nan(my_pow(my_NAN, 2345.2345));
  ck_assert_ldouble_nan(my_pow(-2345.2345, my_NAN));
  ck_assert_ldouble_nan(my_pow(2345.2345, my_NAN));
  ck_assert_ldouble_eq_tol(my_pow(2.234, -5.234), pow(2.234, -5.234),
                           0.0000001);
  ck_assert_ldouble_eq_tol(my_pow(-2.543, 3), pow(-2.543, 3), 0.0000001);
  ck_assert_ldouble_eq_tol(my_pow(-2.543, 4), pow(-2.543, 4), 0.0000001);
  ck_assert_ldouble_eq_tol(my_pow(2.234, -3), pow(2.234, -3), 0.0000001);
}
END_TEST

START_TEST(test_my_atan) {
  ck_assert_double_eq_tol(my_atan(0.), atan(0.), 0.000001);
  ck_assert_double_eq_tol(my_atan(1.), atan(1.), 0.000001);
  ck_assert_double_eq_tol(my_atan(628), atan(628), 0.000001);
  ck_assert_double_eq_tol(my_atan(2.526624), atan(2.526624), 0.000001);
  ck_assert_double_eq_tol(my_atan(-2.526624), atan(-2.526624), 0.000001);
  ck_assert_ldouble_nan(my_atan(my_NAN));
  ck_assert_double_eq_tol(my_atan(my_POSITIVE_INF), atan(my_POSITIVE_INF),
                          0.000001);
  ck_assert_double_eq_tol(my_atan(my_NEGATIVE_INF), atan(my_NEGATIVE_INF),
                          0.000001);
  ck_assert_ldouble_eq(my_atan(0), atan(0));
  ck_assert_ldouble_eq_tol(my_atan(1), atan(1), 0.0000001);
  ck_assert_ldouble_eq_tol(my_atan(-1), atan(-1), 0.0000001);
  ck_assert_ldouble_eq_tol(my_atan(0.5), atan(0.5), 0.0000001);
  ck_assert_ldouble_eq_tol(my_atan(-0.5), atan(-0.5), 0.0000001);
  ck_assert_ldouble_eq_tol(my_atan(1e308), atan(1e308), 0.0000001);
  ck_assert_ldouble_eq_tol(my_atan(-1e308), atan(-1e308), 0.0000001);
  ck_assert_ldouble_eq_tol(my_atan(1e-16), atan(1e-16), 0.0000001);
  ck_assert_ldouble_eq_tol(my_atan(-1e-16), atan(-1e-16), 0.0000001);
  ck_assert_ldouble_eq_tol(my_atan(100), atan(100), 0.00000001);
  ck_assert_ldouble_eq_tol(my_atan(my_POSITIVE_INF), atan(my_POSITIVE_INF),
                           0.0000001);
  ck_assert_ldouble_eq_tol(my_atan(my_NEGATIVE_INF), atan(my_NEGATIVE_INF),
                           0.0000001);
  ck_assert_ldouble_nan(my_atan(my_NAN));
}
END_TEST

START_TEST(test_my_asin) {
  ck_assert_double_eq_tol(my_asin(0.), asin(0.), 0.000001);
  ck_assert_double_eq_tol(my_asin(1.), asin(1.), 0.000001);
  ck_assert_ldouble_nan(my_asin(628));
  ck_assert_ldouble_nan(my_asin(2.526624));
  ck_assert_ldouble_nan(my_asin(-2.526624));
  ck_assert_ldouble_nan(my_asin(my_NAN));
  ck_assert_ldouble_nan(my_asin(my_POSITIVE_INF));
  ck_assert_ldouble_nan(my_asin(my_NEGATIVE_INF));
  ck_assert_ldouble_eq(my_asin(0), asin(0));
  ck_assert_ldouble_eq_tol(my_asin(1), asin(1), 0.0000001);
  ck_assert_ldouble_eq_tol(my_asin(-1), asin(-1), 0.0000001);
  ck_assert_ldouble_nan(my_asin(1e308));
  ck_assert_ldouble_nan(my_asin(-1e308));
  ck_assert_ldouble_nan(my_asin(2.3425));
  ck_assert_ldouble_nan(my_asin(-2.3425));
  ck_assert_ldouble_nan(my_asin(my_POSITIVE_INF));
  ck_assert_ldouble_nan(my_asin(my_NEGATIVE_INF));
  ck_assert_ldouble_nan(my_asin(my_NAN));
}
END_TEST

START_TEST(test_my_acos) {
  ck_assert_double_eq_tol(my_acos(0.), acos(0.), 0.000001);
  ck_assert_double_eq_tol(my_acos(-1.), acos(-1.), 0.000001);
  ck_assert_double_eq(my_acos(1.), acos(1.));
  ck_assert_ldouble_nan(my_acos(628));
  ck_assert_ldouble_nan(my_acos(2.526624));
  ck_assert_ldouble_nan(my_acos(-2.526624));
  ck_assert_ldouble_nan(my_acos(my_NAN));
  ck_assert_ldouble_nan(my_acos(my_POSITIVE_INF));
  ck_assert_ldouble_nan(my_acos(my_NEGATIVE_INF));
  ck_assert_ldouble_eq_tol(my_acos(0), acos(0), 0.0000001);
  ck_assert_ldouble_eq(my_acos(1), acos(1));
  ck_assert_ldouble_eq_tol(my_acos(-1), acos(-1), 0.0000001);
  ck_assert_ldouble_nan(my_acos(2.3425));
  ck_assert_ldouble_nan(my_acos(-2.3425));
  ck_assert_ldouble_eq_tol(my_acos(1e-309), acos(1e-309), 0.0000001);
  ck_assert_ldouble_eq_tol(my_acos(-1e-308), acos(-1e-308), 0.0000001);
  ck_assert_ldouble_nan(my_acos(1e308));
  ck_assert_ldouble_nan(my_acos(-1e308));
  ck_assert_ldouble_nan(my_acos(my_POSITIVE_INF));
  ck_assert_ldouble_nan(my_acos(my_NEGATIVE_INF));
  ck_assert_ldouble_nan(my_acos(my_NAN));
}
END_TEST

START_TEST(test_my_sin) {
  ck_assert_double_eq_tol(my_sin(0.), sin(0.), 0.000001);
  ck_assert_double_eq_tol(my_sin(1.), sin(1.), 0.000001);
  ck_assert_double_eq_tol(my_sin(628), sin(628), 0.000001);
  ck_assert_double_eq_tol(my_sin(2.526624), sin(2.526624), 0.000001);
  ck_assert_double_eq_tol(my_sin(-2.526624), sin(-2.526624), 0.000001);
  ck_assert_ldouble_nan(my_sin(my_NAN));
  ck_assert_ldouble_nan(my_sin(my_POSITIVE_INF));
  ck_assert_ldouble_nan(my_sin(my_NEGATIVE_INF));
}
END_TEST

START_TEST(test_my_cos) {
  ck_assert_double_eq(my_cos(0.), cos(0.));
  ck_assert_double_eq_tol(my_cos(1.), cos(1.), 0.000001);
  ck_assert_double_eq_tol(my_cos(628), cos(628), 0.000001);
  ck_assert_double_eq_tol(my_cos(2.526624), cos(2.526624), 0.000001);
  ck_assert_double_eq_tol(my_cos(-2.526624), cos(-2.526624), 0.000001);
  ck_assert_ldouble_nan(my_cos(my_NAN));
  ck_assert_ldouble_nan(my_cos(my_POSITIVE_INF));
}
END_TEST

START_TEST(test_my_tan) {
  ck_assert_double_eq_tol(my_tan(0.), tan(0.), 0.000001);
  ck_assert_double_eq_tol(my_tan(1.), tan(1.), 0.000001);
  ck_assert_double_eq_tol(my_tan(628), tan(628), 0.000001);
  ck_assert_double_eq_tol(my_tan(2.526624), tan(2.526624), 0.000001);
  ck_assert_double_eq_tol(my_tan(-2.526624), tan(-2.526624), 0.000001);
  ck_assert_ldouble_nan(my_tan(my_NAN));
  ck_assert_ldouble_nan(my_tan(my_POSITIVE_INF));
  ck_assert_ldouble_nan(my_tan(my_NEGATIVE_INF));
}
END_TEST

int main() {
  Suite *s = suite_create("Suite");
  TCase *tc = tcase_create("Case");
  SRunner *sr = srunner_create(s);

  tcase_add_test(tc, test_my_abs);
  tcase_add_test(tc, test_my_fabs);
  tcase_add_test(tc, test_my_ceil);
  tcase_add_test(tc, test_my_floor);
  tcase_add_test(tc, test_my_exp);
  tcase_add_test(tc, test_my_log);
  tcase_add_test(tc, test_my_sqrt);
  tcase_add_test(tc, test_my_fmod);
  tcase_add_test(tc, test_my_pow);
  tcase_add_test(tc, test_my_atan);
  tcase_add_test(tc, test_my_asin);
  tcase_add_test(tc, test_my_acos);
  tcase_add_test(tc, test_my_sin);
  tcase_add_test(tc, test_my_cos);
  tcase_add_test(tc, test_my_tan);

  suite_add_tcase(s, tc);
  srunner_run_all(sr, CK_NORMAL);

  int failed = srunner_ntests_failed(sr);

  srunner_free(sr);

  return failed == 0 ? 0 : 1;
}