#include <cstdio>
#include <algorithm>
#include <cstdlib>
#include <cmath>
#include <map>
#include <vector>
#define fr(a,b,c) for(int a=b; a<c; a++)
#define rp(a,b) fr(a,0,b)

using namespace std;

struct edge {
    int x, y, cost;
    edge(){}
    edge(int x, int y, int cost):x(x),y(y),cost(cost){}
    bool operator<(const edge &lhs) const {
        return cost < lhs.cost;
    }
} e[111111];

int rep[11111];

int findset(int a) {
    if (a==rep[a]) return a;
    return rep[a]=findset(rep[a]);
}

bool link(int a, int b) {
    a=findset(a), b=findset(b);
    if (a==b) return 0;
    rep[a]=b;
    return 1;
}

int main() {
    int n, m, c, cost, t, cas=1;
    while (scanf("%d%d", &n, &m) == 2 && n > 0) {
        rp(i,n) rep[i]=i;
        rp(i,m) scanf("%d%d%d", &e[i].x, &e[i].y, &e[i].cost);
        sort(e,e+m);
        bool ok = 0;
        rp(i,m) {
            if (!link(e[i].x,e[i].y))   if (ok) printf(" %d", e[i].cost);
                                        else printf("%d", e[i].cost), ok = 1;
        }
        if (!ok) printf("forest");
        printf("\n");
    }
    return 0;
}
