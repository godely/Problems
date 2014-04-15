#include <cstdio>
#include <cstdlib>
#include <cmath>
#include <vector>
#include <cstring>
#include <map>
#include <iostream>
#include <algorithm>
#define fr(a,b,c) for(int a = b; a < c; a++)
#define rp(a,b) fr(a,0,b)
#define clvec(vec,n) for(int i = 0; i <= n; i++) vec[i].clear()
#define pb push_back

using namespace std;

vector<int> adj[300];
int mark[300], bico;

void dfs(int a, int color) {
	mark[a]=color;
	rp(i,adj[a].size()) {
		if (!mark[adj[a][i]]) dfs(adj[a][i], color^1);
		else if (mark[adj[a][i]]==color) {
			bico = 0;
			return;
		}
	}
}

int main() {
	int n,m,a,b;
	while (scanf("%d", &n) == 1 && n > 0) {
		scanf("%d", &m);
		clvec(adj,n);
		while (m--) scanf("%d%d", &a, &b), adj[a].pb(b), adj[b].pb(a);
		memset(mark,0,sizeof mark); bico=1;
		dfs(0,2);
		if (bico) printf("BICOLORABLE.\n");
		else printf("NOT BICOLORABLE.\n");
	}
	return 0;
}