#include <bits/stdc++.h>
using namespace std;
#define fr(a,b,c) for(int a = b; a < c; a++)
#define rp(a,b) fr(a,0,b)
#define F first
#define S second
#define maxn 511
#define mp make_pair

char base[] = "()";
int pot2[50];
int N, K, M;

void solve(int n, int k, int m) {
	if (n == 1) {
		fr(i,k,k+m) printf("%c", base[i]);
		return;
	} else {
		if (!k) {
			printf("(");
			k++, m--;
		}
		int count = 1;
		for (int i = 1; m > 0 && i < n; i++) {
			if (count + pot2[i] > k) {
				if (m <= pot2[i]-(k-count)) {
					solve(i, k-count, m);
					return;
				} else {
					solve(i, k-count, pot2[i]-(k-count));
					m -= (pot2[i]-(k-count));
					k += (pot2[i]-(k-count));
				}
			}
			count += pot2[i];
		}
		if (m > 0) printf(")");
	}
}

int main() {
	pot2[0] = 1;
	fr(i,1,32) pot2[i] = pot2[i-1]<<1;
	while (scanf("%d%d%d", &N, &K, &M) == 3 && N > 0) {
		solve(N, K, M);
		printf("\n");
	}
	return 0;
}