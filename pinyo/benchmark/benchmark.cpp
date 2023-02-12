#include "benchmark.h"

const int BUN_SIZE = 1000;

TEST_CASE("lpart apply", "[lpart]") {
  BENCHMARK_ADVANCED("transfer_part")(Catch::Benchmark::Chronometer meter) {
    ray r(Vec3(0.5, -0.32, 0), Vec3_lm(0.01, 0.0, false));
    Mat3 m (Eigen::AngleAxisd(0.01, Vec3(0,1,0)));
    transfer trf (m.transpose(), Vec3(0.2, 0.4, -10));
    transfer_part trfp (trf);
    std::vector<ray> init_bun_rays(BUN_SIZE);
    std::fill(init_bun_rays.begin(), init_bun_rays.end(), r);
    bun b(init_bun_rays);
    std::vector<bun> buns(meter.runs());
    std::fill(buns.begin(), buns.end(), b);
    meter.measure([&buns, &trfp](int i) {
      return trfp.apply(buns.at(i));
    });
  };

  BENCHMARK_ADVANCED("standard shape_reflect_part")
    (Catch::Benchmark::Chronometer meter) {
    // Ray bundle
    ray r(Vec3(0.5, -0.32, 0), Vec3_lm(0.005, 0.01, true));
    std::vector<ray> init_bun_rays(BUN_SIZE);
    std::fill(init_bun_rays.begin(), init_bun_rays.end(), r);
    bun b(init_bun_rays);
    std::vector<bun> buns(meter.runs());
    std::fill(buns.begin(), buns.end(), b);
    // lpart
    standard sd(1.0/5, -1.1);
    shape_reflect_part srp_std(sd);
    meter.measure([&buns, &srp_std](int i) {
      return srp_std.apply(buns.at(i));
    });
  };

  BENCHMARK_ADVANCED("standard shape_refract_part")
    (Catch::Benchmark::Chronometer meter) {
    // Ray bundle
    ray r(Vec3(0.5, -0.32, 0), Vec3_lm(0.005, 0.01, true));
    std::vector<ray> init_bun_rays(BUN_SIZE);
    std::fill(init_bun_rays.begin(), init_bun_rays.end(), r);
    bun b(init_bun_rays);
    std::vector<bun> buns(meter.runs());
    std::fill(buns.begin(), buns.end(), b);
    // lpart
    standard sd(1.0/5, -1.1);
    shape_refract_part srp_std(sd, 1.2);
    meter.measure([&buns, &srp_std](int i) {
      return srp_std.apply(buns.at(i));
    });
  };
}
