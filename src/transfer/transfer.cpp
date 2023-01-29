#include "transfer.h"

/* Constructors */
transfer::transfer () {
  Bt = Mat3::Identity();
  D = Vec3::Zero();
}

transfer::transfer (Vec3 _D) {
// Identity rotation implied.
  Bt = Mat3::Identity();
  D = _D;
}

transfer::transfer (Mat3 _Bt, Vec3 _D) {
  Bt = _Bt;
  D = _D;
}

/* Printer */
std::ostream& operator<< (std::ostream &out, const transfer &trf) {
  out << "transfer(\nBt =\n" << trf.Bt << "\nD =\n" << trf.D << ")";
  return out;
}

/* transfer operation */
void transfer::apply (ray &r) {
  r.v = Bt * r.v;

  if (r.v[2] == 0) {
    r.code = 4;
    return;}

  r.p = Bt * r.p - D;
  double t_inter = - r.p[2] / r.v[2];
  r.p[0] = r.p[0] + t_inter * r.v[0];
  r.p[1] = r.p[1] + t_inter * r.v[1];
  r.p[2] = 0;
}
