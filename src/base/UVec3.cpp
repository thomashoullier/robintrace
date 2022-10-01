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

std::ostream& operator<< (std::ostream &out, UVec3 const& v) {
  // Printer method.
  out << "UVec3(" << v.l << ", " << v.m << ", " << v.n << ")";
  return out;
}
