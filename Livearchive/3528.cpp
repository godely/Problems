#include <bits/stdc++.h>
using namespace std;
#define fr(a,b,c) for(int a = b; a < c; a++)
#define rp(a,b) fr(a,0,b)
typedef long long ll;
typedef unsigned long long ull;
#define BASE 11ULL
#define maxs 1000100


int n, si, sj, ei, ej;
char g[8][9];

ull getghash(int i, int j) {
	ull ret = (i+1)*BASE + (j+1);
	rp(i_,n) rp(j_,n) ret *= BASE, ret += g[i_][j_];
	return ret;
}

struct st {
	char m[8][9];
	int i, j, cost;
	
	st() {}
	st(int i, int j, int cost) : i(i), j(j), cost(cost) {
		rp(i_,n) rp(j_,n) m[i_][j_] = g[i_][j_];
	}
} aux;

int ini, fim;
st fila[maxs];
set<ull> s;
ull temphash;

int di[] = {1,0,-1,0};
int dj[] = {0,1,0,-1};

bool valid(int i, int j) { return i >= 0 && i < n && j >= 0 && j < n; }

//trash
int tempsz, ii, jj, cost;

void print() {
	rp(i,n) {
		rp(j,n) printf("%d ", g[i][j]);
		puts("");
	}
	puts("");
}

int bfs() {
	s.clear();
	ini = fim = 0;
	aux = st(si,sj,0);
	fila[fim++] = aux;
	s.insert(getghash(si,sj));
	bool first = 1;
	while (ini < fim) {
		aux = fila[ini++];
		ii = aux.i, jj = aux.j, cost = aux.cost;
		if (ii == ei && jj == ej) return cost;
		
		rp(i,n) rp(j,n) g[i][j] = aux.m[i][j];
		//print();
		rp(k,4) {
			if (valid(ii+di[k],jj+dj[k]) && g[ii+di[k]][jj+dj[k]] > 0) {
				temphash = getghash(ii+di[k],jj+dj[k]);
				if (!s.count(temphash)) {
					s.insert(temphash);
					fila[fim++] = st(ii+di[k],jj+dj[k],cost+1);
				}
			}
		}

		tempsz = g[ii][jj];
		if (tempsz > 1) {
			tempsz++;
			rp(k,4) {
				fr(l,1,tempsz) if (!valid(ii+di[k]*l, jj+dj[k]*l) || g[ii+di[k]*l][jj+dj[k]*l] > 0) goto cant;
				fr(l,1,tempsz) g[ii+di[k]*l][jj+dj[k]*l] = 1;
				g[ii][jj] = 0;
				temphash = getghash(ii+di[k],jj+dj[k]);
				if (!s.count(temphash)) {
					s.insert(temphash);
					fila[fim++] = st(ii+di[k],jj+dj[k],cost+1);
				}
				fr(l,1,tempsz) g[ii+di[k]*l][jj+dj[k]*l] = 0;
				g[ii][jj] = tempsz-1;
				cant:;
			}
		}
		first = 0;
	}
	return -1;
}

char gb[12];
int main() {
	while (scanf("%d%d%d", &n, &si, &sj) == 3 && n > 0) {
		si--, sj--;
		memset(g,0,sizeof g);
		rp(i,n) {
			scanf("%s", gb);
			rp(j,n) {
				if (gb[j] == 'E') {
					gb[j] = '1';
					ei = i, ej = j;
				}
				if (gb[j] != '.') g[i][j] = (gb[j]-'0');
			}
		}
		int ret = bfs();
		if (~ret) printf("%d\n", ret);
		else printf("Impossible.\n");
	}
	return 0;
}