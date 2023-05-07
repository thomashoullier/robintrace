#include "ray/ray.h"

/** The ray is initialized with all its components set to 0, and a 'Success'
 *  status code. */
ray::ray () {
  p = Vec3::Zero();
  v = Vec3::Zero();
  code = 0;
}

/** Construct a \p ray with initial point component \p _p and orientation
 * component \p _v.
 * @param _p Initial point component of the ray.
 * @param _v Initial orientation component of the ray.
 * The status \p code is initialized to 0. */
ray::ray (Vec3 _p, Vec3 _v) {
  p = _p; v = _v;
  code = 0;
}

/** Status code shorthand for checking ray validity. */
bool ray::is_valid () {
  return (code == 0);
}

std::ostream& operator<< (std::ostream &out, const ray &r) {
  out << "ray(p: " << r.p << ", v: " << r.v << ", code: " << r.code << ")";
  return out;
}
