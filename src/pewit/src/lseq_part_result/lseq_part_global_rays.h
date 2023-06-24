/** @file */
#ifndef LSEQ_PART_GLOBAL_RAYS_H
#define LSEQ_PART_GLOBAL_RAYS_H

#include "lseq_part_result.h"
#include "../ray_pack.h"

class lseq_part_global_rays : public lseq_part_result {
  public:
    ray_pack ray_buns;

    lseq_part_global_rays (const ray_pack &ray_buns);
};

#endif // LSEQ_PART_GLOBAL_RAYS_H
