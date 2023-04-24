#include "base/Vec3.h"

/**
 * The component n is built automatically from (l, m) and the specified sign
 * so as to obtain a unit vector.
 * */
Vec3 Vec3_lm (double l, double m, bool nsign) {
  // nsign: True for +1, False for -1.
  double n = std::sqrt(1 - l*l - m*m);
  n = (nsign) ? n : - n;
  Vec3 v (l, m, n);
  return v;
}

