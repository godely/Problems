#include <cstring>
#include <cstdio>
#include <cstdlib>

using namespace std;

int N;
char tab[110][110];
long long dp[110][110];
int counter = 1;

long long int search(int i, int j) {
	if (dp[i][j] >= 0) return dp[i][j];
	if (i == 0) return dp[i][j] = 1;
	dp[i][j] = 0;
	if (i - 1 >= 0 && j - 1 >= 0) {
		if (tab[i - 1][j - 1] != 'B') {
			dp[i][j] += search(i - 1, j - 1);
		} else {
			if (i - 2 >= 0 && j - 2 >= 0) {
				if (tab[i - 2][j - 2] != 'B') {
					dp[i][j] += search(i - 2, j - 2);
				}
			}
		}
	}
	if (i - 1 >= 0 && j + 1 < N) {
		if (tab[i - 1][j + 1] != 'B') {
			dp[i][j] += search(i - 1, j + 1);
		} else {
			if (i - 2 >= 0 && j + 2 < N) {
				if (tab[i - 2][j + 2] != 'B') {
					dp[i][j] += search(i - 2, j + 2);
				}
			}
		}
	}
	return dp[i][j] %= 1000007;
}

void process() {
	scanf("%d",&N);

	memset(dp,-1,sizeof(dp));

	int pos[2];
	for (int i = 0; i < N; i++) {
		scanf("%s",&tab[i]);
		for (int j = 0; j < N; j++) {
			if (tab[i][j] == 'W') {
				pos[0] = i;
				pos[1] = j;
			}
		}
	}

	printf("Case %d: %d\n", counter++, search(pos[0], pos[1]));
}

int main() {
	int T;
	scanf("%d",&T);
	while (T--) {
		process();
	}

	return 0;
}
