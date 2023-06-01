/** @file */
#ifndef LSEQ_RAYS_H
#define LSEQ_RAYS_H

class lseq_rays : lseq_input {
  public:
    /** @brief Current ray states. */
    ray_pack ray_buns;
    /** @brief Last raytraced part. */
    int last_part;
};

#endif // LSEQ_RAYS_H


