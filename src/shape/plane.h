#ifndef PLANE_H
#define PLANE_H

#include "shape.h"

class plane: public shape {
  public:
    void intersect (ray &r);
};

#endif //PLANE_H
