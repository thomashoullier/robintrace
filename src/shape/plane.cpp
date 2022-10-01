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
