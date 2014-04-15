#include <cstdio>
#include <cstdlib>
#include <algorithm>
#include <vector>
#include <cmath>
#include <map>
#include <set>
#include <iostream>
#include <cstring>
#include <queue>
using namespace std;
#define MP make_pair
typedef pair<int,int> pii;
typedef long long ll;
#define fr(a,b,c) for(int a = b; a < c; a++)
#define rp(a,b) fr(a,0,b)
#define cl(a,b) memset(a,b,sizeof a)
#define cl(a,b) memset(a,b,sizeof a)
#define F first
#define S second

#define maxn 211000
int T, N;
ll x[maxn];

int adj[40*maxn][2], sz;

void insert(ll n) {
	int cur = 0;
	for (ll i = 31; i >= 0 && cur != -1; i--) {
		ll p = (n>>i)&1LL;
		if (adj[cur][p] == -1) adj[cur][p] = sz++;
		cur = adj[cur][p];
	}
}

ll bigval(ll n) {
	int cur = 0;
	ll res = 0;
	for (ll i = 31; i >= 0 && cur != -1; i--) {
		ll p = (n>>i)&1LL;
		if (adj[cur][!p] != -1) cur = adj[cur][!p], res += (1LL<<i);
		else cur = adj[cur][p];
	}
	return res;
}

int main() {
	scanf("%d", &T);
	while (T--) {
		scanf("%d", &N);
		cl(adj,-1);
		sz = 1;
		ll ans = 0;
		x[0] = 0;
		insert(0);
		fr(i,1,N+1) {
			scanf("%lld", &x[i]);
			ans = max(ans,x[i]);
			x[i] ^= x[i-1];
			insert(x[i]);
		}
		fr(i,1,N+1) ans = max(ans,bigval(x[i]));
		printf("%lld\n", ans);
	}
	return 0;
}