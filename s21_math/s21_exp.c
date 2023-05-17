#include "s21_math.h"

long double s21_exp(double x) {
  long double result = 1, temp = 1;
  if (!x)
    result = 1;
  else if (x > 710)
    result = S21_INF;
  else if (x < 0)
    result = 1 / s21_exp(-x);
  else {
    for (long int i = 1; temp > 1e-17; i++) result += temp *= x / i;
  }
  return result;
}