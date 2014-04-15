#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <algorithm>
#include <vector>
#include <iostream>
#include <map>
#include <utility>
#include <iostream>
#include <set>
#define mp make_pair
using namespace std;
#define fr(a,b,c) for(int a = b; a < c; a++)
#define rp(a,b) fr(a,0,b)
#define cl(a,b) memset(a,b,sizeof a)
#define mp make_pair
typedef long long ll;
typedef unsigned long long ull;
#define maxn 11000
#define maxm 11000000

int to[maxm], cost[maxm], ant[maxm], adj[maxn], z = 0;
#define add(a,b,c) to[z] = b, cost[z] = c, ant[z] = adj[a], adj[a] = z++

int N, P;
char gb[maxn], str[maxn];
int szStr;
int w[maxn], sz[maxn];
ull hash[maxn], th[maxn];
int dp[maxn];

int go() {
	dp[szStr] = 0;
	int res;
	for (int i = szStr-1; i >= 0; i--) {
		res = dp[i+1]-P;
		//printf("%d %d\n", i, res);
		for (int j = adj[i]; ~j; j = ant[j]) {
			res = max(res,dp[to[j]]+cost[j]);
		}
		dp[i] = res;
	}
	return dp[0];
}

ull tmp, BASE[maxn];
int main() {
	int cas = 1;
	BASE[0] = 1;
	BASE[1] = 63;
	fr(i,2,maxn) BASE[i] = BASE[i-1]*BASE[1];
	int T;
	scanf("%d", &T);
	while (T--) {
		cl(adj,-1); z = 0;
		scanf("%d%d", &N, &P);
		rp(i,N) {
			scanf("%s%d", gb, &w[i]);
			tmp = 0;
			for (int j = 0; gb[j]; j++) {
				tmp = (tmp*BASE[1]);
				tmp = (tmp+gb[j]-'a'+1);
			}
			sz[i] = strlen(gb);
			hash[i] = tmp;
			//printf("%d %llu\n", sz[i], hash[i]);
		}
		scanf("%s", str);
		th[0] = str[0]-'a'+1;
		//printf("%llu", th[0]);
		for (int j = 1; str[j]; j++) th[j] = (th[j-1]*BASE[1] + str[j] - 'a'+1);//, printf(" %llu", th[j]);
		//puts("");
		szStr = strlen(str);
		rp(i,N) {
			if (th[sz[i]-1] == hash[i]) add(0,sz[i],w[i]);//, printf("%d > %d (%d)\n", 0, sz[i], w[i]);
			for (int j = sz[i]; j < szStr; j++) {
				if (th[j]-th[j-sz[i]]*BASE[sz[i]] == hash[i]) add(j-sz[i]+1,j+1,w[i]);//, printf("%d > %d (%d)\n", j-sz[i]+1, j+1, w[i]);
			}
		}
		printf("Case %d: %d\n", cas++, go());
	}
}