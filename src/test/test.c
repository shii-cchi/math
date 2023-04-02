#include <check.h>
#include <math.h>
#include <stdlib.h>

#include "../_math.h"

START_TEST(abs_test) {
  ck_assert_int_eq(abs(0), _abs(0));
  ck_assert_int_eq(abs(1), _abs(1));
  ck_assert_int_eq(abs(-1), _abs(-1));
  ck_assert_int_eq(abs(12345678), _abs(12345678));
  ck_assert_int_eq(abs(-12345678), _abs(-12345678));
  ck_assert_int_eq(abs(2147483647), _abs(2147483647));
  ck_assert_int_eq(abs(-2147483647), _abs(-2147483647));
}
END_TEST

START_TEST(ceil_test) {
  ck_assert_ldouble_eq(ceil(POS_INF), _ceil(POS_INF));
  ck_assert_ldouble_eq(ceil(NEG_INF), _ceil(NEG_INF));
  ck_assert_ldouble_nan(ceil(_NAN));
  ck_assert_ldouble_nan(_ceil(_NAN));
  ck_assert_ldouble_eq(ceil(0), _ceil(0));
  ck_assert_ldouble_eq(ceil(-0), _ceil(-0));
  ck_assert_ldouble_eq(ceil(1.0), _ceil(1.0));
  ck_assert_ldouble_eq(ceil(-1.0), _ceil(-1.0));
  ck_assert_ldouble_eq(ceil(1.1), _ceil(1.1));
  ck_assert_ldouble_eq(ceil(-1.1), _ceil(-1.1));
  ck_assert_ldouble_eq(ceil(12345.678), _ceil(12345.678));
  ck_assert_ldouble_eq(ceil(-12345.678), _ceil(-12345.678));
  ck_assert_ldouble_eq(ceil(1e9), _ceil(1e9));
  ck_assert_ldouble_eq(ceil(-1e9), _ceil(-1e9));
  ck_assert_ldouble_eq(ceil(999999999.999999), _ceil(999999999.999999));
  ck_assert_ldouble_eq(ceil(-999999999.999999), _ceil(-999999999.999999));
}
END_TEST

START_TEST(fabs_test) {
  ck_assert_ldouble_eq(fabs(POS_INF), _fabs(POS_INF));
  ck_assert_ldouble_eq(fabs(NEG_INF), _fabs(NEG_INF));
  ck_assert_ldouble_nan(fabs(_NAN));
  ck_assert_ldouble_nan(_fabs(_NAN));
  ck_assert_ldouble_eq(fabs(1.0), _fabs(1.0));
  ck_assert_ldouble_eq(fabs(-1.0), _fabs(-1.0));
  ck_assert_ldouble_eq(fabs(12345.678), _fabs(12345.678));
  ck_assert_ldouble_eq(fabs(-12345.678), _fabs(-12345.678));
  ck_assert_ldouble_eq(fabs(1e10), _fabs(1e10));
  ck_assert_ldouble_eq(fabs(-1e10), _fabs(-1e10));
  ck_assert_ldouble_eq(fabs(9999999999.999999), _fabs(9999999999.999999));
  ck_assert_ldouble_eq(fabs(-9999999999.999999), _fabs(-9999999999.999999));
}
END_TEST

START_TEST(floor_test) {
  ck_assert_ldouble_eq(floor(POS_INF), _floor(POS_INF));
  ck_assert_ldouble_eq(floor(NEG_INF), _floor(NEG_INF));
  ck_assert_ldouble_nan(floor(_NAN));
  ck_assert_ldouble_nan(_floor(_NAN));
  ck_assert_ldouble_eq(floor(0), _floor(0));
  ck_assert_ldouble_eq(floor(-0), _floor(-0));
  ck_assert_ldouble_eq(floor(1.0), _floor(1.0));
  ck_assert_ldouble_eq(floor(-1.0), _floor(-1.0));
  ck_assert_ldouble_eq(floor(1.1), _floor(1.1));
  ck_assert_ldouble_eq(floor(-1.1), _floor(-1.1));
  ck_assert_ldouble_eq(floor(12345.678), _floor(12345.678));
  ck_assert_ldouble_eq(floor(-12345.678), _floor(-12345.678));
  ck_assert_ldouble_eq(floor(1e9), _floor(1e9));
  ck_assert_ldouble_eq(floor(-1e9), _floor(-1e9));
  ck_assert_ldouble_eq(floor(999999999.999999), _floor(999999999.999999));
  ck_assert_ldouble_eq(floor(-999999999.999999), _floor(-999999999.999999));
}
END_TEST

START_TEST(fmod_test_1) {
  ck_assert_ldouble_nan(fmod(_NAN, _NAN));
  ck_assert_ldouble_nan(_fmod(_NAN, _NAN));
  ck_assert_ldouble_nan(fmod(_NAN, POS_INF));
  ck_assert_ldouble_nan(_fmod(_NAN, POS_INF));
  ck_assert_ldouble_nan(fmod(_NAN, NEG_INF));
  ck_assert_ldouble_nan(_fmod(_NAN, NEG_INF));
  ck_assert_ldouble_nan(fmod(POS_INF, _NAN));
  ck_assert_ldouble_nan(_fmod(POS_INF, _NAN));
  ck_assert_ldouble_nan(fmod(NEG_INF, _NAN));
  ck_assert_ldouble_nan(_fmod(NEG_INF, _NAN));
  ck_assert_ldouble_nan(fmod(POS_INF, POS_INF));
  ck_assert_ldouble_nan(_fmod(POS_INF, POS_INF));
  ck_assert_ldouble_nan(fmod(POS_INF, NEG_INF));
  ck_assert_ldouble_nan(_fmod(POS_INF, NEG_INF));
  ck_assert_ldouble_nan(fmod(NEG_INF, NEG_INF));
  ck_assert_ldouble_nan(_fmod(NEG_INF, NEG_INF));
  ck_assert_ldouble_nan(fmod(NEG_INF, POS_INF));
  ck_assert_ldouble_nan(_fmod(NEG_INF, POS_INF));
  ck_assert_ldouble_nan(_fmod(0, _NAN));
  ck_assert_ldouble_nan(fmod(0, _NAN));
  ck_assert_ldouble_nan(_fmod(_NAN, 0));
  ck_assert_ldouble_nan(fmod(_NAN, 0));
  ck_assert_ldouble_nan(_fmod(1, _NAN));
  ck_assert_ldouble_nan(fmod(1, _NAN));
  ck_assert_ldouble_nan(_fmod(_NAN, 1));
  ck_assert_ldouble_nan(fmod(_NAN, 1));
  ck_assert_ldouble_eq(fmod(0, POS_INF), _fmod(0, POS_INF));
  ck_assert_ldouble_eq(fmod(0, NEG_INF), _fmod(0, NEG_INF));
  ck_assert_ldouble_nan(fmod(POS_INF, 0));
  ck_assert_ldouble_nan(_fmod(POS_INF, 0));
  ck_assert_ldouble_nan(fmod(NEG_INF, 0));
  ck_assert_ldouble_nan(_fmod(NEG_INF, 0));
  ck_assert_ldouble_nan(fmod(POS_INF, 1));
  ck_assert_ldouble_nan(_fmod(POS_INF, 1));
  ck_assert_ldouble_nan(fmod(NEG_INF, 1));
  ck_assert_ldouble_nan(_fmod(NEG_INF, 1));
  ck_assert_ldouble_eq(fmod(-1, NEG_INF), _fmod(-1, NEG_INF));
  ck_assert_ldouble_eq(fmod(-1, POS_INF), _fmod(-1, POS_INF));
  ck_assert_ldouble_nan(fmod(POS_INF, -1));
  ck_assert_ldouble_nan(_fmod(POS_INF, -1));
  ck_assert_ldouble_nan(fmod(NEG_INF, -1));
  ck_assert_ldouble_nan(_fmod(NEG_INF, -1));
}
END_TEST

START_TEST(fmod_test_2) {
  ck_assert_ldouble_nan(fmod(0, 0));
  ck_assert_ldouble_nan(_fmod(0, 0));
  ck_assert_ldouble_eq(fmod(0, 1), _fmod(0, 1));
  ck_assert_ldouble_eq(fmod(0, -1), _fmod(0, -1));
  ck_assert_ldouble_nan(fmod(1, 0));
  ck_assert_ldouble_nan(_fmod(1, 0));
  ck_assert_ldouble_nan(fmod(-1, 0));
  ck_assert_ldouble_nan(_fmod(-1, 0));
  for (double k = -1500; k <= 1500; k += 150) {
    for (double j = -10; j <= 10; j += 1.25) {
      if (j != 0 && k != 0) {
        ck_assert_ldouble_eq(fmod(k, j), _fmod(k, j));
        ck_assert_ldouble_eq(fmod(j, k), _fmod(j, k));
      }
    }
  }
}
END_TEST

START_TEST(sin_test) {
  ck_assert_ldouble_nan(sin(_NAN));
  ck_assert_ldouble_nan(_sin(_NAN));
  ck_assert_ldouble_nan(sin(POS_INF));
  ck_assert_ldouble_nan(_sin(POS_INF));
  ck_assert_ldouble_nan(sin(NEG_INF));
  ck_assert_ldouble_nan(_sin(NEG_INF));
  for (int k = 0; k <= 20; k++) {
    for (double r = -2 * _PI; r <= 2 * _PI; r += _PI / 24) {
      ck_assert_ldouble_eq_tol(sin(2 * _PI * k + r),
                               _sin(2 * _PI * k + r), 1e-6);
    }
  }
  ck_assert_ldouble_eq_tol(sin(9999999999.999999), _sin(9999999999.999999),
                           1e-6);
  ck_assert_ldouble_eq_tol(sin(-9999999999.999999), _sin(-9999999999.999999),
                           1e-6);
}
END_TEST

START_TEST(cos_test) {
  ck_assert_ldouble_nan(cos(_NAN));
  ck_assert_ldouble_nan(_cos(_NAN));
  ck_assert_ldouble_nan(cos(POS_INF));
  ck_assert_ldouble_nan(_cos(POS_INF));
  ck_assert_ldouble_nan(cos(NEG_INF));
  ck_assert_ldouble_nan(_cos(NEG_INF));
  ck_assert_ldouble_eq_tol(cos(_PI / 2), _cos(_PI / 2), 1e-6);
  ck_assert_ldouble_eq_tol(cos(3 * _PI / 2), _cos(3 * _PI / 2), 1e-6);
  for (int k = 0; k <= 20; k++) {
    for (double r = -2 * _PI; r <= 2 * _PI; r += _PI / 24) {
      ck_assert_ldouble_eq_tol(cos(2 * _PI * k + r),
                               _cos(2 * _PI * k + r), 1e-6);
    }
  }
  ck_assert_ldouble_eq_tol(cos(9999999999.999999), _cos(9999999999.999999),
                           1e-6);
  ck_assert_ldouble_eq_tol(cos(-9999999999.999999), _cos(-9999999999.999999),
                           1e-6);
}
END_TEST

START_TEST(tan_test) {
  ck_assert_ldouble_nan(tan(_NAN));
  ck_assert_ldouble_nan(_tan(_NAN));
  ck_assert_ldouble_nan(tan(POS_INF));
  ck_assert_ldouble_nan(_tan(POS_INF));
  ck_assert_ldouble_nan(tan(NEG_INF));
  ck_assert_ldouble_nan(_tan(NEG_INF));
  ck_assert_ldouble_eq_tol(tan(_PI / 2), _tan(_PI / 2), 1e-6);
  ck_assert_ldouble_eq_tol(tan(-_PI / 2), _tan(-_PI / 2), 1e-6);
  for (int k = 0; k <= 20; k++) {
    for (double r = -2 * _PI; r <= 2 * _PI; r += _PI / 11) {
      ck_assert_ldouble_eq_tol(tan(2 * _PI * k + r),
                               _tan(2 * _PI * k + r), 1e-6);
    }
  }
  ck_assert_ldouble_eq_tol(tan(9999999999.999999), _tan(9999999999.999999),
                           1e-6);
  ck_assert_ldouble_eq_tol(tan(-9999999999.999999), _tan(-9999999999.999999),
                           1e-6);
}
END_TEST

START_TEST(asin_test) {
  ck_assert_ldouble_nan(asin(_NAN));
  ck_assert_ldouble_nan(_asin(_NAN));
  ck_assert_ldouble_nan(asin(POS_INF));
  ck_assert_ldouble_nan(_asin(POS_INF));
  ck_assert_ldouble_nan(asin(NEG_INF));
  ck_assert_ldouble_nan(_asin(NEG_INF));
  ck_assert_ldouble_nan(asin(2));
  ck_assert_ldouble_nan(_asin(2));
  ck_assert_ldouble_nan(asin(-2));
  ck_assert_ldouble_nan(_asin(-2));
  for (float k = -1; k <= 1; k += 0.05) {
    ck_assert_ldouble_eq_tol(asin(k), _asin(k), 1e-6);
  }
}
END_TEST

START_TEST(acos_test) {
  ck_assert_ldouble_nan(acos(_NAN));
  ck_assert_ldouble_nan(_acos(_NAN));
  ck_assert_ldouble_nan(acos(POS_INF));
  ck_assert_ldouble_nan(_acos(POS_INF));
  ck_assert_ldouble_nan(acos(NEG_INF));
  ck_assert_ldouble_nan(_acos(NEG_INF));
  ck_assert_ldouble_nan(acos(2));
  ck_assert_ldouble_nan(_acos(2));
  ck_assert_ldouble_nan(acos(-2));
  ck_assert_ldouble_nan(_acos(-2));
  for (float k = -1; k <= 1; k += 0.05) {
    ck_assert_ldouble_eq_tol(acos(k), _acos(k), 1e-6);
  }
}
END_TEST

START_TEST(atan_test) {
  ck_assert_ldouble_nan(atan(_NAN));
  ck_assert_ldouble_nan(_atan(_NAN));
  ck_assert_ldouble_eq(atan(POS_INF), _atan(POS_INF));
  ck_assert_ldouble_eq(atan(NEG_INF), atan(NEG_INF));
  for (float k = -100; k <= 100; k += 2.05) {
    ck_assert_ldouble_eq_tol(atan(k), _atan(k), 1e-6);
  }
  ck_assert_ldouble_eq_tol(atan(9999999999.999999), _atan(9999999999.999999),
                           1e-6);
  ck_assert_ldouble_eq_tol(atan(-9999999999.999999),
                           _atan(-9999999999.999999), 1e-6);
}
END_TEST

START_TEST(exp_test) {
  ck_assert_ldouble_nan(exp(_NAN));
  ck_assert_ldouble_nan(_exp(_NAN));
  ck_assert_ldouble_eq(exp(POS_INF), _exp(POS_INF));
  ck_assert_ldouble_eq(exp(NEG_INF), _exp(NEG_INF));
  ck_assert_ldouble_eq(exp(0), _exp(0));
  ck_assert_ldouble_eq_tol(exp(1), _exp(1), 1e-6);
  for (double k = -100; k <= 100; k += 1.5) {
    long double err = 1e-6;
    int i = 0;
    while ((int)exp(k) / (1e11 * (pow(10, i)))) {
      i++;
    }
    err *= pow(10, i);
    ck_assert_ldouble_eq_tol(exp(k), _exp(k), err);
  }
  for (double k = -10; k <= 10; k += 0.0045) {
    ck_assert_ldouble_eq_tol(exp(k), _exp(k), 1e-6);
  }
  ck_assert_ldouble_eq(exp(9999999999.999999), _exp(9999999999.999999));
  ck_assert_ldouble_eq(exp(-9999999999.999999), _exp(-9999999999.999999));
}
END_TEST

START_TEST(log_test) {
  ck_assert_ldouble_nan(log(_NAN));
  ck_assert_ldouble_nan(_log(_NAN));
  ck_assert_ldouble_eq(log(POS_INF), _log(POS_INF));
  ck_assert_ldouble_nan(log(NEG_INF));
  ck_assert_ldouble_nan(_log(NEG_INF));
  ck_assert_ldouble_eq(log(0), _log(0));
  ck_assert_ldouble_eq_tol(log(1), _log(1), 1e-6);
  ck_assert_ldouble_nan(log(-1));
  ck_assert_ldouble_nan(_log(-1));
  ck_assert_ldouble_eq_tol(log(_E), _log(_E), 1e-6);
  for (double k = 2; k <= 100; k += 1.5) {
    ck_assert_ldouble_eq_tol(log(k), _log(k), 1e-6);
  }
  for (double k = 2; k <= 10; k += 0.0045) {
    ck_assert_ldouble_eq_tol(log(k), _log(k), 1e-6);
  }
  ck_assert_ldouble_eq_tol(log(9999999999.999999), _log(9999999999.999999),
                           1e-6);
}
END_TEST

START_TEST(pow_test_1) {
  ck_assert_ldouble_nan(pow(_NAN, _NAN));
  ck_assert_ldouble_nan(_pow(_NAN, _NAN));
  ck_assert_ldouble_nan(pow(_NAN, POS_INF));
  ck_assert_ldouble_nan(_pow(_NAN, POS_INF));
  ck_assert_ldouble_nan(pow(_NAN, NEG_INF));
  ck_assert_ldouble_nan(_pow(_NAN, NEG_INF));
  ck_assert_ldouble_nan(pow(_NAN, 1));
  ck_assert_ldouble_nan(_pow(_NAN, 1));
  ck_assert_ldouble_eq(pow(_NAN, 0), _pow(_NAN, 0));
  ck_assert_ldouble_nan(pow(0, _NAN));
  ck_assert_ldouble_nan(_pow(0, _NAN));
  ck_assert_ldouble_eq(pow(1, _NAN), _pow(1, _NAN));
  ck_assert_ldouble_nan(pow(POS_INF, _NAN));
  ck_assert_ldouble_nan(_pow(POS_INF, _NAN));
  ck_assert_ldouble_nan(pow(NEG_INF, _NAN));
  ck_assert_ldouble_nan(_pow(NEG_INF, _NAN));
  ck_assert_ldouble_eq(pow(POS_INF, POS_INF), _pow(POS_INF, POS_INF));
  ck_assert_ldouble_eq(pow(POS_INF, NEG_INF), _pow(POS_INF, NEG_INF));
  ck_assert_ldouble_eq(pow(NEG_INF, NEG_INF), _pow(NEG_INF, NEG_INF));
  ck_assert_ldouble_eq(pow(NEG_INF, POS_INF), _pow(NEG_INF, POS_INF));
  ck_assert_ldouble_eq(pow(-1, POS_INF), _pow(-1, POS_INF));
  ck_assert_ldouble_eq(pow(0.5, POS_INF), _pow(0.5, POS_INF));
  ck_assert_ldouble_eq(pow(1, POS_INF), _pow(1, POS_INF));
  ck_assert_ldouble_eq(pow(-1, NEG_INF), _pow(-1, NEG_INF));
  ck_assert_ldouble_eq(pow(2, POS_INF), _pow(2, POS_INF));
  ck_assert_ldouble_eq(pow(0.5, NEG_INF), _pow(0.5, NEG_INF));
  ck_assert_ldouble_eq(pow(1, NEG_INF), _pow(1, NEG_INF));
  ck_assert_ldouble_eq(pow(2, NEG_INF), _pow(2, NEG_INF));
  ck_assert_ldouble_eq(pow(POS_INF, 0), _pow(POS_INF, 0));
  ck_assert_ldouble_eq(pow(NEG_INF, 0), _pow(NEG_INF, 0));
  ck_assert_ldouble_eq(pow(POS_INF, 1), _pow(POS_INF, 1));
  ck_assert_ldouble_eq(pow(NEG_INF, 1), _pow(NEG_INF, 1));
  ck_assert_ldouble_eq(pow(POS_INF, -1), _pow(POS_INF, -1));
  ck_assert_ldouble_eq(pow(NEG_INF, -1), _pow(NEG_INF, -1));
}
END_TEST

START_TEST(pow_test_2) {
  ck_assert_ldouble_eq(pow(0, 0), _pow(0, 0));
  ck_assert_ldouble_eq(pow(0, 1), _pow(0, 1));
  ck_assert_ldouble_eq(pow(0, -1), _pow(0, -1));
  ck_assert_ldouble_eq(pow(1, 0), _pow(1, 0));
  ck_assert_ldouble_eq(pow(-1, 0), _pow(-1, 0));
  ck_assert_ldouble_eq(pow(-1, 2), _pow(-1, 2));
  ck_assert_ldouble_eq(pow(-1, 3), _pow(-1, 3));
  ck_assert_ldouble_nan(pow(-1, 1.1));
  ck_assert_ldouble_nan(_pow(-1, 1.1));
  for (double k = -10; k <= 10; k += 1) {
    for (double j = -5; j <= 5; j += 1) {
      if (pow(k, j) == pow(k, j) && _pow(k, j) == _pow(k, j) &&
          pow(k, j) != POS_INF && pow(k, j) != NEG_INF &&
          _pow(k, j) != POS_INF && _pow(k, j) != NEG_INF) {
        ck_assert_ldouble_eq_tol(pow(k, j), _pow(k, j), 1e-7);
      }
    }
  }
  for (double k = -0.01; k <= 0.01; k += 0.001) {
    for (double j = -1.5; j <= 1.5; j += 0.5) {
      if (pow(k, j) == pow(k, j) && _pow(k, j) == _pow(k, j) &&
          pow(k, j) != POS_INF && pow(k, j) != NEG_INF &&
          _pow(k, j) != POS_INF && _pow(k, j) != NEG_INF) {
        long double err = 1e-6;
        int i = 0;
        while ((int)exp(k) / (1e11 * (pow(10, i)))) {
          i++;
        }
        err *= pow(10, i);
        ck_assert_ldouble_eq_tol(pow(k, j), _pow(k, j), err);
      }
    }
  }
}
END_TEST

START_TEST(sqrt_test) {
  ck_assert_ldouble_nan(sqrt(_NAN));
  ck_assert_ldouble_nan(_sqrt(_NAN));
  ck_assert_ldouble_eq(sqrt(POS_INF), _sqrt(POS_INF));
  ck_assert_ldouble_nan(sqrt(NEG_INF));
  ck_assert_ldouble_nan(_sqrt(NEG_INF));
  ck_assert_ldouble_eq_tol(sqrt(0), _sqrt(0), 1e-6);
  ck_assert_ldouble_eq_tol(sqrt(0), _sqrt(0), 1e-6);
  ck_assert_ldouble_nan(sqrt(-1));
  ck_assert_ldouble_nan(_sqrt(-1));
  for (double k = 1; k <= 100; k += 1.5) {
    ck_assert_ldouble_eq_tol(sqrt(k), _sqrt(k), 1e-6);
  }
  for (double k = 1; k <= 10; k += 0.0045) {
    ck_assert_ldouble_eq_tol(sqrt(k), _sqrt(k), 1e-6);
  }
  ck_assert_ldouble_eq_tol(sqrt(9999999999.999999), _sqrt(9999999999.999999),
                           1e6);
}
END_TEST

Suite *_math_suite(void) {
  Suite *suite = suite_create("_math");
  TCase *tcase_core = tcase_create("math");
  tcase_add_test(tcase_core, abs_test);
  tcase_add_test(tcase_core, ceil_test);
  tcase_add_test(tcase_core, fabs_test);
  tcase_add_test(tcase_core, floor_test);
  tcase_add_test(tcase_core, fmod_test_1);
  tcase_add_test(tcase_core, fmod_test_2);
  tcase_add_test(tcase_core, sin_test);
  tcase_add_test(tcase_core, cos_test);
  tcase_add_test(tcase_core, tan_test);
  tcase_add_test(tcase_core, asin_test);
  tcase_add_test(tcase_core, acos_test);
  tcase_add_test(tcase_core, atan_test);
  tcase_add_test(tcase_core, exp_test);
  tcase_add_test(tcase_core, log_test);
  tcase_add_test(tcase_core, pow_test_1);
  tcase_add_test(tcase_core, pow_test_2);
  tcase_add_test(tcase_core, sqrt_test);
  suite_add_tcase(suite, tcase_core);
  return suite;
}

int main(void) {
  Suite *suite = _math_suite();
  SRunner *suite_runner = srunner_create(suite);
  srunner_run_all(suite_runner, CK_VERBOSE);
  srunner_free(suite_runner);
  return 0;
}
