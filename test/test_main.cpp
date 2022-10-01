#include <catch2/catch.hpp>

#include "Point3.h"

TEST_CASE("Objects instantiation", "[constructors]") {
  Point3 p = Point3();

  REQUIRE(p.x == 0);
}
