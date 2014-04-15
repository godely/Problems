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

int main() {
	int n;
	int cas = 1;
	while (scanf("%d", &n) == 1 && n > 0) {
		printf("Teste %d\n", cas++);
		int res = 0, x;
		rp(i,n) {
			scanf("%d", &x); x--;
			if (x == i) res = x+1;
		}
		printf("%d\n", res);
		puts("");
	}
	return 0;
}