#include "ray/ray.h"

ray::ray () {
  // Constructor
  p = Point3();
  v = Vec3();
  code = 0;
}

ray::ray (Point3 _p, Vec3 _v) {
  // Construct + initialize
  p = _p; v = _v;
  code = 0;
}

std::ostream& operator<< (std::ostream &out, const ray &r) {
  // Printer method
  out << "ray(" << r.p << ", " << r.v << ", code: " << r.code << ")";
  return out;
}
