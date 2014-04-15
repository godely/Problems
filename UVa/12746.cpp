#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <cassert>
#include <vector>
#include <algorithm>
#include <iostream>
using namespace std;
#define fr(a,b,c) for (int a = b; a < c; a++)
#define rp(a,b) fr(a,0,b)
#define cl(a,b) memset(a,b,sizeof a)
#define MOD 100007

int main() {
	scanf("%d", &T);
	while (T--) {
		scanf("%d%d", &R, &C);
		int M = R*C;
		rp(i,M) {
			scanf("%d", &grau[i]);
			rp(j,grau[i]) {
				scanf("%d", &adj[i][j]);
				adj[i][j]--;
			}
			lst[grau[i]][sLst[grau[i]]++] = i;
		}
		rp(i,5) sort(lst[i],lst[i]+sLst[i]);
		
		bool change = 0;
		if (R > C) swap(R,C), change = 1;

		if (C == 1) {
			if (grau[0] > 0) printf("NO SUCH GRID\n");
			else printf("1\n");
		} else if (R == 1) {
			if (grau[1] != 2 || grau[0] > 0 || grau[3] > 0 || grau[4] > 0) printf("NO SUCH GRID\n");
			else {
				int s = lst[1][0];
				grid[0][0] = s;
				mark[s] = 1;
				int i = 1;
				s = adj[s][0];
				grid[0][1] = s;
				mark[s] = 1;
				while (s != lst[1][1]) {
					int a = adj[s][0];
					if (mark[a])
				}
			}
		} else if (R == 2) {

		} else {

		}

	}
}