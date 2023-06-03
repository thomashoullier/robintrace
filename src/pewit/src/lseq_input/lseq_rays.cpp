#include "lseq_rays.h"

lseq_rays::lseq_rays (const ray_pack &ray_buns) {
  last_part = -1;
  this->ray_buns = ray_buns;
}
