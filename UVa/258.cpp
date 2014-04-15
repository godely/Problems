#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <algorithm>
#include <vector>
#include <iostream>
#include <map>
#include <utility>
#include <iostream>
#include <set>
#include <cassert>
#define mp make_pair
using namespace std;
#define fr(a,b,c) for(int a = b; a < c; a++)
#define rp(a,b) fr(a,0,b)
#define cl(a,b) memset(a,b,sizeof a)
#define mp make_pair
#define F first
#define S second
#define oo 0x3f3f3f3f
typedef long long ll;
typedef unsigned long long ull;
typedef pair<int,int> pii;

int n, m;
char g[100][100];
pair<pii,int> ns[3];
int sz;
pii to[100][100][5];
bool vis[100][100][5];
int pr[100][100];

int di[] = {1,0,-1,0};
int dj[] = {0,1,0,-1};
char dc[] = {92, 47};

bool valid(int i, int j) { return i >= 0 && i < n && j >= 0 && j < m; }

bool dfs(int i, int j, int d) {
	vis[i][j][d] = 1;
	if (g[i][j] == '.') return 1;

	int k = (d+1)&3;
	int ni = to[i][j][k].F;
	int nj = to[i][j][k].S;
	if (ni != -1 && !vis[ni][nj][k] && (pr[i][j] == -1 || pr[i][j] == (d&1))) {
		if (g[i][j] != '.') g[i][j] = dc[d&1];
		pr[i][j] = d&1;
		if (dfs(ni,nj,k)) return 1;
		pr[i][j] = -1;
	}
	k = (d+3)&3;
	ni = to[i][j][k].F;
	nj = to[i][j][k].S;
	if (ni != -1 && !vis[ni][nj][k] && (pr[i][j] == -1 || pr[i][j] == (!(d&1)))) {
		if (g[i][j] != '.') g[i][j] = dc[!(d&1)];
		pr[i][j] = !(d&1);
		if (dfs(ni,nj,k)) return 1;
		pr[i][j] = -1;
	}
	vis[i][j][d] = 0;
	return 0;
}

int main() {
	bool ok = 0;
	while (scanf("%d%d", &m, &n) == 2 && m != -1) {
		rp(i,n) scanf("%s", g[i]);
		sz = 0;
		rp(i,n) {
			if (g[i][0] != '*') ns[sz++] = mp(mp(i,0),1);
			if (g[i][m-1] != '*') ns[sz++] = mp(mp(i,m-1),3);
		}
		rp(j,m) {
			if (g[0][j] != '*') ns[sz++] = mp(mp(0,j),0);
			if (g[n-1][j] != '*') ns[sz++] = mp(mp(n-1,j),2);
		}
		int aff = 0;
		rp(i,n) rp(j,m) {
			if (g[i][j] == 47 || g[i][j] == 92) {
				aff++;
				rp(k,4) {
					int ni = i+di[k], nj = j+dj[k];
					while (valid(ni,nj) && g[ni][nj] == '.') ni+=di[k], nj+=dj[k];
					if (!valid(ni,nj)) ni-=di[k], nj-=dj[k];
					to[i][j][k] = mp(-1,-1);
					if (valid(ni,nj) && g[ni][nj] != '*' && (ni != i || nj != j)) to[i][j][k] = mp(ni,nj);
				}
			}
		}
		cl(vis,0);
		cl(pr,-1);
		int ni = ns[0].F.F, nj = ns[0].F.S, k = ns[0].S;
		while (valid(ni,nj) && g[ni][nj] == '.') ni+=di[k], nj+=dj[k];
		if (valid(ni,nj)) {
			if (!dfs(ni,nj,k)) {
				assert(false);
				while(1);
			}
		}

		if (ok) puts("");
		else ok = 1;
		rp(i,n) {
			rp(j,m) printf("%c", g[i][j]);
			puts("");
		}
	}
	return 0;
}