#include <bits/stdc++.h>
using namespace std;
#define fr(a,b,c) for(int a = b; a < c; a++)
#define rp(a,b) fr(a,0,b)
#define ii i[0]
#define jj j[0]
#define inf 0x3f3f3f3f

// /\ > \/ <
int di[] = {-1, 0, 1, 0};
int dj[] = {0, 1, 0, -1};
int n, m;
char g[55][55];
int mark[55][55], turn = 0;
int cost[55][55][5];

struct P {
	int i[5], j[5];
	P() {}
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
	return i >= 0 && i < n && j >= 0 && j < m && g[i][j] != '*' && g[i+di[(k+2)%4]][j+dj[(k+2)%4]] != '*';
}

bool pode2(int i, int j, P block) {
	bool ret = (i >= 0 && i < n && j >= 0 && j < m && g[i][j] != '*');
	if (!ret) return 0;
	rp(k,4) if (i == block.i[k] && j == block.j[k]) return 0;
	return 1;
}

int bfs(P block, P init, P fim) {
	//printf("\n%d %d\n%d %d\n", init.ii, init.jj, fim.ii, fim.jj);
	//rp(i,4) printf("> %d %d\n", block.i[i], block.j[i]);
	turn++;
	queue<st> fila;
	fila.push(st(init));
	mark[init.ii][init.jj] = turn;
	while (!fila.empty()) {
		aux2 = fila.front(); fila.pop();
		if (aux2.x == fim) return aux2.cost;
		rp(k,4) {
			if (pode2(aux2.x.ii+di[k], aux2.x.jj+dj[k], block) && mark[aux2.x.ii+di[k]][aux2.x.jj+dj[k]] != turn) {
				mark[aux2.x.ii+di[k]][aux2.x.jj+dj[k]] = turn;
				fila.push(st(P(aux2.x.ii+di[k], aux2.x.jj+dj[k]), 0, aux2.cost+1));
			}
		}
	}
	return inf;
}

int dijkstra(P init, int kInit) {
	//rp(k,4) printf("(%d %d) ", init.i[k], init.j[k]);
	//printf("\n");
	priority_queue<st> fila;
	fila.push(st(init,kInit));
	memset(cost,0x3f,sizeof cost);
	cost[init.ii][init.jj][kInit] = 0;
	while (!fila.empty()) {
		aux = fila.top(); fila.pop();
		if (aux.cost > cost[aux.x.ii][aux.x.jj][aux.k]) continue;
		if (aux.x.ii == 0 && aux.x.jj == 0) return aux.cost;
		//printf(">\n");
		//printf("%d %d, %d %d\n", aux.x.ii, aux.x.jj, aux.k, aux.cost);
		//printf("coisas:\n");
		//rp(k,4) printf("(%d %d) ", aux.x.i[k], aux.x.j[k]);
		//printf("... %d %d\n", aux.k, aux.cost);
		//printf("\n");
		
		P tP1 = P(aux.x.i[aux.k]+di[aux.k], aux.x.j[aux.k]+dj[aux.k]);
		P tP2 = P(aux.x.i[aux.k]+di[aux.k]+di[(aux.k+1)%4], aux.x.j[aux.k]+dj[aux.k]+dj[(aux.k+1)%4]);
		//printf("tP1: %d %d, tP2: %d %d\n", tP1.ii, tP1.jj, tP2.ii, tP2.jj);
		rp(k,4) if (k != aux.k && pode(aux.x.i[k]+di[k], aux.x.j[k]+dj[k], k)) {
			int d1 = bfs(aux.x, tP1, P(aux.x.i[k]+di[k], aux.x.j[k]+dj[k])) + bfs(aux.x, tP2, P(aux.x.i[k]+di[k]+di[(k+1)%4], aux.x.j[k]+dj[k]+dj[(k+1)%4]));
			int d2 = bfs(aux.x, tP2, P(aux.x.i[k]+di[k], aux.x.j[k]+dj[k])) + bfs(aux.x, tP1, P(aux.x.i[k]+di[k]+di[(k+1)%4], aux.x.j[k]+dj[k]+dj[(k+1)%4]));
			//printf("d1: %d, d2: %d\n", d1, d2);
			
			P tX = (aux.x+P(di[k], dj[k]));
			if (aux.cost+min(d1,d2)+1 < cost[tX.ii][tX.jj][(k+2)%4]) {
				/*printf("	Indo para ");
				rp(t,4) printf(" (%d %d)", tX.i[t], tX.j[t]);
				printf("\n");*/
				fila.push(st(tX, (k+2)%4, aux.cost+min(d1,d2)+1));
				cost[tX.ii][tX.jj][(k+2)%4] = aux.cost+min(d1,d2)+1;
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
			rp(k,4) if (pode(X.i[k]+di[k], X.j[k]+dj[k], k)) {
				int d1 = bfs(X, p1, P(X.i[k]+di[k], X.j[k]+dj[k])) + bfs(X, p2, P(X.i[k]+di[k]+di[(k+1)%4], X.j[k]+dj[k]+dj[(k+1)%4]));
				int d2 = bfs(X, p2, P(X.i[k]+di[k], X.j[k]+dj[k])) + bfs(X, p1, P(X.i[k]+di[k]+di[(k+1)%4], X.j[k]+dj[k]+dj[(k+1)%4]));
				//printf("%d %d, %d %d\n", p1.ii, p1.jj, P(X.i[k]+di[k], X.j[k]+dj[k]).ii, P(X.i[k]+di[k], X.j[k]+dj[k]).jj);
				int c1 = dijkstra(X, k);
				int c2 = dijkstra(X+P(di[k], dj[k]), (k+2)%4) + 1;
				//printf("%d %d\n", d1, d2);
				RES = min(RES, min(c1, c2) + min(d1, d2));
			}
			if (RES < inf) printf("%d\n", RES);
			else printf("-1\n");
		}
	}
	return 0;
}