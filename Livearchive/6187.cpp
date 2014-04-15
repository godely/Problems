#include <bits/stdc++.h>
using namespace std;
#define fr(a,b,c) for(int a = b; a < c; a++)
#define rp(a,b) fr(a,0,b)
#define MAXN 100100
#define mp make_pair
#define F first
#define S second
typedef long long ll;
typedef pair<int,ll> pii;

int N, M;
char cmd[10];
int a, b;
ll w;
pii rep[MAXN];

pii findset(int x) {
	if (x == rep[x].F) return mp(x,0LL);
	else {
		pii p = findset(rep[x].F);
		return rep[x] = mp(p.F, rep[x].S+p.S);
	}
}

void unionset(int x, int y, ll w) {
	pii p = findset(x);
	pii q = findset(y);
	rep[p.F] = mp(q.F, w-p.S+q.S);
}

bool sameSet(int x, int y) {
	return findset(x).F == findset(y).F;
}

int main() {
	while (scanf("%d%d", &N, &M) == 2 && N > 0) {
		rp(i,N) rep[i] = mp(i,0);
		rp(i,M) {
			scanf("%s", cmd);
			if (cmd[0] == '!') {
				scanf("%d%d%lld", &a, &b, &w); a--, b--;
				if (!sameSet(a,b)) unionset(a,b,w);
			} else {
				scanf("%d%d", &a, &b); a--, b--;
				if (sameSet(a,b)) {
					printf("%lld\n", findset(a).S - findset(b).S);
				} else printf("UNKNOWN\n");
			}
		}
	}
	return 0;
}