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
typedef long long ll;
#define MP make_pair
#define F first
#define S second
#define oo 0x3f3f3f3f

#define maxn 60
#define maxm 3600

int n, m;
bool exist[60][60], found;
double pd[60][60], cap[60][60];

bool floydTest(double m) {
	rp(i,n) rp(j,n) {
		if (exist[i][j]) pd[i][j] = cap[i][j] - m;
		else pd[i][j] = 1e10;
	}
	rp(k,n) rp(i,n) rp(j,n) pd[i][j] = min(pd[i][j], pd[i][k] + pd[k][j]);
	rp(i,n) if (pd[i][i] < 0) {
		found = 1;
		return 1;
	}
	return 0;
}

int main() {
	int cas = 1;
	int T;
	scanf("%d", &T);
	while (T--) {
		scanf("%d%d", &n, &m);
		cl(exist,0);
		rp(i,n) rp(j,n) cap[i][j] = 1e10;
		rp(i,m) {
			int a, b; double c;
			scanf("%d%d%lf", &a, &b, &c); a--, b--;
			exist[a][b] = 1;
			cap[a][b] = min(cap[a][b],c);
		}
		double ini = -1e7, fim = 1e7, m;
		found = 0;
		rp(_,200) {
			m = (ini+fim)/2.0;
			if (floydTest(m)) fim = m;
			else ini = m;
		}
		if (found) printf("Case #%d: %.2lf\n", cas++, ini);
		else printf("Case #%d: No cycle found.\n", cas++);
	}
}