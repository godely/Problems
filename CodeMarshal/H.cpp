#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <cassert>
#include <vector>
#include <algorithm>
#include <iostream>
#include <utility>
#include <map>
using namespace std;
#define fr(a,b,c) for (int a = b; a < c; a++)
#define rp(a,b) fr(a,0,b)
#define cl(a,b) memset(a,b,sizeof a)
#define MP make_pair
#define F first
#define S second
typedef pair<int,int> pii;
typedef long long ll;
typedef unsigned long long ull;
#define MAXN 1001000
#define MOD 1000000007LL

int M, N, S;
char gb[1000];

ll pot25[100];

ll go(int i, int j) {
	if (i >= N) return 1LL;

	printf("%d %d\n", i, j);

	ll ret = (pot25[1] * go(i + 1, j))%MOD;
	if (j < S) ret = (ret + (pot25[M] * go(min(i + M + 1, N), j + 1))%MOD)%MOD;
	return ret;
}

int main() {
	pot25[0] = 1;
	fr(i,1,20) pot25[i] = (pot25[i-1]*25)%MOD;

	int T; scanf("%d", &T);
	while (T--) {
		scanf("%s", gb);
		scanf("%d%d", &M, &N);
		S = strlen(gb);
		printf("%lld\n", go(0,0));
	}
}