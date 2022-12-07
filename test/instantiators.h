#ifndef INSTANTIATORS_H
#define INSTANTIATORS_H

#include <catch2/catch.hpp>
#include "poaky.h"

TEST_CASE("Objects instantiation", "[constructors]") {
  SECTION("base") {
    Vec3 v1 = Vec3(); (void)v1;
    SUCCEED("Vec3 void constructor.");
    Vec3 v2 = Vec3(0.0, 0.0, 1.0); (void)v2;
    SUCCEED("Vec3 initialization constructor.");
    Vec3 v3 = Vec3_lm(0.01, -0.02, true); (void)v3;
    SUCCEED("Vec3 automatic n component.");
  }

  SECTION("ray") {
    ray r1 = ray(); (void)r1;
    SUCCEED("'ray' instantiated.");
    ray r2 = ray(Vec3(1, 2, 3), Vec3(0, 0, 1.0)); (void)r2;
    SUCCEED("'ray' initialization constructor.");
  }

  SECTION("shape") {
    plane pl = plane(); (void)pl;
    SUCCEED("'plane instantiated.");

    sphere s = sphere(10.0); (void)s;
    SUCCEED("'sphere' instantiated.");

    standard sd = standard(5.0, -2.0); (void)sd;
    SUCCEED("'standard' instantiated.");
  }

  SECTION("transfer") {
    transfer trf_only_translate (Vec3(0, 0, -1.0));
    SUCCEED("transfer constructor: translation only.");
    transfer trf_full (Mat3::Identity(), Vec3(0, 0, -1.0));
    SUCCEED("transfer constructor: rotation and translation.");
  }
}

#endif // INSTANTIATORS_H
