#include <bits/stdc++.h>
#define fr(a,b,c) for(int a=b;a<c;a++)
#define rp(a,b) fr(a,0,b)
#define LL long long
#define LSOne(x) (x&(-x))
#define MAXN 1000010

using namespace std;

int ft[MAXN], ft_size;
int getVal(int x) {
	int val = 0;
	for (; x > 0; x-=LSOne(x)) val+=ft[x];
	return val;
}

int getInterval(int a, int b) {
	return getVal(b) - getVal(a-1);
}

void setVal(int x, int val) {
	//printf("%d %d\n", x, val);
	for (; x <= MAXN; x += LSOne(x)) ft[x] += val;
}

int main() {
	int n, m, a, b, c, d;
	bool ok;
	while (scanf("%d%d", &n, &m) == 2 && (n || m)) {
		memset(ft, 0, sizeof ft);
		ok = 1;
		rp(i,n) {
			scanf("%d%d", &a, &b);
			a++, b++;
			if (ok) {
				if (getInterval(a, b-1) > 0) ok = 0;
				else fr(j,a,b) setVal(j, 1);
			}
		}
		rp(i,m) {
			scanf("%d%d%d", &a, &b, &c);
			a++, b++;
			if (ok) {
				for (int j = a; j <= MAXN && ok; j += c) {
					d = min(j+(b-a), MAXN);
					if (getInterval(j, d-1) > 0) ok = 0;
					else fr(k,j,d) setVal(k, 1);
				}
			}
		}
		if (ok) printf("NO CONFLICT\n");
		else printf("CONFLICT\n");
	}
	return 0;
}