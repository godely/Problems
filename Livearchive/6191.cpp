#include <bits/stdc++.h>
using namespace std;
#define fr(a,b,c) for(int a = b; a < c; a++)
#define rp(a,b) fr(a,0,b)
#define H(a,b,c) ((((a*5)+b)*5)+c)
#define pb push_back
#define inf 1000000000.0
#define MAXP 216

int xi, yi, zi, xj, yj, zj;
int g[5][5][5];
double cost[MAXP];

struct tup {
	int i, j, k;
	double cost;
	tup() {}
	tup(int i, int j, int k, double cost = 0.0) : i(i), j(j), k(k), cost(cost) {}

	bool operator<(const tup &lhs) const {
		return cost > lhs.cost;
	}
} aux;
vector<tup> to[6*6*6];
priority_queue<tup> heap;

double dist(int a, int b, int c, int d, int e, int f) { return sqrt((d-a)*(d-a) + (e-b)*(e-b) + (f-c)*(f-c)); }

bool podeLinha(int i1, int j1, int k1, int t) {
	int p;
	if (t == 0) p = g[i1][j1-1][k1-1] + g[i1][j1-1][k1] + g[i1][j1][k1-1] + g[i1][j1][k1];
	else if (t == 1) p = g[i1-1][j1][k1-1] + g[i1-1][j1][k1] + g[i1][j1][k1-1] + g[i1][j1][k1];
	else p = g[i1-1][j1-1][k1] + g[i1-1][j1][k1] + g[i1][j1-1][k1] + g[i1][j1][k1];
	return p > 0 && p < 4;
}

int ccw(int xa, int ya, int xb, int yb) {
	int c = (xa*yb - ya*xb);
	if (c < 0) return -1;
	else if (c > 0) return 1;
	return 0;
}

int di[] = {0,1,0,1};
int dj[] = {0,0,1,1};
bool passa(int vi, int vj, int a, int b) {
	int ti, tj;
	int cs, rccw = 0;
	rp(i,4) {
		ti = a+di[i], tj = b+dj[i];
		if ((cs = ccw(vi,vj,ti,tj)) != 0) {
			if (!rccw) rccw = cs;
			else if (rccw != cs) return true;
		}
	}
	return false;
}

int main() {
	int id, idEnd;
	char c[6];
	bool liga;
	while (scanf("%d%d%d%d%d%d", &xi, &yi, &zi, &xj, &yj, &zj) == 6 && (xi||yi||zi||xj||yj||zj)) {
		xi++, yi++, zi++, xj++, yj++, zj++;
		idEnd = H(xj,yj,zj);
		memset(g,0,sizeof g);
		memset(to,0,sizeof to);
		fr(z,1,4) fr(y,1,4) fr(x,1,4) {
			scanf("%1s", c);
			g[x][y][z] = (c[0] == '#');
		}
		fr(i,1,5) fr(j,1,5) fr(k,1,5) {
			to[H(i,j,k)].clear();
			fr(t,1,5) {
				if (abs(t-i) == 1 && podeLinha(min(t,i),j,k,0)) to[H(i,j,k)].pb(tup(t,j,k));
				if (abs(t-j) == 1 && podeLinha(i,min(t,j),k,1)) to[H(i,j,k)].pb(tup(i,t,k));
				if (abs(t-k) == 1 && podeLinha(i,j,min(t,k),2)) to[H(i,j,k)].pb(tup(i,j,t));
			}
			fr(u,1,5) {
				fr(v,1,5) {
					if (u != j && v != k) {
						liga = true;
						fr(y,min(j,u),max(j,u)) {
							fr(z,min(k,v),max(k,v)) {
								if (passa(u-j,v-k,y-j,z-k)) liga &= (g[i-1][y][z]^g[i][y][z]);
							}
						}
						if (liga) to[H(i,j,k)].pb(tup(i,u,v));
					}
					if (u != i && v != k) {
						liga = true;
						fr(x,min(i,u),max(i,u)) {
							fr(z,min(k,v),max(k,v)) {
								if (passa(u-i,v-k,x-i,z-k)) liga &= (g[x][j-1][z]^g[x][j][z]);
							}
						}
						if (liga) to[H(i,j,k)].pb(tup(u,j,v));
					}
					if (u != i && v != j) {
						liga = true;
						fr(x,min(i,u),max(i,u)) {
							fr(y,min(j,v),max(j,v)) {
								if (passa(u-i,v-j,x-i,y-j)) liga &= (g[x][y][k-1]^g[x][y][k]);
							}
						}
						if (liga) to[H(i,j,k)].pb(tup(u,v,k));
					}
				}
			}
		}

		while (!heap.empty()) heap.pop();
		heap.push(tup(xi,yi,zi));
		rp(i,MAXP) cost[i] = inf;
		while (1) {
			aux = heap.top(); heap.pop();
			id = H(aux.i,aux.j,aux.k);
			if (aux.cost > cost[id]) continue;
			if (id == idEnd) { printf("%.5lf\n", aux.cost); break; }
			int sz = to[id].size();
			rp(i,sz) {
				if (aux.cost + dist(aux.i,aux.j,aux.k,to[id][i].i,to[id][i].j,to[id][i].k) < cost[H(to[id][i].i,to[id][i].j,to[id][i].k)]) {
					//printf("	%d, %d %d %d, %lf\n", H(to[id][i].i,to[id][i].j,to[id][i].k), to[id][i].i,to[id][i].j,to[id][i].k, dist(aux.i,aux.j,aux.k,to[id][i].i,to[id][i].j,to[id][i].k));
					cost[H(to[id][i].i,to[id][i].j,to[id][i].k)] = aux.cost + dist(aux.i,aux.j,aux.k,to[id][i].i,to[id][i].j,to[id][i].k);
					heap.push(tup(to[id][i].i,to[id][i].j,to[id][i].k,aux.cost + dist(aux.i,aux.j,aux.k,to[id][i].i,to[id][i].j,to[id][i].k)));
				}
			}
		}
	}
	return 0;
}