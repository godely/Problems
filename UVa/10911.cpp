#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <cmath>
#include <algorithm>
#define inf 0x3f3f3f
#define fr(a,b,c) for(int a=b; a<c; a++)
#define rp(a,b) fr(a,0,b)

using namespace std;

struct PT {
    double x, y;
    PT() {}
    PT(double x, double y) : x(x), y(y) {}
} pts[30];

double dist(PT a, PT b) {
    return sqrt((a.x-b.x)*(a.x-b.x) + (a.y-b.y)*(a.y-b.y));
}

int N;
int calc[1<<16], passo=0;
double dp[1<<16];
double solve(int mask, int aux) {
    if (aux >= N) return 0.0;
    if (calc[mask] == passo) return dp[mask];
    calc[mask] = passo;

    double D = inf;
    fr(i,0,N) {
        if (mask&(1<<i)) continue;
        fr(j,i+1,N) {
            if (mask&(1<<j)) continue;
            //printf("%lf\n", dist(pts[i], pts[j]));
            D = min(D, dist(pts[i], pts[j]) + solve((mask|(1<<i))|(1<<j), aux+2));
        }
    }
    return dp[mask] = D;
}

int main() {
    int cas=1;
    while (scanf("%d", &N) == 1 && N > 0) {
        N*=2;
        rp(i,N) {
            scanf("%*s%lf%lf", &pts[i].x, &pts[i].y);
        }
        passo++;
        printf("Case %d: %.2lf\n", cas++, solve(0,0));
    }
    return 0;
}
