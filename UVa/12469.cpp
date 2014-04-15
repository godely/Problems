#include <bits/stdc++.h>
using namespace std;
#define fr(a,b,c) for(int a=b; a<c; a++)
#define rp(a,b) fr(a,0,b)
#define cl(a,b) memset(a, b, sizeof(a))
#define LL long long

int N, dp[1111][2222];
bool isWinning(int rest, int jog) {
	if (~dp[rest][jog]) return dp[rest][jog];
	if (rest == 0) return dp[rest][jog] = 0;
	for (int i = 1; i <= rest && i <= jog; i++) {
		if (!isWinning(rest-i, 2*i)) return dp[rest][jog] = 1;
	}
	return dp[rest][jog] = 0;
}

int main() {
	memset(dp,-1,sizeof dp);
	while (scanf("%d", &N) == 1 && N > 0) {
		if (isWinning(N,N-1)) printf("Alicia\n");
		else printf("Roberto\n");
	}
	return 0;
}
