#include "shape/sphere.h"
#include <cmath>

/* Constructor */
sphere::sphere (double _R) {
  R = _R;
}

/* Print method */
std::ostream& operator<< (std::ostream &out, sphere const& s) {
  out << "sphere(R = " << s.R << ")";
  return out;
}

/* intersect */
void sphere::intersect (ray &r) {
  double b = 2 * (r.p.x * r.v.l + r.p.y * r.v.m - r.v.n * R);
  double c = r.p.x * r.p.x + r.p.y * r.p.y;
  double delta = b * b - 4 * c;
  
  if (delta <= 0) { // Error: no intersection.
    r.code = 1;
    return;
  }

  double sigb = std::copysign(1.0, b);
  double tsol = (-b + sigb * std::sqrt(delta)) / 2.0;

  r.p.z = tsol * r.v.n;
  if (std::abs(r.p.z) >= std::abs(R)) { // Error: Beyond first hemisphere.
    r.code = 2;
    return;
  }

  r.p.x = r.p.x + tsol * r.v.l;
  r.p.y = r.p.y + tsol * r.v.m;
}

