/** @file */
#ifndef LSEQ_PART_GLOBAL_POSITION_H
#define LSEQ_PART_GLOBAL_POSITION_H

#include "lseq_part_result.h"
#include "poaky.h"

/** @brief The global coordinates position of a lseq renderable part. */
class lseq_part_global_position : public lseq_part_result {
  public:
    /** @brief Global coordinates position of the part. */
    struct position {
      /** @brief Global coordinates position of the part's apex. */
      Vec3 apex;
      /** @brief Global coordinates attitude matrix of the part. */
      Mat3 rotation;
    };

    /** @brief The pose of the object in global coordinates. */
    position pose;

    /** @brief Constructor. */
    lseq_part_global_position(const Vec3 &apex, const Mat3 &rotation);

    /** @brief Printer. */
    friend std::ostream& operator<< (std::ostream &out,
      const lseq_part_global_position &pos);
};

#endif // LSEQ_PART_GLOBAL_POSITION_H
