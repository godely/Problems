#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <cmath>
#include <algorithm>
#include <queue>

#define PAR pair<int, int>

using namespace std;

int C, L, S, E, D, A, B;

int adjSize[510];
int adj[110][510];
bool mark[110][220];

int main() {
	queue<PAR> fila;
	PAR aux;
	while (scanf("%d%d", &C, &L) && C) {
		memset(adjSize, 0, sizeof(adjSize));
		memset(adj, 0, sizeof(adj));
		for (int i = 0; i < L; i++) {
			scanf("%d%d", &A, &B);
			adj[A][adjSize[A]++] = B;
			adj[B][adjSize[B]++] = A;
		}
		scanf("%d%d%d", &S, &E, &D);
		while (!fila.empty()) fila.pop();
		fila.push(make_pair(S, D));
		memset(mark, 0, sizeof(mark));
		while (!fila.empty()) {
			aux = fila.front();
			fila.pop();
			if (mark[aux.first][aux.second]) continue;
			if (!aux.second) {
				if (aux.first == E) goto CANTRAVEL;
				continue;
			}
			mark[aux.first][aux.second] = 1;
			for (int i = 0; i < adjSize[aux.first]; i++) {
				fila.push(make_pair(adj[aux.first][i], aux.second-1));
			}
		}
		printf("No, Teobaldo can not travel.\n");
		continue;
		CANTRAVEL:
		printf("Yes, Teobaldo can travel.\n");
	}
	return 0;
}