#include <bits/stdc++.h>
using namespace std;
#define fr(a,b,c) for(int a = b; a < c; a++)
#define rp(a,b) fr(a,0,b)

int L, C, g[400][400], k;
void trocaL(int i, int j) { rp(a,C) swap(g[i][a],g[j][a]); }
void trocaC(int i, int j) { rp(a,L) swap(g[a][i],g[a][j]); }

int main() {
	while (scanf("%d%d", &L, &C) == 2) {
		rp(i,L) rp(j,C) scanf("%d", &g[i][j]), g[i][j]--;
		int ans = 0;
		fr(i,0,L) {
			k = i;
			fr(j,i,L) if (g[j][0] <= g[k][0]) k = j;
			if (k != i) ans++, trocaL(i,k);
		}
		fr(i,0,C) {
			k = i;
			fr(j,i,C) if (g[0][j] <= g[0][k]) k = j;
			if (k != i) ans++, trocaC(i,k);
		}
		int cnt = 0;
		rp(i,L) rp(j,C) {
			if (g[i][j] != cnt) {
				cnt = -1;
				goto aff;
			} else cnt++;
		}
		aff:;
		if (cnt == -1) printf("*\n");
		else printf("%d\n", ans);
	}
}