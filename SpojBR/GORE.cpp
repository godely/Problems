#include <cstdio>
#include <cstdlib>
#include <algorithm>
#include <vector>
#include <cmath>
#include <map>
#include <set>
#include <iostream>
#include <cstring>
using namespace std; 
#define fr(a,b,c) for (int a = b; a < c; a++) 
#define rp(a,b) fr(a,0,b) 
#define CL(a,b) memset((a),(b),sizeof (a))
#define MP make_pair
#define maxn 410000
#define OFF 200001
#define F first
#define S second
typedef long long ll;
typedef pair<int,int> pii;
#define LSOne(x) (x&(-x))

int T, N, D;
int x, y, X[maxn];
pair<pii,int> v[maxn];
int ans[maxn];

int bit[maxn];
int get(int p) {
	int sum = 0;
	p+=OFF;
	if (p < 0) return 0;
	if (p >= maxn) p = maxn-1;
	for (; p > 0; p -= LSOne(p)) sum += bit[p];
	return sum;
}

void chg(int p, int v) {
	p+=OFF;
	if (p < 0) return;
	for (; p < maxn; p += LSOne(p)) bit[p]+=v;
}

int main() {
	int T; scanf("%d", &T);
	while (T--) {
		scanf("%d%d", &N, &D);
		rp(i,N) {
			scanf("%d%d", &x, &y);
			v[i] = MP(MP(x - y, x + y), i);
			X[i] = x - y;
		}
		sort(v,v+N);
		sort(X,X+N);

		int a = 0, b = N;
		CL(bit,0);
		rp(i,N) {
			if (v[i].F.F < X[0] + D) chg(v[i].F.S,1);
			else {
				b = i;
				break;
			}
		}

		int M = unique(X,X+N) - X;
		int c = 0;
		rp(i,M) {
			for (; a < N && v[a].F.F < X[i]-D; a++) chg(v[a].F.S,-1);
			for (; b < N && v[b].F.F <= X[i]+D; b++) chg(v[b].F.S,1);
			for (; c < N && v[c].F.F == X[i]; c++) {
				ans[v[c].S] = get(v[c].F.S+D) - get(v[c].F.S-D-1) - 1;
			}
		}
		printf("%d", ans[0]);
		fr(i,1,N) printf(" %d", ans[i]);
		puts("");
	}
}