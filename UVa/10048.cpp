#include <bits/stdc++.h>
#define fr(a,b,c) for(int a=b;a<c;a++)
#define rp(a,b) fr(a,0,b)
#define LL long long
#define MAXN 1000010
#define inf 2147483647

using namespace std;

long long cost[111][111];
int c, s, q;
long long ff() { rp(k,c) rp(i,c) rp(j,c) cost[i][j] = cost[j][i] = min(cost[i][j], max(cost[i][k], cost[k][j])); }

int main() {
	int a, b, d, cas = 1;
	bool ok = 0;
	while (scanf("%d%d%d", &c, &s, &q)==3 && (c+s+q)>0) {
		if (ok) printf("\n");
		else ok = 1;
		rp(i,c+1) rp(j,c+1) cost[i][j]=inf;
		rp(i,s) {
			scanf("%d%d%d", &a, &b, &d);
			cost[a-1][b-1]=cost[b-1][a-1]=d;
		}
		ff();
		printf("Case #%d\n", cas++);
		rp(i,q) {
			scanf("%d %d", &a, &b);
			if (cost[a-1][b-1]<inf) printf("%lld\n", cost[a-1][b-1]);
			else printf("no path\n");
		}
	}
	return 0;
}