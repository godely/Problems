#include <bits/stdc++.h>
#define fr(a,b,c) for(int a=b; a<c; a++)
#define ifr(a,b,c) for(int a=b; a>=c; a--)
#define rp(a,b) fr(a,0,b)
#define mp make_pair
#define F first
#define S second
using namespace std;

typedef pair<int,int> pii;

int n, k;
int g[511][511], sum1[511], sum2[511][511];
int dp[511][511], pai[511][511];
int glob;

int go(int x, int y, int z, int cap) {
	if (x == z && (~dp[x][y])) return dp[x][y];
	if (x == z) pai[x][y] = -1;
	if (x == n) {
		if (y > 0) cap = 0;
		if (x == z) dp[x][y] = cap;
		return cap;
	}
	int ret = 0, to = -1;
	if (y > 0) {
		ret = go(x+1,y-1,x+1,0) + cap + sum1[x];
		to = x+1;
		if (x == z) pai[x][y] = to;
	}
	if (go(x+1,y,x+1,0) + cap + sum1[x] > ret) {
		int ret2 = go(x+1,y,z,cap+sum1[x]-sum2[z][x+1]);
		if (ret2 > ret) {
			ret = ret2;
			to = glob;
			if (x == z) pai[x][y] = to;
		}
	}
	glob = to;
	if (x == z) dp[x][y] = ret;
	return ret;
}

int main() {
	memset(sum1,0,sizeof sum1);
	memset(sum2,0,sizeof sum2);
	scanf("%d%d", &n, &k);
	fr(i,0,n-1) {
		fr(j,i+1,n) {
			scanf("%d", &g[i][j]);
			sum1[i] += g[i][j];
		}
	}
	fr(i,1,n) ifr(j,i-1,0) sum2[j][i] = sum2[j+1][i] + g[j][i];
	
	memset(dp,-1,sizeof dp);
	printf("%d\n", go(0,k,0,0));
	bool ok = 0;
	int at = pai[0][k];
	printf("%d", at);
	for(int i = 1; i < k; ++i){
		at = pai[at][k-i];
		printf(" %d", at);
	}
	printf("\n");
}