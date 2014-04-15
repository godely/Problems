#include <cstdio>
#include <cstdlib>
#include <cmath>
#include <cstring>
#include <algorithm>
#define fr(a,b,c) for(int a = b; a < c; a++)
#define rp(a,b) fr(a,0,b)
using namespace std;

const double pi = acos(-1);
const double EPS = 1e-7;

int T;
double a, b;
double f(double k) {
	return a*sin(k) + b*cos(k);
}

int main() {
	double resA, resB;
	scanf("%d", &T);
	while (T--) {
		scanf("%lf%lf", &a, &b);
		double k = atan2(a,b);
		if (k < 0) k+=2*pi;
		if (f(k+(pi/2)) > f(k)) {
			k+=pi/2;
			if (k > 2*pi) k-=2*pi;
		}
		printf("%.2lf %.2lf\n", k, f(k));
	}
	return 0;
}