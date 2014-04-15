#include <cstdio>
#include <cstdlib>
#include <algorithm>
#include <cstring>
#include <utility>
#include <queue>
#include <map>
#include <iostream>
#include <cassert>

using namespace std;

#define Fr(a,b,c) for(int a = b; a < c; ++a)
#define dbg if(0)

#define scanf printf
#define printf asdjnasd

#define MAXN 55
#define MAXK 10
#define MAXM 2450
#define MAXZ 65545

struct No {
	int node, mask, cost;
	No(int a = 0, int b = 0, int c = 0) {
		node = a, mask = b, cost = c;
	}
	bool operator<(const No &node) const {
		if(cost != node.cost) return cost > node.cost;
		return mask < node.mask;
	}
};

int m, k;
int adj[MAXN], n;
int to[MAXM], ant[MAXM], w[MAXM], qtd;

priority_queue<No> heap;
int ticks[MAXN], events[MAXN];
map<int, int> mapa;
int tempo[MAXK][2];

int mark[MAXN][MAXZ][2];

inline void add(int a, int b, int c) {
	to[qtd] = b, w[qtd] = c, ant[qtd] = adj[a]; adj[a] = qtd++;
}

inline bool tem2(int mask) {
	if(mask) return false;
	int a = mask & - mask;
	mask -= a;
	return mask && (mask == (mask & - mask));
}

int main() {
	memset(mark, -1, sizeof(mark));
	
	int t, caso = 0;
	cin >> t;
//	scanf("%d", &t);
	while(t--) {
		cin >> n >> m >> k;
//		scanf("%d%d%d", &n, &m, &k);
		Fr(i,0,n+1) adj[i] = -1, ticks[i] = events[i] = 0;
		qtd = 0;
		
		mapa.clear();
		
		Fr(s,0,m) {
			int a, b, c;
			cin >> a >> b >> c;
//			scanf("%d%d%d", &a, &b, &c);
			add(a, b, c), add(b, a, c);
		}

		int full = 0;
		Fr(s,0,k) {
			int a, d, e;
			cin >> a >> tempo[s][0] >> tempo[s][1] >> d;
//			scanf("%d%d%d%d", &a, &tempo[s][0], &tempo[s][1], &d);
			events[a] |= 3 << (s << 1);
			full |= 3 << (s << 1);
			mapa[3 << (s << 1)] = s;
			
			Fr(aa,0,d) {
				cin >> e;
//				scanf("%d", &e);
				ticks[e] |= 1 << (s << 1);
			}
		}

		while(!heap.empty()) heap.pop();
		heap.push(No(1, ticks[1], 0));
		mark[1][ticks[1]][0] = caso, mark[1][ticks[1]][1] = 0;
		int ans = -1;
		while(!heap.empty()) {
			No at = heap.top(); heap.pop();
//			dbg printf("\n  Node(pos %d, mask %d, cost %d)\n", at.node, at.mask, at.cost);
//			dbg printf("mark[%d][%d][1] %d\n", at.node, at.mask, mark[at.node][at.mask][1]);
			if(mark[at.node][at.mask][1] < at.cost) continue;
//			dbg printf(" !!\n");
			if(at.node == 1 && at.mask == full) {
				ans = at.cost;
				break;
			}

			int poss = events[at.node];
			while(poss) {
				int a = poss & - poss;
				poss -= a;
				int b = poss & - poss;
				poss -= b;
				a |= b;
				
				//Já visitei
				if(tem2(at.mask & a)) continue;
				int who = mapa[a];
				No novo = No(at.node, at.mask | a, at.cost);
				
				if(at.mask & a) novo.cost += tempo[who][1]; //tem fast
				else novo.cost += tempo[who][0]; //"normal"
				
				if(mark[novo.node][novo.mask][0] != caso ||
					mark[novo.node][novo.mask][1] > novo.cost) {
						mark[novo.node][novo.mask][0] = caso;
						mark[novo.node][novo.mask][1] = novo.cost;
						heap.push(novo);
				}
			}

			//adjacentes
			for(int i = adj[at.node]; ~i; i = ant[i]) {
				int u = to[i], v = w[i];
				No novo = No(u, at.mask | ticks[u], at.cost + v);
				if(mark[novo.node][novo.mask][0] != caso ||
					mark[novo.node][novo.mask][1] > novo.cost) {
						mark[novo.node][novo.mask][0] = caso;
						mark[novo.node][novo.mask][1] = novo.cost;
						heap.push(novo);
				}
			}
		}

		cout << "Case #" << ++caso << ": " << ans << endl;
//		printf("Case #%d: %d\n", ++caso, ans);
	}
	
	return 0;
}