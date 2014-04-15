
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <cmath>
#include <algorithm>

using namespace std;

int ord[250*250+20], P[250*250+20], pd[250*250+20];

int N;

int solve() {
	int m = 0, K;
	for (int i = 0; i < N; i++) {
		K = upper_bound(pd, pd+m, P[i]) - pd;
		if (K == m) m++;
		pd[K] = P[i];
	}
	return m;
}

int main() {
	int T, a, n, p, q, cas=1;
	scanf("%d", &T);
	while (T--) {
		scanf("%d%d%d", &n, &p, &q);
		memset(ord, -1, sizeof ord);
		for (int i = 0; i <= p; i++) {
			scanf("%d", &a);
			ord[a] = i;
		}
		N = 0;
		for (int i = 0; i <= q; i++) {
			scanf("%d", &a);
			if (ord[a] != -1) P[N++] = ord[a];
		}
		printf("Case %d: %d\n", cas++, solve());
	}
}
