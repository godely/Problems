#include <bits/stdc++.h>
using namespace std;
#define fr(a,b,c) for(int a = b; a < c; a++)
#define rp(a,b) fr(a,0,b)

char gb[100], gb2[100], gb3[100];
int C[1111];
int dist[111][111];
map<string, int> id;
int n, c, r, k;
int fw() { rp(k,n) rp(i,n) rp(j,n) dist[i][j] = min(dist[i][j], dist[i][k] + dist[k][j]); }

int a, b, v;
int main() {
	int cas = 1;
	while(scanf("%d%d%d", &n, &c, &r)==3 && n > 0) {
		id.clear(); k = 0;
		c++;
		rp(i,c) {
			scanf("%s", gb);
			if (id.count(gb) == 0) id[gb] = k++;
			C[i] = id[gb];
		}
		memset(dist,0x3f,sizeof dist);
		rp(i,n) dist[i][i] = 0;
		rp(i,r) {
			scanf("%s%s%s", gb, gb2, gb3);
			if (id.count(gb) == 0) id[gb] = k++;
			if (id.count(gb3) == 0) id[gb3] = k++;
			int a = id[gb], b = id[gb3], s = strlen(gb2);
			gb2[s-2] = '\0';
			sscanf(gb2+2, "%d", &v);
			if (gb2[s-1] == '>') dist[a][b] = min(dist[a][b],v);
			if (gb2[0] == '<') dist[b][a] = min(dist[b][a],v);
		}
		fw();
		int ans = 0;
		fr(i,1,c) {
			ans += dist[C[0]][C[i]] + dist[C[i]][C[0]];
		}
		printf("%d. %d\n", cas++, ans);
	}
	return 0;
}