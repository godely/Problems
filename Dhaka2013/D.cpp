#include <bits/stdc++.h>
using namespace std;
#define mod 10000000000007LL

typedef long long ll;


ll mulmod(ll a, ll b, ll c) {
	ll x = 0, y=a%c;
	while(b > 0){
		if(b&1){
			x = (x+y)%c;
		}
		y = (y<<1)%c;
		b >>= 1;
	}
	return x%c;
}

void inv(ll a, ll b, ll &x, ll &y, ll &d) {
	if (!b) x = 1, y = 0, d = a;
	else {
		inv(b,a%b,x,y,d);
		swap(x,y);
		y = (y - mulmod((a/b),x,mod) + mod)%mod;
		x %= mod;
	}
}

ll s[100010], p[100010];
int main() {
	int cas = 1;
	s[0] = 1;
	p[0] = 1;
	for (ll i = 1; i <= 10010; i++) {
		s[i] = (mulmod(s[i-1],i,mod) + 1)%mod;
		p[i] = mulmod(p[i-1],i,mod);
	}
	int T;
	ll L, M, N;
	scanf("%d", &T);
	while (T--) {
		scanf("%lld%lld%lld", &L, &M, &N);
		ll a = s[L*L-N], b = mod, c, d, e;
		inv(a,b,c,d,e);
		c = (c+mod)%mod;

		ll r1 = mulmod(s[L*L-M],c,mod);

		a = p[L*L-M], b = mod;
		inv(a,b,c,d,e);
		c = (c+mod)%mod;

		ll r2 = mulmod(p[L*L],c,mod);
		printf("> %lld %lld\n", p[L*L], c);
		printf("Case %d: %lld\n", cas++, mulmod(r1,r2,mod));
	}
	return 0;
}