#include <bits/stdc++.h>
using namespace std;
#define fr(a,b,c) for(int a = b; a < c; a++)
#define rp(a,b) fr(a,0,b)

int n;
double t, R[30], C[30];

double f(double r) {
	double k = t - r;
	double mini = 1000000000.0;
	fr(i,1,n) {
		mini = min(mini, r/R[i] + k/C[i]);
	}
	return ((r/R[n] + k/C[n]) - mini)*3600;
}

const double EPS = 1e-8;

int main() {
	while (scanf("%lf", &t) == 1) {
		scanf("%d", &n);
		fr(i,1,n+1) scanf("%lf %lf", &R[i], &C[i]);
		double i = 0.0, j = t, g, h;
		while (fabs(i-j) > EPS) {
			//printf("> %lf %lf\n", i, j);
			g = (j+2*i)/3.0;
			h = (2*j+i)/3.0;
			if (f(g) >= f(h)) i = g;
			else j = h;
		}
		if (f(i) > 0) printf("The cheater cannot win.\n");
		else printf("The cheater can win by %.0lf seconds with r = %.2lfkm and k = %.2lfkm.\n", -f(i), i, t-i);
	}
	return 0;
}
