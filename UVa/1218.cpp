#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <cmath>
#include <vector>
#define inf 0xffffff

using namespace std;

int dp[11111][4], calc[11111][4], passo=0;
vector<int> adj[11111];

int solve(int ind, int estado, int from) {
    //printf("%d %d %d\n", ind, estado, from);
    if (adj[ind].size()==1 && from != -1) return (estado==0)?inf:0;
    if (calc[ind][estado]==passo) return dp[ind][estado];
    calc[ind][estado]=passo;

    int res=inf, size=adj[ind].size();
    if (estado==0) { //um filho tem que ser preto
        int temp=inf, sum=0;
        for (int i = 0; i < size; i++) {
            if (adj[ind][i]==from) continue;
            solve(adj[ind][i],1,ind);
        }
        for (int i = 0; i < size; i++) {
            if (adj[ind][i]==from) continue;
            sum+=solve(adj[ind][i],0,ind);
        }
        for (int i = 0; i < size; i++) {
            if (adj[ind][i]==from) continue;
            temp=min(temp,1+dp[adj[ind][i]][1]+sum-dp[adj[ind][i]][0]);
        }
        res=temp;
    } else if (estado==1) { //eh preto
        int temp=0;
        for (int i = 0; i < size; i++) {
            if (adj[ind][i]==from) continue;
            temp+=min(1+solve(adj[ind][i],1,ind), solve(adj[ind][i],2,ind));
        }
        res=temp;
    } else { //eh branco
        int temp=0;
        for (int i = 0; i < size; i++) {
            if (adj[ind][i]==from) continue;
            temp+=solve(adj[ind][i],0,ind);
        }
        res=temp;
    }
    //printf(">%d\n", res);
    return dp[ind][estado]=res;
}

int main() {
    int N,a,b,aff;
    while (scanf("%d", &N)==1) {
        passo++;
        for (int i = 1; i <= N; i++) adj[i].clear();
        for (int i = 1; i < N; i++) {
            scanf("%d%d", &a, &b);
            adj[a].push_back(b);
            adj[b].push_back(a);
        }
        printf("%d\n", min(solve(1,0,-1), 1+solve(1,1,-1)));
        scanf("%d", &aff);
        if (aff==-1) break;
    }
}
