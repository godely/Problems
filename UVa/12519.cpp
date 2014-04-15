#include <bits/stdc++.h>
using namespace std;
#define fr(a,b,c) for(int a=b;a<c;a++)
#define rp(a,b) fr(a,0,b)
#define cl(a,b) memset((a),(b),sizeof(a))
#define MAXN 111
#define mp make_pair
#define f first
#define s second

int N, M;
int COST[111][111];
void ff() { for (int k = 1; k <= N; k++) for (int i = 1; i <= N; i++) for (int j = 1; j <= N; j++) COST[i][j] = min(COST[i][j], COST[i][k] + COST[k][j]); }

int main() {
    int u, v, c;
    while (scanf("%d%d", &N, &M) == 2 && N > 0) {
        memset(COST, 0x3f, sizeof COST);
        rp(i,M) {
            scanf("%d%d%d", &u, &v, &c);
            COST[u][v] = c;
            COST[v][u] = -c;
        }
        ff();
        if (COST[1][1] < 0) printf("Y\n");
        else printf("N\n");
    }
    return 0;
}