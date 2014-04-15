#include <bits/stdc++.h>
using namespace std;
#define fr(a,b,c) for(int a = b; a < c; a++)
#define rp(a,b) fr(a,0,b)
#define Y(x) (2*x)
#define N(x) (2*x + 1)
#define NEG(x) (x^1)
#define MAXM 2000

#define add(a,b) to[z] = b, ant[z] = adj[a], adj[a] = z++
int to[MAXM], ant[MAXM], adj[MAXM], z;
int mark[MAXM], vis[MAXM], comp[MAXM], st[MAXM], stSize, c, k;
int num[MAXM], low[MAXM];

void scc(int u) {
	st[stSize++] = u;
	mark[u] = vis[u] = 1; num[u] = low[u] = k++;
	for (int i = adj[u]; i != -1; i = ant[i]) {
		if (!mark[to[i]]) scc(to[i]);
		if (vis[to[i]]) low[u] = min(low[u], low[to[i]]);
	}
	if (low[u] == num[u]) {
		int v;
		do {
			v = st[--stSize];
			vis[v] = 0;
			comp[v] = c;
		} while (u != v);
		c++;
	}
}

void insert(int a, int b) {
	add(NEG(a),b);
	add(NEG(b),a);
}

bool twosat(int n) {
	fr(i,1,n+1) {
		if (!mark[Y(i)]) scc(Y(i));
		if (!mark[N(i)]) scc(N(i));
	}
	fr(i,1,n+1) if (comp[Y(i)] == comp[N(i)]) return 0;
	return 1;
}

int main() {
	int T, n, m, p;
	int x_i, x_j, y_i, y_j;
	scanf("%d", &T);
	while (T--) {
		memset(mark,0,sizeof mark);
		memset(vis,0,sizeof vis);
		memset(adj,-1,sizeof adj);
		z = k = c = 0;
		scanf("%d%d%d", &n, &m, &p);
		rp(i,p) {
			scanf("%d%d%d%d", &x_i, &y_i, &x_j, &y_j);
			y_i+=n, y_j+=n;
			if (y_i != y_j) {
				insert(Y(x_i)^(y_i>y_j),Y(x_j)^(y_i>y_j));
				if (x_i != x_j) insert(Y(y_j)^(x_i>x_j),Y(x_j)^(y_i>y_j));
			}
			if (x_i != x_j) {
				insert(Y(y_j)^(x_i>x_j),Y(y_i)^(x_i>x_j));
				if (y_i != y_j) insert(Y(x_i)^(y_i>y_j),Y(y_i)^(x_i>x_j));
			}
		}
		if (twosat(n+m)) printf("Yes\n");
		else printf("No\n");
	}
	return 0;
}