#include "base/UVec3.h"

UVec3::UVec3 () {
  // Constructor
  l = 0;
  m = 0;
  n = 1;
}

UVec3::UVec3 (double _l, double _m, double _n) {
  // Construct + initialize
  l = _l; m = _m; n = _n;
}

UVec3 UVec3_lm (double _l, double _m, bool nsign) {
  // Construct and initialize a UVec3. The component n
  // is built automatically from l, m and its specified sign.
  // zsign is true for +1, false for -1.
  double n = std::sqrt(1 - _l*_l - _m*_m);
  n = (nsign) ? n : - n;
  return UVec3(_l, _m, n);
}

std::ostream& operator<< (std::ostream &out, UVec3 const& v) {
  // Printer method.
  out << "UVec3(" << v.l << ", " << v.m << ", " << v.n << ")";
  return out;
}
