#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <cmath>
#define INF 0xfff

using namespace std;

int N;
int grid[110][110];
int dp[110];

int max2D() {
	int res = -INF;
	for (int i = 0; i < N; i++) {
		memset(dp,0,sizeof(dp));
		for (int k = i; k < N; k++) {
			for (int j = 0; j < N; j++) {
				dp[j] += grid[k][j];
			}
			int temp = 0, max = -INF;
			for (int j = 0; j < N; j++) {
				temp += dp[j];
				if (temp > max) {
					max = temp;
				}
				if (temp < 0) {
					temp = 0;
				}
			}
			if (max > res) res = max;
		}
	}
	return res;
}

int main() {
	scanf("%d", &N);
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < N; j++) {
			scanf("%d", &grid[i][j]);
		}
	}
	printf("%d\n", max2D());
}
