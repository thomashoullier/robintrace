/** @file */
#ifndef LSEQ_PART_H
#define LSEQ_PART_H

#include <memory>
#include "ray_pack.h"
#include "pinyo.h"

#include "type_map/type_map.h"

#include "lseq_part_result/lseq_part_rays.h"
#include "lseq_part_result/lseq_part_global_position.h"

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
};

#endif // LSEQ_PART_H

