#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <cmath>
#include <vector>
#include <list>
#include <algorithm>
#define fr(a,b,c) for(int a=b; a<c; a++)
#define rp(a,b) fr(a,0,b)
#define pb push_back
#define mp make_pair
#define pii pair<int,int>
using namespace std;

int n, m;
vector<pii> adj[11111];
list<int> cyc;

void EulerCycle(list<int>::iterator it, int a) {
    int b, t;
    rp(i,adj[a].size()) {
        if (adj[a][i].first>0) {
            b = adj[a][i].second;
            t = adj[a][i].first;
            rp(j,adj[b].size()) {
                if (t==adj[b][j].first) {
                    adj[a][i].first = adj[b][j].first = 0;
                }
            }
            EulerCycle(cyc.insert(it,t), b);
        }
    }
}

int main() {
    list<int> teste;
    int a, b, c, n, start;
    while (scanf("%d%d", &a, &b) == 2 && a > 0) {
        fr(i,1,50) adj[i].clear();
        start = min(a,b);
        n = 0;
        do {
            scanf("%d",&c);
            n = max(n,max(a,b));
            adj[a].pb(mp(c,b));
            adj[b].pb(mp(c,a));
        } while (scanf("%d%d", &a, &b)==2 && a > 0);
        bool ok = 1;
        fr(i,1,n+1) {
            sort(adj[i].begin(),adj[i].end());
            if (adj[i].size()&1) {
                ok = 0;
                break;
            }
        }
        if (!ok) printf("Round trip does not exist.\n\n");
        else {
            cyc.clear();
            EulerCycle(cyc.begin(),start);
            reverse(cyc.begin(), cyc.end());
            for (list<int>::iterator it = cyc.begin(); it != cyc.end(); it++) {
                if (it!=cyc.begin()) printf(" ");
                printf("%d", *it);
            }
            printf("\n\n");
        }
    }
    return 0;
}
