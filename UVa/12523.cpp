//stor
#include <bits/stdc++.h>
using namespace std;
#define fr(a,b,c) for(int a=b;a<c;a++)
#define rp(a,b) fr(a,0,b)
#define cl(a,b) memset((a),(b),sizeof(a))
#define mp make_pair
#define F first
#define S second
#define LL long long
#define pii pair<int, int>

const double EPS = 1e-8;
int sum[111];	
pii upper[111];

bool cmp(pii a, pii b) { return a.F > b.F; }

int main() {
	int S, N, a, b, porc;
	LL res;
	while (scanf("%d%d", &S, &N) == 2 && S > 0) {
		memset(sum,0,sizeof sum);
		res = 0; porc = 100;
		rp(i,S) rp(j,N) scanf("%d", &a), sum[j] += a;
		rp(j,N) {
			scanf("%d%d", &a, &b);
			res += a*sum[j];
			porc -= a;
			upper[j] = mp(sum[j], b-a);
		}
		sort(upper, upper+N, cmp);
		for (int i = 0; i < N && porc > 0; i++) {
			res += min(upper[i].S, porc)*upper[i].F;
			porc -= min(upper[i].S, porc);
		}
		printf("%.2lf\n", (double)res/(100*S) + EPS);
	}
	return 0;
}