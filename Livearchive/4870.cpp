#include <bits/stdc++.h>
using namespace std;
#define fr(a,b,c) for(int a = b; a < c; a++)
#define rp(a,b) fr(a,0,b)
#define inf 0x3f3f3f3f

int dp[2][20100], N, K, L, F, D;
int main() {
	int s, a, res;
	while (scanf("%d%d%d", &N, &K, &L) == 3 && N > 0) {
		memset(dp, inf, sizeof dp);
		dp[0][0] = 0;
		s = a = 0;
		while(N--) {
			scanf("%d%d", &F, &D);
			s += F;
			rp(j,s+1) {
				if (dp[a][j] <= L) dp[a^1][j] = max(dp[a][j]-K,0);
				if (j >= F) dp[a^1][j] = min(dp[a^1][j], dp[a][j-F]+D);
			}
			a=1-a;
		}
		res = 0;
		for (int i = s; i >= 0; i--) {
			if (dp[a][i] <= L) {
				res = i;
				break;
			}
		}
		printf("%d\n", res);
	}
	return 0;
}