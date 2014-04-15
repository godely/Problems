#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
#define fr(a,b,c) for(int a = b; a < c; a++)
#define rp(a,b) fr(a,0,b)
#define maxn 1000100

ll dp[maxn];
int main() {
	dp[3] = 0;
	ll cnt = 0;
	fr(i,4,maxn) cnt += (i-2)>>1, dp[i] = dp[i-1] + cnt;
	int N;
	while (scanf("%d", &N) == 1 && N >= 3) printf("%lld\n", dp[N]);
	return 0;
}
