//by stor
#include <cstdio>
#include <map>
#include <queue>
#include <cstdlib>
#include <cstring>
#include <cmath>
#include <algorithm>
#define inf 0x3f3f3f3f
#define fr(a,b,c) for(int a = b; a < c; a++)
#define rp(a,b) fr(a,0,b)
#define X first
#define Y second

using namespace std;

long long M;
long long dp[100010];
int calc[100010], passo=0;

/*long long solve(int n) {
    if (n == 1) return 1;
    if (calc[n] == passo) return dp[n];
    calc[n] = passo;
    //printf("%d\n", n);
    //printf("%d %d\n", ind, rest);
    return dp[n] = (n&1)?solve(n-1)%M:(solve(n-1)+solve(n/2))%M;
}*/

int main() {
    int cas = 1;
    int T, K;
    scanf("%d", &T);
    while (T--) {
        passo++;
        scanf("%d %lld", &K, &M);

        dp[1] = 1;
        fr(i,2,K+1) dp[i] = (i&1)? dp[i-1] : (dp[i-1] + dp[i/2])%M;
        printf("Case %d: %lld\n", cas++, dp[K]);
    }
    return 0;
}
