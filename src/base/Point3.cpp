#include "base/Point3.h"

Point3::Point3 () {
  // Constructor.
  x = 0; y = 0; z = 0;
}

Point3::Point3 (double _x, double _y, double _z) {
  // Construct + initialize.
  x = _x; y = _y; z = _z;
}

std::ostream& operator<< (std::ostream &out, const Point3 &p) {
  // Printer method
  out << "Point3(" << p.x << ", " << p.y << ", " << p.z << ")";
  return out;
}
