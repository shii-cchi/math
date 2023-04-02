#ifndef SRC__MATH_H_
#define SRC__MATH_H_

#include <float.h>

#define _PI 3.14159265358979323846
#define _E 2.71828182845904523536
#define POS_INF 1.0 / 0.0
#define NEG_INF -1.0 / 0.0
#define _NAN 0.0 / 0.0

int _abs(int x);
long double _acos(double x);
long double _asin(double x);
long double _atan(double x);
long double _ceil(double x);
long double _cos(double x);
long double _exp(double x);
long double _fabs(double x);
long double _floor(double x);
long double _fmod(double x, double y);
long double _log(double x);
long double _pow(double base, double exp);
long double _sin(double x);
long double _sqrt(double x);
long double _tan(double x);
long double _factorial(int number);

double exp_more_than_one(double *base, double *exp, const double *base_base);
int base_exp_check(double *base, const double *exp);
long double lower_number(double x);
long double find_place(long double new_x);
long double find_sign(long double place, int flag);

#endif  //  SRC__MATH_H_
