#include <bits/stdc++.h>
using namespace std;
#define fr(a,b,c) for(int a = b; a < c; a++)
#define rp(a,b) fr(a,0,b)
#define ii i[0]
#define jj j[0]
#define inf 0x01010101
#define inf2 0x2222

// /\ > \/ <
int di[] = {-1, 0, 1, 0};
int dj[] = {0, 1, 0, -1};
int d[5];
int n, m;
char g[32][32];
int mark[30][30], turn = 0;
int cost[30][30][5];
short costBfs[55][55][2];

struct P {
	int i[5], j[5];
	P() { ii = -1, jj = -1; }
	P(int _i, int _j) {
		memset(i,0,sizeof i);
		memset(j,0,sizeof j);
		ii = _i, jj = _j;
	}
	
	P operator+(const P &q) const {
		P ret;
		rp(k,4) ret.i[k] = i[k]+q.ii, ret.j[k] = j[k]+q.jj;
		return ret;
	}
	bool operator==(const P &q) const {
		return ii == q.ii && jj == q.jj;
	}
} X, p1, p2;

struct st {
	P x;
	int k, cost;
	st() {}
	st(P _x, int k = 0, int cost = 0) : k(k), cost(cost) {
		rp(t,4) x.i[t] = _x.i[t], x.j[t] = _x.j[t];
	}
	
	bool operator<(const st &lhs) const {
		return cost > lhs.cost;
	}
} aux, aux2;

bool pode(int i, int j, int k = -1) {
	if (k == -1) return i >= 0 && i < n && j >= 0 && j < m;
	return i >= 0 && i < n && j >= 0 && j < m && g[i][j] != '*' && g[i+di[(k+2)&3]][j+dj[(k+2)&3]] != '*';
}

bool pode2(int i, int j, P block) {
	bool ret = (i >= 0 && i < n && j >= 0 && j < m && g[i][j] != '*');
	if (!ret) return 0;
	rp(k,4) if (i == block.i[k] && j == block.j[k]) return 0;
	return 1;
}

void bfs(P block, P init, int p = 0, int s = 0) {
	turn++;
	queue<st> fila;
	fila.push(st(init));
	mark[init.ii][init.jj] = turn;
	costBfs[init.ii][init.jj][p] = 0;
	int t = 0;
	while (!fila.empty()) {
		t++;
		if (s == 1 && t > 700 ) break;
		aux2 = fila.front(); fila.pop();
		rp(k,4) {
			if (pode2(aux2.x.ii+di[k], aux2.x.jj+dj[k], block) && mark[aux2.x.ii+di[k]][aux2.x.jj+dj[k]] != turn) {
				mark[aux2.x.ii+di[k]][aux2.x.jj+dj[k]] = turn;
				costBfs[aux2.x.ii+di[k]][aux2.x.jj+dj[k]][p] = aux2.cost+1;
				fila.push(st(P(aux2.x.ii+di[k], aux2.x.jj+dj[k]), 0, aux2.cost+1));
			}
		}
	}
}

priority_queue<st> heap;
int dijkstra() {
	while (!heap.empty()) {
		aux = heap.top(); heap.pop();
		if (aux.cost > cost[aux.x.ii][aux.x.jj][aux.k]) continue;
		if (aux.x.ii == 0 && aux.x.jj == 0) return aux.cost;
		
		P tP1 = P(aux.x.i[aux.k]+di[aux.k], aux.x.j[aux.k]+dj[aux.k]);
		P tP2 = P(aux.x.i[aux.k]+di[aux.k]+di[(aux.k+1)&3], aux.x.j[aux.k]+dj[aux.k]+dj[(aux.k+1)&3]);
		memset(costBfs, 0x22, sizeof costBfs);
		bfs(aux.x, tP1, 0, 1);
		bfs(aux.x, tP2, 1, 1);
		rp(k,4) if (k != aux.k && pode(aux.x.i[k]+di[k], aux.x.j[k]+dj[k], k)) {
			int d1 = costBfs[aux.x.i[k]+di[k]][aux.x.j[k]+dj[k]][0] + costBfs[aux.x.i[k]+di[k]+di[(k+1)&3]][aux.x.j[k]+dj[k]+dj[(k+1)&3]][1];
			d1 = (d1 >= inf2) ? inf : d1;
			int d2 = costBfs[aux.x.i[k]+di[k]][aux.x.j[k]+dj[k]][1] + costBfs[aux.x.i[k]+di[k]+di[(k+1)&3]][aux.x.j[k]+dj[k]+dj[(k+1)&3]][0];
			d2 = (d2 >= inf2) ? inf : d2;
			
			P tX = (aux.x+P(di[k], dj[k]));
			if (aux.cost+min(d1,d2)+1 < cost[tX.ii][tX.jj][(k+2)&3]) {
				heap.push(st(tX, (k+2)&3, aux.cost+min(d1,d2)+1));
				cost[tX.ii][tX.jj][(k+2)&3] = aux.cost+min(d1,d2)+1;
			}
		}
		//printf("\n");
	}
	return inf;
}

int main() {
	while (scanf("%d%d", &n, &m) == 2 && (n+m) > 0) {
		int found = 0;
		p1.ii = -1;
		X.ii = -1;
		for (int i = 0; i < n; i++) {
			scanf("%s", g[i]);
			for (int j = 0; found < 3 && j < m; j++) {
				if (X.ii == -1 && g[i][j] == 'X') {
					X = P(i,j);
					found++;
				} else if (g[i][j] == '.') {
					if (p1.ii == -1) p1 = P(i,j);
					else p2 = P(i,j);
					found++;
				}
			}
		}
		X.i[1] = X.i[0], X.j[1] = X.j[0]+1;
		X.i[2] = X.i[0]+1, X.j[2] = X.j[0]+1;
		X.i[3] = X.i[0]+1, X.j[3] = X.j[0];
		if (g[0][0] == 'X') printf("0\n");
		else {
			int RES = inf;
			memset(costBfs, 0x22, sizeof costBfs);
			bfs(X, p1, 0);
			bfs(X, p2, 1);
			rp(k,4) if (pode(X.i[k]+di[k], X.j[k]+dj[k], k)) {
				int d1 = costBfs[X.i[k]+di[k]][X.j[k]+dj[k]][0] + costBfs[X.i[k]+di[k]+di[(k+1)&3]][X.j[k]+dj[k]+dj[(k+1)&3]][1];
				int d2 = costBfs[X.i[k]+di[k]][X.j[k]+dj[k]][1] + costBfs[X.i[k]+di[k]+di[(k+1)&3]][X.j[k]+dj[k]+dj[(k+1)&3]][0];
				d[k] = min(d1, d2);
				d[k] = (d[k] >= inf2) ? inf : d[k];
			}
			while (!heap.empty()) heap.pop();
			memset(cost,0x01,sizeof cost);
			rp(k,4) if (pode(X.i[k]+di[k], X.j[k]+dj[k], k)) {
				heap.push(st(X,k,d[k]));
				cost[X.ii][X.jj][k] = d[k];
				heap.push(st(X+P(di[k], dj[k]), (k+2)&3, d[k]+1));
				cost[(X+P(di[k], dj[k])).ii][(X+P(di[k], dj[k])).jj][k] = d[k]+1;
			}
			RES = dijkstra();
			if (RES < inf) printf("%d\n", RES);
			else printf("-1\n");
		}
	}
	return 0;
}