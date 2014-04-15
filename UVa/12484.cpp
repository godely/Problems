#include <bits/stdc++.h>
using namespace std;
#define MAXN 10100
#define ll long long

int N;
ll vet[MAXN], dp[2][MAXN];

int main() {
	while (scanf("%d", &N) == 1) {
		for (int i = 0; i < N; i++) scanf("%lld", &vet[i]), dp[0][i] = 0;
		
		int a = 0, b = 1;
		for (int k = 1; k < N; k++) {
			if (k&1)
				for (int i = N-k-1; i >= 0; i--)
					dp[b][i] = max(vet[i] + dp[a][i+1], vet[i+k] + dp[a][i]);
			else
				for (int i = N-k-1; i >= 0; i--)
					dp[b][i] = min(dp[a][i+1], dp[a][i]);
			swap(a,b);
		}
		printf("%lld\n", dp[a][0]);
	}
	return 0;
}