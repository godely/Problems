#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <cmath>
#include <algorithm>
#include <stack>

using namespace std;

int P[10000000], N=0, pd[10000000], pos[10000000], volta[10000000];

int solve() {
	int m = 0, K;
	for (int i = 0; i < N; i++) {
		K = lower_bound(pd, pd+m, P[i]) - pd;
		if (K == m) m++;
		pd[K] = P[i];
		pos[K] = i;
		if (K==0) volta[i] = -1;
		else volta[i] = pos[K-1];
	}
	return m;
}

int main() {
	int a;
	while (scanf("%d", &a)==1) {
		P[N++]=a;
	}
	int l = solve();
	printf("%d\n-\n", l);

	stack<int> lol;
	int h = pos[l-1];
	while (true) {
		lol.push(P[h]);
		h = volta[h];
		//printf("%d\n", h);
		if (h == -1) break;
	}
	while (!lol.empty()) {
		printf("%d\n", lol.top());
		lol.pop();
	}

	return 0;
}
