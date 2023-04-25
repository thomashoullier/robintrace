/** @file */
#ifndef RAY_H
#define RAY_H

#include "base/Vec3.h"
#include <iostream>

/** @brief Class for individual rays. */
class ray {
  public:
    /**@brief Point component.
     *
     * Holds the three components \f$(x,y,z)\f$ of the ray.*/
    Vec3 p; 

    /**@brief Orientation component.
     *
     * Holds the three components \f$(l,m,n)\f$ of the ray.*/
    Vec3 v;
    int code;
    
    ray ();
    ray (Vec3 _p, Vec3 _v);

    bool is_valid();
};

std::ostream& operator<< (std::ostream &out, const ray &r);

#endif // RAY_H
