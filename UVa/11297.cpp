#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <algorithm>
#include <cmath>
#define PAR pair<int, int>
#define INF 1073741824;

using namespace std;

int grid[550][550], val[1<<24][2];

PAR q(int R, int i_a, int j_a, int i_b, int j_b, int i_INI, int j_INI, int i_FIM, int j_FIM) {
	if (!i_a || !j_a || !i_b || !j_b || i_a > i_b || j_a > j_b) return make_pair(-1073741824,1073741824);
	if (i_b < i_INI || j_b < j_INI || i_a > i_FIM || j_a > j_FIM) return make_pair(-1073741824,1073741824);
	else if (i_INI <= i_a && j_INI <= j_a && i_b <= i_FIM && j_b <= j_FIM) {
		//printf("%d %d %d %d (max:%d min:%d)\n", i_a, j_a, i_b, j_b, val[R][0], val[R][1]);
		return make_pair(val[R][0], val[R][1]);
	} else {
		int M1 = (i_a+i_b)/2;
		int M2 = (j_a+j_b)/2;

		PAR par1 = q(4*R-2, i_a, j_a, M1, M2, i_INI, j_INI, i_FIM, j_FIM);
		PAR par2 = q(4*R-1, i_a, M2+1, M1, j_b, i_INI, j_INI, i_FIM, j_FIM);
		PAR par3 = q(4*R, M1+1, j_a, i_b, M2, i_INI, j_INI, i_FIM, j_FIM);
		PAR par4 = q(4*R+1, M1+1, M2+1, i_b, j_b, i_INI, j_INI, i_FIM, j_FIM);
		return make_pair(max(par1.first, max(par2.first, max(par3.first, par4.first))), min(par1.second, min(par2.second, min(par3.second, par4.second))));
	}
}

int att(int R, int i_a, int j_a, int i_b, int j_b, int i_t, int j_t, int v) {
	if (!i_a || !j_a || !i_b || !j_b || i_a > i_b || j_a > j_b) return 0;
	else if (i_a == i_b  && i_b == i_t && j_a == j_b && j_b == j_t) {
		return val[R][0] = val[R][1] = v;
	} else {
		int M1 = (i_a+i_b)/2;
		int M2 = (j_a+j_b)/2;
		if (i_t <= M1) {
			if (j_t <= M2) {
				att(4*R-2, i_a, j_a, M1, M2, i_t, j_t, v);
			} else {
				att(4*R-1, i_a, M2+1, M1, j_b, i_t, j_t, v);
			}
		} else {
			if (j_t <= M2) {
				att(4*R, M1+1, j_a, i_b, M2, i_t, j_t, v);
			} else {
				att(4*R+1, M1+1, M2+1, i_b, j_b, i_t, j_t, v);
			}
		}
		val[R][0] = max(val[4*R-2][0], max(val[4*R-1][0], max(val[4*R][0], val[4*R+1][0])));
		val[R][1] = min(val[4*R-2][1], min(val[4*R-1][1], min(val[4*R][1], val[4*R+1][1])));
	}
}

void createST(int R, int i_a, int j_a, int i_b, int j_b) {
	if (!i_a || !j_a || !i_b || !j_b || i_a > i_b || j_a > j_b) val[R][0] = -1073741824, val[R][1] = 1073741824;
	else if (i_a == i_b && j_a == j_b) val[R][0] = val[R][1] = grid[i_a][j_a];
	else {
		int M1 = (i_a+i_b)/2;
		int M2 = (j_a+j_b)/2;
		createST(4*R-2, i_a, j_a, M1, M2);
		createST(4*R-1, i_a, M2+1, M1, j_b);
		createST(4*R, M1+1, j_a, i_b, M2);
		createST(4*R+1, M1+1, M2+1, i_b, j_b);
		val[R][0] = max(val[4*R-2][0], max(val[4*R-1][0], max(val[4*R][0], val[4*R+1][0])));
		val[R][1] = min(val[4*R-2][1], min(val[4*R-1][1], min(val[4*R][1], val[4*R+1][1])));
	}
}

int main() {
	int N, Q, i_a, j_a, i_b, j_b, v;
	char ch;
	scanf("%d%*d", &N);
	for (int i = 1; i <= N; i++) {
		for (int j = 1; j <= N; j++) {
			scanf("%d", &grid[i][j]);
		}
	}
	createST(1, 1, 1, N, N);
	scanf("%d", &Q);
	while (Q--) {
		getchar();
		ch = getchar();
		if (ch == 'q') {
			scanf("%d%d%d%d", &i_a, &j_a, &i_b, &j_b);
			pair<int, int> res = q(1, 1, 1, N, N, i_a, j_a, i_b, j_b);
			printf("%d %d\n", res.first, res.second);
		} else {
			scanf("%d%d%d", &i_a, &j_a, &v);
			att(1, 1, 1, N, N, i_a, j_a, v);
		}
	}
}