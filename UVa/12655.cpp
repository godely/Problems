#include <bits/stdc++.h>
using namespace std;
#define fr(a,b,c) for (int a = b; a < c; a++)
#define rp(a,b) fr(a,0,b)
#define MAXN 81000
#define MAXM 1010000

struct edge {
	int a, b, w;
	edge() {}
	edge(int a, int b, int w) : a(a), b(b), w(w) {}
	
	bool operator<(const edge &q) const {
		return w > q.w;
	}
} e[MAXM];

int rep[MAXN];
int findSet(int a) { return (a == rep[a]) ? a : rep[a] = findSet(rep[a]); }
void unionSet(int a, int b) { rep[findSet(a)] = findSet(b); }
bool sameSet(int a, int b) { return findSet(a) == findSet(b); }

#define add(a,b,c) to[z] = b, cost[z] = c, ant[z] = adj[a], adj[a] = z++
int to[MAXM], cost[MAXM], ant[MAXM], adj[MAXN], z;
int N, M, S;

int LIM, par[MAXN][35], dp[MAXN][35], level[MAXN];
void getParents(int x) {
	for (int i = adj[x]; ~i; i = ant[i]) {
		if (to[i] != par[x][0]) {
			par[to[i]][0] = x;
			dp[to[i]][0] = cost[i];
			level[to[i]] = level[x]+1;
			getParents(to[i]);
		}
	}
}

void preLCA() {
	memset(par,-1,sizeof par);
	memset(dp,0,sizeof dp);
	level[0] = 0;
	getParents(0);
	
	int _ = N;
	LIM = 1;
	while (_ > 1) _/=2, LIM++;
	
	fr(k,1,LIM+1) rp(i,N) {
		par[i][k] = par[par[i][k-1]][k-1];
		dp[i][k] = min(dp[i][k-1],dp[par[i][k-1]][k-1]);
	}
}

int query(int a, int b) {
	if (a == b) return 0;
	if (level[a] < level[b]) swap(a,b);
	int dif = level[a]-level[b];
	int ans = 0x3f3f3f3f;
	for (int i = 0; dif > 0; i++) {
		if (dif&1) {
			ans = min(ans,dp[a][i]);
			a = par[a][i];
		}
		dif>>=1;
	}
	for (int i = LIM; i >= 0; i--) {
		if (par[a][i] != -1 && par[a][i] != par[b][i]) {
			ans = min(ans,min(dp[a][i],dp[b][i]));
			a = par[a][i];
			b = par[b][i];
		}
	}
	if (a != b) ans = min(ans,min(dp[a][0],dp[b][0]));
	return ans;
}

int main() {
	int a, b, w;
	while (scanf("%d%d%d", &N, &M, &S) == 3) {
		rp(i,N) rep[i] = i;
		rp(i,M) scanf("%d%d%d", &a, &b, &w), e[i] = edge(a-1,b-1,w);
		sort(e,e+M);
		memset(adj,-1,sizeof adj); z = 0;
		rp(i,M) {
			if (!sameSet(e[i].a,e[i].b)) {
				unionSet(e[i].a,e[i].b);
				add(e[i].a,e[i].b,e[i].w);
				add(e[i].b,e[i].a,e[i].w);
			}
		}
		preLCA();
		rp(i,S) {
			scanf("%d%d", &a, &b); a--, b--;
			printf("%d\n", query(a,b));
		}
	}
	return 0;
}
