#include "Vec2.h"

/** The last component of the output Vec3 is set to zero. */
Vec3 Vec2_to_Vec3 (const Vec2 &v) {
  return Vec3(v(0), v(1), 0.0);
}

std::ostream& operator<< (std::ostream &out, const Vec2 &v) {
  out << "[" << v(0) << ", " << v(1) << "]";
  return out;
}

