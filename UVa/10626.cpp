#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <cmath>
#include <algorithm>

using namespace std;

int C, n[5], totalMoney;
int dp[151][101][51];

int solve(int cokesLeft, int c5, int c10) {
	if (~dp[cokesLeft][c5][c10]) {
		return dp[cokesLeft][c5][c10];
	}
	if (!cokesLeft) {
		return dp[cokesLeft][c5][c10] = 0;
	}

	int moneyLeft = totalMoney - (C-cokesLeft)*8;
	int c1 = moneyLeft-5*c5-10*c10;

	//printf("> 1(%d) + 5(%d) + 10(%d) = %d //// CokesLeft: %d\n", c1, c5, c10, moneyLeft, cokesLeft);
	int ret = 99999999;
	if (c10 >= 1) ret = min(ret, 1+solve(cokesLeft-1, c5, c10-1));
	if (c10 >= 1 && c1 >= 3) ret = min(ret, 4+solve(cokesLeft-1, c5+1, c10-1));
	if (c5 >= 2) ret = min(ret, 2+solve(cokesLeft-1, c5-2, c10));
	if (c5 >= 1 && c1 >= 3) ret = min(ret, 4+solve(cokesLeft-1, c5-1, c10));
	if (c1 >= 8) ret = min(ret, 8+solve(cokesLeft-1, c5, c10));

	return dp[cokesLeft][c5][c10] = ret;
}

int main() {
	int T;
	scanf("%d", &T);
	while (T--) {
		scanf("%d%d%d%d", &C, &n[0], &n[1], &n[2]);
		totalMoney = n[0] + 5*n[1] + 10*n[2];
		memset(dp,-1,sizeof(dp));
		printf("%d\n", solve(C, n[1], n[2]));
	}
}
