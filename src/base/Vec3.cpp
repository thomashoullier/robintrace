#include "base/Vec3.h"

/*** Constructors ***/
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

Vec3::Vec3 (double _l, double _m, bool nsign) {
  // Construct and initialize a unit Vec3. The component n
  // is built automatically from l, m and its specified sign.
  // zsign is true for +1, false for -1.
  l = _l;
  m = _m;
  double n = std::sqrt(1 - l*l - m*m);
  n = (nsign) ? n : - n;
}

/*** Operations ***/
double dot (Vec3 v1, Vec3 v2) {
  // Dot product operation.
  double dot_product = v1.l * v2.l + v1.m * v2.m + v1.n * v2.n;
  return dot_product;
}

Vec3 operator* (const double scal, const Vec3 vec) {
  // Scalar-vector multiplication.
  Vec3 vecmul(scal * vec.l, scal * vec.m, scal * vec.n);
  return vecmul;
}

/*** Printers ***/
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
