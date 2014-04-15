//by stor
#include <bits/stdc++.h>
#include <algorithm>
#define fr(a,b,c) for(int a = b; a < c; a++)
#define rp(a,b) fr(a,0,b)
#define ll long long
#define MAXN 100010
#define pb push_back
#define mp make_pair
#define pii pair<int, int>
#define f first
#define s second

using namespace std;

int N;
int dp[51][51000], vet[51];

int isWinning(int n1, int nt) {
	if (~dp[n1][nt]) return dp[n1][nt];
	dp[n1][nt] = 0;

	if (nt == 1) dp[n1][nt] = isWinning(n1+1,0);
	else if (n1 > 0 && nt > 1 && !isWinning(n1-1, nt+1)) dp[n1][nt] = 1;
	else if (n1 > 0 && !isWinning(n1-1, nt)) dp[n1][nt] = 1;
	else if (nt > 1 && !isWinning(n1, nt-1)) dp[n1][nt] = 1;
	else if (n1 > 1 && nt > 0 && !isWinning(n1-2, nt+3)) dp[n1][nt] = 1;
	else if (n1 > 1 && nt == 0 && !isWinning(n1-2, nt+2)) dp[n1][nt] = 1;
	return dp[n1][nt];
}

int main() {
	memset(dp, -1, sizeof dp);
	dp[0][0] = 0;
	int cas = 1, T;
	cin.sync_with_stdio(false);
	scanf("%d", &T);
	int n1, nt;
	while (T--) {
		scanf("%d", &N);
		n1 = nt = 0;
		rp(i,N) {
			scanf("%d", &vet[i]);
			if (vet[i]==1) n1++;
			else nt += vet[i]+1;
		}
		if (nt > 0) nt--;
		if (isWinning(n1,nt)) cout << "Case #" << cas++ << ": Alice" << endl;
		else cout << "Case #" << cas++ << ": Bob" << endl;
	}
	return 0;
}