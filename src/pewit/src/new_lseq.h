/** @file */
#ifndef NEW_LSEQ_H
#define NEW_LSEQ_H

#include <vector>

#include "pinyo.h"
#include "lseq_part.h"
#include "lseq_input/lseq_input.h"
#include "lpart_vec.h"
#include "lseq_input/lseq_rays.h"
#include "type_map/type_map.h"

class new_lseq {
  public:
    /** @brief Vector of the system's lseq_part. */
    std::vector<lseq_part> parts;
    type_map<lseq_input> inputs;

    /** @brief Default constructor. */
    new_lseq();
    /** @brief Initialization constructor. */
    new_lseq (const lpart_vec &parts);

    /** @brief Trace the lseq_rays through the next part. */
    void trace_next ();
    /** @brief Trace the lseq_rays through the remaining parts. */
    void trace_remaining ();
};

#endif // NEW_LSEQ_H
