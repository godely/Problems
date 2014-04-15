//stor
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <cmath>
#include <map>
#include <algorithm>
#include <queue>
#include <stack>
#define inf 0x3f3f3f3f
#define fr(a,b,c) for(int a=b; a<c; a++)
#define rp(a,b) fr(a,0,b)
#define P 10000

using namespace std;

int N, K;
int dp[2][101][101], calc[2][101][101];
int passo=0;

int solve(int ind, int k, int last) {
    //printf("%d %d %d %d\n", ind, k, last, N);
    if (ind >= N) return k==K;
    if (k > K) return 0;
    if (calc[last][ind][k]==passo) return dp[last][ind][k];
    calc[last][ind][k]=passo;

    return dp[last][ind][k] = solve(ind+1,k+(last==1),1) + solve(ind+1,k,0);
}

int main() {
    int T, CAS=1;
    scanf("%d", &T);
    while (T--) {
        scanf("%d%d%d", &CAS, &N, &K);
        passo++;
        printf("%d %d\n", CAS, solve(0,0,0));
    }
}
