/** @file */
#ifndef LSEQ_PART_H
#define LSEQ_PART_H

#include <memory>
#include "ray_pack.h"
#include "pinyo.h"

#include "type_map/type_map.h"

#include "lseq_part_result/lseq_part_rays.h"
#include "lseq_part_result/lseq_part_global_position.h"
#include "lseq_part_result/lseq_part_semi_diameter.h"
#include "lseq_part_result/lseq_part_global_rays.h"
#include "lseq_part_result/lseq_part_propagation_direction.h"

/** @brief A part in a lseq. It contains both data and methods relative to a
 * single part. */
class lseq_part {
  public:
    /** @brief A copy of the underlying lpart. */
    std::unique_ptr<lpart> part;
    /** @brief Results table. */
    type_map<lseq_part_result> results;

    /** @brief Whether to save ray states when tracing. */
    bool save_rays;

    /** @brief Constructor. */
    template <typename T>
    lseq_part (const T &part) {
      static_assert(std::is_base_of<lpart, T>::value,
                    "T must be derived from lpart.");
      this->part = part.clone();
      save_rays = false;
    }

    /** @brief Apply raytracing of the part to a ray_pack.
     *   
     *  Also save the ray states if the option is enabled. */
    void trace (ray_pack &ray_buns);
    /** @brief Compute the part semi-diameter from the saved ray states. */
    void compute_semi_diameter ();
    /** @brief Convert a ray_pack in the part's LCS to a ray_pack in global
     * coordinates. */
    ray_pack rays_to_global (const ray_pack &local_rays);
    /** @brief Convert the lseq_part_rays to lseq_part_global_rays.
     *  
     *  Requires lseq_part_global_position being present. */
    void compute_global_rays ();
    /** @brief Compute the lseq_part_propagation_direction. */
    void compute_propagation_direction ();
};

#endif // LSEQ_PART_H

