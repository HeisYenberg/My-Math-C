#include "s21_math.h"

long double s21_cos(double x) {
  long double result = 0;
  if (x != x || s21_fabs(x) == S21_INF)
    result = S21_NAN;
  else
    result = s21_sin(S21_M_PI_2 - x);
  return result;
}