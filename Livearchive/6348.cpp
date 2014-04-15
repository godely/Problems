#include <cstdio>
#include <cstdlib>
#include <algorithm>
#include <vector>
#include <cmath>
#include <map>
#include <set>
#include <iostream>
#include <cstring>
#include <ctime>
using namespace std;
typedef pair<int,int> pii;
#define fr(a,b,c) for(int a = b; a < c; a++)
#define rp(a,b) fr(a,0,b)
#define cl(a,b) memset(a,b,sizeof a)
#define F first
#define S second
#define oo 0x3f3f3f3f
#define PB push_back
#define MP make_pair
typedef long long ll;
#define maxn 500100

struct evt {
	int x, yd, yu;
	int type, id;
	evt() {}
	evt(int x, int yd, int yu, int type, int id) : x(x), yd(yd), yu(yu), type(type), id(id) {}

	bool operator<(const evt &lhs) const {
		if (x != lhs.x) return x < lhs.x;
		return type < lhs.type;
	}
} e[maxn];
int k;

map<int,int> mm;
map<int,int>::iterator it;
pair<pii,pii> v[maxn];
int pai[maxn];

int main() {
	mm.clear();
	int N;
	scanf("%d", &N);
	k = 0;
	rp(i,N) scanf("%d%d%d%d", &v[i].F.F, &v[i].F.S, &v[i].S.F, &v[i].S.S);
	rp(i,N) {
		e[k++] = evt(v[i].F.F,v[i].F.S,v[i].S.S,1,i);
		e[k++] = evt(v[i].S.F,v[i].F.S,v[i].S.S,0,i);
	}
	sort(e,e+k);
	rp(i,k) {
		if (e[i].type) {
			it = mm.upper_bound(e[i].yu);
			if (it == mm.end()) pai[e[i].id] = -1;
			else {
				int yg = (*it).first;
				int idg = (*it).second;
				if (yg == v[idg].F.S) pai[e[i].id] = pai[idg];
				else pai[e[i].id] = idg;
			}
			//printf("%d: x = %d, y_up = %d, y_down = %d, pai = %d, id = %d\n", i, e[i].x, e[i].yu, e[i].yd, pai[e[i].id], e[i].id);
			mm.insert(MP(e[i].yd,e[i].id));
			mm.insert(MP(e[i].yu,e[i].id));
		} else {
			mm.erase(e[i].yd);
			mm.erase(e[i].yu);
		}
	}
	rp(i,N) printf("%d\n", pai[i]);
}