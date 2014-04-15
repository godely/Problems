#include <bits/stdc++.h>
using namespace std;
#define fr(a,b,c) for(int a = b; a < c; a++)
#define rp(a,b) fr(a,0,b)
typedef long long ll;

ll n, m;

ll f[1000], s[1000];
int main() {
	f[1] = 1;
	f[2] = 1;
	fr(i,3,301) f[i] = (f[i-1]+f[i-2])%100;
	s[0] = 0;
	fr(i,1,301) s[i] = f[i]+s[i-1];
	int t; scanf("%d", &t);
	while (t--) {
		scanf("%lld%lld", &n, &m);
		ll resA = (m/300)*s[300]+s[m%300];
		ll resB = ((n-1)/300)*s[300]+s[(n-1)%300];
		printf("%lld\n", resA-resB);
	}
	return 0;
}