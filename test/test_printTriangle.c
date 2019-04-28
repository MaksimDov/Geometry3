#include "geometry.h"

int printTriangle(
        double x1,
        double y1,
        double x2,
        double y2,
        double x3,
        double y3,
        bool flag,
        int k,
        int lkl,
        int n)
{
    double s, p, determinant;
    p = sqrt((x2 - x1) * (x2 - x1)) + sqrt((x3 - x1) * (x3 - x1))
            + sqrt((x3 - x2) * (x3 - x2));
    determinant = (x1 - x3) * (y2 - y3) - (x2 - x3) * (y1 - y3);

    determinant < 0 ? s = determinant / (-2) : s = determinant / 2;
    cout << n << endl;
    printf("Triangle(%.1f %.1f , %.1f %.1f , %.1f %.1f)\n",
           x1,
           y1,
           x2,
           y2,
           x3,
           y3);
    printf("perimetr = %.3f\n", p);
    printf("area = %.3f\n", s);
    if (flag == 1) {
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

TEST_CASE("PRINT_TRIANGLE", "[TRIANGLE]")
{
    bool flag_ = false;
    REQUIRE(printTriangle(1, 1, 1, 1, 1, 1, flag_, 1) == 0);
    flag_ = true;
    REQUIRE(printTriangle(1, 1, 1, 1, 1, 1, flag_, 1) == 1);
    REQUIRE(printTriangle(1, 1, 1, 1, 1, 1, flag_, 2) == 2);
    REQUIRE(printTriangle(1, 1, 1, 1, 1, 1, flag_, 3) == 3);
    cout << "Test print Triagle" << endl;
}

