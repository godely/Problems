#include <cstdio>
#include <cstdlib>
#include <algorithm>
#include <vector>
#include <cmath>
#include <map>
#include <set>
#include <iostream>
#include <cstring>
using namespace std;
#define fr(a,b,c) for (int a = b; a < c; a++)
#define rp(a,b) fr(a,0,b)
#define CL(a,b) memset((a),(b),sizeof (a))
#define MAXN 100000
#define MAXM 1000000
typedef long long ll;

ll x, y, d;
void ee(ll a, ll b) {
	if (b == 0) {
		x = 1, y = 0, d = a;
		return;
	}
	ee(b,a%b);
	ll x1 = y;
	ll y1 = x - (a/b) * y;
	x = x1;
	y = y1;
}

int main() {
	ll n, c1, n1, c2, n2, a, b, a1, b1;
	while (scanf("%lld", &n) == 1 && n > 0) {
		scanf("%lld%lld%lld%lld", &c1, &n1, &c2, &n2);
		ee(n1,n2);

		if (n%d != 0) puts("failed");
		else {
			x *= n / d, y *= n / d;
			n2 /= d, n1 /= d;

			ll c = ceil(-(double) x / n2), f = floor((double) y / n1);
			//printf("%lld %lld, %lld %lld\n", x, y, c, f);
			if (c > f) puts("failed");
			else {
				a = x + n2 * c;
				b = y - n1 * c;

				a1 = x + n2 * f;
		 		b1 = y - n1 * f;

		 		if (c1*a + c2*b < c1*a1 + c2*b1) printf("%lld %lld\n", a, b);
		 		else printf("%lld %lld\n", a1, b1);
			}
		}
	}
	return 0;
}