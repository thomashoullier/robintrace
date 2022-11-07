#include "base/Vec3.h"

Vec3::Vec3 () {
  // Constructor
  l = 0;
  m = 0;
  n = 1;
}

Vec3::Vec3 (double _l, double _m, double _n) {
  // Construct + initialize
  l = _l; m = _m; n = _n;
}

double dot (Vec3 v1, Vec3 v2) {
  // Dot product operation.
  double dot_product = v1.l * v2.l + v1.m * v2.m + v1.n * v2.n;
  return dot_product;
}

std::string coords_as_str (const Vec3 v) {
  // Return the vector coordinates as a printable string.
  std::string coords_str =
    "(" + std::to_string(v.l) + ", " + std::to_string(v.m) + ", "
        + std::to_string(v.n) + ")";
  return coords_str;
}

std::ostream& operator<< (std::ostream &out, Vec3 const& v) {
  // Printer method.
  out << "Vec3" << coords_as_str(v);
  return out;
}
