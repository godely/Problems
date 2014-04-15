#include <cstdio>
#include <queue>
#include <cstring>
#include <algorithm>
#include <cstdlib>
#include <cmath>
#include <map>
#include <vector>
#include <iostream>
#define fr(a,b,c) for(int a=b; a<c; a++)
#define rp(a,b) fr(a,0,b)
#define inf 0x3f3f3f3f

using namespace std;

int adj[111][111], size[111];
char str[1111111];
int mark[1111111], passo = 0;
int vis[1111111], pas=0;
int res[111], sRes;
int cant[111], cantPas=0, glob, yep;

int dfs(int ind) {
    if (vis[ind]==pas) {
        if (ind==glob) yep=1;
        return 0;
    }
    vis[ind]=pas;
    int r = 1;
    rp(i,size[ind]) {
        r+=dfs(adj[ind][i]);
    }
    return r;
}

int main() {
    int T, k, from, to;
    char *pt;
    map<string, int> mapa;
    vector<string> vec;
    while (scanf("%d\n", &T) == 1 && T > 0) {
        cantPas++;
        mapa.clear();
        vec.clear();
        k = 1;
        memset(size,0,sizeof size);
        rp(i,T) {
            passo++;
            gets(str);
            pt = strtok(str, " ");
            if (mapa[pt]==0) mapa[pt] = k++, vec.push_back(pt);
            from = mapa[pt];
            while ((pt = strtok(NULL, " "))) {
                if (mapa[pt]==0) mapa[pt] = k++, vec.push_back(pt);
                to = mapa[pt];
                if (mark[to]==passo) continue;
                mark[to]=passo;
                adj[from][size[from]++]=to;
                //printf("%d %d\n", from, to);
            }
        }
        int MIN = inf, r;
        sRes = 0;
        fr(i,1,k) {
            if (cant[i] != cantPas) {
                pas++;
                yep = 0;
                glob = i;
                r = dfs(i);
                if (yep) fr(j,1,k) if(vis[j]==pas) cant[j]=cantPas;
                //printf("%d\n", r);
                if (r <= MIN) {
                    if (r < MIN) sRes = 0;
                    MIN = r;
                    fr(j,1,k) if (vis[j]==pas) res[sRes++] = j-1;
                }
            }
        }
        printf("%d\n", sRes);
        priority_queue<string, vector<string>, greater<string> > fila;
        fr(i,0,sRes) fila.push(vec[res[i]]);
        printf("%s", fila.top().c_str());
        fila.pop();
        while (!fila.empty()) {
            printf(" %s", fila.top().c_str());
            fila.pop();
        }
        printf("\n");
    }
    return 0;
}
