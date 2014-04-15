
#include <bits/stdc++.h>
using namespace std;
#define fr(a,b,c) for(int a=b; a<c; a++)
#define rp(a,b) fr(a,0,b)
#define cl(a,b) memset(a, b, sizeof(a))
#define LL long long

int N, K;
LL dp[1<<12][11];
int calc[1<<12][11], passo=0;
LL solve(int mask, int rest, int count) {
	if (rest == 0) return count==K;
	if (calc[mask][rest]==passo) return dp[mask][rest];
	calc[mask][rest] = passo;

	LL ret = 0;
	for (int i = 0; i < N; i++) {
		ret += solve(mask|(1<<i), rest-1, count+((mask&(1<<i))==0));
	}
	return dp[mask][rest] = ret;
}

LL gcd(LL a, LL b) {
	if (!a || !b) return max(a,b);
	return gcd(a%b, b%a);
}

int main() {
	int T, M;
	scanf("%d", &T);
	while (T--) {
		scanf("%d%d%d", &N, &M, &K);
		passo++;
		LL ret = solve(0,M,0);
		LL lol = 1;
		rp(i,M) lol*=N;
		LL g = gcd(ret,lol);
		if (ret==0 || ret==lol) printf("%d\n", ret==0?0:1);
		else printf("%lld/%lld\n", ret/g, lol/g);
	}
	return 0;
}
