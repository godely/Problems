#include <cstdio>
#include <cstdlib>
#include <algorithm>
#include <vector>
#include <cmath>
#include <map>
#include <set>
#include <iostream>
#include <cstring>
#include <queue>
using namespace std;
#define MP make_pair
typedef pair<int,int> pii;
#define fr(a,b,c) for(int a = b; a < c; a++)
#define rp(a,b) fr(a,0,b)
#define cl(a,b) memset(a,b,sizeof a)
#define cl(a,b) memset(a,b,sizeof a)
#define F first
#define S second

int N, C;
int x[210];
double dp[210][210];
double pc[210][210];


/*int mark[210][210], passo;

double go(int i, int h) {
	double &pd = dp[i][h];
	if (mark[i][h] == passo) return pd;
	if (i >= N) return pd = 0;
	if (h == 0) return pd = 1e10;
	
	
	double ans = pc[i][N-1] + go(N,h-1);
	for (int j = i+1; j < N; j++) {
		ans = min(ans, pc[i][j] + go(j,h-1));
		//printf("%d %d %d > %lf\n", i, h, j, ans);
	}
	return pd = ans;
}*/

int main() {
	//passo = 0;
	int T; scanf("%d", &T);
	while (T--) {
		scanf("%d%d", &N, &C);
		rp(i,N) scanf("%d", &x[i]);
		fr(i,0,N) {
			pc[i][i] = 0.0;
			fr(j,i+1,N) {
				pc[i][j] = 0.0;
				fr(k,i+1,j) {
					pc[i][j] += fabs(x[k] - fabs(x[i] + double((x[j] - x[i]) * (double(k - i) / double(j - i) ))))/double(N);
				}
			}
			fr(k,0,C) dp[i][k] = 1e10;
		}
		dp[N-1][0] = 0;
		
		double pd;
		for (int i = N-2; i >= 0; i--) {
			for (int k = 1; k < C; k++) {
				pd = 1e10;
				for (int j = i+1; j < N; j++) {
					pd = min(pd, pc[i][j] + dp[j][k-1]);
				}
				dp[i][k] = pd;
			}
		}
		printf("%.4lf\n", dp[0][C-1]);
	}
	return 0;
}