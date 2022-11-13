#include <iostream>
#include "poaky.h"

int main(){
  std::cout << "# Main #" << std::endl;
  ray r = ray();
  std::cout << r << std::endl;
  ray r2 = ray(Vec3(1, 2, 3), Vec3_lm(0.01, -0.002, true));
  std::cout << r2 << std::endl;
  bool reqr2 = (r.v == r2.v);
  std::cout << reqr2 << (r.v == r.v) << std::endl;
}
