#include <bits/stdc++.h>
using namespace std;
#define Fr(a,b,c) for(int a = b; a < c; a++)
#define Rp(a,b) Fr(a,0,b)
#define F first
#define S second
#define pb push
#define mp make_pair

int n, m, a, b;
int main() {
	while (scanf("%d%d", &n, &m) == 2) {
		int res = 1000000000;
		Rp(i,m) {
			scanf("%d%d", &a, &b);
			if (a*n%(a+b) > 0) res = min(res, a*n%(a+b));
			else res = min(res, (a+b));
		}
		printf("%d\n", res);
	}
	return 0;
}