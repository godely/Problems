#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <cmath>
#include <algorithm>
#define inf 0x3f3f3f3f
#define fr(a,b,c) for(int a = b; a < c; a++)
#define rp(a,b) fr(a,0,b)

using namespace std;

int C[3][1111];
int n, m, x, y;

int pd[1111][3];

int solve(int ind, bool cor) {
    if (ind >= m) return 0;
    if (~pd[ind][cor]) return pd[ind][cor];

    int custo = 0;
    for (int i=ind; i < ind+x-1 && i < m; i++) {
        custo+=C[cor][i];
    }
    //printf("%d %d %d\n", ind, cor, custo);
    int res=inf;
    for (int i=ind+x-1; i < ind+y && i < m; i++) {
        custo += C[cor][i];
        res = min(res, custo+solve(i+1, cor^1));
    }
    return pd[ind][cor] = res;
}

char str[1111];
int main() {
    scanf("%d%d%d%d", &n, &m, &x, &y);
    rp(i,n) {
        scanf("%s", str);
        rp(j,m) {
            if (str[j]=='#') C[0][j]++;
            else C[1][j]++;
        }
    }
    //rp(i,m) printf("Coluna 1 custo p->b: %d / custo b->p: %d\n", C[0][i], C[1][i]);

    memset(pd,-1,sizeof pd);
    printf("%d\n", min(solve(0,0), solve(0,1)));
}
