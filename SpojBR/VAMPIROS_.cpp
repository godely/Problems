#include <bits/stdc++.h>
#define fr(a,b,c) for(int a=b; a<c; a++)
#define ifr(a,b,c) for(int a=b; a>=c; a--)
#define rp(a,b) fr(a,0,b)
#define mp make_pair
#define F first
#define S second
using namespace std;

int EV1, EV2, AT, D;
double jog1, jog2;
double p[30];

int cmp(double a, double b = 0) {
	if (fabs(a-b) < 1e-6) return 0;
	if (a < b) return -1;
	return 1;
}

int main() {
	while (scanf("%d%d%d%d", &EV1, &EV2, &AT, &D) == 4 && AT > 0) {
		jog1 = (double)AT/6.0;
		jog2 = 1-jog1;
		
		int s = EV1+EV2;
		rp(i,s+1) p[i] = 0.0;
		p[EV1] = 1.0;
		while (cmp(p[0]+p[s],1) < 0) {
			fr(i,1,s) {
				int x = min(s-i,D), y = min(i,D);
				p[i+x] += jog1*p[i];
				p[i-y] += jog2*p[i];
				p[i] = 0.0;
			}
		}
		printf("%.1lf\n", p[s]*100.0);
	}
	return 0;
}