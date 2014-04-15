#include <bits/stdc++.h>
using namespace std;
#define fr(a,b,c) for(int a = b; a < c; a++)
#define rp(a,b) fr(a,0,b)
#define mod 1000000007

int W, H, P, Q, N, X, Y, a, b, c, d;
int sum, w, h;
int x[1111111], y[1111111];
int dx[1111111], dy[1111111], nx, ny;
int main() {
	int T, N, K, cas = 1;
	scanf("%d", &T);
	while (T--) {
		nx = ny = 0;
		scanf("%d%d%d%d%d%d%d%d%d%d%d", &W, &H, &P, &Q, &N, &X, &Y, &a, &b, &c, &d);
		x[0] = X; y[0] = Y;
		dx[nx++] = x[0], dy[ny++] = y[0];
		fr(i,1,N) {
			x[i] = (x[i - 1] * a + y[i - 1] * b + 1) % W;
			y[i] = (x[i - 1] * c + y[i - 1] * d + 1) % H;
			dx[nx++] = x[i];
			dy[ny++] = y[i];
		}
		dx[nx++] = 0; dx[nx++] = W;
		dy[ny++] = 0; dy[ny++] = H;
		sort(dx,dx+nx);
		sort(dy,dy+ny);
		nx = unique(dx,dx+nx)-dx;
		ny = unique(dy,dy+ny)-dy;
		sum = 0;
		rp(i,nx-1) {
			rp(j,ny-1) {
				w = dx[i+1]-dx[i];
				h = dy[i+1]-dy[i];
				if (w >= P && h >= Q) sum += (w-P+1)*(h-Q+1);
			}
		}
		printf("Case %d: %d\n", cas++, sum);
	}
}