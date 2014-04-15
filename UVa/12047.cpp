#include <bits/stdc++.h>
#define MAXN 100010
using namespace std;
#define fr(a,b,c) for(int a = b; a < c; a++)
#define rp(a,b) fr(a,0,b)

#define add(a,b,c) ant[z] = adj[a], to[z] = b, cost[z] = c, adj[a] = z++
int ant[MAXN], to[MAXN], cost[MAXN], adj[MAXN], z;

struct graf {
	int no, cost;
	bool valid;
	graf() {}
	graf(int no, int cost, bool valid) : no(no), cost(cost), valid(valid) {}
	bool operator<(const graf &lhs) const {
		return cost > lhs.cost;
	}
} aux;

int T, N, M, s, t, p, u, v, c;
priority_queue<graf> fila;
int C[10010][2], mark[10010][2], passo = 0;
bool foi(int k) {
	while (!fila.empty()) fila.pop();
	passo++;
	fila.push(graf(s,0,0));
	mark[s][0] = passo, C[s][0] = 0;
	while (!fila.empty()) {
		aux = fila.top(); fila.pop();
		if (aux.cost > C[aux.no][aux.valid]) continue;
		if (aux.no == t && aux.valid) return aux.cost <= p;
		for (int i = adj[aux.no]; i != -1; i = ant[i]) {
			c = aux.valid|(cost[i] >= k);
			if (mark[to[i]][c] != passo || C[to[i]][c] > aux.cost + cost[i]) {
				mark[to[i]][c] = passo, C[to[i]][c] = aux.cost + cost[i];
				fila.push(graf(to[i], C[to[i]][c], c));
			}
		}
	}
	return 0;
}

int main() {
	scanf("%d", &T);
	while (T--) {
		memset(adj, -1, sizeof adj); z = 0;
		scanf("%d%d%d%d%d", &N, &M, &s, &t, &p);
		rp(i,M) {
			scanf("%d%d%d", &u, &v, &c);
			add(u,v,c);
		}
		int ini = -1, fim = 100000, meio;
		while (fim > -1 && ini < fim) {
			meio = (ini+fim+1)>>1;
			if (foi(meio)) ini = meio;
			else fim = meio-1;
		}
		printf("%d\n", ini);
	}
}