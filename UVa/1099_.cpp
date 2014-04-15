#include <bits/stdc++.h>
using namespace std;
#define fr(a,b,c) for(int a = b; a < c; a++)
#define rp(a,b) fr(a,0,b)
#define CL(a,b) memset(a,b,sizeof a)

int n, x, y;
int sum[1<<16];
int dp[1<<16][101], mark[1<<16][101], passo;
int go(int msk, int h) {
	int w = sum[msk]/h;
	int &pd = dp[msk][h];
	if (mark[msk][h] == passo) return pd;
	if ((msk&(-msk)) == msk) return pd = 1;
	mark[msk][h] = passo;
	
	for (int i = msk&(msk-1); i; i = msk&(i-1)) {
		int tmp = sum[i];
		if (tmp%h == 0) if (go(i,min(h,tmp/h)) && go(msk-i,min(h,sum[msk-i]/h))) return pd = 1;
		if (tmp%w == 0) if (go(i,min(w,tmp/w)) && go(msk-i,min(w,sum[msk-i]/w))) return pd = 1;
	}
	return pd = 0;
}

int main() {
	int cas = 1;
	passo = 0;
	CL(mark,0);
	while (scanf("%d", &n) == 1 && n > 0) {
		scanf("%d%d", &x, &y);
		rp(i,n) scanf("%d", &sum[1<<i]);
		int lim = 1<<n;
		sum[0] = 0;
		fr(i,1,lim) if ((i&(-i)) != i) sum[i] = sum[i&(i-1)] + sum[i-(i&(i-1))];
		passo++;
		if (sum[lim-1] != x*y) printf("Case %d: No\n", cas++);
		else {
			if (go(lim-1,min(x,y))) printf("Case %d: Yes\n", cas++);
			else printf("Case %d: No\n", cas++);
		}
	}
	return 0;
}