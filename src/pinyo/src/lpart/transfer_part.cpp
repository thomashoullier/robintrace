#include "lpart/transfer_part.h"

/** The default transfer() is used. */
transfer_part::transfer_part () {
  trf = transfer();
}

/** @param _trf Initial \ref transfer operation. */
transfer_part::transfer_part (transfer _trf) {
  trf = _trf;
}

void transfer_part::apply (bun &b) {
  for (auto &r : b.rays) {
    if (r.is_valid()) {
      trf.apply(r);
    }
  }
}

std::string transfer_part::print_str () const {
  std::stringstream ss;
  ss << "transfer_part<" << trf << ">";
  return ss.str();
}
