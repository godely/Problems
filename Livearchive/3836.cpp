#include <bits/stdc++.h>
using namespace std;
#define fr(a,b,c) for(int a = b; a < c; a++)
#define rp(a,b) fr(a,0,b)
#define inf 0x3f3f3f3f

int N, C, m[1011][1011];
int dp[1011][1011], calc[1011][1011], passo = 0;

int solve(int year, int last) {
	if (year >= N) return (year == last) ? 0 : inf;
	if (calc[year][last] == passo) return dp[year][last];
	calc[year][last] = passo;
	return dp[year][last] = min(solve(year+1,last), C + m[last][year] + solve(year+1,year+1));
}

int main() {
	while (scanf("%d", &C) == 1) {
		passo++;
		scanf("%d", &N);
		rp(i,N) fr(j,i,N) {
			scanf("%d", &m[i][j]);
		}
		printf("%d%c", solve(0,0), 10);
	}
	return 0;
}
