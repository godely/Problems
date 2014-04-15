#include <cstdio>
#include <cstring>
#include <cstdlib>
#include <vector>
#include <map>
#include <cmath>
#include <algorithm>
#define fr(a,b,c) for(int a = b; a < c; a++)
#define rp(a,b) fr(a,0,b)
#define cl(a,b) memset(a,b,sizeof a)
using namespace std;
typedef unsigned long long ull;

int N, q;
int x;
bool pd[1010];

int main() {
    int T;
	scanf("%d", &T);
	while (T--) {
	    cl(pd,0);
		scanf("%d%d", &N, &q);
		pd[0] = 1;
		rp(i,q) {
			scanf("%d", &x);
			for (int i = N; i >= x; i--) {
				pd[i] |= pd[i-x];
			}
		}
		
		if (pd[N]) puts("YES");
		else puts("NO");
	}
	return 0;
}