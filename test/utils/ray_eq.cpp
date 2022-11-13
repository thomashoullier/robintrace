#include "ray_eq.h"

void ray_eq (const ray &ray_totest, const ray &ray_ref) {
  // Compare a test ray to a reference ray for equality.
  // A numerical epsilon is allowed. Error rays are
  // considered equal if their error code is the same.
  if (ray_totest.code != 0) {REQUIRE(ray_totest.code == ray_ref.code);}
  else {
   REQUIRE(ray_totest.p(0) == Approx(ray_ref.p(0)));
   REQUIRE(ray_totest.p(1) == Approx(ray_ref.p(1)));
   REQUIRE(ray_totest.p(2) == Approx(ray_ref.p(2)));
   REQUIRE(ray_totest.v(0) == Approx(ray_ref.v(0)));
   REQUIRE(ray_totest.v(1) == Approx(ray_ref.v(1)));
   REQUIRE(ray_totest.v(2) == Approx(ray_ref.v(2)));}}
