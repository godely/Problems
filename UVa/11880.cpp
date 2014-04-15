#include <bits/stdc++.h>
using namespace std;
#define inf 0x3f3f3f3f

const double pi = acos(-1);

int L, W, x, y, R, a, v, t, p, q;
double s, O, y_, x_;
int main() {
	while (scanf("%d%d%d%d%d%d%d%d", &L, &W, &x, &y, &R, &a, &v, &t) == 8 && L > 0) {
		L -= 2*R; W -= 2*R;
		x -= R; y -= R;
		s = (double)v*t;
		O = (double)a*pi/180.0;
		x_ = s*cos(O) + x;
		y_ = s*sin(O) + y;
		p = (int)fmod(floor(fabs(x_)/L),2);
		q = (int)fmod(floor(fabs(y_)/W),2);
		x_ = fmod(fabs(x_), L);
		y_ = fmod(fabs(y_), W);
		if (p&1) x_ = L - x_;
		if (q&1) y_ = W - y_;
		printf("%.2lf %.2lf\n", x_+R, y_+R);
	}
	return 0;
}