#include "geometry.h"

int distan(double x, double y, double x1, double y1, double& L) {
	L = sqrt((x - x1) * (x - x1) + (y - y1) * (y - y1));
	return L;
}

int perpendicular(double a, double b, double c, double P) {
	return (2 * sqrt(P * (P - a) * (P - b) * (P - c))) / c;
}

int testing(double a, double b, double c, double& J) {
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

int proverka(double x0, double y0, double x1, double y1, double x2, double y2,
	     double& Perimetr, double r, bool& okr) {
	double a, b, c, H, dl, J, Poluper;

	distan(x0, y0, x1, y1, a);
	distan(x0, y0, x2, y2, b);
	distan(x1, y1, x2, y2, c);
	Perimetr = a + b + c;

	Poluper = Perimetr / 2;
	dl = testing(a, b, c, J);
	if (dl == -1) {
		perpendicular(a, b, c, Poluper);
		dl = H;

	} else
		dl = J;
	if (dl <= r) {
		okr = true;
	}
}
TEST_CASE("Distan", "[dist]") {
	double L = 0;
	REQUIRE(distan(0, 3, 0, 7, L) == 4);
	REQUIRE(distan(2, 3, 7, 3, L) == 5);
	REQUIRE(distan(5, 6, 5, 1, L) == 5);
	REQUIRE(distan(-2, 0, 2, 0, L) == 4);
	REQUIRE(distan(0, 7, 0, 3, L) == 4);
	REQUIRE(distan(7, 3, 2, 3, L) == 5);
	REQUIRE(distan(5, 1, 5, 6, L) == 5);
	REQUIRE(distan(2, 0, -2, 0, L) == 4);
	cout << "Test distan" << endl;
}
TEST_CASE("perpendicular", "[PERPEND]") {
	REQUIRE(perpendicular(11, 11, 10, 16) == 9);
	REQUIRE(perpendicular(6, 6, 9, 10.5) == 3);
	cout << "Test perpendicular" << endl;
}

TEST_CASE("testing", "[TEST]") {
	double J = 0;
	REQUIRE(testing(1, 2, 3, J) == -1);
	REQUIRE(testing(10, 2, 3, J) == 1);
	cout << "Test function testing" << endl;
}

