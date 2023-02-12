#include "poaky_test.h"

TEST_CASE("Shape intersections", "[shape]") {
  SECTION("plane") {
    ray r = ray(Vec3(0.2, 0.3, 0.0), Vec3(0, 0, 1.0));
    ray r_valid(r); // Validation ray is the input ray.
    plane pl = plane();
    pl.intersect(r);
    SUCCEED("ray/plane intersection happened.");
    ray_eq(r, r_valid);
  }

  SECTION("standard sphere nominal") {
    ray r(Vec3(0.5, -0.32, 0), Vec3_lm(0.01, -0.005, true));
    standard sd(1/5.0, 0);
    ray r_valid(
      Vec3(0.5003541437826592, -0.3201770718913296, 0.0354121647981072),
      r.v);
    sd.intersect(r);
    SUCCEED("ray/sphere intersection happened.");
    ray_eq(r, r_valid);
  }

  SECTION("standard sphere error: no intersection") {
    standard sd(1/5.0, 0);
    ray r(Vec3(4.3, -0.32, 0), Vec3_lm(0.2, -0.005, true));
    
    ray r_valid(r); r_valid.code = 5;
    sd.intersect(r);
    SUCCEED("ray/sphere intersection happened.");
    ray_eq(r, r_valid);
  }

  SECTION("standard sphere beyond first hemisphere.") {
    standard sd(1/5.0, 0);
    ray r(Vec3(10, -8.32, 0), Vec3_lm(-0.55, 0.55, true));
    ray r_valid(
      Vec3(4.020308637104494, -2.340308637104494, 6.833050448164786),
      r.v);
    sd.intersect(r);
    SUCCEED("ray/sphere intersection happened.");
    ray_eq(r, r_valid);
  }

  SECTION("standard: match with plane") {
    ray r_plane = ray(Vec3(0.2, 0.3, 0.0), Vec3(0, 0, 1.0));
    ray r_sd(r_plane);
    plane pl = plane();
    pl.intersect(r_plane);
    standard sd(0, 0);
    sd.intersect(r_sd);
    SUCCEED("ray/sd intersection happened.");
    ray_eq(r_sd, r_plane);
  }

  SECTION("standard: nominal case") {
    ray r(Vec3(4.1, 0.5, 0), Vec3_lm(-0.01, 0.02, true));
    ray r_valid(Vec3(4.104473059201623, 0.4910538815967531,
                     -0.44719407970049674),
                Vec3_lm(-0.01, 0.02, true));
    standard sd(-1.0/20, 3);
    sd.intersect(r);
    SUCCEED("ray/sd intersection happened.");
    ray_eq(r, r_valid);
  }

  SECTION("standard: no intersection") {
    ray r(Vec3(4.1, 0.5, 0), Vec3_lm(-0.01, 0.02, true));
    ray r_valid(r);
    r_valid.code = 5;
    standard sd(-1.0/20, 25);
    sd.intersect(r);
    SUCCEED("ray/sd intersection happened.");
    ray_eq(r, r_valid);
  }
}

TEST_CASE("Shape normal vector", "[normal]") {
  SECTION("plane") {
    ray r(Vec3(0, 0, 0), Vec3(0, 0, 1));
    plane pl;
    Vec3 N_pl = pl.normal(r);
    REQUIRE(N_pl(2) == Catch::Approx(- r.v(2)));
    REQUIRE(N_pl(0) == Catch::Approx(0));
    REQUIRE(N_pl(1) == Catch::Approx(0));
  }

  SECTION("standard sphere") {
    ray r(Vec3(0.5, -0.32, 0), Vec3_lm(0.01, -0.005, true));
    standard sd(1/5.0, 0);
    sd.intersect(r);

    Vec3 N_valid(0.10007082875653184, -0.06403541437826592,
                 -0.9929175670403786);
    Vec3 N_test = sd.normal(r);
    SUCCEED("sphere normal happened");
    REQUIRE(N_test(0) == Catch::Approx(N_valid(0)));
    REQUIRE(N_test(1) == Catch::Approx(N_valid(1)));
    REQUIRE(N_test(2) == Catch::Approx(N_valid(2)));
  }

  SECTION("standard") {
    ray r(Vec3(4.1, 0.5, 0), Vec3_lm(-0.01, 0.02, true));
    Vec3 N_valid(-0.2197903934822415, -0.026295440194246535,
                 -0.9751926644299127);
    standard sd(-1.0/20, 3);
    sd.intersect(r);
    Vec3 N_test = sd.normal(r);
    SUCCEED("standard normal happened.");
    REQUIRE(N_test(0) == Catch::Approx(N_valid(0)));
    REQUIRE(N_test(1) == Catch::Approx(N_valid(1)));
    REQUIRE(N_test(2) == Catch::Approx(N_valid(2)));
  }
}

TEST_CASE("Ray operations", "[rop]") {
  SECTION("reflect") {
    ray r(Vec3(0.5, -0.32, 0), Vec3_lm(0.01, -0.005, true));
    standard sd(1/5.0, 0);
    sd.intersect(r);
    Vec3 N = sd.normal(r);
    Vec3 v_valid = reflect_ref(r, N);
    reflect(r, N);
    SUCCEED("reflect happened");
    REQUIRE(r.v(0) == Catch::Approx(v_valid(0)));
    REQUIRE(r.v(1) == Catch::Approx(v_valid(1)));
    REQUIRE(r.v(2) == Catch::Approx(v_valid(2)));
  }

  SECTION("refract") {
    ray r(Vec3(0.5, -0.32, 0.0), Vec3_lm(0.01, -0.005, false));
    Vec3 N = Vec3_lm(0.02, 0.01, true);
    double nr = 1.3;
    
    ray r_valid = refract_ref(r, N, nr);
    refract(r, N, nr);
    SUCCEED("refract happened");
    REQUIRE(r.v(0) == Catch::Approx(r_valid.v(0)));
    REQUIRE(r.v(1) == Catch::Approx(r_valid.v(1)));
    REQUIRE(r.v(2) == Catch::Approx(r_valid.v(2)));
  }
}

TEST_CASE("Transfer", "[transfer]") {
  SECTION("transfer") {
    ray r (Vec3(0.2, 0.3, 0.0), Vec3(0, 0, 1.0));
    Mat3 m (Eigen::AngleAxisd(0.01, Vec3(0,1,0)));
    transfer trf (m.transpose(), Vec3(0.2, 0.4, -10));

    ray r_valid = transfer_ref(r, trf);
    trf.apply(r);
    SUCCEED("transfer happened");
    ray_eq(r, r_valid);
  }

  SECTION("transfer error: ray is parallel to new local plane.") {
    ray r (Vec3(0, 0, 0), Vec3(0, 0, 0));
    // We trigger the error with a zero vector.
    // The matrix itself works but maybe should not.
    Mat3 m (Eigen::AngleAxisd(M_PI_2, Vec3(1, 0, 0)));
    transfer trf(m.transpose(), Vec3(0, 0, 0));
    
    ray r_valid = transfer_ref(r, trf);
    trf.apply(r);
    ray_eq(r, r_valid);
  }
}
