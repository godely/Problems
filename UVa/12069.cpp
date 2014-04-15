#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <cmath>
#include <queue>
#include <algorithm>
#define fr0(a,b) for(int a=0;a<b;a++)
#define fr1(a,b) for(int a=1;a<=b;a++)
#define oo 0x3F3F3F3F

using namespace std;

int p[] = {0, 1, 0, -1};
int q[] = {1, 0, -1, 0};

struct abc {
    int i, j, cost, dir;

    abc() {}
    abc(int i, int j, int cost, int dir) : i(i), j(j), cost(cost), dir(dir) {}

    bool operator<(const abc &lhs) const {
    	return cost > lhs.cost;
    }
} aux;

int dx[655], dy[655], nx, ny;
int grid[355][355];
int calc[355][355][5];
bool check(int i, int j) {
    return i >= 0 && j >= 0 && i <= nx && j <= ny && grid[i][j] != -1;
}

int ret[305][4], ini[305][2], fim[305][2];
int main() {
    int T, N, Q, xi, yi, xf, yf, cas = 1;
    priority_queue<abc> fila;
    scanf("%d", &T);
    int passo = 0;
    while (T--) {
        nx = 0;
        ny = 0;
        scanf("%d", &N);
        for (int i = 0; i < N; i++) {
            scanf("%d%d%d%d", &xi, &yi, &xf, &yf);
            xi*=2, yi*=2, xf*=2, yf*=2;
            ret[i][0] = xi, ret[i][1] = yi, ret[i][2] = xf, ret[i][3] = yf;
            dx[nx++] = xi;
            dx[nx++] = xi-1;
            dx[nx++] = xf;
            dx[nx++] = xf+1;
            dy[ny++] = yi;
            dy[ny++] = yi-1;
            dy[ny++] = yf;
            dy[ny++] = yf+1;
        }
        scanf("%d", &Q);
        for (int i = 0; i < Q; i++) {
            scanf("%d%d%d%d", &xi, &yi, &xf, &yf);
            xi*=2, yi*=2, xf*=2, yf*=2;
            ini[i][0] = xi, ini[i][1] = yi;
            fim[i][0] = xf, fim[i][1] = yf;
            dx[nx++] = xi;
            dx[nx++] = xf;
            dy[ny++] = yi;
            dy[ny++] = yf;
        }
        dx[nx++] = -oo, dx[nx++] = oo;
        dy[ny++] = -oo, dy[ny++] = oo;
        sort(dx, dx+nx);
        nx = unique(dx, dx+nx)-dx;
        sort(dy, dy+ny);
        ny = unique(dy, dy+ny)-dy;

		//int grid2[500][500];
        for (int i = 0; i <= nx; i++) {
            for (int j = 0; j <= ny; j++) {
                grid[i][j] = oo;
				//grid2[i][j] = 0;
            }
        }
       	for (int k = 0; k < N; k++) {
            xi = lower_bound(dx, dx+nx, ret[k][0])-dx;
            yi = lower_bound(dy, dy+ny, ret[k][1])-dy;
            xf = lower_bound(dx, dx+nx, ret[k][2])-dx;
            yf = lower_bound(dy, dy+ny, ret[k][3])-dy;
			for (int i = xi; i <= xf; i++) {
                for (int j = yi; j <= yf; j++) {
                    grid[i][j] = -1;
          			//grid2[i][j] = 1;
                }
            }
        }
		/*int pk = 2;
        for (int k = 0; k < Q; k++) {
            grid2[lower_bound(dy, dy+ny, ini[k].yi)-dy][lower_bound(dx, dx+nx, ini[k].xi)-dx] = pk++;
            grid2[lower_bound(dy, dy+ny, fim[k].yf)-dy][lower_bound(dx, dx+nx, fim[k].xf)-dx] = pk++;
        }*/
        printf("Labyrinth #%d\n", cas++);
        /*for (int i = 0; i <= nx; i++) {
        	for (int j = 0; j <= ny; j++) {
        		printf("%d", grid2[i][j]);
        	}
        	printf("\n");
        }*/
		int XI, YI, XF, YF;
        for (int k = 0; k < Q; k++) {
            passo++;
            XI = lower_bound(dx, dx+nx, ini[k][0])-dx;
            YI = lower_bound(dy, dy+ny, ini[k][1])-dy;
            XF = lower_bound(dx, dx+nx, fim[k][0])-dx;
            YF = lower_bound(dy, dy+ny, fim[k][1])-dy;

			while (!fila.empty()) fila.pop();
            fr0(i,4) fila.push(abc(XI, YI, 0, i));
            while (!fila.empty()) {
                aux = fila.top();
                fila.pop();
                if (calc[aux.i][aux.j][aux.dir] == passo) continue;

				calc[aux.i][aux.j][aux.dir] = passo;
				grid[aux.i][aux.j] = min(aux.cost, grid[aux.i][aux.j]);

               	if (aux.i == XF && aux.j == YF) {
               		printf("%d\n", aux.cost);
               		goto lol;
               	}
               	//printf("(%d %d, dir: %d) = %d\n", aux.i, aux.j, aux.dir, aux.cost);

				for (int i = 0; i < 4; i++) {
					if (i == (aux.dir+2)%4) continue;
					if (check(aux.i+p[i], aux.j+q[i])) {
						//if (aux.i == 3 && aux.j == 1) printf("(%d, %d (d:%d c:%d i:%d)) -> (%d, %d (d:%d c:%d))  //  \n", aux.i, aux.j, aux.dir, aux.cost, i, aux.i+p[i], aux.j+q[i], i, (aux.dir == -1 || aux.dir == i) ? aux.cost : aux.cost+1);
						if (calc[aux.i+p[i]][aux.j+q[i]][i] == passo) continue;
						fila.push(abc(aux.i+p[i], aux.j+q[i], aux.dir == i ? aux.cost : aux.cost+1, i));
					}
				}
            }
			printf("Impossible.\n");
            lol:;
        }
    }
    return 0;
}
