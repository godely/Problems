#include <bits/stdc++.h>
using namespace std;
#define fr(a,b,c) for(int a = b; a < c; a++)
#define rp(a,b) fr(a,0,b)

int main() {
	int t, n, cas = 1;
	scanf("%d", &t);
	while (t--) {
		scanf("%d", &n);
		int x1 = (45*n)/20;
		int y1 = (30*n)/20;
		int x2 = (55*n)/20;
		printf("Case %d:\n", cas++);
		printf("%d %d\n%d %d\n%d %d\n%d %d\n", -x1, y1, x2, y1, x2, -y1, -x1, -y1);
	}
	return 0;
}