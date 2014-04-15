#include <cstdio>
#include <cstdlib>
#include <cstring>

using namespace std;

int p[111111], k = 0;
bool isPrimo[111111];

long long fastExp(int n, int exp) {
	if (exp == 0) return 1;

	long long aux = fastExp(n, exp/2);
	aux = (aux*aux)%10000019;
	if (exp&1) aux = ((long long)aux*n)%10000019;
	return aux;
}

int main() {
	memset(isPrimo, 1, sizeof isPrimo);
	for (int i = 2; i <= 100000; i++) {
		if (isPrimo[i]) {
			p[k++] = i;
			for (long long j = (long long)i*i; j <= 100000; j+=i) {
				isPrimo[j] = 0;
			}
		}
	}

	int T, N, t, cas = 1;
	scanf("%d", &T);
	while (T--) {
		scanf("%d%d", &N, &t);
		long long res = 1;
		int temp, m;
		for (int i = 0; p[i] <= N && i < k; i++) {
			temp = 0;
			m = N;
			while (m > 0) {
				m/=p[i];
				temp+=m;
			}
			res = ((long long)res*fastExp(p[i], temp/t))%10000019;
		}
		printf("Case %d: %lld\n", cas++, (res > 1) ? res : -1);
	}
}
