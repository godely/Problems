#include <bits/stdc++.h>
using namespace std;

struct matriz {
	double a, b, c, d;
	matriz() {}
	matriz(double a, double b, double c, double d) : a(a), b(b), c(c), d(d) {}
	matriz operator*(const matriz &lhs) const { return matriz(a*lhs.a+b*lhs.c, a*lhs.b+b*lhs.d, c*lhs.a+d*lhs.c, c*lhs.b+d*lhs.d); }
} expo, res;

int main() {
	int T, K, cas = 1;
	double N, M, P, Pe, ret;
	scanf("%d", &T);
	while (T--) {
		scanf("%lf%lf%lf%d", &N, &M, &P, &K);
		ret = 0;
		for (int x = 1; x <= N; x++) {
			for (int y = 1; y <= M; y++) {
				for (int z = 1; z <= P; z++) {
					Pe = (x*(N-x+1) + (N-x+1)*x - 1)/(N*N) * (y*(M-y+1) + (M-y+1)*y - 1)/(M*M) * (z*(P-z+1) + (P-z+1)*z - 1)/(P*P);
					expo = matriz(1-Pe, Pe, Pe, 1-Pe);
					//printf("%d %d %d %lf: ", x, y, z, Pe);
					res = matriz(1,0,0,1);
					for(int k = K; k; k>>=1, expo=expo*expo) if (k&1) res=res*expo;
					//printf("a:%lf b:%lf c:%lf d:%lf\n", res.a, res.b, res.c, res.d);
					ret += res.b;
				}
			}
		}
		printf("Case %d: %.10lf\n", cas++, ret);
	}
	return 0;
}