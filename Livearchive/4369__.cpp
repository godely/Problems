//

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
#define Fr(a,b,c) for(int a = b ; a < (c) ; ++a)
#define CL(a,b) memset(a,b,sizeof(a))
typedef long long ll;
typedef unsigned long long ull;
typedef pair<int,int> pii;
typedef vector<pair<int,int> > vpii;
#define F first
#define S second
#define MP make_pair
#define PB push_back
#define y1 Y1
#define INF 0x3f3f3f3f
#define LINF 0x3f3f3f3f3f3f3f3fLL
#define ULMAX 0xffffffffffffffffULL

#define dbg if(0)

#define MAXN 70

int up[MAXN], po[MAXN];
ll pd[MAXN];

void go(int n, ll row) {
	dbg printf(" go(n %2d, row %5lld)\n", n, row);
	pd[n] = INF;
	if(n == 0) return;
	ll lines = 1LL << (n - 1);
	up[n] = row < lines;
	po[n] = !row;
	if(row < lines) go(n - 1, row);
	else go(n - 1, row - lines);
	dbg printf(" up[%d] %d\n", n, up[n]);
}

ll g(int n, ll ii, ll jj) {
	dbg printf(" g(n %d, ii %lld, jj %lld) up[] %d (%8lld)\n", n, ii, jj, up[n], (1LL << n));
	if(n == 0) return 1;
	
	if (ii == 0 && ((1LL << n) - 1) == jj) {
		if(pd[n] == INF) {
			if(po[n]) pd[n] = jj-ii+1;
			else pd[n] = 0;
		}
		
		return pd[n];
	}
	
	ll cols = 1LL << (n - 1);
	ll res = 0;
	if(ii < cols) res += g(n - 1, ii, min(jj, cols - 1));
	if(cols <= jj) {
		if(up[n]) res += g(n - 1, max(ii, cols) - cols, jj - cols);
		else res -= g(n - 1, max(ii, cols) - cols, jj - cols);
	}
	return res;
}

int n;
ll r, s, e;
int main() {
	while(scanf("%d%lld%lld%lld", &n, &r, &s, &e) == 4) {
		if(n == -1) break;
		go(n, r);
		printf("%lld\n", g(n, s, e));
	}
	
	return 0;
}