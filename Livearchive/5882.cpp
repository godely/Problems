#include <bits/stdc++.h>
using namespace std;
#define fr(a,b,c) for(int a = b; a < c; a++)
#define rp(a,b) fr(a,0,b)
#define MAXN 101000

int N, M;
char grid[111][111];
int di[] = {1,-1,0,0};
int dj[] = {0,0,1,-1};

bool pode(int i, int j) {
	return i >= 0 && i < N && j >= 0 && j < M;
}

int id(int i, int j) {
	return i*M + j;
}

int owner[MAXN], vis[MAXN], passo = 0, LEFT[MAXN], sl, block;
int adj[MAXN][5], size[MAXN];
int AlternatingPath(int u) {
	if (vis[u] == passo) return 0;
	vis[u] = passo;
	for (int j = 0; j < size[u]; j++) {
		int v = adj[u][j];
		if (v == block) continue;
		if (owner[v] == -1 || AlternatingPath(owner[v])) {
			owner[v] = u;
			return 1;
		}
	}
	return 0;
}

int matching() {
	int C = 0;
	memset(owner, -1, sizeof owner);
	rp(i,sl) {
		if (LEFT[i] == block) continue;
		passo++;
		C += AlternatingPath(LEFT[i]);
	}
	return C;
}

int main() {
	int TOTAL, D = 0;
	while (scanf("%d%d", &N, &M) == 2 && N > 0) {
		rp(i,N) {
			scanf("%s", grid[i]);
			rp(j,M) D += (grid[i][j] == '.');
		}
		sl = 0;
		for (int i = 0; i < N; i++) {
			for (int j = i&1; j < M; j+=2) {
				if (grid[i][j] == 'X') continue;
				LEFT[sl++] = id(i,j);
				size[id(i,j)] = 0;
				rp(k,4) {
					if (pode(i+di[k], j+dj[k]) && grid[i+di[k]][j+dj[k]] == '.') {
						adj[id(i,j)][size[id(i,j)]++] = id(i+di[k], j+dj[k]);
					}
				}
				//printf("%d size:%d\n", id(i,j), size[id(i,j)]);
			}
		}
		block = -1;
		TOTAL = matching();
		rp(i,N) {
			rp(j,M) {
				if (grid[i][j] == 'X') printf("X");
				else {
					block = id(i,j);
					if (matching() == TOTAL) printf("B");
					else printf("A");
				}
			}
			printf("%c",10);
		}
		printf("%c",10);
	}
	return 0;
}