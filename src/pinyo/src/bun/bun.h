#ifndef BUN_H
#define BUN_H

#include "poaky.h"
#include <vector>
#include <unordered_set>

class bun {
  public:
    std::vector<ray> rays;

    bun();
    bun(const std::vector<ray> _rays);
};

std::ostream& operator<< (std::ostream &out, const bun &b);

#endif // BUN_H
