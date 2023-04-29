/** @file */
#ifndef TRANSFER_H
#define TRANSFER_H

#include "base/Vec3.h"
#include "base/Mat3.h"
#include "ray/ray.h"

/** @brief Transfer operation over a ray. **/
class transfer {
  public:
    Mat3 Bt; // Transpose of rotation matrix B.
    Vec3 D; // Translation vector D.

    transfer ();
    transfer (Vec3 _D);
    transfer (Mat3 _Bt, Vec3 _D);

    void apply (ray &r);
};

std::ostream& operator<< (std::ostream &out, const transfer &trf);

#endif // TRANSFER_H
