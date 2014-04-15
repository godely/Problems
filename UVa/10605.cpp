#include <bits/stdc++.h>
using namespace std;
#define fr(a,b,c) for(int a = b; a < c; a++)
#define rp(a,b) fr(a,0,b)
#define MAXN 500000

char gb[100], grid[100][100];

int dp[1500], vis[12][12][1500], passo = 0;

int di[] = {0,0,1,-1};
int dj[] = {1,-1,0,0};
int n, m, k;
int newMask;

bool pode(int i, int j) {
	return i >= 0 && i < n && j >= 0 && j < m;
}

struct abc {
	int i, j, mask, cost;
	abc() {}
	abc(int i, int j, int mask, int cost) : i(i), j(j), mask(mask), cost(cost) {}
} aux;

queue<abc> fila;
int main() {
	int t;
	scanf("%d", &t);
	while (t--) {
		scanf("%d%d", &n, &m);
		k = 0;
		rp(i,n) {
			scanf("%s", gb);
			rp(j,m) {
				grid[i][j] = (gb[j] == '*') ? '0' + k++ : gb[j];
			}
			grid[i][m] = '\0';
			
		}
		memset(dp,0x3f,sizeof dp);
		dp[0] = 0;
	
		passo++;
		rp(i,n) rp(j,m) {
			if (grid[i][j] >= '0') fila.push(abc(i,j,1<<(grid[i][j]-'0'),0)), vis[i][j][1<<(grid[i][j]-'0')] = passo;
		}
		
		while (!fila.empty()) {
			aux = fila.front(); fila.pop();
			if (grid[aux.i][aux.j] == '#') {
				dp[aux.mask] = min(dp[aux.mask], aux.cost);
				continue;
			}
			rp(k,4) {
				newMask = (grid[aux.i+di[k]][aux.j+dj[k]] >= '0') ? (1<<(grid[aux.i+di[k]][aux.j+dj[k]]-'0'))|aux.mask : aux.mask;
				if (vis[aux.i+di[k]][aux.j+dj[k]][newMask] != passo) {
					if (grid[aux.i+di[k]][aux.j+dj[k]] != '#') vis[aux.i+di[k]][aux.j+dj[k]][newMask] = passo;
					fila.push(abc(aux.i+di[k], aux.j+dj[k], newMask, aux.cost+1));
				}
			}
		}
		int lim = (1<<k);
		for (int i = 1; i < (1<<k); i++) {
			for (int j = i; j; j = (j-1)&i) {
				dp[i] = min(dp[i], dp[j] + dp[i-j]);
			}
		}
		printf("%d\n", dp[(1<<k)-1]);
	}
	return 0;
}