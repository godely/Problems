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

#define maxn 20100
#define maxm 1001000
#define add(a,b) pai[b]++, to[z] = b, ant[z] = adj[a], adj[a] = z++

int pai[maxn], to[maxm], ant[maxm], adj[maxn], z;
int rep[maxn], vis[maxn];

int n, m, a, b;

int findset(int x) {
	if (x == rep[x]) return x;
	else return rep[x] = findset(rep[x]);
}

bool sameset(int x, int y) { return findset(x) == findset(y); }
void unionset(int x, int y) { rep[findset(x)] = findset(y); }

bool cycle(int x) {
	vis[x] = 1;
	for (int i = adj[x]; i != -1; i = ant[i]) {
		if (vis[to[i]] == 1) return 1;
		if (!vis[to[i]] && cycle(to[i])) return 1;
	}
	vis[x] = 2;
	return 0;
}

bool disjoint() {
	int p = findset(0);
	Fr(i,1,n) {
		if (findset(i) != p) return 1;
	}
	return 0;
}

int arr[maxn];
int ult;
bool cant;
set<int> s;
int twoways(int x) {
	if (~arr[x]) return arr[x];
	if (x == ult) return arr[x] = 0;
	int maxi = 0;
	for (int i = adj[x]; i != -1; i = ant[i]) {
		maxi = max(maxi, twoways(to[i])+1);
	}
	if (s.count(maxi) == 1) cant = 1;
	s.insert(maxi);
	return arr[x] = maxi;
}

int main() {
	while (scanf("%d%d", &n, &m) == 2) {
		if (!(n||m)) return 0;
		memset(pai,0,sizeof pai);
		memset(adj,-1,sizeof adj);
		Fr(i,0,n) rep[i] = i;
		z = 0;
		Fr(i,0,m) {
			scanf("%d%d", &a, &b); a--, b--;
			add(a,b);
			unionset(a,b);
		}
		bool tcycle = 0;
		memset(vis,0,sizeof vis);
		Fr(i,0,n) {
			if (!vis[i]) {
				if (cycle(i)) {
					tcycle = 1;
					break;
				}
			}
		}
		if (tcycle) printf("0\n");
		else {
			int princ = -1; ult = -1;
			Fr(i,0,n) {
				if (!pai[i]) {
					if (princ == -1) princ = i;
					else princ = -2;
				}
				if (adj[i] == -1) {
					if (ult == -1) ult = i;
					else ult = -2;
				}
			}
			if (disjoint() || princ == -2 || ult == -2) printf("2\n");
			else {
				memset(arr,-1,sizeof arr);
				s.clear();
				cant = 0;
				twoways(princ);
				if (cant) printf("2\n");
				else printf("1\n");
			}
		}
	}
	return 0;
}