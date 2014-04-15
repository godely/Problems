#include <bits/stdc++.h>
using namespace std;
#define fr(a,b,c) for(int a = b; a < c; a++)
#define rp(a,b) fr(a,0,b)

char grid[111][111];
char P[111];
int p[] = {-1, -1, -1, 0, 1, 1, 1, 0};
int q[] = {-1, 0, 1, 1, 1, 0, -1, -1};
int n;

int size;
int dfs(int i, int j, int dir, int k) {
	if (k == size) return 1;
	if (i < 0 || i >= n || j < 0 || j >= n) return 0;
	if (grid[i][j] == P[k]) return dfs(i+p[dir], j+q[dir], dir, k+1);
	return 0;
}

int main() {
	scanf("%d", &n);
	while (n > 0) {
		rp(i,n) {
			scanf("%s", grid[i]);
		}
		while (scanf("%s", P)) {
			if (P[0] < 'A') {
				n = atoi(P);
				break;
			}
			size = strlen(P);
			rp(i,n) rp(j,n) if (grid[i][j] == P[0]) rp(t,8) {
				if (dfs(i,j,t,0)) {
					printf("%d,%d %d,%d\n", i+1, j+1, i+1+p[t]*(size-1), j+1+q[t]*(size-1));
					goto xD;
				}
			}
			printf("Not found\n");
			xD:;
		}
	}
	return 0;
}