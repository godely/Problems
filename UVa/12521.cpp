//by stor
#include <bits/stdc++.h>
using namespace std;
#define fr(a,b,c) for(int a = b; a < c; a++)
#define rp(a,b) fr(a,0,b)

int adj[5011][5011], adjSize[5011], mark[5011];
char teamName[111][50];
int teamCaptain[111];
int uniformSize[5011];
bitset<5011> adjList[5011], teste;
int tempUnif[55];

int main() {
	int T, N, M, cas = 1;
	int a, b, uniform, fi;
	while (scanf("%d%d", &T, &N) == 2 && T > 0) {
		M = N/T;
		rp(i,T) scanf("%s %d", teamName[i], teamCaptain+i);
		N++;
		rp(i,N) adjSize[i] = 0, adjList[i].reset(), mark[i] = 0;
		fr(i,1,N) {
			scanf("%d %d %d", &a, &uniform, &fi);
			uniformSize[a] = uniform;
			adjList[a].set(a);
			rp(j,fi) {
				scanf("%d", &b);
				adj[a][adjSize[a]++] = b;
				adjList[a].set(b);
			}
		}
		printf("Case %d:\n", cas++);
		rp(i,T) {
			a = teamCaptain[i];
			memset(tempUnif, 0, sizeof tempUnif);
			tempUnif[uniformSize[a]]++;
			rp(j,adjSize[a]) {
				b = adj[a][j];
				if (!mark[b]) {
					teste = adjList[a]&adjList[b];
					if (teste.count() >= M) {
						mark[b] = 1;
						tempUnif[uniformSize[b]]++;
					}
				}
			}
			printf("%s\n", teamName[i]);
			fr(j,1,51) if (tempUnif[j] > 0) printf("%d %d\n", j, tempUnif[j]);
		}
	}
	return 0;
}