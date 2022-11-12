#include "reflect_ref.h"

Vec3 reflect_ref (const ray &r, const Vec3 &N) {
  // Reference implementation of the reflect operation.
  Eigen::Vector3d NVec(N.l, N.m, N.n);
  Eigen::Vector3d inc_ray(r.v.l, r.v.m, r.v.n);
  Eigen::Vector3d out_ray = inc_ray -
                            2 * NVec * NVec.dot(inc_ray);
  return Vec3(out_ray(0), out_ray(1), out_ray(2));
}
