/** @file */

#ifndef NEW_LSEQ_H
#define NEW_LSEQ_H

#include <vector>
#include <memory>
#include <typeindex>
#include <unordered_map>

#include "pinyo.h"
#include "lseq_part.h"
#include "lseq_input/lseq_input.h"
#include "lpart_vec.h"
#include "lseq_input/lseq_rays.h"

class new_lseq {
  public:
    /** @brief Vector of the system's lseq_part. */
    std::vector<lseq_part> parts;

    std::unordered_map<std::type_index, std::unique_ptr<lseq_input>> inputs;

    /** @brief Default constructor. */
    new_lseq();
    /** @brief Initialization constructor. */
    new_lseq (const lpart_vec &parts);

    /** @brief Add an input to lseq. */
    template <typename T>
    void add_input (T &input) {
      static_assert(std::is_base_of<lseq_input, T>::value,
                    "T must be derived from lseq_input.");
      inputs[std::type_index(typeid(T))] = std::make_unique<T>(input);
    }

    /** @brief Get a reference to a lseq input. */
    template <typename T>
    T& get_input() {
      static_assert(std::is_base_of<lseq_input, T>::value,
                    "T must be derived from lseq_input.");     
      auto it = inputs.find(std::type_index(typeid(T)));
      if (it != inputs.end()) {
          return *static_cast<T*>(it->second.get());
      } else {
          throw std::runtime_error("Input not found.");
      }
    }

    /** @brief Trace the lseq_rays through the next part. */
    void trace_next ();
};

#endif // NEW_LSEQ_H
