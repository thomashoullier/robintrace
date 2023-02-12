#include "benchmark.h"

TEST_CASE("Shape intersections", "[shape]") {
  BENCHMARK_ADVANCED("standard")
                    (Catch::Benchmark::Chronometer meter) {
    ray r(Vec3(0.5, -0.32, 0), Vec3_lm(0.005, 0.01, true));
    standard sd(1.0/5, -1.1);

    std::vector<ray> init_rays (meter.runs());
    std::fill(init_rays.begin(), init_rays.end(), r);
    meter.measure([&init_rays, &sd](int i) {
      return sd.intersect(init_rays[i]);});
  };
}

TEST_CASE("Shape normals", "[normal]") {
  BENCHMARK_ADVANCED("standard")
                    (Catch::Benchmark::Chronometer meter) {
    ray r(Vec3(0.5, -0.32, 0), Vec3_lm(0.005, 0.01, true));
    standard sd(1.0/5.0, -1.1);
    sd.intersect(r);

    std::vector<ray> init_rays (meter.runs());
    std::fill(init_rays.begin(), init_rays.end(), r);
    meter.measure([&init_rays, &sd](int i) {
      return sd.normal(init_rays[i]);});
  };
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

TEST_CASE("Transfer", "[transfer]") {
  BENCHMARK_ADVANCED("transfer")(Catch::Benchmark::Chronometer meter) {
    ray r(Vec3(0.5, -0.32, 0), Vec3_lm(0.01, 0.0, false));
    Mat3 m (Eigen::AngleAxisd(0.01, Vec3(0,1,0)));
    transfer trf (m.transpose(), Vec3(0.2, 0.4, -10));

    std::vector<ray> init_rays (meter.runs());
    std::fill(init_rays.begin(), init_rays.end(), r);
    meter.measure([&init_rays, &trf](int i) {
      return trf.apply(init_rays[i]);});
  };
}
