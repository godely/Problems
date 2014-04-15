#include <cstdio>
#include <cstdlib>
#include <cmath>
#include <vector>
#include <cstring>
#include <map>
#include <iostream>
#define fr(a,b,c) for(int a = b; a < c; a++)
#define rp(a,b) fr(a,0,b)
#define MAXN 3011
#define MAXM 501111

using namespace std;

//graph structure
#define add(a,b) from[z] = a, to[z] = b, ant[z] = adj[a], adj[a] = z++
int from[MAXM], to[MAXM], ant[MAXM], adj[MAXN], z;
int vis[MAXN], match[MAXN];

int n, m;
char gb[50];

int augment(int l) {
	if (vis[l]) return 0;
	vis[l] = 1;
	for (int i = adj[l]; ~i; i = ant[i]) {
		if (match[to[i]] == -1 || augment(match[to[i]])) {
			match[to[i]] = l;
			return 1;
		}
	}
	return 0;
}

int alf[511][30], tmp[30];

int main() {
	while (scanf("%d%d", &n, &m) == 2) {
		memset(adj,-1,sizeof adj); z = 0;
		rp(i,n) {
			scanf("%s", gb);
			memset(alf[i],0,sizeof alf[i]);
			for (int j = 0; gb[j]; j++) {
				alf[i][gb[j]-'a']++;
			}
		}
		rp(j,m) {
			scanf("%s", gb);
			memset(tmp,0,sizeof tmp);
			for (int i = 0; gb[i]; i++) {
				tmp[gb[i]-'a']++;
			}
			rp(i,n) {
				rp(k,26) {
					if (alf[i][k] < tmp[k]) goto cant;
				}
				add(i,j+n);
				cant:;
			}
		}
		int ans = 0;
		memset(match,-1,sizeof match);
		rp(i,n) {
			memset(vis,0,sizeof vis);
			ans += augment(i);
		}
		printf("%d\n", ans);
	}
	return 0;
}