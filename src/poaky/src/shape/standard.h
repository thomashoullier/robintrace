/** @file */
#ifndef STANDARD_H
#define STANDARD_H

#include "shape/shape.h"
#include <iostream>

/** @brief Standard shape specialization. */
class standard: public shape {
  public:
    /** @brief Curvature.
     *
     * This is the reciprocal of the radius of curvature \f$R\f$.
     * \f[ c = \frac{1}{R} \f]
     * The case \f$ c = 0 \f$ describes a plane. */
    double c;
    /** @brief Quadric constant.
     *
     * The type of quadric is specified by \p k. The cases are the following,
     * - \f$ k < -1 \f$ Single sheet from a hyperboloid of revolution of two
     *   sheets.
     * - \f$ k = -1 \f$ Circular paraboloid.
     * - \f$ k > -1 \f$ Spheroid, with the case \f$ k=0 \f$ being a sphere. */
    double k; // Quadric constant

    /** @brief Default constructor */
    standard ();
    /** @brief Initialization constructor */
    standard (double _c, double _k);

    /** @brief Operate the intersection of ray \p r with standard shape. */
    virtual void intersect (ray &r);
    /** @brief Compute the normal of the standard shape at the current ray
      * \p r position. */
    virtual Vec3 normal (const ray &r);

  private:
    /** @brief Printer. */
    virtual std::string print_str () const;
};


#endif // STANDARD_H
