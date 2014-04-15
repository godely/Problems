#include <bits/stdc++.h>
using namespace std;
#define fr(a,b,c) for (int a = b; a < c; a++)
#define rp(a,b) fr(a,0,b)
#define pb push_back
#define MAXN 100100
#define add(a,b) ant[z] = adj[a], to[z] = b, adj[a] = z++, size[a]++

//clear: z = 0, memset(adj, -1, sizeof adj);
int ant[MAXN], to[MAXN], adj[MAXN], size[MAXN], z;
int mark[MAXN], passo = 0;

int dp[MAXN], temp[MAXN];
int N, T;

void solve(int u) {
	if (mark[u] != passo) {
		dp[u] = 1;
		return;
	}
	for (int v = adj[u]; v != -1; v = ant[v]) solve(to[v]);
	for (int i = 0, v = adj[u]; v != -1; i++, v = ant[v]) temp[i] = dp[to[v]];
	sort(temp,temp+size[u]);
	int qnt = (T*size[u] + 99)/100;
	dp[u] = 0;
	rp(v,qnt) dp[u] += temp[v];
}

int main() {
	int a;
	while (scanf("%d%d", &N, &T) == 2 && N > 0) {
		passo++; z = 0;
		rp(i,N) {
			scanf("%d", &a);
			if (mark[a] != passo) mark[a] = passo, adj[a] = -1, size[a] = 0;
			add(a,i+1);
		}
		solve(0);
		printf("%d%c", dp[0], 10);
	}
	return 0;
}