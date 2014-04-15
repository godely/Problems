#include <bits/stdc++.h>
#define fr(a,b,c) for(int a=b;a<c;a++)
#define rp(a,b) fr(a,0,b)
#define LL long long

using namespace std;

int ind[1111];
struct abc{
	int i, a;
	abc() {}
	abc(int i, int a):i(i), a(a) {}
} g[10001][1001];

int size[10001];

int main() {
	int m, n, r, a;
	while (scanf("%d%d", &m, &n) == 2) {
		memset(size, 0, sizeof size);
		rp(i,m) {
			scanf("%d", &r);
			rp(j,r) scanf("%d", &ind[j]), ind[j]--;
			rp(j,r) {
				scanf("%d", &a);
				g[ind[j]][size[ind[j]]++] = abc(i,a);
			}
		}
		printf("%d %d\n", n, m);
		rp(i,n) {
			r = size[i];
			printf("%d", r);
			rp(j,r) printf(" %d", g[i][j].i+1);
			printf("\n");
			if (r > 0) {
				printf("%d", g[i][0].a);
				fr(j,1,r) printf(" %d", g[i][j].a);
			}
			printf("\n");
		}
	}
	return 0;
}