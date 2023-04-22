#ifndef PINYO_INSTANTIATORS_H
#define PINYO_INSTANTIATORS_H

#include "pinyo.h"

TEST_CASE("Objects instantiation", "[pinyo_constructors]") {
  SECTION("bun") {
    bun b_def;
    SUCCEED("Default constructor.");
    ray r1(Vec3(1, 2 ,3), Vec3(0, 0, 1));
    ray r2(Vec3(4, 5 ,6), Vec3(0, 0, 1));
    std::vector<ray> rays;
    rays.push_back(r1);
    rays.push_back(r2);
    bun b (rays);
    SUCCEED("bun instantiated.");
  }

  SECTION("transfer_part") {
    transfer_part trfp_default;
    SUCCEED("transfer_part default constructor.");
    transfer_part trfp_fromtransfer(transfer(Vec3(3, 0, 0)));
    SUCCEED("transfer_part constructor from transfer.");
    auto trfp_cpy = trfp_default.clone();
    SUCCEED("transfer_part cloning.");
  }

  SECTION("shape_part") {
    plane pl;
    shape_reflect_part plpr (pl);
    SUCCEED("shape_reflect_part with plane shape.");
    shape_refract_part plpf (pl, 1.2);
    SUCCEED("shape_refract_part with plane shape.");
    shape_reflect_part sdpr (standard(0,0));
    SUCCEED("shape_reflect_part with standard shape.");
    shape_refract_part sdpf (standard(0,0), 1.2);
    SUCCEED("shape_refract_part with standard shape.");
    auto plpr_cpy = plpr.clone();
    SUCCEED("shape_reflect_part cloning.");
    auto sdpf_cpy = sdpf.clone();
    SUCCEED("shape_refract_part cloning.");
  }
}

#endif // PINYO_INSTANTIATORS_H
