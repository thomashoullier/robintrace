#include "ray_eq.h"

void Vec3_eq (const Vec3 &vec_totest, const Vec3 &vec_ref) {
  REQUIRE(vec_totest(0) == Catch::Approx(vec_ref(0)));
  REQUIRE(vec_totest(1) == Catch::Approx(vec_ref(1)));
  REQUIRE(vec_totest(2) == Catch::Approx(vec_ref(2)));
}

void Mat3_eq (const Mat3 &mat_totest, const Mat3 &mat_ref) {
  REQUIRE(mat_totest(0, 0) == Catch::Approx(mat_ref(0, 0)));
  REQUIRE(mat_totest(0, 1) == Catch::Approx(mat_ref(0, 1)));
  REQUIRE(mat_totest(0, 2) == Catch::Approx(mat_ref(0, 2)));
  REQUIRE(mat_totest(1, 0) == Catch::Approx(mat_ref(1, 0)));
  REQUIRE(mat_totest(1, 1) == Catch::Approx(mat_ref(1, 1)));
  REQUIRE(mat_totest(1, 2) == Catch::Approx(mat_ref(1, 2)));
  REQUIRE(mat_totest(2, 0) == Catch::Approx(mat_ref(2, 0)));
  REQUIRE(mat_totest(2, 1) == Catch::Approx(mat_ref(2, 1)));
  REQUIRE(mat_totest(2, 2) == Catch::Approx(mat_ref(2, 2)));
}

void ray_eq (const ray &ray_totest, const ray &ray_ref) {
  // Compare a test ray to a reference ray for equality.
  // A numerical epsilon is allowed. Error rays are
  // considered equal if their error code is the same.
  if (ray_totest.code != 0) {REQUIRE(ray_totest.code == ray_ref.code);}
  else {
   Vec3_eq(ray_totest.p, ray_ref.p);
   Vec3_eq(ray_totest.v, ray_ref.v);
  }
}
