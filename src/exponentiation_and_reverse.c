#include "_math.h"

long double _exp(double x) {
  long double S = 1;
  if (x == x) {
    if (x != POS_INF && x != NEG_INF) {
      int flag = 0;
      double an = 1;
      long double eps = 1e-40, n = 1;
      if (x < 0) {
        x *= -1;
        flag = 1;
      }
      while (_fabs(an) > eps) {
        an *= x / n;
        n++;
        S += an;
        if (S > DBL_MAX) {
          S = POS_INF;
          break;
        }
      }
      if (flag == 1) {
        if (S > DBL_MAX) {
          S = 0;
        } else {
          S = 1. / S;
        }
      }
      if (S > DBL_MAX) {
        S = POS_INF;
      }
    } else {
      if (x == POS_INF) {
        S = x;
      } else {
        S = 0;
      }
    }
  } else {
    S = _NAN;
  }
  return S;
}

long double _log(double x) {
  int ex_pow = 0;
  double result = 0;
  double compare = 0;
  if (x == POS_INF) {
    result = POS_INF;
  } else if (x == 0) {
    result = NEG_INF;
  } else if (x < 0) {
    result = _NAN;
  } else if (x == 1) {
    result = 0;
  } else {
    for (; x >= _E; x /= _E, ex_pow++) continue;
    int i;
    for (i = 0; i < 100; i++) {
      compare = result;
      result = compare + 2 * (x - _exp(compare)) / (x + _exp(compare));
    }
  }
  return (result + ex_pow);
}

long double _pow(double base, double exp) {
  if (base_exp_check(&base, &exp) == 0) {
    const double base_base = base;
    if (_fmod(exp, 1) == 0 && exp != 0) {
      if (exp > 0) {
        base = exp_more_than_one(&base, &exp, &base_base);
      } else {
        for (int i = -1; i > exp; i--) {
          base *= base_base;
        }
        base = 1 / base;
      }
    } else if (exp == 0) {
      base = 1;
    } else {
      if (base < 0) {
        base = _NAN;
      } else if (base > 0) {
        base = _exp(_log(base) * exp);
      } else {
        base = 0;
      }
    }
  }
  return base;
}

int base_exp_check(double *base, const double *exp) {
  int flag = 1;
  if (*base != *base && *exp != 0) {
  } else if (*exp != *exp) {
    if (*base == 1) {
    } else {
      *base = _NAN;
    }
  } else if (*exp == NEG_INF) {
    if (*base < -1 || *base > 1) {
      *base = 0;
    } else if (*base == 1 || *base == -1) {
      *base = 1;
    } else {
      *base = POS_INF;
    }
  } else if (*exp == POS_INF) {
    if (*base < -1 || *base > 1) {
      *base = POS_INF;
    } else if (*base == 1 || *base == -1) {
      *base = 1;
    } else {
      *base = 0;
    }
  } else {
    flag = 0;
  }
  return flag;
}

double exp_more_than_one(double *base, double *exp, const double *base_base) {
  for (int i = 1; i < (int)*exp; i++) {
    *base *= *base_base;
  }
  return *base;
}

long double _sqrt(double x) {
  long double mid = 0;
  if (x == x) {
    long double left = 0, right = x > 1 ? x : 1;
    mid = (left + right) / 2;
    if (x < 0) {
      mid = _NAN;
    } else {
      while ((mid - left) > 1e-15) {
        if (mid * mid > x) {
          right = mid;
        } else {
          left = mid;
        }
        mid = (left + right) / 2;
      }
    }
  } else {
    mid = _NAN;
  }
  return mid;
}
