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

char af[10];
int led[1110];

int main() {
	int T, n, a, b;
	scanf("%d", &T);
	while (T--) {
		cl(led,0);
		scanf("%d", &n);
		rp(i,n) {
			scanf("%s%d%d", af, &a, &b);
			fr(i,a,b) led[i]++;
		}
		rp(i,1000) if (led[i] > 0) printf("%c", led[i]+'A'-1);
		puts("");
	}
	return 0;
}