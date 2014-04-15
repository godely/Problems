#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <cmath>
#include <iostream>
#include <algorithm>
using namespace std;
#define fr(a,b,c) for (int a = b; a < c; a++)
#define rp(a,b) fr(a,0,b)
#define cl(a,b) memset(a,b,sizeof a)
#define sf(a) scanf("%d", &a)
#define sf2(a,b) scanf("%d%d", &a, &b)
#define sf3(a,b,c) scanf("%d%d%d", &a, &b, &c)
#define sf4(a,b,c,d) scanf("%d%d%d%d", &a, &b, &c, &d)
typedef pair<int,int> pii;
#define MP make_pair
#define F first
#define S second
#define oo 0x3f3f3f3f

int x, ma, mi, sc;
int col[10100];

struct af {
	string s;
	string ss;
	int sc;
	af() {}
	
	void ajeita() {
		ss = s;
		for (int i = 0; i < ss.size(); i++) {
			ss[i]|=0x20;
		}
	}
	
	bool operator<(const af &q) const {
		if (sc != q.sc) return sc < q.sc;
		return ss > q.ss;
	}
} p[1010];

int main() {
	int n;
	int cas = 1;
	while (scanf("%d", &n) == 1 && n > 0) {
		printf("Teste %d\n", cas++);
		rp(i,n) {
			cin >> p[i].s;
			sc = 0;
			ma = -1000000;
			mi = 1000000;
			rp(j,12) {
				scanf("%d", &x);
				ma = max(ma,x);
				mi = min(mi,x);
				sc += x;
			}
			sc = sc - ma - mi;
			p[i].sc = sc;
			p[i].ajeita();
		}
		sort(p,p+n);
		col[n-1] = 1;
		cout << "1 " << p[n-1].sc << " " << p[n-1].s << endl;
		for (int i = n-2; i >= 0; i--) {
			if (p[i].sc == p[i+1].sc) col[i] = col[i+1];
			else col[i] = n-i;
			cout << col[i] << " " << p[i].sc << " " << p[i].s << endl;
		}
		puts("");
	}
	return 0;
}