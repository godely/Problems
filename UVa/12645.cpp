#include <cstdio>
#include <cstdlib>
#include <cmath>
#include <vector>
#include <cstring>
#include <map>
#include <iostream>
#define fr(a,b,c) for(int a = b; a < c; a++)
#define rp(a,b) fr(a,0,b)
#define MAXN 3011
#define MAXM 501111

using namespace std;

//graph structure
#define add(a,b) from[z] = a, to[z] = b, ant[z] = adj[a], adj[a] = z++
int from[MAXM], to[MAXM], ant[MAXM], adj[MAXN], z;

//scc
int vis[MAXN], mark[MAXN];
int low[MAXN], num[MAXN], counter;
int stack[MAXN], size;
int group[MAXN], gs;

void scc(int x) {
	mark[x]=1;
	vis[x]=1;
	num[x]=low[x]=counter++;
	stack[size++] = x;
	for (int i = adj[x]; ~i; i = ant[i]) {
		if (num[to[i]]==-1) scc(to[i]);
		if (vis[to[i]]) low[x] = min(low[x],low[to[i]]);
	}
	if (low[x]==num[x]) {
		while(1) {
			int v = stack[--size];
			vis[v]=0;
			group[v]=gs;
			if (x==v) break;
		}
		gs++;
	}
}

int main() {
	int n, m;
	int a, b;
	while (scanf("%d%d", &n, &m) == 2) {
		memset(mark,0,sizeof mark);
		memset(vis,0,sizeof vis);
		memset(num,-1,sizeof num);
		memset(adj,-1,sizeof adj);
		size = z = counter = gs = 0;
		rp(i,m) {
			scanf("%d%d", &a, &b);
			add(a,b);
		}
		rp(i,n+1) if (!mark[i]) scc(i);
		memset(mark,0,sizeof mark);
		rp(i,z) if (group[from[i]] != group[to[i]]) mark[group[to[i]]] = 1; 
		int ans = 0;
		rp(i,gs) if (i != group[0] && !mark[i]) ans++;
		//rp(i,n+1) printf("%d: %d %d\n", i, group[i], mark[group[i]]);
		printf("%d\n", ans);
	}
	return 0;
}