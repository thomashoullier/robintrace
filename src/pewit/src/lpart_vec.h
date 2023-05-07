/** @file */
#include <vector>
#include <memory>
#include <iostream>

/** @brief Vector of lparts.
 *
 * Thin wrapper around a vector for \ref lpart objects. */
class lpart_vec {
  public:
    /** @brief Vector of lpart */
    std::vector<std::unique_ptr<lpart>> v;

    /** @brief Add a lpart to the vector.
     *
     * A copy of the lpart is added. */
    template <typename T>
    void add_lpart(T part) {
      static_assert(std::is_base_of<lpart, T>::value,
                    "T must be derived from lpart.");
      v.push_back(std::make_unique<T>(part));
    };

    /** @brief Return a deep copy of the instance. */
    lpart_vec cpy () const {
      // Return a copy of the instance.
      lpart_vec lv;
      lv.v = clone_vec();
      return lv;
    };

  private:
    /** @brief Return a deep copy of the raw vector of lparts */
    std::vector<std::unique_ptr<lpart>> clone_vec () const {
      // Return a copy of the internal vector.
      std::vector<std::unique_ptr<lpart>> _v;
      for (auto &ptr : v) {
        _v.push_back(std::unique_ptr<lpart>(ptr->clone()));
      }
      return _v;
    };

  /** @brief Printer. */
  friend std::ostream& operator<< (std::ostream &out, const lpart_vec &parts) {
    out << "lpart_vec[";
    int part_index = 0;
    for (auto &part_ptr : parts.v) {
      out << std::endl << "#" << part_index << ": " << *part_ptr;
      part_index++;
    }
    out << "]";
    return out;
  };
};
