#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <iostream>
#include <cmath>
#include <queue>
#include <algorithm>
using namespace std;
#define fr(a,b,c) for(int a = b; a < c; a++)
#define rp(a,b) fr(a,0,b)
#define mp make_pair
#define pb push
#define inf 0x3f3f3f3f3f3f3f3fLL
#define idx(x) id2[(x&(-x))]
#define LL long long

LL mat[25][25];
int n, m, l;
void ff() { rp(k,n) rp(i,n) rp(j,n) mat[i][j] = min(mat[i][j], mat[i][k]+mat[k][j]); }

int vec[1111111], t, id2[1111111];
void gen(int mask, int ind) {
	int k = __builtin_popcount(mask);
	if (k == l) {
		vec[t++] = mask;
		return;
	}
	if (ind >= n-2) return;
	gen(mask|(1<<ind),ind+1);
	if (n-2-ind > l-k) gen(mask,ind+1);
}

LL dp1[20][(1<<18)+100], dp2[20][(1<<18)+100];
int mark1[20][(1<<18)+100], passo1 = 0, mark2[20][(1<<18)+100], passo2 = 0;
LL solve1(int ind, int mask) {
	if (mark1[ind][mask] == passo1) return dp1[ind][mask];
	mark1[ind][mask] = passo1;
	if (!mask) return dp1[ind][mask] = mat[ind][0];
	int s = mask;
	LL res = inf;
	while (s > 0) {
		res = min(res, mat[ind][idx(s)]+solve1(idx(s), mask-(s&(-s))));
		s -= s&(-s);
	}
	return dp1[ind][mask] = res;
}

LL solve2(int ind, int mask) {
	if (mark2[ind][mask] == passo2) return dp2[ind][mask];
	mark2[ind][mask] = passo2;
	if (!mask) return dp2[ind][mask] = mat[ind][n-1];
	int s = mask;
	LL res = inf;
	while (s > 0) {
		res = min(res, mat[ind][idx(s)]+solve2(idx(s), mask-(s&(-s))));
		s -= s&(-s);
	}
	return dp2[ind][mask] = res;
}

int main() {
	int a, b, c, cas = 1;
	rp(i,20) id2[1<<i] = i+1;
	while (scanf("%d%d", &n, &m) == 2) {
		t = 0;
		l = (n-2)/2;
		memset(mat,0x3f,sizeof mat);
		rp(i,n) mat[i][i] = 0;
		rp(i,m) {
			scanf("%d%d%d", &a, &b, &c);
			mat[a][b] = mat[b][a] = c;
		}
		ff();
		if (n == 3) printf("Case %d: %d\n", cas++, 1<<(mat[0][1]+mat[1][2]));
		else {
			passo1++; passo2++;
			gen(0,0);
			rp(i,t) {
				int s = vec[i];
				while (s > 0) {
					dp1[idx(s)][vec[i]] = solve1(idx(s), vec[i]-(s&(-s)));
					dp2[idx(s)][vec[i]] = solve2(idx(s), vec[i]-(s&(-s)));
					s-=(s&(-s));
				}
			}
			int LIM = (1<<(n-2))-1;
			LL res = inf;
			rp(i,t) {
				int vecj = LIM-vec[i];
				//printf("%d %d\n", vec[i], vecj);
				LL min1 = inf, min2 = inf;
				if (n&1) {
					for (int s = vecj; s; s -= (s&(-s))) {
						for (int p = vec[i]; p; p -= (p&(-p))) {
							for (int q = vecj-(s&(-s)); q; q -= (q&(-q))) {
								//printf("%d(%d) %d(%d) %d: %d %d %d %d\n", vec[i], idx(p), vecj, idx(q), idx(s), dp1[idx(p)][vec[i]], mat[idx(p)][idx(s)], mat[idx(s)][idx(q)], dp2[idx(q)][vecj-(s&(-s))]);
								min1 = min(min1, dp1[idx(p)][vec[i]]+mat[idx(p)][idx(s)]+mat[idx(s)][idx(q)]+dp2[idx(q)][vecj-(s&(-s))]);
								min2 = min(min2, dp2[idx(p)][vec[i]]+mat[idx(p)][idx(s)]+mat[idx(s)][idx(q)]+dp1[idx(q)][vecj-(s&(-s))]);
							}
						}
					}
				} else {
					for (int p = vec[i]; p; p -= (p&(-p))) {
						for (int q = vecj; q; q -= (q&(-q))) {
							min1 = min(min1, dp1[idx(p)][vec[i]]+mat[idx(p)][idx(q)]+dp2[idx(q)][vecj]);
							min2 = min(min2, dp2[idx(p)][vec[i]]+mat[idx(p)][idx(q)]+dp1[idx(q)][vecj]);
						}
					}
				}
				res = min(res,min1+min2);
			}
			printf("Case %d: %lld\n", cas++, res);
		}
	}
	return 0;
}