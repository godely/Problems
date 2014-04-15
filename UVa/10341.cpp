#include <bits/stdc++.h>
using namespace std;

const double EPS = 1e-8;

int p, q, r, s, t, u;
double f(double x) {
	return (p*exp(-x) + q*sin(x) + r*cos(x) + s*tan(x) + t*x*x + u);
}

int main() {
	while (scanf("%d%d%d%d%d%d", &p, &q, &r, &s, &t, &u) == 6) {
		double ini = 0.0, fim = 1.0, meio;
		if (f(0)*f(1) > 0) printf("No solution\n");
		else {
			while (fabs(ini-fim) > EPS) {
				meio = (ini+fim)/2;
				if (f(ini)*f(meio) > 0) ini = meio;
				else fim = meio;
			}
			printf("%.4lf\n", ini);
		}
	}
	return 0;
}