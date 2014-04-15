#include <bits/stdc++.h>
#define fr(a,b,c) for(int a=b;a<c;a++)
#define rp(a,b) fr(a,0,b)
#define LL long long
#define MAXN 111
#define pb push_back
using namespace std;

vector<int> adj[111];
bool mark[111], res[111][111];

void dfs(int a) {
	mark[a]=1;
	rp(i,adj[a].size()) {
		if (!mark[adj[a][i]]) dfs(adj[a][i]);
	}
}

int main() {
	int T, N, a;
	scanf("%d", &T);
	fr(cas,1,T+1) {
		scanf("%d", &N);
		rp(i,N) adj[i].clear(), mark[i]=0;
		rp(i,N) rp(j,N) {
			scanf("%d", &a);
			if (a) adj[i].pb(j);
		}
		memset(mark,0,sizeof mark);
		dfs(0);
		rp(i,N) res[0][i]=mark[i];
		fr(i,1,N) {
			memset(mark,0,sizeof mark);
			mark[i]=1;
			dfs(0);
			mark[i]=0;
			rp(j,N) {
				if (mark[j]!=res[0][j]) res[i][j]=1;
				else res[i][j]=0;
			}
		}
		printf("Case %d:\n", cas);
		rp(i,N) {
			printf("+-");
			rp(j,N-1) printf("--");
			printf("+\n");
			rp(j,N) printf("|%c", res[i][j]?'Y':'N');
			printf("|\n");
		}
		printf("+-");
		rp(j,N-1) printf("--");
		printf("+\n");
	}
	return 0;
}