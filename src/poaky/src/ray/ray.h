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
     * Holds the three components \f$(x,y,z)\f$ of the ray.
     * It describes where the ray is resting in the current LCS.*/
    Vec3 p; 

    /**@brief Orientation component.
     *
     * Holds the three components \f$(l,m,n)\f$ of the ray.
     * It orients the ray from its point component in the light propagation
     * direction. The light propagates along the positive \p v direction.*/
    Vec3 v;

    /**@brief Status code.
     *
     * Status code for signaling error cases in raytracing operations.
     * The status codes are tabulated hereafter.
     *
     * Code | Meaning
       ---- | -------------
       0    | Valid
       3    | refract(): TIR
       4    | transfer.apply(): ray is parallel to the new local plane.
       5    | standard::intersect(): No intersection.
     * A status code of 0 means the ray is holding valid values.*/
    int code;
    
    /** @brief Default constructor. */
    ray ();
    /** @brief Initialization constructor. */
    ray (Vec3 _p, Vec3 _v);
    /** @brief Check whether the ray holds valid data. */
    bool is_valid() const;
    /** @brief Printer. */
    friend std::ostream& operator<< (std::ostream &out, const ray &r);
};

#endif // RAY_H
