#include <cstdio>
#include <cstdlib>
#include <algorithm>
#include <vector>
#include <cmath>
#include <map>
#include <set>
#include <iostream>
using namespace std;
#define MP make_pair
typedef pair<int,int> pii;
#define fr(a,b,c) for(int a = b; a < c; a++)
#define rp(a,b) fr(a,0,b)
#define F first
#define S second
#define MOD 1000000007

const double eps = 1e-8;

int cmp(double a, double b = 0) {
	if (fabs(a-b) < eps) return 0;
	else if (a < b) return -1;
	return 1;
}

struct PT {
	double x, y, v;
	PT() {}
	PT(double x, double y) : x(x), y(y) {}

	PT operator-(const PT &q) const { return PT(x-q.x, y-q.y); }
	double operator!() { return sqrt(x*x + y*y); }
} p[100];

int N;
double test2(PT q) {
	double ret = 0;
	rp(i,N) ret = max(ret,(!(p[i]-q))/p[i].v);
	return ret;
}

double test1(double x) {
	double ini = -1e10, fim = 1e10, g, h;
	rp(_,100) {
		g = (2*ini + fim)/3.0;
		h = (ini + 2*fim)/3.0;
		if (test2(PT(x,g)) > test2(PT(x,h))) ini = g;
		else fim = h;
	}
	return test2(PT(x,ini));
}

int main() {
	int T;
	scanf("%d", &T);
	while (T--) {
		scanf("%d", &N);
		double me_x = 1e30, ma_x = -1e30;
		rp(i,N) scanf("%lf%lf%lf", &p[i].x, &p[i].y, &p[i].v), me_x = min(p[i].x, me_x), ma_x = max(p[i].x, ma_x);

		double ini = -1e10, fim = 1e10, g, h;
		rp(_,100) {
			g = (2*ini + fim)/3.0;
			h = (ini + 2*fim)/3.0;
			if (test1(g) > test1(h)) ini = g;
			else fim = h;
		}
		printf("%.6lf\n", test1(ini));
	}
}