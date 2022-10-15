#ifndef SHAPE_H
#define SHAPE_H

#include "ray/ray.h"
#include "base/UVec3.h"

class shape {
  public:
    virtual void intersect (ray &r) = 0;
    virtual UVec3 normal (double xq, double yq) = 0;
};

#endif //SHAPE_H
