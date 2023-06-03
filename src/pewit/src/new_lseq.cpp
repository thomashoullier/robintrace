#include "new_lseq.h"

new_lseq::new_lseq (const lpart_vec &parts) {
  for (const auto &part : parts.v) {
    this->parts.push_back(lseq_part(*part));
  }
}

void new_lseq::trace_next () {
  auto rays = this->get_input<lseq_rays>();
  if (rays.last_part + 1 >= int(parts.size())) {
    throw std::length_error("lseq::trace_next: No more parts to raytrace.");
  }
  parts.at(rays.last_part + 1).trace(rays.ray_buns);
  rays.last_part++;
}
