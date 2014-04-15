#include <cstdio>
#include <cstring>
#include <algorithm>
#include <queue>
#include <cstdlib>
#define fr0(a,b) for(int a=0;a<b;a++)
#define fr1(a,b) for(int a=1;a<=b;a++)

using namespace std;

int n,f,t;
int grid[30][30], grC[30][30][6][2];
int p[] = {1, 0, -1, 0};
int q[] = {0, -1, 0, 1};

struct abc {
    int i, j, t, cost;

    abc() {}
    abc(int i, int j, int t, int cost) : i(i), j(j), t(t), cost(cost) {}

    bool operator<(const abc &lhs) const {
        return cost > lhs.cost;
    }
} aux;
priority_queue<abc> fila;

bool check(int i, int j) {
    return i >= 0 && j >= 0 && i < n && j < n;
}

int main(){
    int i_, j_, cas=1;
    while(scanf("%d%d%d",&n,&f,&t) == 3 && n){
        fr0(i,n) fr0(j,n) scanf("%d",&grid[i][j]);
        memset(grC, -1, sizeof grC);
        for (int ind = 0; ind < f; ind++) {
            scanf("%d%d", &i_, &j_);
            fila.push(abc(i_, j_, 0, 0));
            while (!fila.empty()) {
                aux = fila.top();
                fila.pop();
                if (grC[aux.i][aux.j][ind][0] == -1) {
                    grC[aux.i][aux.j][ind][0] = aux.cost;
                }
                if (grC[aux.i][aux.j][ind][1] == -1 || aux.t < grC[aux.i][aux.j][ind][1]) {
                    grC[aux.i][aux.j][ind][1] = aux.t;
                    if (aux.t < t) {
                        for (int i = 0; i < 4; i++) {
                            if (check(aux.i+p[i], aux.j+q[i]))
                                fila.push(abc(aux.i+p[i], aux.j+q[i], aux.t+1, aux.cost+grid[aux.i][aux.j]));
                        }
                    }
                }
            }
        }
        long long minT = 999999999, temp;
        int resI, resJ;
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < n; j++) {
                temp = 0;
                for (int k = 0; k < f; k++) {
                    if (grC[i][j][k][0] == -1) goto stop;
                    temp += grC[i][j][k][0];
                }
                if (temp < minT) {
                    minT = temp;
                    resI = i;
                    resJ = j;
                }
                stop:;
            }
        }
        if (minT == 999999999) {
            printf("Case #%d: Impossible.\n", cas++);
        } else {
            printf("Case #%d: Selected city (%d,%d) with minimum cost %lld.\n", cas++, resI, resJ, minT);
        }
    }
    return 0;
}
