#include <bits/stdc++.h>
using namespace std;
#define fr(a,b,c) for(int a = b; a < c; a++)
#define rp(a,b) fr(a,0,b)
#define inf 0x3f3f3f3f
#define MAXN 200010

struct seg {
	int id;
	double x;
	bool end;
	seg() {}
	seg(int id, double x, bool end = 0) : id(id), x(x), end(end) {}

	bool operator<(const seg &lhs) const {
		if (x != lhs.x) return x < lhs.x;
		return end < lhs.end;
	}
} S[MAXN];
int k;

int mark[MAXN], passo = 0;

int main() {
	int L, D, N, x, y, count;
	while (scanf("%d", &L) == 1) {
		scanf("%d%d", &D, &N);
		k = 0;
		rp(i,N) {
			scanf("%d%d", &x, &y);
			S[k++] = seg(i, (double)x - sqrt(D*D - y*y));
			S[k++] = seg(i, (double)x + sqrt(D*D - y*y), 1);
		}
		sort(S, S+k);
		
		passo++;
		count = 0;
		rp(i,k) {
			//printf("%lf %d %d\n", S[i].x, S[i].id, S[i].end);
			if (S[i].end && mark[S[i].id] == passo) count++, passo++;
			else mark[S[i].id] = passo;
		}
		printf("%d%c", count, 10);
	}
	return 0;
}