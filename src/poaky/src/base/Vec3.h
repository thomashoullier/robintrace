/** @file */

#ifndef VEC3_H
#define VEC3_H

#include <cmath>
#include <iostream>
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

/** @brief Vec3 printer */
std::ostream& operator<< (std::ostream &out, const Vec3 &v);

#endif //VEC3_H
