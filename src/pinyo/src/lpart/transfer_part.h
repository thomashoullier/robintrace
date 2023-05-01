/** @file */
#ifndef TRANSFER_PART_H
#define TRANSFER_PART_H

#include "lpart/lpart.h"
#include "poaky.h"

/** @brief Part which applies a transfer operation to rays. */
class transfer_part: public lpart {
  public:
    /** @brief The transfer operation to perform. */
    transfer trf;
    
    /** @brief Default constructor. */
    transfer_part ();
    /** @brief Constructor with initialization to the \ref transfer \p _trf. */
    transfer_part (transfer _trf);

    /** @brief Apply the transfer operation to ray bundle \p b. */
    void apply (bun &b);
    std::unique_ptr<lpart> clone () const override {
      return std::make_unique<transfer_part>(*this);
    };
};

#endif // TRANSFER_PART_H

