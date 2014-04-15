#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <iostream>
#include <map>
#include <queue>
#include <algorithm>

using namespace std;

int adj[6200][6200];
int cost[6200][6200];
bool isLPG[6200];
int size[6200];

struct abc {
	int city, cost, cap;
	abc() {}
	abc(int city, int cost, int cap) : city(city), cost(cost), cap(cap) {}
};

bool mark[6200][2200];

char start[20], end[20], c1[20], c2[20];

int main() {
	int N, M, cap, k, len, a, b, sId = 1, eId = 2;
	map<string, int> id;
	while (scanf("%d%d%d", &N, &M, &cap) == 3 && N > 0) {
		for (int i = 0; i <= N*2; i++) size[i] = 0;
		for (int i = 0; i <= N*2; i++) isLPG[i] = 0;
		id.clear();
		k = 1;
		scanf("%s%s", start, end);
		id[start] = k++;
		id[end] = k++;
		for (int i = 0; i < N; i++) {
			scanf("%s%s%d", c1, c2, &len);
			if (!id[c1]) id[c1] = k++;
			if (!id[c2]) id[c2] = k++;
			a = id[c1];
			b = id[c2];
			adj[a][size[a]] = b;
			cost[a][size[a]++] = len;
			adj[b][size[b]] = a;
			cost[b][size[b]++] = len;
		}
		for (int i = 0; i < M; i++) {
			scanf("%s", c1);
			isLPG[id[c1]] = true;
		}
		memset(mark,0,sizeof mark);
		abc aux;
		queue<abc> fila;
		fila.push(abc(id[start], 0, 10*cap));
		mark[id[start]][10*cap] = true;
		while (!fila.empty()) {
			aux = fila.front();
			fila.pop();
			if (aux.city == eId) {
				printf("%d\n", aux.cost);
				goto foi;
			}
			if (isLPG[aux.city]) {
				aux.cap = cap*10;
			}

            int siz = size[aux.city];
			for (int i = 0; i < siz; i++) {
				if (aux.cap > cost[aux.city][i] && !mark[adj[aux.city][i]][aux.cap-cost[aux.city][i]]) {
					fila.push(abc(adj[aux.city][i], aux.cost+cost[aux.city][i], aux.cap-cost[aux.city][i]));
					mark[aux.city][aux.cap-cost[aux.city][i]] = true;
				}
			}
		}
		printf("-1\n");
		foi:;
	}
}
