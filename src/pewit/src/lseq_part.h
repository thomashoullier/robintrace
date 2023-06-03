/** @file */
#ifndef LSEQ_PART_H
#define LSEQ_PART_H

#include <memory>
#include <typeindex>
#include <unordered_map>
#include "ray_pack.h"
#include "pinyo.h"

#include "lseq_part_result/lseq_part_rays.h"

/** @brief A part in a lseq. It contains both data and methods relative to a
 * single part. */
class lseq_part {
  public:
    /** @brief A copy of the underlying lpart. */
    std::unique_ptr<lpart> part;
    /** @brief Results table. */
    std::unordered_map<std::type_index, std::unique_ptr<lseq_part_result>>
      results;

    /** @brief Whether to save ray states when tracing. */
    bool save_rays;

    /** @brief Constructor. */
    template <typename T>
    lseq_part (const T &part) {
      static_assert(std::is_base_of<lpart, T>::value,
                    "T must be derived from lpart.");
      this->part = part.clone();
      save_rays = false;
    }

    /** @brief Add a result to the table. */
    template <typename T>
    void add_result (const T &result) {
      static_assert(std::is_base_of<lseq_part_result, T>::value,
                    "T must be derived from lseq_part_result.");
      results[std::type_index(typeid(T))] = std::make_unique<T>(result);
    }

    /** @brief Retrieve a reference to a result. */
    template <typename T>
    T& get_result() {
      static_assert(std::is_base_of<lseq_part_result, T>::value,
                    "T must be derived from lseq_part_result.");
      auto it = results.find(std::type_index(typeid(T)));
      if (it != results.end()) {
          return *static_cast<T*>(it->second.get());
      } else {
          throw std::runtime_error("Result not found.");
      }
    }

    /** @brief Apply raytracing of the part to a ray_pack.
     *   
     *  Also save the ray states if the option is enabled. */
    void trace (ray_pack &ray_buns);
};

#endif // LSEQ_PART_H

