#ifndef SHAPE_H
#define SHAPE_H

#include "ray/ray.h"

class shape {
  public:
    virtual void intersect (ray &r) = 0;
};

#endif //SHAPE_H
