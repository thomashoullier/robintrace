#include "reflect_ref.h"

Vec3 reflect_ref (const ray &r, const Vec3 &N) {
  // Reference implementation of the reflect operation.
  Vec3 out_ray = r.v - 2 * N * N.dot(r.v);
  return out_ray;
}
