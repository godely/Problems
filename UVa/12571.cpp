#include <cstdio>
#include <cstdlib>
#include <cmath>
#include <cstring>
#include <algorithm>
#define fr(a,b,c) for(int a = b; a < c; a++)
#define rp(a,b) fr(a,0,b)
using namespace std;

int pd[300];
int V[100100];

int main() {
	int T, N, Q, A;
	scanf("%d", &T);
	while (T--) {
		memset(pd, 0, sizeof pd);
		scanf("%d%d", &N, &Q);
		rp(i,N) {
			scanf("%d", &V[i]);
			rp(j,231) pd[j] = max(pd[j], j&V[i]);
		}
		rp(i,Q) scanf("%d", &A), printf("%d\n", pd[A]);
	}
	return 0;
}