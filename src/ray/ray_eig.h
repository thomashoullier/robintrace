#ifndef RAY_EIG_H
#define RAY_EIG_H

#include <iostream>
#include <Eigen/Dense>

class ray_eig {
  public:
    Eigen::Vector3d p;
    Eigen::Vector3d v;
    int code;

    ray_eig ();
    ray_eig (Eigen::Vector3d _p, Eigen::Vector3d _v);
};

std::ostream& operator<< (std::ostream &out, const ray_eig &r);

#endif // RAY_EIG_H
