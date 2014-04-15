#include <utility>
#include <vector>
#include <queue>
#include <stack>
#include <map>
#include <string>
#include <set>
#include <cstdio>
#include <cmath>
#include <ctime>
#include <iostream>
#include <cstring>
#include <cassert>

using namespace std;

#define db(x) cout << #x " == " << x << endl
//#define _ << ", " <<
#define fr(a,b,c) for( int a = b ; a < c ; ++a )
#define rp(a,b) fr(a,0,b)
#define cl(a,b) memset(a,b,sizeof(a))
#define cpy(a,b) memcpy(a,b,sizeof b)
typedef unsigned long long ll;
typedef unsigned long long ull;
typedef pair<int,int> pii;
typedef vector<pair<int,int> > vpii;
typedef map<int,int> mii;
#define F first
#define S second
#define MP make_pair
#define PB push_back
#define INF 0x3f3f3f3f
#define LINF 0x3f3f3f3f3f3f3f3fLL
#define ULMAX 0xffffffffffffffffULL
#define y1 Y1
#define MAXN 40100

char T[MAXN], P[MAXN];
int n, m;

struct state {
	int len, link;
	int next[30];
	int& operator[](const char c) { return next[c-'a']; }
} st[2*MAXN];

int sz, last;

void sa_init() {
	sz = 1;
	last = 0;
	st[0].len = 0;
	st[0].link = -1;
	cl(st[0].next,-1);
}

void sa_extend(char c) {
	int cur = sz++;
	st[cur].len = st[last].len + 1;
	cl(st[cur].next,-1);
	int p = last;
	for (; (~p) && !(~st[p][c]); p = st[p].link) st[p][c] = cur;
	if (p == -1) st[cur].link = 0;
	else {
		int q = st[p][c];
		if (st[p].len+1 == st[q].len) st[cur].link = q;
		else {
			int clone = sz++;
			st[clone].len = st[p].len+1;
			cpy(st[clone].next,st[q].next);
			st[clone].link = st[q].link;
			for (; p != -1 && st[p][c] == q; p = st[p].link) st[p][c] = clone;
			st[q].link = st[cur].link = clone;
		}
	}
	last = cur;
}

bool busca() {
	for (int i = 0, pos = 0; i < m; i++) {
		if (~st[pos][P[i]]) pos = st[pos][P[i]];
		else return 0;
	}
	return 1;
}

int main() {
	scanf("%s", T);
	n = strlen(T);
	sa_init();
	for (int i = 0; T[i]; i++) sa_extend(T[i]);
	while (scanf("%s", P) == 1) {
		m = strlen(P);
		printf("%d\n", busca());
	}
}