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

    /**@brief Status code.
     *
     * Status code for signaling error cases in raytracing operations.
     * The status codes are tabulated hereafter.
     * @todo Link to the functions in the error code description.
     *
     * Code | Meaning
       ---- | -------------
       0    | Success
       3    | refract: TIR
       4    | transfer: ray is parallel to the new local plane.
       5    | standard intersection: No intersection.
     * A status code of 0 means the ray is holding valid values.*/
    int code;
    
    /** @brief Default constructor. */
    ray ();
    ray (Vec3 _p, Vec3 _v);

    bool is_valid();
};

std::ostream& operator<< (std::ostream &out, const ray &r);

#endif // RAY_H
