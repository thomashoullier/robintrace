#ifndef LSEQ_H
#define LSEQ_H

#include "pinyo.h"
#include "lpart_vec.h"
#include <vector>
#include <stdexcept>

typedef std::vector<bun> ray_pack;

class lseq {
  public:
    lpart_vec parts; // Sequence of parts.
    int last_part; // Last raytraced part.
    ray_pack ray_buns; // Current ray state
    // Indices of parts at which to save ray states.
    std::vector<int> states_tosave;
    std::vector<ray_pack> saved_states; // Ray states saved.
    int next_saved;
    
    lseq (const lpart_vec &_parts, const ray_pack &_ray_buns,
          const std::vector<int> &_states_tosave) {
      // Initialization constructor
      parts = _parts.cpy();
      last_part = -1;
      ray_buns = _ray_buns;
      states_tosave = _states_tosave;
      next_saved = 0;
      // Prepare the table of saved states
      // TODO: Initialize the tables at the right size.
    };
    
    void apply_next () {
      // Raytrace all rays through the next part, saving ray states along the
      // way.
      if (last_part + 1 >= int(parts.v.size())) {
        throw std::length_error("lseq::apply_next: No more parts to raytrace.");
      }
      // Modify the ray state by raytracing
      for (auto &b : ray_buns) { parts.v.at(last_part + 1)->apply(b); }
      last_part++;
      // Save the state if requested
      // TODO: Have states_tosave as a container where we can read and pop the
      // front element as we go along saving states. It contains the states
      // which remain to be saved.
      if (last_part == states_tosave.at(next_saved)) {
        saved_states.push_back(ray_buns);
        next_saved++;
      }
    };
    
    void apply_remaining () {
      // apply_next until all remaining parts are raytraced through.
      while (last_part + 1 < int(parts.v.size())) {
        apply_next();
      }
    };
};

#endif // LSEQ_H
