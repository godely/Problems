#include <bits/stdc++.h>
using namespace std;
#define fr(a,b,c) for(int a = b; a < c; a++)
#define rp(a,b) fr(a,0,b)

int N, C, T1, T2, dp[1111], x[1111];
int go(int i) {
	if (~dp[i]) return dp[i];
	if (i >= N) return dp[i] = 0;
	
	int l1 = upper_bound(x+i,x+N,x[i]+T1)-x;
	int l2 = upper_bound(x+i,x+N,x[i]+T2)-x;
	return dp[i] = min(T1+go(l1),T2+go(l2));
}

int main() {
	while (scanf("%d%d%d%d", &N, &C, &T1, &T2) == 4) {
		rp(i,N) scanf("%d", &x[i]);
		sort(x,x+N);
		memset(dp,-1,sizeof dp);
		printf("%d\n", go(0));
	}
	return 0;
}