#include <bits/stdc++.h>
using namespace std;
#define fr(a,b,c) for(int a = b; a < c; a++)
#define rp(a,b) fr(a,0,b)
#define FR(a,b,c) for(int a = b; a <= c; a++)
#define MAXN 210
#define MAXM 30000
#define inf 0x3f3f3f
#define F(x) (2*x)
#define S(x) (2*x+1)

//-------------MAXFLOW---------------
int adj[MAXN], ant[MAXM], from[MAXM], to[MAXM], cap[MAXM], pat[MAXM], z;
#define add(a,b,c) from[z] = a, pat[z] = c, to[z] = b, cap[z] = c, ant[z] = adj[a], adj[a] = z++
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

int T, N;
double D;

int n, m, MAXI;
double X[MAXN], Y[MAXN];

bool ok;

double dist2(int i, int j) {
	return (X[i]-X[j])*(X[i]-X[j]) + (Y[i]-Y[j])*(Y[i]-Y[j]);
}

int main() {
	scanf("%d", &T);
	while (T--) {
		scanf("%d%lf", &N, &D);
		D*=D;
		memset(adj,-1,sizeof(adj)); z=0;
		MAXI = 0;
		FR(i,1,N) {
			scanf("%lf%lf%d%d", &X[i], &Y[i], &n, &m);
			MAXI += n;
			if (m > 0) {
				add(F(i),S(i),m);
				add(S(i),F(i),0);
			}
			if (n > 0) {
				add(0,F(i),n);
				add(F(i),0,0);
			}
		}
		FR(i,1,N) {
			FR(j,i+1,N) {
				if (dist2(i,j) <= D) {
					add(S(i),F(j),inf);
					add(F(j),S(i),0);
					add(S(j),F(i),inf);
					add(F(i),S(j),0);
				}
			}
		}
		ok = 0;
		FR(i,1,N) {
			rp(j,z) cap[j] = pat[j];
			if (maxflow(0,F(i)) == MAXI) {
				if (ok) printf(" %d", i-1);
				else printf("%d", i-1), ok = 1;
			}
		}
		if (!ok) printf("-1");
		printf("\n");
	}
	return 0;
}