/** @file */
#ifndef ROP_H
#define ROP_H

#include "base/Vec3.h"
#include "ray/ray.h"
#include <cmath>

/** @brief Reflect ray operation. */
void reflect (ray &r, const Vec3 &N);
/** @brief Refract ray operation. */
void refract (ray &r, const Vec3 &N, double nr);

#endif // ROP_H
