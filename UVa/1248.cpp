#include <bits/stdc++.h>
using namespace std;
#define fr(a,b,c) for(int a = b; a < c; a++)
#define rp(a,b) fr(a,0,b)
#define maxn 1011
#define inf 0x3f3f3f3f
#define dbg if(0)

int dp[2][211];
int cost[maxn], maxp[maxn], order[maxn];
int main() {
	int T, N; scanf("%d", &T);
	while (T--) {
		scanf("%d", &N);
		rp(i,N) scanf("%d%d%d", &cost[i], &maxp[i], &order[i]), maxp[i] = min(maxp[i],200);
		
		int a = 0;
		memset(dp,0x3f,sizeof dp);
		dp[0][0] = 0;
		fr(i,0,N) {
			int z = 1 + ((i == 0) ? 0 : maxp[i-1]);
			fr(j,0,201) dp[a^1][j] = inf;
			fr(j,0,z) {
				if (j+maxp[i] >= order[i] && dp[a][j] < inf) {
					int x = max(0,order[i]-j), y = maxp[i]+1;
					fr(k,x,y) {
						dp[a^1][k-x] = min(dp[a^1][k-x], dp[a][j] + k*cost[i]);
dbg						printf("%d %d %d = %d\n", i, j, k, dp[a^1][k-x]);
					}
				}
			}
dbg			puts("");
			a^=1;
		}
		int res = inf;
		fr(i,0,201) res = min(res,dp[a][i]);
		printf("%d\n", res);
	}
	return 0;
}