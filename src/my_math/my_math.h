#ifndef MY_MATH_H
#define MY_MATH_H

#define MY_INF __builtin_inf()
#define MY_NAN __builtin_nan("")
#define MY_M_E 2.718281828459045235360287471352662498
#define MY_M_PI 3.141592653589793238462643383279502884
#define MY_M_PI_2 1.570796326794896619231321691639751442
#define MY_M_PI_4 0.785398163397448309615660845819875721
#define MY_EPS_9 1e-9

int my_abs(int x);
long double my_acos(double x);
long double my_asin(double x);
long double my_atan(double x);
long double my_ceil(double x);
long double my_cos(double x);
long double my_exp(double x);
long double my_fabs(double x);
long double my_fact(int x);
long double my_floor(double x);
long double my_fmod(double x, double y);
long double my_log(double x);
long double my_pow(double x, double y);
long double my_sin(double x);
long double my_sqrt(double x);
long double my_tan(double x);

#endif // MY_MATH_H
