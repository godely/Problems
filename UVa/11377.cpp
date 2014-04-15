#include <cstdio>
#include <cstdlib>
#include <algorithm>
#include <vector>
#include <cmath>
#include <map>
#include <set>
#include <iostream>
#include <cstring>
#include <queue>
using namespace std;
#define MP make_pair
typedef pair<int,int> pii;
#define fr(a,b,c) for(int a = b; a < c; a++)
#define rp(a,b) fr(a,0,b)
#define cl(a,b) memset(a,b,sizeof a)
#define cl(a,b) memset(a,b,sizeof a)
#define F first
#define S second

#define maxn 8000
#define maxm 30000
#define add(a,b,c) to[z] = b, cost[z] = c, ant[z] = adj[a], adj[a] = z++
int to[maxm], cost[maxm], ant[maxm], adj[maxn], z;

int N, M, K;
int rep[maxn], ap[maxn], C[maxn];
int findset(int x) {
	if (x == rep[x]) return x;
	return rep[x] = findset(rep[x]);
}

priority_queue<pii, vector<pii>, greater<pii> > pq;
int dij(int a, int b) {
	while (!pq.empty()) pq.pop();
	cl(C,0x3f);
	pq.push(MP(1-ap[a],a));
	pii aux;
	while (!pq.empty()) {
		aux = pq.top(); pq.pop();
		int c = aux.F, u = aux.S;
		if (u == b) return c;
		
		for (int v = adj[u]; ~v; v = ant[v]) {
			if (c + cost[v] < C[to[v]]) {
				C[to[v]] = c + cost[v];
				pq.push(MP(c + cost[v], to[v]));
			}
		}
	}
	return -1;
}

int main() {
	int T, a, b;
	int cas = 1;
	scanf("%d", &T);
	while (T--) {
		scanf("%d%d%d", &N, &M, &K);
		rp(i,N) rep[i] = i;
		cl(ap,0);
		cl(adj,-1); z = 0;
		rp(i,K) scanf("%d", &a), ap[a-1] = 1;
		rp(i,M) {
			scanf("%d%d", &a, &b), a--, b--;
			add(a,b,1-ap[b]);
			add(b,a,1-ap[a]);
			rep[findset(a)] = findset(b);
		}
		int Q;
		scanf("%d", &Q);
		printf("Case %d:\n", cas++);
		while (Q--) {
			scanf("%d%d", &a, &b); a--, b--;
			if (a == b) puts("0");
			else if (findset(a) != findset(b)) puts("-1");
			else {
				printf("%d\n", dij(a,b));
			}
		}
		puts("");
	}
}