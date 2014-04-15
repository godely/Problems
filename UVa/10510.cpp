#include <bits/stdc++.h>
using namespace std;
#define pb push_back
#define fr(a,b,c) for (int a = b; a < c; a++)
#define rp(a,b) fr(a,0,b)

vector<int> adj[10001];
int num[10001], low[10001], onPile[10001], mark[10001], counter, sccCount;
stack<int> st, st2;

void scc(int a) {
	num[a] = low[a] = counter++;
	st.push(a);
	onPile[a] = 1;
	rp(i,adj[a].size()) {
		if (mark[adj[a][i]]) {
			sccCount = 2;
			return;
		}
		if (num[adj[a][i]]==-1) {
			st2.push(a);
			mark[a] = 0;
			scc(adj[a][i]);
		} else {
			int w;
			do {
				w = st2.top(), st2.pop();
				mark[w] = 1;
			} while (w != adj[a][i]);
			mark[a] = 1;
		}
		if (onPile[adj[a][i]]) low[a] = min(low[a], low[adj[a][i]]);
	}

	if (num[a]==low[a]) {
		int w;
		do {
			w = st.top(), st.pop();
			onPile[w] = 0;
		} while (w != a);
		sccCount++;
	}
}

int main() {
	int T, n, m, a, b;
	scanf("%d", &T);
	while (T--) {
		scanf("%d%d", &n, &m);
		
		//limpar o grafo
		rp(i,n) {
			adj[i].clear();
			num[i]=-1;
			onPile[i]=0;
			mark[i]=0;
		}
		counter = sccCount = 0;
		
		rp(i,m) {
			scanf("%d%d", &a, &b);
			adj[a].pb(b);
		}
		scc(0);
		bool ok = (sccCount==1);
		if (ok) fr(i,1,n) if (num[i]==-1) { ok = 0; break; }
		
		
		if (ok) printf("YES\n");
		else printf("NO\n");
	}
}