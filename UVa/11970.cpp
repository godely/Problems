#include <bits/stdc++.h>
using namespace std;
#define fr(a,b,c) for (int a = b; a < c; a++)
#define rp(a,b) fr(a,0,b)

int N, X;

int main() {
	int cas = 1;
	int T; scanf("%d", &T);
	while (T--) {
		scanf("%d", &N);
		int sq = sqrt(N);
		printf("Case %d:", cas++);
		for (int i = sq; i > 0; i--) {
			X = N - i*i;
			if (!X) continue;
			if (X%i==0) printf(" %d", X);
		}
		printf("\n");
	}
	return 0;
}