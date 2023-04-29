/** @file */
#ifndef SHAPE_H
#define SHAPE_H

#include "ray/ray.h"
#include "base/Vec3.h"
#include <cmath>

/** @brief Virtual class for shapes */
class shape {
  public:
    /** @brief Operate the intersection of ray \p r with shape. */
    virtual void intersect (ray &r) = 0;
    /** @brief Compute the normal of shape at current ray \p r position. */
    virtual Vec3 normal (const ray &r) = 0;
};

#endif //SHAPE_H
