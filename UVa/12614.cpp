#include <bits/stdc++.h>
using namespace std;
#define fr(a,b,c) for(int a = b; a < c; a++)
#define rp(a,b) fr(a,0,b)

int main() {
	int t, n, cas = 1;
	scanf("%d", &t);
	while (t--) {
		scanf("%d", &n);
		int res = 0, a;
		while (n--) {
			scanf("%d", &a);
			res = max(res,a);
		}
		printf("Case %d: %d\n", cas++, res);
	}
	return 0;
}