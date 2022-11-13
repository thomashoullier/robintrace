#include "sphere_ref.h"

ray sphere_intersect_ref (const sphere &s, const ray &r) {
  // Sphere intersect reference implementation
  double R = s.R;
  ray r_ref(r);

  double b = 2 * (r.p(0) * r.v(0) + r.p(1) * r.v(1) - r.v(2) * R);
  double c = r.p(0) * r.p(0) + r.p(1) * r.p(1);
  double delta = b * b - 4 * c;

  if (delta <= 0) { // Error: no intersection.
    r_ref.code = 1;
    return r_ref;
  }

  double sigb = std::copysign(1.0, b);
  double tsol = (-b + sigb * std::sqrt(delta)) / 2.0;

  r_ref.p(2) = tsol * r_ref.v(2);
  if (std::abs(r_ref.p(2)) >= std::abs(R)) { // Error: Beyond first hemisphere.
    r_ref.code = 2;
    return r_ref;
  }

  r_ref.p(0) = r_ref.p(0) + tsol * r_ref.v(0);
  r_ref.p(1) = r_ref.p(1) + tsol * r_ref.v(1);
  return r_ref;
}

Vec3 sphere_normal_ref (const sphere &s, const ray &r) {
  // Sphere normal vector reference implementation
  Vec3 C(0, 0, s.R);
  Vec3 CI = r.p - C;
  // Flip the vector opposite to the incident ray in the z direction.
  if (r.v(2) * CI(2) > 0) {CI = - CI;}
  // Return the normalized vector.
  CI.normalize();
  return CI;
}
