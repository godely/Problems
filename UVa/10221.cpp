#include <bits/stdc++.h>
using namespace std;

const double pi = acos(-1);

double r, y;
char c[100];
int main() {
	while (scanf("%lf%lf%s", &r, &y, c) == 3) {
		if (c[0] == 'm') y /= 60;
		if (y > 180) y = 360-y;
		printf("%.6lf %.6lf\n", pi*(r+6440)*y/180.0, sqrt(2*(r+6440)*(r+6440)*(1-cos(y*pi/180))));
	}
	return 0;
}