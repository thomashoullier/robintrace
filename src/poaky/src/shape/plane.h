/** @file */
#ifndef PLANE_H
#define PLANE_H

#include "shape/shape.h"

#include <iostream>
#include <cmath>

/** @brief Plane shape specialization. */
class plane: public shape {
  public:
    /** @brief Operate the intersection of ray \p r with the plane */
    void intersect (ray &r);
    /** @brief Compute the plane normal. */
    Vec3 normal (const ray &r);

    std::string print_str () const;
};

#endif //PLANE_H
