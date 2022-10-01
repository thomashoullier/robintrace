#ifndef RAY_H
#define RAY_H

#include "Point3.h"
#include "UVec3.h"

class ray {
  public:
    Point3 p;
    UVec3 v;
    int code;
    
    ray();
};

#endif // RAY_H
