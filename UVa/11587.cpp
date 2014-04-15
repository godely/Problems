#include <cstdio>
#include <cstring>
#include <cstdlib>
#include <vector>
#include <map>
#include <cmath>
#include <algorithm>
#include <queue>
#include <utility>
#define fr(a,b,c) for(int a = b; a < c; a++)
#define rp(a,b) fr(a,0,b)
#define cl(a,b) memset(a,b,sizeof a)
using namespace std;
typedef pair<int,int> pii;

char g[1000];
int sz;
bool p[1000], pd[1000];

int can[1000], canSz;
int nm[1000], k;
int id[1000], ids;

/*void gera() {
	pd[0] = 0;
	fr(i,1,41) {
		pd[i] = 0;
		rp(j,k) if (i >= nm[j] && !pd[i-nm[j]]) {
			pd[i] = 1;
			break;
		}
		printf("%c", pd[i]?'W':'L');
	}
	puts("");
}*/

bool test(int mask) {
	pd[0] = 0;
	fr(i,1,sz) {
		pd[i] = 0;
		rp(j,k) if (i >= nm[j] && !pd[i-nm[j]]) {
			pd[i] = 1;
			break;
		}
		if (!pd[i]) {
			rp(j,ids) if (i >= id[j] && ((mask>>j)&1) && !pd[i-id[j]]) {
				pd[i] = 1;
				break;
			}
		}
		if (pd[i] != p[i]) return 0;
	}
	return 1;
}

int getMin(int a, int b) {
	rp(i,ids) if (((a>>i)&1) != ((b>>i)&1)) return ((a>>i)&1) ? a : b;
	return a;
}

int main() {
	int T, cas = 1; scanf("%d", &T);
	while (T--) {
		scanf("%s", g);
		sz = strlen(g);
		p[0] = 0;
		rp(i,sz) p[i+1] = (g[i]=='W');
		sz++;
		printf("Case %d:", cas++);
		canSz = k = ids = 0;
		fr(i,1,min(sz,21)) {
			if (p[i]) {
				rp(j,canSz) if (!p[i-can[j]]) {
					id[ids++] = i;
					goto thisCan;
				}
				nm[k++] = i;
				thisCan:;
				can[canSz++] = i;
			}
		}
		int LIM = (1<<ids);
		int anscnt = 100000, ansmsk = 0;
		rp(i,LIM) { 
			if (__builtin_popcount(i) < anscnt) {
				if (test(i)) {
					anscnt = __builtin_popcount(i);
					ansmsk = i;
				}
			} else if (__builtin_popcount(i) == anscnt) {
				if (test(i)) ansmsk = getMin(ansmsk,i);
			}
		}
		rp(j,ids) if ((ansmsk>>j)&1) nm[k++] = id[j];
		if (k == 0) nm[k++] = sz;
		sort(nm,nm+k);
		rp(i,k) printf(" %d", nm[i]);
		puts("");
	}
	return 0;
}