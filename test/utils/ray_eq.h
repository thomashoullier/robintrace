#ifndef RAY_EQ_H
#define RAY_EQ_H

#include "poaky.h"
#include "catch2/catch_test_macros.hpp"
#include "catch2/catch_approx.hpp"

void Vec3_eq (const Vec3 &vec_totest, const Vec3 &vec_ref);
void Mat3_eq (const Mat3 &mat_totest, const Mat3 &mat_ref);
void ray_eq (const ray &r_totest, const ray &r_ref);

#endif // RAY_EQ_H
