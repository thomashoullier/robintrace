#include "lseq_part_global_position.h"

lseq_part_global_position::lseq_part_global_position
  (const Vec3 &apex, const Mat3 &rotation) {
  pose.apex = apex;
  pose.rotation = rotation;
}

std::ostream& operator<< (std::ostream &out,
      const lseq_part_global_position &pos) {
  out << "<lseq_part_global_position:" << std::endl
      << "apex: " << pos.pose.apex << std::endl
      << "rotation: " << std::endl << pos.pose.rotation << ">";
  return out;
}
