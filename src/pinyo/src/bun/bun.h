/** @file */
#ifndef BUN_H
#define BUN_H

#include "poaky.h"
#include <vector>
#include <unordered_set>

/** @brief Class for ray bundles.
 *
 * The bun class is a very thin abstraction around a vector of rays.
 * It is used in order to define operations over groups of rays. */
class bun {
  public:
    /** @brief Vector of rays. */
    std::vector<ray> rays;

    /** @brief Default constructor. */
    bun();
    /** @brief Initialization constructor. */
    bun(const std::vector<ray> _rays);

    /** @brief Printer. */
    friend std::ostream& operator<< (std::ostream &out, const bun &b);
};


#endif // BUN_H
