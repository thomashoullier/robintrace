#include "refract_ref.h"

ray refract_ref (const ray &r, const Vec3 &N, double nr) {
  // refract operation reference implementation.
  ray r_ref(r);
  
  double Ndoti = N.dot(r.v);
  double in_sqrt = 1 - nr * nr * (1 - std::pow(Ndoti, 2));
  if (in_sqrt < 0) {
    r_ref.code = 3;
    return r_ref;
  }

  r_ref.v = nr * r.v - (nr * Ndoti + std::sqrt(in_sqrt)) * N;
  return r_ref;
}
