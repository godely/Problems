#include <bits/stdc++.h>
using namespace std;
#define fr(a,b,c) for(int a = b; a < c; a++)
#define rp(a,b) fr(a,0,b)

const double EPS = 1e-3;
double a[10], b[10];
int P[10], N;

bool f(double k) {
	double st = a[P[0]];
	rp(i,N) {
		if (b[P[i]] < st) return 0;
		if (a[P[i]] > st) st = a[P[i]]+k;
		else st += k;
	}
	return 1;
}

int main() {
	int cas = 1;
	double maximo, ini, fim, meio;
	int x, y;
	while (scanf("%d", &N) == 1 && N > 0) {
		rp(i,N) scanf("%d%d", &x, &y), a[i]=(double)(x*60), b[i]=(double)y*60, P[i] = i;
		maximo = 0;
		do {
			ini = 0, fim = 86400, meio;
			while (fabs(fim-ini) > EPS) {
				meio = (ini+fim)/2.0;
				if (f(meio)) ini = meio;
				else fim = meio;
			}
			maximo = max(maximo, ini);
		} while(next_permutation(P,P+N));
		int res = (int)(maximo+0.5);
		printf("Case %d: %d:%.2d\n", cas++, res/60, res%60);
	}
	return 0;
}