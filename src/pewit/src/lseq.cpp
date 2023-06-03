#include "lseq.h"

lseq::lseq (const lpart_vec &parts) {
  for (const auto &part : parts.v) {
    this->parts.push_back(lseq_part(*part));
  }
}

void lseq::trace_next () {
  lseq_rays &rays = inputs.get<lseq_rays>();
  if (rays.last_part + 1 >= int(parts.size())) {
    throw std::length_error("lseq::trace_next: No more parts to raytrace.");
  }
  parts.at(rays.last_part + 1).trace(rays.ray_buns);
  rays.last_part++;
}

void lseq::trace_remaining () {
  lseq_rays &rays = inputs.get<lseq_rays>();
  while (rays.last_part + 1 < int(parts.size())) {
    trace_next();
  }
}
