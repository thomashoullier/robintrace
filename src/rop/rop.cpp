#include "rop.h"

void reflect (ray &r, const Vec3 N) {
  /* Specular reflection operation */
  double Ndotv2 = 2 * (N.l * r.v.l + N.m * r.v.m + N.n * r.v.n);
  r.v.l = r.v.l - N.l * Ndotv2;
  r.v.m = r.v.m - N.m * Ndotv2;
  r.v.n = r.v.n - N.n * Ndotv2;
}
