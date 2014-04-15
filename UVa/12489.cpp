#include <bits/stdc++.h>
using namespace std;
#define fr(a,b,c) for(int a = b; a < c; a++)
#define rp(a,b) fr(a,0,b)
#define MAXN 10100
#define ll long long
#define pb push_back
#define mp make_pair
#define F first
#define S second

#define base 27272701LL

int N;
vector<int> adj[2][MAXN];

int fila[MAXN][2], mark[MAXN], passo = 0, back[2][MAXN];

pair<int,int> findRoot(int a) {
	int ini = 0, fim = 1, aux, cost;
	passo++;
	mark[0] = passo;
	fila[0][0] = 1;
	fila[0][1] = 0;
	while (ini != fim) {
		cost = fila[ini][0];
		aux = fila[ini++][1];
		rp(i,adj[a][aux].size()) {
			if (mark[adj[a][aux][i]] != passo) {
				mark[adj[a][aux][i]] = passo;
				fila[fim][0] = cost+1;
				fila[fim++][1] = adj[a][aux][i];
			}
		}
	}

	passo++;
	mark[fila[fim-1][1]] = passo;
	fila[0][0] = 1;
	fila[0][1] = fila[fim-1][1];
	back[a][fila[fim-1][1]] = -1;
	ini = 0, fim = 1;
	while (ini != fim) {
		cost = fila[ini][0];
		aux = fila[ini++][1];
		rp(i,adj[a][aux].size()) {
			if (mark[adj[a][aux][i]] != passo) {
				mark[adj[a][aux][i]] = passo;
				back[a][adj[a][aux][i]] = aux;
				fila[fim][0] = cost+1;
				fila[fim++][1] = adj[a][aux][i];
			}
		}
	}
	
	int height = fila[fim-1][0];
	aux = fila[fim-1][1];
	for (int i = 0; i < ((height+1)>>1); i++, aux = back[a][aux]); 
	return mp(height, aux);
}

unsigned long long dp[MAXN], vet[MAXN];
void hash(int v, int from, int a) {
	bool leaf = 1;
	rp(i,adj[a][v].size()) {
		if (adj[a][v][i] != from) {
			leaf = 0;
			hash(adj[a][v][i], v, a);
		}
	}
	if (leaf) { dp[v] = 1; return; }
	else {
		int k = 0;
		rp(i,adj[a][v].size()) if (adj[a][v][i] != from) vet[k++] = dp[adj[a][v][i]];
		sort(vet, vet+k);
		unsigned long long myHash = 0;
		rp(i,k) myHash = (myHash + vet[i])*base;
		dp[v] = myHash;
	}
}

int main() {
	int a, b;
	pair<int,int> p1, p2;
	unsigned long long hash1_1, hash1_2, hash2_1, hash2_2;
	while (scanf("%d", &N) == 1) {
		rp(i,N) adj[0][i].clear(), adj[1][i].clear();
		rp(i,N-1) {
			scanf("%d%d", &a, &b);
			adj[0][a-1].pb(b-1);
			adj[0][b-1].pb(a-1);
		}
		rp(i,N-1) {
			scanf("%d%d", &a, &b);
			adj[1][a-1].pb(b-1);
			adj[1][b-1].pb(a-1);
		}
		p1 = findRoot(0);
		p2 = findRoot(1);
		if (p1.F != p2.F) printf("N\n");
		else {
			hash(back[0][p1.S],-1,0); hash1_1 = dp[back[0][p1.S]];
			hash(back[1][p2.S],-1,1); hash2_1 = dp[back[1][p2.S]];
			if (hash1_1 == hash2_1) printf("S\n");
			else {
				if ((p1.F)&1) printf("N\n");
				else {
					hash(p1.S,-1,0); hash1_2 = dp[p1.S];
					hash(p2.S,-1,0); hash2_2 = dp[p2.S];
					if (hash1_1 == hash2_2 || hash1_2 == hash2_1 || hash1_2 == hash2_2) printf("S\n");
					else printf("N\n");
				}
			}
		}
	}
	return 0;
}