#include "shape/plane.h"

/* Print method */
std::ostream& operator<< (std::ostream &out, plane const& pl) {
  (void)(pl);
  out << "plane";
  return out;
}

/* Intersect */
void plane::intersect (ray &r) {
  (void)(r);
}

/* Normal */
UVec3 plane::normal (ray &r) {
  double sig_n = std::copysign(1.0, r.v.n);
  return UVec3(0, 0, - sig_n);
}
