#include <catch2/catch.hpp>

#include "base/Point3.h"
#include "base/UVec3.h"
#include "ray/ray.h"

TEST_CASE("Objects instantiation", "[constructors]") {
  SECTION("base") {
    Point3 p = Point3(); (void)p;
    UVec3 v = UVec3(); (void)v;
    SUCCEED("'base' objects instantiated.");
  }

  SECTION("ray") {
    ray r = ray(); (void)r;
    SUCCEED("'ray' instantiated.");
  }

  /* TODO: Try benchmark */

}
