#include <bits/stdc++.h>
using namespace std;
#define fr(a,b,c) for(int a = b; a < c; a++)
#define rp(a,b) fr(a,0,b)
#define mod 1000000007

double div2[111];
int S, B;

int qnt[111][211]; //qnt[i][j]: de quantas formas eu posso preencher i-1 caixas com j pedras
int comb(int ind, int rest) {
	if (~qnt[ind][rest]) return qnt[ind][rest];
	if (ind == 0) return 1;
	
	int K = 0, i = 0;
	if (ind == 2) i = rest;
	for (; i <= rest; i++) K = (K + comb(ind-1, rest-i))%mod;
	return qnt[ind][rest] = K;
}

int start;
map<double, int> dp[111][111][211];
int solve(int ind, int rest, double m) {
	if (dp[start][ind][rest].count(m) != 0) return dp[start][ind][rest][m];
	if (m >= 1.0) return dp[start][ind][rest][m] = 0;
	if (m + rest*div2[B-ind+1] < 1.0) return dp[start][ind][rest][m] = qnt[ind][rest];
	if (ind == 1) return dp[start][ind][rest][m] = 1;
	int K = 0, i = 0;
	if (ind == 2) i = rest;
	for (; i <= rest; i++) {
		K = (K + solve(ind-1, rest-i, m + i*div2[B-ind+1]))%mod;
	}
	return dp[start][ind][rest][m] = K;
}

int main() {
	double p = 1;
	fr(i,1,102) p/=2.0, div2[i] = p;

	memset(qnt, -1, sizeof qnt);
	for (int i = 2; i <= 100; i++) for (int j = 1; j <= 200; j++) if (qnt[i][j] == -1) comb(i,j);

	while (scanf("%d%d", &S, &B) == 2) {
		start = B;
		printf("%d\n", solve(B, S, 0.0));
	}
	return 0;
}