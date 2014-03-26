#include <bits/stdc++.h>
using namespace std;
#define fr(a,b,c) for (int a = b; a < c; a++)
#define rp(a,b) fr(a,0,b)
#define cl(a,b) memset(a,b,sizeof (a))

#define MAXN 1001
#define MAXM 100100

#define add(a,b,c,d,e) to[z] = b, open[z] = c, closed[z] = d, cost[z] = e, ant[z] = adj[a], adj[a] = z++
int to[MAXM], open[MAXM], closed[MAXM], cost[MAXM], ant[MAXM], adj[MAXN], z;
int C[MAXN];

struct st{
	int no, cost;
	st() {}
	st(int no, int cost) : no(no), cost(cost) {}

	bool operator<(const st &lhs) const {
		return cost > lhs.cost;
	}
};

int dij(int s, int t) {
	cl(C,0x3f);
	C[s] = 0;
	priority_queue<st> pq;
	pq.push(st(s,0));
	st aux;
	int u, auxCost;
	while (!pq.empty()) {
		aux = pq.top(); pq.pop();
		u = aux.no;
		auxCost = aux.cost;
		if (auxCost > C[u]) continue;
		if (u == t) return auxCost;
		for (int i = adj[u]; ~i; i = ant[i]) {
			int tmp = auxCost % (open[i]+closed[i]);

			if (cost[i] <= open[i]) {
				if (C[to[i]] > auxCost + cost[i] + open[i] + closed[i] - tmp) {
					C[to[i]] = auxCost + cost[i] + open[i] + closed[i] - tmp;
					pq.push(st(to[i],C[to[i]]));
				}
				
				if (tmp + cost[i] <= open[i] && C[to[i]] > auxCost + cost[i]) {
					C[to[i]] = auxCost + cost[i];
					pq.push(st(to[i],C[to[i]]));
				}
			}
		}
	}
	return -1;
}

int main() {
	int n, m, s, t;
	int u, v, a, b, c;
	while (scanf("%d%d%d%d", &n, &m, &s, &t) == 4) {
		cl(adj,-1); z = 0;
		rp(i,m) {
			scanf("%d%d%d%d%d", &u, &v, &a, &b, &c);
			add(u,v,a,b,c);
		}
		printf("%d\n", dij(s,t));
	}
}