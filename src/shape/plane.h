#ifndef PLANE_H
#define PLANE_H

#include "shape.h"

class plane: public shape {
  public:
    void intersect (ray &r) {(void)(r);}; // Do nothing.
};

#endif //PLANE_H
