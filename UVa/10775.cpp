//by stor
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <cmath>

using namespace std;

int M[500][3][3];

int main() {
	M[0][0][0] = 8;
	M[0][0][1] = 1;
	M[0][0][2] = 6;
	M[0][1][0] = 3;
	M[0][1][1] = 5;
	M[0][1][2] = 7;
	M[0][2][0] = 4;
	M[0][2][1] = 9;
	M[0][2][2] = 2;
	for (int c = 1; c <= 350; c++)
		for (int i = 0; i < 3; i++)
			for (int j = 0; j < 3; j++)
				M[c][i][j] = M[0][i][j] + 9*c;

	int N;
	while (scanf("%d", &N) == 1 && N > 0) {
		if (N&1) {
			int K = N/3;
			bool prnt = 0;
			for (int c = 0; c < K; c++) {
				for (int j = 0; j < 3; j++) {
					if (prnt) printf(" ");
					else prnt = 1;
					printf("%d", M[c][0][j]);
				}
			}
			printf("\n");
			
			int Z = N/6;
			for (int i = 1, c = i-1, count; i < 3; i++) {
				prnt = 0;
				for (c = (c+Z)%K, count = 0; count < K; c = (c+Z)%K, count++) {
					for (int j = 0; j < 3; j++) {
						if (prnt) printf(" ");
						else prnt = 1;
						printf("%d", M[c][i][j]);
					}
				}
				printf("\n");
			}			
			
		} else printf("IMPOSSIBLE\n");
	}
}