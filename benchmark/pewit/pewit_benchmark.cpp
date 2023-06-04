#include "pewit_benchmark.h"

const int BUN_SIZE = 100;
const int PACK_SIZE = 10;
const int NUM_SURF = 10;

TEST_CASE("lseq apply", "[lseq]") {
  BENCHMARK("10 surfaces (full setup and full save)") {
    // Pairs of transfer/standard with full ray state saving.
    // Full setup and raytrace.
    // TODO: Find a way around the huge memory required to run the advanced
    //       benchmark.
    // Initial rays
    ray r(Vec3(0.01, -0.02, 0), Vec3_lm(0.01, -0.003, false));
    std::vector<ray> init_bun_rays(BUN_SIZE);
    std::fill(init_bun_rays.begin(), init_bun_rays.end(), r);
    bun b(init_bun_rays);
    ray_pack ray_buns;
    for (int i = 0 ; i < PACK_SIZE ; i++) {
      ray_buns.push_back(bun(b));
    }
    // Raytracing system
    standard sd (1.0/10000, -1.01);
    shape_refract_part srp(sd, 1.01);
    Mat3 m (Eigen::AngleAxisd(0.01, Vec3(0,1,0)));
    transfer trf (m.transpose(), Vec3(0.01, -0.02, -10));
    transfer_part trfp (trf);
    lpart_vec parts;
    for (int i = 0 ; i < NUM_SURF ; i++) {
      parts.add_lpart(trfp);
      parts.add_lpart(srp);
    }
    // lseq system
    lseq ls(parts);
    // Ray states to save
    for (int i = 0 ; i < NUM_SURF*2 ; i++) {
      ls.parts.at(i).save_rays = true;
    }
    ls.inputs.add(lseq_rays(ray_buns));
    ls.trace_remaining();
  };

  BENCHMARK("10 surfaces (full setup and no save)") {
    // Pairs of transfer/standard with full ray state saving.
    // Full setup and raytrace.
    // TODO: Find a way around the huge memory required to run the advanced
    //       benchmark.
    // Initial rays
    ray r(Vec3(0.01, -0.02, 0), Vec3_lm(0.01, -0.003, false));
    std::vector<ray> init_bun_rays(BUN_SIZE);
    std::fill(init_bun_rays.begin(), init_bun_rays.end(), r);
    bun b(init_bun_rays);
    ray_pack ray_buns;
    for (int i = 0 ; i < PACK_SIZE ; i++) {
      ray_buns.push_back(bun(b));
    }
    // Raytracing system
    standard sd (1.0/10000, -1.01);
    shape_refract_part srp(sd, 1.01);
    Mat3 m (Eigen::AngleAxisd(0.01, Vec3(0,1,0)));
    transfer trf (m.transpose(), Vec3(0.01, -0.02, -10));
    transfer_part trfp (trf);
    lpart_vec parts;
    for (int i = 0 ; i < NUM_SURF ; i++) {
      parts.add_lpart(trfp);
      parts.add_lpart(srp);
    }
    // lseq system
    lseq ls(parts);
    ls.inputs.add(lseq_rays(ray_buns));
    ls.trace_remaining();
  };
}
