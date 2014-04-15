#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <cmath>
#include <algorithm>
#define pii pair<int,int>
#define fr(a,b,c) for(int a = b; a < c; a++)
#define rp(a,b) fr(a,0,b)

using namespace std;

int vet[11111], n, k, dp[11111][111], calc[11111][111], passo=0;

int solve(int ind, int mod) {
    if (ind>=n) return !mod;
    if (calc[ind][mod]==passo) return dp[ind][mod];
    calc[ind][mod] = passo;

    return dp[ind][mod] = solve(ind+1, ((mod+vet[ind])%k+k)%k) || solve(ind+1, ((mod-vet[ind])%k+k)%k);
}

int main() {
    int T;
    scanf("%d", &T);
    while (T--) {
        scanf("%d%d", &n, &k);
        rp(i,n) scanf("%d", &vet[i]);
        passo++;
        if(solve(0,0)) printf("Divisible\n");
        else printf("Not divisible\n");
    }
    return 0;
}
