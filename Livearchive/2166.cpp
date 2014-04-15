#include <cstdio>
#include <cstdlib>
#include <iostream>
#include <algorithm>
#include <cmath>
#include <cstring>
#include <queue>
#include <bitset>
#include <vector>
#include <utility>
using namespace std;
#define fr(a,b,c) for(int a = b; a < c; a++)
#define rp(a,b) fr(a,0,b)
#define cl(a,b) memset(a,b,sizeof a)
#define F first
#define S second

int c[3], a[3], b[3], tot;


int x[3], z[3], C;
int fila[3000000];
int mark[160][160], passo;
int dij() {
	passo++;
	fila[0] = a[0];
	fila[1] = a[1];
	fila[2] = 0;
	for (int ini = 0, fim = 2; ini <= fim;) {
		x[0] = fila[ini++], x[1] = fila[ini++];
		x[2] = tot - x[0] - x[1], C = fila[ini++];
		if (x[0] == b[0] && x[1] == b[1] && x[2] == b[2]) return C;
		rp(i,3) rp(j,3) if (i != j) {
			z[i] = max(x[i] - c[j] + x[j], 0);
			z[j] = min(x[j] + x[i], c[j]);
			z[3-i-j] = x[3-i-j];
			if (mark[z[0]][z[1]] != passo) {
				mark[z[0]][z[1]] = passo;
				fila[++fim] = z[0];
				fila[++fim] = z[1];
				fila[++fim] = C+1;
			}
		}
	}
	return -1;
}

int main() {
	cl(mark,0); passo = 0;
	while (scanf("%d", &c[0]) && c[0]) {
		fr(i,1,3) scanf("%d", &c[i]);
		rp(i,3) scanf("%d", &a[i]);
		rp(i,3) scanf("%d", &b[i]);
		tot = a[0] + a[1] + a[2];
		printf("%d\n", dij());
	}
}