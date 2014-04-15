#include <bits/stdc++.h>
#define fr(a,b,c) for(int a = b; a < c; a++)
#define rp(a,b) fr(a,0,b)
#define inf 0x3f3f3f3f
#define pb push_back
#define mp make_pair
#define MAXN 110

using namespace std;

int Tower[MAXN][MAXN];
int size[MAXN];
int N, F, M, K;
int bi, fi, bj, fj, t;
int C[500][500];
map< pair<int,int>, int > s;

void fw() {
	rp(k,K) rp(i,K) rp(j,K) C[i][j] = min(C[i][j], C[i][k]+C[k][j]);
}

int main() {
	int T; scanf("%d", &T);
	while (T--) {
		scanf("%d%d%d", &N, &F, &M);
		memset(C,0x3f,sizeof C);
		memset(size,0,sizeof size);
		s.clear();
		rp(i,N) {
			C[i][i] = 0;
			C[i][(i+1)%N] = C[i][(i-1+N)%N] = 1;
			s[mp(i,0)] = i;
			Tower[i][size[i]++] = 0;
		}
		K = N;
		rp(i,M) {
			scanf("%d%d%d%d%d", &bi, &fi, &bj, &fj, &t);
			bi--, fi--, bj--, fj--;
			if (s.count(mp(bi,fi)) == 0) s[mp(bi,fi)] = K, K++;
			if (s.count(mp(bj,fj)) == 0) s[mp(bj,fj)] = K, K++;
			int a = s[mp(bi,fi)], b = s[mp(bj,fj)];
			C[a][a] = C[b][b] = 0;
			Tower[bi][size[bi]++] = fi;
			Tower[bj][size[bj]++] = fj;
			C[a][b] = C[b][a] = min(C[a][b], t);
		}
		rp(i,N) {
			sort(Tower[i], Tower[i]+size[i]);
			size[i] = unique(Tower[i], Tower[i]+size[i])-Tower[i];
			fr(j,1,size[i]) {
				int a = s[mp(i,Tower[i][j-1])], b = s[mp(i,Tower[i][j])];
				C[a][b] = C[b][a] = Tower[i][j] - Tower[i][j-1];
			}
		}
		fw();
		int Q;
		scanf("%d", &Q);
		while (Q--) {
			scanf("%d%d%d%d", &bi, &fi, &bj, &fj);
			bi--, fi--, bj--, fj--;
			
			int res = inf;
			if (bi == bj) res = min(res, abs(fi-fj));
			
			for (int i = 0; i < size[bi]; i++) {
				for (int j = 0; j < size[bj]; j++) {
					res = min(res, C[s[mp(bi,Tower[bi][i])]][s[mp(bj,Tower[bj][j])]] + abs(fi-Tower[bi][i]) + abs(fj-Tower[bj][j]));
				}
			}
			printf("%d\n", res);
		}
	}
	return 0;
}