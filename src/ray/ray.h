#ifndef RAY_H
#define RAY_H

#include "base/Vec3.h"
#include <iostream>

class ray {
  public:
    Vec3 p;
    Vec3 v;
    int code;
    
    ray ();
    ray (Vec3 _p, Vec3 _v);
};

std::ostream& operator<< (std::ostream &out, const ray &r);

#endif // RAY_H
