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

int g[1010][1010];

int main() {
	int n, m;
	int x, y;
	int cas = 1;
	while (scanf("%d%d", &n, &m) == 2 && n > 0) {
		rp(i,n) rp(j,m) scanf("%d", &g[i][j]);
		int X = 0, Y = 0;
		while (scanf("%d%d", &x, &y) == 2 && (x != 0 || y != 0)) {
			X=(X-x+m)%m;
			Y=(Y+y+n)%n;
		}
		while (X < 0) X=(X+m)%m;
		while (Y < 0) Y=(Y+n)%n;
		printf("Teste %d\n", cas++);
		rp(i,n) {
			printf("%d", g[(i+Y)%n][X%m]);
			fr(j,1,m) {
				printf(" %d", g[(i+Y)%n][(j+X)%m]);
			}
			puts("");
		}
		puts("");
	}
	return 0;
}