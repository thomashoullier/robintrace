#include "sphere_ref.h"

ray sphere_intersect_ref (const sphere &s, const ray &r) {
  // Sphere intersect reference implementation
  double R = s.R;
  double b = 2 * (r.p.x * r.v.l + r.p.y * r.v.m - r.v.n * R);
  double c = r.p.x * r.p.x + r.p.y * r.p.y;
  double delta = b * b - 4 * c;

  ray r_ref(r);

  if (delta <= 0) { // Error: no intersection.
    r_ref.code = 1;
    return r_ref;
  }

  double sigb = std::copysign(1.0, b);
  double tsol = (-b + sigb * std::sqrt(delta)) / 2.0;

  r_ref.p.z = tsol * r_ref.v.n;
  if (std::abs(r_ref.p.z) >= std::abs(R)) { // Error: Beyond first hemisphere.
    r_ref.code = 2;
    return r_ref;
  }

  r_ref.p.x = r_ref.p.x + tsol * r_ref.v.l;
  r_ref.p.y = r_ref.p.y + tsol * r_ref.v.m;
  return r_ref;
}
