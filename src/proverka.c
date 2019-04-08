#include "geometry.h"

void distan(double x, double y, double x1, double y1, double& L)
{
    L = sqrt((x - x1) * (x - x1) + (y - y1) * (y - y1));
}
void perpendicular(double a, double b, double c, double P, double& H)
{
    H = (2 * sqrt(P * (P - a) * (P - b) * (P - c))) / c;
}
int testing(double a, double b, double c, double& J)
{
    int cs;
    cs = (b * b + c * c - (a * a)) / 2 * b * c;
    if (cs < 0) {
        J = b;
        return 1;
    }
    cs = (a * a + c * c - (b * b)) / 2 * a * c;
    if (cs < 0) {
        J = a;
        return 1;
    }
    return -1;
}

void proverka(
        double x0,
        double y0,
        double x1,
        double y1,
        double x2,
        double y2,
        double& Perimetr,
        double r,
        bool& okr)
{
    double a, b, c, H, dl, J, Poluper;

    distan(x0, y0, x1, y1, a);
    distan(x0, y0, x2, y2, b);
    distan(x1, y1, x2, y2, c);
    Perimetr = a + b + c;

    Poluper = Perimetr / 2;
    dl = testing(a, b, c, J);
    if (dl == -1) {
        perpendicular(a, b, c, Poluper, H);
        dl = H;

    } else
        dl = J;
    if (dl <= r) {
        okr = true;
    }
}
