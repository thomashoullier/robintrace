#include "rop.h"

void reflect (ray &r, const Vec3 &N) {
  /* Specular reflection operation */
  double Ndotv2 = 2 * (N.l * r.v.l + N.m * r.v.m + N.n * r.v.n);
  r.v.l = r.v.l - N.l * Ndotv2;
  r.v.m = r.v.m - N.m * Ndotv2;
  r.v.n = r.v.n - N.n * Ndotv2;
}

void refract (ray &r, const Vec3 &N, double nr) {
  /* Refraction operation. The ray r contains the incident ray direction.
     N is the surface normal.
     nr is n1/n2 with n1 and n2 the refractive indices of the incident and
     exit media respectively.*/
  double w = - nr * (N.l * r.v.l + N.m * r.v.m + N.n * r.v.n);
  double c2m = (w - nr) * (w + nr);
  if (c2m < -1) {r.code = 3; return;} // TIR error
  double ncoef = w - std::sqrt(1 + c2m);

  r.v.l = nr * r.v.l + ncoef * N.l;
  r.v.m = nr * r.v.m + ncoef * N.m;
  r.v.n = nr * r.v.n + ncoef * N.n;
}
