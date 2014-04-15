#include <cstdio>
#include <cstdlib>
#include <algorithm>
#include <vector>
#include <cmath>
#include <map>
#include <set>
#include <iostream>
#include <cstring>
using namespace std;
#define MP make_pair
typedef pair<int,int> pii;
typedef long long ll;
#define fr(a,b,c) for(int a = b; a < c; a++)
#define rp(a,b) fr(a,0,b)
#define cl(a,b) memset(a,b,sizeof a)
#define F first
#define S second
#define MOD 1000000007

bool isPal[2][1<<12];
int N, K;
int COMP, COMP2;
ll dp[500][1<<12];
int mark[500][1<<12], passo;

ll go(int i, int msk) {
	ll &pd = dp[i][msk];
	if (mark[i][msk] == passo) return pd;
	mark[i][msk] = passo;
	if (i >= N) return pd = 1;

	ll res = 0;
	if (!isPal[0][(msk<<1)&COMP] && !isPal[1][msk<<1]) res = (res+go(i+1, (msk<<1)&COMP))%MOD;
	if (!isPal[0][((msk<<1)|1)&COMP] && !isPal[1][(msk<<1)|1]) res = (res+go(i+1, ((msk<<1)|1)&COMP))%MOD;
	return pd = res;
}

int main() {
	passo = 0;
	int T;
	scanf("%d", &T);
	while (T--) {
		scanf("%d%d", &N, &K);
		if (N < K) printf("%d\n", 1<<N);
		else {
			COMP = (1<<K)-1;
			cl(isPal,0);
			rp(i,COMP+1) {
				isPal[0][i] = 1;
				rp(j,K>>1) if (((i>>j)&1) != ((i>>(K-1-j))&1)) {
					isPal[0][i] = 0;
					break;
				}
			}
			COMP2 = (COMP<<1) + 1;
			rp(i,COMP2+1) {
				isPal[1][i] = 1;
				rp(j,(K+1)>>1) if (((i>>j)&1) != ((i>>(K-j))&1)) {
					isPal[1][i] = 0;
					break;
				}
			}
			passo++;
			ll res = 0;
			rp(i,COMP+1) if (!isPal[0][i]) res = (res + go(K,i))%MOD;
			printf("%lld\n", res);
		}
	}
}