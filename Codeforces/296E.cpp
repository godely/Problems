#include <bits/stdc++.h>
using namespace std;
#define Fr(a,b,c) for (int a = b; a < c; a++)
#define Rp(a,b) Fr(a,0,b)
#define LSOne(x) (x&(-x))
typedef long long ll;
#define maxn 60
#define inf 0x3f3f3f3f

int N, K;
int dp[maxn][maxn][maxn][maxn][1];

int solve(int a, int b, int c, int d, int k) {
	if (~dp[a][b][c][d][k]) return dp[a][b][c][d][k];
	if (!a && !b) return dp[a][b][c][d][k] = 0;
	//printf("%d %d %d %d %d\n", a, b, c, d, k);
	dp[a][b][c][d][k] = inf;
	int res = inf;
	if (k == 0) {
		Rp(i,min(a+1,K+1)) {
			int q = (K-i)/2;
			if ((i || q) && q <= b) {
				res = min(res, 1+solve(a-i, b-q, c+i, d+q, 1));
			}
		}
	} else {
		Rp(i,min(c+1,K+1)) {
			int q = (K-i)/2;
			if ((i || q) && q <= d) {
				res = min(res, 1+solve(a+i, b+q, c-i, d-q, 0));
			}
		}
	}
	return dp[a][b][c][d][k] = res;
}

int main() {
	memset(dp,-1,sizeof dp);
	scanf("%d%d", &N, &K);
	K/=50;
	int a = 0, b = 0, p;
	Rp(i,N) {
		scanf("%d", &p);
		if (p == 50) a++;
		else b++;
	}
	printf("%d\n", solve(a,b,0,0,0));
}

