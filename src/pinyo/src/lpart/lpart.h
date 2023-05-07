/** @file */
#ifndef LPART_H
#define LPART_H

#include "bun/bun.h"
#include "memory"
#include <string>
#include <sstream>

/** @brief Virtual class for elementary optical parts which can be
 * applied to ray bundles. */
class lpart {
  public:
    /** @brief Obtain a copy of the lpart. */
    virtual std::unique_ptr<lpart> clone () const = 0;
    /** @brief Apply the lpart's operations to the ray bundle \p b.
     * 
     * A part typically manages the error cases which occur at the individual
     * ray level. The default behaviour is to leave non-valid rays out of any
     * computations and continue with valid rays. */
    virtual void apply (bun &b) = 0;

  private:
    /** @brief String for printing the object. */
    virtual std::string print_str () const = 0;

  /** @brief Printer */
  friend std::ostream& operator<< (std::ostream &out, const lpart &lp) {
    out << lp.print_str();
    return out;
  };
};

#endif // LPART_H
