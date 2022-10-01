#define CATCH_CONFIG_MAIN
#include <catch2/catch.hpp>

#include <cmath>

#include "base/Point3.h"
#include "base/UVec3.h"
#include "ray/ray.h"
#include "shape/sphere.h"

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
}

TEST_CASE("Shape intersections", "[shape]") {
  ray r = ray();
  r.p.x = 0.5;
  r.p.y = -0.32;
  r.p.z = 0;
  r.v.l = 0.01;
  r.v.m = -0.005;
  r.v.n = std::sqrt(1 - r.v.l * r.v.l - r.v.m * r.v.m);
  
  sphere s = sphere(5.0);
  
  SECTION("sphere") {
    s.intersect(r);
    REQUIRE(r.code == 0);
    /* TODO: Value assertions. Catch2 has a REQUIRE for floats.
             But maybe we need our own ray comparison util. */
  }
}
