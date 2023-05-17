#include "s21_math.h"

long double s21_sin(double x) {
  long double result = 0;
  if (s21_fabs(x) > 2 * S21_M_PI) x = s21_fmod(x, 2 * S21_M_PI);
  for (int i = 0; i < 17; i++)
    result += (s21_pow(-1, i) * s21_pow(x, 1 + 2 * i)) / s21_fact(1 + 2 * i);
  return result;
}