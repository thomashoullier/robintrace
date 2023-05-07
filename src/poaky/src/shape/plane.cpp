#include "shape/plane.h"

/** The ray is assumed to rest at the current LCS plane, so intersect
 *  does nothing for a plane shape.
 *
 *  There are no error cases. */
void plane::intersect (ray &r) {
  (void)(r);
}

/** The plane shape normal is position-invariant. Its value is always
 * \f[ \overrightarrow{N} = (0, 0, -\textrm{sign}(n))\f]
 *
 * There are no error cases. */
Vec3 plane::normal (const ray &r) {
  double sig_n = std::copysign(1.0, r.v(2));
  return Vec3(0, 0, - sig_n);
}

std::string plane::print_str () const {
  return "plane";
}

