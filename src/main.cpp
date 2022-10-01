#include <iostream>
#include "ray.h"
#include "plane.h"
#include "sphere.h"

int main(){
  ray ray1;
  plane plane1;
  sphere sphere1(4.5);

  plane1.intersect(ray1);

  ray1.p.x = 1;

  std::cout << "Ray z: " << ray1.p.z << std::endl;
  std::cout << "Ray code: " << ray1.code << std::endl;

  sphere1.intersect(ray1);

  std::cout << "Ray z after sphere intersect: " << ray1.p.z << std::endl;
  std::cout << "Ray code: " << ray1.code << std::endl;

}
