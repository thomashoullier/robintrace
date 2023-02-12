#ifndef PINYO_PRINTERS_H
#define PINYO_PRINTERS_H

#include "pinyo.h"
#include <iostream>
#include <boost/iostreams/stream.hpp>

TEST_CASE("Objects printing", "[pinyo_printers]") {
  boost::iostreams::stream<boost::iostreams::null_sink>
    nullOstream((boost::iostreams::null_sink()));
 
  SECTION("bun") {
    ray r1 (Vec3(0, 0, 0), Vec3(0, 0, 0));
    bun b;
    b.rays.push_back(r1);
    nullOstream << b;
    SUCCEED("bun");
  }
}

#endif // PINYO_PRINTERS_H
