#include <bits/stdc++.h>
using namespace std;
#define fr(a,b,c) for(int a = b; a < c; a++)
#define rp(a,b) fr(a,0,b)
typedef long long ll;

int go(int N, ll y, ll x) {
	if (N == 0) return 1;
	else {
		ll half = (1LL<<(N-1));
		int sign = 1;
		if (y >= half && x >= half) sign = -1;
		if (y >= half) y -= half;
		if (x >= half) x -= half;
		return sign*go(N-1,y,x);
	}
}

int main() {
	int N;
	ll R, S, E;
	while (scanf("%d%lld%lld%lld", &N, &R, &S, &E) == 4 && N >= 0) {
		int s = 0;
		for(long long i = S; i <= E; i++) {
			s += go(N,R,i);
		}
		printf("%d\n", s);
	}
	return 0;
}