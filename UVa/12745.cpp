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
typedef long long ll;
#define MP make_pair
#define F first
#define S second
#define oo 0x3f3f3f3f
#define MOD 10007

#define MAXN 310000
#define MAXM 510000

#define N(x) (2*x + 1)
#define Y(x) (2*x)
#define NEG(x) (x%2 == 1 ? x-1 : x+1)

#define add(a,b) to[z] = b, ant[z] = adj[a], adj[a] = z++
int to[MAXM], ant[MAXM], adj[MAXN], z;

int high[MAXN], vis[MAXN], stck[MAXN], comp[MAXN];
int ncomp, t, num;

void dfscc(int u) {
	high[u] = vis[u] = num--;
	stck[t++] = u;
	for (int i = adj[u]; ~i; i = ant[i]) {
		int v = to[i];
		if (!vis[v]) {
			dfscc(v);
			high[u] = max(high[u], high[v]);
		} else if (vis[v] > vis[u] && !comp[v]) {
			high[u] = max(high[u], vis[v]);
		}
	}
	if (high[u] == vis[u]) {
		ncomp++;
		int v;
		do {
			v = stck[--t];
			comp[v] = ncomp;
		} while (v != u);
	}
}

void scc(int n) {
	ncomp = t = 0; num = n;
	cl(vis,0); cl(comp,0);
	for(int i = 0; i < n; i++) {
		if (!vis[i]) dfscc(i);
	}
}

bool two_sat(int n) {
	n *= 2;
	bool ok = true;
	scc(n);
	for (int i=0; i<n/2 && ok; i++) {
		//printf("%d: %d %d\n", i, comp[i<<1], comp[(i<<1)+1]);
		ok &= (comp[i<<1] != comp[(i<<1)+1]);
	}
	return ok;
}

void clau(int x, int y) {
	add(NEG(x),y);
	add(NEG(y),x);
}

int main() {
	int cas = 1;
	int T, N, M, a, b;
	scanf("%d", &T);
	while (T--) {
		scanf("%d%d", &N, &M);
		cl(adj,-1); z = 0;
		rp(i,M) {
			scanf("%d%d", &a, &b);
			if (a < 0) a = N((-a-1));
			else a = Y((a-1));
			if (b < 0) b = N((-b-1));
			else b = Y((b-1));
			clau(a,b);
			clau(NEG(a),NEG(b));
		}
		if (two_sat(N)) printf("Case %d: Yes\n", cas++);
		else printf("Case %d: No\n", cas++);
	}
}