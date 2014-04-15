#include <cstdlib>
#include <cstdio>
#include <iostream>
#include <cstring>
#include <cassert>
#include <algorithm>
#include <cmath>
#include <queue>
#include <stack>
#include <vector>
#include <list>
#include <set>
#include <map>
#include <cassert>
#include <ctime>
 
#define iter(c) __typeof((c).begin())
#define Tr(a,b) for(iter(b) a = (b).begin(); a != (b).end(); ++a)
#define Fr(a,b,c) for(int a = b; a < c; ++a)
#define Rp(a,c) Fr(a,0,c)
#define PB push_back
#define MP make_pair
#define F first
#define S second
#define oo 0x3F3F3F3F
 
#define dbg if(0)
 
using namespace std;
 
typedef pair<int,int> pii;
typedef long long ll;
typedef unsigned long long ull;
typedef unsigned long long rash;
 
#define MAXN 5050
#define MAXM 20500
 
int m;
int adj[MAXN], nodes;
int to[MAXM], w[MAXM], ant[MAXM], edges;
 
void add(int x, int y, int c) {
    to[edges] = y, w[edges] = c, ant[edges] = adj[x]; adj[x] = edges++;
}
 
int dad[MAXN], edge[MAXN], cycle[MAXN], num[MAXN], tempo;
bool mark[MAXM], bridge[MAXM];
void go(int u) {
        dbg printf(" go %d\n", u);
        num[u] = tempo++;
        for(int i = adj[u]; ~i; i = ant[i]) if(!mark[i]) {
                mark[i] = mark[i ^ 1] = true;
                edge[u] = i;
                int v = to[i];
                if(num[v] == -1) {
                        dad[v] = u;
                        dbg printf("dad[%d] %d\n", v, u);
                        go(v);
                } else {
                        dbg printf("(current %d, next (grand father %d, dad (sinbling) %d)\n", u, v, dad[u]);
                        bridge[ edge[dad[u]] ] = bridge[ edge[dad[u]] ^ 1] = true;
                        cycle[v] = edge[dad[u]];
                        dad[u] = v;
                }
        }
}
 
int pd[MAXN][3];
int rec(int x, int y) {
        if(~pd[x][y]) return pd[x][y];
        pd[x][y] = oo;
        
        if(cycle[x] == -1) {
                if(y < 2) {
                        int &resp = pd[x][y];
                        int r = 0, s = 0;
                        for(int i = adj[x]; ~i; i = ant[i]) if(!bridge[i] && x == dad[to[i]]) {
                                r += min(w[i] + rec(to[i], 0), rec(to[i], y + 1));
                                s += min(w[i] + rec(to[i], 0), rec(to[i], 1));
                        }
                        
                        resp = min(resp, r);
                        for(int i = adj[x]; ~i; i = ant[i]) if(!bridge[i] && x == dad[to[i]]) {
                                int a = w[i] + rec(to[i], 0);
                                int b = min(a, rec(to[i], 1));
                                resp = min(resp, s - b + a);
                        }
                        
                } else {
                        int zero = 0, &one = pd[x][y];
                        for(int i = adj[x]; ~i; i = ant[i]) if(!bridge[i] && x == dad[to[i]]) {
                                int a = w[i] + rec(to[i], 0);
                                int b = min(a, rec(to[i], 1));
                                
                                one = min(one + b, zero + a);
                                zero += b;
                        }
                }
        } else {
                dbg printf("  node %d at cycle. Bridge %d\n", x, cycle[x]);
                int ii = -1, jj = -1;
                for(int i = adj[x]; ~i; i = ant[i]) if(x == dad[to[i]]) {
                        if(ii == -1) ii = i;
                        else {
                                assert(jj == -1);
                                jj = i;
                        }
                }
                
                int &resp = pd[x][y];
                resp = min(resp, w[ii] + rec(to[ii], 0) + rec(to[jj], 1)); //left, not mid, not right (A B)
                resp = min(resp, w[jj] + rec(to[ii], 1) + rec(to[jj], 0)); //not left, not mid, right (B A)
                if(y != 2) resp = min(resp, w[cycle[x]] + rec(to[ii], 0) + rec(to[jj], 0)); //not left, mid, not right (A A)
                resp = min(resp, w[ii] + w[jj] + rec(to[ii], 0) + rec(to[jj], 0)); //left, not mid, right (A A)
                resp = min(resp, w[ii] + w[cycle[x]] + rec(to[ii], 0) + rec(to[jj], 0)); //left, mid, not right (A A)
                resp = min(resp, w[jj] + w[cycle[x]] + rec(to[ii], 0) + rec(to[jj], 0)); //not left, mid, right (A A)
                if(y == 0) {
                        resp = min(resp, rec(to[ii], 1) + rec(to[jj], 2));
                        resp = min(resp, rec(to[ii], 2) + rec(to[jj], 1));
                }
                
                if(y == 1) resp = min(resp, rec(to[ii], 2) + rec(to[jj], 2));
        }
        
        dbg printf("pd[%d][%d] %d\n", x, y, pd[x][y]);
        return pd[x][y];
}
 
int main() {
        int t, caso = 0; scanf("%d", &t);
        while(t--) {
                scanf("%d%d", &nodes, &m);
                
                Rp(i,nodes+1) adj[i] = -1; edges = 0;
                Rp(_,m) {
                        int a, b, c; scanf("%d%d%d", &a, &b, &c), --a, --b;
                        add(a, b, c), add(b, a, c);
                }
                
                tempo = 0;
                Rp(i,nodes) dad[i] = -1, num[i] = -1, cycle[i] = -1;
                dad[0] = 0;
                Rp(i,edges) mark[i] = false, bridge[i] = false;
                go(0);
                
                dbg {           
                        Rp(i,nodes) printf("%2d: dad %d, cycle %2d, num %d, adj %d\n", i, dad[i], cycle[i], num[i], adj[i]); puts("");
                        Rp(i,edges) printf("%2d: to %d, w %d, ant %2d, mark %d, bridge %d\n", i, to[i], w[i], ant[i], mark[i], bridge[i]); puts("");
                }
                
                Rp(i,nodes) Rp(j,3) pd[i][j] = -1;
                printf("Case %d: %d\n", ++caso, rec(0,1));
        }
        
        return 0;
}