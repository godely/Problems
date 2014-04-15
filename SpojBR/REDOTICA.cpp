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


pair<int, pair<int,int> > p[20100];
int rep[200];

int findset(int i) {
	if (i == rep[i]) return rep[i];
	else return findset(rep[i]);
}

bool sameSet(int i, int j) {
	return findset(i) == findset(j);
}

void unionSet(int i, int j) {
	rep[findset(i)] = findset(j);
}

int main() {
	int n, m;
	int a, b, c;
	int cas = 1;
	while (scanf("%d%d", &n, &m) == 2 && n > 0) {
		rp(i,n) rep[i] = i;
		rp(i,m) {
			scanf("%d%d%d", &a, &b, &c); a--, b--;
			p[i] = MP(c,MP(a,b));
		}
		sort(p,p+m);
		printf("Teste %d\n", cas++);
		rp(i,m) {
			if (!sameSet(p[i].S.F,p[i].S.S)) {
				unionSet(p[i].S.F,p[i].S.S);
				printf("%d %d\n", min(p[i].S.F,p[i].S.S)+1, max(p[i].S.F,p[i].S.S)+1);
			}
		}
		puts("");
	}
	return 0;
}