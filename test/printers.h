#ifndef PRINTERS_H
#define PRINTERS_H

#include <catch2/catch.hpp>
#include "poaky.h"
#include <iostream>
#include <boost/iostreams/stream.hpp>

TEST_CASE("Objects printing", "[printers]") {

  boost::iostreams::stream<boost::iostreams::null_sink>
    nullOstream((boost::iostreams::null_sink()));

  SECTION("ray") {
    ray r = ray();
    nullOstream << r;
    SUCCEED("ray");
  }

  SECTION("shape") {
    plane pl = plane();
    nullOstream << pl;
    SUCCEED("plane");

    sphere s = sphere(5.0);
    nullOstream << s;
  }
}

#endif // PRINTERS_h
