#include "_math.h"

int _abs(int x) {
  if (x < 0) {
    x = -x;
  }
  return x;
}

long double _ceil(double x) {
  if ((x - (int)x) != 0 && x != POS_INF && x != NEG_INF) {
    if (x > 0) {
      x += 1 - (x - (int)x);
    } else if (x < 0) {
      x += -(x - (int)x);
    }
  }
  return x;
}

long double _fabs(double x) {
  if (x < 0) {
    x = -x;
  }
  return x;
}

long double _floor(double x) {
  if ((x - (int)x) != 0 && x != POS_INF && x != NEG_INF) {
    if (x >= 0) {
      x += -(x - (int)x);
    } else {
      x += -1 - (x - (int)x);
    }
  }
  return x;
}

long double _fmod(double x, double y) {
  long double res = 0;
  if ((!(x == x) || !(y == y)) || (x == POS_INF || x == NEG_INF) || (y == 0)) {
    res = _NAN;
  } else if (y == POS_INF || y == NEG_INF) {
    res = x;
  } else {
    res = (long double)x - (int)(x / y) * (long double)y;
  }
  return res;
}

long double _factorial(int number) {
  long double result = 1;
  for (int i = 1; i <= number; i++) {
    result = result * i;
  }
  return result;
}
