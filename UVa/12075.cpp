//SUBMITTED BY STOR
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <cmath>
#include <algorithm>

using namespace std;

int gcd(int a, int b) {
	if (!a || !b || a == b) return max(a, b);
	return gcd(a%b, b%a);
}

int main() {
	int cas = 1, _i, _j;
	unsigned long long qnt, res, M, N, d;
	while (scanf("%llu%llu", &M, &N) == 2 && M) {
		M++;
		N++;
		if (M < N) {
			M+=N;
			N=M-N;
			M-=N;
		}
		qnt = M*N;
		qnt = (qnt*(qnt-1)*(qnt-2))/6 - N*((M*(M-1)*(M-2))/6) - M*((N*(N-1)*(N-2))/6);

		for (int i = 1; i < M; i++) {
			for (int j = 1; j < N; j++) {
				if (gcd(i,j) == 1) {
					d = 1;
					_i = 2*i+1;
					_j = 2*j+1;
					while (_i <= M && _j <= N) {
						qnt -= (unsigned long long)2*d*(M-_i+1)*(N-_j+1);
						d++;
						_i+=i;
						_j+=j;
					}
				}
			}
		}

		printf("Case %d: %llu\n", cas++, qnt);
	}
	return 0;
}
