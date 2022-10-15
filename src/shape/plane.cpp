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
UVec3 plane::normal (double xq, double yq) {
  (void)(xq); (void)(yq);
  return UVec3(0, 0, 1);
}
