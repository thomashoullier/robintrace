#ifndef SPHERE_H
#define SPHERE_H

#include "shape/shape.h"

#include <iostream>

class sphere: public shape {
  public:
    double R; // Radius of curvature
    sphere (double _R);

    void intersect (ray &r);
    Vec3 normal (ray &r);
};

std::ostream& operator<< (std::ostream &out, sphere const& s);

#endif //SPHERE_H
