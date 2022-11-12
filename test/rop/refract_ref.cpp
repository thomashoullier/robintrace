#include "refract_ref.h"

ray refract_ref (const ray &r, const Vec3 &N, double nr) {
  // refract operation reference implementation.
  ray r_ref(r);
  Eigen::Vector3d NVec(N.l, N.m, N.n);
  Eigen::Vector3d iVec(r.v.l, r.v.m, r.v.n);
  
  double Ndoti = NVec.dot(iVec);
  double in_sqrt = 1 - nr * nr * (1 - std::pow(Ndoti, 2));
  if (in_sqrt < 0) {
    r_ref.code = 3;
    return r_ref;
  }

  Eigen::Vector3d tVec = nr * iVec - (nr * Ndoti + std::sqrt(in_sqrt)) * NVec;
  r_ref.v.l = tVec(0);
  r_ref.v.m = tVec(1);
  r_ref.v.n = tVec(2);
  return r_ref;
}
