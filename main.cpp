#include <iostream>
#include "poaky.h"

int main(){
  std::cout << "# Main #" << std::endl;

  ray r (Vec3(0.2, 0.3, 0.0), Vec3(0, 0, 1.0));
  Mat3 m (Eigen::AngleAxisd(0.01, Vec3(0,1,0)));
  transfer trf (m.transpose(), Vec3(0.2, 0.4, -10));
  std::cout << trf << std::endl;
  std::cout << "Initial ray: " << r << std::endl;
  trf.apply(r);
  std::cout << "ray after transfer: " << r << std::endl;
}
