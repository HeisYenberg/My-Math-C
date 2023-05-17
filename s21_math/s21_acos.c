#include "s21_math.h"

long double s21_acos(double x) {
  long double result = 0;
  if (x != x)
    result = x;
  else if (s21_fabs(x) == S21_INF)
    result = S21_NAN;
  else if (!x)
    result = S21_M_PI_2;
  else if (s21_fabs(x) <= 1) {
    if (x > 0)
      result = s21_atan(s21_sqrt(1 - x * x) / x);
    else
      result = s21_atan(s21_sqrt(1 - x * x) / x) + S21_M_PI;
  } else
    result = S21_NAN;
  return result;
}