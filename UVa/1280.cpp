#include <bits/stdc++.h>
using namespace std;

int N;
double a[30], b[30];
double low, high, inc, vol, klow;
const double PI = acos(-1);
const double EPS = 1e-7;

double integral(double x) {
	double res = 0.0;
	for (int i = 2*N; i >= 0; i--) {
		res *= x;
		res += (double)b[i]/(i+1);
	}
	res *= x;
	return res - klow;
}

int main() {
	int cas = 1;
	while (scanf("%d", &N) == 1) {
		for (int i = 0; i <= N; i++) scanf("%lf", &a[i]), b[i] = b[i+N+1] = 0.0;
		for (int i = 0; i <= N; i++) {
			for (int j = 0; j <= N; j++) {
				b[i+j] += a[i]*a[j];
			}
		}
		scanf("%lf%lf%lf", &low, &high, &inc);
		klow = 0; klow = integral(low);
		vol = PI*integral(high);
		printf("Case %d: %.2lf%c", cas++, vol, 10);
		if (inc >= vol) printf("insufficient volume\n");
		else {
			double t = inc;
			for (int i = 0; i < 8 && t < vol; i++) {
				double ini = low, fim = high, meio;
				while (fabs(ini-fim) > EPS) {
					meio = (ini+fim)/2.0;
					if (PI*integral(meio) > t) fim = meio;
					else ini = meio;
				}
				if (i) printf(" %.2lf", ini-low);
				else printf("%.2lf", ini-low);
				t += inc;
			}
			printf("\n");
		}
	}
	return 0;
}