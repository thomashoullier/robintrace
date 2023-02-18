#ifndef LSEQ_H
#define LSEQ_H

#include "pinyo.h"
#include <vector>
#include <stdexcept>

typedef std::vector<bun> ray_pack;

class lseq {
  public:
    // TODO: Find a way to use smart pointers in order to hold a copy of the
    // parts in // this scope. Can maybe be implemented using a templated
    // function for adding parts of type T derived from lpart.
    std::vector<lpart*> parts; // Sequence of parts.
    int last_part; // Last raytraced part.
    ray_pack ray_buns; // Current ray state
    // Indices of parts at which to save ray states.
    std::vector<int> states_tosave;
    std::vector<ray_pack> saved_states; // Ray states saved.
    int next_saved;

    lseq (const std::vector<lpart*> _parts, const ray_pack _ray_buns,
          const std::vector<int> _states_tosave) {
      // Initialization constructor
      parts = _parts;
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
      if (last_part + 1 >= int(parts.size())) {
        throw std::length_error("lseq::apply_next: No more parts to raytrace.");
      }
      auto cur_part = parts.at(last_part + 1);
      // Modify the ray state by raytracing
      for (auto &b : ray_buns) { cur_part->apply(b); }
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
    /*
    void apply_remaining () {
      // apply_next until all remaining parts are raytraced through.
      // TODO: Stop when there are no more parts to raytrace.
    };*/
};

#endif // LSEQ_H
