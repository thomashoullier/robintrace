#include "lseq_part.h"

void lseq_part::trace (ray_pack &ray_buns) {
  for (auto &b : ray_buns) {
    part->apply(b);
  }
  if (save_rays) {
    lseq_part_rays ray_state(ray_buns);
    results.add(ray_state);
  }
}

void lseq_part::compute_semi_diameter () {
  double semi_diameter_value = 0;
  const auto &ray_states = results.get<lseq_part_rays>();
  for (const auto &bundle : ray_states.ray_buns) {
    for (const auto &r : bundle.rays) {
      if (r.is_valid()) {
        double radial_position = std::sqrt(r.p(0)*r.p(0) + r.p(1)*r.p(1));
        semi_diameter_value = std::max(semi_diameter_value, radial_position);
      }
    }
  }
  lseq_part_semi_diameter sd (semi_diameter_value);
  results.add(sd);
}
