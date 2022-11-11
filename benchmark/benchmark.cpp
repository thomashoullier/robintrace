#include "benchmark.h"

TEST_CASE("Shape intersections", "[shape]") {
  SECTION("Sphere") {
    BENCHMARK_ADVANCED("sphere/ray intersection")
                      (Catch::Benchmark::Chronometer meter) {
      double n = std::sqrt(1 - 0.01*0.01 - 0.005*0.005);
      ray r(Point3(0.5, -0.32, 0), Vec3(0.005, 0.01, n));
      sphere s(5.0);
      std::vector<ray> init_rays (meter.runs());
      std::fill(init_rays.begin(), init_rays.end(), r);
      meter.measure([&init_rays, &s](int i) {
        return s.intersect(init_rays[i]);});
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
  BENCHMARK_ADVANCED("reflect")(Catch::Benchmark::Chronometer meter) {
      double n = std::sqrt(1 - 0.01*0.01 - 0.04*0.04);
      ray r(Point3(0, 0, 0), Vec3(0.04, 0.01, n));
      double Nn = std::sqrt(1 - 0.01*0.01 - 0.08*0.08);
      Vec3 N(0.08, -0.01, - Nn);    
      std::vector<ray> init_rays (meter.runs());
      std::fill(init_rays.begin(), init_rays.end(), r);
      meter.measure([&init_rays, &N](int i) {
        return reflect(init_rays[i], N);});
    };

  BENCHMARK_ADVANCED("refract")(Catch::Benchmark::Chronometer meter) {
      ray r(Point3(0.5, -0.32, 0), Vec3(0.01, 0.0, false));
      Vec3 N(0.0, 0.01, true);
      double nr = 1.3;
      std::vector<ray> init_rays (meter.runs());
      std::fill(init_rays.begin(), init_rays.end(), r);
      meter.measure([&init_rays, &N, &nr](int i) {
        return refract(init_rays[i], N, nr);});
    };
}
