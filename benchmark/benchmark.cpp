#include "benchmark.h"

TEST_CASE("Shape intersections", "[shape]") {

  double n = std::sqrt(1 - 0.01*0.01 - 0.005*0.005);
  ray r(Point3(0.5, -0.32, 0), UVec3(0, 0.01, n));

  sphere s(5.0);
  BENCHMARK("sphere/ray intersection") {
    return s.intersect(r);
    /* TODO: Generate a vector of rays to apply the benchmark to.
       https://github.com/catchorg/Catch2/blob/v2.x/docs/benchmarks.md */
  };

  BENCHMARK("CGAL sphere/ray intersection") {
    return cgal_sphere_intersect(s, r);
  };
}
