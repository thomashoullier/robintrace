#include <iostream>
#include "poaky.h"

int main(){
  std::cout << "# Main #" << std::endl;

  ray r (Vec3(0.2, 0.3, 0.0), Vec3(0, 0, 1.0));
  Mat3 m; m << 1, 0, 0, 0, std::sqrt(3)/2, 0.5, 0, -0.5, std::sqrt(3)/2;
  transfer trf (m.transpose(), Vec3(0.2, 0.4, -10));
  std::cout << trf << std::endl;
  std::cout << "Initial ray: " << r << std::endl;
  trf.apply(r);
  std::cout << "ray after transfer: " << r << std::endl;
}
