//by stor
#include <bits/stdc++.h>
#include <algorithm>
#define fr(a,b,c) for(int a = b; a < c; a++)
#define rp(a,b) fr(a,0,b)
#define ll long long
#define MAXN 100010
#define pb push_back
#define mp make_pair
#define pii pair<int, int>
#define f first
#define s second

using namespace std;

vector<pii> adj[MAXN];
int qnt[MAXN], mark[MAXN], passo = 0;
ll res;
int N;

int dfs(int no) {
	mark[no] = passo;
	int ret, ans = 0;
	rp(i,adj[no].size()) {
		if (mark[adj[no][i].f] != passo) {
			ret = dfs(adj[no][i].f);
			ans += ret;
			res += min(ret, N-ret)*adj[no][i].s;
		}
	}
	qnt[no] = ans;
	return ans+1;
}

int dfs2(int no) {

}

int main() {
	cin.sync_with_stdio(false);
	int T, cas = 1, a, b, c;
	cin >> T;
	while (T--) {
		passo++;
		cin >> N;
		fr(i,1,N+1) adj[i].clear(), qnt[i]=0;
		rp(i,N-1) {
			cin >> a >> b >> c;
			adj[a].pb(mp(b,2*c));
			adj[b].pb(mp(a,2*c));
		}
		res = 0; passo++; dfs(1);
		cout << "Case #" << cas++ << ": " << res << endl;
	}
	return 0;
}