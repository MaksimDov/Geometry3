#include "geometry.h"

double pi = 3.14159265359;

int printCircle(
        double x1, double y1, double r1, bool flag, int k, int lkl, int n)
{
    double p1, s1;
    p1 = pi * r1 * r1;
    s1 = 2 * pi * r1;
    cout << n << endl;
    printf("Circle(%.1f %.1f , %.1f)\n", x1, y1, r1);
    printf("perimetr = %.3f\n", p1);
    printf("area = %.3f\n", s1);
    if (flag == true) {
        printf("intersects: \n   ");
        if (lkl == 1) {
            cout << k << ". Circle" << endl;

        } else if (lkl == 2) {
            cout << k << ". Triangle" << endl;

        } else if (lkl == 3) {
            cout << k << ". Poligon" << endl;
        }

    } else
        printf("intersects: \n   - \n");
}

TEST_CASE("PRINT_CIRCLE", "[CIRCLE]")
{
    bool flag_ = false;
    REQUIRE(printCircle(0, 0, 346, flag_, 1) == 0);
    flag_ = true;
    REQUIRE(printCircle(0, 0, 235, flag_, 1) == 1);
    REQUIRE(printCircle(0, 0, 235, flag_, 2) == 2);
    REQUIRE(printCircle(0, 0, 235, flag_, 3) == 3);
    cout << "Test printCircle" << endl;
}
