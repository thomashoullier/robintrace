#include "benchmark.h"

TEST_CASE("Shape intersections", "[shape]") {

  double n = std::sqrt(1 - 0.01*0.01 - 0.005*0.005);
  ray r(Point3(0.5, -0.32, 0), UVec3(0, 0.01, n));

  sphere s(5.0);
  BENCHMARK("sphere/ray intersection") {
    return s.intersect(r);
  };

  ray r_fornormal(Point3(0.5, -0.32, 0), UVec3(0, 0.01, n));
  s.intersect(r_fornormal);

  BENCHMARK("sphere normal") {
    return s.normal(r_fornormal);
  };

  BENCHMARK("CGAL sphere/ray intersection") {
    return cgal_sphere_intersect(s, r);
  };
}
