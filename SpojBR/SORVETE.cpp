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

int P, S;
int a, b;
pii p[11000];

int main() {
	int n, cas = 1;
	while (scanf("%d%d", &P, &S) == 2 && P > 0) {
		rp(i,S) {
			scanf("%d%d", &a, &b);
			p[i] = MP(a,b);
		}
		sort(p,p+S);
		a = p[0].F, b = p[0].S;
		printf("Teste %d\n", cas++);
		fr(i,1,S) {
			if (p[i].F <= b) b = max(p[i].S,b);
			else {
				printf("%d %d\n", a, b);
				a = p[i].F;
				b = p[i].S;
			}
		}
		printf("%d %d\n", a, b);
		puts("");
	}
	return 0;
}