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
    virtual void apply (bun &b) override;

    /** @brief Do nothing.
     * 
     * \todo We need to revise the abstraction lpart and intersect. */
    virtual void intersect (bun &b) override;
    /** @brief Clone */
    virtual std::unique_ptr<lpart> clone () const override {
      return std::make_unique<transfer_part>(*this);
    };
    virtual bool is_transfer () override {
      return true;
    };
    virtual bool is_renderable () override {
      return false;
    };

  private:
    virtual std::string print_str () const override;
};

#endif // TRANSFER_PART_H

