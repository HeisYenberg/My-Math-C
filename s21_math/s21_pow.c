#include "s21_math.h"

long double s21_pow(double x, double y) {
  long double result = 0;
  if (!x && !y)
    result = 1;
  else if (x == -S21_INF && y == S21_INF)
    result = S21_INF;
  else if (x == -S21_INF && y == -S21_INF)
    result = 0;
  else if (x < 0 && y - (int)y)
    result = -S21_NAN;
  else {
    result = s21_exp(y * s21_log(s21_fabs(x)));
    if (x < 0 && (int)y % 2) result *= -1;
  }
  return result;
}