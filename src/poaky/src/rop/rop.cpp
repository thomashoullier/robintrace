#include "rop.h"

/** This applies a specular reflection to the orientation of ray \p r
 * incident to a mirror with local normal vector \p N.
 *  @param r The ray to apply the operation to. Modified in-place.
 *  @param N The normal vector of the reflective element.
 *
 *  This operation does not have error cases. */
void reflect (ray &r, const Vec3 &N) {
  r.v = r.v - N * 2 * N.dot(r.v);
}

/** This applies a refraction to the orientation of ray \p r incident to
 * a diopter with local normal vector \p N and relative index of refraction
 * \p nr.
 * @param r The ray to apply the operation to. Modified in-place.
 * @param N The normal vector of the diopter.
 * @param nr The relative index of refraction of the diopter, \f$n_r =
 * n_1/n_2\f$ with \f$n1\f$ and \f$n2\f$ the refractive indices of the incident
 * and exit media respectively.
 *
 * Possible error: TIR.*/
void refract (ray &r, const Vec3 &N, double nr) {
  double w = - nr * (N.dot(r.v));
  double c2m = (w - nr) * (w + nr);
  if (c2m < -1) {r.code = 3; return;} // TIR error
  r.v = nr * r.v + (w - std::sqrt(1 + c2m)) * N;
}
