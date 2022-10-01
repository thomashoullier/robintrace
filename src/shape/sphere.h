#ifndef SPHERE_H
#define SPHERE_H

#include "shape.h"

class sphere: public shape {
  public:
    double R; // Radius of curvature
    sphere(double);

    void intersect (ray &r);
};

#endif //SPHERE_H
