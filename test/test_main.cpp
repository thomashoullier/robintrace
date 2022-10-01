#include <catch2/catch.hpp>

#include "base/Point3.h"
#include "base/UVec3.h"
#include "ray/ray.h"

TEST_CASE("Objects instantiation", "[constructors]") {
  SECTION("base") {
    Point3 p = Point3();
    UVec3 v = UVec3();
    p.x = 2;
    v.l = 0.2;
    REQUIRE(p.x == 2);
    REQUIRE(v.l == 0.2);
  }

  SECTION("ray") {
    ray r = ray();
    r.p.y = 9;
    REQUIRE(r.p.y == 9);
  }

  /* TODO: Try benchmark */

}
