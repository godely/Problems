#include <bits/stdc++.h>
using namespace std;
#define fr(a,b,c) for(int a = b; a < c; a++)
#define rp(a,b) fr(a,0,b)
#define MAXN 500000

#define add(a,b) ant[z] = adj[a], to[z] = b, adj[a] = z++
int ant[100], to[100], adj[100], z = 0;

int T, n, m, s, t;
int mask;
int auxMask, auxNo, auxCost;

int fila[MAXN][5], start, end;
int back[MAXN][5];
int calc[35536][17], passo = 0;

int main() {
	int a, b, cas = 1;
	scanf("%d", &T);
	while (T--) {
		memset(adj, -1, sizeof adj), z = 0; passo++;
		scanf("%d%d%d%d", &n, &m, &s, &t);
		s--, t--;
		mask = 0;
		rp(i,m) scanf("%d", &a), mask|=(1<<(a-1));
		mask|=(1<<s);
		fr(i,1,n) {
			scanf("%d%d", &a, &b);
			add(a-1,b-1);
			add(b-1,a-1);
		}
		start = end = 0;
		fila[end][0] = mask;
		fila[end][1] = s;
		fila[end++][2] = 0;
		calc[mask][s] = passo;
		back[0][2] = -1;
		printf("Case %d:", cas++);
		while (start < end) {
			auxMask = fila[start][0];
			auxNo = fila[start][1];
			auxCost = fila[start++][2];
			//printf("%d %d %d %d\n", start, auxMask, auxNo, auxCost);
			if (auxNo == t) {
				printf(" %d\n", auxCost);
				int k = start-1, b = 0;
				while (back[k][2] != -1) {
					fila[b][0] = back[k][0];
					fila[b++][1] = back[k][1];
					k = back[k][2];
				}
				for (int i = b-1; i >= 0; i--) printf("%d %d\n", fila[i][0], fila[i][1]);
				printf("\n");
				goto xD;
			} else {
				rp(i,n) {
					if (auxMask&(1<<i)) {
						for (int j = adj[i]; j != -1; j = ant[j]) {
							if ((auxMask&(1<<to[j])) == 0 && calc[(auxMask&(~(1<<i)))|(1<<to[j])][((i == auxNo) ? to[j] : auxNo)] != passo) {
								fila[end][0] = (auxMask&(~(1<<i)))|(1<<to[j]);
								fila[end][1] = ((i == auxNo) ? to[j] : auxNo);
								calc[fila[end][0]][fila[end][1]] = passo;
								fila[end][2] = auxCost + 1;
								back[end][0] = i+1;
								back[end][1] = to[j]+1;
								back[end][2] = start-1;
								end++;
							}
						}
					}
				}
			}
		}
		printf(" -1\n");
		xD:;
	}
	return 0;
}