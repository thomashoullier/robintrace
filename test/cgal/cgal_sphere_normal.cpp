#include "cgal_sphere_normal.h"

Vec3 cgal_sphere_normal (const sphere s, const ray r) {
  /*Compute the sphere normal at the intersection point indicated by r.*/
  Point_3f C(0, 0, s.R);
  Point_3f I(r.p.x, r.p.y, r.p.z);
  Vector_3f CI(C, I);
  // Flip the vector opposite to the incident ray in the z direction.
  if (r.v.n * CI.z() > 0) {CI = - CI;}
  // Return the normalized vector.
  CI = CI / std::sqrt(CI.squared_length());
  Vec3 N(CI.x(), CI.y(), CI.z());
  return N;
}
