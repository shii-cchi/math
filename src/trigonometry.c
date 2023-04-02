#include "_math.h"

long double _cos(double x) {
  long double cos = 0, sign = 0, place = 0, new_x = 0;
  int flag = 2;
  new_x = lower_number(x);
  place = find_place(new_x);
  sign = find_sign(place, flag);
  if (new_x != POS_INF && new_x != NEG_INF && new_x == new_x) {
    for (int i = 0; i < 150; i++) {
      cos += (_pow(-1, i) * _pow(new_x, 2 * i)) / _factorial(2 * i);
    }
    cos = _fabs(cos) * sign;
  } else {
    cos = _NAN;
  }
  return cos;
}

long double _sin(double x) {
  long double sin = 0, new_x = 0, sign = 0, place = 0;
  int flag = 1;
  new_x = lower_number(x);
  place = find_place(new_x);
  sign = find_sign(place, flag);
  if (new_x != POS_INF && new_x != NEG_INF && new_x == new_x) {
    for (int i = 0; i < 150; i++) {
      sin += (_pow(-1, i) * _pow(new_x, 2 * i + 1)) / _factorial(2 * i + 1);
    }
    sin = _fabs(sin) * sign;
  } else {
    sin = _NAN;
  }
  return sin;
}

long double _tan(double x) {
  long double tan = 0, new_x = 0;
  new_x = lower_number(x);
  if (new_x != POS_INF && new_x != NEG_INF && new_x == new_x) {
    if (new_x == _PI / 2) {
      tan = 16331239353195370;
    } else if (new_x == -_PI / 2) {
      tan = -16331239353195370;
    } else {
      long double sin = _sin(new_x);
      long double cos = _cos(new_x);
      tan = sin / cos;
    }
  } else {
    tan = _NAN;
  }
  return tan;
}

long double lower_number(double x) {
  long double new_x = 0;
  new_x = x;
  if (new_x != POS_INF && new_x != NEG_INF) {
    long double n;
    while (new_x < -2 * _PI || new_x > 2 * _PI) {
      if (new_x < -10000000 || new_x > 10000000) {
        n = 2 * 4000000;
      } else {
        n = 2;
      }
      if (new_x < -2 * _PI) {
        new_x += n * _PI;
      } else {
        new_x -= n * _PI;
      }
    }
  }
  return new_x;
}

long double find_place(long double new_x) {
  long double place = 0;
  if ((new_x >= 0 && new_x <= _PI / 2) ||
      (new_x >= -2 * _PI && new_x <= -3 * _PI / 2) || new_x == 2 * _PI) {
    place = 0;
  } else if ((new_x > _PI / 2 && new_x <= _PI) ||
             (new_x > -3 * _PI / 2 && new_x <= -_PI)) {
    place = 1;
  } else if ((new_x > _PI && new_x <= 3 * _PI / 2) ||
             (new_x > -_PI && new_x <= -_PI / 2)) {
    place = 2;
  } else if ((new_x > 3 * _PI / 2 && new_x < 2 * _PI) ||
             (new_x > -_PI / 2 && new_x < 0)) {
    place = 3;
  } else {
    place = 4;
  }
  return place;
}

long double find_sign(long double place, int flag) {
  long double sign = -1;
  if (flag == 1) {
    if (place == 0 || place == 1) {
      sign = 1;
    }
  } else {
    if (place == 0 || place == 3) {
      sign = 1;
    }
  }
  return sign;
}
