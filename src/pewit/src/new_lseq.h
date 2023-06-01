/** @file */

#ifndef NEW_LSEQ_H
#define NEW_LSEQ_H

#include <vector>
#include <memory>
#include <typeindex>
#include <unordered_map>

#include "pinyo.h"
#include "lseq_part.h"
#include "lseq_input/lseq_input.h"
#include "lpart_vec.h"

class new_lseq {
  public:
    /** @brief Vector of the system's lseq_part. */
    std::vector<lseq_part> parts;

    std::unordered_map<std::type_index, std::unique_ptr<lseq_input>> inputs;

    /** @brief Default constructor. */
    new_lseq();
    /** @brief Initialization constructor. */
    new_lseq (const lpart_vec &parts);

    // TODO:
    // * Create classes for lseq_input, lseq_output for the properties used as
    // input or output in the lseq globally. The same exists for individual
    // parts.
    // For the inputs, every possible input should have a type inheriting
    // lseq_input. It is stored in the input hash-table by a method in lseq.
    // The hash-table is keyed by input type (use type_index?).
    // We can query the results by using a template `const T& get_output()`
    // which asks for a specific return type T.
    

    // Let's use the new architecture to match the old features.
    // Inputs:
    // * Rays to raytrace, initialized at the beginning of the system.
    //   It should be modified in-place by the raytracing and have
    //   an associated last raytraced part.
    // Part-wise inputs:
    // * Whether to save or not the rays being traced on the part.
    // Part-wise outputs:
    // * Saved raystates.
    //void add_input (std::unique_ptr<lseq_input> &input);

    // Operations on lseq_rays
    //void apply_next ();
};

#endif // NEW_LSEQ_H
