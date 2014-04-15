#include <bits/stdc++.h>
using namespace std;
#define fr(a,b,c) for(int a = b; a < c; a++)
#define rp(a,b) fr(a,0,b)
#define inf 0x3f3f3f3f

int N;
char p[20][30];
int size[20];
int f[20][30];
int trans[20][20];
void prekmp(int k) {
	int i = 0, j = -1;
	f[k][0] = -1;
	while (i < size[k]) {
		while (j >= 0 && p[k][i] != p[k][j]) j = f[k][j];
		i++, j++;
		f[k][i] = j;
	}
}

int kmp(int x, int y) {
	int i = 0, j = 0;
	while (i < size[y]) {
		while (j >= 0 && p[y][i] != p[x][j]) j = f[x][j];
		i++, j++;
		if (j == size[x]) return size[x];
	}
	return j;
}

int COMPLETE, done[20][1<<15], yes = 0, dp[20][1<<15];
int solve(int i, int mask) {
	if (done[i][mask] == yes) return dp[i][mask];
	if (mask == COMPLETE) return 0;
	done[i][mask] = yes;

	int ret = inf;
	rp(j,N) {
		if (!(mask&(1<<j))) {
			ret = min(ret, trans[i][j]+solve(j,mask|(1<<j)));
		}
	}
	return dp[i][mask] = ret;
}

int main() {
	while (scanf("%d", &N) == 1 && N > 0) {
		rp(i,N) scanf("%s", p[i]), size[i] = strlen(p[i]), prekmp(i);
		rp(i,N) {
			trans[15][i] = size[i];
			rp(j,N) {
				if (i != j) {
					trans[j][i] = size[i]-kmp(i,j);
				}
			}
		}
		COMPLETE = (1<<N)-1;
		yes++;
		printf("%d\n", solve(15,0));
	}
}