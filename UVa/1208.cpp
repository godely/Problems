#include <cstdio>
#include <algorithm>
#include <cstdlib>
#include <cstring>
#include <cmath>

using namespace std;

int rep[100];
int findset(int i) {
    if (i == rep[i]) return i;
    else return rep[i] = findset(rep[i]);
}

bool join(int i, int j) {
    i = findset(i);
    j = findset(j);
    if (i != j) {
        rep[i] = j;
        return true;
    }
    return false;
}

struct edge{
    int i, j, cost;
    edge(){}
    edge(int i, int j, int cost):i(i),j(j),cost(cost){}

    bool operator<(const edge &lhs) const {
        return cost<lhs.cost;
    }
} edges[10000];

struct abc{
    int p;
    char A, B;

    abc(){}
    abc(int p, char A, char B) : p(p), A(A), B(B) {}

    bool operator<(const abc &lhs) const {
        if (p != lhs.p) return p < lhs.p;
        if (A != lhs.A) return A < lhs.A;
        return B < lhs.B;
    }
} res[10000];

int main() {
    int T,C,k,aux,k2, cas =1;
    scanf("%d", &T);
    while (T--) {
        scanf("%d", &C);
        k=0;
        for (int i = 0; i <= C; i++) rep[i] = i;
        for (int i = 0; i < C; i++) {
            for (int j = 0; j < C; j++) {
                scanf("%d, ", &aux);
                if (i==j||!aux) continue;
                edges[k++] = edge(i,j,aux);
                //printf("%d %d %d\n", edges[k-1].i, edges[k-1].j, edges[k-1].cost);
            }
        }
        sort(edges,edges+k);

        k2=0;
        for (int i = 0; i < k; i++) {
            if (join(edges[i].i, edges[i].j)) {
                res[k2++]=abc(edges[i].cost, min(edges[i].i,edges[i].j)+'A', max(edges[i].i,edges[i].j)+'A');
            }
        }
        sort(res,res+k2);
        printf("Case %d:\n", cas++);
        for (int i = 0; i < k2; i++) printf("%c-%c %d\n", res[i].A, res[i].B, res[i].p);
    }
    return 0;
}
