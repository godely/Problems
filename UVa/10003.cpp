#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <cmath>
#include <algorithm>
#define inf 0xffffff

using namespace std;

int N, t, cut[100], pd[1111][1111], calc[1111][1111], passo=0;

int solve(int a, int b) {
	if (a >= b) return 0;
	if (calc[a][b] == passo) return pd[a][b];
	calc[a][b] = passo;
	//printf("%d %d\n", a, b);

	int res = inf;
	for (int i = 0; i < t; i++) {
		if (cut[i] >= a && cut[i] < b) {
			res = min(res,(b-a+1)+solve(a,cut[i])+solve(cut[i]+1,b));
		}
	}
	if (res == inf) res = 0;
	return pd[a][b] = res;
}

int main() {
	while (scanf("%d", &N) == 1 && N > 0) {
		passo++;
		scanf("%d", &t);
		for (int i = 0; i < t; i++) scanf("%d", &cut[i]);
		printf("The minimum cutting is %d.\n", solve(1,N));
	}
}
