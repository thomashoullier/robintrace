#include <vector>
#include <memory>

class lpart_vec {
  public:
    std::vector<std::unique_ptr<lpart>> v;

    template <typename T>
    void add_lpart(T part) {
      static_assert(std::is_base_of<lpart, T>::value,
                    "T must be derived from lpart.");
      v.push_back(std::make_unique<T>(part));
    };

    std::vector<std::unique_ptr<lpart>> clone_vec () const {
      // Return a copy of the internal vector.
      std::vector<std::unique_ptr<lpart>> _v;
      for (auto &ptr : v) {
        _v.push_back(std::unique_ptr<lpart>(ptr->clone()));
      }
      return _v;
    };

    lpart_vec cpy () const {
      // Return a copy of the instance.
      lpart_vec lv;
      lv.v = clone_vec();
      return lv;
    };
};
