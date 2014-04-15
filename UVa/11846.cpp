#include <bits/stdc++.h>
using namespace std;
#define fr(a,b,c) for(int a = b; a < c; a++)
#define rp(a,b) fr(a,0,b)

int larg[][4] = {{0,0,0,0}, {1,0,0,0}, {2,1,0,0}, {3,1,0,0}, {4,2,1,0}, {5,1,0,0}, {6,3,2,1}, {7,1,0,0}, {8,4,2,1}, {9,3,1,0}};
int size[] = {0,1,2,2,3,2,4,2,4,3};
char res[22][22];
char inp[22][22];
char gb[22];
int N, K;
int Y[30], X[30], V[30];

bool solve(int ind) {
	if (ind == K) {
		rp(i,N) printf("%s\n", res[i]);
		return 1;
	}
	int y = Y[ind], x = X[ind], v = V[ind], alt, lar;
	rp(k,size[v]) {
		lar = larg[v][k];
		alt = v/lar;
		fr(cy,max(y-alt+1,0),y+1) {
			fr(cx,max(x-lar+1,0),x+1) {
				if (cy+alt-1 >= N) goto rs2;
				if (cx+lar-1 >= N) break;
				fr(_y,cy,cy+alt) fr(_x,cx,cx+lar) if (res[_y][_x] != '.' || (~inp[_y][_x] && inp[_y][_x] != ind)) goto rs;
				fr(_y,cy,cy+alt) fr(_x,cx,cx+lar) res[_y][_x] = ind + 'A';
				if (solve(ind+1)) return 1;
				fr(_y,cy,cy+alt) fr(_x,cx,cx+lar) res[_y][_x] = '.';
				rs:;
			}
		}
		rs2:;
	}
	return 0;
}

int main() {
	int k;
	while (scanf("%d%d", &N, &K) == 2 && N > 0) {
		k = 0;
		rp(i,N) {
			scanf("%s", gb);
			rp(j,N) if (gb[j] != '.') Y[k] = i, X[k] = j, V[k] = gb[j]-'0', inp[i][j] = k++, res[i][j] = '.', inp[i][j] = -1;
		}
		solve(0);
	}
	return 0;
}