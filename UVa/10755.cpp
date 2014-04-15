#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <cmath>
#include <algorithm>
#define INF 1152921504606846976LL

using namespace std;

long long grid[20][20][20], dp[20];

int A, B, C;

long long max3D() {
	long long maxT = -INF;
	for (int a1 = 0; a1 < A; a1++) {
		for (int a2 = a1; a2 < A; a2++) {
			for (int b1 = 0; b1 < B; b1++) {
				memset(dp, 0, sizeof(dp));
				for (int b2 = b1; b2 < B; b2++) {
					for (int a3 = a1; a3 <= a2; a3++) {
						for (int c = 0; c < C; c++) {
							dp[c] += grid[a3][b2][c];
						}
					}

					long long max = -INF, temp = 0;
					for (int k = 0; k < C; k++) {
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
	}
	return maxT;
}

int main() {
	int T;
	bool caso = false;
	scanf("%d", &T);
	while (T--) {
		scanf("%d%d%d", &A, &B, &C);
		for (int i = 0; i < A; i++) {
			for (int j = 0; j < B; j++) {
				for (int k = 0; k < C; k++) {
					scanf("%lld", &grid[i][j][k]);
				}
			}
		}
		if (!caso) caso = true;
		else printf("\n");
		printf("%lld\n", max3D());
	}
}