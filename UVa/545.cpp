#include <cstdio>
#include <cmath>
using namespace std;

const double EPS = 1e-9;

int main() {
	int T, N;
	scanf("%d", &T);
	while (T--) {
		scanf("%d", &N);
		int M = N;
		double x = 1;
		int c = 0;
		while (M--) {
			x/=2;
			while (x < 1) x*=10, c++;
		}
		printf("2^-%d = %.3lfE-%d\n", N, x+EPS, c);
	}
	return 0;
}