#include <bits/stdc++.h>
using namespace std;
#define fr(a,b,c) for(int a = b; a < c; a++)
#define rp(a,b) fr(a,0,b)
#define inf 0x3f3f3f3f

int cmp(int a, int b, bool t) {
	if (t) return max(a,b);
	else return min(a,b);
}

int vet[510];
struct SegTree {
	int V[9100][2]; //0 = menor, 1 = maior
	
	SegTree() {}
	
	void build(int R, int l, int r) {
		if (l == r) V[R][0] = V[R][1] = vet[l];
		else {
			int m = (l+r)/2;
			build(2*R,l,m);
			build(2*R+1,m+1,r);
			V[R][0] = min(V[2*R][0], V[2*R+1][0]);
			V[R][1] = max(V[2*R][1], V[2*R+1][1]);
		}
	}
	
	void update(int R, int l, int r, int x, int val) {
		if (l == r) V[R][0] = V[R][1] = val;
		else {
			int m = (l+r)/2;
			if (x <= m) update(2*R,l,m,x,val);
			else update(2*R+1,m+1,r,x,val);
			V[R][0] = min(V[2*R][0], V[2*R+1][0]);
			V[R][1] = max(V[2*R][1], V[2*R+1][1]);
		}
	}
	
	int query(int R, int l, int r, int a, int b, bool maior) {
		if (r < a || l > b) return ((maior) ? -inf : inf);
		else if (l >= a && r <= b) return V[R][maior];
		else return cmp(query(2*R,l,(l+r)/2,a,b,maior), query(2*R+1,(l+r)/2+1,r,a,b,maior), maior);
	}
} S[510];

char str[5];
int main() {
	int N, Q;
	int a, l, b, r, M, m;
	scanf("%d%*d", &N);
	rp(i,N) {
		rp(j,N) {
			scanf("%d", &vet[j+1]);
		}
		S[i+1].build(1,1,N);
	}
	scanf("%d", &Q);
	rp(i,Q) {
		scanf("%s", str);
		if (str[0] == 'q') {
			M = -inf, m = inf;
			scanf("%d%d%d%d", &a, &l, &b, &r);
			fr(i,a,b+1) M = max(M, S[i].query(1,1,N,l,r,1)), m = min(m, S[i].query(1,1,N,l,r,0));
			printf("%d %d\n", M, m);
		} else {
			scanf("%d%d%d", &a, &b, &l);
			S[a].update(1,1,N,b,l);
		}
	}
	return 0;
}