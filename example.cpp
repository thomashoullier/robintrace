#include <iostream>
#include <vector>
#include <memory>
#include "robintrace.h"

int main(){
  std::cout << "# Main #" << std::endl;

  std::cout << "## Poaky ##" << std::endl;
  ray r (Vec3(0.2, 0.3, 0.0), Vec3(0, 0, 1.0));
  std::cout << "ray is valid? " << r.is_valid() << std::endl;
  standard sd (1.0/20, -2);
  std::cout << sd << std::endl;
  std::cout << "ray before intersection: " << r << std::endl;
  sd.intersect(r);
  std::cout << "ray after intersection: " << r << std::endl;
  Vec3 N = sd.normal(r);
  std::cout << "normal vector: " << N << std::endl;

  transfer tfr;
  std::cout << tfr << std::endl;

  std::cout << "## Pinyo ##" << std::endl;
  // bun
  std::vector<ray> rays;
  ray r1(Vec3(0.2, 0.3 , 0), Vec3(0, 0, 1));
  ray r2(Vec3(0.21, 0.31, 0), Vec3(0, 0, 1));
  rays.push_back(r1); rays.push_back(r2);
  bun b (rays);
  std::cout << "Before transfer: " << b << std::endl;

  // transfer_part
  transfer_part trfp(transfer(Vec3(0.01, 0, 0)));
  std::cout << trfp << std::endl;
  trfp.apply(b);
  std::cout << "After transfer: " << b << std::endl;

  // Standard reflective part
  standard sd2 (1.0/20, -2);
  shape_reflect_part srp(sd2);
  std::cout << srp << std::endl;
  srp.apply(b);
  std::cout << "After standard reflective part: " << b << std::endl;

  std::cout << "## Pewit ##" << std::endl;
  lpart_vec parts;
  parts.add_lpart(trfp);
  parts.add_lpart(srp);
  std::cout << parts << std::endl;
  bun b2 (b);
  ray_pack ray_buns; ray_buns.push_back(b); ray_buns.push_back(b2);
  std::vector<int> states_tosave {0, 1};
  lseq ls (parts, ray_buns, states_tosave);
  ls.apply_next();
  std::cout << "After lseq first surface: " << ls.ray_buns << std::endl;
  ls.apply_next();
  std::cout << "After lseq second surface: "
            << ls.ray_buns << std::endl;
  std::cout << "Saved states ls:" << std::endl << "#1: "
            << ls.saved_states.front() << std::endl << "#2: "
            << ls.saved_states.at(1) << std::endl;
  // A second time with raytrace all.
  lseq ls2 (parts, ray_buns, states_tosave);
  ls2.apply_remaining();
  std::cout << "Saved states ls2:" << std::endl << "#1: "
            << ls2.saved_states.front() << std::endl << "#2: "
            << ls2.saved_states.at(1) << std::endl;

  // Testing the new_lseq
  std::cout << "## new_lseq ##" << std::endl;
  new_lseq nls (parts);
  lseq_rays n_rays(ray_buns);
  nls.add_input(n_rays);
  nls.parts.at(0).save_rays = true;
  nls.parts.at(1).save_rays = true;
  nls.trace_next(); // surf0
  nls.trace_next(); // surf1
  auto rays_surf0 = nls.parts.at(0).get_result<lseq_part_rays>();
  auto rays_surf1 = nls.parts.at(1).get_result<lseq_part_rays>();
  std::cout << rays_surf0.ray_buns << std::endl;
  std::cout << rays_surf1.ray_buns << std::endl;
  std::cout << "Image rays:" << std::endl;
  std::cout << nls.get_input<lseq_rays>().ray_buns << std::endl;
}

