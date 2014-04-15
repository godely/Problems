#include <bits/stdc++.h>
using namespace std;
#define fr(a,b,c) for (int a = b; a < c; a++)
#define rp(a,b) fr(a,0,b)
#define pb push_back
#define MAXN 200100

vector<int> a;
vector< vector<int> > p;
vector<int> Log2;

int pairmin(int i1, int i2) {
	return a[i1] </*=*/a[i2] ? i1 : i2;
}

void init(vector<int> &_a) {
	a = _a;
	int n = a.size();
	Log2.resize(n+1);
	for (int i = 1, k = 0; i <= n; i++) {
		Log2[i] = k;
		if (1 << (k+1) == i) k++;
	}
	
	int ln = Log2[n];
	p.assign(ln+1, vector<int>(n));
	for (int i = 0; i < n; i++) p[0][i] = i;
	for (int i = 1; i <= ln; i++) {
		for (int j = 0; j+(1 << i) - 1 < n; j++) {
			int i1 = p[i-1][j];
			int i2 = p[i-1][j + (1 << i-1)];
			p[i][j] = pairmin(i1, i2);
		}
	}
}

int query(int b, int e) {
	int ln = Log2[e-b+1];
	int i1 = p[ln][b];
	int i2 = p[ln][e - (1 << ln) + 1];
	return pairmin(i1, i2);
}

int N, nE;
int sizeCyc;
vector<int> adj[MAXN];

vector<int> L;
int E[2*MAXN], R[MAXN], vis[MAXN];

void euler(int u, int p, int e1) {
	E[nE++] = u; L.pb(e1);
	vis[u] = 1;
	for (int i = 0; i < adj[u].size(); i++) {
		if (!vis[adj[u][i]] && adj[u][i] != p) {
			euler(adj[u][i], u, e1+1);
			E[nE++] = u; L.pb(e1);
		}
	}
}

void preprocess(int root) {
	int i;
	nE = 0;
	L.clear();
	memset(vis, 0, sizeof vis);
	euler(root, -1, 0);
	for (i = 2*sizeCyc-2; i >= 0; i--) R[E[i]] = i;
	init(L);
}

int lca(int u, int v) {
	return E[query(min(R[u], R[v]), max(R[u], R[v]))];
}

int to[MAXN];
stack<int> st;

vector<int> cycle[MAXN];
int partOf[MAXN], endsAt[MAXN], mark[MAXN], naPilha[MAXN], dist[MAXN], pos[MAXN];

int dfs(int u) {
	if (mark[u]) {
		if (!naPilha[u]) return endsAt[u];
		int v;
		do {
			v = st.top();
			naPilha[v] = 0;
			endsAt[v] = v;
			partOf[v] = sizeCyc;
			pos[v] = cycle[sizeCyc].size();
			cycle[sizeCyc].pb(v);
			st.pop();
		} while (v != u);
		adj[0].pb(sizeCyc);
		sizeCyc++;
		return -1;
	}
	mark[u] = 1;
	naPilha[u] = 1;
	st.push(u);

	int ret = dfs(to[u]);
	if (naPilha[u]) naPilha[u] = 0, st.pop();
	if (ret != -1) {
		dist[u] = dist[to[u]] + 1;
		return endsAt[u] = ret;
	} else {
		if (partOf[u] == -1 && partOf[to[u]] != -1) {
			dist[u] = 1;
			return endsAt[u] = to[u];
		}
		return -1;
	}
}

int main() {
	while (scanf("%d", &N) == 1) {
		fr(i,1,N+1) scanf("%d", &to[i]), to[i];
		sizeCyc = N+1;
		rp(i,2*N+1) adj[i].clear(), cycle[i].clear();
		memset(mark, 0, sizeof mark);
		memset(partOf, -1, sizeof partOf);
		memset(naPilha, 0, sizeof naPilha);
		memset(endsAt, -1, sizeof endsAt);
		memset(dist, 0, sizeof dist);
		fr(i,1,N+1) if (!mark[i]) dfs(i);
		fr(i,1,N+1) {
			if (partOf[i] == -1) {
				if (partOf[to[i]] != -1) adj[partOf[to[i]]].pb(i);
				else adj[to[i]].pb(i);
			}
		}
		preprocess(0);
		int Q, u, v, _u, _v, _p;
		scanf("%d", &Q);
		while (Q--) {
			scanf("%d%d", &u, &v);
			_u = u, _v = v;
			if (partOf[u] != -1) _u = partOf[u];
			if (partOf[v] != -1) _v = partOf[v];
			
			_p = lca(_u,_v);
			if (_p == 0) printf("-1\n");
			else {
				if (_p <= N) printf("%d\n", dist[u] + dist[v] - 2*dist[_p]);
				else printf("%d\n", dist[u] + dist[v] + min(abs(pos[endsAt[u]]-pos[endsAt[v]]), (int)cycle[_p].size() - abs(pos[endsAt[u]]-pos[endsAt[v]])));
			}
		}
	}
	return 0;
}