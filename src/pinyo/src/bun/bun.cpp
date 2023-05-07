#include "bun/bun.h"

/** An empty vector of rays is initialized. */
bun::bun () {
  std::vector<ray> rays;
}

/** @param _rays Initial vector of rays. */
bun::bun (const std::vector<ray> _rays) {
  rays = _rays;
}

/* Printer */
std::ostream& operator<< (std::ostream &out, const bun &b) {
  out << "bun<";
  for (auto r : b.rays) {
    out << std::endl << r;
  }
  out << ">";
  return out;
}

