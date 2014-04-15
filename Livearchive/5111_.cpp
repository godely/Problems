#include<iostream>
#include<cstdio>
#include<stdio.h>
#include<stdlib.h>
#include<cstdlib>
#include<math.h>
#include<algorithm>
#include<string>
#include<string.h>
#include<cstring>
#include<map>
#include<vector>
#include<queue>
#include <climits>

using namespace std;

int n, digs[10], dp[101][101][101];


int bt(int d, int a1, int a2, int b1, int b2, int next, int t) {
	if (t >= digs[next]) next++, t = 0;

	while(digs[next] == 0) next++;

	if (dp[d][a1][b1] == -1) {
		if (next > 9) {
			if (b1 != b2) dp[d][a1][b1] = INT_MAX;
			else {
				dp[d][a1][b1] = max(a1, a2-1)*2;
				if (a1 != a2) dp[d][a1][b1]++;
			}
		}

		else {
			dp[d][a1][b1] = INT_MAX;
			dp[d][a1][b1] = min(dp[d][a1][b1], bt(d+1, a1+1, a2, (b1+next)%11, b2, next, t+1));
			dp[d][a1][b1] = min(dp[d][a1][b1], bt(d+1, a1, a2+1, b1, (b2+next)%11, next, t+1));
		}
	}

	return dp[d][a1][b1];

}

int main() {
	// freopen("in.txt","r",stdin);
	scanf("%d", &n);
	while(n--) {
		for (int i = 1; i < 10; i++) scanf("%d", &digs[i]);
		digs[0] = INT_MAX;
		memset(dp, -1, sizeof(dp));
		int resp = bt(0, 0, 0, 0, 0, 1, 0);
		printf("%d\n", (resp < INT_MAX)?(resp):(-1));

	}

	return 0;
}
