#include <bits/stdc++.h>
using namespace std;
#define fr(a,b,c) for (int a = b; a < c; a++)
#define rp(a,b) fr(a,0,b)
#define F first
#define S second

double mat[310][310];

map<int, double> prob[1000];
map<int, double>::iterator ii, jj;

int to[1000], grau[1000], son[1000][2];
int fila[1000], start, end, aux, a1, b1;

const double EPS = 1e-8;

int main() {
	int N, a, b;
	while (scanf("%d", &N) == 1 && N > 0) {
		rp(i,N) rp(j,N) scanf("%lf", &mat[i+1][j+1]);
		for (int i = 1; i <= N; i++) {
			grau[N+i] = 0;
			prob[i].clear(); prob[N+i].clear();
			prob[i][i] = 1.0;
		}
		start = end = 0;
		fr(i,1,N) {
			scanf("%d%d", &a, &b);
			to[a] = to[b] = N+i;
			son[N+i][0] = a; son[N+i][1] = b;
			grau[N+i] = (a > N) + (b > N);
			if (grau[N+i] == 0) fila[end++] = N+i;
		}
		while (start != end) {
			aux = fila[start++];
			a1 = son[aux][0]; b1 = son[aux][1];
			if (prob[a1].count(1) > 0) {
				for (jj = prob[b1].begin(); jj != prob[b1].end(); jj++) {
					prob[aux][1] += prob[a1][1]*(*jj).S*mat[1][(*jj).F];
				}
			} else if (prob[b1].count(1) > 0) {
				for (jj = prob[a1].begin(); jj != prob[a1].end(); jj++) {
					prob[aux][1] += prob[b1][1]*(*jj).S*mat[1][(*jj).F];
				}
			} else {
				for (ii = prob[a1].begin(); ii != prob[a1].end(); ii++) {
					for (jj = prob[b1].begin(); jj != prob[b1].end(); jj++) {
						prob[aux][(*ii).F] += (*ii).S*(*jj).S*mat[(*ii).F][(*jj).F];
						prob[aux][(*jj).F] += (*ii).S*(*jj).S*mat[(*jj).F][(*ii).F];
					}
				}
			}
			grau[to[aux]]--;
			if (grau[to[aux]] == 0) fila[end++] = to[aux];
		}
		aux = fila[end-1];
		printf("%.6lf\n", prob[aux][1]);
	}
	return 0;
}