#include "shape/sphere.h"

/* Constructor */
sphere::sphere (double _R) {
  R = _R;
}

/* Print method */
std::ostream& operator<< (std::ostream &out, const sphere &s) {
  out << "sphere(R = " << s.R << ")";
  return out;
}

/* intersect */
void sphere::intersect (ray &r) {
  double b = 2 * (r.p(0) * r.v(0) + r.p(1) * r.v(1) - r.v(2) * R);
  double c = r.p(0) * r.p(0) + r.p(1) * r.p(1);
  double delta = b * b - 4 * c;
  
  if (delta <= 0) { // Error: no intersection.
    r.code = 1;
    return;
  }

  double sigb = std::copysign(1.0, b);
  double tsol = (-b + sigb * std::sqrt(delta)) / 2.0;

  r.p(2) = tsol * r.v(2);
  if (std::abs(r.p(2)) >= std::abs(R)) { // Error: Beyond first hemisphere.
    r.code = 2;
    return;
  }

  r.p(0) = r.p(0) + tsol * r.v(0);
  r.p(1) = r.p(1) + tsol * r.v(1);
}

/* normal */
Vec3 sphere::normal (ray &r) {
  double Rn = std::copysign(R, r.v(2));
  double nl = r.p(0) / Rn;
  double nm = r.p(1) / Rn;
  double nn = (r.p(2) - R) / Rn;
  return Vec3(nl, nm, nn);
}
