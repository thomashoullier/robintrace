#include "shape/standard.h"

/** The default initialization is to a plane surface,
 * - \f$ c = 0 \f$
 * - \f$ k = 0 \f$ */
standard::standard () {
  c = 0;
  k = 0;
}

/** Initializes the standard shape to curvature \p _c and quadric constant \p
 * _k.
 * @param _c Initial curvature of the standard shape.
 * @param _k Initial quadric constant of the standard shape. */
standard::standard (double _c, double _k) {
  c = _c;
  k = _k;
}

/** Initialize a sphere of curvature \p _c.
 *
 * @param _c Initial sphere curvature. */
standard::standard (double _c) {
  c = _c;
  k = 0;
}

/* Printer */
std::string standard::print_str () const {
  std::stringstream ss;
  ss << "standard(c: " << c << ", k: " << k << ")";
  return ss.str();
}

/** Possible error case: no intersection found between ray and shape.
 *
 * The exact definition of the standard shape is implicitely specified by
 * this operation. */
void standard::intersect (ray &r) {
  double f = c * (r.p(0) * r.p(0) + r.p(1) * r.p(1));
  double g = r.v(2) - c * (r.v(0) * r.p(0) + r.v(1) * r.p(1));
  double h = g * g - c * f * (1 + k * r.v(2) * r.v(2));

  if (h <= 0) { // Error: no intersection
    r.code = 5;
    return;
  }

  double sig_n = std::copysign(1.0, r.v(2));
  double t = f / (g + sig_n * std::sqrt(h));
  
  r.p(0) = r.p(0) + t * r.v(0);
  r.p(1) = r.p(1) + t * r.v(1);
  r.p(2) = t * r.v(2);
}

/** It is assumed this operation is applied where the normal vector can be
 *  computed, for instance after a successful intersection. No error cases
 *  are signaled by the normal computation. */
Vec3 standard::normal (const ray &r) {
  double sig_n = std::copysign(1.0, r.v(2));
  double in_sqrt = 1 - 2 * c * k * r.p(2) + c * c * (k+1) * k * r.p(2) * r.p(2);
  double coef = sig_n / std::sqrt(in_sqrt);
  Vec3 N (r.p(0) * c, r.p(1) * c, r.p(2) * c * (k+1) - 1);
  N = N * coef;
  return N;
}
