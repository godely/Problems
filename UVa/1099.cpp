#include <bits/stdc++.h>
using namespace std;
#define fr(a,b,c) for(int a = b; a < c; a++)
#define rp(a,b) fr(a,0,b)

int N, x, y, v[20];
int LIM;
int sum[1<<15];
int dp[105][1<<15], calc[105][1<<15], passo = 0;

bool solve(int w, int mask) {
	int h = sum[mask]/w;
	if (calc[w][mask] == passo) return dp[w][mask];
	else if (calc[h][mask] == passo) return dp[h][mask];
	calc[w][mask] = calc[h][mask] = passo;
	if ((mask&(-mask)) == mask) return dp[w][mask] = dp[h][mask] = 1;
	
	bool ok = 0;
	for (int i = (mask-1)&mask; !ok && i; i=(i-1)&mask) {
		if (sum[i]%w == 0) ok |= (solve(w,i)&solve(w,mask-i));
		if (sum[i]%h == 0) ok |= (solve(h,i)&solve(h,mask-i));
	}
	return dp[w][mask] = dp[h][mask] = ok;
}

int main() {
	int cas = 1;
	while (scanf("%d", &N) == 1 && N > 0) {
		scanf("%d%d", &x, &y);
		rp(i,N) scanf("%d", &v[i]);
		LIM = (1<<N);
		memset(sum,0,sizeof sum);
		rp(i,LIM) rp(j,N) if (i&(1<<j)) sum[i]+=v[j];
		
		if (sum[LIM-1] != x*y) { printf("Case %d: No\n", cas++); continue; }
		passo++;

		if (solve(x,LIM-1)) printf("Case %d: Yes\n", cas++);
		else printf("Case %d: No\n", cas++);
	}
	return 0;
}