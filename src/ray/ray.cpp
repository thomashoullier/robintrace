#include "ray/ray.h"

ray::ray () {
  // Constructor
  p = Vec3::Zero();
  v = Vec3::Zero();
  code = 0;
}

ray::ray (Vec3 _p, Vec3 _v) {
  // Construct + initialize
  p = _p; v = _v;
  code = 0;
}

bool ray::is_valid () {
  // Check whether the ray is valid. (error code = 0)
  return (code == 0);
}

std::ostream& operator<< (std::ostream &out, const ray &r) {
  // Printer method
  out << "ray([" << r.p(0) << ", " << r.p(1) << ", " << r.p(2) << "]"
          << "[" << r.v(0) << ", " << r.v(1) << ", " << r.v(2) << "]"
          << ", code: " << r.code << ")";
  return out;
}
