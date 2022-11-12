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

Vec3 sphere_normal_ref (const sphere &s, const ray &r) {
  // Sphere normal vector reference implementation
  Eigen::Vector3d C(0, 0, s.R);
  Eigen::Vector3d I(r.p.x, r.p.y, r.p.z);
  Eigen::Vector3d CI = I - C;
  // Flip the vector opposite to the incident ray in the z direction.
  if (r.v.n * CI(2) > 0) {CI = - CI;}
  // Return the normalized vector.
  CI.normalize();
  Vec3 N(CI(0), CI(1), CI(2));
  return N;
}
