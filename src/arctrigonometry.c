#include "_math.h"

long double _atan(double x) {
  int indicate_of_chandge = 0;
  int amount_of_decreas = 0;
  if (x < 0) {
    indicate_of_chandge |= 1;
    x = -x;
  }
  if (x > 1) {
    indicate_of_chandge |= 2;
    x = 1 / x;
  }
  while (x > _PI / 12) {
    x = (x * _sqrt((double)3) - 1) / (x + _sqrt((double)3));
    amount_of_decreas++;
  }
  double res =
      x * (0.55913709 / (1.4087812 + x * x) + 0.60310579 - 0.05160454 * x * x);
  while (amount_of_decreas != 0) {
    res = res + _PI / 6;
    amount_of_decreas--;
  }
  if ((indicate_of_chandge & 2)) {
    res = _PI / 2 - res;
  }
  if (indicate_of_chandge & 1) {
    res = -res;
  }
  return res;
}

long double _asin(double x) {
  long double res = 0;
  if (x > 1 || x < -1) {
    res = _NAN;
  } else {
    res = _atan(x / _sqrt(1 - x * x));
  }
  return res;
}

long double _acos(double x) {
  long double res = 0;
  if (x > 1 || x < -1) {
    res = _NAN;
  } else {
    res = _PI / 2 - _asin(x);
  }
  return res;
}
