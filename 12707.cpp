#include <bits/stdc++.h>
using namespace std;
#define MP make_pair
typedef pair<int,int> pii;
#define MAXN 20100
#define fr(a,b,c) for(int a = b; a < c; a++)
#define rp(a,b) fr(a,0,b)
#define F first
#define S second

pii v[MAXN];
multiset<int> s;
multiset<int>::iterator it;

int main() {
	int T, N, a, b;
	int cas = 1;
	scanf("%d", &T);
	while (T--) {
		s.clear();
		scanf("%d", &N);
		rp(i,N) {
			scanf("%d%d", &a, &b);
			v[i] = MP(a,b);
		}
		sort(v,v+N);
		int res = N;
		rp(i,N) {
			int j;
			for (j = i; j < N && v[j].F == v[i].F; j++) {
				it = s.upper_bound(v[j].S);
				if (it != s.end()) {
					res--;
					s.erase(it);
				}
			}
			for (j = i; j < N && v[j].F == v[i].F; j++) s.insert(v[j].S);
			i = j - 1;
		}
		printf("Case %d: %d\n", cas++, res);
	}
}