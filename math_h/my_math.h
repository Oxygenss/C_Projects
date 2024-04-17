#include <float.h>

#ifndef my_MATH_H
#define my_MATH_H

#define my_PI \
  3.1415926535897932384626433832795028841971693993751058209749445923078164062862089986280348253421170679821480865132823066470938446095505822317253594081284811174502841027019385211055596446229489549303819644288109756659334461284756482337867831652712019091L
#define my_2PI 2.0 * my_PI
#define my_EXP 2.7182818284590452353602874713526624L

#define my_EPS 1e-300

#define my_POSITIVE_INF 1.0 / 0.0
#define my_NEGATIVE_INF -1.0 / 0.0
#define my_NAN 0.0 / 0.0

int my_abs(int x);
long double my_fabs(double x);
long double my_ceil(double x);
long double my_floor(double x);
long double my_exp(double x);
long double my_log(double x);
long double my_sqrt(double x);
long double my_fmod(double x, double y);
long double my_pow(double base, double exp);

long double my_atan(double x);
long double my_acos(double x);
long double my_asin(double x);

long double my_cos(double x);
long double my_sin(double x);
long double my_tan(double x);

long double my_sinn(double x);
long double my_coss(double x);
long double my_tann(double x);

#endif