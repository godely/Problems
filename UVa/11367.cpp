#include <cstdio>
#include <algorithm>
#include <cstring>
#include <utility>
#include <vector>
#include <queue>
#include <stack>
#include <map>
#include <iostream>
#include <set>
#include <cmath>
#include <cassert>
#include <ctime>
#include <string>

using namespace std;

#define db(x) cout << #x " == " << x << endl
//#define _ << ", " <<
#define iter(a) typeof((a).begin())
#define Tr(a,b) for(iter(b) a = (b).begin(); a != (b).end(); ++a)
#define Fr(a,b,c) for( int a = b ; a < c ; ++a )
#define rF(a,b,c) for( int a = c-1; a>=b ; --a )
#define Rp(a,b) Fr(a,0,b)
#define fr Fr
#define rp Rp
#define cl(a,b) memset(a,b,sizeof(a))
typedef long long ll;
typedef unsigned long long ull;
typedef pair<int,int> pii;
typedef pair<double,pair<int,int> > pdi;
typedef vector<pair<int,int> > vpii;
#define F first
#define S second
#define MP make_pair
#define PB push_back
#define y1 Y1
#define INF 0x3f3f3f3f
#define LINF 0x3f3f3f3f3f3f3f3fLL
#define ULMAX 0xffffffffffffffffULL
#define maxn 2100
#define maxm 22000
#define MOD 200003

int n, m, p[maxn];
int q;
int a, b, c, u, f, t;
int to[maxm], cost[maxm], ant[maxm], adj[maxn], z;
#define add(a,b,c) to[z] = b, cost[z] = c, ant[z] = adj[a], adj[a] = z++

struct st {
	int cost, city, fuel;
	st() {}
	st(int cost, int city, int fuel) : cost(cost), city(city), fuel(fuel) {}

	bool operator<(const st &q) const {
		if (cost != q.cost) return cost > q.cost;
		if (fuel != q.fuel) return fuel < q.fuel;
		return city > q.city;
	}
} aux;

priority_queue<st> pq;
int C[maxn][111];
int main() {
	cl(adj,-1); z = 0;
	scanf("%d%d", &n, &m);
	rp(i,n) scanf("%d", &p[i]);
	rp(i,m) scanf("%d%d%d", &a, &b, &c), add(a,b,c), add(b,a,c);
	scanf("%d", &q);
	rp(i,q) {
		while (!pq.empty()) pq.pop();
		scanf("%d%d%d", &c, &a, &b);
		pq.push(st(0,a,0));
		cl(C,0x3f);
		C[a][0] = 0;
		while (!pq.empty()) {
			aux = pq.top(); pq.pop();
			u = aux.city;
			f = aux.fuel;
			t = aux.cost;

			if (t > C[u][f]) continue;

			if (u == b) {
				printf("%d\n", t);
				goto fim;
			}

			if (f < c && C[u][f+1] > C[u][f] + p[u]) {
				C[u][f+1] = C[u][f] + p[u];
				pq.push(st(C[u][f+1],u,f+1));
			}
			for (int v = adj[u]; ~v; v = ant[v]) {
				if (f >= cost[v] && C[to[v]][f - cost[v]] > C[u][f]) {
					C[to[v]][f - cost[v]] = C[u][f];
					pq.push(st(C[to[v]][f - cost[v]],to[v],f - cost[v]));
				}
			}
		}
		puts("impossible");
		fim:;
	}
}