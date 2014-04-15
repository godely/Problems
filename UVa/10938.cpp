#include <cstring>
#include <vector>
#define MAXN 1024

using namespace std;

int n, nE;
int adj[MAXN][MAXN], nadj[MAXN];

vector<int> L;
int E[2*MAXN], R[MAXN], vis[MAXN];

void euler(int u, int p, int el) {
    E[nE++] = u; L.push_back(el);
    vis[u] = 1;
    for (int i = 0; i < nadj[u]; i++) {
        if (!vis[adj[u][i]] && adj[u][i] != p) {
            euler(adj[u][i], u, el+1);
            E[nE++] = u; L.push_back(el);
        }
    }
}

void preprocess(int root) {
    int i;
    nE = 0;
    L.clear();
    memset(vis, 0, sizeof(vis));
    euler(root, -1, 0);
    for (i = 2*n-2; i >= 0; i--) R[E[i]] = i;
    init(L);
}

int lca(int u, int v) {
    return E[query(min(R[u], R[v]), max(R[u], R[v]))];
}

int main() {

}
