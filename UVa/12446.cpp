#include <bits/stdc++.h>
using namespace std;
#define fr(a,b,c) for(int a=b; a<c; a++)
#define rp(a,b) fr(a,0,b)
#define cl(a,b) memset(a, b, sizeof(a))
#define inf 1000000000000000LL
#define LL long long
#define mod 1000000007LL

/*LL solve(int ind, int state) {
	if (ind >= N) return state == 0;
	if (calc[ind][state]==passo) return dp[ind][state];
	calc[ind][state] = passo;

	if (state==0) {
		LL r1 = solve(ind+1,0);
		LL r2 = solve(ind+1,1);
		LL r3 = solve(ind+1,2);
		return dp[ind][state] = (2*r1+r2+4*r3)%mod;
	} else if (state==1) {
		return dp[ind][state] = solve(ind+1,0)%mod;
	} else {
		LL r1 = solve(ind+1,0);
		LL r2 = solve(ind+1,1);
		return dp[ind][state] = (r1+r2)%mod;
	}
}*/

LL dp[1000011][4];
int main() {
	int T, N;
	scanf("%d", &T);

	dp[0][0] = 1;
	dp[0][1] = 0;
	dp[0][2] = 0;
	for (int i = 1; i <= 1000000; i++) {
		dp[i][0] = (2*dp[i-1][0] + dp[i-1][1] + 4*dp[i-1][2])%mod;
		dp[i][1] = dp[i-1][0]%mod;
		dp[i][2] = (dp[i-1][0]+dp[i-1][2])%mod;
	}
	while (T--) {
		scanf("%d", &N);
		printf("%lld\n", dp[N][0]);
	}
	return 0;
}
