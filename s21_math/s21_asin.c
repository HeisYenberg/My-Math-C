#include "s21_math.h"

long double s21_asin(double x) {
  long double result = 0;
  if (x != x)
    result = x;
  else if (x) {
    if (s21_fabs(x) <= 1)
      result = s21_atan(x / (s21_sqrt(1 - x * x)));
    else
      result = S21_NAN;
  }
  return result;
}