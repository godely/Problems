#include <cstdio>
#include <algorithm>
#include <cstdlib>
#include <cmath>
#include <map>
#include <vector>
#define fr(a,b,c) for(int a=b; a<c; a++)
#define rp(a,b) fr(a,0,b)
#define inf 0x3f3f3f3f

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

int R[111], r, temp;
int main() {
    int T, n, m, c, cost, t, cas=1;
    scanf("%d", &T);
    while (T--) {
        scanf("%d%d", &n, &m);
        rp(i,n) rep[i+1]=i+1;
        rp(i,m) scanf("%d%d%d", &e[i].x, &e[i].y, &e[i].cost);
        sort(e,e+m);
        cost = r = 0;
        rp(i,m) {
            if (link(e[i].x,e[i].y)) {
                cost+=e[i].cost;
                R[r++] = i;
            }
        }
        printf("%d ", cost);
        cost = inf;
        rp(i,r) {
            rp(j,n) rep[j+1]=j+1;
            temp = 0;
            rp(j,m) {
                if (j == R[i]) continue;
                if (link(e[j].x,e[j].y)) {
                    temp+=e[j].cost;
                }
            }
            rp(j,n-1) if (findset(j+1) != findset(j+2)) goto kkk;
            cost = min(cost, temp);
            kkk:;
        }
        printf("%d\n", cost);
    }
    return 0;
}
