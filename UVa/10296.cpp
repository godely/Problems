#include <bits/stdc++.h>
#define fr(a,b,c) for(int a = b; a < c; a++)
#define rp(a,b) fr(a,0,b)
#define CL(a,b) memset(a,b,sizeof (a))
#define oo 0x3f3f3f3f
using namespace std;
typedef long long ll;

#define maxn 20

int cap[maxn][maxn];
int grau[maxn];
int n, m;
int dp[1<<16];
void fw() { rp(k,n) rp(i,n) rp(j,n) cap[i][j] = min(cap[i][j],cap[i][k]+cap[k][j]); }

int LIM = (1<<16)-1;
int go(int msk) {
	int &pd = dp[msk];
	if (~pd) return pd;
	if (msk == LIM) return pd = 0;
	
	pd = oo;
	rp(i,n) if (!((msk>>i)&1)) {
		fr(j,i+1,n) if (!((msk>>j)&1)) {
			pd = min(pd,cap[i][j]+go(msk|(1<<i)|(1<<j)));
		}
		break;
	}
	return pd;
}

int main() {
	int a, b, c;
	while (scanf("%d", &n) == 1 && n > 0) {
		scanf("%d", &m);
		CL(grau,0);
		CL(cap,0x3f);
		int ans = 0;
		rp(i,m) scanf("%d%d%d", &a, &b, &c), a--, b--, ans+=c, cap[a][b] = cap[b][a] = min(cap[a][b],c), grau[a]++, grau[b]++;
		fw();
		int msk = LIM;
		rp(i,n) if (grau[i]&1) msk&=(~(1<<i));
		memset(dp,-1,sizeof dp);
		printf("%d\n", ans+go(msk));
	}
}