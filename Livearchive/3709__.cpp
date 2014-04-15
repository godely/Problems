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

int grau[MAXN];
void reset(int n, int m, int a, int b) {
	rp(i,z) {
		if (ori[i] == -1) cap[i] = m*b;
		else if (ori[i] == -2) cap[i] = 2*a + (m - grau[from[i]])*b;
		else if (ori[i] == -3) cap[i] = b;
		else cap[i] = 0;
	}
	printf("\n");
}

vector<pair<int, int> > G;
vector<int> res;
bool teste(int n, int m, int k) {
	reset(n, m, G[k].F, G[k].S);
	long long s = maxflow(0,n+1);
	res.clear();
	for (int i = adj[0]; i != -1; i = ant[i]) {
		if (cap[i] > 0) res.push_back(to[i]);
	}
	rp(i,z) printf("%d, %d = %d\n", from[i], to[i], cap[i]);
	printf("%d %d/%d %lld %d\n", k, G[k].F, G[k].S, s, res.size());
	return res.empty();
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
		memset(adj,-1,sizeof(adj)); z=0; memset(grau, 0, sizeof grau);
		fr(i,1,n+1) {
			add(0,i,-1); add(i,0,0); //-1 == edge m*B
			add(i,n+1,-2); add(n+1,i,0); //-2 == edge (m + 2*A - di)*B
		}
		fr(i,1,m+1) {
			scanf("%d%d", &u, &v);
			grau[u]++; grau[v]++;
			add(u,v,-3); add(v,u,-3); //-3 == edge 1*B
		}
		fr(i,1,n+1) printf("%d: %d\n", i, grau[i]);
		G.clear();
		fr(j,1,m+1) rp(i,(j*(j-1))/2+1) if (gcd(i,j) == 1) G.pb(mp(i,j));
		sort(G.begin(), G.end(), cmp);
		//rp(i,G.size()) printf("%d/%d\n", G[i].F, G[i].S);
		int ini = 0, fim = G.size()-1, meio;
		/*while (ini < fim) {
			meio = (ini+fim+1)/2;
			if (teste(n, m, meio)) ini = meio;
			else fim = meio-1;
		}*/
		rp(i,G.size()) {
			if (teste(n, m, i)) break;
		}	
		printf("%d\n", res.size());
		rp(i,res.size()) printf("%d\n", res[i]);
	}
	return 0;
}
