#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <cmath>
#include <algorithm>
#include <iostream>

using namespace std;

char a[80], b[80];
int dp[62][62][62][62];

int lp(int i1, int j1, int i2, int j2) {
	//printf("%d %d %d %d\n", i1, j1, i2, j2);
	if (j1 < i1 || j2 < i2) return 0;
	if (~dp[i1][j1][i2][j2]) return dp[i1][j1][i2][j2];

	if (a[i1] == a[j1] && a[i1] == b[i2] && a[j1] == b[j2]) {
		int ad = min((i1 != j1) + 1, (i2 != j2) + 1);
		return dp[i1][j1][i2][j2] = ad + lp(i1+1, j1-1, i2+1, j2-1);
	} else {
		return dp[i1][j1][i2][j2] = max(lp(i1+1, j1, i2, j2), max(lp(i1, j1-1, i2, j2), max(lp(i1, j1, i2+1, j2), lp(i1, j1, i2, j2-1))));
	}
}

int main() {
	int T, sizeA, sizeB;
	cin >> T;
	int cas = 1;
	while (T--) {
		scanf("%s%s", a, b);
		sizeA = strlen(a);
		sizeB = strlen(b);
		for (int i = 0; i < sizeA; i++) {
			for (int j = 0; j < sizeA; j++) {
				for (int k = 0; k < sizeB; k++) {
					for (int w = 0; w < sizeB; w++) {
						dp[i][j][k][w] = -1;
					}
				}
			}
		}
		printf("Case %d: %d\n", cas++, lp(0, sizeA-1, 0, sizeB-1));
	}
}
