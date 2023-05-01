/** @file */
#ifndef LSEQ_H
#define LSEQ_H

#include "pinyo.h"
#include "lpart_vec.h"
#include <vector>
#include <stdexcept>

/** @brief Vector of ray bundles.
 *
 * This is effectively a vector of vectors of rays. */
typedef std::vector<bun> ray_pack;

/** @brief Sequence of optical parts with associated ray pack, raytracing
 * application and ray states saving.
 *
 * lseq is the top-level API class for the RobinTrace raytracer. It holds
 * the definition of a sequence of lparts, rays to apply the sequence to, and
 * buffers for saving the ray states along the way. */
class lseq {
  public:
    /** @brief Sequence of parts. */
    lpart_vec parts;
    /** @brief State variable: last raytraced part. */
    int last_part;
    /** @brief Current ray state. */
    ray_pack ray_buns;
    /** @brief Indices of parts at which to save ray states. */
    std::vector<int> states_tosave;
    /** @brief Saved ray state data. */
    std::vector<ray_pack> saved_states;
    /** @brief State variable: next part at which to save the ray states. */
    int next_saved;
    
    /** @brief Default constructor.
     *
     * Everything is empty by default. */
    lseq () {
      // Default constructor
      last_part = -1;
      next_saved = 0;
    };

    /** @brief Initialization constructor.
     * 
     * @param _parts Initial vector of parts.
     * @param _ray_buns Initial ray pack.
     * @param _states_tosave The part indices at which to save the ray states.
     *
     * The arguments are all copied into lseq.
     *
     * \todo Initialize the saved states buffer at the right size. */
    lseq (const lpart_vec &_parts, const ray_pack &_ray_buns,
          const std::vector<int> &_states_tosave) {
      // Initialization constructor
      parts = _parts.cpy();
      last_part = -1;
      ray_buns = _ray_buns;
      states_tosave = _states_tosave;
      next_saved = 0;
    };
    
    /** @brief Apply the next part in the sequence to the ray pack, saving
     * ray states along the way as specified.
     *
     * \todo
     * Have states_tosave as a container where we can read and pop the
     * front element as we go along saving states. It contains the states
     * which remain to be saved. */
    void apply_next () {
      if (last_part + 1 >= int(parts.v.size())) {
        throw std::length_error("lseq::apply_next: No more parts to raytrace.");
      }
      // Modify the ray state by raytracing
      for (auto &b : ray_buns) { parts.v.at(last_part + 1)->apply(b); }
      last_part++;
      // Save the state if requested
      if (not(states_tosave.empty())
          && (last_part == states_tosave.at(next_saved))) {
        saved_states.push_back(ray_buns);
        next_saved++;
      }
    };
    
    /** @brief apply_next() until all remaining parts are raytraced through. */
    void apply_remaining () {
      while (last_part + 1 < int(parts.v.size())) {
        apply_next();
      }
    };
};

#endif // LSEQ_H
