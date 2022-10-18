#include "benchmark.h"

TEST_CASE("Shape intersections", "[shape]") {
  SECTION("Sphere") {
    double n = std::sqrt(1 - 0.01*0.01 - 0.005*0.005);
    ray r(Point3(0.5, -0.32, 0), UVec3(0, 0.01, n));

    sphere s(5.0);
    BENCHMARK("sphere/ray intersection") {
      return s.intersect(r);
    };
  }
}

TEST_CASE("Shape normals", "[normal]") {
  SECTION("Sphere") {
    sphere s(5.0);
    double n = std::sqrt(1 - 0.01*0.01 - 0.005*0.005);
    ray r(Point3(0.5, -0.32, 0), UVec3(0, 0.01, n));
    s.intersect(r);

    BENCHMARK("sphere normal") {
      return s.normal(r);
    };
  }
}

TEST_CASE("Ray operations", "[rop]") {
  sphere s(5.0);
  double n = std::sqrt(1 - 0.01*0.01 - 0.005*0.005);
  ray r(Point3(0.5, -0.32, 0), UVec3(0, 0.01, n));
  s.intersect(r);
  UVec3 N = s.normal(r);
  
  BENCHMARK("reflect") {
    return reflect(r, N);
  };
}
