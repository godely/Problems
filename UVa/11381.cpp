//Stor Algorithm of MCMF
#include <bits/stdc++.h>
using namespace std;
#define fr(a,b,c) for(int a = b; a < c; a++)
#define rp(a,b) fr(a,0,b)
#define mp make_pair

#define MAXN 500
#define MAXM 9000
#define add(a,b,c,d) to[z] = b, cap[z] = c, cost[z] = d, ant[z] = adj[a], adj[a] = z++
#define LL int
LL to[MAXM], cap[MAXM], cost[MAXM], ant[MAXM], z;
LL adj[MAXN], from[MAXN], edgeTo[MAXN], minflow[MAXN], dist[MAXN];

//reset: memset(adj,-1,sizeof adj); z = 0;

LL dijkstra(LL source, LL sink) {
	if (source == sink) return 0;
	memset(from,-1,sizeof from);
	from[source] = -2;
	dist[source] = 0, dist[sink] = 0;
	minflow[source] = 1<<30;
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

LL E[30][30];
char A[1111], B[1111];
int sizeA, sizeB;

int main() {
	int T;
	scanf("%d", &T);
	while (T--) {
		scanf("%s%s", A, B);
		sizeA = strlen(A); sizeB = strlen(B);
		memset(E,0,sizeof E);
		rp(i,sizeA-1) if (!E[A[i]-'a'][A[i+1]-'a']) E[A[i]-'a'][A[i+1]-'a'] = (i+1)*(i+1);
		memset(adj,-1,sizeof(adj)); z = 0;
		rp(i,sizeB) {
			add(0,2*(i+1)-1,1,0); add(2*(i+1)-1,0,0,0);
			add(2*(i+1),2*sizeB+1,1,0); add(2*sizeB+1,2*(i+1),0,0);
			fr(j,i+1,sizeB) if (E[B[i]-'a'][B[j]-'a']) add(2*(i+1)-1,2*(j+1),1,E[B[i]-'a'][B[j]-'a']), add(2*(j+1),2*(i+1)-1,0,-E[B[i]-'a'][B[j]-'a']);
		}
		pair<LL,LL> ret = mcmf(0,2*sizeB+1);
		printf("%d %d\n", sizeB-ret.first, ret.second);
	}
	return 0;
}