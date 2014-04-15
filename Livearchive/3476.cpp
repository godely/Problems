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

#define MAXN 1000
#define MAXM 100000
#define add(a,b,c) from[z] = a, to[z] = b, cap[z] = c, ant[z] = adj[a], adj[a] = z++
int from[MAXM], to[MAXM], cap[MAXM], ant[MAXM], z;
int adj[MAXN], copy_adj[MAXN], fila[MAXN], level[MAXN];

//reset: memset(adj,-1,sizeof adj); z = 0;

int bfs(int source, int sink) {
	memset(level,-1,sizeof level);
	level[source] = 0;
	int front = 0, size = 0, v;
	fila[size++] = source;
	while (front < size) {
		v = fila[front++];
		for (int i = adj[v]; i != -1; i = ant[i]) {
			if (cap[i] && level[to[i]] == -1) {
				level[to[i]] = level[v] + 1;
				fila[size++] = to[i];
			}
		}
	}
	return level[sink] != -1;
}

int dfs(int v, int sink, int flow) {
	if (v == sink) return flow;
	int f;
	for (int &i = copy_adj[v]; i != -1; i = ant[i]) {
		if (cap[i] && level[to[i]] == level[v]+1 && (f = dfs(to[i], sink, min(flow, cap[i])))) {
			cap[i]-=f, cap[i^1]+=f;
			return f;
		}
	}
	return 0;
}

int maxflow(int source, int sink) {
	int ret = 0, flow;
	while (bfs(source, sink)) {
		memcpy(copy_adj, adj, sizeof adj);
		while ((flow = dfs(source, sink, 1<<30))) ret += flow;
	}
	return ret;
}

pii p[100];
int sk;
int N, M, B;
int g[10][10], cur[10][10];
int l[10][10];
int idv[10][10], idh[10][10], ids;
int _idv[1000], _idh[1000];
bool light[10][10];
pii pos[1000];
int ps;

int di[] = {1,0,-1,0};
int dj[] = {0,1,0,-1};

bool valid(int i, int j) { return i >= 0 && i < N && j >= 0 && j < M; }

bool can(int i, int j) {
	if (!valid(i,j)) return 0;
	if (g[i][j] != -1) return 0;
	if (light[i][j]) return 0;
	for (int ii = i; ii >= 0 && g[ii][j] == -1; ii--) if (light[ii][j]) return 0;
	for (int ii = i; ii < N && g[ii][j] == -1; ii++) if (light[ii][j]) return 0;
	for (int jj = j; jj >= 0 && g[i][jj] == -1; jj--) if (light[i][jj]) return 0;
	for (int jj = j; jj < M && g[i][jj] == -1; jj++) if (light[i][jj]) return 0;
	rp(k,4) {
		int ni = i+di[k];
		int nj = j+dj[k];
		if (valid(ni,nj) && g[ni][nj] != -1 && cur[ni][nj] >= g[ni][nj]) return 0;
	}
	return 1;
}

int testRes, tmpRes;
void bt2(int x) {
	if (x >= ps) {
		rp(i,N) rp(j,M) if (!l[i][j] && g[i][j] == -1) return;
		testRes = min(testRes,tmpRes);
		return;
	}
	int i = pos[x].F, j = pos[x].S;
	if (!l[i][j] && can(i,j)) {
		for (int ii = i; ii >= 0 && g[ii][j] == -1; ii--) l[ii][j]++;
		for (int ii = i; ii < N && g[ii][j] == -1; ii++) l[ii][j]++;
		for (int jj = j; jj >= 0 && g[i][jj] == -1; jj--) l[i][jj]++;
		for (int jj = j; jj < M && g[i][jj] == -1; jj++) l[i][jj]++;
		light[i][j] = 1;
		tmpRes++;
		bt2(x+1);
		tmpRes--;
		light[i][j] = 0;
		for (int ii = i; ii >= 0 && g[ii][j] == -1; ii--) l[ii][j]--;
		for (int ii = i; ii < N && g[ii][j] == -1; ii++) l[ii][j]--;
		for (int jj = j; jj >= 0 && g[i][jj] == -1; jj--) l[i][jj]--;
		for (int jj = j; jj < M && g[i][jj] == -1; jj++) l[i][jj]--;
		fr(y,x+1,ps) {
			int ni = pos[y].F, nj = pos[y].S;
			if ((ni == i || nj == j) && !l[ni][nj] && can(ni,nj)) {
				bt2(y);
				break;
			}
		}
	} else {
		bt2(x+1);
	}
}

int test() {
	int res = 0;
	cl(l,0);
	rp(i,N) rp(j,M) if (light[i][j]) {
		res++;
		for (int ii = i; ii >= 0 && g[ii][j] == -1; ii--) l[ii][j]++;
		for (int ii = i; ii < N && g[ii][j] == -1; ii++) l[ii][j]++;
		for (int jj = j; jj >= 0 && g[i][jj] == -1; jj--) l[i][jj]++;
		for (int jj = j; jj < M && g[i][jj] == -1; jj++) l[i][jj]++;
	}
	ps = 0;
	rp(i,N) rp(j,M) if (!l[i][j] && g[i][j] == -1 && can(i,j)) pos[ps++] = mp(i,j);
	tmpRes = 0, testRes = oo;
	bt2(0);
	//printf("%d\n", testRes);
	return res+testRes;
}

void update(int i, int j, int d) {
	rp(k,4) {
		int ni = i+di[k];
		int nj = j+dj[k];
		if (valid(ni,nj) && g[ni][nj] != -1) cur[ni][nj] += d;
	}
}

int globRes;
void bt(int x) {
	if (x >= sk) {
		globRes = min(globRes,test());
		return;
	}
	
	int i = p[x].F, j = p[x].S;
	if (g[i][j]-cur[i][j] == 0) bt(x+1);
	if (g[i][j]-cur[i][j] == 1) {
		rp(k1,4) {
			int ni1 = i+di[k1];
			int nj1 = j+dj[k1];
			if (can(ni1,nj1)) {
				light[ni1][nj1] = 1;
				update(ni1,nj1,1);
				bt(x+1);
				update(ni1,nj1,-1);
				light[ni1][nj1] = 0;
			}
		}
	} else if (g[i][j]-cur[i][j] == 2) {
		rp(k1,4) {
			int ni1 = i+di[k1];
			int nj1 = j+dj[k1];
			if (can(ni1,nj1)) {
				light[ni1][nj1] = 1;
				update(ni1,nj1,1);
				fr(k2,k1+1,4) {
					int ni2 = i+di[k2];
					int nj2 = j+dj[k2];
					if (can(ni2,nj2)) {
						light[ni2][nj2] = 1;
						update(ni2,nj2,1);
						bt(x+1);
						update(ni2,nj2,-1);
						light[ni2][nj2] = 0;
					}
				}
				update(ni1,nj1,-1);
				light[ni1][nj1] = 0;
			}
		}
	} else if (g[i][j]-cur[i][j] == 3) {
		rp(k1,4) {
			int ni1 = i+di[k1];
			int nj1 = j+dj[k1];
			if (can(ni1,nj1)) {
				light[ni1][nj1] = 1;
				update(ni1,nj1,1);
				fr(k2,k1+1,4) {
					int ni2 = i+di[k2];
					int nj2 = j+dj[k2];
					if (can(ni2,nj2)) {
						light[ni2][nj2] = 1;
						update(ni2,nj2,1);
						fr(k3,k2+1,4) {
							int ni3 = i+di[k3];
							int nj3 = j+dj[k3];
							if (can(ni3,nj3)) {
								light[ni3][nj3] = 1;
								update(ni3,nj3,1);
								bt(x+1);
								update(ni3,nj3,-1);
								light[ni3][nj3] = 0;
							}
						}
						update(ni2,nj2,-1);
						light[ni2][nj2] = 0;
					}
				}
				update(ni1,nj1,-1);
				light[ni1][nj1] = 0;
			}
		}
	} else if (g[i][j]-cur[i][j] == 4) {
		rp(k1,4) {
			int ni1 = i+di[k1];
			int nj1 = j+dj[k1];
			if (can(ni1,nj1)) {
				light[ni1][nj1] = 1;
				update(ni1,nj1,1);
				fr(k2,k1+1,4) {
					int ni2 = i+di[k2];
					int nj2 = j+dj[k2];
					if (can(ni2,nj2)) {
						light[ni2][nj2] = 1;
						update(ni2,nj2,1);
						fr(k3,k2+1,4) {
							int ni3 = i+di[k3];
							int nj3 = j+dj[k3];
							if (can(ni3,nj3)) {
								light[ni3][nj3] = 1;
								update(ni3,nj3,1);
								fr(k4,k3+1,4) {
									int ni4 = i+di[k4];
									int nj4 = j+dj[k4];
									if (can(ni4,nj4)) {
										light[ni4][nj4] = 1;
										update(ni4,nj4,1);
										bt(x+1);
										update(ni4,nj4,-1);
										light[ni4][nj4] = 0;
									}
								}
								update(ni3,nj3,-1);
								light[ni3][nj3] = 0;
							}
						}
						update(ni2,nj2,-1);
						light[ni2][nj2] = 0;
					}
				}
				update(ni1,nj1,-1);
				light[ni1][nj1] = 0;
			}
		}
	}
}

int main() {
	while (scanf("%d%d", &N, &M) == 2 && N > 0) {
		scanf("%d", &B);
		cl(g,-1);
		cl(cur,0);
		cl(light,0);
		sk = 0;
		int R, C, K;
		rp(i,B) {
			scanf("%d%d%d", &R, &C, &K); R--, C--;
			g[R][C] = K;
			if (K == -1) g[R][C] = 8;
			else p[sk++] = mp(R,C);
		}
		globRes = oo;
		bt(0);
		if (globRes >= oo) printf("No solution\n");
		else printf("%d\n", globRes);
	}
	return 0;
}