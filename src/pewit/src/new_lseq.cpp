#include "new_lseq.h"

new_lseq::new_lseq (const lpart_vec &parts) {
  // TODO: instantiate the lseq parts and put them in 'parts.'
  for (const auto &part : parts.v) {
    this->parts.push_back(lseq_part(*part));
  }
}
