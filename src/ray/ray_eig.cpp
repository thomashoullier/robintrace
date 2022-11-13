#include "ray_eig.h"

ray_eig::ray_eig () {
  p = Eigen::Vector3d(0.0, 0.0, 0.0);
  v = Eigen::Vector3d(0.0, 0.0, 1.0);
  code = 0;
}

ray_eig::ray_eig (Eigen::Vector3d _p, Eigen::Vector3d _v) {
  p = _p;
  v = _v;
  code = 0;
}

std::ostream& operator<< (std::ostream &out, const ray_eig &r) {
  out << "ray(" << r.p(0) << ", " << r.p(1) << ", " << r.p(2) << ", " <<
                   r.v(0) << ", " << r.v(1) << ", " << r.v(2) << ")";
  return out;
}
