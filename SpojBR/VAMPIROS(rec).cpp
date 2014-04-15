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

int mark[30][1010], passo = 0;
double dp[30][1010];

double go(int v1, int k) {
	if (mark[v1][k] == passo) return dp[v1][k];
	mark[v1][k] = passo;
	if (v1 >= EV1+EV2) return dp[v1][k] = 100.0;
	if (!v1) return dp[v1][k] = 0.0;
	if (k > 1000) return dp[v1][k] = 0.0;

	int p = min(EV2+(EV1-v1),D), q = min(v1,D);
	return dp[v1][k] = jog1*go(v1+p,k+1) + jog2*go(v1-q,k+1);
}

int main() {
	while (scanf("%d%d%d%d", &EV1, &EV2, &AT, &D) == 4 && AT > 0) {
		jog1 = (double)AT/6.0;
		jog2 = 1-jog1;
		passo++;
		printf("%.1lf\n", go(EV1,0));
	}
	return 0;
}