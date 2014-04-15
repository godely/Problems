#include <bits/stdc++.h>
using namespace std;
#define fr(a,b,c) for(int a = b; a < c; a++)
#define rp(a,b) fr(a,0,b)
typedef long long ll;

bool dp[2][3000];
int v[150], n, p, a;
int main() {
	int t; scanf("%d", &t);
	while (t--) {
		scanf("%d", &n); n/=10;
		scanf("%d", &p);
		rp(i,p) scanf("%d", &v[i]), v[i]/=10;
		memset(dp,0,sizeof dp);
		dp[1][0] = 1;
		rp(i,p) {
			a = i&1;
			rp(j,2501) {
				dp[a][j] = dp[a^1][j];
				if (j >= v[i]) dp[a][j] |= dp[a^1][j-v[i]];
			}
		}
		a = (p&1)^1;
		fr(i,n,2501) if (dp[a][i]) {
			printf("%d\n", i*10);
			goto fim;
		}
		printf("NO SOLUTION\n");
		fim:;
	}
	return 0;
}