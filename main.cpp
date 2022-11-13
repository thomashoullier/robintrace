#include <iostream>
#include <cmath>

#include "poaky.h"
#include <Eigen/Dense>
#include <cmath>

int main(){
  std::cout << "# Main #" << std::endl;

  // Incoming ray
  Eigen::Vector3d p(0.5, -0.32, 0);
  Eigen::Vector3d v(0.01, -0.005, 0);
  v(2) = std::sqrt(1 - v(0) * v(0) - v(1) * v(1));
  ray_eig r_new = ray_eig(p, v);
  std::cout << r_new << std::endl;

  // Normal vector
  Eigen::Vector3d N(0.001, -0.002, 0);
  N(2) = - std::sqrt(1 - N(0) * N(0) - N(1) * N(1));
  std::cout << "N: " << N(0) << ", " << N(1) << ", " << N(2) << std::endl;
  
  // Reflect
  reflect_eig(r_new, N);
  std::cout << "Ray after reflect: " << r_new << std::endl;
}
