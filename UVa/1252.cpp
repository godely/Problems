#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <cmath>
#include <algorithm>
#define inf 11111111
#define fr(a,b,c) for(int a=b;a<c;a++)
#define rp(a,b) fr(a,0,b)
#define cl(a,b) memset((a),(b),sizeof(a))

using namespace std;

int g[200], memo[1<<11], memoP=0;
int m, n;
int dp[1<<11][1<<11], calc[1<<11][1<<11], passo=0;

int solve(int q, int p) {
    if (calc[q][p]==passo) return dp[q][p];
    calc[q][p]=passo;

    int k=0;
    rp(i,n) {
        if ((q&g[i]) == p) k++;
        //printf("%d %d %d %d\n", q&g[i], p, (q&g[i])==p, k);
    }
    if (k <= 1) {
        k=0;
        //printf("xD %d %d\n", q, p);
        rp(i,m) if(q&(1<<i)) k++;
        return dp[q][p]=k;
    }

    int d, res=inf;
    rp(i,m) {
        d = 1<<i;
        if (!(q&d)) {
            res=min(res,max(solve(q|d, p),solve(q|d, p|d)));
        }
    }
    return dp[q][p]=res;
}

char str[20];
int main() {
    while (scanf("%d%d", &m, &n) == 2 && m > 0) {
        rp(i,n) {
            scanf("%s", &str);
            g[i]=strtol(str,NULL,2);
            //printf("%d\n", g[i]);
        }

        passo++;
        printf("%d\n", solve(0,0));
    }
    return 0;
}