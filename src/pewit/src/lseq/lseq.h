#ifndef LSEQ_H
#define LSEQ_H

#include "pinyo.h"
#include <vector>

typedef std::vector<bun> ray_pack;

class lseq {
  public:
    std::vector<lpart> parts; // Sequence of parts.
    int last_part; // Last raytraced part.
    ray_pack ray_buns; // Current ray state
    std::vector<int> states_tosave; // Indices of parts at which to save ray states.
    std::vector<ray_pack> saved_states; // Ray states saved.

    lseq();
    lseq(const std::vector<lpart> _parts, const ray_pack _ray_buns,
         const std::vector<int> _states_tosave);

    // Raytrace all rays through next part, saving states along the way.
    void apply_next (); 
    // apply_next until all remaining parts are raytraced through.
    void apply_remaining ();
};

#endif // LSEQ_H
