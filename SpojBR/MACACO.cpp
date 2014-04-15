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

int X, V, U, Y;
int xx, yy, uu, vv;

int main() {
	int n, cas = 1;
	while (scanf("%d", &n) == 1 && n > 0) {
		xx = -200000;
		uu = 200000;
		yy = -200000;
		vv = 200000;
		int can = 1;
		rp(i,n) {
			scanf("%d%d%d%d", &X, &V, &U, &Y);
			xx = max(xx,X);
			uu = min(uu,U);
			yy = max(yy,Y);
			vv = min(vv,V);
			if (xx >= uu || yy >= vv) can = 0;
		}
		printf("Teste %d\n", cas++);
		if (can) printf("%d %d %d %d\n", xx, vv, uu, yy);
		else printf("nenhum\n");
		puts("");
	}
	return 0;
}