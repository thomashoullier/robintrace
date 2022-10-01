#ifndef RAY_H
#define RAY_H

#include "base/Point3.h"
#include "base/UVec3.h"

#include <iostream>

class ray {
  public:
    Point3 p;
    UVec3 v;
    int code;
    
    ray ();
    ray (Point3 _p, UVec3 _v);
};

std::ostream& operator<< (std::ostream &out, ray const& r);

#endif // RAY_H
