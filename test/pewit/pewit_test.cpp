#include "pewit_test.h"

TEST_CASE("lpart_vec", "[lpart_vec]") {
  SECTION("lpart_vec") {
    lpart_vec parts;
    SUCCEED("lpart_vec constructor");
    transfer_part trfp(transfer(Vec3(0.01, 0, 0)));
    parts.add_lpart(trfp);
    SUCCEED("Add lpart");
    lpart_vec parts_cpy = parts.cpy();
    SUCCEED("lpart_vec copy.");
  }
}

TEST_CASE("lseq", "[lseq]") {
  SECTION("One transfer and one surface") {
    // Creating the parts
    transfer_part trfp(transfer(Vec3(0.01, 0, 0)));
    shape_reflect_part srp(standard(1.0/20, -2));
    lpart_vec parts;
    parts.add_lpart(trfp);
    parts.add_lpart(srp);
    // Creating the rays
    std::vector<ray> rays;
    ray r1(Vec3(0.2, 0.3 , 0), Vec3(0, 0, 1));
    ray r2(Vec3(0.21, 0.31, 0), Vec3(0, 0, 1));
    rays.push_back(r1); rays.push_back(r2);
    bun b (rays);
    bun b2 (b);
    ray_pack ray_buns; ray_buns.push_back(b); ray_buns.push_back(b2);
    std::vector<int> states_tosave {0, 1};
    lseq ls (parts, ray_buns, states_tosave);
    SUCCEED("lseq instantiation.");
    ls.apply_next();
    SUCCEED("Apply next.");
    ls.apply_remaining();
    SUCCEED("Apply remaining.");
    CHECK_THROWS(ls.apply_next()); // No more parts to raytrace through.
  }
  SECTION("BUG #1: One surface then one transfer.") {
    // Parts
    shape_refract_part entrance(plane(), 1.0);
    transfer_part gap(Vec3(0, 0, 20));
    lpart_vec parts;
    parts.add_lpart(entrance);
    parts.add_lpart(gap);
    ray r1(Vec3(0, 0, 0), Vec3(0, 0, 1));
    bun b1;
    b1.rays.push_back(r1);
    ray_pack ray_buns;
    ray_buns.push_back(b1);
    // Not wanting the last state generated the bug
    std::vector<int> states_tosave {0};
    lseq ls (parts, ray_buns, states_tosave);
    SUCCEED("lseq instantiation.");
    ls.apply_remaining();
    SUCCEED("Apply remaining.");
  }
}
