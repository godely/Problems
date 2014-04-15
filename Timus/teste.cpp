#include <bits/stdc++.h>
using namespace std;
#define fr(a,b,c) for(int a = b; a < c; a++)
#define rp(a,b) fr(a,0,b)
typedef long long ll;

bool comp[400];
ll P[500];
int psize = 0;

void sieve() {
	memset(comp,0,sizeof comp);
	for (int i = 2; i <= 305; i++) if (!comp[i]) {
		P[psize++] = i;
		for (int j = i*i; j <= 305; j+=i) comp[j] = 1;
	}
}

ll cnt(int ind, int q, ll num, int A, int K) {
	if (num > A) return 0;
	if (ind >= psize || P[ind] > K+1) {
		int sign = (q&1) ? -1 : 1;
		return sign*(A/num);
	}
	return cnt(ind+1, q, num, A, K) + cnt(ind+1, q+1, num*P[ind], A, K);
}

ll phi2(int n, int k) {
	ll ret = cnt(0, 0, 1, n, k);
	rp(i,psize) if (i < psize && P[i] <= k+1 && P[i] <= n) ret++;
	return ret;
}

int main() {
	sieve();
	int A, B, K;
	while (scanf("%d%d%d", &A, &B, &K) == 3) {
		printf("%lld\n", phi2(A+B,K)-phi2(A,K));
	}
}