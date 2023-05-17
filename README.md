# s21_math 
## My version of the standard math.h library in the C programming language.

##  Usage :
- To build a library run `make s21_math.a`
- To see tests run `make test`, might need to install `check`.
- To see tests code coverage run `make gcov_report`, might need to install `lcov`. 
### Overview of "s21_math.h" functions

| No. | Function | Description |
| --- | -------- | ----------- |
| 1 | `int abs(int x)` | computes absolute value of an integer value |
| 2 | `long double acos(double x)` | computes arc cosine |
| 3 | `long double asin(double x)` | computes arc sine |
| 4 | `long double atan(double x)` | computes arc tangent |
| 5 | `long double ceil(double x)` | returns the nearest integer not less than the given value |
| 6 | `long double cos(double x)` | computes cosine |
| 7 | `long double exp(double x)` | returns e raised to the given power |
| 8 | `long double fabs(double x)` | computes absolute value of a floating-point value |
| 9 | `long double fact(int x)` | computes a factorial of a number |
| 10 | `long double floor(double x)` | returns the nearest integer not greater than the given value |
| 11 | `long double fmod(double x, double y)` | remainder of the floating-point division operation |
| 12 | `long double log(double x)` | computes natural logarithm |
| 13 | `long double pow(double base, double exp)` | raises a number to the given power |
| 14 | `long double sin(double x)` | computes sine |
| 15 | `long double sqrt(double x)` | computes square root |
| 16 | `long double tan(double x)` | computes tangent |