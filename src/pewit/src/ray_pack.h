/** @file */
#ifndef RAY_PACK_H
#define RAY_PACK_H

#include "pinyo.h"
#include <iostream>
#include <vector>

/** @brief Vector of ray bundles.
 *
 * This is effectively a vector of vectors of rays. */
typedef std::vector<bun> ray_pack;

/** @brief ray_pack printer. */
std::ostream& operator<< (std::ostream &out, const ray_pack &ray_buns);

#endif // RAY_PACK_H
