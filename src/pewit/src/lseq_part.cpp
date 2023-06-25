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

void lseq_part::compute_global_rays () {
  const auto &local_rays = results.get<lseq_part_rays>();
  const auto &global_position = results.get<lseq_part_global_position>();
  ray_pack global_rays;
  bun cur_bundle;
  for (const auto &bundle : local_rays.ray_buns) {
    cur_bundle.rays.clear();
    for (const auto &r : bundle.rays) {
      Vec3 global_ray_p = global_position.pose.rotation * r.p
                          + global_position.pose.apex;
      Vec3 global_ray_v = global_position.pose.rotation * r.v;
      cur_bundle.rays.push_back(ray(global_ray_p, global_ray_v));
    }
    global_rays.push_back(cur_bundle);
  }
  results.add(lseq_part_global_rays(global_rays));
}

void lseq_part::compute_propagation_direction () {
  const auto &local_rays = results.get<lseq_part_rays>();
  // Collect the propagation direction of all valid rays.
  std::vector<bool> collected_ray_directions;
  for (const auto &bundle : local_rays.ray_buns) {
    for (const auto &r : bundle.rays) {
      if (r.is_valid()) { collected_ray_directions.push_back((r.v(2) > 0)); }
    }
  }
  // Check the coherence of ray directions.
  bool direction, validity;
  if (not(collected_ray_directions.empty())) {
    direction = collected_ray_directions.front();
    validity = true;
    for (const auto &dir : collected_ray_directions) {
      if (dir != direction) { validity = false; }
    }
  } else {
    direction = true;
    validity = false;
  }
  // Adding the result to the table.
  lseq_part_propagation_direction propag_dir(direction, validity);
  results.add(propag_dir);
}
