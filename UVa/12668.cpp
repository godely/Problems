#include <bits/stdc++.h>
using namespace std;
#define fr(a,b,c) for(int a = b; a < c; a++)
#define rp(a,b) fr(a,0,b)
#define CL(a,b) memset(a,b,sizeof a)
#define oo 0x3f3f3f3f

#define add(a,b,c) to[z] = b, cap[z] = c, ant[z] = adj[a], adj[a] = z++
#define MAXN 10500
#define MAXM 210000

int to[MAXM], cap[MAXM], ant[MAXM], adj[MAXN], adj2[MAXN], z;
int level[MAXN], fila[MAXN], ini, fim;
bool bfs(int source, int sink) {
	CL(level,-1);
	ini = fim = 0;
	level[source] = 0;
	fila[fim++] = source;
	while (ini < fim) {
		int x = fila[ini++];
		if (x == sink) return 1;
		for (int i = adj[x]; ~i; i = ant[i]) {
			if (cap[i] && level[to[i]] == -1) {
				level[to[i]] = level[x]+1;
				fila[fim++] = to[i];
			}
		}
	}
	return 0;
}

int dfs(int x, int sink, int f) {
	if (x == sink) return f;
	for (int &i = adj2[x]; ~i; i = ant[i]) {
		if (cap[i] && level[to[i]] == level[x]+1) {
			int aux = dfs(to[i],sink,min(f,cap[i]));
			if (aux) {
				cap[i]-=aux;
				cap[i^1]+=aux;
				return aux;
			}
		}
	}
	return 0;
}

int maxflow(int source, int sink) {
	int f = 0, aux;
	while (bfs(source,sink)) {
		memcpy(adj2,adj,sizeof adj);
		while (aux = dfs(source,sink,oo)) f+=aux;
	}
	return f;
}

char g[111][111];
int idh[111][111], idv[111][111];
int main() {
	int n, s, t, m, a, b, c;
	int cas = 1;
	while (scanf("%d", &n) == 1) {
		CL(adj,-1); z = 0;
		rp(i,n) scanf("%s", g[i]);
		int no = 2;
		CL(idh,-1);
		CL(idv,-1);
		rp(i,n) rp(j,n) if (g[i][j] == '.') {
			if (idh[i][j] == -1) {
				fr(k,j,n) {
					if (g[i][k] != '.') break;
					idh[i][k] = no;
				}
				add(0,no,1);
				add(no,0,0);
				no++;
			}
			if (idv[i][j] == -1) {
				fr(k,i,n) {
					if (g[k][j] != '.') break;
					idv[k][j] = no;
				}
				add(no,1,1);
				add(1,no,0);
				no++;
			}
			add(idh[i][j],idv[i][j],1);
			add(idv[i][j],idh[i][j],0);
		}
		printf("%d\n", maxflow(0,1));
	}
	return 0;
}