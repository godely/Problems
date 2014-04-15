#include <cstdio>
#include <cstring>
#include <algorithm>
#include <iostream>
#include <cmath>
using namespace std;
#define inf 0x3f3f3f3f
#define fr(a,b,c) for(int a = b; a < c; a++)
#define rp(a,b) fr(a,0,b)

int g[20][20], h[20][20];
int N, res, D;

bool p(int i, int j) { return (((i > 0) && h[i-1][j]) + ((i < N-1) && h[i+1][j]) + ((j > 0) && h[i][j-1]) + ((j < N-1) && h[i][j+1]))&1; }

void bt(int ind) {
	if (ind >= N) {
		int c = D;
		//printf("%d %d %d\n", h[0][0], h[0][1], h[0][2]);
		for (int i = 1; i < N; i++) {
			for (int j = 0; j < N; j++) {
				h[i][j] = g[i][j];
				if (p(i-1,j)) {
					if (h[i][j]) return;
					h[i][j]=1, c++;
				}
			}
		}
		//if (c < res) printf("> %d %d!!!\n", D, c);
		res = min(res,c);
		return;
	}
	if (g[0][ind]) {
		bt(ind+1);
	} else {
		h[0][ind] = 0;
		bt(ind+1);
		h[0][ind] = 1;
		D++;
		bt(ind+1);
		D--;
	}
}

int main() {
	int T, cas=1;
	scanf("%d", &T);
	while (T--) {
		scanf("%d", &N);
		rp(i,N) rp(j,N) scanf("%d", &g[i][j]);
		rp(j,N) h[0][j] = g[0][j];
		res = inf;
		D = 0;
		bt(0);
		printf("Case %d: ", cas++);
		if (res==inf) printf("-1\n");
		else printf("%d\n", res);
	}
	return 0;
}