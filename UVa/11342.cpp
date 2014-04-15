#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <cmath>
#include <algorithm>
#include <vector>
#include <iostream>

using namespace std;

int N, square[6000], k;

int A[30000], B[30000], M[30000], aff[3];

int main() {
	for (int i = 0; i <= 223; i++) {
		for (int j = i; j <= 223; j++) {
			A[k] = i;
			B[k] = j;
			M[k] = i*i + j*j;
			k++;
		}
	}
	int T, sq;
	bool foi;
	scanf("%d", &T);
	while (T--) {
		scanf("%d", &N);
		foi = false;
		for (int i = 0; i < k; i++) {
			if (M[i] <= N) {
				sq = sqrt(N-M[i]);
				if (sq*sq == N-M[i]) {
					aff[0] = A[i];
					aff[1] = B[i];
					aff[2] = sq;
					sort(aff,aff+3);
					printf("%d %d %d\n", aff[0], aff[1], aff[2]);
					foi = true;
					break;
				}
			}
		}
		if (!foi)
			printf("-1\n");
	}
	return 0;
}
