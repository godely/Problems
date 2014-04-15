#include <bits/stdc++.h>
using namespace std;
#define fr(a,b,c) for(int a = b; a < c; a++)
#define rp(a,b) fr(a,0,b)

struct vetor {
	int x, y;
	vetor() {}
	vetor(int x, int y) : x(x), y(y) {}
	
	bool operator <(const vetor &lhs) const {
		if (x == 0 || lhs.x == 0) return x == 0;
		else return (double)y/x > (double)lhs.y/lhs.x;
	}
} V[100];

int N, K;
int dp[55][55][2600], calc[55][55][2600], passo=0;
int solve(int ind, int k, int alt) {
	if (k == 0) return 0;
	if (calc[ind][k][alt] == passo) return dp[ind][k][alt];
	calc[ind][k][alt] = passo;

	if (k >= N-ind) return dp[ind][k][alt] = V[ind].x*(2*alt + V[ind].y) + solve(ind+1,k-1,alt+V[ind].y);
	return dp[ind][k][alt] = max(V[ind].x*(2*alt + V[ind].y) + solve(ind+1,k-1,alt+V[ind].y), solve(ind+1, k, alt));
}

int main() {
	int T, altura, area, cas = 1;
	scanf("%d", &T);
	while (T--) {
		passo++;
		scanf("%d%d", &N, &K);
		rp(i,N) scanf("%d%d", &V[i].x, &V[i].y);
		sort(V,V+N);
		printf("Case %d: %d\n", cas++, solve(0,K,0));
	}
	return 0;
}