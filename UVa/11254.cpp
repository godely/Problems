#include <bits/stdc++.h>
using namespace std;

int main() {
	int N;
	while (scanf("%d", &N) == 1 && N > 0) {
		N*=2;
		int sq = sqrt(N);
		for (int i = sq; i > 0; i--) if (N%i == 0) {
			int A = i;
			int B = N/A;
			if ((B-A+1)%2 == 0 && B-A+1 > 0) {
				int a1 = (B-A+1)/2;
				int an = a1 + A - 1;
				printf("%d = %d + ... + %d\n", N/2, a1, an);
				break;
			}
		}
	}
	return 0;
}