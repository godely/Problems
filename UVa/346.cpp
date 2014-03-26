#include <cstdio>
#include <algorithm>
#include <cstring>
#include <utility>
#include <vector>
#include <queue>
#include <stack>
#include <map>
#include <string>
#include <set>
#include <cmath>
#include <iostream>
#include <ctime>
#include <cassert>
#define fr(a,b,c) for(int a = b; a < c; a++)
#define rp(a,b) fr(a,0,b)
#define CL(a,b) memset(a,b,sizeof a)
#define oo 0x3f3f3f3f

#define MAXN 111

using namespace std;

char P[MAXN], T[MAXN], V[MAXN];
int p, t, v;
int dp[MAXN][MAXN][MAXN], to[MAXN][MAXN][MAXN];
int f[MAXN];

void prekmp() {
	int i = 0, j = -1;
	f[i] = -1;
	while (i<v) {
		while (j >= 0 && V[i] != V[j]) j = f[j];
		f[++i] = ++j;
	}
}

int go(int i, int j, int k) {
	int &pd = dp[i][j][k];
	int &para = to[i][j][k];
	if (~pd) return pd;
	if (k == v) return pd = -oo;
	else if (i == p || j == t) return pd = 0;

	pd = 0;
	int l = go(i+1,j,k);
	int r = go(i,j+1,k);
	if (max(l,r) > pd) {
		if (l > r) {
			para = 0;
			pd = l;
		} else {
			para = 1;
			pd = r;
		}
	}
	int ll = -1, rr = -1;
	if (P[i] == T[j]) {
		if (P[i] == V[k]) {
			ll = 1+go(i+1,j+1,k+1);
			if (ll > pd) {
				pd = ll;
				para = 2;
			}
		} else {
			int _k = k;
			while (_k >= 0 && P[i] != V[_k]) _k = f[_k];
			rr = 1+go(i+1,j+1,_k+1);
			if (rr > pd) {
				pd = rr;
				para = 3+_k+1;
			}
		}
	}
	return pd;
}

int main() {
	scanf("%s%s%s", P, T, V);
	p = strlen(P);
	t = strlen(T);
	v = strlen(V);
	prekmp();
	CL(dp,-1);
	CL(to,-1);
	if (!go(0,0,0)) printf("0\n");
	else {
		int a = 0, b = 0, c = 0;
		while (~to[a][b][c]) {
			if (to[a][b][c] == 0) a++;
			else if (to[a][b][c] == 1) b++;
			else if (to[a][b][c] == 2) printf("%c", P[a]), a++, b++, c++;
			else printf("%c", P[a]), c = to[a][b][c]-3, a++, b++;
		}
		puts("");
	}
}
