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

int X1, Y1, X2, Y2, x, y;
int main() {
	int n, cas = 1;
	while (scanf("%d%d%d%d", &X1, &Y2, &X2, &Y1) == 4 && (X1 || X2 || Y1 || Y2)) {
		scanf("%d", &n);
		int cnt = 0;
		rp(i,n) {
			scanf("%d%d", &x, &y);
			if (x >= X1 && x <= X2 && y >= Y1 && y <= Y2) cnt++;
		}
		printf("Teste %d\n%d\n\n", cas++, cnt);
	}
	return 0;
}