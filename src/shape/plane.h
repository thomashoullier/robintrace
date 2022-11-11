#ifndef PLANE_H
#define PLANE_H

#include "shape/shape.h"

#include <iostream>
#include <cmath>

class plane: public shape {
  public:
    void intersect (ray &r);
    Vec3 normal (ray &r);
};

std::ostream& operator<< (std::ostream &out, plane const& pl);

#endif //PLANE_H
