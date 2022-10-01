#define CATCH_CONFIG_MAIN
#define CATCH_CONFIG_ENABLE_BENCHMARKING
#include <catch2/catch.hpp>

#include <cmath>

#include "base/Point3.h"
#include "base/UVec3.h"
#include "ray/ray.h"
#include "shape/sphere.h"

TEST_CASE("Shape intersections", "[shape]") {

  double n = std::sqrt(1 - 0.01*0.01 - 0.005*0.005);
  ray r(Point3(0.5, -0.32, 0), UVec3(0, 0.01, n));

  sphere s(5.0);
  BENCHMARK("sphere/ray intersection") {
    return s.intersect(r);
    /* TODO: Generate a vector of rays to apply the benchmark to.
       https://github.com/catchorg/Catch2/blob/v2.x/docs/benchmarks.md */
  };
}
