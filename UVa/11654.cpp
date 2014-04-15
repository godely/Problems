#include <cstdio>
#include <cstdlib>
#include <algorithm>
#include <vector>
#include <cmath>
#include <map>
#include <set>
#include <iostream>
#include <cstring>
using namespace std;
#define fr(a,b,c) for(int a = b; a < c; a++)
#define rp(a,b) fr(a,0,b)
#define MAXN 1100
#define F first
#define S second
#define MP make_pair
#define MOD 10000007
typedef pair<int,int> pii;

int T, N, x[300];
pii y[300];

int dp[300][300];

int main() {
	int cas = 1;
	scanf("%d", &T);
	while (T--) {
		scanf("%d", &N);
		rp(i,N) scanf("%d", &x[i]), y[i] = MP(x[i],i);
		x[N] = -1;
		sort(y,y+N);

		int res = N;
		for (int i = N-1; i >= 0; i--) {
			for (int j = N-1; j > i; j--) {
				dp[i][j] = 1;
				int p = x[j]+x[j]-x[i];
				int k = lower_bound(y,y+N,MP(p,j+1)) - y;
				for (; k < N && y[k].F == p; k++) {
					dp[i][j] = (dp[i][j]+dp[j][y[k].S])%MOD;
				}
				//printf("%d %d %d\n", i, j, dp[i][j]);
				res = (res+dp[i][j])%MOD;
			}
		}
		printf("Case %d: %d\n", cas++, res);
	}
}