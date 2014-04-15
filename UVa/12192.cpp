#include <bits/stdc++.h>
using namespace std;
#define fr(a,b,c) for(int a = b; a < c; a++)
#define rp(a,b) fr(a,0,b)
#define MAXN 511
#define LL long long
#define pb push_back
#define inf 0x3f3f3f3f

int p2[] = {1, 2, 4, 8, 16, 32, 64, 128, 256};

int N, M, G[MAXN][MAXN], D[2*MAXN][MAXN], size[2*MAXN], k;

int main() {
	int a, b, ans, up, down;
	while (scanf("%d%d", &N, &M) == 2 && N > 0) {
		memset(size, 0, sizeof size);
		rp(i,N) rp(j,M) scanf("%d", &G[i][j]);
		k = 0;
		for (int j = M-1; j >= 0; j--) {
			for (int i = 0; i < min(M-j,N); i++) {
				D[k][size[k]++] = G[i][j+i];
			}
			k++;
		}
		for (int i = 1; i < N; i++) {
			for (int j = 0; j < min(N-i,M); j++) {
				D[k][size[k]++] = G[i+j][j];
			}
			k++;
		}
		/*rp(i,k) {
			rp(j,size[i]) printf("%d ", D[i][j]);
			printf("\n");
		}*/
		int Q; scanf("%d", &Q);
		while (Q--) {
			scanf("%d%d", &a, &b);
			ans = 0;
			rp(i,k) {
				//up = -1;
				//for (int j = 8; j >= 0; j--) if (up+p2[j] < size[i] && D[i][up+p2[j]] < a) up += p2[j];
				//down = up;
				//for (int j = 8; j >= 0; j--) if (down+p2[j] < size[i] && D[i][down+p2[j]] <= b) down += p2[j];
				//printf("%d %d %d\n", i, up, down);
				up = lower_bound(D[i], D[i]+size[i], a) - D[i];
				down = upper_bound(D[i], D[i]+size[i], b) - D[i];
				ans = max(ans, down-up);
			}
			printf("%d%c", ans, 10);
		}
		printf("-%c", 10);
	}
	return 0;
}