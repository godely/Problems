#include <bits/stdc++.h>
#define fr(a,b,c) for(int a = b; a < c; a++)
#define rp(a,b) fr(a,0,b)
#define CL(a,b) memset(a,b,sizeof (a))
#define oo 0x3f3f3f3f
using namespace std;
typedef long long ll;
#define maxn 255

int dp[maxn][maxn], mid[maxn][maxn], mark[maxn][maxn], passo;
int sum[maxn];
int n;

int go(int i, int j) {
	int &pd = dp[i][j];
	int &m = mid[i][j];
	if (mark[i][j] == passo) return pd;	
	mark[i][j] = passo;
	pd = oo; m = i;
	if (i >= j) return pd = 0;
	go(i,j-1);
	go(i+1,j);
	int ini = mid[i][j-1], fim = mid[i+1][j]+1, aux;
	fr(k,ini,fim) {
		aux = sum[j+1] - sum[k+1] + sum[k] - sum[i] + go(i,k-1) + go(k+1,j);
		if (aux < pd) {
			pd = aux;
			m = k;
		}
	}
	return pd;
}

int main() {
	CL(mark,0); passo = 0;
	int f;
	while (scanf("%d", &n) == 1) {
		sum[0] = 0;
		rp(i,n) scanf("%d", &f), sum[i+1] = sum[i]+f;
		passo++;
		printf("%d\n", go(0,n-1));
	}
	return 0;
}