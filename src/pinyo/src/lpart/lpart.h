/** @file */
#ifndef LPART_H
#define LPART_H

#include "bun/bun.h"
#include "memory"

/** @brief Virtual class for elementary optical parts which can be
 * applied to ray bundles. */
class lpart {
  public:
    /** @brief Apply the lpart's operations to the ray bundle \p b.
     * 
     * A part typically manages the error cases which occur at the individual
     * ray level. The default behaviour is to leave non-valid rays out of any
     * computations and continue with valid rays. */
    virtual void apply (bun &b) = 0;
    /** @brief Obtain a copy of the lpart. */
    virtual std::unique_ptr<lpart> clone () const = 0;
};

#endif // LPART_H
