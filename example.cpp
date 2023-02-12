#include <iostream>
#include "robintrace.h"

int main(){
  std::cout << "# Main #" << std::endl;

  std::cout << "## Poaky ##" << std::endl;
  ray r (Vec3(0.2, 0.3, 0.0), Vec3(0, 0, 1.0));
  std::cout << "ray is valid? " << r.is_valid() << std::endl;
  standard sd (1.0/20, -2);
  std::cout << sd << std::endl;
  std::cout << "ray before intersection: " << r << std::endl;
  sd.intersect(r);
  std::cout << "ray after intersection: " << r << std::endl;
  Vec3 N = sd.normal(r);
  std::cout << "normal vector: " << N << std::endl;

  transfer tfr;
  std::cout << tfr << std::endl;

  std::cout << "## Pinyo ##" << std::endl;
  // bun
  std::vector<ray> rays;
  ray r1(Vec3(0.2, 0.3 , 0), Vec3(0, 0, 1));
  ray r2(Vec3(0.21, 0.31, 0), Vec3(0, 0, 1));
  rays.push_back(r1); rays.push_back(r2);
  bun b (rays);
  std::cout << "Before transfer: " << b << std::endl;

  // transfer_part
  transfer_part trfp(transfer(Vec3(0.01, 0, 0)));
  trfp.apply(b);
  std::cout << "After transfer: " << b << std::endl;

  // Standard reflective part
  standard sd2 (1.0/20, -2);
  shape_reflect_part srp(sd2);
  srp.apply(b);
  std::cout << "After standard reflective part: " << b << std::endl;
}
