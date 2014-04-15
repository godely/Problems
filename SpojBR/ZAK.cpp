#include <bits/stdc++.h>
using namespace std;
#define fr(a,b,c) for(int a = b; a < c; a++)
#define rp(a,b) fr(a,0,b)
#define MAXN 1010
#define inf 0x3f3f3f3f

int M, N, G, K;
int mana[MAXN], dano[MAXN];
int ADJ[MAXN][MAXN], ADJ_SIZE[MAXN];
int SALA[MAXN][MAXN], SALA_SIZE[MAXN];
int PESO_SALA[MAXN];
int COST[MAXN], MARK[MAXN];

int knap[2*MAXN];

void knapsack() {
	knap[0] = 0;
	for (int j = 1; j <= 2000; j++) knap[j] = inf;
	for (int i = 0; i < M; i++) {
		for (int j = dano[i]; j <= 2000; j++) {
			if (knap[j - dano[i]] < inf) knap[j] = min(knap[j], knap[j - dano[i]] + mana[i]);
		}
	}
	for (int i = 1999; i >= 1; i--) {
		knap[i] = min(knap[i], knap[i+1]);
	}
}

struct state {
	int id, cost;
	state() {}
	state(int id, int cost) : id(id), cost(cost) {}
	
	bool operator <(const state &lhs) const {
		return cost > lhs.cost;
	}
} aux;

priority_queue<state> fila;

int main() {
	int a, b;
	while (scanf("%d%d%d%d", &M, &N, &G, &K) == 4 && M > 0) {
		memset(ADJ_SIZE, 0, sizeof ADJ_SIZE);
		memset(SALA_SIZE, 0, sizeof SALA_SIZE);
		rp(i,M) {
			scanf("%d%d", &mana[i], &dano[i]);
		}
		rp(i,G) {
			scanf("%d%d", &a, &b);
			ADJ[a][ADJ_SIZE[a]++] = b;
			ADJ[b][ADJ_SIZE[b]++] = a;
		}
		rp(i,K) {
			scanf("%d%d", &a, &b);
			SALA[a][SALA_SIZE[a]++] = b;
		}
		knapsack();
		fr(i,1,N+1) {
			PESO_SALA[i] = 0;
			for (int k = 0; k < SALA_SIZE[i]; k++) PESO_SALA[i] += knap[SALA[i][k]];
		}
		
		while (!fila.empty()) fila.pop();
		memset(COST, 0x3f, sizeof COST);
		memset(MARK, 0, sizeof MARK);
		COST[1] = PESO_SALA[1];
		fila.push(state(1, PESO_SALA[1]));
		while (!fila.empty()) {
			aux = fila.top();
			fila.pop();
			if (MARK[aux.id]) continue;
			MARK[aux.id] = 1;
			if (aux.id == N) {
				printf("%d\n", aux.cost);
				goto lol;
			}
			for (int i = 0; i < ADJ_SIZE[aux.id]; i++) {
				if (!MARK[ADJ[aux.id][i]] && COST[ADJ[aux.id][i]] > aux.cost + PESO_SALA[ADJ[aux.id][i]]) {
					COST[ADJ[aux.id][i]] = aux.cost + PESO_SALA[ADJ[aux.id][i]];
					fila.push(state(ADJ[aux.id][i], aux.cost + PESO_SALA[ADJ[aux.id][i]]));
				}
			}
		}
		printf("-1\n");
		lol:;
	}
	return 0;
}