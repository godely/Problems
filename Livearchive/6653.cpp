#include <cstdio>
#include <cstdlib>
#include <algorithm>
#include <vector>
#include <cmath>
#include <map>
#include <set>
#include <iostream>
#include <cstring>
using namespace std; 
#define fr(a,b,c) for (int a = b; a < c; a++) 
#define rp(a,b) fr(a,0,b) 
#define CL(a,b) memset((a),(b),sizeof (a))
#define MP make_pair
#define F first
#define S second
typedef long long ll;
typedef pair<int,int> pii;
#define MOD 10000000000007LL

using namespace std;

ll mulmod(ll a, ll b) {
	ll r = 0;
	for (; b > 0; b>>=1LL, a = (a+a)%MOD) if (b & 1) r = (r + a) % MOD;
	return r;
}

int main() {
	int T, cas = 1;
	scanf("%d", &T);
	ll L, M, N;
	while (T--) {
		scanf("%lld%lld%lld", &L, &M, &N);
		ll K = L*L;
		ll tmp = 1;
		rp(i,M) tmp = mulmod(tmp,K-i);
		ll ans = tmp;
		fr(i,M,N) {
			tmp = mulmod(tmp,K-i);
			ans = (ans + tmp)%MOD;
		}
		printf("Case %d: %lld\n", cas++, ans);
	}
	return 0;
}