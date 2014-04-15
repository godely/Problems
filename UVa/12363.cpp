#include <bits/stdc++.h>
using namespace std;
#define fr(a,b,c) for(int a = b; a < c; a++)
#define rp(a,b) fr(a,0,b)
#define MAXN 10010
#define pb push_back

int num[MAXN], low[MAXN], mark[MAXN], rep[MAXN], counter;
vector<int> adj[MAXN];

int findset(int u) {
	if (u == rep[u]) return u;
	return rep[u] = findset(rep[u]);
}

void link(int u, int v) {
	rep[findset(u)] = findset(v);
}

bool isSameSet(int u, int v) {
	return findset(u) == findset(v);
}

int findBridge(int u, int from) {
	num[u] = low[u] = counter++;
	mark[u] = 1;
	rp(v,adj[u].size()) {
		if (!mark[adj[u][v]]) {
			findBridge(adj[u][v], u);
			if (low[adj[u][v]] > num[u]) { //PONTE!
				link(u,adj[u][v]);
			}
			low[u] = min(low[u], low[adj[u][v]]);
		} else if (adj[u][v] != from) low[u] = min(low[u], num[adj[u][v]]);
	}
}

int main() {
	int R, C, Q, a, b;
	while (scanf("%d%d%d", &R, &C, &Q) == 3 && R > 0) {
		fr(i,1,R+1) adj[i].clear(), rep[i] = i;
		rp(i,C) {
			scanf("%d%d", &a, &b);
			adj[a].pb(b);
			adj[b].pb(a);
		}
		memset(mark, 0, sizeof mark);
		counter = 0;
		fr(i,1,R+1) if (!mark[i]) findBridge(i, -1);
		rp(i,Q) {
			scanf("%d%d", &a, &b);
			if (isSameSet(a,b)) printf("Y\n");
			else printf("N\n");
		}
		printf("-\n");
	}
	return 0;
}