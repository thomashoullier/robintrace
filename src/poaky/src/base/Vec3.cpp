#include "base/Vec3.h"

/**
 * The component n is built automatically from (l, m) and the specified sign
 * so as to obtain a unit vector.
 *
 * When \p nsign is True,
 * \f[
 *   n = \sqrt{1 - l^2 - m^2}
 * \f]
 * When \p nsign is False,
 * \f[
 *   n = - \sqrt{1 - l^2 - m^2}
 * \f]
 * */
Vec3 Vec3_lm (double l, double m, bool nsign) {
  // nsign: True for +1, False for -1.
  double n = std::sqrt(1 - l*l - m*m);
  n = (nsign) ? n : - n;
  Vec3 v (l, m, n);
  return v;
}

