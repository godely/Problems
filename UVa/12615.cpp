#include <bits/stdc++.h>
using namespace std;
#define fr(a,b,c) for(int a = b; a < c; a++)
#define rp(a,b) fr(a,0,b)
#define INF 0x3f3f3f3f

#define maxn 10100
#define maxm 300100
#define add(a,b,c) to[z] = b, cost[z] = c, ant[z] = adj[a], adj[a] = z++

int to[maxm], cost[maxm], ant[maxm], adj[maxn], z;
int parent[maxn], st[maxn], sz, op[maxn];
bool mark[maxn], isCycle[maxn];

int a, b, c;
void dfs(int u) {
	mark[u] = 1;
	st[sz++] = u;
	for (int i = adj[u]; ~i; i = ant[i]) {
		if (to[i] != parent[u]) {
			if (mark[to[i]]) {
				if (!isCycle[u]) {
					int a = st[sz-1], b = st[sz-2], c = st[sz-3];
					sz-=3;
					isCycle[a] = isCycle[b] = isCycle[c] = 1;
					for (int i = adj[a]; ~i; i = ant[i]) {
						if (to[i] == b) op[c] = cost[i];
						if (to[i] == c) op[b] = cost[i];
					}
					for (int i = adj[b]; ~i; i = ant[i]) {
						if (to[i] == c) {
							op[a] = cost[i];
							break;
						}
					}
				}
			} else parent[to[i]] = u, dfs(to[i]);
		}
	}
	if (!isCycle[u]) sz--;
}

int solve(int no, bool enterCycle, int prot) {

	if (!enterCycle) {
		if (!isCycle[no]) {
			if (!prot) {
			
			} else if (prot == 1) {
				ll ret = INF;
				for (int i = adj[no]; ~i; i = ant[i]) {
					if (to[i] != parent[no]) {
						parent[to[i]] = u;
						temp1 = min(temp1, cost[i] + solve(to[i], isCycle[to[i]], 2));
					}
				}
			} else {
				ll ret = 0;
				for (int i = adj[no]; ~i; i = ant[i]) {
					if (to[i] != parent[no]) {
						parent[to[i]] = u;
						ret += min(solve(to[i], isCycle[to[i]], 1), cost[i]+solve(to[i], isCycle[to[i]], 2));
					}
				}
				return dp[no][enterCycle][prot] = ret;
			}
		} else {
		
		}
	} else {
	
	}
}

int main() {
	int T, N, M; scanf("%d", &T);
	int u, v, w;
	while (T--) {
		memset(adj,-1,sizeof adj); z = 0;
		scanf("%d%d", &N, &M);
		rp(i,M) {
			scanf("%d%d%d", &u, &v, &w); u--; v--;
			add(u,v,w);
			add(v,u,w);
		}
		memset(mark,0,sizeof mark);
		memset(parent,-1,sizeof parent);
		sz = 0;
		dfs(0);
		rp(i,N) printf("%d %d\n", i+1, isCycle[i]);
	}
	return 0;
}