#include <cstdio>
#include <algorithm>
#include <cstring>
#include <utility>
#include <vector>
#include <queue>
#include <stack>
#include <map>
#include <iostream>
#include <set>
#include <cmath>
#include <cassert>
#include <ctime>
#include <string>

using namespace std;

#define db(x) cout << #x " == " << x << endl
//#define _ << ", " <<
#define Fr(a,b,c) for( int a = b ; a < c ; ++a )
#define CL(a,b) memset(a,b,sizeof(a))
typedef long long ll;
typedef unsigned long long ull;
typedef pair<int,int> pii;
typedef vector<pair<int,int> > vpii;
#define F first
#define S second
#define MP make_pair
#define PB push_back
#define y1 Y1
#define INF 0x3f3f3f3f
#define LINF 0x3f3f3f3f3f3f3f3fLL
#define ULMAX 0xffffffffffffffffULL

#define maxn 50100
#define maxm 300100
#define add(a,b) to[z] = b, ant[z] = adj[a], adj[a] = z++

int to[maxm], cost[maxm], ant[maxm], adj[maxn], z;
int N, M, a, b;
int low[maxn], num[maxn], parent[maxn], mark[maxn], cnt, root, child;
ll resp, qntT;

ll art(int u) {
	low[u] = num[u] = cnt++;
	bool isArt = 0;
	ll qnt = 0, qnt2 = 0;
	ll temp = 0;
	//printf("%d\n", u+1);
	for (int i = adj[u]; i != -1; i = ant[i]) {
		int v = to[i];
		if (num[v] == -1) {
			parent[v] = u;
			if (u == root) {
				child++;
				if (child > 1) isArt = 1;
			}
			ll ret = art(v);
			qnt2 += ret;
			
			if (u != root && low[v] >= num[u]) isArt = 1;
			
			if (low[v] >= num[u]) {
				temp += qnt*ret;
				qnt += ret;
			}
			low[u] = min(low[u], low[v]);
		} else if (v != parent[u]) {
			low[u] = min(low[u], num[v]);
		}
	}
	
	if (isArt) {
		//printf("%d %lld\n", u+1, qnt);
		temp += qnt*(qntT-qnt-1);
		resp += 2*temp;
	}
	return qnt2+1;
}

ll dfs(int u) {
	mark[u] = 1;
	ll ret = 1;
	for (int i = adj[u]; i != -1; i = ant[i]) {
		if (!mark[to[i]]) ret += dfs(to[i]);
	}
	return ret;
}

int cas = 1;
int main() {
	int T; scanf("%d", &T);
	while (T--) {
		memset(adj,-1,sizeof adj); z = 0;
		scanf("%d%d", &N, &M);
		Fr(i,0,M) {
			scanf("%d%d", &a, &b);
			add(a-1,b-1); add(b-1,a-1);
		}
		memset(low,-1,sizeof low);
		memset(num,-1,sizeof num);
		memset(parent,-1,sizeof parent);
		memset(mark,0,sizeof mark);
		resp = 0;
		Fr(i,0,N) {
			if (!mark[i]) {
				qntT = dfs(i);
				root = i;
				cnt = 0;
				child = 0;
				art(i);
			}
		}
		printf("Case %d: %lld\n", cas++, resp);
	}
	return 0;
}