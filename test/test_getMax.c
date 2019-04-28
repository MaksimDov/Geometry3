#include "geometry.h"

double getMax(double x1, double x2)
{
    return x1 > x2 ? x1 : x2;
}
TEST_CASE("GETMAX", "[MAX]")
{
    REQUIRE(getMax(1, 3) == 3);
    REQUIRE(getMax(5, 10) == 10);
    REQUIRE(getMax(-100, 100) == 100);
    REQUIRE(getMax(-36.6, 0) == 0);
    cout << "Test getMax" << endl;
}
