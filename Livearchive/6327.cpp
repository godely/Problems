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
#define MOD 1000000007LL

void ee(ll a, ll b, ll &x, ll &y, ll &d) {
	if (!b) {
		x = 1, y = 0, d = a;
		return;
	}
	ee(b,a%b,x,y,d);
	swap(x,y);
	y-=(a/b)*x;
}

ll expomod(ll a, ll b) {
	ll r = 1;
	for (; b > 0; b>>=1LL, a = (a*a)%MOD) if (b & 1) r = (r * a) % MOD;
	return r;
}

ll N, mul[50], inv[50];
ll getCs(ll n, int msk, bool big) {
	ll m;
	ll s = n;
 	for (int i = msk; i > 0; i = (i-1)&msk) {
 		int l = __builtin_popcount(i);
 		if (l&1) m = -1;
 		else m = 1;
 		//printf("%d %lld %d %lld\n", i, n, msk, s);
 		if (big || n >= mul[i]) s = (s + (m*(n-n%mul[i])*inv[i] + MOD + MOD)%MOD)%MOD;
 		//printf("%lld\n\n", s);
 	}
 	return s;
}

ll gcd(ll a, ll b) { return (!b) ? a : gcd(b,a%b); }

ll lcm(ll a, ll b) {
	return (a*b)/gcd(a,b);
}

char str[100];
ll go(ll N, int mskcant, int mskcan) {
	/*ll sum = (expomod(10,N) - 1 + MOD)%MOD;
	ll rs = getCs(sum,mskcant,N>1);
	if (rs >= mul[mskcan]) {
		rs = ((rs-rs%mul[mskcan])*inv[mskcan] + MOD + MOD)%MOD;
	} else rs = 0;
	if (!mskcant) rs = (rs+1+MOD)%MOD;
	return rs;*/
	ll A = 1;
	rp(_,N) A*=10;
	ll cnt = 0;
	rp(i,A) {
		fr(j,1,7) {
			if (str[j-1] == '1' && i%j > 0) goto aff;
			else if (str[j-1] == '0' && i%j == 0) goto aff;
		}
		cnt++;
		cnt %= MOD;
		aff:;
	}
	return cnt;
}

struct mat {
	ll a, b, c, d;
	mat () {}
	mat(ll a, ll b, ll c, ll d) : a(a), b(b), c(c), d(d) {}
	
	mat operator*(const mat &q) const {
		return mat((a * q.a + b*q.c)%MOD, (a * q.b + b * q.d)%MOD, (c * q.a + d * q.c)%MOD, (c * q.b + d * q.d)%MOD);
	}
};

mat expomat(mat a, ll b) {
	mat r = mat(1,0,0,1);
	for (; b > 0; b >>=1, a = a*a) if (b&1) r = r*a;
	return r;
}

int main() {
	/*rp(i,32) {
		mul[i] = 1;
		rp(j,5) if ((i>>j)&1) mul[i] = lcm(mul[i],(j+2));
		ll x, y, d;
		ee(mul[i],MOD,x,y,d);
		inv[i] = (x+MOD)%MOD;
		//printf("%d: %lld %lld\n", i, mul[i], inv[i]);
	}
	
	ll STOR;
	rp(a,3) rp(b,3) rp(c,3) rp(d,3) rp(e,3) rp(f,3) fr(N,3,6) {
		str[0] = a+'0';
		str[1] = b+'0';
		str[2] = c+'0';
		str[3] = d+'0';
		str[4] = e+'0';
		str[5] = f+'0';
		
		if (str[0] == '0') STOR = 0;
		else {
			if (str[1] == '0' && str[3] == '0') str[3] = '2';
			if (str[1] == '0' && str[5] == '0') str[5] = '2';
			if (str[2] == '0' && str[5] == '0') str[5] = '2';
			if ((str[3] == '1' && str[1] == '0') || (str[5] == '1' && str[2] == '0') || (str[5] == '1' && str[1] == '0')) {
				STOR = 0;
			} else {
				int mskcan = 0, mskcant = 0;
				fr(i,1,6) {
					if (str[i] == '0') mskcant |= (1<<(i-1));
					else if (str[i] == '1') mskcan |= (1<<(i-1));
				}
				if (N <= 5) STOR = go(N,mskcant,mskcan);
				else {
					ll A = go(4,mskcant,mskcan);
					ll B = go(5,mskcant,mskcan);
				
					mat a = mat(10,1,0,1);
					a = expomat(a,N-5);
					if (B/10 == A) STOR = ((a.a*B)%MOD + (a.b*(B%10))%MOD + MOD)%MOD;
					else STOR = ((a.a*10*(B/10))%MOD + (a.b*10*((B/10)%10))%MOD + B%10 + MOD)%MOD;
				}
			}
		}
		
		printf("%d %d%d%d%d%d%d = %lld\n", N, a,b,c,d,e,f, STOR);
	}*/
	
	rp(i,32) {
		mul[i] = 1;
		rp(j,5) if ((i>>j)&1) mul[i] = lcm(mul[i],(j+2));
		ll x, y, d;
		ee(mul[i],MOD,x,y,d);
		inv[i] = (x+MOD)%MOD;
		//printf("%d: %lld %lld\n", i, mul[i], inv[i]);
	}
	int T;
	scanf("%d", &T);
	while (T--) {
		scanf("%lld %s", &N, str);
		if (str[0] == '0') puts("0");
		else {
			if (str[1] == '0' && str[3] == '0') str[3] = '2';
			if (str[1] == '0' && str[5] == '0') str[5] = '2';
			if (str[2] == '0' && str[5] == '0') str[5] = '2';
			if ((str[3] == '1' && str[1] == '0') || (str[5] == '1' && str[2] == '0') || (str[5] == '1' && str[1] == '0')) {
				puts("0");
			} else {
				int mskcan = 0, mskcant = 0;
				fr(i,1,6) {
					if (str[i] == '0') mskcant |= (1<<(i-1));
					else if (str[i] == '1') mskcan |= (1<<(i-1));
				}
				if (N <= 5) printf("%lld\n", go(N,mskcant,mskcan));
				else {
					ll A = go(4,mskcant,mskcan);
					ll B = go(5,mskcant,mskcan);
					
					mat a = mat(10,1,0,1);
					a = expomat(a,N-5);
					if (B/10 == A) printf("%lld\n", ((a.a*B)%MOD + (a.b*(B%10))%MOD + MOD)%MOD);
					else printf("%lld\n", ((a.a*10*(B/10))%MOD + (a.b*10*((B/10)%10))%MOD + B%10 + MOD)%MOD);
				}
			}
		}
	}
	return 0;
}