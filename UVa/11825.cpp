#include <bits/stdc++.h>
using namespace std;
#define fr(a,b,c) for(int a = b; a < c; a++)
#define rp(a,b) fr(a,0,b)
#define MAXM 1000
#define LS(x) (x&-x)
//#define add(a,b) to[z] = b, ant[z] = adj[a], adj[a] = z++
//int to[MAXM], ant[MAXM], adj[MAXM], z;
int S[1<<16], dp[1<<16];

int main () {
	int N, m, mask, a, cas = 1;
	while (scanf("%d", &N) == 1 && N > 0) {
		memset(dp,0,sizeof dp);
		rp(i,N) {
			scanf("%d", &m);
			mask = (1<<i);
			rp(j,m) {
				scanf("%d", &a);
				mask |= (1<<a);
			}
			S[1<<i] = mask;
		}
		int LIM = (1<<N);
		fr(i,1,LIM) {
			int s = i, mask = 0;
			while (s > 0) {
				mask |= S[LS(s)];
				s-=LS(s);
			}
			if (mask == LIM-1) dp[i] = 1;
		}
		fr(i,1,LIM) {
			for (int j = (i-1)&i; j; j = (j-1)&i) {
				dp[i] = max(dp[i], dp[j]+dp[i-j]);
			}
		}
		printf("Case %d: %d\n", cas++, dp[LIM-1]);
	}
	return 0;
}