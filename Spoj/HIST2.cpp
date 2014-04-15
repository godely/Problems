#include <cstdio>
#include <cstdlib>
#include <iostream>
#include <algorithm>
#include <cmath>
#include <cstring>
#include <queue>
#include <bitset>
#include <vector>
#include <utility>
using namespace std;
#define fr(a,b,c) for(int a = b; a < c; a++)
#define rp(a,b) fr(a,0,b)
#define cl(a,b) memset(a,b,sizeof a)
#define F first
#define S second
typedef pair<int,int> pii;

pii dp[1<<16][16];
int mark[1<<16][16], passo = 0;
int x[16];
int n, CPLT;

pii go(int msk, int l) {
	pii &pd = dp[msk][l];
	if (mark[msk][l] == passo) return pd;
	mark[msk][l] = passo;
	if (msk == CPLT) return pd = pii(x[l],1);

	pii ans = pii(0,0), ret;
	rp(i,n) if (!((msk>>i)&1)) {
		ret = go(msk|(1<<i),i);
		ret.F += 2 + abs(x[l]-x[i]);
		if (ret.F > ans.F) ans = ret;
		else if (ret.F == ans.F) ans.S += ret.S;
	}
	return pd = ans;
}

int main() {
	cl(mark,0); passo = 0;
	while (scanf("%d", &n) == 1 && n > 0) {
		rp(i,n) scanf("%d", &x[i]);
		x[n] = 0;
		CPLT = (1<<n)-1;
		passo++;
		pii ans = go(0,n);
		printf("%d %d\n", ans.F, ans.S);
	}
	return 0;
}