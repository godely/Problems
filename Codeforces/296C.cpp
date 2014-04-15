#include <bits/stdc++.h>
using namespace std;
#define Fr(a,b,c) for (int a = b; a < c; a++)
#define Rp(a,b) Fr(a,0,b)
#define LSOne(x) (x&(-x))
typedef long long ull;
#define maxn 100100

ull bit[3][maxn+100];
void add(int x, ull a, int who) {
	for (int i = x; i < maxn; i+=LSOne(i)) bit[who][i] += a;
}

ull get(int x, int who) {
	ull ret = 0;
	for (int i = x; i > 0; i-=LSOne(i)) ret += bit[who][i];
	return ret;
}

int n, m, k;
int l[maxn], r[maxn], p, q;
ull in[maxn], d[maxn];
int main() {
	memset(bit, 0, sizeof bit);
	scanf("%d%d%d", &n, &m, &k);
	
	Rp(i,n) scanf("%lld", &in[i]);
	Rp(i,m) scanf("%d%d%lld", &l[i], &r[i], &d[i]);
	Rp(i,k) {
		scanf("%d%d", &p, &q);
		add(p,1,1);
		add(q+1,-1,1);
	}
	Rp(i,m) {
		ull qnt = get(i+1,1);
		add(l[i], qnt*d[i], 0);
		add(r[i]+1, -qnt*d[i], 0);
	}
	printf("%I64d", in[0]+get(1,0));
	Fr(i,1,n) printf(" %I64d", in[i]+get(i+1,0));
	printf("\n");
}