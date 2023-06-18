/** @file */
#ifndef LSEQ_H
#define LSEQ_H

#include <vector>

#include "pinyo.h"
#include "lseq_part.h"
#include "lseq_input/lseq_input.h"
#include "lpart_vec.h"
#include "lseq_input/lseq_rays.h"
#include "type_map/type_map.h"

/** @brief Top-level API for robintrace. Holds parts, rays and manages the
 *  computations. */
class lseq {
  public:
    /** @brief Vector of the system's lseq_part. */
    std::vector<lseq_part> parts;
    /** @brief Table of inputs for computations in lseq. */
    type_map<lseq_input> inputs;

    /** @brief Default constructor. */
    lseq();
    /** @brief Initialization constructor. */
    lseq (const lpart_vec &parts);

    /** @brief Trace the lseq_rays through the next part. */
    void trace_next ();
    /** @brief Trace the lseq_rays through the remaining parts. */
    void trace_remaining ();
    /** @brief Compute the global position (apex and rotation) of all parts. */
    void compute_parts_global_position ();
};

#endif // LSEQ_H
