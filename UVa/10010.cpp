#include <bits/stdc++.h>
using namespace std;
#define MAX_N 300000
#define inf 0x3f3f3f3f
#define fr(a,b,c) for(int a = b; a < c; a++)
#define rp(a,b) fr(a,0,b)

char grid[100][100];
char P[100];
int p[] = {-1, -1, -1, 0, 1, 1, 1, 0};
int q[] = {-1, 0, 1, 1, 1, 0, -1, -1};
int n, m;

int size;
int dfs(int i, int j, int dir, int k) {
	if (k == size) return 1;
	if (i < 0 || i >= n || j < 0 || j >= m) return 0;
	if (grid[i][j] == P[k]) return dfs(i+p[dir], j+q[dir], dir, k+1);
	return 0;
}

int main() {
	int T, ok = 0, k;
	scanf("%d", &T);
	while (T--) {
		if (ok) printf("\n");
		else ok = 1;
		scanf("%d%d", &n, &m);
		rp(i,n) {
			scanf("%s", grid[i]);
			rp(j,m) grid[i][j]|=0x20;
		}
		scanf("%d", &k);
		while(k--) {
			scanf("%s", &P);
			size = strlen(P);
			rp(i,size) P[i]|=0x20;
			rp(i,n) rp(j,m) if (grid[i][j] == P[0]) rp(t,8) {
				if (dfs(i,j,t,0)) {
					printf("%d %d\n", i+1, j+1);
					goto xD;
				}
			}
			xD:;
		}
	}
	return 0;
}