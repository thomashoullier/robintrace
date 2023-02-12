#ifndef LPART_H
#define LPART_H

#include "bun/bun.h"

class lpart {
  // Virtual top class for any part which can be applied to ray bundles.
  public:
    virtual void apply (bun &b) = 0;
};

#endif // LPART_H
