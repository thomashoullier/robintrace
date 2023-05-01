/** @file */
#include <vector>
#include <memory>

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

    /** @brief Return a deep copy of the raw vector of lparts */
    std::vector<std::unique_ptr<lpart>> clone_vec () const {
      // Return a copy of the internal vector.
      std::vector<std::unique_ptr<lpart>> _v;
      for (auto &ptr : v) {
        _v.push_back(std::unique_ptr<lpart>(ptr->clone()));
      }
      return _v;
    };

    /** @brief Return a deep copy of the instance. */
    lpart_vec cpy () const {
      // Return a copy of the instance.
      lpart_vec lv;
      lv.v = clone_vec();
      return lv;
    };
};
