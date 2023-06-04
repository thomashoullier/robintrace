/** @file */
#ifndef LSEQ_RAYS_H
#define LSEQ_RAYS_H

#include "lseq_input.h"
#include "../ray_pack.h"

/** @brief Input rays to lseq. */
class lseq_rays : public lseq_input {
  public:
    /** @brief Current ray states. */
    ray_pack ray_buns;
    /** @brief Last raytraced part. */
    int last_part;

    /** @brief Constructor. */
    lseq_rays (const ray_pack &ray_buns);
};

#endif // LSEQ_RAYS_H


