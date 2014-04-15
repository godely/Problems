#include <cstdio>
#include <cmath>
#include <algorithm>
#include <cstring>
#include <iostream>
using namespace std;
#define fr(a,b,c) for(int a = b; a < c; a++)
#define rp(a,b) fr(a,0,b)

const double EPS = 1e-9;
int N, M, Q, TOTAL;
int K[20];
long long C[55][55], P[55], dp[60][1<<13];
void fw() { rp(k,N) rp(i,N) rp(j,N) C[i][j] = min(C[i][j], C[i][k]+C[k][j]); }

int calc[60][1<<13], passo = 0;

long long solve(int ind, int mask) {
	if (mask == TOTAL) return -C[ind][0];
	if (calc[ind][mask] == passo) return dp[ind][mask];
	calc[ind][mask] = passo;
	 
	long long ret = -C[ind][0];
	for (int i = 0; i < Q; i++) {
		if (!(mask&(1<<i))) {
			ret = max(ret, -C[ind][K[i]]+P[i]+solve(K[i],mask|(1<<i)));
		}
	}
	return dp[ind][mask] = ret;
}

int main() {
	int T, a, b;
	long long c, d;
	scanf("%d", &T);
	while (T--) {
		scanf("%d%d", &N, &M);
		N++;
		rp(i,N) rp(j,N) C[i][j] = 1e17;
		rp(i,N) C[i][i] = 0;
		rp(i,M) scanf("%d %d %lld.%lld", &a, &b, &c, &d), c=(c*100)+d, C[a][b] = C[b][a] = min(c, C[a][b]);
		fw();
	   
		scanf("%d", &Q);
		TOTAL = (1<<Q)-1;
		rp(i,Q) scanf("%d %lld.%lld", &a, &c, &d), c=(c*100)+d, K[i] = a, P[i] = c;
		passo++;
		long long ret = solve(0,0);
		if (ret > 0) printf("Daniel can save $%lld.%.2lld\n", ret/100, ret%100);
		else printf("Don't leave the house\n");
	}
}