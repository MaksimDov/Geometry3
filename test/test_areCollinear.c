#include "geometry.h"

bool areCollinear(double x1, double y1, double x2, double y2) {
  return x1 / x2 == y1 / y2 ? true : false;
}

TEST_CASE("Test are colinear", "[areCollinear]") {
  REQUIRE(areCollinear(1, 1, 1, 1) == true);
  REQUIRE(areCollinear(234, 1, 43, 1) == false);
  cout << "Test areCollinear" << endl;
}
