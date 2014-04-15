#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <cmath>
#include <algorithm>
#include <map>
#define fr(a,b,c) for(int a=b; a < c; a++)
#define rp(a,b) fr(a,0,b)
#define inf 0x3f3f3f3f

using namespace std;

int vet[11];

int dp[11][11][111][111], calc[11][11][111][111], passo=0;
int solve(int dig, int rest, int a, int b, int p, int q) {
    if (dig >= 9) {
        if (a!=b) return inf;
        //printf("> %d %d\n", p, q);
        return (max(p,q)*2)-1+(p==q);
    }
    if (calc[dig][a][p][q]==passo) return dp[dig][a][p][q];
    calc[dig][a][p][q]=passo;

    if (rest==0) return dp[dig][a][p][q] = solve(dig+1,vet[dig+1],a,b,p,q);
    //printf("%d %d %d %d %d %d\n", dig, rest, a, b, p, q);
    return dp[dig][a][p][q] = min(solve(dig,rest-1,(a+dig+1)%11, b, p+1, q), solve(dig,rest-1,a,(b+dig+1)%11, p, q+1));
}

int main() {
    int T;
    scanf("%d", &T);
    while (T--) {
        passo++;
        rp(i,9) scanf("%d", &vet[i]);
        int res = solve(0,vet[0],0,0,0,0);
        printf("%d\n", res < inf?res:-1);
    }
    return 0;
}
