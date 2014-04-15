#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <cmath>
#include <algorithm>
#include <vector>
#include <iostream>
#define fr(a,b,c) for(int a=b;a<c;a++)
#define rp(a,b) fr(a,0,b)
using namespace std;

int adj[111][111], size[111], low[111], num[111], counter, arts, rootChildren;
bool mark[111];

void findArt(int a, int from) {
	low[a] = num[a] = counter++;
	mark[a] = 1;
	int kkk = 0;
	rp(i,size[a]) {
		if (adj[a][i] == from) continue;
		if (!mark[adj[a][i]]) {
			if (a==0) rootChildren++;
			findArt(adj[a][i], a);
			if (low[adj[a][i]] >= num[a] && a>0 && !kkk) {
				kkk=1;
				//printf("> %d\n", a+1);
			}
			low[a] = min(low[a],low[adj[a][i]]);
		} else if (adj[a][i] != from) {
			low[a] = min(low[a],num[adj[a][i]]);
		}
		//printf("FROM:%d   %d,%d,%d   %d,%d,%d\n", from+1, a+1, num[a], low[a], adj[a][i]+1, num[adj[a][i]], low[adj[a][i]]);
	}
	arts+=kkk;
}

char gb[11111];
int main() {
	int N, a, b;
	char *pt;
	while (scanf("%d\n", &N) == 1 && N > 0) {
		memset(size, 0, sizeof size);
		while (gets(gb)) {
			if (gb[0] == '0') break;
			pt = strtok(gb, " ");
			a = atoi(pt) - 1;
			while ((pt = strtok(NULL, " "))) {
				b = atoi(pt) - 1;
				adj[a][size[a]++] = b;
				adj[b][size[b]++] = a;
			}
		}
		rp(i,N) {
			sort(adj[i], adj[i]+size[i]);
			size[i] = unique(adj[i], adj[i]+size[i]) - adj[i];
			/*printf("%d:", i+1);
			rp(j,size[i]) printf(" %d", adj[i][j]+1);
			printf("\n");*/
		}
		counter = arts = rootChildren = 0;
		memset(mark, 0, sizeof mark);
		findArt(0, -1);
		printf("%d\n", arts+(rootChildren>1));
	}
}