#include "pinyo_test.h"

// This section tests that ray bundles actually achieve the same
// result as individual rays in poaky.
TEST_CASE("lpart apply", "[lpart]") {
  SECTION("transfer_part") {
    // rays
    ray r1 (Vec3(0.2, 0.3, 0.0), Vec3(0, 0, 1.0));
    ray r2 (Vec3(0.2001, 0.301, 0.0), Vec3(0, 0, 1.0));
    std::vector<ray> rays;
    rays.push_back(r1); rays.push_back(r2);
    bun b(rays);
    // transfer
    Mat3 m (Eigen::AngleAxisd(0.01, Vec3(0,1,0)));
    transfer trf (m.transpose(), Vec3(0.2, 0.4, -10)); 
    transfer_part trfp(trf);
    // Validation rays
    ray r1valid(r1); trf.apply(r1valid);
    ray r2valid(r2); trf.apply(r2valid);
    // function call and test
    trfp.apply(b);
    SUCCEED("transfer_part apply call.");
    ray_eq(b.rays.at(0), r1valid);
    ray_eq(b.rays.at(1), r2valid);
  }

  SECTION("plane shape_reflect_part") {
    // rays
    ray r1 (Vec3(-0.2, -0.3, 0.0), Vec3_lm(0.1, 0.2, false));
    ray r2 (Vec3(0.2001, 0.301, 0.0), Vec3_lm(0.2, -0.1, false));
    std::vector<ray> rays;
    rays.push_back(r1); rays.push_back(r2);
    bun b(rays);
    // plane
    plane pl;
    shape_reflect_part srp_pl(pl);
    // validation rays
    ray r1valid(r1), r2valid(r2);
    pl.intersect(r1valid);
    auto N1 = pl.normal(r1valid);
    reflect(r1valid, N1);
    pl.intersect(r2valid);
    auto N2 = pl.normal(r2valid);
    reflect(r2valid, N2);
    // function call and test
    srp_pl.apply(b);
    SUCCEED("shape_reflect_part plane call.");
    ray_eq(b.rays.at(0), r1valid);
    ray_eq(b.rays.at(1), r2valid);
  }

  SECTION("standard shape_refract_part") {
    // rays
    ray r1(Vec3(0.5, -0.32, 0), Vec3_lm(0.01, -0.005, true));
    ray r2(Vec3(0.5001, -0.3202, 0), Vec3_lm(0.0101, -0.005, true));
    std::vector<ray> rays;
    rays.push_back(r1); rays.push_back(r2);
    bun b(rays);
    // standard
    double nr = 1.3;
    standard sd(1/5.0, 0);
    shape_refract_part sfp_sd(sd, nr);
    // validation rays
    ray r1valid(r1), r2valid(r2);
    sd.intersect(r1valid); sd.intersect(r2valid);
    auto N1 = sd.normal(r1valid); auto N2 = sd.normal(r2valid);
    refract(r1valid, N1, nr); refract(r2valid, N2, nr);
    // function call and test
    sfp_sd.apply(b);
    SUCCEED("shape_refract_part standard call.");
    ray_eq(b.rays.at(0), r1valid);
    ray_eq(b.rays.at(1), r2valid);
  }

  SECTION("standard shape_reflect_part error case") {
    // rays
    ray r1(Vec3(4.3, -0.32, 0), Vec3_lm(0.2, -0.005, true));
    ray r2(Vec3(4.3001, -0.32, 0), Vec3_lm(0.2001, -0.005, true));
    std::vector<ray> rays;
    rays.push_back(r1); rays.push_back(r2);
    bun b(rays);
    // standard
    standard sd(1/5.0, 0);
    shape_reflect_part srp_sd(sd);
    // validation rays
    ray r1valid(r1), r2valid(r2);
    sd.intersect(r1valid); sd.intersect(r2valid);
    // The error case is no intersection.
    // function call and test
    srp_sd.apply(b);
    SUCCEED("shape_reflect_part standard call.");
    ray_eq(b.rays.at(0), r1valid);
    ray_eq(b.rays.at(1), r2valid);
  }
}

