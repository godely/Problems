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

int C, F, N, D;
int pd[3][1010];

int main() {
	int cas = 1;
	while (scanf("%d%d", &C, &F) == 2 && C > 0) {
		cl(pd,0);
		int a = 1, b = 0;
		int res = 0;
		rp(i,F) {
			scanf("%d%d", &N, &D);
			for (int i = 0; i <= C; i++) {
				pd[a][i] = pd[b][i];
				if (i >= N) pd[a][i] = max(pd[b][i],pd[b][i-N]+D);
				res = max(res,pd[a][i]);
			}
			swap(a,b);
		}
		printf("Teste %d\n", cas++);
		printf("%d\n", res);
		puts("");
	}
}