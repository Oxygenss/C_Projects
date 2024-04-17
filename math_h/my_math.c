#include "my_math.h"

int my_abs(int x) { return x > 0 ? x : -x; }

long double my_fabs(double x) { return x > 0 ? x : -x; }

long double my_ceil(double x) {
  if (x == my_POSITIVE_INF) {
    return my_POSITIVE_INF;
  } else if (x == my_NEGATIVE_INF) {
    return my_NEGATIVE_INF;
  } else if (x != x) {
    return my_NAN;
  }
  long double ceil_x = (long long int)x;

  if (x > ceil_x) {
    ceil_x += 1;
  }

  if (-1 < x && x < 0) {
    ceil_x = -0.0;
  }

  return ceil_x;
}

long double my_floor(double x) {
  if (x == my_POSITIVE_INF) {
    return my_POSITIVE_INF;
  } else if (x == my_NEGATIVE_INF) {
    return my_NEGATIVE_INF;
  } else if (x != x) {
    return my_NAN;
  }

  long double floor_x = (long long int)x;

  if (my_fabs(x - floor_x) > 0. && my_fabs(x) > 0.) {
    if (x < 0.) {
      floor_x -= 1;
    }
  }

  return floor_x;
}

long double my_exp(double x) {
  if (x == my_NEGATIVE_INF) {
    return 0;
  }

  long double iteration = 1;
  long double value = 1;
  long double i = 1;
  int flag = 0;
  if (x < 0) {
    x *= -1;
    flag = 1;
  }

  while (my_fabs(iteration) > my_EPS) {
    iteration *= x / i;
    i += 1;
    value += iteration;
    if (value > DBL_MAX) {
      value = my_POSITIVE_INF;
      break;
    }
  }

  if (flag) {
    value = 1 / value;
  }

  return value;
}

long double my_log(double x) {
  long double result = 0;
  double temp = 0;
  int count = 0;
  if (x == my_POSITIVE_INF) {
    return my_POSITIVE_INF;
  } else if (x == 0) {
    return my_NEGATIVE_INF;
  } else if (x < 0) {
    return my_NAN;
  } else {
    while (x > my_EXP) {
      x /= my_EXP;
      count++;
    }
    for (int i = 0; i < 200; i++) {
      temp = result;
      result = temp + 2 * (x - my_exp(temp)) / (x + my_exp(temp));
    }
    result += count;
  }

  return result;
}

long double my_sqrt(double x) {
  if (x == my_NEGATIVE_INF) {
    return my_NAN;
  } else if (x != x) {
    return my_NAN;
  } else if (x < 0) {
    return my_NAN;
  } else if (x == 0) {
    return 0;
  }

  return my_pow(x, 0.5);
}

long double my_pow(double base, double exp1) {
  long double result;
  long long int copy_exp = (long long int)exp1;

  if (base == 0 && exp1 > 0) return 0;
  if (base == my_NEGATIVE_INF && exp1 < 0 && exp1 != (long long int)exp1)
    return 0;
  if (base == my_NEGATIVE_INF && exp1 != (long long int)exp1)
    return my_POSITIVE_INF;
  if (base == 0 && exp1 < 0) return my_POSITIVE_INF;
  if (base == 1 || exp1 == 0 || exp1 == -0) return 1;
  if (base == -1 && (exp1 == my_NEGATIVE_INF || exp1 == my_POSITIVE_INF))
    return 1;
  if (exp1 == my_NEGATIVE_INF) return 0;
  if (base < 0 && exp1 != (long long int)exp1) return my_NAN;
  int flag = 0;

  if (base < 0 && (copy_exp & 1)) {
    flag = 1;
    base = -base;
  } else if (base < 0 && !(copy_exp & 1)) {
    base = -base;
  }

  if (exp1 > 0) {
    result = my_exp(exp1 * my_log(base));
  } else {
    exp1 = -exp1;
    result = 1 / my_exp(exp1 * my_log(base));
  }

  if (flag) {
    result = -result;
  }
  return result;
}

long double my_fmod(double x, double y) {
  if (x == 0 && y == 0) {
    return my_NAN;
  } else if (x == 0) {
    return 0;
  } else if (y == 0) {
    return my_NAN;
  } else if (x == my_NEGATIVE_INF || x == my_POSITIVE_INF) {
    return my_NAN;
  } else if (y == my_NEGATIVE_INF || y == my_POSITIVE_INF) {
    return x;
  }
  long long int mod = x / y;

  return (long double)x - mod * (long double)y;
}

long double my_atan(double x) {
  if (x == my_POSITIVE_INF) {
    return my_PI / 2;
  } else if (x == my_NEGATIVE_INF) {
    return -my_PI / 2;
  } else if (x == 1) {
    return my_PI / 4;
  } else if (x == -1) {
    return -my_PI / 4;
  } else if (x != x) {
    return my_NAN;
  } else if (x == 0) {
    return 0;
  } else {
    if (-1 < x && x < 1) {
      long double sum = 0;
      long double term = x;
      int i = 1;
      while (my_fabs(term) >= my_EPS) {
        sum += term;
        term *= -x * x * (2 * i - 1) / (2 * i + 1);
        i++;
      }
      return sum;
    } else if (x < -1) {
      long double result = -my_PI / 2 - my_atan(1 / x);
      return result;
    } else {
      long double result = my_PI / 2 - my_atan(1 / x);
      return result;
    }
  }
}

long double my_asin(double x) {
  long double result;
  if (x >= -1 && x <= 1) {
    result = my_atan(x / my_sqrt(1 - x * x));
  } else {
    return my_NAN;
  }

  return result;
}

long double my_acos(double x) {
  long double result;

  if (x >= 0 && x <= 1) {
    result = my_atan(my_sqrt(1 - x * x) / x);
  } else if (x >= -1 && x <= 0) {
    result = my_PI + my_atan(my_sqrt(1 - x * x) / x);
  } else {
    result = my_NAN;
  }

  return result;
}

long double my_sin(double x) {
  if (x == my_POSITIVE_INF || x == my_NEGATIVE_INF || x == my_NAN) {
    return my_NAN;
  }

  char sign = 1;
  x = my_fmod(x, 2 * my_PI);

  if (x < 0) {
    x += 2 * my_PI;
  }

  if ((x > my_PI) && (x < 3 * my_PI)) {
    sign = -1;
  }

  long double result = my_sqrt(1 - my_pow(my_cos(x), 2));
  return sign * result;
}

long double my_cos(double x) {
  x = my_fmod(x, my_2PI);
  char sign = 1;
  if (x > my_PI) {
    x -= my_PI;
    sign = -1;
  }
  double xx = x * x;

  return sign *
         (1 - ((xx) / (2)) + ((xx * xx) / (24)) - ((xx * xx * xx) / (720)) +
          ((xx * xx * xx * xx) / (40320)) -
          ((xx * xx * xx * xx * xx) / (3628800)) +
          ((xx * xx * xx * xx * xx * xx) / (479001600)) -
          ((xx * xx * xx * xx * xx * xx * xx) / (87178291200)) +
          ((xx * xx * xx * xx * xx * xx * xx * xx) / (20922789888000)) -
          ((xx * xx * xx * xx * xx * xx * xx * xx * xx) / (6402373705728000)) +
          ((xx * xx * xx * xx * xx * xx * xx * xx * xx * xx) /
           (2432902008176640000)));
}

long double my_tan(double x) {
  long double result;
  if (x == my_POSITIVE_INF || x == my_NEGATIVE_INF)
    result = -my_NAN;
  else if (x == my_NAN)
    result = my_NAN;
  else
    result = my_sin(x) / my_cos(x);
  return result;
}
