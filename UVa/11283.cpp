#include <bits/stdc++.h>
using namespace std;
#define fr(a,b,c) for(int a = b; a < c; a++)
#define rp(a,b) fr(a,0,b)

char grid[10][10];
char P[20];
int p[] = {-1, -1, -1, 0, 1, 1, 1, 0};
int q[] = {-1, 0, 1, 1, 1, 0, -1, -1};

int size;
bool pode(int i, int j) { return (i >= 0 && i < 4 && j >= 0 && j < 4 && grid[i][j] != '.'); }
bool dfs(int i, int j, int k) {
	if (grid[i][j] == P[k]) {
		if (k == size-1) return 1;
		bool ok;
		char aux;
		rp(t,8) if (pode(i+p[t], j+q[t])) {
			aux = grid[i][j];
			grid[i][j] = '.';
			ok = dfs(i+p[t], j+q[t], k+1);
			grid[i][j] = aux;
			if (ok) return 1;
		}
	}
	return 0;
}

int main() {
	int T, n, sum, cas = 1;
	scanf("%d", &T);
	while (T--) {
		rp(i,4) {
			scanf("%s", grid[i]);
		}
		scanf("%d", &n);
		sum = 0;
		while (n--) {
			scanf("%s", P);
			size = strlen(P);
			rp(i,4) rp(j,4) if (grid[i][j] == P[0]) {
				if (dfs(i,j,0)) {
					if (size==3) sum++;
					else if (size < 7) sum+=size-3;
					else if (size == 7) sum+=5;
					else sum+=11;
					goto xD;
				}
			}
			xD:;
		}
		printf("Score for Boggle game #%d: %d\n", cas++, sum);
	}
	return 0;
}