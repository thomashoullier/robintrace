#include "lpart/transfer_part.h"

transfer_part::transfer_part () {
  trf = transfer();
}

transfer_part::transfer_part (transfer _trf) {
  // Constructor
  trf = _trf;
}

void transfer_part::apply (bun &b) {
  for (auto &r : b.rays) {
    if (r.is_valid()) {
      trf.apply(r);
    }
  }
}

