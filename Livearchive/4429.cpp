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
#define inf 0x3f3f3f3f

#define maxn 1111

int n, t;
int a, b, c;
pair<int,pair<int,int> > v[maxn];
int next[maxn];

int dp[maxn][maxn], mark[maxn][maxn], passo;

int go(int i, int k) {
	int &pd = dp[i][k];
	if (mark[i][k] == passo) return pd;
	mark[i][k] = passo;
	if (k == 0) return pd = 0;
	if (i >= n) return pd = inf;
	
	int ans = inf;
	int inc = 0, dec = 0;
	if (i == 0 || v[i-1].F != v[i].F) {	
		inc = v[i].S.S;
		ans = go(next[i], k);
	}
	if (k == 1) {
		ans = min(ans, inc + (v[i].S.S - v[i].S.F) + go(i+1,0));
	}
	if (next[i] > i+1) ans = min(ans, inc + min((v[i].S.S - v[i].S.F) + (v[i+1].S.S - v[i].S.S) + go(i+1, k-1), (v[i+1].S.S - v[i].S.S) + go(i+1, k)));
	//printf("%d %d, %d %d\n",i,k,inc,ans);
	ans = min(ans, inc + (v[i].S.S - v[i].S.F) + v[i].S.S + go(next[i], k-1));
	return pd = ans;
}

int main() {
	passo = 0;
	while (scanf("%d%d", &n, &t) == 2 && (n+t > 0)) {
		rp(i,n) scanf("%d%d%d", &a, &b, &c), v[i] = MP(a,MP(b,c));
		sort(v,v+n);
		v[n] = MP(-1,MP(-1,-1));
		rp(i,n) {
			int j = i+1;
			for (; j < n && v[i].F == v[j].F; j++);
			for (int k = i; k < j; k++) next[k] = j;
			i = j-1;
		}
		
		//rp(i,n) printf("%d %d %d, %d\n", v[i].F, v[i].S.F, v[i].S.S, next[i]);
		
		passo++;
		int ini = 0, fim = n, m;
		while (ini < fim) {
			m = (ini+fim+1)>>1;
			//printf("%d %d, %d = %d\n", ini, fim, m, go(0,m));
			if (go(0,m) <= t) ini = m;
			else fim = m-1;
		}
		printf("%d\n", ini);
	}
	return 0;
}