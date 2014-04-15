#include <cstdio>
#include <cstdlib>
#include <cmath>
#include <cstring>
#include <queue>
#include <algorithm>

using namespace std;

int N;
int g[100][100][100];
int dx[40], dy[40], dz[40];
int nx, ny, nz;

struct pr {
	int coordLol[6];
	int coord[6];

	pr() {}
	pr(int xi, int yi, int zi, int xf, int yf, int zf) {
		 coord[0] = xi;
		 coord[1] = yi;
		 coord[2] = zi;
		 coord[3] = xf;
		 coord[4] = yf;
		 coord[5] = zf;
	}
} para[30];

struct abc {
	int coord, idPos, id;

	abc() {}
	abc(int coord, int idPos, int id) : coord(coord), idPos(idPos), id(id) {}

	bool operator <(const abc &lhs) const {
		return coord > lhs.coord;
	}
};

bool read() {
	if (scanf("%d", &N) != 1) return false;
	int a, b, c, d, e, f;
	priority_queue<abc> heap;
	nx = 0, ny = 0, nz = 0;
	for (int i = 0; i < N; i++) {
		scanf("%d%d%d %d%d%d", &a, &b, &c, &d, &e, &f);
		para[i] = pr(a, b, c, d, e, f);
		dx[nx++] = a;
		dx[nx++] = d;
		dy[ny++] = b;
		dy[ny++] = e;
		dz[nz++] = c;
		dz[nz++] = f;
	}
	sort(dx, dx+nx);
	nx = unique(dx,dx+nx)-dx;
	sort(dy, dy+ny);
	ny = unique(dy,dy+ny)-dy;
	sort(dz, dz+nz);
	nz = unique(dz,dz+nz)-dz;

	for (int i = 0; i < N; i++) {
		para[i].coordLol[0] = lower_bound(dx, dx+nx, para[i].coord[0])-dx;
		para[i].coordLol[1] = lower_bound(dy, dy+ny, para[i].coord[1])-dy;
		para[i].coordLol[2] = lower_bound(dz, dz+nz, para[i].coord[2])-dz;
		para[i].coordLol[3] = lower_bound(dx, dx+nx, para[i].coord[3])-dx;
		para[i].coordLol[4] = lower_bound(dy, dy+ny, para[i].coord[4])-dy;
		para[i].coordLol[5] = lower_bound(dz, dz+nz, para[i].coord[5])-dz;
//		printf("(%d %d %d) (%d %d %d)\n", para[i].coordLol[0], para[i].coordLol[1], para[i].coordLol[2], para[i].coordLol[3], para[i].coordLol[4], para[i].coordLol[5]);
	}
	return true;
}

void process() {
	memset(g,0,sizeof(g));
	for (int k = 0; k < N; k++) {
		for (int i = para[k].coordLol[0]; i < para[k].coordLol[3]; i++) {
			for (int j = para[k].coordLol[1]; j < para[k].coordLol[4]; j++) {
				for (int b = para[k].coordLol[2]; b < para[k].coordLol[5]; b++) {
					g[i][j][b]++;
				}
			}
		}
	}

	long long vol = 0;
	for (int i = 0; i < nx; i++) {
		for (int j = 0; j < ny; j++) {
			for (int k = 0; k < nz; k++) {
				if (g[i][j][k] >= 2) {
					vol += (dx[i+1]-dx[i])*(dy[j+1]-dy[j])*(dz[k+1]-dz[k]);
				}
			}
		}
	}
	printf("%lld\n", vol);
}

int main() {
	while (read()) process();
	return 0;
}
