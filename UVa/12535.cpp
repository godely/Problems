#include <cstdlib>
#include <cstring>
#include <cstdio>
#include <algorithm>
#include <cmath>
#define fr(a,b,c) for(int a = b; a < c; a++)
#define rp(a,b) fr(a,0,b)
#define LIM 1000100

using namespace std;

long long N, R;
int P[20100];

bool pode(int i, int j) {
	if (j == i) return 0;
	if (P[j] >= P[i]) return P[j]-P[i] <= 180000;
	else return P[i]-P[j] >= 180000;
}

int main() {
	int a, b;
	int cas = 1;
	while (scanf("%lld%*lld", &N) == 1 && N > 0) {
		rp(i,N) scanf("%d.%d", &a, &b), P[i] = a*1000+b;
		sort(P, P+N);
		if (N <= 2) printf("Case %d: 0\n", cas++);
		else {
			long long K = 0;
			for (int i = 0, j = 2; i < N; i++) {
				while (pode(i,j%N)) j++;
				K += (j-i-1)*(j-i-2)/2;
			}
			printf("Case %d: %lld\n", cas++, (N*(N-1)*(N-2))/6 - K);
		}
	}
	return 0;
}