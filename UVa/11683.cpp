#include <bits/stdc++.h>
using namespace std;
#define fr(a,b,c) for(int a = b; a < c; a++)
#define rp(a,b) fr(a,0,b)

int main() {
	int A, C, a, b, res;
	while (scanf("%d", &A) == 1 && A > 0) {
		scanf("%d", &C);
		a = A;
		res = 0;
		rp(i,C) {
			scanf("%d", &b);
			if (b > a) res += b-a;
			a = b;
		}
		printf("%d\n", res+A-b);
	}
	return 0;
}