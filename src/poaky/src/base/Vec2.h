/** @file */
#ifndef VEC2_H
#define VEC2_H

#include <Eigen/Dense>
#include <iostream>
#include "Vec3.h"

/** @brief A 2D vector. */
typedef Eigen::Vector2d Vec2;

/** @brief Vec2 to Vec3 conversion */
Vec3 Vec2_to_Vec3 (const Vec2 &v);

/** @brief Vec2 printer. */
std::ostream& operator<< (std::ostream &out, const Vec2 &v);

#endif // VEC2_H
