/** @file */
#ifndef LSEQ_PART_PROPAGATION_DIRECTION_H
#define LSEQ_PART_PROPAGATION_DIRECTION_H

#include "lseq_part_result.h"

/** @brief Propagation direction of the lseq_part_rays. */
class lseq_part_propagation_direction : public lseq_part_result {
  public:
    /** @brief The propagation direction of the rays.
     *
     * True for positive along the z axis (n component of the ray). */
    bool direction;
    /** @brief Propagation direction validity flag.
     *
     * The propagation direction is valid if all the rays propagate in the same
     * direction. Note this excludes hyperhemispherical surfaces for the time
     * being. */
    bool validity;

    /** @brief Constructor. */
    lseq_part_propagation_direction (bool direction, bool validity);
};

#endif // LSEQ_PART_PROPAGATION_DIRECTION_H
