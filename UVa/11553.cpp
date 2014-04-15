#include <bits/stdc++.h>
using namespace std;
#define fr(a,b,c) for(int a = b; a < c; a++)
#define rp(a,b) fr(a,0,b)

int grid[10][10];
int perm[10];

int main() {
	int T, N, res, temp;
	scanf("%d", &T);
	while (T--) {
		scanf("%d", &N);
		rp(i,N) rp(j,N) scanf("%d", &grid[i][j]);
		rp(i,N) perm[i] = i;
		res = 0x3f3f3f3f;
		do {
			temp = 0;
			rp(i,N) temp += grid[i][perm[i]];
			res = min(res, temp);
		} while (next_permutation(perm, perm+N) != 0);
		printf("%d\n", res);
	}
	return 0;
}