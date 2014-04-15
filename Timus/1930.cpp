#include <bits/stdc++.h>
using namespace std;
#define fr(a,b,c) for(int a = b; a < c; a++)
#define rp(a,b) fr(a,0,b)
#define maxn 30000
#define maxm 300000
#define mp make_pair
#define add(a,b,c) to[z] = b, tp[z] = c, ant[z] = adj[a], adj[a] = z++
int to[maxm], tp[maxm], ant[maxm], adj[maxn], z;

typedef pair<int,int> pii;

struct st {
	int F, S, cost;
	st() {}
	st(int F, int S, int cost = 0) : F(F), S(S), cost(cost) {}
	
	bool operator<(const st &lhs) const {
		return cost > lhs.cost;
	}
} aux;

priority_queue<st> fila;
int cost[maxn][3];
int main() {
	memset(adj,-1,sizeof adj); z = 0;
	memset(cost,0x3f,sizeof cost);
	int n, m, a, b;
	scanf("%d%d", &n, &m);
	rp(i,m) {
		scanf("%d%d", &a, &b);
		add(a,b,1);
		add(b,a,0);
	}
	scanf("%d%d", &a, &b);
	while (!fila.empty()) fila.pop();
	fila.push(st(a,0));
	fila.push(st(a,1));
	cost[a][0] = 0;
	cost[a][1] = 0;
	while (!fila.empty()) {
		aux = fila.top(); fila.pop();
		//printf("%d %d %d\n", aux.F, aux.S, cost[aux.F][aux.S]);
		if (aux.cost > cost[aux.F][aux.S]) continue;
		if (aux.F == b) {
			printf("%d\n", aux.cost);
			break;
		}
		for (int i = adj[aux.F]; i != -1; i = ant[i]) {
			//printf("> %d %d\n", to[i], tp[i]);
			if (cost[aux.F][aux.S] + !(aux.S == tp[i]) < cost[to[i]][tp[i]]) {
				cost[to[i]][tp[i]] = cost[aux.F][aux.S] + !(aux.S == tp[i]);
				fila.push(st(to[i], tp[i], cost[to[i]][tp[i]]));
			}
		}
	}
	return 0;
}