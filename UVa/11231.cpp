//by stor
#include <bits/stdc++.h>
#define fr(a,b,c) for(int a = b; a < c; a++)
#define rp(a,b) fr(a,0,b)
#define ll long long
#define MAXN 100100

int main() {
	ll a, b, c, d;
	while (scanf("%lld%lld%lld", &a, &b, &c) == 3 && a > 0) {
		d = (a-7)*(b-7);
		printf("%lld\n", (d+c)/2);
	}
	return 0;
}