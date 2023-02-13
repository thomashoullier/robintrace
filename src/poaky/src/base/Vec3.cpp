#include "base/Vec3.h"

Vec3 Vec3_lm (double l, double m, bool nsign) {
  // Construct and initialize a unit Vec3. The component n
  // is built automatically from l, m and its specified sign.
  // zsign is true for +1, false for -1.
  double n = std::sqrt(1 - l*l - m*m);
  n = (nsign) ? n : - n;
  Vec3 v (l, m, n);
  return v;
}

