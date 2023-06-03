/** @file */
#ifndef LSEQ_PART_RAYS_H
#define LSEQ_PART_RAYS_H

#include "lseq_part_result.h"
#include "../ray_pack.h"

class lseq_part_rays : public lseq_part_result {
  public:
    /** @brief Saved ray states. */
    ray_pack ray_buns;

    /** @brief Constructor. */
    lseq_part_rays (const ray_pack &ray_buns);
};

#endif // LSEQ_PART_RAYS_H

