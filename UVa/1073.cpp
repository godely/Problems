#include <bits/stdc++.h>
using namespace std;
#define fr(a,b,c) for(int a = b; a < c; a++)
#define rp(a,b) fr(a,0,b)

int F[1010];
void crivofat() {
	memset(F, 0, sizeof F);
	F[1] = 1;
	for (int i = 2; i <= 1000; i++)
		for (int j = i; j <= 1000; j += i) if (!F[j]) F[j] = i;
}

int fat[1010];
long long comb(int c, int b) {
	memset(fat,0,sizeof fat);
	for (int i = 2; i <= c; i++) {
		int k = i;
		while (k != 1) fat[F[k]]++, k /= F[k];
	}
	int lim = max(b,c-b);
	int men = min(b,c-b);
	for (int i = 2; i <= lim; i++) {
		int k = i;
		while (k != 1) fat[F[k]]-=(1+(i<=men)), k /= F[k];
	}
	long long res = 1;
	for (long long i = 2; i <= c; i++) rp(j,fat[i]) res*=i;
	return res;
}

int main() {
	crivofat();
	int N, cas = 1;
	while (scanf("%d", &N) == 1 && N > 0) {
		printf("Case %d: ", cas++);
		if (N&1) printf("0\n");
		else if (N == 4) printf("1\n");
		else if (N == 6) printf("6\n");
		else {
			N/=2;
			printf("%lld\n", comb(N+3, N-2) - comb(N+1,N-4));
		}
	}
	return 0;
}