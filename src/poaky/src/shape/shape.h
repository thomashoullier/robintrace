/** @file */
#ifndef SHAPE_H
#define SHAPE_H

#include "ray/ray.h"
#include "base/Vec3.h"
#include <cmath>
#include <string>
#include <sstream>

/** @brief Virtual class for shapes */
class shape {
  public:
    /** @brief Operate the intersection of ray \p r with shape. */
    virtual void intersect (ray &r) = 0;
    /** @brief Compute the normal of shape at current ray \p r position. */
    virtual Vec3 normal (const ray &r) = 0;
    /** @brief String for printing the object */
    virtual std::string print_str () const = 0;

    friend std::ostream& operator<< (std::ostream &out, const shape &shp) {
      out << shp.print_str();
      return out;
    };
};

#endif //SHAPE_H
