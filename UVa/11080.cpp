#include <cstdio>
#include <algorithm>
#include <cstdlib>
#include <cmath>
#include <map>
#include <vector>
#include <cstring>
#define fr(a,b,c) for(int a=b; a<c; a++)
#define rp(a,b) fr(a,0,b)
#define inf 0x3f3f3f3f

using namespace std;

int adj[222][222], size[222];
int mark[222];
int t;

bool dfs(int ind, int color) {
    t++;
    mark[ind]=color;
    int res;
    rp(i,size[ind]) {
        if (!mark[adj[ind][i]]) {
            if (!dfs(adj[ind][i], color^1)) return 0;
        } else if (mark[adj[ind][i]] == color) return 0;
    }
    return 1;
}

int main() {
    int T, N, M, a, b, res;
    scanf("%d", &T);
    while (T--) {
        memset(size, 0, sizeof size);
        scanf("%d%d", &N, &M);
        rp(i,M) scanf("%d%d",&a,&b), adj[a][size[a]++]=b, adj[b][size[b]++]=a;
        memset(mark,0,sizeof mark);
        res = 0;
        rp(i,N) {
            if (!mark[i]) {
                t = 0;
                if (!dfs(i,2)) {
                    printf("-1\n");
                    goto lol;
                } else res += max(1,t/2);
            }
        }
        printf("%d\n", res);
        lol:;
    }
    return 0;
}
