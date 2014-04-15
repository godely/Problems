#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <cassert>
#include <vector>
#include <algorithm>
#include <iostream>
using namespace std;
#define fr(a,b,c) for (int a = b; a < c; a++)
#define rp(a,b) fr(a,0,b)
#define MOD 1000000007

int N, K;
int dp[2010][2010];

int go(int i, int k) {
	int &pd = dp[i][k];
	if (~pd) return pd;
	if (k == 0) return pd = 1;

	int j = i, ans = 0;
	while (j <= N) {
		ans = (ans+go(j,k-1))%MOD;
		j += i;
	}
	return pd = ans;
}

int main() {
	memset(dp,-1,sizeof dp);
	scanf("%d%d", &N, &K);
	int ans = 0;
	fr(i,1,N+1) {
		ans = (ans+go(i,K-1))%MOD;
	}
	printf("%d\n", ans);
}