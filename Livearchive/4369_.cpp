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

int up[MAXN];
ll lines[MAXN];

void go(int n, ll row) {
	dbg printf(" go(n %2d, row %5lld)\n", n, row);
	if(n == 0) return;
	ll lines = 1LL << (n - 1);
	up[n] = row < lines;
	if(row < lines) go(n - 1, row);
	else go(n - 1, row - lines);
	dbg printf(" up[%d] %d\n", n, up[n]);
}

int get(int n, ll ii) {
	if(n == 0) return 1;
	ll cols = 1LL << (n - 1);
	if(ii < cols || up[n]) return get(n - 1, ii % cols);
	return - get(n - 1, ii % cols);
}

int n;
ll r, s, e;
int main() {
	while(scanf("%d%lld%lld%lld", &n, &r, &s, &e) == 4) {
		if(n == -1) break;
		go(n, r);
		int ans = 0;
		int tam = e - s + 1;
		Fr(i,0,tam) ans += get(n, s + i);
		printf("%d\n", ans);
	}
	
	return 0;
}