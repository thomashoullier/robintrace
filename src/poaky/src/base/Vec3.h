/**
 * @file Vec3.h
 */

#ifndef VEC3_H
#define VEC3_H

#include <cmath>
#include <Eigen/Dense>

/** A 3D vector. */
typedef Eigen::Vector3d Vec3;

/** @brief
 * Constructor of a unit Vec3 from direction cosines (l, m) and the sign of n.
 * @param l Direction cosine in the x direction.
 * @param m Direction cosine in the y direction.
 * @param nsign Sign of the direction cosine in the z direction. True for
 * positive, False for negative. */
Vec3 Vec3_lm (double l, double m, bool nsign);

#endif //VEC3_H
