#include <cstdio>
#include <cmath>
#include <cstring>
#include <algorithm>
using namespace std;
#define fr(a,b,c) for(int a = b; a < c; a++)
#define rp(a,b) fr(a,0,b)
#define cl(a,b) memset(a,b,sizeof a)

typedef long long ll;

ll A[10];

int win(ll x, ll y, ll z) {
	if (y > z) swap(y,z);
	if (y == 0) {
		if (z <= 2) {
			if (z > 0 || x == 0) return 3;
			return 2;
		}
		return (x&1) ? 1 : 2;
	}

	if (!(x&1)) return 1;
	else {
		if (z == y) return 2;
		else if (z > y && z <= y + 2) return 3;
		return 1;
	}
}

int main() {
	int T, N, cas = 1;
	ll L, B;
	scanf("%d", &T);
	while (T--) {
		scanf("%d", &N);
		cl(A,0);
		rp(i,N) {
			scanf("%lld%lld", &L, &B);
			if (B%3 < 2) {
				A[B%3] += (L-1)*(B-1);
			} else {
				A[2] += (L>>1LL)*(B-1);
				A[1] += (L - (L>>1LL) - 1)*(B-1);
			}
		}
		int res = win(A[0],A[1],A[2]);
		printf("Case %d: ", cas++);
		if (res == 1) puts("M");
		else if (res == 2) puts("J");
		else puts("Draw");
	}
	return 0;
}