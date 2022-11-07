#include "test_main.h"

/*TODO: Accessors */

TEST_CASE("Base operations", "[base-ops]") {
  SECTION("Vec3") {
    Vec3 v1 (0, 0, 1);
    Vec3 v2 (1, 0, 0);
    Vec3 v3 = 4 * v1;
    
    // Dot product
    double v1dotv1 = dot(v1, v1);
    REQUIRE(v1dotv1 == Approx(1.0));
    double v1dotv2 = dot(v1, v2);
    REQUIRE(v1dotv2 == Approx(0.0));
    
    // Scalar multiplication
    REQUIRE(v3.l == Approx(0.0));
    REQUIRE(v3.m == Approx(0.0));
    REQUIRE(v3.n == Approx(4.0));
  }
}

TEST_CASE("Shape intersections", "[shape]") {
  SECTION("plane") {
    ray r = ray(Point3(0.2, 0.3, 0.0), UVec3(0, 0, 1));
    ray r_valid(r); // Validation ray is the input ray.
    plane pl = plane();
    pl.intersect(r);
    SUCCEED("ray/plane intersection happened.");
    ray_eq(r, r_valid);
  }

  SECTION("sphere nominal") {
    ray r = ray();
    r.p.x = 0.5;
    r.p.y = -0.32;
    r.p.z = 0;
    r.v.l = 0.01;
    r.v.m = -0.005;
    r.v.n = std::sqrt(1 - r.v.l * r.v.l - r.v.m * r.v.m);
    
    sphere s = sphere(5.0);
  
    ray r_valid = cgal_sphere_intersect(s, r);
    s.intersect(r);
    SUCCEED("ray/sphere intersection happened.");
    ray_eq(r, r_valid);
  }

  SECTION("sphere error: no intersection") {
    sphere s = sphere(5.0);
    double l = 0.2; double m = -0.005;
    double n = std::sqrt(1 - l*l - m*m);
    ray r(Point3(4.3, -0.32, 0), UVec3(l, m, n));
    
    ray r_valid = cgal_sphere_intersect(s, r);
    s.intersect(r);
    SUCCEED("ray/sphere intersection happened.");
    ray_eq(r, r_valid);
  }

  SECTION("sphere error: beyond first hemisphere.") {
    sphere s = sphere(5.0);
    double l = -0.55; double m = 0.55;
    double n = std::sqrt(1 - l*l - m*m);
    ray r(Point3(10, -8.32, 0), UVec3(l, m, n));

    ray r_valid = cgal_sphere_intersect(s, r);
    s.intersect(r);
    SUCCEED("ray/sphere intersection happened.");
    ray_eq(r, r_valid);
  }
}

TEST_CASE("Shape normal vector", "[normal]") {
  SECTION("plane") {
    ray r;
    plane pl;
    UVec3 N_pl = pl.normal(r);
    REQUIRE(N_pl.n == Approx(- r.v.n));
    REQUIRE(N_pl.l == Approx(0));
    REQUIRE(N_pl.m == Approx(0));
  }

  SECTION("sphere") {
    ray r = ray();
    r.p.x = 0.5;
    r.p.y = -0.32;
    r.p.z = 0;
    r.v.l = 0.01;
    r.v.m = -0.005;
    r.v.n = std::sqrt(1 - r.v.l * r.v.l - r.v.m * r.v.m);
    
    sphere s = sphere(5.0);
  
    s.intersect(r);

    UVec3 N_valid = cgal_sphere_normal(s, r);
    UVec3 N_test = s.normal(r);
    SUCCEED("sphere normal happened");
    REQUIRE(N_test.l == Approx(N_valid.l));
    REQUIRE(N_test.m == Approx(N_valid.m));
    REQUIRE(N_test.n == Approx(N_valid.n));
  }
}

TEST_CASE("Ray operations", "[rop]") {
  SECTION("reflect") {
    ray r = ray();
    r.p.x = 0.5;
    r.p.y = -0.32;
    r.p.z = 0;
    r.v.l = 0.01;
    r.v.m = -0.005;
    r.v.n = std::sqrt(1 - r.v.l * r.v.l - r.v.m * r.v.m);

    sphere s = sphere(5.0);

    s.intersect(r);
    UVec3 N = s.normal(r);
    UVec3 v_valid = cgal_reflect(r, N);
    reflect(r, N);
    SUCCEED("reflect happened");
    REQUIRE(r.v.l == Approx(v_valid.l));
    REQUIRE(r.v.m == Approx(v_valid.m));
    REQUIRE(r.v.n == Approx(v_valid.n));
  }
}
