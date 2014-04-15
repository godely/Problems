#include <bits/stdc++.h>
using namespace std;
#define fr(a,b,c) for(int a = b; a < c; a++)
#define rp(a,b) fr(a,0,b)
typedef long long ll;
#define inf 0x3f3f3f3f
#define add(a,b) to[z] = b, ant[z] = adj[a], adj[a] = z++
#define maxn 511
#define maxm 40100
int to[maxm], ant[maxm], adj[maxn], z;

int N, M, a, b;

int ini, fim, fila[1000], walk[1000];
int bfs(int no) {
	ini = fim = 0;
	fila[fim++] = no;
	memset(walk,-1,sizeof walk);
	walk[no] = 0;
	while (ini < fim) {
		int aux = fila[ini++];
		for (int i = adj[aux]; ~i; i = ant[i]) {
			if (walk[to[i]] == -1) {
				fila[fim++] = to[i];
				walk[to[i]] = walk[aux]+1;
			} else if (walk[aux]+walk[to[i]] > 1) return walk[aux]+walk[to[i]]+1;
		}
	}
	return inf;
}

int main() {
	int T, cas = 1;
	scanf("%d", &T);
	while (T--) {
		memset(adj,-1,sizeof adj); z = 0;
		scanf("%d%d", &N, &M);
		rp(i,M) scanf("%d%d", &a, &b), add(a,b), add(b,a);
		int res = inf;
		rp(i,N) res = min(res,bfs(i));
		if (res == inf) printf("Case %d: impossible\n", cas++);
		else printf("Case %d: %d\n", cas++, res);
	}
	return 0;
}