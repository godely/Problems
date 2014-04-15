#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <cmath>
#include <iostream>
#include <algorithm>
using namespace std;
#define fr(a,b,c) for (int a = b; a < c; a++)
#define rp(a,b) fr(a,0,b)
#define cl(a,b) memset(a,b,sizeof a)
#define sf(a) scanf("%d", &a)
#define sf2(a,b) scanf("%d%d", &a, &b)
#define sf3(a,b,c) scanf("%d%d%d", &a, &b, &c)
#define sf4(a,b,c,d) scanf("%d%d%d%d", &a, &b, &c, &d)
typedef pair<int,int> pii;
#define MP make_pair
#define F first
#define S second
#define oo 0x3f3f3f3f

int g[10][10];
bool u[10][10];
int mask;

int bt(int i, int j) {
	if (i >= 7) return 1;
	if (j >= 8) return bt(i+1,0);

	if (u[i][j]) return bt(i,j+1);

	u[i][j] = 1;

	int ret = 0;

	if (j < 7 && !u[i][j+1]) {
		int mi = min(g[i][j], g[i][j+1]);
		int ma = max(g[i][j], g[i][j+1]);
		int r = ((15-mi)*mi)/2 + ma-mi;
		if (!((mask>>r)&1)) {
			mask |= (1<<r);
			u[i][j+1] = 1;
			ret += bt(i,j+1);
			u[i][j+1] = 0;
			mask &= (~(1<<r));
		}
	}
	if (i < 6 && !u[i+1][j]) {
		int mi = min(g[i][j], g[i+1][j]);
		int ma = max(g[i][j], g[i+1][j]);
		int r = ((15-mi)*mi)/2 + ma-mi;
		if (!((mask>>r)&1)) {
			mask |= (1<<r);
			u[i+1][j] = 1;
			ret += bt(i,j+1);
			u[i+1][j] = 0;
			mask &= (~(1<<r));
		}
	}

	u[i][j] = 0;

	return ret;
}

int main() {
	int T; sf(T);
	int cas = 1;
	while (T--) {
		rp(i,7) rp(j,8) scanf("%d", &g[i][j]);
		cl(u,0); mask = 0;
		printf("Teste %d\n%d\n\n", cas++, bt(0,0));
	}
	return 0;
}