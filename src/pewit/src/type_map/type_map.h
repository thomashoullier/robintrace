/** @file */
#ifndef TYPE_MAP_H
#define TYPE_MAP_H

#include <unordered_map>
#include <memory>
#include <typeindex>

/** @brief Map class storing unique_ptr to elements and keyed by their type. */
template <class element_type>
class type_map {
  private:
    /** @brief Map of type/pointers. */
    std::unordered_map<std::type_index, std::unique_ptr<element_type>> table;
  public:
    /** @brief Add an element of a type derived from element_type. */
    template <typename T>
    void add (const T &input) {
      static_assert(std::is_base_of<element_type, T>::value,
                    "T must be derived from element_type.");
      table[std::type_index(typeid(T))] = std::make_unique<T>(input);
    }

    /** @brief Get a reference to an element of the map. */
    template <typename T>
    T& get () {
      static_assert(std::is_base_of<element_type, T>::value,
                    "T must be derived from element_type.");
      auto it = table.find(std::type_index(typeid(T)));
      if (it != table.end()) {
          return *static_cast<T*>(it->second.get());
      } else {
          throw std::runtime_error("Element type not found.");
      }
    }
};

#endif // TYPE_MAP_H
