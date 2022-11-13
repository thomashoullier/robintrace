#include "benchmark.h"

TEST_CASE("Shape intersections", "[shape]") {
  SECTION("Sphere") {
    BENCHMARK_ADVANCED("sphere/ray intersection")
                      (Catch::Benchmark::Chronometer meter) {
      ray r(Vec3(0.5, -0.32, 0), Vec3_lm(0.005, 0.01, true));
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
    ray r(Vec3(0.5, -0.32, 0), Vec3_lm(0.005, 0.01, true));
    sphere s(5.0);
    s.intersect(r);

    BENCHMARK("sphere normal") {
      return s.normal(r);
    };
  }
}

TEST_CASE("Ray operations", "[rop]") {
  BENCHMARK_ADVANCED("reflect")(Catch::Benchmark::Chronometer meter) {
    ray r(Vec3(0, 0, 0), Vec3_lm(0.04, 0.01, true));
    Vec3 N = Vec3_lm(0.08, -0.01, false);    
    
    std::vector<ray> init_rays (meter.runs());
    std::fill(init_rays.begin(), init_rays.end(), r);
    meter.measure([&init_rays, &N](int i) {
      return reflect(init_rays[i], N);});
  };

  BENCHMARK_ADVANCED("refract")(Catch::Benchmark::Chronometer meter) {
    ray r(Vec3(0.5, -0.32, 0), Vec3_lm(0.01, 0.0, false));
    Vec3 N = Vec3_lm(0.0, 0.01, true);
    double nr = 1.3;

    std::vector<ray> init_rays (meter.runs());
    std::fill(init_rays.begin(), init_rays.end(), r);
    meter.measure([&init_rays, &N, &nr](int i) {
      return refract(init_rays[i], N, nr);});
  };
}
