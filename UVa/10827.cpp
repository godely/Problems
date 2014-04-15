#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <cmath>
#include <algorithm>

using namespace std;

int grid[110][110], grid2[110][110], dp[110];

int N;

int max2D() {
	int maxT = 0;
	
	for (int grau = 0; grau < N; grau++) {
		for (int i = 0; i < N; i++) {
			memset(dp, 0, sizeof(dp));
			for (int j = i; j < N+i; j++) {
				for (int k = 0; k < N; k++) {	
					dp[k] += grid[j%N][(k+grau)%N];
				}
				int max = 0, temp = 0;
				for (int k = 0; k < N; k++) {
					temp += dp[k];
					if (temp > max)
						max = temp;
					if (temp < 0)
						temp = 0;
				}
				if (max > maxT) maxT = max;
			}
		}
	}
	return maxT;
}

int main() {
	int T, maxlol = 0;
	scanf("%d", &T);
	while (T--) {
		scanf("%d", &N);
		for (int i = 0; i < N; i++) {
			for (int j = 0; j < N; j++) {
				scanf("%d", &grid[i][j]);
				grid2[j][i] = grid[i][j];
			}
		}
		printf("%d\n", max2D());
	}
}