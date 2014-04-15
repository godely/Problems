#include <bits/stdc++.h>
using namespace std;
#define fr(a,b,c) for(int a = b; a < c; a++)
#define rp(a,b) fr(a,0,b)
#define MAXN 700
#define MAXM 6*MAXN
#define inf 0x3f3f3f3f

//-------------MAXFLOW---------------
int adj[MAXN], ant[MAXM], from[MAXM], to[MAXM], cap[MAXM], z;
#define add(a,b,c) from[z] = a, to[z] = b, cap[z] = c, ant[z] = adj[a], adj[a] = z++
int level[MAXN], fila[MAXN], copy_adj[MAXN];

int bfs(int source, int sink) {
	memset(level, -1, sizeof level);
	level[source] = 0;
	int pos = 0, tam = 0;
	fila[tam++] = source;
	while (pos < tam) {
		int now = fila[pos++];
		for (int i = adj[now]; i >= 0; i = ant[i]) {
			if (cap[i] && level[to[i]] == -1) {
				level[to[i]] = level[now]+1;
				fila[tam++] = to[i];
			}
		}
	}
	return level[sink] != -1;
}

int dfs(int no, int sink, int flow) {
	if (no==sink) return flow;
	for (int &i = copy_adj[no]; i>=0; i = ant[i]) {
		if (cap[i] && level[no]+1 == level[to[i]]) {
			int nflow = dfs(to[i], sink, min(flow, cap[i]));
			if (nflow) {
				cap[i] -= nflow, cap[i^1] += nflow;
				return nflow;
			}
		}
	}
	return 0;
}

long long maxflow(int source, int sink) {
	long long mf = 0;
	while(1) {
		if (bfs(source, sink)) {
			memcpy(copy_adj,adj,sizeof adj);
			while (1) {
				int new_f = dfs(source, sink, 1<<30);
				if (new_f) mf += new_f;
				else break;
			}
		} else break;
	}
	return mf;
}
//--------------END MAXFLOW--------------

int N, M, G;
int pts[MAXN], LEFT[MAXN][MAXN];

int a, b, k, score;
char str[10];
bool ok;
int main() {
	while (scanf("%d%d%d", &N, &M, &G) == 3 && N > 0) {
		fr(i,0,N) {
			pts[i] = 0;
			fr(j,i+1,N) LEFT[i][j] = M;
		}
		rp(i,G) {
			scanf("%d%s%d", &a, str, &b);
			LEFT[min(a,b)][max(a,b)]--;
			if (str[0] == '=') pts[a]++, pts[b]++;
			else pts[b] += 2;
		}
		fr(j,1,N) {
			pts[0] += 2*LEFT[0][j];
		}
		score = 0;
		k = 2*N;
		ok = 1;
		memset(adj,-1,sizeof(adj)); z=0;
		fr(i,1,N) {
			if (pts[0]-1-pts[i] < 0) {
				ok = 0;
				break;
			}
			add(0,i,inf); add(i,0,inf);
			add(N+i-1,2*N-1,pts[0]-1-pts[i]); add(2*N-1,N+i-1,0);
			fr(j,i+1,N) {
				if (LEFT[i][j] > 0) {
					score += 2*LEFT[i][j];
					add(i,k,2*LEFT[i][j]); add(k,i,0);
					add(k,N+i-1,inf); add(N+i-1,k,0);
					add(k,N+j-1,inf); add(N+j-1,k,0);
					k++;
				}
			}
		}
		if (!ok || maxflow(0,2*N-1) != score) printf("N%c",10);
		else printf("Y%c",10);
	}
	return 0;
}