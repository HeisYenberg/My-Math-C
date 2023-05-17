#include "s21_math.h"

long double s21_ceil(double x) {
  long double result = (long int)x;
  if (x != x || s21_fabs(x) == S21_INF)
    result = x;
  else if (x - (int)x > 0)
    result = (long int)x + 1;
  return result;
}