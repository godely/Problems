#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <iostream>
#include <algorithm>
#include <cmath>
#include <vector>
using namespace std;
#define fr(a,b,c) for(int a = b; a < c; a++)
#define rp(a,b) fr(a,0,b)
#define MAXN 100100

int first[MAXN], last[MAXN], gp[MAXN], mark[MAXN], mark2[MAXN];
int dp[MAXN][20], g;

void rmq_preprocess() {
	for (int i = 1; 1 << i <= g; i++) {
		for (int j = 0; j + (1 << i) <= g; j++) {
			dp[j][i] = max(dp[j][i-1], dp[j+(1<<(i-1))][i-1]);
		}
	}
}

int _log2(int a) {
	int k = 1;
	for (; (1<<k) <= a; k++);
	return k-1;
}

int rmq_query(int a, int b) {
	int k = _log2(b-a+1);
	return max(dp[a][k], dp[b-(1<<k)+1][k]);
}

struct planet {
	int v, r;
	planet() {}
	planet(int v):v(v) {}
	bool operator<(const planet &lhs) const {
		return v < lhs.v;
	}
} p[MAXN];

int vec[MAXN];
struct segtree {
	int size;
	vector<int> V[MAXN*20];
	segtree() {}
	
	void construct(int R, int i, int j) {
		if (i == j) V[R] = vector<int>(vec+i, vec+i+1);
		else {
			construct(2*R, i, (i+j)/2);
			construct(2*R+1, (i+j)/2+1, j);
			V[R] = vector<int>(vec+i,vec+j+1);
			sort(V[R].begin(), V[R].end());
		}
	}
	
	int query(int R, int i, int j, int a, int b) {
		if (i > b || j < a) return 0;
		else if (i >= a && j <= b) return lower_bound(V[R].begin(), V[R].end(), a) - V[R].begin();
		else return query(2*R, i, (i+j)/2, a, b) + query(2*R+1, (i+j)/2+1, j, a, b);
	}
} ST;

int main() {
	int n, s, d, m;
	int t, a, b, left, right, res;
	scanf("%d%d%d", &n, &s, &d);
	rp(i,n) scanf("%d%d", &p[i].v, &p[i].r);
	sort(p, p+n);
	p[n].v = 100000000; t = 0; g = 1;
	first[0] = 1;
	rp(i,n) {
		if (mark[p[i].r] != g) mark[p[i].r] = g, t++, vec[i+1] = 0;
		else vec[i+1] = mark2[p[i].r];
		mark2[p[i].r] = i+1;
		gp[i] = g-1;
		if (p[i].v+d < p[i+1].v) {
			last[g-1] = i+1;
			first[g] = i+2;
			dp[g-1][0] = t;
			t = 0;
			g++;
		}
	}
	ST.construct(1,1,n);
	rmq_preprocess();
	scanf("%d", &m);
	rp(i,m) {
		scanf("%d%d", &a, &b);
		left = lower_bound(p, p+n, planet(a)) - p;
		right = upper_bound(p, p+n, planet(b)) - p - 1;
		if (a > b || left > right) {
			printf("0\n");
			continue;
		}
		res = 0;
		bool c = (gp[left]==gp[right]);
		int indLeft = left+1, indRight = right+1;
		if (left > 0 && gp[left-1] == gp[left]) {
			res = ST.query(1,1,n,indLeft,c?indRight:last[gp[left]]);
			left = gp[left]+1;
		} else left = gp[left];
		if (right < n-1 && gp[right+1] == gp[right]) {
			res = max(res, ST.query(1,1,n,c?indLeft:first[gp[right]],indRight));
			right = gp[right]-1;
		} else right = gp[right];
		if (left <= right) res = max(res, rmq_query(left, right));
		printf("%d\n", res);
	}
}