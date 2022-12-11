#ifndef STANDARD_H
#define STANDARD_H

#include "shape/shape.h"
#include <iostream>

class standard: public shape {
  public:
    double c; // Curvature
    double k; // Quadric constant

    standard (double _c, double _k);

    void intersect (ray &r);
    Vec3 normal (ray &r);
};

std::ostream& operator<< (std::ostream &out, const standard &sd);

#endif // STANDARD_H
