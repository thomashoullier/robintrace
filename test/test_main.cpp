#define CATCH_CONFIG_MAIN
#include <catch2/catch.hpp>

#include <cmath>

#include "poaky.h"
#include "sphere_intersect_valid.h"

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

  SECTION("shape") {
    plane pl = plane(); (void)pl;
    SUCCEED("'plane instantiated.");

    sphere s = sphere(10.0); (void)s;
    SUCCEED("'sphere' instantiated.");
  }
}

/*TODO: Accessors */

TEST_CASE("Shape intersections", "[shape]") {
  // TODO: Check tracing happened before checking result.
  ray r = ray();
  r.p.x = 0.5;
  r.p.y = -0.32;
  r.p.z = 0;
  r.v.l = 0.01;
  r.v.m = -0.005;
  r.v.n = std::sqrt(1 - r.v.l * r.v.l - r.v.m * r.v.m);
  
  sphere s = sphere(5.0);

  ray r_valid = foo(s, r); (void)(r_valid);
  
  SECTION("sphere") {
    s.intersect(r);
    REQUIRE(r.code == 0);
    /* TODO: Value assertions. Catch2 has a REQUIRE for floats.
             But maybe we need our own ray comparison util. */
  }
}

