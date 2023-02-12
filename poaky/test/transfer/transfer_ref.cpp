#include "transfer_ref.h"

ray transfer_ref (const ray &r, const transfer &trf) {
  // transfer operation reference implementation.
  ray r_valid;
  r_valid.v = trf.Bt * r.v;
  r_valid.p = trf.Bt * r.p - trf.D;
  if (r_valid.v[2] == 0) {
    r_valid.code = 4;
    return r_valid;
  }
  double t = - r_valid.p[2] / r_valid.v[2];
  r_valid.p = r_valid.p + t * r_valid.v;
  r_valid.p[2] = 0;
  return r_valid;
}
