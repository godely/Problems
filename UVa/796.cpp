#include <cstdio>
#include <cstring>
#include <algorithm>
#include <iostream>
#include <cmath>
#include <vector>
using namespace std;
#define MAXN 11000
#define fr(a,b,c) for(int a=b;a<c;a++)
#define rp(a,b) fr(a,0,b)
#define pb push_back
#define mp make_pair

vector<int> adj[MAXN];
int low[MAXN], num[MAXN], counter;
bool mark[MAXN];
vector<pair<int,int> > res;

void findBridge(int a, int from) {
	low[a]=num[a]=counter++;
	mark[a]=1;
	rp(i,adj[a].size()) {
		if (!mark[adj[a][i]]) {
			findBridge(adj[a][i],a);
			if (low[adj[a][i]] > num[a]) res.pb(mp(min(a,adj[a][i]),max(a,adj[a][i])));
			low[a] = min(low[a],low[adj[a][i]]);
		} else if (adj[a][i] != from) {
			low[a] = min(low[a],num[adj[a][i]]);
		}
	}
}

int main() {
	int N, a, b, n;
	while (scanf("%d", &N) == 1) {
		rp(i,N) adj[i].clear(), mark[i]=0;
		counter = 0;
		rp(i,N) {
			scanf("%d (%d)", &a, &n);
			rp(j,n) scanf("%d", &b), adj[a].pb(b);
		}
		res.clear();
		rp(i,N) if (!mark[i]) findBridge(i,-1);
		sort(res.begin(),res.end());
		printf("%d critical links\n", res.size());
		rp(i,res.size()) printf("%d - %d\n", res[i].first, res[i].second);
		printf("\n");
	}
	return 0;
}