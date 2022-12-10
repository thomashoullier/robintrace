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

    standard sd = standard(5.0, -3.0);
    nullOstream << sd;
    SUCCEED("standard");
  }

  SECTION("transfer") {
    transfer trf(Vec3(0, 0, -1));
    nullOstream << trf;
    SUCCEED("transfer");
  }
}

#endif // PRINTERS_h
