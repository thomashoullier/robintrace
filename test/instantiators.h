#ifndef INSTANTIATORS_H
#define INSTANTIATORS_H

#include <catch2/catch.hpp>
#include "poaky.h"

TEST_CASE("Objects instantiation", "[constructors]") {
  SECTION("base") {
    Point3 p1 = Point3(); (void)p1;
    SUCCEED("Point3 void constructor.");
    Point3 p2 = Point3(1.0, 2.0, 3.0); (void)p2;
    SUCCEED("Point3 initialization constructor.");
    UVec3 v1 = UVec3(); (void)v1;
    SUCCEED("UVec3 void constructor.");
    UVec3 v2 = UVec3(0.0, 0.0, 1.0); (void)v2;
    SUCCEED("UVec3 initialization constructor.");
  }

  SECTION("ray") {
    ray r1 = ray(); (void)r1;
    SUCCEED("'ray' instantiated.");
    ray r2 = ray(Point3(1, 2, 3), UVec3(0, 0, 1)); (void)r2;
    SUCCEED("'ray' initialization constructor.");
  }

  SECTION("shape") {
    plane pl = plane(); (void)pl;
    SUCCEED("'plane instantiated.");

    sphere s = sphere(10.0); (void)s;
    SUCCEED("'sphere' instantiated.");
  }}

#endif // INSTANTIATORS_H
