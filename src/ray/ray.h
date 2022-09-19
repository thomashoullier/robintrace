#ifndef RAY_H
#define RAY_H

#include "Point3.h"
#include "UVec3.h"

class ray {
  public:
    Point3 p;
    UVec3 v;
    
    ray();
};

ray::ray () {
  p = Point3();
  v = UVec3();
}

#endif // RAY_H
