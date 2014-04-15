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

int main() {
	int e, f, c;
	int T; scanf("%d", &T);
	while (T--) {
		scanf("%d%d%d", &e, &f, &c);
		e+=f;
		int ans = 0;
		while (e >= c) {
			ans += e/c;
			e = e/c + e%c;
		}
		printf("%d\n", ans);
	}
}