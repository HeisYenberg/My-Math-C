#include "my_math.h"

int my_abs(int x) {
  if (x < 0) x = -x;
  return x;
}

long double my_acos(double x) {
  long double result = MY_NAN;
  if (!x)
    result = MY_M_PI_2;
  else if (my_fabs(x) <= 1) {
    if (x > 0)
      result = my_atan(my_sqrt(1 - x * x) / x);
    else
      result = my_atan(my_sqrt(1 - x * x) / x) + MY_M_PI;
  }
  return result;
}
long double my_asin(double x) {
  long double result = MY_NAN;
  if (my_fabs(x) <= 1) result = my_atan(x / (my_sqrt(1 - x * x)));
  return result;
}

long double my_atan(double x) {
  long double result = 0;
  if (x != x)
    result = MY_NAN;
  else if (x == 0)
    result = x;
  else if (x == -MY_INF)
    result = -MY_M_PI_2;
  else if (x == MY_INF)
    result = MY_M_PI_2;
  else if (my_fabs(x) == 1)
    result = MY_M_PI_4 * x;
  else if (my_fabs(x) < 1) {
    for (int i = 0; i < 5000; i++) {
      result += (my_pow(-1, i) * my_pow(x, 1 + 2 * i)) / (1 + 2 * i);
    }
  } else if (my_fabs(x) > 1) {
    for (int i = 0; i < 5000; i++)
      result += (my_pow(-1, i) * my_pow(x, -1 - 2 * i)) / (1 + 2 * i);
    result = ((MY_M_PI * my_sqrt(x * x)) / (2 * x)) - result;
  }
  return result;
}

long double my_ceil(double x) {
  long double result = (long int)x;
  if (x != x || my_fabs(x) == MY_INF)
    result = MY_NAN;
  else if (x - (int)x > 0)
    result = (long int)x + 1;
  return result;
}

long double my_cos(double x) {
  long double result = MY_NAN;
  if (x == x && my_fabs(x) != MY_INF) result = my_sin(MY_M_PI_2 - x);
  return result;
}

long double my_exp(double x) {
  long double result = 1, temp = 1;
  if (!x)
    result = 1;
  else if (x > 710)
    result = MY_INF;
  else if (x < 0)
    result = 1 / my_exp(-x);
  else {
    for (long int i = 1; temp > 1e-17; i++) result += temp *= x / i;
  }
  return result;
}

long double my_fabs(double x) {
  if (x < 0) x = -x;
  return x;
}

long double my_fact(int x) {
  long double result = 1;
  for (int i = 1; i <= x; i++) result *= i;
  return result;
}

long double my_floor(double x) {
  long double result = (long int)x;
  if (x != x || my_fabs(x) == MY_INF) result = x;
  if (x - (int)x < 0) result = (long int)x - 1;
  return result;
}

long double my_fmod(double x, double y) {
  long double result = 0;
  if (my_fabs(x) == MY_INF || !y)
    result = MY_NAN;
  else if (my_fabs(y) == MY_INF)
    result = x;
  else
    result = x - ((int)(x / y) * y);
  return result;
}

long double my_log(double x) {
  long double result = 0;
  if (!x)
    result = -MY_INF;
  else if (x < 0)
    result = -MY_NAN;
  else if (x != x || x == MY_INF)
    result = x;
  else {
    for (int i = 0; i < 100; i++)
      result = result + 2 * (x - my_exp(result)) / (x + my_exp(result));
  }
  return result;
}

long double my_pow(double x, double y) {
  long double result = 0;
  if (!x && !y)
    result = 1;
  else if (x == -MY_INF && y == MY_INF)
    result = MY_INF;
  else if (x == -MY_INF && y == -MY_INF)
    result = 0;
  else if (x < 0 && y - (int)y)
    result = -MY_NAN;
  else {
    result = my_exp(y * my_log(my_fabs(x)));
    if (x < 0 && (int)y % 2) result *= -1;
  }
  return result;
}

long double my_sin(double x) {
  long double result = 0;
  if (my_fabs(x) > 2 * MY_M_PI) x = my_fmod(x, 2 * MY_M_PI);
  for (int i = 0; i < 17; i++)
    result += (my_pow(-1, i) * my_pow(x, 1 + 2 * i)) / my_fact(1 + 2 * i);
  return result;
}

long double my_sqrt(double x) {
  long double result = MY_NAN;
  if (x >= 0) result = my_pow(x, 0.5);
  return result;
}

long double my_tan(double x) { return my_sin(x) / my_cos(x); }