#include "shape/standard.h"

/* Constructor */
standard::standard (double _c, double _k) {
  c = _c;
  k = _k;
}

/* Printer */
std::ostream& operator<< (std::ostream &out, const standard &sd) {
  out << "standard(c = " << sd.c << ", k = " << sd.k << ")";
  return out;
}

/* intersect */
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

/* normal */
Vec3 standard::normal (const ray &r) {
  double sig_n = std::copysign(1.0, r.v(2));
  double in_sqrt = 1 - 2 * c * k * r.p(2) + c * c * (k+1) * k * r.p(2) * r.p(2);
  double coef = sig_n / std::sqrt(in_sqrt);
  Vec3 N (r.p(0) * c, r.p(1) * c, r.p(2) * c * (k+1) - 1);
  N = N * coef;
  return N;
}
