#include <cstdio>
#include <algorithm>
#include <cstring>
#include <utility>
#include <vector>
#include <queue>
#include <stack>
#include <map>
#include <iostream>
#include <set>
#include <cmath>
#include <cassert>

using namespace std;

#define db(x) cout << #x " == " << x << endl
//#define _ << ", " <<
#define fr(a,b,c) for( int a = b ; a < c ; ++a )
#define rp(a,b) fr(a,0,b)
#define cl(a,b) memset(a,b,sizeof a)
typedef long long ll;
typedef unsigned long long ull;
typedef pair<int,int> pii;
typedef vector<pair<int,int> > vpii;
#define F first
#define S second
#define MP make_pair
#define PB push_back
#define y1 Y1
#define INF 0x3f3f3f3f
#define LINF 0x3f3f3f3f3f3f3f3fLL
#define ULMAX 0xffffffffffffffffULL

#define MAXN 40
#define add(a,b,c,d) to[z] = b, cost[z] = c, id[z] = d, ant[z] = adj[a], adj[a] = z++
int to[MAXN], cost[MAXN], id[MAXN], ant[MAXN], adj[MAXN], z;

double C[40][40];
int M[40][40];
void calc(int f, int u, int x = -1, int mask = 0, int len = 0) {
    for (int v = adj[u]; ~v; v = ant[v]) {
        if (to[v] != x) calc(f,to[v],u,mask|id[v],len+cost[v]);
    }
    if (f != u) {
        C[f][u] = double(len)/__builtin_popcount(mask);
        M[f][u] = mask;
    } else {
        C[f][u] = 0;
        M[f][u] = 0;
    }
    //printf("%d to %d: C = %lf, M = %d\n", f, u, C[f][u], M[f][u]);
}

int n;
double dp[1<<16];
int mark[1<<16], passo;
int FULL;
double go(int mask) {
    double &pd = dp[mask];
    if (mark[mask] == passo) return pd;
    mark[mask] = passo;
    
    if (mask == FULL) return pd = 0;
    
    double ret = INF;
    fr(i,0,n) fr(j,i+1,n) {
        if (!(mask&M[i][j])) {
            ret = min(ret, C[i][j] + go(mask|M[i][j]));
        }
    }
    return pd = ret;
}

int main() {
    int T;
    int a, b, c;
    passo = 0;
    while (scanf("%d", &n) == 1 && n > 0) {
        cl(adj,-1); z = 0;
        rp(i,n-1) {
            scanf("%d%d%d", &a, &b, &c);
            add(a,b,c,1<<i);
            add(b,a,c,1<<i);
        }
        FULL = (1<<(n-1))-1;
        for (int i = 0; i < n; i++) calc(i,i);
        passo++;
        printf("%.4lf\n", go(0));
    }
    return 0;
}