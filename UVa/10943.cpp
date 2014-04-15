#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <cmath>

using namespace std;

int pd[101][101];

int N, K;
int solve(int k, int sum) {
	if (sum > N) return 0;
	if (k == 0) {
		return sum == N;
	}
	if (~pd[k][sum]) return pd[k][sum];

	int res = 0;
	for (int i = 0; i <= N; i++) {
		res = (res+solve(k-1, sum+i))%1000000;
	}
	return pd[k][sum] = res;
}

int main(){
	while (scanf("%d%d", &N, &K) > 0 && N > 0) {
		memset(pd, -1, sizeof pd);
		printf("%d\n", solve(K, 0));
	}
	return 0;
}
