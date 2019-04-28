#include "geometry.h"

double getMin(double x1, double x2)
{
    return x1 < x2 ? x1 : x2;
}
TEST_CASE("GETMIN", "[MIN])
{
    REQUIRE(getMin(1, 3) == 1);
    REQUIRE(getMon(5, 10) == 5);
    REQUIRE(getMin(-100, 100) == -100);
    REQUIRE(getMin(-36.6, 0) == -36.6);
    cout << "Test getMin" << endl;
}
