#include "s21_math.h"

long double s21_fact(int x) {
  long double result = 1;
  for (int i = 1; i <= x; i++) result *= i;
  return result;
}