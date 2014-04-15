#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <cstdlib>
#include <queue>
#define fr(a,b,c) for(int a = b; a < c; a++)
#define rp(a,b) fr(a,0,b)
#define inf 0x3f3f3f3f

using namespace std;

int grid[1001][1001];
int cost[1001][1001];

struct estado {
    int i, j;
    int cost;

    estado() {}
    estado(int i, int j, int cost):i(i), j(j), cost(cost) {}

    bool operator<(const estado &lhs) const {
        return cost > lhs.cost;
    }
} aux;

int p[] = {0,1,0,-1};
int q[] = {1,0,-1,0};

int main() {
    int T, n, m;
    scanf("%d", &T);
    while (T--) {
        scanf("%d%d", &n, &m);
        rp(i,n) rp(j,m) {
            cost[i][j]=inf;
            scanf("%d", &grid[i][j]);
        }
        priority_queue<estado> fila;
        fila.push(estado(0,0,grid[0][0]));
        cost[0][0] = 0;
        while (!fila.empty()) {
            aux = fila.top();
            fila.pop();
            if (aux.i == n-1 && aux.j == m-1) {
                printf("%d\n", aux.cost);
                break;
            }
            int newI, newJ;
            for (int i = 0; i < 4; i++) {
                newI = aux.i+p[i];
                newJ = aux.j+q[i];
                if (newI >= 0 && newI < n && newJ >= 0 && newJ < m && aux.cost+grid[newI][newJ] < cost[newI][newJ]) {
                    fila.push(estado(newI, newJ, aux.cost+grid[newI][newJ]));
                    cost[newI][newJ] = aux.cost+grid[newI][newJ];
                }
            }
        }
    }
    return 0;
}
