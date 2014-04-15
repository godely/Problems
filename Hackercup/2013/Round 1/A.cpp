#include <bits/stdc++.h>
using namespace std;
#define fr(a,b,c) for(int a = b; a < c; a++)
#define rp(a,b) fr(a,0,b)
#define mod 1000000007
long long C[10100][10100];

void comb() {
	fr(i,0,10001) C[i][0] = 1;
	fr(i,1,10001) fr(j,1,i+1) C[i][j] = (C[i-1][j-1] + C[i-1][j])%mod;
}

bool cmp(int a, int b) {
	return a > b;
}

long long V[10100];
int main() {
	comb();
	int T, N, K, cas = 1;
	scanf("%d", &T);
	while (T--) {
		scanf("%d%d", &N, &K);
		rp(i,N) scanf("%d", &V[i]);
		sort(V,V+N,cmp);
		long long sum = 0;
		rp(i,N-K+1) {
			sum = (sum+(V[i]*C[N-i-1][K-1])%mod)%mod;
		}
		printf("Case #%d: %lld\n", cas++, sum);
	}
}