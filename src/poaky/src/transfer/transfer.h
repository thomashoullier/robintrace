/** @file */
#ifndef TRANSFER_H
#define TRANSFER_H

#include "base/Vec3.h"
#include "base/Mat3.h"
#include "ray/ray.h"

/** @brief Transfer operation over a ray.
 *
 * The transfer operation defines a new LCS to propagate the ray to. It
 * operates a change of basis and an intersection with the newly defined local
 * plane.
 * Let, in a hypothetical global common coordinate system,
 * - LCS1 the starting LCS defined by its origin and basis vectors
 *   \f$ (A_1, \hat{x_1}, \hat{y_1}, \hat{z_1}) \f$
 * - LCS2 the new LCS defined by the transfer, 
 *   \f$ (A_2, \hat{x_2}, \hat{y_2}, \hat{z_2}) \f$
 *
 * The definition of LCS2 from LCS1 is done with,
 * - \f$ B \f$: A 3x3 rotation matrix between the basis vectors of LCS1 and
 *   LCS2.
 * - \f$ \overrightarrow{D} \f$: A translation vector from LCS1 to LCS2.
 *
 * The coordinates of the origin and basis vectors of LCS are expressed with,
 * \f[ \begin{cases}
 *   A_2       &= B \cdot \overrightarrow{D} \\
 *   \hat{x_2} &= B \cdot \hat{x_1} \\
 *   \hat{y_2} &= B \cdot \hat{y_1} \\
 *   \hat{z_2} &= B \cdot \hat{z_1}
 * \end{cases} \f]
 *
 * Which is to say, LCS2 is obtained from LCS1 by first applying the rotation
 * \f$ B \f$ and then translating the origin by \f$ \overrightarrow{D} \f$, with
 * \f$ D \f$ expressed in the rotated coordinates.
 * 
 * \image html shape/transfer-definition.svg
 * */

class transfer {
  public:
    /** @brief Transpose of the rotation matrix \f$ B \f$.
     *
     * Note that since rotation matrices are orthogonal, we have
     * \f$ B^{-1} = B^\top \f$. */
    Mat3 Bt;
    /** @brief Translation vector \f$ D \f$.
     *
     * Note the translation from LCS1 to LCS2 is applied in the rotated
     * coordinates. */
    Vec3 D;

    /** @brief Default constructor. */
    transfer ();
    /** @brief Translation initialization constructor. */
    transfer (Vec3 _D);
    /** @brief Full initialization constructor. */
    transfer (Mat3 _Bt, Vec3 _D);

    /** @brief Apply the transfer to a ray */
    void apply (ray &r);

    /** @brief Printer. */
    friend std::ostream& operator<< (std::ostream &out, const transfer &trf);
};

#endif // TRANSFER_H
