#include "rop.h"

void reflect (ray &r, const Vec3 &N) {
  /* Specular reflection operation */
  r.v = r.v - N * 2 * N.dot(r.v);
}

void refract (ray &r, const Vec3 &N, double nr) {
  /* Refraction operation. The ray r contains the incident ray direction.
     N is the surface normal.
     nr is n1/n2 with n1 and n2 the refractive indices of the incident and
     exit media respectively.*/
  
  double w = - nr * (N.dot(r.v));
  double c2m = (w - nr) * (w + nr);
  if (c2m < -1) {r.code = 3; return;} // TIR error

  r.v = nr * r.v + (w - std::sqrt(1 + c2m)) * N;
}
