#include <bits/stdc++.h>
using namespace std;
#define fr(a,b,c) for(int a = b; a < c; a++)
#define rp(a,b) fr(a,0,b)
typedef long long ll;
#define X(a) ((a)<<1)
#define Y(a) (((a)<<1)+1)
#define inf 0x3f3f3f3f

int N, g[511][511];
int seg[511][10110][2];
void build(int ind, int R, int i, int j) {
	if (i == j) seg[ind][R][0] = seg[ind][R][1] = g[ind][i-1];
	else {
		int m = (i+j)>>1;
		build(ind, X(R), i, m);
		build(ind, Y(R), m+1, j);
		seg[ind][R][0] = max(seg[ind][X(R)][0], seg[ind][Y(R)][0]);
		seg[ind][R][1] = min(seg[ind][X(R)][1], seg[ind][Y(R)][1]);
	}
}

int query(int ind, int R, int i, int j, int a, int b, int type) {
	if (b < i || a > j) return (type == 0) ? -1 : inf;
	if (a <= i && b >= j) return seg[ind][R][type];
	
	int m = (i+j)>>1;
	if (type == 0) return max(query(ind, X(R), i, m, a, b, type), query(ind, Y(R), m+1, j, a, b, type));
	else return min(query(ind, X(R), i, m, a, b, type), query(ind, Y(R), m+1, j, a, b, type));
}

void update(int ind, int R, int i, int j, int x, int v) {
	if (i == j) seg[ind][R][0] = seg[ind][R][1] = v;
	else {
		int m = (i+j)>>1;
		if (x <= m) update(ind, X(R), i, m, x, v);
		else update(ind, Y(R), m+1, j, x, v);
		seg[ind][R][0] = max(seg[ind][X(R)][0], seg[ind][Y(R)][0]);
		seg[ind][R][1] = min(seg[ind][X(R)][1], seg[ind][Y(R)][1]);
	}
}

char cmd[10];
int i1, J1, i2, j2, val;
int main() {
	scanf("%d%*d", &N);
	rp(i,N) rp(j,N) scanf("%d", &g[i][j]);
	rp(i,N) build(i,1,1,N);
	int Q; scanf("%d", &Q);
	while (Q--) {
		scanf("%s", cmd);
		if (cmd[0] == 'q') {
			scanf("%d%d%d%d", &i1, &J1, &i2, &j2);
			int res1 = -1, res2 = inf;
			fr(i,i1-1,i2) res1 = max(res1, query(i,1,1,N,J1,j2,0)), res2 = min(res2, query(i,1,1,N,J1,j2,1));
			printf("%d %d\n", res1, res2);
		} else {
			scanf("%d%d%d", &i1, &J1, &val);
			update(i1-1,1,1,N,J1,val);
		}
	}
	return 0;
}