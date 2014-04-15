#include <bits/stdc++.h>
using namespace std;
#define fr(a,b,c) for(int a = b; a < c; a++)
#define rp(a,b) fr(a,0,b)
#define inf 0x3f3f3f3f
#define maxn 510
#define maxm 122000
#define mp make_pair
#define add(a,b,c,d) to[z] = b, cap[z] = c, cost[z] = d, ant[z] = adj[a], adj[a] = z++
int to[maxm], cap[maxm], cost[maxm], ant[maxm], adj[maxn], z;
int from[maxn], edgeTo[maxn], minflow[maxn], dist[maxn];
int adjList[2][maxn][maxn], sz[2][maxn];
int cnt[2][maxn];
int dp[maxn][maxn], mark[maxn][maxn], passo = 0;

int N, M;

int dijkstra(int source, int sink) {
	if (source == sink) return 0;
	memset(from,-1,sizeof from);
	from[source] = -2;
	dist[source] = 0;
	minflow[source] = 1<<28;
	pair<int,int> v;
	priority_queue<pair<int,int>, vector<pair<int,int> >, greater<pair<int,int> > > pq;
	pq.push(mp(0,source));
	while (!pq.empty()) {
		v = pq.top(); pq.pop();
		if (v.first > dist[v.second]) continue;
		if (v.second == sink) break;
		for (int i = adj[v.second]; i != -1; i = ant[i]) {
			if (cap[i] && (from[to[i]] == -1 || dist[to[i]] > v.first + cost[i])) {
				dist[to[i]] = v.first + cost[i];
				from[to[i]] = v.second;
				edgeTo[to[i]] = i;
				minflow[to[i]] = min(minflow[v.second], cap[i]);
				pq.push(mp(dist[to[i]],to[i]));
			}
		}
	}
	if (from[sink] != -1) return minflow[sink];
	return 0;
}

pair<int,int> mcmf(int source, int sink) {
	pair<int,int> ret(0,0);
	int flow, k;
	while ((flow = dijkstra(source, sink))) {
		k = sink;
		while (from[k] != -2) {
			cap[edgeTo[k]]-=flow, cap[edgeTo[k]^1]+=flow;
			ret.second += cost[edgeTo[k]]*flow;
			k = from[k];
		}
		ret.first += flow;
		//printf("%d %d\n", ret.first, ret.second);
	}
	return ret;
}

int dfs(int no, int id) {
	int ret = 1;
	//printf("%d %d %d, %d %d\n", no, id, sz[id][no], adjList[id][no][0], adjList[id][no][1]);
	rp(i,sz[id][no]) ret += dfs(adjList[id][no][i],id);
	return cnt[id][no] = ret;
}

int go(int x, int y) {
	if (mark[x][y] == passo) return dp[x][y];
	mark[x][y] = passo;
	
	
	if (sz[0][x] == 0) dp[x][y] = cnt[1][y]-1;
	else if (sz[1][y] == 0) dp[x][y] = cnt[0][x]-1;
	else {
		rp(i,sz[0][x]) rp(j,sz[1][y]) go(adjList[0][x][i],adjList[1][y][j]);
		
		memset(adj,-1,sizeof adj);
		z = 0;
		int pA = 0, pB = 1, trocou = 0;
		
		if (sz[pB][y] >= sz[pA][x]) {
			swap(pA,pB);
			swap(x,y);
			swap(N,M);
			trocou = 1;
		}

		if (sz[pA][x] >= sz[pB][y]) {
			rp(i,sz[pA][x]) {
				add(0,adjList[pA][x][i],1,0), add(adjList[pA][x][i],0,0,0);
				add(adjList[pA][x][i],500,1,cnt[pA][adjList[pA][x][i]]), add(500,adjList[pA][x][i],1,-cnt[pA][adjList[pA][x][i]]);

				rp(j,sz[pB][y]) {
					if (!trocou) add(adjList[pA][x][i],N+adjList[pB][y][j],1,dp[adjList[pA][x][i]][adjList[pB][y][j]]), add(N+adjList[pB][y][j],adjList[pA][x][i],0,-dp[adjList[pA][x][i]][adjList[pB][y][j]]);
					else add(adjList[pA][x][i],N+adjList[pB][y][j],1,dp[adjList[pB][y][j]][adjList[pA][x][i]]), add(N+adjList[pB][y][j],adjList[pA][x][i],0,-dp[adjList[pB][y][j]][adjList[pA][x][i]]);
				}
			}
			rp(i,sz[pB][y]) {
				add(N+adjList[pB][y][i],501,1,0), add(501,N+adjList[pB][y][i],0,0);
			}
			add(500,501,sz[pA][x]-sz[pB][y],0), add(501,500,0,0);
		}
		
		if (trocou) {
			swap(x,y);
			swap(N,M);
		}
		
		dp[x][y] = mcmf(0,501).second;
	}

	return dp[x][y];
}

int a;
int main() {
	memset(mark,0,sizeof mark);
	int T;
	scanf("%d", &T);
	while (T--) {
		memset(sz,0,sizeof sz);
		scanf("%d", &N);
		rp(i,N) scanf("%d", &a), adjList[0][a][sz[0][a]++] = i+1;
		dfs(0,0);
		scanf("%d", &M);
		rp(i,M) scanf("%d", &a), adjList[1][a][sz[1][a]++] = i+1;
		dfs(0,1);
		passo++;
		printf("%d\n", go(0,0));
	}
}