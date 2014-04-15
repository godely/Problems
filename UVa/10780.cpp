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

bool p[maxn];
int f[maxn];
int n, m, t[maxn];

void sieve() {
	cl(p,1);
	p[0] = p[1] = 0;
	for (int i = 4; i < maxn; i+=2) p[i] = 0, f[i] = 2;
	f[1] = 1;
	f[2] = 2;
	for (int i = 3; i < maxn; i+=2) {
		if (p[i]) {
			f[i] = i;
			for (int j = i*i; j < maxn; j+=i) {
				if (p[j]) f[j] = i;
				p[j] = 0;
			}
		}
	}
}

int main() {
	int cas = 1;
	sieve();
	int T;
	scanf("%d", &T);
	while (T--) {
		scanf("%d%d", &m, &n);
		cl(t,0);
		fr(i,2,n+1) {
			int k = i;
			while (k > 1) {
				t[f[k]]++;
				k/=f[k];
			}
		}
		/*rp(i,maxn) if (t[i]) printf("%d %d\n", i, t[i]);
		puts("");*/

		int cnt = 0, last = -1;
		int res = 1000000000;
		while (m > 0) {
			if (f[m] != last) {
				if (cnt > 0) {
					//printf("%d %d\n", last, cnt);
					res = min(res,t[last]/cnt);
				}
				last = f[m];
				cnt = 0;
				if (m == 1) break;
			}
			m /= f[m];
			cnt++;
		}
		printf("Case %d:\n", cas++);
		if (!res) puts("Impossible to divide");
		else printf("%d\n", res);
	}
}