#ifndef TRANSFER_PART_H
#define TRANSFER_PART_H

#include "lpart/lpart.h"
#include "poaky.h"

class transfer_part: public lpart {
  public:
    transfer trf;
    
    transfer_part ();
    transfer_part (transfer _trf);
    void apply (bun &b);
};

#endif // TRANSFER_PART_H
