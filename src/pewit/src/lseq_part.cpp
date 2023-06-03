#include "lseq_part.h"

void lseq_part::trace (ray_pack &ray_buns) {
  for (auto &b : ray_buns) {
    part->apply(b);
  }
}
