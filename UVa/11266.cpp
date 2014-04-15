#include <cstdio>
#include <algorithm>
#include <cstring>
#include <utility>
#include <vector>
#include <queue>
#include <stack>
#include <map>
#include <iostream>
#include <set>
#include <cmath>
#include <cassert>
#include <ctime>
#include <string>

using namespace std;

#define db(x) cout << #x " == " << x << endl
//#define _ << ", " <<
#define iter(a) typeof((a).begin())
#define Tr(a,b) for(iter(b) a = (b).begin(); a != (b).end(); ++a)
#define Fr(a,b,c) for( int a = b ; a < c ; ++a )
#define rF(a,b,c) for( int a = c-1; a>=b ; --a )
#define Rp(a,b) Fr(a,0,b)
#define fr Fr
#define rp Rp
#define cl(a,b) memset(a,b,sizeof(a))
typedef long long ll;
typedef unsigned long long ull;
typedef pair<int,int> pii;
typedef pair<double,pair<int,int> > pdi;
typedef vector<pair<int,int> > vpii;
#define F first
#define S second
#define MP make_pair
#define PB push_back
#define y1 Y1
#define INF 0x3f3f3f3f
#define LINF 0x3f3f3f3f3f3f3f3fLL
#define ULMAX 0xffffffffffffffffULL
#define MAXN 1000
#define MAXM 120000
#define MOD 200003

ll gcd(ll a, ll b) { return (!b) ? a : gcd(b,a%b); }

ll comb(ll n, ll r){ 
	ll a[15], i, j; 
	for(i=0; i<r; i++) a[i]=n-i; 
	for(i=r; i>1; i--) {
		ll k = i;
		for(j=0; j<r; j++) {
			ll d = gcd(a[j],k);
			a[j]/=d;
			k/=d;
		}
		fim:;
	}
	i=1;
	for (j=0; j<r; j++) i = (i*a[j])%MOD;
	return i; 
}

int b[MAXN];

ll drunen(int s, int n, int mask) {
	//if (mask > 0) return 0;
	ll r = 1;
	rp(i,n) if ((mask>>i)&1) {
		r*=(-1);
		s -= b[i];
	}
	//printf("%d: %d %d\n", mask, s+n-1, n-1);
	if (s+n-1 < n-1) return 0;
	return (comb(s+n-1,n-1)*r)%MOD;
}

int main() {
	int T; scanf("%d", &T);
	while (T--) {
		int n, s, a;
		scanf("%d%d", &n, &s);
		rp(i,n) {
			scanf("%d%d", &a, &b[i]);
			s -= a;
			b[i] = b[i]-a+1;
			a = 0;
		}
		ll res = 0;
		int lim = (1<<n);
		rp(i,lim) {
			res = (res+drunen(s,n,i)+MOD)%MOD;
		}
		printf("%lld\n", res);
	}
	return 0;
}