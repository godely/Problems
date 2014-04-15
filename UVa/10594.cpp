#include <bits/stdc++.h>
using namespace std;
#define fr(a,b,c) for(int a = b; a < c; a++)
#define rp(a,b) fr(a,0,b)
#define mp make_pair

#define MAXN 200
#define MAXM 5*5000
#define add(a,b,c,d) to[z] = b, cap[z] = c, cost[z] = d, ant[z] = adj[a], adj[a] = z++
#define LL long long
LL to[MAXM], cap[MAXM], cost[MAXM], ant[MAXM], z;
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

//EXEMPLO DE USO:
//UVA 10594 - DATA FLOW
//TEMPO DE EXECUÇÃO: 0.164s
int main() {
	LL n, m, d, k;
	LL u, v, c;
	pair<LL,LL> res;
	while (scanf("%lld%lld", &n, &m) == 2) {
		memset(adj,-1,sizeof(adj)); z = 0;
		rp(i,m) scanf("%lld%lld%lld", &u, &v, &c), add(u,v,0,c), add(v,u,0,-c), add(v,u,0,c), add(u,v,0,-c);
		scanf("%lld%lld", &d, &k);
		for (int i = 0; i < z; i+=2) cap[i] = k;
		add(0,1,d,0);
		add(1,0,0,0);
		res = mcmf(0,n);
		if (res.first < d) printf("Impossible.\n");
		else printf("%lld\n", res.second);
	}
	return 0;
}