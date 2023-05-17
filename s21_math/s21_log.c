#include "s21_math.h"

long double s21_log(double x) {
  long double result = 0;
  if (!x)
    result = -S21_INF;
  else if (x < 0)
    result = -S21_NAN;
  else if (x != x || x == S21_INF)
    result = x;
  else {
    for (int i = 0; i < 100; i++)
      result = result + 2 * (x - s21_exp(result)) / (x + s21_exp(result));
  }
  return result;
}