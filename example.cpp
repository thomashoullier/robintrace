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
  transfer_part trfp2(transfer(Vec3(0.01, 0, 0)));
  shape_reflect_part srp2(standard(1.0/20, -2));
  lpart_vec parts;
  parts.add_lpart(trfp2);
  parts.add_lpart(srp2);
  lseq ls(parts);
  std::vector<ray> rays_ls;
  ray r1_ls(Vec3(0.2, 0.3 , 0), Vec3(0, 0, 1));
  ray r2_ls(Vec3(0.21, 0.31, 0), Vec3(0, 0, 1));
  rays_ls.push_back(r1_ls); rays_ls.push_back(r2_ls);
  bun b_ls(rays_ls);
  bun b2_ls(b_ls);
  ray_pack ray_buns;
  ray_buns.push_back(b_ls);
  ray_buns.push_back(b2_ls);
  ls.inputs.add(lseq_rays(ray_buns));
  ls.parts.at(0).save_rays = true;
  ls.parts.at(1).save_rays = true;
  ls.trace_remaining();
  auto rays_surf0 = ls.parts.at(0).results.get<lseq_part_rays>();
  auto rays_surf1 = ls.parts.at(1).results.get<lseq_part_rays>();
  std::cout << rays_surf0.ray_buns << std::endl;
  std::cout << rays_surf1.ray_buns << std::endl;
  // Compute part global position.
  ls.compute_parts_global_position();
  std::cout << ls.parts.at(1).results.get<lseq_part_global_position>()
            << std::endl;
  // Compute part semi-diameter.
  ls.parts.at(1).compute_semi_diameter();
  auto sdia = ls.parts.at(1).results.get<lseq_part_semi_diameter>();
  std::cout << "Semi-diameter: " << sdia.value << std::endl;
  // Compute rays in global coordinates
  ls.parts.at(1).compute_global_rays();
  auto global_rays = ls.parts.at(1).results.get<lseq_part_global_rays>();
  std::cout << "Global rays of part 1: " << std::endl
            << global_rays.ray_buns << std::endl;
  // Compute the local rays propagation direction.
  ls.parts.at(1).compute_propagation_direction();
  const auto &propagation_direction =
    ls.parts.at(1).results.get<lseq_part_propagation_direction>();
  std::cout << "Local rays propagation direction at part 1: "
            << propagation_direction.direction << " "
            << propagation_direction.validity << std::endl;
}

