#include <cstdio>
#include <cstring>
#include <cstdlib>
#include <vector>
#include <map>
#include <cmath>
#include <algorithm>
#include <queue>
#define fr(a,b,c) for(int a = b; a < c; a++)
#define rp(a,b) fr(a,0,b)
#define cl(a,b) memset(a,b,sizeof a)
using namespace std;
const int N = 362;

class Graph {
	private:
		int n, mate[N];
		bool g[N][N], inQ[N], inBlo[N];
		queue<int> Q;
		int start, newBase, prev[N], base[N];
		int lca(int,int);
		void trace(int);
		void contract(int,int);
		bool search();
		void augment(int);
	public:
		bool init();
		int match();
};

int Graph::lca(int u, int v) {
	bool path[N] = { false };
	while (true) {
		u = base[u];
		path[u] = true;
		if (u == start) break;
		u = prev[mate[u]];
	}
	while (true) {
		v = base[v];
		if (path[v]) break;
		v = prev[mate[v]];
	}
	return v;
}

void Graph::trace(int u) {
	while (base[u] != newBase) {
		int v = mate[u];
		inBlo[base[u]] = inBlo[base[v]] = true;
		u = prev[v];
		if (base[u] != newBase) prev[u] = v;
	}
}

void Graph::contract(int u, int v) {
	newBase = lca(u,v);
	memset(inBlo,false,sizeof inBlo);
	trace(u);
	trace(v);
	if (base[u] != newBase) prev[u] = v;
	if (base[v] != newBase) prev[v] = u;
	for (int i = 0; i < n; i++) {
		if (inBlo[base[i]]) {
			base[i] = newBase;
			if (!inQ[i]) {
				Q.push(i);
				inQ[i] = true;
			}
		}
	}
}

bool Graph::search() {
	memset(inQ,false,sizeof inQ);
	memset(prev,-1,sizeof prev);
	for (int i = 0; i < n; i++) base[i] = i;
	while (!Q.empty()) Q.pop();
	Q.push(start);
	inQ[start] = true;
	while (!Q.empty()) {
		int u = Q.front(); Q.pop();
		for (int i = 0; i < n; i++) {
			if (g[u][i] && base[u] != base[i] && mate[u] != i) {
				if (i == start || (mate[i] >= 0 && prev[mate[i]] >= 0)) contract(u,i);
				else if (prev[i] < 0) {
					prev[i] = u;
					if (mate[i] != -1) {
						Q.push(mate[i]);
						inQ[mate[i]] = true;
					} else {
						augment(i);
						return true;
					}
				}
			}
		}
	}
	return false;
}

void Graph::augment(int u) {
	while (u >= 0) {
		int v = prev[u], w = mate[v];
		mate[v] = u;
		mate[u] = v;
		u = w;
	}
}

int Graph::match() {
	memset(mate,-1,sizeof mate);
	int mth = 0;
	for (int i = 0; i < n; i++) {
		if (mate[i] >= 0) continue;
		start = i;
		if (search()) mth++;
	}
	return mth;
}

int passo;
int M, K;
int adj[N][N], mt[N][N];
bool Graph::init() {
	memset(inQ,0,sizeof inQ);
	memset(inBlo,0,sizeof inBlo);
	while (!Q.empty()) Q.pop();
	memset(mate,-1,sizeof mate);
	n = K;
	rp(i,n) rp(j,n) g[i][j] = (adj[i][j]==passo);
}

int main() {
	cl(adj,0); passo = 0;
	Graph graph;
    int T, cas = 1;
    scanf("%d", &T);
    while (T--) {
 		scanf("%d", &M);
		K = (1<<M);
 		rp(i,K-1) rp(j,K-1-i) scanf("%d", &mt[i][i+j+1]);
 		int ini = 1, fim = 1000000000, m;
 		while (ini < fim) {
 			m = (ini+fim+1)>>1;
 			passo++;
 			rp(i,K-1) rp(j,K-1-i) if (mt[i][i+j+1] >= m) adj[i][i+j+1] = adj[i+j+1][i] = passo;
 			graph.init();
 			int mtch = graph.match();
 			if (mtch == (K>>1)) ini = m;
 			else fim = m-1;
 		}
 		printf("Case %d: %d\n", cas++, ini);
 	}
 	return 0;
}    