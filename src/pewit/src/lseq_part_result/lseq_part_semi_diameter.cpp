#include "lseq_part_semi_diameter.h"

lseq_part_semi_diameter::lseq_part_semi_diameter (double value) {
  this->value = value;
  validity = (this->value > 0.0);
}
