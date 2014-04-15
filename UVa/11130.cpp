#include <bits/stdc++.h>
using namespace std;

const double PI = acos(-1);

int vert, hori;
double a, b, m, A, s, h, v;
int main() {
	while (scanf("%lf%lf%lf%lf%lf", &a, &b, &m, &A, &s) == 5 && a > 0) {
		A = A*PI/180.0;
		m=m*s/2.0;
		h = cos(A)*m;
		v = sin(A)*m;
		vert = (int)((h+a/2.0)/a);
		hori = (int)((v+b/2.0)/b);
		printf("%d %d\n", vert, hori);
	}
	return 0;
}