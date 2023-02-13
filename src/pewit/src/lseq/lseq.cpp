#include "lseq.h"

lseq::lseq () {
  // Default constructor
}

lseq::lseq (const std::vector<lpart> _parts, const ray_pack _ray_buns,
            const std::vector<int> _states_tosave) {
  // Initialization constructor
  parts = _parts;
  last_part = -1;
  ray_buns = _ray_buns;
  states_tosave = _states_tosav;
  // Prepare the table of saved states
  // TODO: Initialize the tables at the right size.
}

void apply_next () {
  // Raytrace all rays through the next part.
  // TODO: Return if there are no more parts to raytrace.
  auto cur_part = parts.at(last_part + 1);
  // Modify the ray state by raytracing
  for (auto &b : ray_buns) { cur_part.apply(b); }
  last_part++;
  // Save the state if requested
  // TODO: Have states_tosave as a container where we can read and pop the front
  //       element as we go along saving states. It contains the states which
  //       remain to be saved.
  if (last_part == states_tosave.at(next_saved)) {
    saved_states.push_back(ray_buns);
    next_saved++;
  }
}

void apply_remaining () {
  // TODO: Stop when there are no more parts or no more states to save?
}
