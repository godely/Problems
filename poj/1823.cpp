//

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
#define INF 1061109567
#define LINF 0x3f3f3f3f3f3f3f3fLL
#define ULMAX 0xffffffffffffffffULL
#define dbg if(0)
#define rp(a,b) Fr(a,0,b)
#define mp make_pair
#define maxn 17000

//set<int> s;

struct seg {
	int pos, tam, pri;
	seg() {}
	seg(int pos, int tam, int pri = 0) : pos(pos), tam(tam), pri(pri) {}
	
	bool operator<(const seg &lhs) const {
		return pos < lhs.pos;
	}
} aux;

struct Compare {
    bool operator() (const struct seg &lhs, const struct seg &rhs) const {
        return lhs.tam < rhs.tam;
    }
};

int mem[maxn];
set<seg> s;
set<seg>::iterator it, it2;
priority_queue<seg, vector<seg>, Compare> heap;
int main() {
	int N, P, I, a, b;
	while (scanf("%d%d", &N, &P) == 2 && N > 0) {
		while (!heap.empty()) heap.pop();
		memset(mem,0,sizeof mem);
		heap.push(seg(1,N));
		s.insert(seg(1,N));
		rp(i,P) {
			scanf("%d", &I);
			if (I == 1) {
				scanf("%d%d", &a, &b);
				it = s.upper_bound(seg(a,0)); it--;
				int ini, last;
				ini = (*it).pos;
				last = ini+(*it).tam-1;
				s.erase(it);
dbg				cout << ini << " " << last << endl;
				mem[ini]++;
				if (ini < a) {
					heap.push(seg(ini,a-ini,mem[ini]));
					s.insert(seg(ini,a-ini));
				}
				if (a+b-1 < last) {
					heap.push(seg(a+b,last-(a+b-1),mem[a+b]));
					s.insert(seg(a+b,last-(a+b-1)));
				}
			} else if (I == 2) {
				scanf("%d%d", &a, &b);
				b=a+b-1;
				if (!s.empty()) {
					it = s.lower_bound(seg(a,0));
					if (it != s.end()) {
						if (it != s.begin()) {
							it2 = it;
							it2--;
dbg							cout << (*it).pos << " " << (*it).tam << " " << (*it2).pos << " " << (*it2).tam << endl;
							int ini, last;
							last = (*it).pos-1;
							ini = (*it2).pos+(*it2).tam;

							if (a == ini) {
								a = (*it2).pos;
								mem[a]++;
								s.erase(it2);
							}
							if (b == last) {
								b = (*it).pos+(*it).tam-1;
								mem[(*it).pos]++;
								s.erase(it);
							}
dbg							printf("(%d %d %d)\n", mem[a], a, b);
						} else {
							int last = (*it).pos-1;
							
							if (b == last) {
								b = (*it).pos+(*it).tam-1;
								mem[(*it).pos]++;
								s.erase(it);
							}
						}
					} else {
						it2 = it;
						it2--;
						int ini = (*it2).pos+(*it2).tam;
						
						if (a == ini) {
							a = (*it2).pos;
							mem[a]++;
							s.erase(it2);
						}
					}
				}
				s.insert(seg(a,b-a+1));
				heap.push(seg(a,b-a+1,mem[a]));
			} else {
				while (!heap.empty()) {
					aux = heap.top();
					if (mem[aux.pos] != aux.pri) {
						heap.pop();
						continue;
					}
					printf("%d\n", aux.tam);
					goto done;
				}
				printf("0\n");
				done:;
			}
dbg {			printf("> %d\n", s.size());
			for (it = s.begin(); it != s.end(); it++) {
				printf("  %d %d %d\n", (*it).pos, (*it).tam, (*it).pri);
			}
}
		}
	}
}