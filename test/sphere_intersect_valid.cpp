#include "sphere_intersect_valid.h"

int foo () {
  std::cout << "CGAL sphere intersection:" << std::endl;

  // Sphere definition
  double R = 5.0;
  Point_3 C(0.0, 0.0, R);
  Sphere_3 S(C, R*R);
  (void)S;

  // Line definition
  Point_3 P(0.5, -0.32, 0.0);
  double l = 0.01;
  double m = -0.005;
  double n = std::sqrt(1 - l * l - m * m);
  Vector_3 V(l, m, n);
  Line_3 L(P, V);

  std::vector <CGAL::Object> intersecs;
  CGAL::intersection(S, L, std::back_inserter(intersecs));
  std::cout << intersecs.size() << std::endl;

  std::pair<K::Circular_arc_point_3,unsigned> p1 =
    CGAL::object_cast< std::pair<K::Circular_arc_point_3,unsigned>
    >(intersecs[0]);
  std::cout << p1.first << std::endl << std::endl;

  std::pair<K::Circular_arc_point_3,unsigned> p2 =
    CGAL::object_cast< std::pair<K::Circular_arc_point_3,unsigned>
    >(intersecs[1]);
  std::cout << p2.first.x() << std::endl << std::endl;

  auto p1p = Point_3(to_double(p1.first.x()), to_double(p1.first.y()),
                     to_double(p1.first.z()));

  std::cout << p1p << std::endl;
  return 1;
}
