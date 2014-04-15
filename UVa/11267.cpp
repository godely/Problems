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
#define iter(a) typeof((a).begin())
#define Tr(a,b) for(iter(b) a = (b).begin(); a != (b).end(); ++a)
#define Fr(a,b,c) for( int a = b ; a < c ; ++a )
#define rF(a,b,c) for( int a = c-1; a>=b ; --a )
#define Rp(a,b) Fr(a,0,b)
#define fr Fr
#define rp Rp
#define cl(a,b) memset(a,b,sizeof(a))
typedef long long ll;
typedef unsigned long long ull;
typedef pair<int,int> pii;
typedef pair<double,pair<int,int> > pdi;
typedef vector<pair<int,int> > vpii;
#define F first
#define S second
#define MP make_pair
#define PB push_back
#define y1 Y1
#define INF 0x3f3f3f3f
#define LINF 0x3f3f3f3f3f3f3f3fLL
#define ULMAX 0xffffffffffffffffULL
#define MAXN 1000
#define MAXM 120000
#define add(a,b) to[z] = b, ant[z] = adj[a], adj[a] = z++
int to[MAXM], ant[MAXM], adj[MAXN], z;
int col[MAXN];

bool bip(int x) {
	for (int i = adj[x]; ~i; i = ant[i]) {
		if (col[to[i]] == col[x]) return 0;
		if (col[to[i]] == -1) {
			col[to[i]] = col[x]^1;
			if (!bip(to[i])) return 0;
		}
	}
	return 1;
}

bool cmp(pair<int,pii> a, pair<int,pii> b) {
	return a.F < b.F;
}

int rep[MAXN];
int findset(int x) {
	if (x == rep[x]) return x;
	return rep[x] = findset(rep[x]);
}

void unionset(int x, int y) {
	rep[findset(x)] = findset(y);
}

pair<int,pii> s[MAXM];
int main() {
	int N, M, a, b, c;
	while (scanf("%d", &N) == 1 && N > 0) {
		rp(i,N) rep[i] = i;
		scanf("%d", &M);
		cl(adj,-1); z = 0;
		rp(i,M) {
			scanf("%d%d%d", &a, &b, &c);
			s[i] = MP(c,MP(a-1,b-1));
			add(a-1,b-1);
			add(b-1,a-1);
		}
		cl(col,-1);
		col[0] = 0;
		if (!bip(0)) printf("Invalid data, Idiot!\n");
		else {
			sort(s,s+M,cmp);
			int res = 0;
			rp(i,M) {
				if (findset(s[i].S.F) != findset(s[i].S.S)) {
					unionset(s[i].S.F,s[i].S.S);
					res+=s[i].F;
				} else res += (s[i].F < 0) ? s[i].F : 0;
			}
			printf("%d\n", res);
		}
	}
	return 0;
}