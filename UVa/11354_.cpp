#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <cmath>
#include <iostream>
#include <algorithm>
using namespace std;
#define fr(a,b,c) for (int a = b; a < c; a++)
#define rp(a,b) fr(a,0,b)
#define cl(a,b) memset(a,b,sizeof a)
#define sf(a) scanf("%d", &a)
#define sf2(a,b) scanf("%d%d", &a, &b)
#define sf3(a,b,c) scanf("%d%d%d", &a, &b, &c)
#define sf4(a,b,c,d) scanf("%d%d%d%d", &a, &b, &c, &d)
typedef pair<int,int> pii;
#define MP make_pair
#define F first
#define S second
#define oo 0x3f3f3f3f

#define MAXN 51000
#define MAXM 210000

int N, M, Q;
int rep[MAXN];
pair<int,pii> are[MAXM];

int dept;
int findset(int x) { return (x == rep[x]) ? x : rep[x] = findset(rep[x]); }
bool unionset(int x, int y) { return (findset(x) != findset(y)) ? rep[findset(x)] = findset(y), true : false; }

#define add(a,b,c) to[z] = b, cost[z] = c, ant[z] = adj[a], adj[a] = z++
int to[MAXM], cost[MAXM], ant[MAXM], adj[MAXN], z;

int pai[MAXN][20];
int dp[MAXN][20];
int level[MAXN];

void dfs(int x) {
	for (int y = adj[x]; ~y; y = ant[y]) {
		if (to[y] != pai[x][0]) {
			dp[to[y]][0] = cost[y];
			pai[to[y]][0] = x;
			level[to[y]] = level[x] + 1;
			dfs(to[y]);
		}
	}
}

void prelca(int root) {
	cl(pai,-1);
	cl(dp,0);
	level[0] = 0;
	dfs(root);
	bool keep = 1;
	for (dept = 1; keep; dept++) {
		keep = 0;
		for (int j = 0; j < N; j++) {
			dp[j][dept] = dp[j][dept-1];
			if (~pai[j][dept-1]) {
				pai[j][dept] = pai[pai[j][dept-1]][dept-1];
				dp[j][dept] = max(dp[j][dept-1], dp[pai[j][dept-1]][dept-1]);
				if (~pai[j][dept]) keep = 1;
			}
		}
	}
}

int query(int a, int b) {
	if (level[a] < level[b]) swap(a,b);
	int res = 0;
	for (int i = dept; i >= 0; i--) {
		if ((~pai[a][i]) && level[ pai[a][i] ] >= level[b]) {
			res = max(res,dp[a][i]);
			a = pai[a][i];
		}
	}
	if (a == b) return res;
	for (int i = dept; i >= 0; i--) {
		if (pai[a][i] != pai[b][i]) {
			res = max(res,max(dp[a][i],dp[b][i]));
			a = pai[a][i];
			b = pai[b][i];
		}
	}
	return max(res,max(dp[a][0],dp[b][0]));
}

int main() {
	bool ok = 0;
	while (sf2(N,M) == 2) {
		if (ok) puts("");
		else ok = 1;
		cl(adj,-1); z = 0;
		rp(i,N) rep[i] = i;
		int x, y, d;
		rp(i,M) {
			sf3(x,y,d); x--, y--;
			are[i] = MP(d,MP(x,y));
		}
		sort(are,are+M);
		rp(i,M) {
			if (unionset(are[i].S.F,are[i].S.S)) {
				add(are[i].S.F, are[i].S.S, are[i].F);
				add(are[i].S.S, are[i].S.F, are[i].F);
			}
		}
		prelca(0);
		sf(Q);
		while (Q--) {
			sf2(x,y);
			printf("%d\n", query(x-1,y-1));
		}
	}
	return 0;
}