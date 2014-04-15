#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <cmath>
#include <iostream>
#include <algorithm>
using namespace std;
#define fr(a,b,c) for (int a = b; a < c; a++)
#define rp(a,b) fr(a,0,b)
#define cl(a,b) memset(a,b,sizeof a)
#define sf(a) scanf("%d", &a)
#define sf2(a,b) scanf("%d%d", &a, &b)
#define sf3(a,b,c) scanf("%d%d%d", &a, &b, &c)
#define sf4(a,b,c,d) scanf("%d%d%d%d", &a, &b, &c, &d)
typedef pair<int,int> pii;
typedef long long ll;
#define MP make_pair
#define F first
#define S second
#define oo 0x3f3f3f3f

int n, a[50];
int dp[1<<16][4][22], mark[1<<16][4][22], passo;

int go(int mask, int q, int sum) {
	int &pd = dp[mask][q][sum];
	if (mark[mask][q][sum] == passo) return pd;
	mark[mask][q][sum] = passo;
	
	if (q == 3) return pd = (sum >= 20) + go(mask,0,0);
	else {
		int res = 0;
		rp(i,n) if (((mask>>i)&1)==0) res = max(res,go(mask|(1<<i),q+1,min(20,sum+a[i])));
		return pd = res;
	}
}

int main() {
	int cas = 1;
	cl(mark,0); passo = 0;
	while (scanf("%d", &n) == 1 && n > 0) {
		rp(i,n) sf(a[i]);
		passo++;
		printf("Case %d: %d\n", cas++, go(0,0,0));
	}
	return 0;
}