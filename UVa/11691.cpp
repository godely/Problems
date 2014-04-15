#include <bits/stdc++.h>
using namespace std;
#define fr(a,b,c) for(int a = b; a < c; a++)
#define rp(a,b) fr(a,0,b)

int dp[8][1<<21];
int mark[8][1<<21], passo;
int N, x[35], FIM;
int go(int lst, int msk) {
	if (mark[lst][msk] == passo) return dp[lst][msk];
	mark[lst][msk] = passo;
	if (msk == FIM) return dp[lst][msk] = 0;
	
	int ret = 1000000000;
	bool tmp[8];
	memset(tmp,0,sizeof tmp);
	rp(i,N) {
		if (tmp[x[i]]) continue;
		if (!((msk>>i)&1)) {
			tmp[x[i]] = 1;
			if (lst >= x[i]) ret = min(ret, 1+go(0, msk|(1<<i)));
			else ret = min(ret, x[i]-lst+(lst>0)+go(x[i]-lst+(lst>0), msk|(1<<i)));
		}
	}
	
	//printf("%d %d > %d\n", lst, msk, ret);
	return dp[lst][msk] = ret;
}

int main() {
	passo = 0;
	memset(mark,0,sizeof mark);
	int T;
	scanf("%d", &T);
	while (T--) {
		scanf("%d", &N);
		FIM = (1<<N)-1;
		rp(i,N) scanf("%d", &x[i]);
		passo++;
		printf("%d\n", go(0,0));
	}
	return 0;
}