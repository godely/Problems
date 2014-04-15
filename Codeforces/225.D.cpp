#include <cstdio>
#include <map>
#include <queue>
#include <cstdlib>
#include <cstring>
#include <cmath>
#include <algorithm>
#define inf 0x3f3f3f3f
#define fr(a,b,c) for(int a = b; a < c; a++)
#define rp(a,b) fr(a,0,b)
#define X first
#define Y second
#define mod 10000000000000007LL

using namespace std;

char grid[20][20];

int n, m, k, endX, endY;

int p[] = {0,1,0,-1};
int q[] = {1,0,-1,0};

map<long long, int> mapa;

struct estado {
    pair<int, int> pos[12];
    int count;

    estado() {}

    long long getHash() {
        long long hash=0;
        rp(i,k) {
            hash=(hash*17)%mod;
            hash=(hash+pos[i].X)%mod;
            hash=(hash*17)%mod;
            hash=(hash+pos[i].Y)%mod;
        }
        return hash;
    }
} start;

void bfs() {
    queue<estado> fila;
    fila.push(start);

    estado aux;
    while (!fila.empty()) {
        aux = fila.front();
        fila.pop();

        if (mapa[aux.getHash()] > 0) continue;
        mapa[aux.getHash()] = 1;

        if (aux.pos[0].X == endX && aux.pos[0].Y == endY) {
            printf("%d\n", aux.count);
            return;
        }

        int newX, newY;
        bool ok;
        estado next;
        next.count = aux.count+1;
        for (int i = 0; i < 4; i++) {
            newX = aux.pos[0].X+p[i];
            newY = aux.pos[0].Y+q[i];
            if (newX >= 0 && newX < n && newY >= 0 && newY < m && grid[newX][newY] != '#') {
                ok = 1;
                fr(j,1,k-1) {
                    if (aux.pos[j].X == newX && aux.pos[j].Y == newY) {
                        ok = 0;
                        break;
                    }
                }
                if (ok) {
                    fr(j,1,k) {
                        next.pos[j].X = aux.pos[j-1].X;
                        next.pos[j].Y = aux.pos[j-1].Y;
                    }
                    next.pos[0].X = newX;
                    next.pos[0].Y = newY;
                    fila.push(next);
                }
            }
        }
    }
    printf("-1\n");
}

int main() {
    scanf("%d%d", &n, &m);
    rp(i,n) scanf("%s", grid[i]);
    k=0;
    start.count=0;
    rp(i,n) {
        rp(j,m) {
            if (grid[i][j]>='1' && grid[i][j]<='9') k = max(k, grid[i][j]-'0'), start.pos[grid[i][j]-'1'] = make_pair(i,j), grid[i][j] = '.';
            if (grid[i][j] == '@') endX=i, endY=j;
        }
    }
    bfs();
}
