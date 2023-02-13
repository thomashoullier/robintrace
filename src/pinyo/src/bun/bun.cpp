#include "bun/bun.h"

bun::bun () {
  // Default constructor.
  std::vector<ray> rays;
}

bun::bun (const std::vector<ray> _rays) {
  // Constructor
  rays = _rays;
}

std::ostream& operator<< (std::ostream &out, const bun &b) {
  // Printer
  out << "bun<" << std::endl;
  for (auto r : b.rays) {
    out << r << std::endl;
  }
  out << ">";
  return out;
}

