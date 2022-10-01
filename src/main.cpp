#include <iostream>
#include "ray/ray.h"
#include "shape/plane.h"
#include "shape/sphere.h"
#include "base/Point3.h"
#include "base/UVec3.h"

int main(){
  ray ray1;
  ray1.p.x = 1;

  plane plane1;
  std::cout << plane1 << std::endl;
  
  sphere sphere1(4.5);
  std::cout << sphere1 << std::endl;

  plane1.intersect(ray1);

  Point3 p(1.0, 2.0, 3.0);
  Point3 p2(p);
  p.x = 5.0;
  std::cout << p2 << std::endl;

  UVec3 v(0.2, 0.1, 0.8);
  std::cout << v << std::endl;
  
  ray r(Point3(1, -1, 0), UVec3(0, -0.2, 0.9));
  std::cout << r << std::endl;

  std::cout << "Ray z: " << ray1.p.z << std::endl;
  std::cout << "Ray code: " << ray1.code << std::endl;

  sphere1.intersect(ray1);

  std::cout << "Ray z after sphere intersect: " << ray1.p.z << std::endl;
  std::cout << "Ray code: " << ray1.code << std::endl;

}
