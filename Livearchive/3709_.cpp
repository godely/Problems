#include <bits/stdc++.h>
using namespace std;
#define fr(a,b,c) for(int a = b; a < c; a++)
#define rp(a,b) fr(a,0,b)
#define inf 0x3f3f3f3f
#define pb push_back
#define mp make_pair
#define MAXN 1300
#define MAXM 4*MAXN
#define F first
#define S second

int gcd(int a, int b) {
	return (!b) ? a : gcd(b, a%b);
}

bool cmp(const pair<int,int> &a, const pair<int,int> &b) {
	return a.F*b.S < b.F*a.S;
}

int adj[MAXN], ant[MAXM], from[MAXM], to[MAXM], ori[MAXM], cap[MAXM], z;
#define add(a,b,c) to[z] = b, from[z] = a, ori[z] = c, cap[z]=c, ant[z]=adj[a], adj[a] = z++
//limpar o grafo : memset(adj,-1,sizeof(adj)); z=0;
int level[MAXN], fila[MAXN], copy_adj[MAXN];

int bfs(int source ,int sink){
	memset(level,-1,sizeof(level));
	level[source] = 0;
	int pos=0, tam=0;
	fila[tam++] = source;
	while(pos < tam){
		int now= fila[pos++];
		for(int i=adj[now] ; i >= 0 ; i=ant[i]){
			if(cap[i] && level[to[i]] == -1){
				level[to[i]] = level[now]+1;
				fila[tam++]=to[i];
			}
		}
	}
	return level[sink] != -1;
}

int dfs(int no,int sink, int flow){
	if(no == sink) return flow;
	for(int &i = copy_adj[no]; i>=0 ; i = ant[i]){
		if(cap[i] && level[no]+1 == level[to[i]]){
			int nflow=dfs(to[i],sink,min(flow,cap[i]));
			if(nflow){
				cap[i] -= nflow, cap[i^1] += nflow;
				return nflow;
			}
		}
	}
	return 0;
}

long long maxflow(int source, int sink){
	long long mf=0;
	while(true){
		if(bfs(source,sink)){
			memcpy(copy_adj,adj,sizeof(adj));
			while(true){
				int new_f = dfs(source,sink,1<<30);
				if(new_f) mf+=new_f;
				else break;
			}
		}else break;
	}
	return mf;
}

void reset(int n, int a, int b) {
	rp(i,z) {
		if (ori[i] == -1) cap[i] = a;
		else if (ori[i] == -2) cap[i] = b;
		else cap[i] = ori[i];
	}
}

vector<pair<int, int> > G;

int can[MAXN];
bool teste(int n, int m, int k) {
	reset(n, G[k].F, G[k].S);
	long long s = maxflow(0,n+m+1);
	memset(can, 0, sizeof can);
	for (int i = adj[0]; i != -1; i = ant[i]) {
		if (!cap[i]) can[to[i]] = 1;
	}
	bool ok = 0;
	int S = 0, p, q;
	for (int i = n+1; i <= n+m; i++) {
		p = q = 0;
		for (int j = adj[i]; j != -1; j = ant[j]) {
			if (to[j] != n+m+1 && can[to[j]] > 0) {
				p++;
				//printf("(%d) %d %d\n", i, to[j], can[to[j]]);
				if (can[to[j]] == 1) q++;
				can[to[j]] = 2;
			}
		}
		//printf("%d: %d %d\n", i, p, q);
		if (p == 2) ok = 1, S += G[k].S - q*G[k].F;
	}
	return ok && S >= 0;
}

vector<int> resArr;
int main() {
	int n, m, u, v;
	bool ok = 0;
	while (scanf("%d%d", &n, &m) == 2) {
		if (ok) printf("\n");
		else ok = 1;
		if (!m) {
			printf("1\n1\n");
			continue;
		}
		memset(adj,-1,sizeof(adj)); z=0;
		fr(i,1,n+1) {
			add(0,i,-1); add(i,0,0);
		}
		fr(i,1,m+1) {
			scanf("%d%d", &u, &v);
			add(u,n+i,inf); add(n+i,u,0);
			add(v,n+i,inf); add(n+i,v,0);
			add(n+i,n+m+1,-2); add(n+m+1,n+i,0);
		}
		G.clear();
		fr(j,1,m+1) rp(i,(j*(j-1))/2+1) if (gcd(i,j) == 1) G.pb(mp(i,j));
		sort(G.begin(), G.end(), cmp);
		//rp(i,G.size()) printf("%d/%d\n", G[i].F, G[i].S);
		int ini = 0, fim = G.size()-1, meio;
		while (ini < fim) {
			meio = (ini+fim+1)/2;
			if (teste(n, m, meio)) ini = meio;
			else fim = meio-1;
		}
		teste(n, m, ini);
		int res = 0;
		resArr.clear();
		for (int i = adj[0]; i != -1; i = ant[i]) {
			if (!cap[i]) res++, resArr.push_back(to[i]);
		}
		sort(resArr.begin(), resArr.end());
		printf("%d\n", res);
		for (int i = 0; i < res; i++) printf("%d\n", resArr[i]);
	}
	return 0;
}
