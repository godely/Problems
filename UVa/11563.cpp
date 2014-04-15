#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <algorithm>
#include <vector>
#include <iostream>
#include <map>
#include <utility>
#include <iostream>
#include <set>
#define mp make_pair
using namespace std;
#define fr(a,b,c) for(int a = b; a < c; a++)
#define rp(a,b) fr(a,0,b)
#define cl(a,b) memset(a,b,sizeof a)
#define mp make_pair
typedef long long ll;
#define maxn 100100

int x[maxn], next[maxn], p[maxn], cached[maxn];
multiset<int> pq;
multiset<int>::iterator cur;

int main() {
	int c, n, a;
	while (scanf("%d%d%d", &c, &n, &a) == 3) {
		rp(i,a) scanf("%d", &x[i]);
		x[a] = n;
		rp(i,n) p[i] = a;
		cl(cached,0);
		pq.clear();
		for (int i = a-1; i >= 0; i--) {
			next[i] = p[x[i]];
			p[x[i]] = i;
		}
		int cnt = 0, res = 0;
		rp(i,a) {
			//printf(">>> %d %d\n", i, x[i]);
			if (cached[x[i]]) {
				//printf("%d: Atualizando %d, era %d, agora eh %d\n---\n", x[i], x[i], *pq.begin(), next[i]);
				pq.erase(pq.begin());
				pq.insert(next[i]);
			} else {
				if (cnt < c) {
					//printf("%d: Inserindo %d, vai ser %d\n---\n", x[i], x[i], next[i]);
					cached[x[i]] = 1;
					pq.insert(next[i]);
					cnt++; res++;
				} else {
					cur = pq.end(); --cur;
					//printf("%d: Removendo %d, era %d (%d)\n---\n",x[i], x[*cur], *cur, (int)pq.size());
					cached[x[*cur]] = 0;
					pq.erase(cur);
					cached[x[i]] = 1;
					pq.insert(next[i]);
					//printf("%d: Inserindo %d, vai ser %d\n---\n", x[i], x[i], next[i]);
					res++;
				}
			}
		}
		printf("%d\n", res);
	}
	return 0;
}