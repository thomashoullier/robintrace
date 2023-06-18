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

void lseq::compute_parts_global_position () {
  // Initialize the global coordinates apex and rotation matrix.
  Vec3 cur_apex = Vec3(0, 0, 0);
  Mat3 cur_mat = Mat3::Identity();
  // Iterate through the parts, accumulating transfers and storing positions in
  // renderable parts.
  std::vector<lseq_part>::size_type renderable_index = 0;
  for (auto &part : parts) {
    if (part.part->is_renderable()) {
      lseq_part_global_position cur_pos(cur_apex, cur_mat);
      part.results.add(cur_pos);
    }
    else if (part.part->is_transfer()) {
      // TODO: The cast is unfortunate, find a better abstraction.
      auto *trf_part = dynamic_cast<transfer_part*>(part.part.get());
      cur_mat = trf_part->trf.Bt.transpose() * cur_mat;
      cur_apex = cur_apex + cur_mat * trf_part->trf.D;
    }
  }
}
