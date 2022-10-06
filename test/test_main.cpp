#include "test_main.h"

/*TODO: Accessors */

TEST_CASE("Shape intersections", "[shape]") {
  // TODO: Check tracing happened before checking result.
  ray r = ray();
  r.p.x = 0.5;
  r.p.y = -0.32;
  r.p.z = 0;
  r.v.l = 0.01;
  r.v.m = -0.005;
  r.v.n = std::sqrt(1 - r.v.l * r.v.l - r.v.m * r.v.m);
  
  sphere s = sphere(5.0);
  
  SECTION("sphere") {
    s.intersect(r);
    ray r_valid = cgal_sphere_intersect(s, r);
    ray_eq(r, r_valid);
  }
}

