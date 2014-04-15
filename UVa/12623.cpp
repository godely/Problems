#include <bits/stdc++.h>
using namespace std;
#define fr(a,b,c) for(int a = b; a < c; a++)
#define rp(a,b) fr(a,0,b)
#define mp make_pair

#define MAXN 200
#define MAXM 5*5000
#define add(a,b,c,d) frm[z] = a, to[z] = b, cap[z] = c, cost[z] = d, ant[z] = adj[a], adj[a] = z++
#define LL long long
LL frm[MAXM], to[MAXM], cap[MAXM], cost[MAXM], ant[MAXM], z;
LL adj[MAXN], from[MAXN], edgeTo[MAXN], minflow[MAXN], dist[MAXN];

//reset: memset(adj,-1,sizeof adj); z = 0;

LL dijkstra(LL source, LL sink) {
	if (source == sink) return 0;
	memset(from,-1,sizeof from);
	from[source] = -2;
	dist[source] = 0;
	minflow[source] = 1LL<<60;
	pair<LL,LL> v;
	priority_queue<pair<LL,LL>, vector<pair<LL,LL> >, greater<pair<LL,LL> > > pq;
	pq.push(mp(0,source));
	while (!pq.empty()) {
		v = pq.top(); pq.pop();
		if (v.first > dist[v.second]) continue;
		if (v.second == sink) break;
		for (LL i = adj[v.second]; i != -1; i = ant[i]) {
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

pair<LL,LL> mcmf(LL source, LL sink) {
	pair<LL,LL> ret(0,0);
	LL flow, k;
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

void print() {
	rp(i,z) {
		printf("%lld %lld %lld %lld\n", frm[i], to[i], cap[i], cost[i]);
	}
}

vector<int> edgeIds[100];
int use[100], fim[100];
int main() {
	int F, P, c, n, f;
	int T; scanf("%d", &T);
	while (T--) {
		memset(adj,-1,sizeof adj); z = 0;
		scanf("%d%d", &F, &P);
		rp(i,F) {
			edgeIds[i].clear();
			add(0,i+1,1,0), add(i+1,0,0,0);
		}
		rp(i,P) {
			fim[i] = z;
			add(F+i+1,F+P+1,1,0), add(F+P+1,F+i+1,0,0);
		}
		rp(i,P) {
			scanf("%d%d", &c, &n);
			rp(j,n) {
				scanf("%d", &f);
				edgeIds[f+1].push_back(z);
				add(f+1,F+i+1,1,c), add(F+i+1,f+1,0,-c);
			}
		}
		pair<LL,LL> res = mcmf(0,F+P+1);
		if (res.first != F) printf("No solution.\n");
		else {
			LL ans = res.second;
			printf("%lld", ans);

			LL remCost = 0;
			fr(i,1,F+1) {
				rp(j,edgeIds[i].size()) {
					use[i-1] = to[edgeIds[i][j]]-F-1;
					rp(k,i-1) if (use[k] == use[i-1]) goto rs;
					rp(k,z) cap[k] = !(k&1);
					rp(k,i) cap[fim[use[k]]] = 0;
					for (int k = adj[0]; ~k; k = ant[k]) if (to[k] <= i) cap[k] = 0;
					res = mcmf(0,F+P+1);
					if (res.first == F-i && res.second+remCost+cost[edgeIds[i][j]] == ans) {
						remCost += cost[edgeIds[i][j]];
						break;
					}
					rs:;
				}
			}
			rp(i,F) printf(" %d", use[i]);
			printf("\n");
		}
	}
	return 0;
}