#include <bits/stdc++.h>
using namespace std;
#define fr(a,b,c) for(int a = b; a < c; a++)
#define rp(a,b) fr(a,0,b)
typedef long long ll;

bool comp[400];
ll P[500];
int psize = 0;
int A, B, K;

void sieve() {
	memset(comp,0,sizeof comp);
	for (int i = 2; i <= 305; i++) if (!comp[i]) {
		P[psize++] = i;
		for (int j = i*i; j <= 305; j+=i) comp[j] = 1;
	}
}

ll res;
void cnt(int ind, bool q, ll num) {
	if (ind == psize || P[ind] > K+1 || num*P[ind] > A+B) return;

	int sign = (q&1) ? -1 : 1;
	res += sign * ((A+B)/(num*P[ind]) - A/(num*P[ind]));

	cnt(ind+1, q, num);
	cnt(ind+1, q^1, num*P[ind]);
}

void phi2() {
	res = B;
	cnt(0,1,1);
	rp(i,psize) if (P[i] <= K+1 && P[i] <= A+B && P[i] > A) res++;
}

int main() {
	sieve();
	scanf("%d%d%d", &A, &B, &K);
	phi2();
	printf("%lld\n", res);
}