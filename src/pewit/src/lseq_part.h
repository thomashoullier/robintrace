/** @file */
#ifndef LSEQ_PART_H
#define LSEQ_PART_H

#include <memory>
#include "pinyo.h"

/** @brief A part in a lseq. It contains both data and methods relative to a
 * single part. */
class lseq_part {
  public:
    /** @brief A copy of the underlying lpart. */
    std::unique_ptr<lpart> part;

    /** @brief Constructor. */
    template <typename T>
    lseq_part (const T &part) {
      static_assert(std::is_base_of<lpart, T>::value,
                    "T must be derived from lpart.");
      this->part = part.clone();
    }
};

#endif // LSEQ_PART_H

