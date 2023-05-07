#include "transfer.h"

/** The defaults are:
 * - \f$ B = B^{-1} = I \f$, the identity matrix.
 * - \f$ \overrightarrow{D} = 0_3 \f$, the zero vector.
 * 
 * This transfer operation does not change the current LCS.
 * */
transfer::transfer () {
  Bt = Mat3::Identity();
  D = Vec3::Zero();
}

/** The translation vector is initialized to \_D, while the rotation matrix
 *  \f$ B \f$ is identity.
 *  @param _D The initial transfer translation vector. */
transfer::transfer (Vec3 _D) {
  Bt = Mat3::Identity();
  D = _D;
}

/** The rotation matrix transpose is initialized to \p _Bt, the translation
 *  vector is initialized to \p _D.
 *  @param _Bt The initial rotation matrix transpose.
 *  @param _D The initial translation vector. */
transfer::transfer (Mat3 _Bt, Vec3 _D) {
  Bt = _Bt;
  D = _D;
}

/* Printer */
std::ostream& operator<< (std::ostream &out, const transfer &trf) {
  out << "transfer(Bt:\n" << trf.Bt << "\nD: " << trf.D << ")";
  return out;
}

/** The operation is decomposed into two successive operations on the ray.
 * - A change of basis from LCS1 to LCS2.
 * - A ray intersection with the local plane of LCS2
 * 
 * Let the ray coordinates in LCS1, \f$ (P_1, \overrightarrow{V_1}) \f$.
 * We first operate the change of basis, which gives us ray coordinates
 * \f$ (P_2, \overrightarrow{V_2}) \f$.
 *
 * \f[ \begin{cases}
 * P_2 &= \begin{bmatrix} x_2 \\ y_2 \\ z_2 \end{bmatrix}
        = B^{-1} \cdot P_1 - \overrightarrow{D} \\
   \overrightarrow{V_2} &= \begin{bmatrix} l_2 \\ m_2 \\ n_2 \end{bmatrix}
                         = B^{-1} \cdot \overrightarrow{V_1}
 * \end{cases} \f]
 *
 * \f$ n_2 = 0 \f$ is an error case, since the ray is parallel to the LCS2
 * local plane.
 *
 * We then operate the intersection of the ray with the LCS2 local plane,
 * obtaining \f$ (P_3, \overrightarrow{V_3}) \f$.
 *
 * \f[ \begin{cases}
    \overrightarrow{V_3} = \overrightarrow{V_2} \\
    t = - \frac{z_2}{n_2} \\
    P_3 = \begin{bmatrix} x_2 + t \cdot l_2 \\
                          y_2 + t \cdot m_2 \\
                          0 \end{bmatrix}
   \end{cases} \f]
 *
 * @image html shape/transfer-operation.svg
 *
 * */
void transfer::apply (ray &r) {
  r.v = Bt * r.v;

  if (r.v[2] == 0) {
    r.code = 4;
    return;}

  r.p = Bt * r.p - D;
  double t_inter = - r.p[2] / r.v[2];
  r.p[0] = r.p[0] + t_inter * r.v[0];
  r.p[1] = r.p[1] + t_inter * r.v[1];
  r.p[2] = 0;
}
