#include <bits/stdc++.h>
using namespace std;
#define fr(a,b,c) for (int a = b; a < c; a++)
#define rp(a,b) fr(a,0,b)
#define F first
#define S second

int grid[111][111][2], a;
int di[] = {1,-1,0,0};
int dj[] = {0,0,1,-1};

int N, R, C, K;

bool pode(int i, int j) {
	return i >= 0 && i < R && j >= 0 && j < C;
}

int main() {
	while (scanf("%d%d%d%d", &N, &R, &C, &K) == 4 && N > 0) {
		rp(i,R) rp(j,C) {
			scanf("%d", &grid[i][j][0]);
		}
		a = 0;
		while (K--) {
			rp(i,R) rp(j,C) {
				grid[i][j][a^1] = grid[i][j][a];
				rp(k,4) {
					if (pode(i+di[k],j+dj[k]) && (grid[i+di[k]][j+dj[k]][a]+1)%N == grid[i][j][a]) {
						grid[i][j][a^1] = grid[i+di[k]][j+dj[k]][a];
						break;
					}
				}
			}
			a ^= 1;
		}
		rp(i,R) {
			printf("%d", grid[i][0][a]);
			fr(j,1,C) printf(" %d", grid[i][j][a]);
			printf("\n");
		}
	}
	return 0;
}
