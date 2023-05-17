#include "s21_math.h"

long double s21_fmod(double x, double y) {
  long double result = 0;
  if (s21_fabs(x) == S21_INF || !y)
    result = S21_NAN;
  else if (s21_fabs(y) == S21_INF)
    result = x;
  else
    result = x - ((int)(x / y) * y);
  return result;
}