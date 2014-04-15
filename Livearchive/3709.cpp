#include <iostream>
#include <cstdio>
#include <vector>
#include <utility>
#include <algorithm>
#include <cstring>
 
#define INF 1000000000
 
#define MAXN 128
#define MAXM 1024
#define MAXS (2+MAXN+MAXM)
 
using namespace std;
 
int gcd(int a, int b)
{
    if (a == 0)
        return b;
    return gcd(b%a, a);
}
 
bool mycmp(const pair <int, int>& p1, const pair <int, int>& p2)
{
    return p1.first*p2.second < p1.second*p2.first;
}
 
int n, m;
vector <int> guys;
vector <pair <int, int> > edges;
 
int mark[MAXS];
vector <int> adj[MAXS];
int caps[MAXS][MAXS];
 
void dfs(int v)
{
    mark[v] = 1;
 
    if (1 <= v && v < 1+n)
        guys.push_back(v-1);
 
    for (int i = 0; i < (int)adj[v].size(); i++) {
        int v2 = adj[v][i];
        if (caps[v][v2] > 0 && !mark[v2])
            dfs(v2);
    }
}
 
int mindist[MAXS], queue[MAXS];
int augment(int v, int sink, int maxf)
{
    if (v == sink)
        return maxf;
 
    for (int i = 0; i < (int)adj[v].size(); i++) {
        int v2 = adj[v][i];
        if (mindist[v2] == mindist[v] + 1 && caps[v][v2] > 0) {
            int x = augment(v2, sink, min(maxf, caps[v][v2]));
            if (x) {
                caps[v][v2] -= x;
                caps[v2][v] += x;
                return x;
            }
        }
    }
 
    return 0;
}
 
int maxflow(int source, int sink)
{
    int flow = 0;
 
    do {
        int qs = 0, qe = 0;
 
        fill(mindist, mindist+MAXS, INF);
 
        mindist[source] = 0;
        queue[qe++] = source;
         
        while (qs < qe && mindist[sink] == INF) {
            int v = queue[qs++];
            for (int i = 0; i < adj[v].size(); i++) {
                int v2 = adj[v][i];
                if (caps[v][v2] > 0 && mindist[v2] > mindist[v] + 1) {
                    mindist[v2] = mindist[v] + 1;
                    queue[qe++] = v2;
                }
            }
        }
 
        if (mindist[sink] == INF)
            break;
 
        int temp = 0;
        int x;
        while (x = augment(source, sink, INF), x) {
            flow += x;
            temp += x;
        }
    } while (1);
         
    return flow;
}
 
 
int solve(int Ka, int Kb)
{
    memset(caps, 0, sizeof(caps));
 
    if (Ka == 0) {
        guys.clear();
        guys.push_back(0);
        return 1;
    }
 
    Ka *= 100, Kb *= 100;
    Ka -= 1;
 
    for (int i = 0; i < 2+n+m; i++)
        adj[i].clear();
 
    for (int i = 0; i < (int)edges.size(); i++) {
        int a = edges[i].first, b = edges[i].second;
         
        caps[0][1+n+i] = Kb;
        caps[1+n+i][0] = Kb;
        adj[0].push_back(1+n+i);
        adj[1+n+i].push_back(0);
 
        caps[1+n+i][1+a] = Kb;
        caps[1+a][1+n+i] = Kb;
        adj[1+a].push_back(1+n+i);
        adj[1+n+i].push_back(1+a);
 
        caps[1+n+i][1+b] = Kb;
        caps[1+b][1+n+i] = Kb;
        adj[1+b].push_back(1+n+i);
        adj[1+n+i].push_back(1+b);
    }
 
    for (int i = 0; i < n; i++) {
        caps[1+i][1+n+m] = Ka;
        caps[1+n+m][1+i] = Ka;
        adj[1+i].push_back(1+n+m);
        adj[1+n+m].push_back(1+i);
    }
 
    int flow = maxflow(0, 1+n+m);
 
    if (flow-m*Kb < 0) {
        memset(mark, 0, sizeof(mark));
        guys.clear();
        dfs(0);
        if (guys.empty())
            return 0;
 
        return 1;
    }
 
    return 0;
}
 
int main(int argc, char ** argv)
{
    int firstest = 1;
     
    while (scanf("%d %d", &n, &m) == 2) {
        edges.clear();
 
        for (int i = 0; i < m; i++) {
            int a, b;
            scanf("%d %d", &a, &b);
            a--, b--;
 
            edges.push_back(make_pair(a, b));
        }
 
        vector <pair <int, int > > Ks;
 
        for (int j = 1; j <= n; j++)
            for (int i = 0; i <= j*(j-1)/2; i++)
                if (gcd(i, j) == 1)
                    Ks.push_back(make_pair(i, j));
 
        sort(Ks.begin(), Ks.end(), mycmp);
 
        guys.clear();
 
        int left = 0, right = Ks.size()-1;
 
        while (left < right) {
            int me = (left+right+1)/2;
 
            if (solve(Ks[me].first, Ks[me].second))
                left = me;
            else
                right = me-1;
        }
 
        solve(Ks[left].first, Ks[left].second);
 
        if (!firstest)
            printf("\n");
 
        sort(guys.begin(), guys.end());
        printf("%d\n", (int)guys.size());
        for (int i = 0; i < (int)guys.size(); i++)
            printf("%d\n", guys[i]+1);
 
        firstest = 0;
    }
 
    return 0;
}