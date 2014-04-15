#include <bits/stdc++.h>
using namespace std;
#define fr(a,b,c) for(int a = b; a < c; a++)
#define rp(a,b) fr(a,0,b)

int x[20], y[20], z[20];
int a, b, c;

int main() {
	rp(i,16) scanf("%d%d%d", &x[i], &y[i], &z[i]);
	while (scanf("%d%d%d", &a, &b, &c) == 3 && a != -1) {
		double minim = 1000000000.0;
		int q;
		rp(i,16) {
			if (sqrt((a-x[i])*(a-x[i]) + (b-y[i])*(b-y[i]) + (c-z[i])*(c-z[i])) < minim) {
				minim = sqrt((a-x[i])*(a-x[i]) + (b-y[i])*(b-y[i]) + (c-z[i])*(c-z[i]));
				q = i;
			}
		}
		printf("(%d,%d,%d) maps to (%d,%d,%d)\n", a, b, c, x[q], y[q], z[q]);
	}
}