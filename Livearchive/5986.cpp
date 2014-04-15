#include <bits/stdc++.h>
#define fr(a,b,c) for(int a = b; a < c; a++)
#define rp(a,b) fr(a,0,b)
#define inf 0x3f3f3f3f
#define pb push_back
#define MAXN 110

using namespace std;

int TowerFloor[MAXN][MAXN];
int TowerInd[MAXN][MAXN];
int size[MAXN];
int K;

int main() {
	int T; scanf("%d", &T);
	while (T--) {
		scanf("%d%d%d", &N, &F, &M);
		memset(C,0x3f,sizeof C);
		memset(size,0,sizeof size);
		rp(i,N) C[i][(i+1)%N] = C[i][(i-1+N)%N] = 1;
		K = N;
		rp(i,M) {
			scanf("%d%d%d%d%d", &bi, &fi, &bj, &fj, &t);
			TowerFloor[bi][size[bi]] = fi;
			TowerInd[bi][size[bi]++] = K;
			TowerFloor[bj][size[bj]] = fj;
			TowerInd[bj][size[bj]++] = K+1;
			C[K][K+1] = C[K+1][K] = t;
			K+=2;
		}
	}
	return 0;
}