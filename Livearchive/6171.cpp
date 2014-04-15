#include <bits/stdc++.h>
using namespace std;
#define fr(a,b,c) for (int a = b; a < c; a++)
#define rp(a,b) fr(a,0,b)
#define inf 0x3f3f3f3f

char M[200];
int dy[] = {-1,0,1,0};
int dx[] = {0,1,0,-1};

int N, grid[100][100], y, x;
int moves[20];

int vis[100][100], turn = 0;
bool dfs(int i, int j) {
	if (i <= 0 || i >= 99 || j <= 0 || j >= 99) return 1;
	if (vis[i][j] == turn) return 0;
	vis[i][j] = turn;
	rp(k,4) if (grid[i+dy[k]][j+dx[k]] == 0 && dfs(i+dy[k],j+dx[k])) return 1;
	return 0;
}

int resposta;
void solve(int dep, long long m) {
	if (dep > 17 || dep > resposta) return;
	int size = 0;
	long long n = m;
	for (int i = 0; n > 0; i++, n/=5, size++) moves[i] = (n%5)-1;
	int y_ = y, x_ = x;
	int grid2[100][100];
	memset(grid2,0,sizeof grid2);
	for (int i = size-1; i >= 0; i--) {
		y_+=dy[moves[i]];
		x_+=dx[moves[i]];
		grid[y_][x_] = grid2[y_][x_] = 1;
	}
	turn++;
	if (!dfs(y_,x_)) {
		y_ = y, x_ = x;
		for (int i = size-1; i >= 0; i--) {
			y_+=dy[moves[i]];
			x_+=dx[moves[i]];
			grid[y_][x_] = 0;
		}
		resposta = min(dep, resposta);
	} else {
		y_ = y, x_ = x;
		for (int i = size-1; i >= 0; i--) {
			y_+=dy[moves[i]];
			x_+=dx[moves[i]];
			grid[y_][x_] = 0;
		}
		int ret = inf;
		rp(k,4) if (grid[y_+dy[k]][x_+dx[k]] == 0 && grid2[y_+dy[k]][x_+dx[k]] == 0) solve(dep+1,m*5+k+1);
	}
}

int a;
char str[10];
int main() {
	M['N'] = 0; M['E'] = 1; M['S'] = 2; M['W'] = 3;
	while (scanf("%d", &N) == 1 && N > 0) {
		memset(grid,0,sizeof grid);
		y = 50, x = 50;
		grid[y][x] = 1;
		rp(i,N) {
			scanf("%d%s", &a, str);
			rp(j,a) {
				y+=dy[M[str[0]]], x+=dx[M[str[0]]];
				grid[y][x] = 1;
			}
		}
		resposta = inf;
		solve(0,0);
		printf("%d\n", resposta);
	}
	return 0;
}