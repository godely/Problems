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

int T, n, P, Q, x[1000];
int main() {
    int cas = 1;
    scanf("%d", &T);
    while (T--) {
        scanf("%d%d%d", &n, &P, &Q);
        rp(i,n) scanf("%d", &x[i]);
        sort(x,x+n);
        int cur = 0, ans = 0;
        rp(i,min(P,n)) {
            if (cur+x[i] <= Q) cur+=x[i], ans++;
            else break;
        }
        printf("Case %d: %d\n", cas++, ans);
    }
    return 0;
}