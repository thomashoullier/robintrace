#include "test_main.h"

/*TODO: Accessors */

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
  
    s.intersect(r);
    SUCCEED("ray/sphere intersection happened.");
    ray r_valid = cgal_sphere_intersect(s, r);
    ray_eq(r, r_valid);
  }

  SECTION("sphere error: no intersection") {
    sphere s = sphere(5.0);
    double l = 0.2; double m = -0.005;
    double n = std::sqrt(1 - l*l - m*m);
    ray r(Point3(4.3, -0.32, 0), UVec3(l, m, n));
    
    s.intersect(r);
    SUCCEED("ray/sphere intersection happened.");
    REQUIRE(r.code == 1);
  }

  SECTION("sphere error: beyond first hemisphere.") {
    sphere s = sphere(5.0);
    double l = -0.55; double m = 0.55;
    double n = std::sqrt(1 - l*l - m*m);
    ray r(Point3(10, -8.32, 0), UVec3(l, m, n));

    s.intersect(r);
    SUCCEED("ray/sphere intersection happened.");
    REQUIRE(r.code == 2);
  }
}

