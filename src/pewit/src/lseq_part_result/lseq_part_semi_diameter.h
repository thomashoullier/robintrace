/** @file */
#ifndef LSEQ_PART_SEMI_DIAMETER
#define LSEQ_PART_SEMI_DIAMETER

#include "lseq_part_result.h"

/** @brief Part semi-diameter from the ray states results. */
class lseq_part_semi_diameter : public lseq_part_result {
  public:
    /** @brief The semi-diameter value. */
    double value;
    /** @brief Semi-diameter validity flag.
     *
     * A valid semi-diameter is non-zero. */
    bool validity;

    /** @brief Constructor. */
    lseq_part_semi_diameter (double value);
};

#endif // LSEQ_PART_SEMI_DIAMETER
