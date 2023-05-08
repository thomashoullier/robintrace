/** @file */
#ifndef SHAPE_PART_H
#define SHAPE_PART_H

#include "lpart/lpart.h"
#include "poaky.h"

/** @brief Class template implementing the specialized lparts for
 * reflective shape parts. */
template <class T>
class shape_reflect_part: public lpart {
  public:
    /** @brief The shape of the part.
     * 
     * T is of type \ref shape.*/
    T shp;

    /** @brief Constructor with initialization to the \ref shape \p _shp.
     * 
     * @param _shp Initial shape of the part.*/
    shape_reflect_part (T _shp) {
      shp = _shp;
    };
    
    /** @brief Apply reflective shape lpart operations to the ray bundle \p b.
     *
     * @param b Ray bundle to apply the part's operations to.
     *
     * The following operations are applied in succession to all rays in the
     * bundle:
     * -# shape.intersect()
     * -# shape.normal()
     * -# reflect()*/
    virtual void apply(bun &b) override {
      for (auto &r : b.rays) {
        if (not(r.is_valid())) {return;}
        shp.intersect(r);
        if (not(r.is_valid())) {return;}
        auto N = shp.normal(r);
        if (not(r.is_valid())) {return;}
        reflect(r, N);
      }
    };

    virtual std::unique_ptr<lpart> clone () const override {
      return std::make_unique<shape_reflect_part>(*this);
    };

    virtual bool is_transfer () override {
      return false;
    };

  private:
    virtual std::string print_str () const override {
      std::stringstream ss;
      ss << "shape_reflect_part<shape: " << shp << ">";
      return ss.str();
    };

    static_assert(std::is_base_of<shape, T>::value,
                  "T must be derived from shape.");
};

/** @brief Class template implementing the specialized lparts for
 * refractive shape parts. */
template <class T>
class shape_refract_part: public lpart {
  public:
    /** @brief The shape of the part.
     * 
     * T is of type \ref shape.*/
    T shp;
    /** @brief Part's relative refractive index. */
    double nr;

    /** @brief Constructor with initialization to the \ref shape \p _shp
     * and relative refractive index \p _nr.
     *
     * @param _shp Initial shape of the part.
     * @param _nr Initial relative refractive index of the part. */
    shape_refract_part (T _shp, double _nr) {
      shp = _shp;
      nr = _nr;
    };

    /** @brief Apply refractive shape lpart operations to the ray bundle \p b.
     *
     * @param b Ray bundle to apply the part's operations to.
     *
     * The following operations are applied in succession to all rays in the
     * bundle:
     * -# shape.intersect()
     * -# shape.normal()
     * -# refract()*/ 
    virtual void apply(bun &b) override {
      for (auto &r : b.rays) {
        if (not(r.is_valid())) {return;}
        shp.intersect(r);
        if (not(r.is_valid())) {return;}
        auto N = shp.normal(r);
        if (not(r.is_valid())) {return;}
        refract(r, N, nr);
      }
    };

    virtual std::unique_ptr<lpart> clone () const override {
      return std::make_unique<shape_refract_part>(*this);
    };

    virtual bool is_transfer () override {
      return false;
    };

  private:
    virtual std::string print_str () const override {
      std::stringstream ss;
      ss << "shape_refract_part<shape: " << shp << "," << std::endl
         << "nr: " << nr << ">";
      return ss.str();
    };

    static_assert(std::is_base_of<shape, T>::value,
                  "T must be derived from shape.");
};

#endif // SHAPE_PART_H
