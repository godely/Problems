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
#define F first
#define S second
#define maxn 1011

int go(int i, int s, int n) {
	int &pd = dp[i][s][n];
	if (mark[i][s][n] == passo) return pd;
	mark[i][s][n] = passo;


	if (i  >= N || n == 0) return pd = 0;

	int ans = 0;
	for (int k = 1; k <= qnt[i] && k <= n && s - k*x[i] >= 0; k++) {
		if ()
		ans = (ans + C[n][k] * go(next[i], s - x[i], n - 1))%MOD;
	}
	return pd = ans;
}

int main() {
	while (t--) {
		scanf("%d", &n);
		scanf("%d%d", &n, &w);
		rp(i,n) scanf("%d", &x[i]);
		sort(x,x+n,greater<int>);
		sa[0] = 0;
		x[n] = 0;
		rp(i,n) {
			qnt[i] = upper_bound(x,x+n,x[i]) - x;
			sa[i+1] = sa[i] + x[i];
		}
		passo++;
		fr(i,1,n+1) {
			ans = (ans + go(0, w, i))%MOD;
		}
		printf("%d\n")
	}
}