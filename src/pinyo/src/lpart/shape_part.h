#ifndef SHAPE_PART_H
#define SHAPE_PART_H

#include "lpart/lpart.h"
#include "poaky.h"

template <class T>
class shape_reflect_part: public lpart {
  public:
    T shp;

    shape_reflect_part (T _shp) {
      shp = _shp;
    };
    
    void apply(bun &b) {
      for (auto &r : b.rays) {
        if (not(r.is_valid())) {return;}
        shp.intersect(r);
        if (not(r.is_valid())) {return;}
        auto N = shp.normal(r);
        if (not(r.is_valid())) {return;}
        reflect(r, N);
      }
    };

    static_assert(std::is_base_of<shape, T>::value,
                  "T must be derived from shape.");
};

template <class T>
class shape_refract_part: public lpart {
  public:
    T shp;
    double nr;

    shape_refract_part (T _shp, double _nr) {
      shp = _shp;
      nr = _nr;
    };
    
    void apply(bun &b) {
      for (auto &r : b.rays) {
        if (not(r.is_valid())) {return;}
        shp.intersect(r);
        if (not(r.is_valid())) {return;}
        auto N = shp.normal(r);
        if (not(r.is_valid())) {return;}
        refract(r, N, nr);
      }
    };

    static_assert(std::is_base_of<shape, T>::value,
                  "T must be derived from shape.");
};

#endif // SHAPE_PART_H
