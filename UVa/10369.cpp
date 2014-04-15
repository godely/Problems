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
    int x, y;
    double cost;
    edge(){}
    edge(int x, int y, double cost):x(x),y(y),cost(cost){}
    bool operator<(const edge &lhs) const {
        return cost < lhs.cost;
    }
} e[251000];
int k;

int rep[511];

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

int x[511], y[511];
double dist(int i, int j) {
    return sqrt((x[i]-x[j])*(x[i]-x[j]) + (y[i]-y[j])*(y[i]-y[j]));
}

int main() {
    int T, n, m, t;
    double cost;
    scanf("%d", &T);
    while (T--) {
        scanf("%d%d", &m, &n);
        rp(i,n) rep[i]=i;
        rp(i,n) scanf("%d%d", &x[i], &y[i]);
        k = 0;
        fr(i,0,n) fr(j,i+1,n) {
            e[k++] = edge(i,j,dist(i,j));
        }
        sort(e,e+k);
        t = 0;
        rp(i,k) {
            if (link(e[i].x,e[i].y)) {
                t++;
                if (t == n-m) {
                    cost = e[i].cost;
                    break;
                }
            }
        }
        printf("%.2lf\n", cost);
    }
    return 0;
}
