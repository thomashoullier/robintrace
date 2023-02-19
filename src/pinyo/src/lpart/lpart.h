#ifndef LPART_H
#define LPART_H

#include "bun/bun.h"
#include "memory"

class lpart {
  // Virtual top class for any part which can be applied to ray bundles.
  public:
    virtual void apply (bun &b) = 0;
    virtual std::unique_ptr<lpart> clone () const = 0;
};

#endif // LPART_H
