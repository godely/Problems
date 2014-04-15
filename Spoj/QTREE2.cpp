#include <bits/stdc++.h>
using namespace std;
#define fr(a,b,c) for(int a = b; a < c; a++)
#define rp(a,b) fr(a,0,b)
#define MAXM 21111
#define add(a,b,c) to[z] = b, cost[z] = c, ant[z] = adj[a], adj[a] = z++
int to[MAXM], cost[MAXM], ant[MAXM], adj[MAXM], z;

int N, P[MAXM][16], D[MAXM][16], L[MAXM];
void dfset(int no) {
	for (int i = adj[no]; i != -1; i = ant[i]) {
		if (to[i] != P[no][0]) {
			P[to[i]][0] = no;
			D[to[i]][0] = cost[i];
			L[to[i]] = L[no]+1;
			dfset(to[i]);
		}
	}
}

int log2N;
void preprocess() {
	memset(P,-1,sizeof P);
	memset(D,0,sizeof D);
	L[1] = 0;
	dfset(1);
	
	for (log2N = 1; (1<<log2N) <= N; log2N++);
	log2N--;
	for (int i = 1; i <= log2N; i++)
		for (int j = 1; j <= N; j++)
			if (~P[j][i-1])
				P[j][i] = P[P[j][i-1]][i-1], D[j][i] = D[j][i-1] + D[P[j][i-1]][i-1];
}

int queryDist(int a, int b) {
	if (a == b) return 0;
	if (L[a] < L[b]) swap(a,b);
	
	int res = 0;
	for (int i = log2N; i >= 0; i--) {
		if (P[a][i] != -1 && L[P[a][i]] >= L[b]) res += D[a][i], a = P[a][i];
	}
	if (a == b) return res;
	for (int i = log2N; i >= 0; i--) {
		if (P[a][i] != -1 && P[a][i] != P[b][i]) res += D[a][i]+D[b][i], a = P[a][i], b = P[b][i];
	}
	res += D[a][0]+D[b][0];
	return res;
}

int queryKth(int a, int b, int k) {
	int oriA = a, oriB = b;
	int tamA = 1, tamB = 1;
	if (L[b] > L[a]) {
		for (int i = log2N; i >= 0; i--) {
			if (P[b][i] != -1 && L[P[b][i]] >= L[a]) tamB += (1<<i), b = P[b][i];
		}
	} else if (L[a] > L[b]) {
		for (int i = log2N; i >= 0; i--) {
			if (P[a][i] != -1 && L[P[a][i]] >= L[b]) tamA += (1<<i), a = P[a][i];
		}
	}
	
	for (int i = log2N; i >= 0; i--) {
		if (P[a][i] != -1 && P[a][i] != P[b][i]) tamA += (1<<i), tamB += (1<<i), a = P[a][i], b = P[b][i];
	}
	if (a != b) tamA++, tamB++;
	
	if (k <= tamA) {
		k--;
		for (int i = log2N; k && i >= 0; i--) {
			if (P[oriA][i] != -1 && k-(1<<i) >= 0) k-=(1<<i), oriA = P[oriA][i];
		}
		return oriA;
	} else {
		k = (tamA+tamB-1)-k;
		//printf("> %d\n", k);
		for (int i = log2N; i >= 0; i--) {
			//printf("<%d, ", oriB);
			if (P[oriB][i] != -1 && k-(1<<i) >= 0) k-=(1<<i), oriB = P[oriB][i];
			//printf("%d> (%d)\n", oriB, i);
		}
		return oriB;
	}
}

char str[100];
int main() {
	int T, a, b, c;
	scanf("%d", &T);
	while (T--) {
		memset(adj,-1,sizeof adj);
		z = 0;
		scanf("%d", &N);
		rp(i,N-1) {
			scanf("%d%d%d", &a, &b, &c);
			add(a,b,c);
			add(b,a,c);
		}
		preprocess();
		while (scanf("%s", str) == 1) {
			if (str[1] == 'O') break;
			else if (str[0] == 'D') {
				scanf("%d%d", &a, &b);
				printf("%d\n", queryDist(a,b));
			} else {
				scanf("%d%d%d", &a, &b, &c);
				printf("%d\n", queryKth(a,b,c));
			}
		}
		printf("\n");
	}
	
	return 0;
}