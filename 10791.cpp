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
#define maxn 11000

ll N, cas;

int main() {
	cas = 1;
	while (scanf("%lld", &N) && N > 0) {
		ll M = sqrt(N);
		ll c, res = 0, n = 0;
		if (N == 1) res = 2;
		for (ll i = 2; i <= M; i++) {
			if (N%i == 0) {
				c = 1;
				while (N%i == 0) N/=i, c*=i;
				res+=c;
				n++;
			}
		}
		if (N > 1) res+=N, n++;
		if (n == 1) res++;
		printf("Case %lld: %lld\n", cas++, res);
	}
}