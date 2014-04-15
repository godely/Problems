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

using namespace std;

#define db(x) cout << #x " == " << x << endl
//#define _ << ", " <<
#define fr(a,b,c) for( int a = b ; a < c ; ++a )
#define rp(a,b) fr(a,0,b)
#define cl(a,b) memset(a,b,sizeof a)
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

int n;
ll a0, a1, b0, b1, c0, c1;
ll A, B, affmax;
ll AFF[1100];

int main() {
	int T;
	scanf("%d", &T);
	while (T--) {
		scanf("%d%lld%lld", &n, &a0, &b1);
		A = a0, B = b1;
		affmax = max(A,B);
		a0 = 1, b1 = 1;
		a1 = b0 = 0;
		for (int i = 2; i <= n; i++) {
		    c0 = a0 + b0, c1 = a1 + b1;
		    a0 = b0, a1 = b1;
		    b0 = c0, b1 = c1;
		}
		cl(AFF,0);
		for (int i = 2; i <= A; i++) {
		    ll s = 0;
		    while (A%i == 0) {
		        A/=i;
		        s++;
		    }
		    AFF[i] += (s*c0);
		}
		for (int i = 2; i <= B; i++) {
		    ll s = 0;
		    while (B%i == 0) {
		        B/=i;
		        s++;
		    }
		    AFF[i] += (s*c1);
		}
		for (int i = 2; i <= affmax; i++) {
		    if (AFF[i] > 0) printf("%d %lld\n", i, AFF[i]);
		}
		puts("");
	}
	return 0;
}