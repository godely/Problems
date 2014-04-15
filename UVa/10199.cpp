#include <cstdio>
#include <cstring>
#include <algorithm>
#include <iostream>
#include <cmath>
#include <vector>
#include <map>
using namespace std;
#define MAXN 11000
#define fr(a,b,c) for(int a=b;a<c;a++)
#define rp(a,b) fr(a,0,b)
#define pb push_back
#define mp make_pair

vector<int> adj[MAXN];
int low[MAXN], num[MAXN], counter, root, rootChildren;
bool mark[MAXN];
vector<string> nome;
vector<string> res;

void findArtAndBridge(int a, int from) {
	low[a]=num[a]=counter++;
	mark[a]=1;
	bool foi=0;
	rp(i,adj[a].size()) {
		if (!mark[adj[a][i]]) {
			if (a==root) rootChildren++;
			findArtAndBridge(adj[a][i],a);
			if (low[adj[a][i]] >= num[a] && !foi && (a!=root || rootChildren > 1)) res.pb(nome[a]), foi=1;
			low[a] = min(low[a],low[adj[a][i]]);
		} else if (adj[a][i] != from) {
			low[a] = min(low[a],num[adj[a][i]]);
		}
	}
}

char str[11111], str2[11111];
map<string, int> mapa;
int main() {
	int N, M, a, b, k, cas=1;
	bool ok=0;
	while (scanf("%d", &N) == 1 && N > 0) {
		if (ok) printf("\n");
		else ok=1;
		nome.clear();
		nome.pb("");
		rp(i,N+1) adj[i].clear();
		mapa.clear();
		k = 1;
		rp(i,N) {
			scanf("%s", str);
			mapa[str]=k++;
			nome.pb(str);
		}
		scanf("%d", &M);
		rp(i,M) {
			scanf("%s %s", str, str2);
			adj[mapa[str]].pb(mapa[str2]);
			adj[mapa[str2]].pb(mapa[str]);
		}
		counter = 0;
		memset(mark,0,sizeof mark);
		res.clear();
		fr(i,1,N+1) if (!mark[i]) {
			rootChildren=0, root=i;
			findArtAndBridge(i,-1);
		}
		sort(res.begin(),res.end());
		printf("City map #%d: %d camera(s) found\n", cas++, res.size());
		rp(i,res.size()) printf("%s\n", res[i].c_str());
	}
	return 0;
}