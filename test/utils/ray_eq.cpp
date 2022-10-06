#include "ray_eq.h"

void ray_eq (const ray ray_totest, const ray ray_ref) {
  // Compare a test ray to a reference ray for equality.
  // A numerical epsilon is allowed. Error rays are
  // considered equal if their error code is the same.
  if (ray_totest.code != 0) {REQUIRE(ray_totest.code == ray_ref.code);}
  else {
   REQUIRE(ray_totest.p.x == Approx(ray_ref.p.x));
   REQUIRE(ray_totest.p.y == Approx(ray_ref.p.y));
   REQUIRE(ray_totest.p.z == Approx(ray_ref.p.z));
   REQUIRE(ray_totest.v.l == Approx(ray_ref.v.l));
   REQUIRE(ray_totest.v.m == Approx(ray_ref.v.m));
   REQUIRE(ray_totest.v.n == Approx(ray_ref.v.n));}}
