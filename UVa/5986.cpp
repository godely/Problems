#include <bits/stdc++.h>
#define fr(a,b,c) for(int a = b; a < c; a++)
#define rp(a,b) fr(a,0,b)
#define inf 0x3f3f3f3f
#define pb push_back
#define mp make_pair
#define MAXN 110
using namespace std;

int v[100], dp[100];
int main() {
	int T, N;
	scanf("%d", &T);
	while (T--) {
		scanf("%d", &N);
		rp(i,N) scanf("%d", &v[i]), dp[i] = (i*(i+1))/2;
		sort(v, v+N);
		int res = 0;
		rp(i,N) {
			if (i > 0) v[i] += v[i-1];
			if (dp[i] > v[i]) {
				res+=(dp[i]-v[i]);
				v[i] = dp[i];
			}
		}
		res+=(v[N-1]-dp[N-1]);
		printf("%d\n", res);
	}
	return 0;
}