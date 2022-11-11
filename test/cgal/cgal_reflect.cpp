#include "cgal_reflect.h"

Vec3 cgal_reflect (const ray r, const Vec3 N) {
  /* Specular reflection reference function.
   * Both r.v and N must be unit vectors. */
  Vector_3f NVec(N.l, N.m, N.n);
  Vector_3f inc_ray(r.v.l, r.v.m, r.v.n);
  Vector_3f out_ray = inc_ray - 2 * NVec * (NVec * inc_ray);
  return Vec3(out_ray.x(), out_ray.y(), out_ray.z());
}
