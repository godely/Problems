#include <cstdio>
#include <cstdlib>
#include <algorithm>
#include <vector>
#include <cmath>
#include <map>
#include <set>
#include <iostream>
#include <cstring>
using namespace std; 
#define fr(a,b,c) for (int a = b; a < c; a++) 
#define rp(a,b) fr(a,0,b) 
#define CL(a,b) memset((a),(b),sizeof (a)) 
#define MAXN 100000 
#define MAXM 1000000 
typedef long long ll; 
  
#define add(a,b) to[z] = b, ant[z] = adj[a], adj[a] = z++ 
int to[MAXM], ant[MAXM], adj[MAXN], tam[MAXN]; 
int z; 
  
  
int pai[MAXN], rd[MAXN][2]; 
  
int dfsbranch(int x) { 
    int a = 0, b = 0, c = 0; 
    for (int i = adj[x]; ~i; i = ant[i]) { 
        if (pai[to[i]] == -1) { 
            pai[to[i]] = x; 
            int aux = dfsbranch(to[i]); 
            if (aux > a) swap(c,b), swap(b,a), a = aux; 
            else if (aux > b) swap(c,b), b = aux;
            else if (aux > c) c = aux;
        } 
    } 
    rd[x][0] = a;
    rd[x][1] = b;
    rd[x][2] = c;
    return 1 + reta;
} 
  

int dp
int go(int x) {
    int ans = rd[x][0] + rd[x][1];

    for (int i = adj[x]; ~i; i = ant[i]) if (to[i] != pai[x]) {
        int l = go(to[i]);
        ans = max(ans,l);

        int r = max(1+rd[to[i]][0], l);
    }

    return ans;
} 
  
void maxBranches(int n) { 
    dfsbranch(0); go(0); 
    rp(i,n) tam[i] = dp[i][0]; 
} 
  
int main() { 
    int n, a, b; 
    while (scanf("%d", &n) == 1) {
        CL(adj,-1); z = 0; 
        rp(i,n-1) { 
            scanf("%d%d", &a, &b); 
            add(a-1,b-1); add(b-1,a-1); 
        } 
        CL(pai,-1); 
        CL(dp,-1); 
        pai[0] = -2; 
        maxBranches(n); 
    }
}