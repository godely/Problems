#include <cstdio>
#include <cstdlib>
#include <algorithm>
#include <vector>
#include <cmath>
#include <map>
#include <set>
#include <iostream>
using namespace std;
#define MP make_pair
typedef pair<int,int> pii;
#define fr(a,b,c) for(int a = b; a < c; a++)
#define rp(a,b) fr(a,0,b)
#define F first
#define S second
#define MAXN 200100
typedef long long ll;

int rep[MAXN], sz[MAXN];
ll dp[MAXN];

struct edge {
	int a, b, c;

	edge() {}
	edge(int a, int b, int c) : a(a), b(b), c(c) {}

	bool operator<(const edge &q) const {
		return c > q.c;
	}
} e[MAXN];

int findset(int a) {
	if (a == rep[a]) return a;
	return rep[a] = findset(rep[a]);
}

void unionset(int a, int b) {
	sz[findset(a)] = sz[findset(b)] = sz[findset(a)] + sz[findset(b)];
	rep[findset(a)] = findset(b);
}

int main() {
	int n, a, b, c;
	while (scanf("%d", &n) == 1) {
		rp(i,n) rep[i] = i, sz[i] = 1, dp[i] = 0;
		rp(i,n-1) {
			scanf("%d%d%d", &a, &b, &c);
			e[i] = edge(a-1,b-1,c);
		}
		sort(e,e+n-1);
		ll res = 0;
		rp(i,n-1) {
			a = findset(e[i].a);
			b = findset(e[i].b);
			c = e[i].c;
			if (dp[a] + ll(c) * ll(sz[b]) > dp[b] + ll(c) * ll(sz[a])) {
				sz[a] += sz[b];
				rep[b] = a;
				dp[a] += ll(c) * ll(sz[b]);
			} else {
				sz[b] += sz[a];
				rep[a] = b;
				dp[b] += ll(c) * ll(sz[a]);
			}
		}
		a = findset(0);
		printf("%lld\n", dp[a]);
	}
	return 0;
}