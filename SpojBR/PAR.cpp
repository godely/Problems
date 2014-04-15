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

char nome1[500], nome2[500];

int main() {
	int n;
	int cas = 1;
	int a, b;
	while (scanf("%d", &n) == 1 && n > 0) {
		scanf("%s%s", nome1, nome2);
		printf("Teste %d\n", cas++);
		rp(i,n) {
			scanf("%d%d", &a, &b); a+=b;
			if (a%2 == 0) printf("%s\n", nome1);
			else printf("%s\n", nome2);
		}
		puts("");
	}
	return 0;
}