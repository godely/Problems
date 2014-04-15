#include <cstdio>
#include <cstring>
#include <algorithm>
#include <iostream>
#include <cmath>
using namespace std;
#define MAX_N 500010
#define fr(a,b,c) for(int a=b;a<c;a++)
#define rp(a,b) fr(a,0,b)

int adj[1111][11], size[1111];
int low[1111], num[1111], mark[1111], counter;

void findBridge(int a, int from) {
	low[a] = num[a] = counter++;
	mark[a] = 1;
	rp(i,size[a]) {
		if (adj[a][i] == from) continue;
		if (mark[adj[a][i]] && num[adj[a][i]] < num[a]) printf("%d %d\n", a, adj[a][i]);
		if (!mark[adj[a][i]]) {
			findBridge(adj[a][i], a);
			if (low[adj[a][i]] > num[a]) printf("%d %d\n%d %d\n", a, adj[a][i], adj[a][i], a);
			else printf("%d %d\n", a, adj[a][i]);
			low[a] = min(low[a],low[adj[a][i]]);
		} else if (adj[a][i] != from && num[adj[a][i]] < low[a]) {
			low[a] = num[adj[a][i]];
		}
	}
}

int main() {
	int N, M, a, b, cas=1;
	while (scanf("%d%d", &N, &M) == 2 && N > 0) {
		memset(size,0,sizeof size);
		memset(mark,0,sizeof mark);
		counter = 0;
		rp(i,M) {
			scanf("%d%d", &a, &b);
			adj[a][size[a]++]=b;
			adj[b][size[b]++]=a;
		}
		printf("%d\n\n",cas++);
		findBridge(1,-1);
		printf("#\n");
	}
	return 0;
}