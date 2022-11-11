#include "benchmark.h"

TEST_CASE("Shape intersections", "[shape]") {
  SECTION("Sphere") {
    double n = std::sqrt(1 - 0.01*0.01 - 0.005*0.005);
    ray r(Point3(0.5, -0.32, 0), Vec3(0.005, 0.01, n));

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
    ray r(Point3(0.5, -0.32, 0), Vec3(0.005, 0.01, n));
    s.intersect(r);

    BENCHMARK("sphere normal") {
      return s.normal(r);
    };
  }
}

TEST_CASE("Ray operations", "[rop]") {
  double n = std::sqrt(1 - 0.01*0.01 - 0.04*0.04);
  ray r(Point3(0, 0, 0), Vec3(0.04, 0.01, n));
  double Nn = std::sqrt(1 - 0.01*0.01 - 0.08*0.08);
  Vec3 N(0.08, -0.01, - Nn);
  
  BENCHMARK("reflect") {
    return reflect(r, N);
  };
}
