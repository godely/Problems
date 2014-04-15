#include <cstdio>
#include <cstdlib>
#include <cmath>
#include <vector>
#include <cstring>
#include <map>
#include <iostream>
#define fr(a,b,c) for(int a = b; a < c; a++)
#define rp(a,b) fr(a,0,b)
#define mod 1000000007LL

using namespace std;
typedef long long ll;

ll expo(ll x, ll n) {
	ll r = 1;
	for (; n; n >>= 1, x=(x*x)%mod) if (n&1) r = (r*x)%mod;
	return r;
}

int main() {
	int cas = 1;
	int T; scanf("%d", &T);
	while (T--) {
		ll n; scanf("%lld", &n); n%=mod;
		printf("Case #%d: %lld\n", cas++, (expo(2,n-1)*n)%mod);
	}
}