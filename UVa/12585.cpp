#include <cstdio>
#include <cmath>
#include <algorithm>
using namespace std;

typedef pair<double,double> pii;
pii dp[305][100];
int s, mark[305][100], passo = 0;
pii solve(int a, int k) {
	int b = s-a;
	if (!a || !b || k >= 100) {
		if (!b) return pii(1,0);
		else return pii(0,0);
	}
	if (mark[a][k] == passo) return dp[a][k];
	mark[a][k] = passo;
	int c = min(a,b);
	pii aux1 = solve(a+c,k+1);
	pii aux2 = solve(a-c,k+1);
	return dp[a][k] = pii(0.5*aux1.first + 0.5*aux2.first, 0.5*(1 + aux1.second) + 0.5*(1 + aux2.second));
}

int main() {
	int T, a, b, cas = 1;
	scanf("%d", &T);
	while (T--) {
		scanf("%d%d", &a, &b);
		s = a + b;
		passo++;
		pii aux = solve(a,0);
		printf("Case %d: %.6lf %.6lf\n", cas++, aux.second, aux.first);
	}
	return 0;
}