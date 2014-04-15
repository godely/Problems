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
#define MOD 100000000LL

struct mat {
	ll m[4][4];
	mat() {}
	
	mat operator*(const mat &q) const {
		mat ret;
		rp(i,4) rp(j,4) {
			ret.m[i][j] = 0;
			rp(k,4) ret.m[i][j] = (ret.m[i][j] + m[i][k]*q.m[k][j])%MOD;
		}
		return ret;
	}
};

ll expo(mat &a, ll p) {
	mat r;
	rp(i,4) rp(j,4) r.m[i][j] = (i==j);
	for (; p; p >>= 1, a = a*a) if (p&1) r = r*a;
	return (8*((r.m[3][0]*2 + r.m[3][1]*2 + r.m[3][2] + r.m[3][3] - 1 + MOD)%MOD))%MOD;
}

int main() {	
	ll N;
	while (scanf("%lld", &N) == 1 && N > 0) {
		ll r = 0;
		if (N < 1000) {
			for (int i = 1; i <= N; i+=2) r += (int)sqrt(i);
			printf("%lld\n", r);
		} else {
			mat a;
			cl(a.m,0);
			a.m[0][0] = a.m[1][1] = a.m[1][2] = a.m[2][2] = a.m[3][0] = a.m[3][3] = 1;
			a.m[0][1] = 2;
			
			ll n = sqrt(N);
			if (n&1) {
				r = (r+(((N-n*n+2)>>1)%MOD)*n)%MOD;
				n--;
			} else {
				r = (r+(((N-n*n+1)>>1)%MOD)*n)%MOD;
				ll m = n;
				n--;
				if (n&1) {
					r = (r+(((m*m-n*n+1)>>1)%MOD)*n)%MOD;
					n--;
				}
			}
		
			n = (n>>1) - 1;
			r = (r + 6 + expo(a,n) + (3*(4+(n-1))*n)%MOD)%MOD;
			printf("%lld\n", r);
		}
	}
}