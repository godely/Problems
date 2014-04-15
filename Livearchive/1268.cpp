#include <bits/stdc++.h>
using namespace std;
#define fr(a,b,c) for(int a = b; a < c; a++)
#define rp(a,b) fr(a,0,b)
#define MAXN 141000

int N;
int x[20], sum[1<<15];
bool prime[1<<15];

bool C[MAXN];
void crivo() {
	memset(C,0,sizeof C);
	C[1] = 1;
	for (int i = 4; i < MAXN; i+=2) C[i] = 1;
	for (int i = 3; i <= 375; i+=2) {
		if (!C[i]) for (int j = i*i; j < MAXN; j+=i) C[j] = 1;
	}
}

int dp[16][1<<15], mark[16][1<<15], passo;
int solve(int k, int mask) {
	if (mark[k][mask] == passo) return dp[k][mask];
	mark[k][mask] = passo;
	if (!k) return dp[k][mask] = (mask==0) ? 0 : -1;
	if (!mask) return dp[k][mask] = -1;
	
	int ret = -1;
	for (int i = mask; i; i=(i-1)&mask) {
		if (prime[i]) {
			int temp = solve(k-1,mask-i);
			if (~temp) ret = max(ret,max(sum[i],temp));
		}
	}
	return dp[k][mask] = ret;
}

int main() {
	crivo();
	int cas = 1;
	memset(mark,0,sizeof mark); passo = 0;
	while (scanf("%d", &N) == 1 && ~N) {
		memset(sum,0,sizeof sum);
		rp(i,N) scanf("%d", &x[i]), sum[1<<i] = x[i];
		int LIM = (1<<N);
		fr(i,1,LIM) {
			sum[i] = sum[i - (i&-i)] + sum[i-((i-1)&i)];
			prime[i] = !C[sum[i]];
		}
		int res = -1;
		passo++;
		rp(i,N) if (x[i] < N) {
			res = max(res,solve(x[i],(LIM-1)&(~(1<<i))));
		}
		if (~res) printf("Case %d: %d\n", cas++, res);
		else printf("Case %d: not a valid clue\n", cas++);
	}
	return 0;
}