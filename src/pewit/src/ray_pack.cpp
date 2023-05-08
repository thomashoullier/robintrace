#include "ray_pack.h"

std::ostream& operator<< (std::ostream &out, const ray_pack &ray_buns) {
  out << "ray_pack[";
  int bundle_index = 0;
  for (const auto &bundle : ray_buns) {
    out << std::endl << "#" << bundle_index << ": " << bundle;
    bundle_index++;
  }
  out << "]";
  return out;
}
