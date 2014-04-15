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

#define maxn 110
#define maxm 20100
#define add(a,b) to[z] = b, ant[z] = adj[a], adj[a] = z++
int to[maxm], ant[maxm], adj[maxn], z;

bool vis[maxn];
int go(int x) {
	int res = 1;
	vis[x] = 1;
	for (int i = adj[x]; ~i; i = ant[i]) {
		if (!vis[to[i]]) {
			res += go(to[i]);
		}
	}
	return res;
}

int main() {
	int cas = 1;
	int n, m;
	int a, b;
	while (scanf("%d%d", &n, &m) == 2 && n > 0) {
		cl(adj,-1); z = 0;
		rp(i,m) {
			scanf("%d%d", &a, &b);
			add(a-1,b-1);
			add(b-1,a-1);
		}
		cl(vis,0);
		int r = go(0);
		printf("Teste %d\n", cas++);
		if (r == n) printf("normal\n");
		else printf("falha\n");
		puts("");
	}
	return 0;
}