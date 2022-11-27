#include "test_main.h"

/*TODO: Accessors */

TEST_CASE("Shape intersections", "[shape]") {
  SECTION("plane") {
    ray r = ray(Vec3(0.2, 0.3, 0.0), Vec3(0, 0, 1.0));
    ray r_valid(r); // Validation ray is the input ray.
    plane pl = plane();
    pl.intersect(r);
    SUCCEED("ray/plane intersection happened.");
    ray_eq(r, r_valid);
  }

  SECTION("sphere nominal") {
    ray r(Vec3(0.5, -0.32, 0), Vec3_lm(0.01, -0.005, true));
    sphere s = sphere(5.0);
  
    ray r_valid = sphere_intersect_ref(s, r);
    s.intersect(r);
    SUCCEED("ray/sphere intersection happened.");
    ray_eq(r, r_valid);
  }

  SECTION("sphere error: no intersection") {
    sphere s = sphere(5.0);
    ray r(Vec3(4.3, -0.32, 0), Vec3_lm(0.2, -0.005, true));
    
    ray r_valid = sphere_intersect_ref(s, r);
    s.intersect(r);
    SUCCEED("ray/sphere intersection happened.");
    ray_eq(r, r_valid);
  }

  SECTION("sphere error: beyond first hemisphere.") {
    sphere s = sphere(5.0);
    ray r(Vec3(10, -8.32, 0), Vec3_lm(-0.55, 0.55, true));

    ray r_valid = sphere_intersect_ref(s, r);
    s.intersect(r);
    SUCCEED("ray/sphere intersection happened.");
    ray_eq(r, r_valid);
  }
}

TEST_CASE("Shape normal vector", "[normal]") {
  SECTION("plane") {
    ray r(Vec3(0, 0, 0), Vec3(0, 0, 1));
    plane pl;
    Vec3 N_pl = pl.normal(r);
    REQUIRE(N_pl(2) == Approx(- r.v(2)));
    REQUIRE(N_pl(0) == Approx(0));
    REQUIRE(N_pl(1) == Approx(0));
  }

  SECTION("sphere") {
    ray r(Vec3(0.5, -0.32, 0), Vec3_lm(0.01, -0.005, true));
    sphere s = sphere(5.0);
  
    s.intersect(r);

    Vec3 N_valid = sphere_normal_ref(s, r);
    Vec3 N_test = s.normal(r);
    SUCCEED("sphere normal happened");
    REQUIRE(N_test(0) == Approx(N_valid(0)));
    REQUIRE(N_test(1) == Approx(N_valid(1)));
    REQUIRE(N_test(2) == Approx(N_valid(2)));
  }
}

TEST_CASE("Ray operations", "[rop]") {
  SECTION("reflect") {
    ray r(Vec3(0.5, -0.32, 0), Vec3_lm(0.01, -0.005, true));
    sphere s = sphere(5.0);

    s.intersect(r);
    Vec3 N = s.normal(r);
    Vec3 v_valid = reflect_ref(r, N);
    reflect(r, N);
    SUCCEED("reflect happened");
    REQUIRE(r.v(0) == Approx(v_valid(0)));
    REQUIRE(r.v(1) == Approx(v_valid(1)));
    REQUIRE(r.v(2) == Approx(v_valid(2)));
  }

  SECTION("refract") {
    ray r(Vec3(0.5, -0.32, 0.0), Vec3_lm(0.01, -0.005, false));
    Vec3 N = Vec3_lm(0.02, 0.01, true);
    double nr = 1.3;
    
    ray r_valid = refract_ref(r, N, nr);
    refract(r, N, nr);
    SUCCEED("refract happened");
    REQUIRE(r.v(0) == Approx(r_valid.v(0)));
    REQUIRE(r.v(1) == Approx(r_valid.v(1)));
    REQUIRE(r.v(2) == Approx(r_valid.v(2)));
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
